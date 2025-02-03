/// \file vcruntime_new.h
/// \copyright (c) 2025 ywx9.com

#pragma once
#include "abc.h"
#include "vcruntime.h"

#if !__ywstd_is_imported
__ywstd_export extern "C++" {

namespace std {

enum class align_val_t : size_t {};

struct nothrow_t { explicit nothrow_t() = default; };
extern const nothrow_t nothrow;

}

[[nodiscard]] __declspec(allocator) void* __cdecl operator new(size_t);
[[nodiscard]] __declspec(allocator) void* __cdecl operator new(size_t, const ::std::nothrow_t&) noexcept;
[[nodiscard]] __declspec(allocator) void* __cdecl operator new[](size_t);
[[nodiscard]] __declspec(allocator) void* __cdecl operator new[](size_t, const ::std::nothrow_t&) noexcept;
void __cdecl operator delete(void*) noexcept;
void __cdecl operator delete(void* _Block, const ::std::nothrow_t&) noexcept;
void __cdecl operator delete[](void*) noexcept;
void __cdecl operator delete[](void*, const ::std::nothrow_t&) noexcept;
void __cdecl operator delete(void*, size_t) noexcept;
void __cdecl operator delete[](void*, size_t) noexcept;
[[nodiscard]] __declspec(allocator) void* __cdecl operator new(size_t, ::std::align_val_t);
[[nodiscard]] __declspec(allocator) void* __cdecl operator new(size_t, ::std::align_val_t, const ::std::nothrow_t&) noexcept;
[[nodiscard]] __declspec(allocator) void* __cdecl operator new[](size_t, ::std::align_val_t);
[[nodiscard]] __declspec(allocator) void* __cdecl operator new[](size_t, ::std::align_val_t, const ::std::nothrow_t&) noexcept;
void __cdecl operator delete(void*, ::std::align_val_t) noexcept;
void __cdecl operator delete(void*, ::std::align_val_t, const ::std::nothrow_t&) noexcept;
void __cdecl operator delete[](void*, ::std::align_val_t) noexcept;
void __cdecl operator delete[](void*, ::std::align_val_t, const ::std::nothrow_t&) noexcept;
void __cdecl operator delete(void*, size_t, ::std::align_val_t) noexcept;
void __cdecl operator delete[](void*, size_t, ::std::align_val_t) noexcept;

[[nodiscard]] constexpr void* __cdecl operator new(size_t size, void* where) noexcept { (void)size; return where; }
[[nodiscard]] inline void* __cdecl operator new[](size_t size, void* where) noexcept { (void)size; return where; }
inline void __cdecl operator delete(void*, void*) noexcept { return; }
inline void __cdecl operator delete[](void*, void*) noexcept {}
}
#endif
