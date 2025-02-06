#pragma once
#include "abc.h"
#include "corecrt.h"

__ywstd_cfunc_begin

size_t __cdecl mbrtoc16(char16_t*, const char*, size_t, mbstate_t*);
size_t __cdecl c16rtomb(char*, char16_t, mbstate_t*);
size_t __cdecl mbrtoc32(char32_t*, const char*, size_t, mbstate_t*);
size_t __cdecl c32rtomb(char*, char32_t, mbstate_t*);

__ywstd_cfunc_end
