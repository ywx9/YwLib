#pragma once // clang-format off
#include "abc.h"

__ywstd_cfunc_begin

__ywstd_nodiscard size_t __stdcall __std_get_string_size_without_trailing_whitespace(const char*, size_t) noexcept;
__ywstd_nodiscard size_t __stdcall __std_system_error_allocate_message(unsigned long, char**) noexcept;
void __stdcall __std_system_error_deallocate_message(char*) noexcept;

__ywstd_cfunc_end
