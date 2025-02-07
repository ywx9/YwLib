#pragma once
#include "abc.h"
#include "vcruntime_new.h"

extern "C++" {

_NODISCARD __declspec(allocator) void* __cdecl operator new(size_t, int, const char*, int);
_NODISCARD __declspec(allocator) void* __cdecl operator new[](size_t, int, const char*, int);
void __cdecl operator delete(void*, int, const char*, int) noexcept;
void __cdecl operator delete[](void*, int, const char*, int) noexcept;
}
