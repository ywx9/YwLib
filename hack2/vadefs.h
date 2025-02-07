#pragma once
#include "abc.h"

#define _CRT_PACKING 8
#pragma pack(push, _CRT_PACKING)

// #ifndef _VCRUNTIME_DISABLED_WARNING_4339
// #ifdef _M_CEE_PURE
// #define _VCRUNTIME_DISABLED_WARNING_4339 4339
// #else
// #define _VCRUNTIME_DISABLED_WARNING_4339
// #endif
// #endif

// #ifndef _VCRUNTIME_DISABLED_WARNING_4412
// #ifdef _M_CEE_PURE
// #define _VCRUNTIME_DISABLED_WARNING_4412 4412
// #else
// #define _VCRUNTIME_DISABLED_WARNING_4412
// #endif
// #endif

// #ifndef _VCRUNTIME_EXTRA_DISABLED_WARNINGS
// #define _VCRUNTIME_EXTRA_DISABLED_WARNINGS
// #endif

// #ifndef _VCRUNTIME_DISABLED_WARNINGS
// #define _VCRUNTIME_DISABLED_WARNINGS                                                                             \
//   _VCRUNTIME_DISABLED_WARNING_4339 _VCRUNTIME_DISABLED_WARNING_4412 4514 4820 _VCRUNTIME_EXTRA_DISABLED_WARNINGS
// #endif

// #ifndef _W64
// #define _W64
// #endif

// #ifndef _ADDRESSOF
// #define _ADDRESSOF(v) (&const_cast<char&>(reinterpret_cast<const volatile char&>(v)))
// #endif

// #ifndef _SLOTSIZEOF
// #define _SLOTSIZEOF(t) (sizeof(t))
// #endif

// #ifndef _APALIGN
// #define _APALIGN(t, ap) (__alignof(t))
// #endif

extern "C" using va_list = char*;
__ywstd_export extern "C" void __cdecl __va_start(char**, ...);

extern "C++" template<typename T> constexpr bool __ywstd_va_check_ = true;
extern "C++" template<typename T> constexpr bool __ywstd_va_check_<T&> = false;
extern "C++" template<typename T> constexpr bool __ywstd_va_check_<T&&> = false;
__ywstd_export extern "C++" template<typename T> requires __ywstd_va_check_<T> struct __ywstd_va_check {};

#pragma pack(pop)
