/// \file
#pragma once
#include "abc.h"

__ywstd_cfunc_begin

__ywstd_export FILE* __cdecl __acrt_iob_func(unsigned);

__declspec(noinline) inline unsigned long long* __cdecl __local_stdio_printf_options() {
  static unsigned long long _OptionsStorage;
  return &_OptionsStorage;
}
__declspec(noinline) inline unsigned long long* __cdecl __local_stdio_scanf_options() {
  static unsigned long long _OptionsStorage;
  return &_OptionsStorage;
}

__ywstd_cfunc_end

#define _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS (*_CSTD __local_stdio_printf_options())
#define _CRT_INTERNAL_LOCAL_SCANF_OPTIONS  (*_CSTD __local_stdio_scanf_options ())

#define _CRT_INTERNAL_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION (1ULL << 0)
#define _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR       (1ULL << 1)
#define _CRT_INTERNAL_PRINTF_LEGACY_WIDE_SPECIFIERS           (1ULL << 2)
#define _CRT_INTERNAL_PRINTF_LEGACY_MSVCRT_COMPATIBILITY      (1ULL << 3)
#define _CRT_INTERNAL_PRINTF_LEGACY_THREE_DIGIT_EXPONENTS     (1ULL << 4)
#define _CRT_INTERNAL_PRINTF_STANDARD_ROUNDING                (1ULL << 5)

#define _CRT_INTERNAL_SCANF_SECURECRT                   (1ULL << 0)
#define _CRT_INTERNAL_SCANF_LEGACY_WIDE_SPECIFIERS      (1ULL << 1)
#define _CRT_INTERNAL_SCANF_LEGACY_MSVCRT_COMPATIBILITY (1ULL << 2)
