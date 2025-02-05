#pragma once
#include "abc.h"

__ywstd_cfunc_begin

using sig_atomic_t = int;
using signal_handler = void (__cdecl*)(int);
signal_handler __cdecl signal(int, signal_handler);
int __cdecl raise(int);

__ywstd_cfunc_end
