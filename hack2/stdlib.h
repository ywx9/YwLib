#pragma once
#include "abc.h"
#include "corecrt.h"

__ywstd_cfunc_begin // clang-format off

__ywstd_export int __cdecl ___mb_cur_max_func();

struct div_t { int quot, rem; };
struct ldiv_t { long quot, rem; };
struct lldiv_t { long long quot, rem; };
using atexit_handler = void (__cdecl*)();
int __cdecl atexit(atexit_handler);
int __cdecl at_quick_exit(atexit_handler);
[[noreturn]] void __cdecl abort();
[[noreturn]] void __cdecl exit(int);
[[noreturn]] void __cdecl _Exit(int);
[[noreturn]] void __cdecl quick_exit(int);
char* __cdecl getenv(const char*);
int __cdecl system(const char*);
void __cdecl free(void*);
__declspec(allocator) void* __cdecl malloc(size_t);
__declspec(allocator) void* __cdecl calloc(size_t, size_t);
__declspec(allocator) void* __cdecl realloc(void*, size_t);
using compare_pred = int (__cdecl*)(const void*, const void*);
void __cdecl qsort(void*, size_t, size_t, compare_pred);
void* __cdecl bsearch(const void*, const void*, size_t, size_t, compare_pred);
int __cdecl mblen(const char*, size_t);
int __cdecl mbtowc(wchar_t*, const char*, size_t);
int __cdecl wctomb(char*, wchar_t);
size_t __cdecl mbstowcs(wchar_t*, const char*, size_t);
size_t __cdecl wcstombs(char*, const wchar_t*, size_t);
int __cdecl atoi(const char*);
long __cdecl atol(const char*);
long long __cdecl atoll(const char*);
double __cdecl atof(const char*);
long __cdecl strtol(const char*, char**, int);
long long __cdecl strtoll(const char*, char**, int);
unsigned long __cdecl strtoul(const char*, char**, int);
unsigned long long __cdecl strtoull(const char*, char**, int);
float __cdecl strtof(const char*, char**);
double __cdecl strtod(const char*, char**);
long double __cdecl strtold(const char*, char**);
int __cdecl rand();
void __cdecl srand(unsigned);
int __cdecl abs(int);
long __cdecl labs(long);
long long __cdecl llabs(long long);
div_t __cdecl div(int, int);
ldiv_t __cdecl ldiv(long, long);
lldiv_t __cdecl lldiv(long long, long long);

// clang-format on

// int __cdecl _fseeki64_nolock(FILE*, __int64, int);

void __cdecl _lock_file(FILE*);
void __cdecl _unlock_file(FILE*);
// int __cdecl _fclose_nolock(FILE*);
int __cdecl _fflush_nolock(FILE*);
// int __cdecl _fgetc_nolock(FILE*);
// int __cdecl _fputc_nolock(int, FILE*);
// size_t __cdecl _fread_nolock(void*, size_t, size_t, FILE*);
// size_t __cdecl _fread_nolock_s(void*, size_t, size_t, size_t, FILE*);
// int __cdecl _fseek_nolock(FILE*, long, int);
// long __cdecl _ftell_nolock(FILE*);
// __int64 __cdecl _ftelli64_nolock(FILE*);
size_t __cdecl _fwrite_nolock(const void*, size_t, size_t, FILE*);
// int __cdecl _getc_nolock(FILE*);
// int __cdecl _putc_nolock(int, FILE*);
// int __cdecl _ungetc_nolock(int, FILE*);

// <__msvc_filebuf.hpp> requires

int __cdecl _fseeki64(FILE*, __int64, int);

errno_t __cdecl _get_stream_buffer_pointers(FILE*, char***, char***, int**);

__ywstd_cfunc_end // clang-format on

// <bit> requires

extern "C" unsigned short __cdecl _byteswap_ushort(unsigned short);
extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
extern "C" unsigned long long __cdecl _byteswap_uint64(unsigned long long);
