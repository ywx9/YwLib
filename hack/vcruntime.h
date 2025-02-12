#pragma once
#include "abc.h"

#define __CLR_OR_THIS_CALL
#define __CLRCALL_OR_CDECL __cdecl
#define __CLRCALL_PURE_OR_CDECL __cdecl
#define __CRTDECL __cdecl

#define _ACRTIMP
#define _CRT_ASSERT 2
#define _CRT_GUARDOVERFLOW
#define _CRT_PACKING 8
#define _CRT_SECURE_INVALID_PARAMETER(expr) ::_invalid_parameter_noinfo_noreturn()
#define _CRTIMP2
#define _CRTIMP2_PURE
#define _HAS_CXX17 1
#define _HAS_CXX20 1
#define _HAS_CXX23 1
#define _HAS_EXCEPTIONS 1
#define _MRTIMP2
#define _MSVC_CONSTEXPR
#define _NODISCARD
#define _PGLOBAL
#define _RPTF0(...)

extern "C" {
[[noreturn]] void __cdecl _invalid_parameter_noinfo_noreturn();
[[noreturn]] void __cdecl _invoke_watson(const wchar_t*, const wchar_t*, const wchar_t*, unsigned, unsigned long long);
}

#define _Analysis_assume_(...)
#define _Deref_post_opt_valid_
#define _Guarded_by_(...)
#define _In_
#define _In_opt_
#define _In_range_(...)
#define _In_reads_(...)
#define _In_z_
#define _Inout_
#define _Inout_opt_
#define _Out_
#define _Out_opt_
#define _Out_writes_(...)
#define _Out_writes_all_(...)
#define _Out_writes_bytes_(...)
#define _Out_writes_opt_(...)
#define _Out_writes_z_(...)
#define _Post_equal_to_(...)
#define _Post_readable_size_(...)
#define _Post_satisfies_(...)
#define _Pre_satisfies_(...)
#define _Ret_range_(...)
#define _Ret_z_
#define _Success_(...)
#define _When_(...)
