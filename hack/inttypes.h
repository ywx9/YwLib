#pragma once
#include "abc.h"
#include "corecrt.h"
#include "stdint.h"

__ywstd_cfunc_begin // clang-format off

struct imaxdiv_t { intmax_t quot, rem; };

intmax_t __cdecl imaxabs(intmax_t);
imaxdiv_t __cdecl imaxdiv(intmax_t, intmax_t);
intmax_t __cdecl strtoimax(const char*, char**, int);
intmax_t __cdecl _strtoimax_l(const char*, char**, int, _locale_t);
uintmax_t __cdecl strtoumax(const char*, char**, int);
uintmax_t __cdecl _strtoumax_l(const char*, char**, int, _locale_t);
intmax_t __cdecl wcstoimax(const wchar_t*, wchar_t**, int);
intmax_t __cdecl _wcstoimax_l(const wchar_t*, wchar_t**, int, _locale_t);
uintmax_t __cdecl wcstoumax(const wchar_t*, wchar_t**, int);
uintmax_t __cdecl _wcstoumax_l(const wchar_t*, wchar_t**, int, _locale_t);

__ywstd_cfunc_end // clang-format on
