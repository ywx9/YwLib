#pragma once
#include "abc.h"
#include "vcruntime.h"

__ywstd_cfunc_begin

struct alignas(16) SETJMP_FLOAT128 { unsigned long long Part[2]; };
using jmp_buf = SETJMP_FLOAT128[16];
__ywstd_export int __cdecl setjmp(jmp_buf);
[[noreturn]] void __cdecl longjmp(jmp_buf, int) noexcept(false);

__ywstd_cfunc_end
