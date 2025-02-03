#pragma once

#ifndef __ywstd_export
#define __ywstd_export
#define __ywstd_is_exported 0
#define _BUILD_STD_MODULE
#else
#define __ywstd_is_exported 1
#endif

#ifndef __ywstd_import
#define __ywstd_is_imported 0
#else
#define __ywstd_is_imported 1
#endif

#ifndef __ywstd_switch
#if __ywstd_is_exported or __ywstd_is_imported
#define __ywstd_switch(x, y) x
#else
#define __ywstd_switch(x, y) y
#endif
#endif

#pragma region[macro constants]-------------------------------------------------

#define _UPPER 0x01
#define _LOWER 0x02
#define _DIGIT 0x04
#define _SPACE 0x08
#define _PUNCT 0x10
#define _CONTROL 0x20
#define _BLANK 0x40
#define _HEX 0x80

#define _SH_DENYRW 0x10
#define _SH_DENYWR 0x20
#define _SH_DENYRD 0x30
#define _SH_DENYNO 0x40
#define _SH_SECURE 0x80

#pragma endregion //-------------------------------------------[macro constants]
#pragma region[sal]-------------------------------------------------------------

#define _Analysis_assume_(...)
#define _Deref_post_opt_valid_
#define _In_
#define _In_opt_
#define _In_range_(...)
#define _In_reads_(...)
#define _In_z_
#define _Inout_
#define _Out_
#define _Out_opt_
#define _Out_writes_(...)
#define _Out_writes_all_(...)
#define _Out_writes_opt_(...)
#define _Out_writes_bytes_(...)
#define _Out_writes_z_(...)
#define _Post_equal_to_(...)
#define _Post_readable_size_(...)
#define _Pre_satisfies_(...)
#define _Ret_range_(...)
#define _Ret_z_
#define _Success_(...)
#define _When_(...)

#pragma endregion //-------------------------------------------------------[sal]
#pragma region[declspec]--------------------------------------------------------

#ifndef _PGLOBAL
#ifdef _M_CEE
#ifdef __cplusplus_cli
#define _PGLOBAL __declspec(process)
#else
#define _PGLOBAL
#endif
#else
#define _PGLOBAL
#endif
#endif

#pragma endregion //--------------------------------------------------[declspec]

extern "C++" {

template<typename T> inline T __ywstd_dummy_object{};
}

extern "C" {

struct fenv_t {
  unsigned long _Fe_ctl;
  unsigned long _Fe_stat;
};

struct FILE {
  void* _Placeholder;
};

struct imaxdiv_t {
  long long quot, rem;
};

struct lconv {
  char* decimal_point;
  char* thousands_sep;
  char* grouping;
  char* int_curr_symbol;
  char* currency_symbol;
  char* mon_decimal_point;
  char* mon_thousands_sep;
  char* mon_grouping;
  char* positive_sign;
  char* negative_sign;
  char int_frac_digits;
  char frac_digits;
  char p_cs_precedes;
  char p_sep_by_space;
  char n_cs_precedes;
  char n_sep_by_space;
  char p_sign_posn;
  char n_sign_posn;
  wchar_t* _W_decimal_point;
  wchar_t* _W_thousands_sep;
  wchar_t* _W_int_curr_symbol;
  wchar_t* _W_currency_symbol;
  wchar_t* _W_mon_decimal_point;
  wchar_t* _W_mon_thousands_sep;
  wchar_t* _W_positive_sign;
  wchar_t* _W_negative_sign;
};

struct _Mbstatet {
  unsigned long _Wchar;
  unsigned short _Byte;
  unsigned short _State;
};
using mbstate_t = _Mbstatet;

struct timespec {
  long long tv_sec;
  long tv_nsec;
};

struct tm {
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
};
}

#pragma region[variable arguments]----------------------------------------------
#define va_start(ap, x) __ywstd_switch(void(::__va_start(&ap, x)), void(0))
#define va_arg(ap, t)                                                                                  \
  ((sizeof(t) > 8 || !!(sizeof(t) & (sizeof(t) - 1))) ? **(t**)((ap += 8) - 8) : *(t*)((ap += 8) - 8))
#define va_end(ap) (void(ap = nullptr))
#define va_copy(dest, src) (void(dest = src))
#if __ywstd_is_exported
extern "C" {
using va_list = char*;
export void __cdecl __va_start(va_list*, ...);
}
#endif
#pragma endregion //----------------------------------------[variable arguments]
#pragma region[printf/scanf]----------------------------------------------------
#if __ywstd_is_exported
extern "C" {
export FILE* __cdecl __acrt_iob_func(unsigned);
inline unsigned long long __ywstd_printf_options{};
inline unsigned long long __ywstd_scanf_options{};
#define _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS (::__ywstd_printf_options)
#define _CRT_INTERNAL_LOCAL_SCANF_OPTIONS (::__ywstd_scanf_options)
#define _CRT_INTERNAL_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION (1ULL << 0)
#define _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR (1ULL << 1)
#define _CRT_INTERNAL_PRINTF_LEGACY_WIDE_SPECIFIERS (1ULL << 2)
#define _CRT_INTERNAL_PRINTF_LEGACY_MSVCRT_COMPATIBILITY (1ULL << 3)
#define _CRT_INTERNAL_PRINTF_LEGACY_THREE_DIGIT_EXPONENTS (1ULL << 4)
#define _CRT_INTERNAL_PRINTF_STANDARD_ROUNDING (1ULL << 5)
#define _CRT_INTERNAL_SCANF_SECURECRT (1ULL << 0)
#define _CRT_INTERNAL_SCANF_LEGACY_WIDE_SPECIFIERS (1ULL << 1)
#define _CRT_INTERNAL_SCANF_LEGACY_MSVCRT_COMPATIBILITY (1ULL << 2)
struct __crt_locale_pointers {
  struct __crt_locale_data* locinfo;
  struct __crt_multibyte_data* mbcinfo;
};
using _locale_t = __crt_locale_pointers*;
int __cdecl __stdio_common_vsprintf(unsigned long long, char*, size_t, const char*, _locale_t, char*);
int __cdecl __stdio_common_vfprintf(unsigned long long, FILE*, const char*, _locale_t, char*);
int __cdecl __stdio_common_vsscanf(unsigned long long, const char*, size_t, const char*, _locale_t, char*);
int __cdecl __stdio_common_vfscanf(unsigned long long, FILE*, const char*, _locale_t, char*);
int __cdecl __stdio_common_vswprintf(unsigned long long, wchar_t*, size_t, const wchar_t*, _locale_t, char*);
int __cdecl __stdio_common_vfwprintf(unsigned long long, FILE*, const wchar_t*, _locale_t, char*);
int __cdecl __stdio_common_vswscanf(unsigned long long, const wchar_t*, const wchar_t*, _locale_t, char*);
int __cdecl __stdio_common_vfwscanf(unsigned long long, FILE*, const wchar_t*, _locale_t, char*);

inline int __cdecl vsnprintf(char* buffer, size_t count, const char* format, char* args) {
  const auto options = _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR;
  const int result = ::__stdio_common_vsprintf(options, buffer, count, format, nullptr, args);
  return result < 0 ? -1 : result;
}
inline int __cdecl vsprintf(char* buffer, const char* format, char* args) {
  return ::vsnprintf(buffer, size_t(-1), format, args);
}
inline int __cdecl vfprintf(FILE* stream, const char* format, char* args) {
  const auto options = _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS;
  return ::__stdio_common_vfprintf(options, stream, format, nullptr, args);
}
inline int __cdecl vsscanf(const char* buffer, const char* format, char* args) {
  const auto options = _CRT_INTERNAL_LOCAL_SCANF_OPTIONS;
  return ::__stdio_common_vsscanf(options, buffer, size_t(-1), format, nullptr, args);
}
inline int __cdecl vfscanf(FILE* stream, const char* format, char* args) {
  const auto options = _CRT_INTERNAL_LOCAL_SCANF_OPTIONS;
  return ::__stdio_common_vfscanf(options, stream, format, nullptr, args);
}

// _vscprintf (for `std::to_string`)

inline int __cdecl _vscprintf(const char* format, va_list args) {
  const auto options = _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR;
  const int result = ::__stdio_common_vsprintf(options, nullptr, 0, format, nullptr, args);
  return result < 0 ? -1 : result;
}
inline int __cdecl _scprintf(const char* const format, ...) {
  va_list args;
  va_start(args, format);
  const int result = _vscprintf(format, args);
  va_end(args);
  return result;
}

// vsprintf_s (for `std::to_string`)

int __cdecl __stdio_common_vsprintf_s(unsigned __int64, char*, size_t, const char*, _locale_t, va_list);

inline int __cdecl vsprintf_s(char* buffer, size_t count, const char* format, va_list args) {
  const auto options = _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS;
  const int result = ::__stdio_common_vsprintf_s(options, buffer, count, format, nullptr, args);
  return result < 0 ? -1 : result;
}

inline int __cdecl sprintf_s(char* buffer, size_t count, const char* format, ...) {
  va_list args;
  va_start(args, format);
  const int result = vsprintf_s(buffer, count, format, args);
  va_end(args);
  return result;
}

// _scwprintf (for `std::to_wstring`)

inline int __cdecl _vscwprintf(const wchar_t* format, va_list args) {
  const auto options = _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR;
  const int result = ::__stdio_common_vswprintf(options, nullptr, 0, format, nullptr, args);
  return result < 0 ? -1 : result;
}

inline int __cdecl _scwprintf(const wchar_t* const format, ...) {
  va_list args;
  va_start(args, format);
  const int result = _vscwprintf(format, args);
  va_end(args);
  return result;
}

// swprintf_s (for `std::to_wstring`)

int __cdecl __stdio_common_vswprintf_s(unsigned __int64, wchar_t*, size_t, const wchar_t*, _locale_t, va_list);

inline int __cdecl vswprintf_s(wchar_t* buffer, size_t count, const wchar_t* format, va_list args) {
  const auto options = _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS;
  const int result = ::__stdio_common_vswprintf_s(options, buffer, count, format, nullptr, args);
  return result < 0 ? -1 : result;
}

inline int __cdecl swprintf_s(wchar_t* buffer, size_t count, const wchar_t* format, ...) {
  va_list args;
  va_start(args, format);
  const int result = vswprintf_s(buffer, count, format, args);
  va_end(args);
  return result;
}
}
#endif
#define stdin (__ywstd_switch(::__acrt_iob_func(0), &::__ywstd_dummy_object<::FILE>))
#define stdout (__ywstd_switch(::__acrt_iob_func(1), &::__ywstd_dummy_object<::FILE>))
#define stderr (__ywstd_switch(::__acrt_iob_func(2), &::__ywstd_dummy_object<::FILE>))
#pragma endregion //----------------------------------------------[printf/scanf]
#pragma region[external functions]---------------------------------------------
extern "C" {

#define __MACHINECALL_CDECL_OR_DEFAULT // because _M_X64

// byteswap

unsigned short __cdecl _byteswap_ushort(unsigned short);
unsigned long __cdecl _byteswap_ulong(unsigned long);
unsigned __int64 __cdecl _byteswap_uint64(unsigned __int64);

// iso_volatile

__int8 __iso_volatile_load8(const volatile __int8*);
__int16 __iso_volatile_load16(const volatile __int16*);
__int32 __iso_volatile_load32(const volatile __int32*);
__int64 __iso_volatile_load64(const volatile __int64*);

void __iso_volatile_store8(volatile __int8*, __int8);
void __iso_volatile_store16(volatile __int16*, __int16);
void __iso_volatile_store32(volatile __int32*, __int32);
void __iso_volatile_store64(volatile __int64*, __int64);

// shift128

unsigned __int64 __shiftleft128(unsigned __int64, unsigned __int64, unsigned char);
unsigned __int64 __shiftright128(unsigned __int64, unsigned __int64, unsigned char);

// ReadWriteBarrier

void _ReadWriteBarrier();

// Interlocked

long _InterlockedCompareExchange(volatile long*, long, long);
unsigned char _InterlockedCompareExchange128(volatile __int64*, __int64, __int64, __int64*);
long _InterlockedDecrement(volatile long*);
long _InterlockedExchange(volatile long*, long);
long _InterlockedIncrement(volatile long*);

// misc

unsigned __int64 _umul128(unsigned __int64, unsigned __int64, unsigned __int64*);
}
#pragma endregion //----------------------------------------[external functions]
