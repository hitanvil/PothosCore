// Copyright (c) 2014-2014 Josh Blum
// SPDX-License-Identifier: BSL-1.0

#include "PothosGuiUtils.hpp" //get object map
#include "TopologyEngine/TopologyEngine.hpp"
#include "GraphObjects/GraphBlock.hpp"
#include "AffinitySupport/AffinityZonesDock.hpp"
#include <Pothos/Proxy.hpp>
#include <Pothos/System/Logger.hpp>
#include <Pothos/Remote.hpp>
#include <Pothos/Framework.hpp>
#include <Poco/URI.h>
#include <Poco/NumberParser.h>
#include <iostream>
#include <cassert>

TopologyEngine::TopologyEngine(QObject *parent):
    QObject(parent),
    _topology(new Pothos::Topology())
{
    _syslogListenPort = Pothos::System::Logger::startSyslogListener();
}

void TopologyEngine::commitUpdate(const GraphObjectList &graphObjects)
{
    //get all block proxy objects
    std::map<std::string, Pothos::Proxy> idToBlock;
    for (auto obj : graphObjects)
    {
        auto block = dynamic_cast<GraphBlock *>(obj);
        if (block == nullptr) continue;
        auto blockEval = this->evalGraphBlock(block);
        if (not blockEval) continue;
        auto proxyBlock = blockEval.callProxy("getProxyBlock");
        idToBlock[block->getId().toStdString()] = proxyBlock;

        //set the thread pool on the proxy block
        auto threadPool = this->getThreadPoolFromZone(block->getAffinityZone());
        if (threadPool) proxyBlock.callVoid("setThreadPool", threadPool);
    }

    //make all of the connections
    _topology->disconnectAll();
    for (const auto &conn : getConnectionInfo(graphObjects))
    {
        _topology->connect(
            idToBlock.at(conn.srcId), conn.srcPort,
            idToBlock.at(conn.dstId), conn.dstPort);
    }

    //commit the new design
    _topology->commit();
}


Pothos::Proxy TopologyEngine::getEvalEnvironment(const QString &zone)
{
    if (_zoneToEvalEnvironment.count(zone) == 0)
    {
        auto env = this->getEnvironmentFromZone(zone);
        auto EvalEnvironment = env->findProxy("Pothos/Util/EvalEnvironment");
        _zoneToEvalEnvironment[zone] = EvalEnvironment.callProxy("new");
    }
    return _zoneToEvalEnvironment.at(zone);
}

Pothos::ProxyEnvironment::Sptr TopologyEngine::getEnvironmentFromZone(const QString &zone)
{
    auto dock = dynamic_cast<AffinityZonesDock *>(getObjectMap()["affinityZonesDock"]);
    assert(dock != nullptr);
    auto config = dock->zoneToConfig(zone);
    auto hostUri = config?config->getValue<std::string>("hostUri"):"tcp://localhost";
    auto processName = config?config->getValue<std::string>("processName"):"";

    //find if the environment already exists
    bool serverProcessNew = false;
    auto &processToServer = _uriToProcessToServerHandle[hostUri];
    if (processToServer.find(processName) == processToServer.end())
    {
        //talk to the server and spawn a new process with a new server
        auto env = Pothos::RemoteClient(hostUri).makeEnvironment("managed");
        auto serverHandle = env->findProxy("Pothos/RemoteServer").callProxy("new", "tcp://0.0.0.0");
        processToServer[processName] = serverHandle;
        serverProcessNew = true;
    }

    //connect to the new server and make the communication environment
    auto serverHandle = _uriToProcessToServerHandle.at(hostUri).at(processName);
    auto actualPort = serverHandle.call<std::string>("getActualPort");
    Poco::URI newHostUri(hostUri);
    newHostUri.setPort(Poco::NumberParser::parseUnsigned(actualPort));
    auto client = Pothos::RemoteClient(newHostUri.toString());
    client.holdRef(Pothos::Object(serverHandle));
    auto env = client.makeEnvironment("managed");
    if (serverProcessNew) //enable log forwarding
    {
        const auto serverAddr = env->getPeeringAddress() + ":" + _syslogListenPort;
        env->findProxy("Pothos/System/Logger").callVoid("startSyslogForwarding", serverAddr);
        const auto logSource = (not zone.isEmpty())? zone.toStdString() : newHostUri.getHost();
        env->findProxy("Pothos/System/Logger").callVoid("forwardStdIoToLogging", logSource);
    }
    return env;
}

Pothos::Proxy TopologyEngine::getThreadPoolFromZone(const QString &zone)
{
    //make the thread pool if DNE
    if (_zoneToThreadPool.count(zone) == 0)
    {
        auto env = this->getEnvironmentFromZone(zone);
        auto dock = dynamic_cast<AffinityZonesDock *>(getObjectMap()["affinityZonesDock"]);
        assert(dock != nullptr);
        auto config = dock->zoneToConfig(zone);
        if (not config) return Pothos::Proxy(); //invalid

        //load the args
        Pothos::ThreadPoolArgs args;
        if (config->has("numThreads"))
        {
            args.numThreads = config->getValue<int>("numThreads");
        }
        if (config->has("priority"))
        {
            args.priority = config->getValue<double>("priority");
        }
        if (config->has("affinityMode") and config->has("affinityMask"))
        {
            args.affinityMode = config->getValue<std::string>("affinityMode");
            auto mask = config->getArray("affinityMask");
            for (size_t i = 0; i < mask->size(); i++) args.affinity.push_back(mask->getElement<int>(i));
        }
        if (config->has("yieldMode"))
        {
            args.yieldMode = config->getValue<std::string>("yieldMode");
        }

        //create the thread pool
        _zoneToThreadPool[zone] = env->findProxy("Pothos/ThreadPool").callProxy("new", args);
    }

    return _zoneToThreadPool.at(zone);
}

void TopologyEngine::clear(void)
{
    _topology->disconnectAll();
    _topology->commit();
}
