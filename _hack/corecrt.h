/// \file corecrt.h
/// \copyright (c) 2025 ywx9.com

#pragma once
#include "vcruntime.h"

#if defined _CRTIMP && !defined _VCRT_DEFINED_CRTIMP
#define _ACRTIMP _CRTIMP
#elif !defined _CORECRT_BUILD && defined _DLL
#define _ACRTIMP __declspec(dllimport)
#else
#define _ACRTIMP
#endif

#define _CRT_GUARDOVERFLOW

#define _CRT_SECURE_INVALID_PARAMETER(expr) ::_invalid_parameter_noinfo_noreturn()

extern "C" {

void __cdecl _invalid_parameter_noinfo();
[[noreturn]] void __cdecl _invalid_parameter_noinfo_noreturn();
[[noreturn]] void __cdecl _invoke_watson(const wchar_t*, const wchar_t*, const wchar_t*, unsigned, unsigned long long);

}
