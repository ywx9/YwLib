#pragma once
#include "abc.h"
#include "corecrt.h"
#include "corecrt_stdio_config.h"

__ywstd_cfunc_begin

  using errno_t = int;
using wint_t = unsigned short;

struct FILE {
  void* _Placeholder;
};

export FILE* __cdecl __acrt_iob_func(unsigned);

wint_t __cdecl fgetwc(FILE*);
wint_t __cdecl fputwc(wchar_t, FILE*);
wint_t __cdecl getwc(FILE*);
wint_t __cdecl getwchar();
wchar_t* __cdecl fgetws(wchar_t*, int, FILE*);
int __cdecl fputws(const wchar_t*, FILE*);
wint_t __cdecl putwc(wchar_t, FILE*);
wint_t __cdecl putwchar(wchar_t);
wint_t __cdecl ungetwc(wint_t, FILE*);

int __cdecl __stdio_common_vfwprintf(unsigned __int64, FILE*, const wchar_t*, _locale_t, va_list);
int __cdecl __stdio_common_vfwprintf_s(unsigned __int64, FILE*, const wchar_t*, _locale_t, va_list);

inline int __cdecl _vfwprintf_l(FILE* const stream, const wchar_t* const format, const _locale_t locale, va_list args) {
  return _CSTD __stdio_common_vfwprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stream, format, locale, args);
}

inline int __cdecl vfwprintf(FILE* const stream, const wchar_t* const format, va_list args) {
  return _CSTD _vfwprintf_l(stream, format, NULL, args);
}

inline int __cdecl _vfwprintf_s_l(FILE* const stream, const wchar_t* const format, const _locale_t locale,
                                  va_list args) {
  return _CSTD __stdio_common_vfwprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stream, format, locale, args);
}

inline int __cdecl vfwprintf_s(FILE* const stream, const wchar_t* const format, va_list args) {
  return _CSTD _vfwprintf_s_l(stream, format, NULL, args);
}

inline int __cdecl _vwprintf_l(const wchar_t* const format, const _locale_t locale, va_list args) {
  return _CSTD _vfwprintf_l(stdout, format, locale, args);
}

inline int __cdecl vwprintf(const wchar_t* const format, va_list args) {
  return _CSTD _vfwprintf_l(stdout, format, NULL, args);
}

inline int __cdecl _vwprintf_s_l(const wchar_t* const format, const _locale_t locale, va_list args) {
  return _CSTD _vfwprintf_s_l(stdout, format, locale, args);
}

inline int __cdecl vwprintf_s(const wchar_t* const format, va_list args) {
  return _CSTD _vfwprintf_s_l(stdout, format, NULL, args);
}

inline int __cdecl _fwprintf_l(FILE* const stream, const wchar_t* const format, const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  const int result = _CSTD _vfwprintf_l(stream, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl fwprintf(FILE* const stream, const wchar_t* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  const int result = _CSTD _vfwprintf_l(stream, format, NULL, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _fwprintf_s_l(FILE* const stream, const wchar_t* const format, const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  const int result = _CSTD _vfwprintf_s_l(stream, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl fwprintf_s(FILE* const stream, const wchar_t* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  const int result = _CSTD _vfwprintf_s_l(stream, format, NULL, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _wprintf_l(const wchar_t* const format, const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  const int result = _CSTD _vfwprintf_l(stdout, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl wprintf(const wchar_t* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  const int result = _CSTD _vfwprintf_l(stdout, format, NULL, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _wprintf_s_l(const wchar_t* const format, const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  const int result = _CSTD _vfwprintf_s_l(stdout, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl wprintf_s(const wchar_t* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  const int result = _CSTD _vfwprintf_s_l(stdout, format, NULL, args);
  __crt_va_end(args);
  return result;
}

int __cdecl __stdio_common_vfwscanf(unsigned __int64, FILE*, const wchar_t*, _locale_t, va_list);

inline int __cdecl _vfwscanf_l(FILE* const stream, const wchar_t* const format, const _locale_t locale, va_list args) {
  return _CSTD __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, stream, format, locale, args);
}

inline int __cdecl vfwscanf(FILE* const stream, const wchar_t* const format, va_list args) {
  return _CSTD _vfwscanf_l(stream, format, NULL, args);
}

inline int __cdecl _vfwscanf_s_l(FILE* const stream, const wchar_t* const format, const _locale_t locale,
                                 va_list args) {
  return _CSTD __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, stream,
                                       format, locale, args);
}

inline int __cdecl vfwscanf_s(FILE* const stream, const wchar_t* const format, va_list args) {
  return _CSTD _vfwscanf_s_l(stream, format, NULL, args);
}

inline int __cdecl _vwscanf_l(const wchar_t* const format, const _locale_t locale, va_list args) {
  return _CSTD _vfwscanf_l(stdin, format, locale, args);
}

inline int __cdecl vwscanf(const wchar_t* const format, va_list args) {
  return _CSTD _vfwscanf_l(stdin, format, NULL, args);
}

inline int __cdecl _vwscanf_s_l(const wchar_t* const format, const _locale_t locale, va_list args) {
  return _CSTD _vfwscanf_s_l(stdin, format, locale, args);
}

inline int __cdecl vwscanf_s(const wchar_t* const format, va_list args) {
  return _CSTD _vfwscanf_s_l(stdin, format, NULL, args);
}

inline int __cdecl _fwscanf_l(FILE* const stream, const wchar_t* const format, const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  const int result = _CSTD _vfwscanf_l(stream, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl fwscanf(FILE* const stream, const wchar_t* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  const int result = _CSTD _vfwscanf_l(stream, format, NULL, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _fwscanf_s_l(FILE* const stream, const wchar_t* const format, const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  const int result = _CSTD _vfwscanf_s_l(stream, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl fwscanf_s(FILE* const stream, const wchar_t* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  const int result = _CSTD _vfwscanf_s_l(stream, format, NULL, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _wscanf_l(const wchar_t* const format, const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  const int result = _CSTD _vfwscanf_l(stdin, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl wscanf(const wchar_t* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  const int result = _CSTD _vfwscanf_l(stdin, format, NULL, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _wscanf_s_l(const wchar_t* const format, const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  const int result = _CSTD _vfwscanf_s_l(stdin, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl wscanf_s(const wchar_t* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  const int result = _CSTD _vfwscanf_s_l(stdin, format, NULL, args);
  __crt_va_end(args);
  return result;
}

int __cdecl __stdio_common_vswprintf(unsigned __int64, wchar_t*, size_t, const wchar_t*, _locale_t, va_list);
int __cdecl __stdio_common_vswprintf_s(unsigned __int64, wchar_t*, size_t, const wchar_t*, _locale_t, va_list);
int __cdecl __stdio_common_vsnwprintf_s(unsigned __int64, wchar_t*, size_t, size_t, const wchar_t*, _locale_t, va_list);

inline int __cdecl _vsnwprintf_l(wchar_t* const buffer, const size_t count, const wchar_t* const format,
                                 const _locale_t locale, va_list args) {
  const auto options = _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION;
  const int result = __stdio_common_vswprintf(options, buffer, count, format, locale, args);
  return result < 0 ? -1 : result;
}

inline int __cdecl _vsnwprintf_s_l(wchar_t* const buffer, const size_t count, const size_t maxcount,
                                   const wchar_t* const format, const _locale_t locale, va_list args) {
  const auto options = _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS;
  const int result = _CSTD __stdio_common_vsnwprintf_s(options, buffer, count, maxcount, format, locale, args);
  return result < 0 ? -1 : result;
}

inline int __cdecl _vsnwprintf_s(wchar_t* const buffer, const size_t count, const size_t maxcount,
                                 const wchar_t* const format, va_list args) {
  return _vsnwprintf_s_l(buffer, count, maxcount, format, NULL, args);
}

inline int __cdecl _vsnwprintf(wchar_t* buffer, size_t count, const wchar_t* format, va_list args) {
  return _vsnwprintf_l(buffer, count, format, NULL, args);
}

inline int __cdecl _vswprintf_c_l(wchar_t* const buffer, const size_t count, const wchar_t* const format,
                                  const _locale_t locale, va_list args) {
  const int result = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, buffer, count, format, locale, args);
  return result < 0 ? -1 : result;
}

inline int __cdecl _vswprintf_c(wchar_t* const buffer, const size_t count, const wchar_t* const format, va_list args) {
  return _vswprintf_c_l(buffer, count, format, NULL, args);
}

inline int __cdecl _vswprintf_l(wchar_t* const buffer, const size_t count, const wchar_t* const format,
                                const _locale_t locale, va_list args) {
  return _vswprintf_c_l(buffer, count, format, locale, args);
}

inline int __cdecl __vswprintf_l(wchar_t* const buffer, const wchar_t* const format, const _locale_t locale,
                                 va_list args) {
  return _vswprintf_l(buffer, (size_t)-1, format, locale, args);
}

inline int __cdecl _vswprintf(wchar_t* const buffer, const wchar_t* const format, va_list args) {
  return _vswprintf_l(buffer, (size_t)-1, format, NULL, args);
}

inline int __cdecl vswprintf(wchar_t* const buffer, const size_t count, const wchar_t* const format, va_list args) {
  return _vswprintf_c_l(buffer, count, format, NULL, args);
}

inline int __cdecl _vswprintf_s_l(wchar_t* const buffer, const size_t count, const wchar_t* const format,
                                  const _locale_t locale, va_list args) {
  const auto options = _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS;
  const int result = __stdio_common_vswprintf_s(options, buffer, count, format, locale, args);
  return result < 0 ? -1 : result;
}

inline int __cdecl vswprintf_s(wchar_t* const buffer, const size_t count, const wchar_t* const format, va_list args) {
  return _vswprintf_s_l(buffer, count, format, NULL, args);
}

inline int __cdecl _vscwprintf_l(const wchar_t* const format, const _locale_t locale, va_list args) {
  const auto options = _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR;
  const int result = __stdio_common_vswprintf(options, NULL, 0, format, locale, args);
  return result < 0 ? -1 : result;
}

inline int __cdecl _vscwprintf(const wchar_t* const format, va_list args) { return _vscwprintf_l(format, NULL, args); }

inline int __cdecl __swprintf_l(wchar_t* const buffer, const wchar_t* const format, const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  const int result = _CSTD __vswprintf_l(buffer, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _swprintf_l(wchar_t* const buffer, const size_t count, const wchar_t* const format,
                               const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  const int result = _CSTD _vswprintf_c_l(buffer, count, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _swprintf(wchar_t* const buffer, const wchar_t* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  const int result = _CSTD __vswprintf_l(buffer, format, NULL, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl swprintf(wchar_t* const buffer, const size_t count, const wchar_t* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  const int result = _CSTD _vswprintf_c_l(buffer, count, format, NULL, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _swprintf_s_l(wchar_t* const buffer, const size_t count, const wchar_t* const format,
                                 const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  const int result = _CSTD _vswprintf_s_l(buffer, count, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl swprintf_s(wchar_t* const buffer, const size_t count, const wchar_t* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  const int result = _CSTD _vswprintf_s_l(buffer, count, format, NULL, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _swprintf_c_l(wchar_t* const buffer, const size_t count, const wchar_t* const format,
                                 const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  const int result = _CSTD _vswprintf_c_l(buffer, count, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _swprintf_c(wchar_t* const buffer, const size_t count, const wchar_t* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  const int result = _CSTD _vswprintf_c_l(buffer, count, format, NULL, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _snwprintf_l(wchar_t* const buffer, const size_t count, const wchar_t* const format,
                                const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  const int result = _CSTD _vsnwprintf_l(buffer, count, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _snwprintf(wchar_t* buffer, size_t count, const wchar_t* format, ...) {
  va_list args;
  __crt_va_start(args, format);
  const int result = _CSTD _vsnwprintf_l(buffer, count, format, NULL, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _snwprintf_s_l(wchar_t* const buffer, const size_t count, const size_t maxcount,
                                  const wchar_t* const format, const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  const int result = _CSTD _vsnwprintf_s_l(buffer, count, maxcount, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _snwprintf_s(wchar_t* const buffer, const size_t count, const size_t maxcount,
                                const wchar_t* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  const int result = _CSTD _vsnwprintf_s_l(buffer, count, maxcount, format, NULL, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _scwprintf_l(const wchar_t* const format, const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  const int result = _CSTD _vscwprintf_l(format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _scwprintf(const wchar_t* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  const int result = _CSTD _vscwprintf_l(format, NULL, args);
  __crt_va_end(args);
  return result;
}

extern "C++" {

inline int swprintf(wchar_t* const buffer, const wchar_t* const format, ...) throw() {
  va_list args;
  __crt_va_start(args, format);
  const int result = _CSTD vswprintf(buffer, 0x7fffffff, format, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl vswprintf(wchar_t* const buffer, const wchar_t* const format, va_list args) throw() {
  return vswprintf(buffer, 0x7fffffff, format, args);
}

inline int _swprintf_l(wchar_t* const buffer, const wchar_t* const format, const _locale_t locale, ...) throw() {
  va_list args;
  __crt_va_start(args, locale);
  const int result = _CSTD _vswprintf_l(buffer, (size_t)-1, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _vswprintf_l(wchar_t* const buffer, const wchar_t* const format, const _locale_t locale,
                                va_list args) throw() {
  return _vswprintf_l(buffer, (size_t)-1, format, locale, args);
}
}

int __cdecl __stdio_common_vswscanf(unsigned __int64, const wchar_t*, size_t, const wchar_t*, _locale_t, va_list);

inline int __cdecl _vswscanf_l(const wchar_t* const buffer, const wchar_t* const format, const _locale_t locale,
                               va_list args) {
  return _CSTD __stdio_common_vswscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, buffer, (size_t)-1, format, locale, args);
}

inline int __cdecl vswscanf(const wchar_t* buffer, const wchar_t* format, va_list args) {
  return _vswscanf_l(buffer, format, NULL, args);
}

inline int __cdecl _vswscanf_s_l(const wchar_t* const buffer, const wchar_t* const format, const _locale_t locale,
                                 va_list args) {
  const auto options = _CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT;
  return _CSTD __stdio_common_vswscanf(options, buffer, (size_t)-1, format, locale, args);
}

inline int __cdecl vswscanf_s(const wchar_t* const buffer, const wchar_t* const format, va_list args) {
  return _vswscanf_s_l(buffer, format, NULL, args);
}

inline int __cdecl _vsnwscanf_l(const wchar_t* const buffer, const size_t count, const wchar_t* const format,
                                const _locale_t locale, va_list args) {
  return _CSTD __stdio_common_vswscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, buffer, count, format, locale, args);
}

inline int __cdecl _vsnwscanf_s_l(const wchar_t* const buffer, const size_t count, const wchar_t* const format,
                                  const _locale_t locale, va_list args) {
  const auto options = _CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT;
  return _CSTD __stdio_common_vswscanf(options, buffer, count, format, locale, args);
}

inline int __cdecl _swscanf_l(const wchar_t* const buffer, const wchar_t* const format, _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  const int result = _CSTD _vswscanf_l(buffer, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl swscanf(const wchar_t* const buffer, const wchar_t* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  const int result = _CSTD _vswscanf_l(buffer, format, NULL, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _swscanf_s_l(const wchar_t* const buffer, const wchar_t* const format, const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  const int result = _CSTD _vswscanf_s_l(buffer, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl swscanf_s(const wchar_t* const buffer, const wchar_t* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  const int result = _CSTD _vswscanf_s_l(buffer, format, NULL, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _snwscanf_l(const wchar_t* const buffer, const size_t count, const wchar_t* const format,
                               const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  const int result = _CSTD _vsnwscanf_l(buffer, count, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _snwscanf(const wchar_t* const buffer, const size_t count, const wchar_t* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  const int result = _CSTD _vsnwscanf_l(buffer, count, format, NULL, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _snwscanf_s_l(const wchar_t* const buffer, const size_t count, const wchar_t* const format,
                                 const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  const int result = _CSTD _vsnwscanf_s_l(buffer, count, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _snwscanf_s(const wchar_t* const buffer, const size_t count, const wchar_t* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  const int result = _CSTD _vsnwscanf_s_l(buffer, count, format, NULL, args);
  __crt_va_end(args);
  return result;
}

__ywstd_cfunc_end
