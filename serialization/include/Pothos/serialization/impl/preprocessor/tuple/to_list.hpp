# /* Copyright (C) 2001
#  * Housemarque Oy
#  * http://www.housemarque.com
#  *
#  * Distributed under the Boost Software License, Version 1.0. (See
#  * accompanying file LICENSE_1_0.txt or copy at
#  * http://www.boost.org/LICENSE_1_0.txt)
#  */
#
# /* Revised by Paul Mensonides (2002-2011) */
# /* Revised by Edward Diener (2011) */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef POTHOS_PREPROCESSOR_TUPLE_TO_LIST_HPP
# define POTHOS_PREPROCESSOR_TUPLE_TO_LIST_HPP
#
# include <Pothos/serialization/impl/preprocessor/cat.hpp>
# include <Pothos/serialization/impl/preprocessor/config/config.hpp>
# include <Pothos/serialization/impl/preprocessor/facilities/overload.hpp>
# include <Pothos/serialization/impl/preprocessor/variadic/size.hpp>
#
# /* POTHOS_PP_TUPLE_TO_LIST */
#
# if POTHOS_PP_VARIADICS
#    if POTHOS_PP_VARIADICS_MSVC
#        define POTHOS_PP_TUPLE_TO_LIST(...) POTHOS_PP_TUPLE_TO_LIST_I(POTHOS_PP_OVERLOAD(POTHOS_PP_TUPLE_TO_LIST_O_, __VA_ARGS__), (__VA_ARGS__))
#        define POTHOS_PP_TUPLE_TO_LIST_I(m, args) POTHOS_PP_TUPLE_TO_LIST_II(m, args)
#        define POTHOS_PP_TUPLE_TO_LIST_II(m, args) POTHOS_PP_CAT(m ## args,)
#    else
#        define POTHOS_PP_TUPLE_TO_LIST(...) POTHOS_PP_OVERLOAD(POTHOS_PP_TUPLE_TO_LIST_O_, __VA_ARGS__)(__VA_ARGS__)
#    endif
#    define POTHOS_PP_TUPLE_TO_LIST_O_1(tuple) POTHOS_PP_CAT(POTHOS_PP_TUPLE_TO_LIST_, POTHOS_PP_VARIADIC_SIZE tuple) tuple
#    define POTHOS_PP_TUPLE_TO_LIST_O_2(size, tuple) POTHOS_PP_TUPLE_TO_LIST_O_1(tuple)
# else
#    if ~POTHOS_PP_CONFIG_FLAGS() & POTHOS_PP_CONFIG_MWCC()
#        define POTHOS_PP_TUPLE_TO_LIST(size, tuple) POTHOS_PP_TUPLE_TO_LIST_I(size, tuple)
#        if ~POTHOS_PP_CONFIG_FLAGS() & POTHOS_PP_CONFIG_MSVC()
#            define POTHOS_PP_TUPLE_TO_LIST_I(s, t) POTHOS_PP_TUPLE_TO_LIST_ ## s t
#        else
#            define POTHOS_PP_TUPLE_TO_LIST_I(s, t) POTHOS_PP_TUPLE_TO_LIST_II(POTHOS_PP_TUPLE_TO_LIST_ ## s t)
#            define POTHOS_PP_TUPLE_TO_LIST_II(res) res
#        endif
#    else
#        define POTHOS_PP_TUPLE_TO_LIST(size, tuple) POTHOS_PP_TUPLE_TO_LIST_OO((size, tuple))
#        define POTHOS_PP_TUPLE_TO_LIST_OO(par) POTHOS_PP_TUPLE_TO_LIST_I ## par
#        define POTHOS_PP_TUPLE_TO_LIST_I(s, t) POTHOS_PP_TUPLE_TO_LIST_ ## s ## t
#    endif
# endif
#
# define POTHOS_PP_TUPLE_TO_LIST_1(e0) (e0, POTHOS_PP_NIL)
# define POTHOS_PP_TUPLE_TO_LIST_2(e0, e1) (e0, (e1, POTHOS_PP_NIL))
# define POTHOS_PP_TUPLE_TO_LIST_3(e0, e1, e2) (e0, (e1, (e2, POTHOS_PP_NIL)))
# define POTHOS_PP_TUPLE_TO_LIST_4(e0, e1, e2, e3) (e0, (e1, (e2, (e3, POTHOS_PP_NIL))))
# define POTHOS_PP_TUPLE_TO_LIST_5(e0, e1, e2, e3, e4) (e0, (e1, (e2, (e3, (e4, POTHOS_PP_NIL)))))
# define POTHOS_PP_TUPLE_TO_LIST_6(e0, e1, e2, e3, e4, e5) (e0, (e1, (e2, (e3, (e4, (e5, POTHOS_PP_NIL))))))
# define POTHOS_PP_TUPLE_TO_LIST_7(e0, e1, e2, e3, e4, e5, e6) (e0, (e1, (e2, (e3, (e4, (e5, (e6, POTHOS_PP_NIL)))))))
# define POTHOS_PP_TUPLE_TO_LIST_8(e0, e1, e2, e3, e4, e5, e6, e7) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, POTHOS_PP_NIL))))))))
# define POTHOS_PP_TUPLE_TO_LIST_9(e0, e1, e2, e3, e4, e5, e6, e7, e8) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, POTHOS_PP_NIL)))))))))
# define POTHOS_PP_TUPLE_TO_LIST_10(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, POTHOS_PP_NIL))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_11(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, POTHOS_PP_NIL)))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_12(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, POTHOS_PP_NIL))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_13(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, POTHOS_PP_NIL)))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_14(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, POTHOS_PP_NIL))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_15(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, POTHOS_PP_NIL)))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_16(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, POTHOS_PP_NIL))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_17(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, POTHOS_PP_NIL)))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_18(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, POTHOS_PP_NIL))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_19(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, POTHOS_PP_NIL)))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_20(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, POTHOS_PP_NIL))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_21(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, POTHOS_PP_NIL)))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_22(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, POTHOS_PP_NIL))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_23(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, POTHOS_PP_NIL)))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_24(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, POTHOS_PP_NIL))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_25(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, POTHOS_PP_NIL)))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_26(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, POTHOS_PP_NIL))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_27(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, POTHOS_PP_NIL)))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_28(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, POTHOS_PP_NIL))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_29(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, POTHOS_PP_NIL)))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_30(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, POTHOS_PP_NIL))))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_31(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, (e30, POTHOS_PP_NIL)))))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_32(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, (e30, (e31, POTHOS_PP_NIL))))))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_33(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, (e30, (e31, (e32, POTHOS_PP_NIL)))))))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_34(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, (e30, (e31, (e32, (e33, POTHOS_PP_NIL))))))))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_35(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, (e30, (e31, (e32, (e33, (e34, POTHOS_PP_NIL)))))))))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_36(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, (e30, (e31, (e32, (e33, (e34, (e35, POTHOS_PP_NIL))))))))))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_37(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, (e30, (e31, (e32, (e33, (e34, (e35, (e36, POTHOS_PP_NIL)))))))))))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_38(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, (e30, (e31, (e32, (e33, (e34, (e35, (e36, (e37, POTHOS_PP_NIL))))))))))))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_39(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, (e30, (e31, (e32, (e33, (e34, (e35, (e36, (e37, (e38, POTHOS_PP_NIL)))))))))))))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_40(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, (e30, (e31, (e32, (e33, (e34, (e35, (e36, (e37, (e38, (e39, POTHOS_PP_NIL))))))))))))))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_41(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, (e30, (e31, (e32, (e33, (e34, (e35, (e36, (e37, (e38, (e39, (e40, POTHOS_PP_NIL)))))))))))))))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_42(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, (e30, (e31, (e32, (e33, (e34, (e35, (e36, (e37, (e38, (e39, (e40, (e41, POTHOS_PP_NIL))))))))))))))))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_43(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, (e30, (e31, (e32, (e33, (e34, (e35, (e36, (e37, (e38, (e39, (e40, (e41, (e42, POTHOS_PP_NIL)))))))))))))))))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_44(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, (e30, (e31, (e32, (e33, (e34, (e35, (e36, (e37, (e38, (e39, (e40, (e41, (e42, (e43, POTHOS_PP_NIL))))))))))))))))))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_45(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, (e30, (e31, (e32, (e33, (e34, (e35, (e36, (e37, (e38, (e39, (e40, (e41, (e42, (e43, (e44, POTHOS_PP_NIL)))))))))))))))))))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_46(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, (e30, (e31, (e32, (e33, (e34, (e35, (e36, (e37, (e38, (e39, (e40, (e41, (e42, (e43, (e44, (e45, POTHOS_PP_NIL))))))))))))))))))))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_47(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, (e30, (e31, (e32, (e33, (e34, (e35, (e36, (e37, (e38, (e39, (e40, (e41, (e42, (e43, (e44, (e45, (e46, POTHOS_PP_NIL)))))))))))))))))))))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_48(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, (e30, (e31, (e32, (e33, (e34, (e35, (e36, (e37, (e38, (e39, (e40, (e41, (e42, (e43, (e44, (e45, (e46, (e47, POTHOS_PP_NIL))))))))))))))))))))))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_49(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, (e30, (e31, (e32, (e33, (e34, (e35, (e36, (e37, (e38, (e39, (e40, (e41, (e42, (e43, (e44, (e45, (e46, (e47, (e48, POTHOS_PP_NIL)))))))))))))))))))))))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_50(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, (e30, (e31, (e32, (e33, (e34, (e35, (e36, (e37, (e38, (e39, (e40, (e41, (e42, (e43, (e44, (e45, (e46, (e47, (e48, (e49, POTHOS_PP_NIL))))))))))))))))))))))))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_51(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, (e30, (e31, (e32, (e33, (e34, (e35, (e36, (e37, (e38, (e39, (e40, (e41, (e42, (e43, (e44, (e45, (e46, (e47, (e48, (e49, (e50, POTHOS_PP_NIL)))))))))))))))))))))))))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_52(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, (e30, (e31, (e32, (e33, (e34, (e35, (e36, (e37, (e38, (e39, (e40, (e41, (e42, (e43, (e44, (e45, (e46, (e47, (e48, (e49, (e50, (e51, POTHOS_PP_NIL))))))))))))))))))))))))))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_53(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, (e30, (e31, (e32, (e33, (e34, (e35, (e36, (e37, (e38, (e39, (e40, (e41, (e42, (e43, (e44, (e45, (e46, (e47, (e48, (e49, (e50, (e51, (e52, POTHOS_PP_NIL)))))))))))))))))))))))))))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_54(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, (e30, (e31, (e32, (e33, (e34, (e35, (e36, (e37, (e38, (e39, (e40, (e41, (e42, (e43, (e44, (e45, (e46, (e47, (e48, (e49, (e50, (e51, (e52, (e53, POTHOS_PP_NIL))))))))))))))))))))))))))))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_55(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, (e30, (e31, (e32, (e33, (e34, (e35, (e36, (e37, (e38, (e39, (e40, (e41, (e42, (e43, (e44, (e45, (e46, (e47, (e48, (e49, (e50, (e51, (e52, (e53, (e54, POTHOS_PP_NIL)))))))))))))))))))))))))))))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_56(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, (e30, (e31, (e32, (e33, (e34, (e35, (e36, (e37, (e38, (e39, (e40, (e41, (e42, (e43, (e44, (e45, (e46, (e47, (e48, (e49, (e50, (e51, (e52, (e53, (e54, (e55, POTHOS_PP_NIL))))))))))))))))))))))))))))))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_57(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, (e30, (e31, (e32, (e33, (e34, (e35, (e36, (e37, (e38, (e39, (e40, (e41, (e42, (e43, (e44, (e45, (e46, (e47, (e48, (e49, (e50, (e51, (e52, (e53, (e54, (e55, (e56, POTHOS_PP_NIL)))))))))))))))))))))))))))))))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_58(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, (e30, (e31, (e32, (e33, (e34, (e35, (e36, (e37, (e38, (e39, (e40, (e41, (e42, (e43, (e44, (e45, (e46, (e47, (e48, (e49, (e50, (e51, (e52, (e53, (e54, (e55, (e56, (e57, POTHOS_PP_NIL))))))))))))))))))))))))))))))))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_59(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, (e30, (e31, (e32, (e33, (e34, (e35, (e36, (e37, (e38, (e39, (e40, (e41, (e42, (e43, (e44, (e45, (e46, (e47, (e48, (e49, (e50, (e51, (e52, (e53, (e54, (e55, (e56, (e57, (e58, POTHOS_PP_NIL)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_60(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, (e30, (e31, (e32, (e33, (e34, (e35, (e36, (e37, (e38, (e39, (e40, (e41, (e42, (e43, (e44, (e45, (e46, (e47, (e48, (e49, (e50, (e51, (e52, (e53, (e54, (e55, (e56, (e57, (e58, (e59, POTHOS_PP_NIL))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_61(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, (e30, (e31, (e32, (e33, (e34, (e35, (e36, (e37, (e38, (e39, (e40, (e41, (e42, (e43, (e44, (e45, (e46, (e47, (e48, (e49, (e50, (e51, (e52, (e53, (e54, (e55, (e56, (e57, (e58, (e59, (e60, POTHOS_PP_NIL)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_62(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, (e30, (e31, (e32, (e33, (e34, (e35, (e36, (e37, (e38, (e39, (e40, (e41, (e42, (e43, (e44, (e45, (e46, (e47, (e48, (e49, (e50, (e51, (e52, (e53, (e54, (e55, (e56, (e57, (e58, (e59, (e60, (e61, POTHOS_PP_NIL))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_63(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, (e30, (e31, (e32, (e33, (e34, (e35, (e36, (e37, (e38, (e39, (e40, (e41, (e42, (e43, (e44, (e45, (e46, (e47, (e48, (e49, (e50, (e51, (e52, (e53, (e54, (e55, (e56, (e57, (e58, (e59, (e60, (e61, (e62, POTHOS_PP_NIL)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))
# define POTHOS_PP_TUPLE_TO_LIST_64(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) (e0, (e1, (e2, (e3, (e4, (e5, (e6, (e7, (e8, (e9, (e10, (e11, (e12, (e13, (e14, (e15, (e16, (e17, (e18, (e19, (e20, (e21, (e22, (e23, (e24, (e25, (e26, (e27, (e28, (e29, (e30, (e31, (e32, (e33, (e34, (e35, (e36, (e37, (e38, (e39, (e40, (e41, (e42, (e43, (e44, (e45, (e46, (e47, (e48, (e49, (e50, (e51, (e52, (e53, (e54, (e55, (e56, (e57, (e58, (e59, (e60, (e61, (e62, (e63, POTHOS_PP_NIL))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))
#
# endif
