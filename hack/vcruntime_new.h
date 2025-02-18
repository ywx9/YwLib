#pragma once
#include "abc.h"
extern "C++" {

  namespace std {
enum class align_val_t : size_t {};
struct nothrow_t { explicit nothrow_t() = default; };
extern nothrow_t const nothrow;
}

_NODISCARD __declspec(allocator) void* __cdecl operator new(size_t);
_NODISCARD __declspec(allocator) void* __cdecl operator new(size_t, const ::std::nothrow_t&) noexcept;
_NODISCARD __declspec(allocator) void* __cdecl operator new[](size_t);
_NODISCARD __declspec(allocator) void* __cdecl operator new[](size_t, const ::std::nothrow_t&) noexcept;

void __cdecl operator delete(void*) noexcept;
void __cdecl operator delete(void*, const ::std::nothrow_t&) noexcept;
void __cdecl operator delete[](void*) noexcept;
void __cdecl operator delete[](void*, const ::std::nothrow_t&) noexcept;
void __cdecl operator delete(void*, size_t) noexcept;
void __cdecl operator delete[](void*, size_t) noexcept;

_NODISCARD __declspec(allocator) void* __cdecl operator new(size_t, ::std::align_val_t);
_NODISCARD __declspec(allocator) void* __cdecl operator new(size_t, ::std::align_val_t, const ::std::nothrow_t&) noexcept;
_NODISCARD __declspec(allocator) void* __cdecl operator new[](size_t, ::std::align_val_t);
_NODISCARD __declspec(allocator) void* __cdecl operator new[](size_t, ::std::align_val_t, const ::std::nothrow_t&) noexcept;

void __cdecl operator delete(void*, ::std::align_val_t) noexcept;
void __cdecl operator delete(void*, ::std::align_val_t, const ::std::nothrow_t&) noexcept;
void __cdecl operator delete[](void*, ::std::align_val_t) noexcept;
void __cdecl operator delete[](void*, ::std::align_val_t, const ::std::nothrow_t&) noexcept;
void __cdecl operator delete(void*, size_t, ::std::align_val_t) noexcept;
void __cdecl operator delete[](void*, size_t, ::std::align_val_t) noexcept;

_NODISCARD _MSVC_CONSTEXPR inline void* __cdecl operator new(size_t n, void* where) noexcept { (void)n; return where; }
inline void __cdecl operator delete(void*, void*) noexcept { return; }
_NODISCARD inline void* __cdecl operator new[](size_t n, void* where) noexcept { (void)n; return where; }
inline void __cdecl operator delete[](void*, void*) noexcept {}
}
