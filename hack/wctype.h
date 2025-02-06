#pragma once
#include "abc.h"
#include "corecrt.h"

__ywstd_cfunc_begin

using wint_t = unsigned short;
using wctype_t = unsigned short;
using wctrans_t = wchar_t;

int __cdecl iswalnum(wint_t);
int __cdecl iswalpha(wint_t);
int __cdecl iswlower(wint_t);
int __cdecl iswupper(wint_t);
int __cdecl iswdigit(wint_t);
int __cdecl iswxdigit(wint_t);
int __cdecl iswcntrl(wint_t);
int __cdecl iswgraph(wint_t);
int __cdecl iswspace(wint_t);
int __cdecl iswblank(wint_t);
int __cdecl iswprint(wint_t);
int __cdecl iswpunct(wint_t);
int __cdecl iswctype(wint_t, wctype_t);
wctype_t __cdecl wctype(const char*);

wint_t __cdecl towupper(wint_t);
wint_t __cdecl towlower(wint_t);
wint_t __cdecl towctrans(wint_t, wctrans_t);
wctrans_t __cdecl wctrans(const char*);

__ywstd_cfunc_end
