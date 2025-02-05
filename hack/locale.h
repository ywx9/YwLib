#pragma once
#include "abc.h"
#include "corecrt.h"

__ywstd_cfunc_begin

struct lconv {
  char *decimal_point, *thousands_sep, *grouping, *int_curr_symbol, *currency_symbol;
  char *mon_decimal_point, *mon_thousands_sep, *mon_grouping, *positive_sign, *negative_sign;
  char int_frac_digits, frac_digits, p_cs_precedes, p_sep_by_space;
  char n_cs_precedes, n_sep_by_space, p_sign_posn, n_sign_posn;
  wchar_t *_W_decimal_point, *_W_thousands_sep, *_W_int_curr_symbol, *_W_currency_symbol;
  wchar_t *_W_mon_decimal_point, *_W_mon_thousands_sep, *_W_positive_sign, *_W_negative_sign;
};

struct tm;

char* __cdecl setlocale(int, const char*);
lconv* __cdecl localeconv();

__ywstd_cfunc_end

#define _ENABLE_PER_THREAD_LOCALE 0x0001
#define _DISABLE_PER_THREAD_LOCALE 0x0002
#define _ENABLE_PER_THREAD_LOCALE_GLOBAL 0x0010
#define _DISABLE_PER_THREAD_LOCALE_GLOBAL 0x0020
#define _ENABLE_PER_THREAD_LOCALE_NEW 0x0100
#define _DISABLE_PER_THREAD_LOCALE_NEW 0x0200
