/// \file vcruntime.h
/// \copyright (c) 2025 ywx9.com

#pragma once
#include "abc.h"
#include "sal.h"
#include "vadefs.h"

#define _HAS_CXX17 1
#define _HAS_CXX20 1
#define _HAS_CXX23 1

// attribute

#ifndef _HAS_NODISCARD
#ifndef __has_cpp_attribute
#define _HAS_NODISCARD 0
#elif __has_cpp_attribute(nodiscard) >= 201603L
#define _HAS_NODISCARD 1
#else
#define _HAS_NODISCARD 0
#endif
#endif
#if _HAS_NODISCARD
#define _NODISCARD [[nodiscard]]
#else
#define _NODISCARD
#endif

#ifndef _MSVC_CONSTEXPR
#ifdef _MSVC_CONSTEXPR_ATTRIBUTE
#define _MSVC_CONSTEXPR [[msvc::constexpr]]
#else
#define _MSVC_CONSTEXPR
#endif
#endif

// call

#if defined _M_CEE_PURE || defined MRTDLL
#define __CLRCALL_OR_CDECL __clrcall
#define __CLR_OR_THIS_CALL __clrcall
#else
#define __CLRCALL_OR_CDECL __cdecl
#define __CLR_OR_THIS_CALL
#endif

#ifdef _M_CEE_PURE
#define __CLRCALL_PURE_OR_CDECL __clrcall
#else
#define __CLRCALL_PURE_OR_CDECL __cdecl
#endif

#define __CRTDECL __CLRCALL_PURE_OR_CDECL

// #ifndef _VCRT_COMPILER_PREPROCESSOR

// #if defined(RC_INVOKED) || defined(Q_MOC_RUN)
// #define _VCRT_COMPILER_PREPROCESSOR 0
// #else
// #define _VCRT_COMPILER_PREPROCESSOR 1
// #endif
// #endif

// #ifndef _UCRT
// #define _UCRT
// #endif

// #ifndef _CRTIMP
// #define _VCRT_DEFINED_CRTIMP
// #if defined CRTDLL && defined _CRTBLD
// #define _CRTIMP __declspec(dllexport)
// #else
// #ifdef _DLL
// #define _CRTIMP __declspec(dllimport)
// #else
// #define _CRTIMP
// #endif
// #endif
// #endif

// #pragma warning(push)
// #pragma warning(disable : _VCRUNTIME_DISABLED_WARNINGS)

// #if defined __cplusplus

// #define _CRT_BEGIN_C_HEADER __pragma(pack(push, _CRT_PACKING)) extern "C" {

// #define _CRT_END_C_HEADER \
//   }                       \
//   __pragma(pack(pop))

// #elif defined __midl

// #define _CRT_BEGIN_C_HEADER cpp_quote("__pragma(pack(push, _CRT_PACKING))") cpp_quote("extern \"C\" {")

// #define _CRT_END_C_HEADER cpp_quote("}") cpp_quote("__pragma(pack(pop))")

// #else

// #define _CRT_BEGIN_C_HEADER __pragma(pack(push, _CRT_PACKING))

// #define _CRT_END_C_HEADER __pragma(pack(pop))

// #endif

// _CRT_BEGIN_C_HEADER

// #ifndef _HAS_EXCEPTIONS
// #ifdef _KERNEL_MODE
// #define _HAS_EXCEPTIONS 0
// #else
// #define _HAS_EXCEPTIONS 1
// #endif /* _KERNEL_MODE */
// #endif /* _HAS_EXCEPTIONS */

// #define _CRT_STRINGIZE_(x) #x
// #define _CRT_STRINGIZE(x) _CRT_STRINGIZE_(x)

// #define _CRT_WIDE_(s) L##s
// #define _CRT_WIDE(s) _CRT_WIDE_(s)

// #define _CRT_CONCATENATE_(a, b) a##b
// #define _CRT_CONCATENATE(a, b) _CRT_CONCATENATE_(a, b)

// #define _CRT_UNPARENTHESIZE_(...) __VA_ARGS__
// #define _CRT_UNPARENTHESIZE(...) _CRT_UNPARENTHESIZE_ __VA_ARGS__

// #ifndef _VCRTIMP
// #if defined _CRTIMP && !defined _VCRT_DEFINED_CRTIMP
// #define _VCRTIMP _CRTIMP
// #elif defined _VCRT_BUILD && defined CRTDLL && !defined _VCRT_SAT_1
// #define _VCRTIMP __declspec(dllexport)
// #else
// #define _VCRTIMP
// #endif
// #endif

// #ifndef _MRTIMP
// #if defined MRTDLL && defined _CRTBLD && !defined _M_CEE_PURE
// #define _MRTIMP __declspec(dllexport)
// #else
// #define _MRTIMP
// #endif
// #endif

// #if defined _M_CEE_PURE || defined MRTDLL
// #define __CLRCALL_OR_CDECL __clrcall
// #define __CLR_OR_THIS_CALL __clrcall
// #else
// #define __CLRCALL_OR_CDECL __cdecl
// #define __CLR_OR_THIS_CALL
// #endif

// #define _VCRT_NOALIAS __declspec(noalias)
// #define _VCRT_RESTRICT __declspec(restrict)

// #if !defined _MSC_VER || _MSC_VER >= 1900
// #define _VCRT_ALLOCATOR __declspec(allocator)
// #else
// #define _VCRT_ALLOCATOR
// #endif

// #if defined _M_CEE && defined _M_X64
// #define _VCRT_JIT_INTRINSIC __declspec(jitintrinsic)
// #else
// #define _VCRT_JIT_INTRINSIC
// #endif

// #ifdef __midl
// #define _VCRT_ALIGN(x)
// #else
// #define _VCRT_ALIGN(x) __declspec(align(x))
// #endif

// #ifndef _CONST_RETURN
// #ifdef __cplusplus
// #define _CRT_CONST_CORRECT_OVERLOADS
// #define _CONST_RETURN const
// #else
// #define _CONST_RETURN
// #endif
// #endif

// #define _WConst_return _CONST_RETURN

// #ifdef _WIN64
// typedef unsigned __int64 size_t;
// typedef __int64 ptrdiff_t;
// typedef __int64 intptr_t;
// #else
// typedef unsigned int size_t;
// typedef int ptrdiff_t;
// typedef int intptr_t;
// #endif

// #if defined __cplusplus
// typedef bool __vcrt_bool;
// #elif defined __midl

// typedef char __vcrt_bool;
// #else
// typedef _Bool __vcrt_bool;
// #endif

// #ifndef _SIZE_T_DEFINED
// #define _SIZE_T_DEFINED
// #endif

// #ifndef _PTRDIFF_T_DEFINED
// #define _PTRDIFF_T_DEFINED
// #endif

// #ifndef _INTPTR_T_DEFINED
// #define _INTPTR_T_DEFINED
// #endif

// #ifndef _WCHAR_T_DEFINED
// #define _WCHAR_T_DEFINED
// typedef unsigned short wchar_t;
// #endif

// #ifndef NULL
// #ifdef __cplusplus
// #define NULL 0
// #else
// #define NULL ((void*)0)
// #endif
// #endif

// #if defined _M_X64 || defined _M_ARM || defined _M_ARM64
// #define _UNALIGNED __unaligned
// #else
// #define _UNALIGNED
// #endif

// #if defined _M_ARM64EC
// #define __security_check_cookie __security_check_cookie_arm64ec
// #endif

// #ifdef __cplusplus
// extern "C++" {
// template<typename _CountofType, size_t _SizeOfArray>
// char (*__countof_helper(_UNALIGNED _CountofType (&_Array)[_SizeOfArray]))[_SizeOfArray];

// #define __crt_countof(_Array) (sizeof(*__countof_helper(_Array)) + 0)
// }
// #else
// #define __crt_countof(_Array) (sizeof(_Array) / sizeof(_Array[0]))
// #endif

// #if defined(_M_IX86) && defined(_CRT_LEGACY_X86_FLT_EXCEPTIONS) && !defined(_M_CEE_PURE)
// #pragma comment(lib, "legacy_x86_flt_exceptions")
// #endif

// #ifdef __cplusplus
// #if defined(_MSVC_LANG) && _MSVC_LANG > __cplusplus
// #define _STL_LANG _MSVC_LANG
// #else
// #define _STL_LANG __cplusplus
// #endif
// #else
// #define _STL_LANG 0L
// #endif

// #undef _STL_LANG

// #if _HAS_CXX20 && !_HAS_CXX17
// #error _HAS_CXX20 must imply _HAS_CXX17.
// #endif

// #if _HAS_CXX23 && !_HAS_CXX20
// #error _HAS_CXX23 must imply _HAS_CXX20.
// #endif

// #ifndef _HAS_NODISCARD
// #ifndef __has_cpp_attribute
// #define _HAS_NODISCARD 0
// #elif __has_cpp_attribute(nodiscard) >= 201603L
// #define _HAS_NODISCARD 1
// #else
// #define _HAS_NODISCARD 0
// #endif
// #endif

// #if _HAS_NODISCARD
// #define _NODISCARD [[nodiscard]]
// #else
// #define _NODISCARD
// #endif

// #pragma push_macro("msvc")
// #pragma push_macro("constexpr")
// #undef msvc
// #undef constexpr

// #ifndef _MSVC_CONSTEXPR
// #ifdef _MSVC_CONSTEXPR_ATTRIBUTE
// #define _MSVC_CONSTEXPR [[msvc::constexpr]]
// #else
// #define _MSVC_CONSTEXPR
// #endif
// #endif

// #pragma pop_macro("constexpr")
// #pragma pop_macro("msvc")

// #define _CRT_DEPRECATE_TEXT(_Text) __declspec(deprecated(_Text))

// #if defined _CRT_SECURE_NO_DEPRECATE && !defined _CRT_SECURE_NO_WARNINGS
// #define _CRT_SECURE_NO_WARNINGS
// #endif

// #ifndef _CRT_INSECURE_DEPRECATE
// #ifdef _CRT_SECURE_NO_WARNINGS
// #define _CRT_INSECURE_DEPRECATE(_Replacement)
// #else
// #define _CRT_INSECURE_DEPRECATE(_Replacement)                                                  \
//   _CRT_DEPRECATE_TEXT("This function or variable may be unsafe. Consider using " #_Replacement \
//                       " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. "        \
//                       "See online help for details.")
// #endif
// #endif

// #if defined _CRT_SECURE_DEPRECATE_MEMORY && !defined _CRT_SECURE_WARNINGS_MEMORY
// #define _CRT_SECURE_WARNINGS_MEMORY
// #endif

// #ifndef _CRT_INSECURE_DEPRECATE_MEMORY
// #ifndef _CRT_SECURE_WARNINGS_MEMORY
// #define _CRT_INSECURE_DEPRECATE_MEMORY(_Replacement)
// #else
// #define _CRT_INSECURE_DEPRECATE_MEMORY(_Replacement) _CRT_INSECURE_DEPRECATE(_Replacement)
// #endif
// #endif

// #if !defined _M_CEE && !defined __midl
// void __cdecl __security_init_cookie(void);

// #if defined(_M_IX86)
// void __fastcall __security_check_cookie(_In_ uintptr_t _StackCookie);
// __declspec(noreturn) void __cdecl __report_gsfailure(void);
// #elif defined(_M_ARM64EC)
// void __cdecl __security_check_cookie_arm64ec(_In_ uintptr_t _StackCookie);
// __declspec(noreturn) void __cdecl __report_gsfailure(_In_ uintptr_t _StackCookie);
// #else
// void __cdecl __security_check_cookie(_In_ uintptr_t _StackCookie);
// __declspec(noreturn) void __cdecl __report_gsfailure(_In_ uintptr_t _StackCookie);
// #endif
// #endif

// extern uintptr_t __security_cookie;

// #ifndef _VCRT_BUILD
// #define __vcrt_malloc_normal(_Size) malloc(_Size)
// #define __vcrt_calloc_normal(_Count, _Size) calloc(_Count, _Size)
// #define __vcrt_free_normal(_Memory) free(_Memory)
// #endif

// _CRT_END_C_HEADER

// #pragma warning(pop)

// #endif
