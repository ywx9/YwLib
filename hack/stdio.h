#pragma once
#include "abc.h"
#include "corecrt.h"
#include "corecrt_wstdio.h"

__ywstd_cfunc_begin

#define BUFSIZ 512
#define EOF (-1)
#define _IOFBF 0x0000
#define _IOLBF 0x0040
#define _IONBF 0x0004
#define L_tmpnam 260
#define SEEK_CUR 1
#define SEEK_END 2
#define SEEK_SET 0
#define FILENAME_MAX 260
#define FOPEN_MAX 20
#define TMP_MAX 2147483647

  using size_t = unsigned long long;
using fpos_t = long long;

void __cdecl clearerr(FILE*);
int __cdecl fclose(FILE*);
int __cdecl feof(FILE*);
int __cdecl ferror(FILE*);
int __cdecl fflush(FILE*);
int __cdecl fgetc(FILE*);
int __cdecl fgetpos(FILE*, fpos_t*);
char* __cdecl fgets(char*, int, FILE*);
FILE* __cdecl fopen(const char*, const char*);
int __cdecl fputc(int, FILE*);
int __cdecl fputs(const char*, FILE*);
size_t __cdecl fread(void*, size_t, size_t, FILE*);
FILE* __cdecl freopen(const char*, const char*, FILE*);
int __cdecl fsetpos(FILE*, fpos_t const*);
int __cdecl fseek(FILE*, long, int);
long __cdecl ftell(FILE*);
size_t __cdecl fwrite(const void*, size_t, size_t, FILE*);
int __cdecl getc(FILE*);
int __cdecl getchar();
void __cdecl perror(const char*);
int __cdecl putc(int, FILE*);
int __cdecl putchar(int);
int __cdecl puts(const char*);
int __cdecl remove(const char*);
int __cdecl rename(const char*, const char*);
void __cdecl rewind(FILE*);
void __cdecl setbuf(FILE*, char*);
int __cdecl setvbuf(FILE*, char*, int, size_t);
FILE* __cdecl tmpfile();
char* tmpnam(char*);

int __cdecl __stdio_common_vfprintf(unsigned __int64, FILE*, const char*, _locale_t, va_list);
int __cdecl __stdio_common_vfprintf_s(unsigned __int64, FILE*, const char*, _locale_t, va_list);
// int __cdecl __stdio_common_vfprintf_p(unsigned __int64, FILE*, const char*, _locale_t, va_list);

inline int __cdecl _vfprintf_l(FILE* const stream, const char* const format, const _locale_t locale, va_list args) {
  return _CSTD __stdio_common_vfprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stream, format, locale, args);
}

inline int __cdecl vfprintf(FILE* const stream, const char* const format, va_list args) {
  return _CSTD _vfprintf_l(stream, format, NULL, args);
}

inline int __cdecl _vfprintf_s_l(FILE* const stream, const char* const format, const _locale_t locale, va_list args) {
  return _CSTD __stdio_common_vfprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stream, format, locale, args);
}

inline int __cdecl vfprintf_s(FILE* const stream, const char* const format, va_list args) {
  return _CSTD _vfprintf_s_l(stream, format, NULL, args);
}

// inline int __cdecl _vfprintf_p_l(FILE* const stream, const char* const format, const _locale_t locale, va_list args)
// {
//   return _CSTD __stdio_common_vfprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stream, format, locale, args);
// }

// inline int __cdecl _vfprintf_p(FILE* const stream, const char* const format, va_list args) {
//   return _CSTD _vfprintf_p_l(stream, format, NULL, args);
// }

inline int __cdecl _vprintf_l(const char* const format, const _locale_t locale, va_list args) {
  return _CSTD _vfprintf_l(stdout, format, locale, args);
}

inline int __cdecl vprintf(const char* const format, va_list args) {
  return _CSTD _vfprintf_l(stdout, format, NULL, args);
}

inline int __cdecl _vprintf_s_l(const char* const format, const _locale_t locale, va_list args) {
  return _CSTD _vfprintf_s_l(stdout, format, locale, args);
}

inline int __cdecl vprintf_s(const char* const format, va_list args) {
  return _CSTD _vfprintf_s_l(stdout, format, NULL, args);
}

// inline int __cdecl _vprintf_p_l(const char* const format, const _locale_t locale, va_list args) {
//   return _CSTD _vfprintf_p_l(stdout, format, locale, args);
// }

// inline int __cdecl _vprintf_p(const char* const format, va_list args) {
//   return _CSTD _vfprintf_p_l(stdout, format, NULL, args);
// }

inline int __cdecl _fprintf_l(FILE* const stream, const char* const format, const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  int result = _CSTD _vfprintf_l(stream, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl fprintf(FILE* const stream, const char* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  int result = _CSTD _vfprintf_l(stream, format, NULL, args);
  __crt_va_end(args);
  return result;
}

int __cdecl _set_printf_count_output(int _Value);
int __cdecl _get_printf_count_output();

inline int __cdecl _fprintf_s_l(FILE* const stream, const char* const format, const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  int result = _CSTD _vfprintf_s_l(stream, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl fprintf_s(FILE* const stream, const char* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  int result = _CSTD _vfprintf_s_l(stream, format, NULL, args);
  __crt_va_end(args);
  return result;
}

// inline int __cdecl _fprintf_p_l(FILE* const stream, const char* const format, const _locale_t locale, ...) {
//   va_list args;
//   __crt_va_start(args, locale);
//   int result = _CSTD _vfprintf_p_l(stream, format, locale, args);
//   __crt_va_end(args);
//   return result;
// }

// inline int __cdecl _fprintf_p(FILE* const stream, const char* const format, ...) {
//   va_list args;
//   __crt_va_start(args, format);
//   int result = _CSTD _vfprintf_p_l(stream, format, NULL, args);
//   __crt_va_end(args);
//   return result;
// }

inline int __cdecl _printf_l(const char* const format, const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  int result = _CSTD _vfprintf_l(stdout, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl printf(const char* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  int result = _CSTD _vfprintf_l(stdout, format, NULL, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _printf_s_l(const char* const format, const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  int result = _CSTD _vfprintf_s_l(stdout, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl printf_s(const char* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  int result = _CSTD _vfprintf_s_l(stdout, format, NULL, args);
  __crt_va_end(args);
  return result;
}

// inline int __cdecl _printf_p_l(const char* const format, const _locale_t locale, ...) {
//   va_list args;
//   __crt_va_start(args, locale);
//   int result = _CSTD _vfprintf_p_l(stdout, format, locale, args);
//   __crt_va_end(args);
//   return result;
// }

// inline int __cdecl _printf_p(const char* const format, ...) {
//   va_list args;
//   __crt_va_start(args, format);
//   int result = _CSTD _vfprintf_p_l(stdout, format, NULL, args);
//   __crt_va_end(args);
//   return result;
// }

int __cdecl __stdio_common_vfscanf(unsigned __int64, FILE*, const char*, _locale_t, va_list);

inline int __cdecl _vfscanf_l(FILE* const stream, const char* const format, const _locale_t locale, va_list args) {
  return _CSTD __stdio_common_vfscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, stream, format, locale, args);
}

inline int __cdecl vfscanf(FILE* const stream, const char* const format, va_list args) {
  return _CSTD _vfscanf_l(stream, format, NULL, args);
}

inline int __cdecl _vfscanf_s_l(FILE* const stream, const char* const format, const _locale_t locale, va_list args) {
  const auto options = _CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT;
  return _CSTD __stdio_common_vfscanf(options, stream, format, locale, args);
}

inline int __cdecl vfscanf_s(FILE* const stream, const char* const format, va_list args) {
  return _CSTD _vfscanf_s_l(stream, format, NULL, args);
}

inline int __cdecl _vscanf_l(const char* const format, const _locale_t locale, va_list args) {
  return _CSTD _vfscanf_l(stdin, format, locale, args);
}

inline int __cdecl vscanf(const char* const format, va_list args) {
  return _CSTD _vfscanf_l(stdin, format, NULL, args);
}

inline int __cdecl _vscanf_s_l(const char* const format, const _locale_t locale, va_list args) {
  return _CSTD _vfscanf_s_l(stdin, format, locale, args);
}

inline int __cdecl vscanf_s(const char* const format, va_list args) {
  return _CSTD _vfscanf_s_l(stdin, format, NULL, args);
}

inline int __cdecl _fscanf_l(FILE* const stream, const char* const format, const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  int result = _CSTD _vfscanf_l(stream, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl fscanf(FILE* const stream, const char* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  int result = _CSTD _vfscanf_l(stream, format, NULL, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _fscanf_s_l(FILE* const stream, const char* const format, const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  int result = _CSTD _vfscanf_s_l(stream, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl fscanf_s(FILE* const stream, const char* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  int result = _CSTD _vfscanf_s_l(stream, format, NULL, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _scanf_l(const char* const format, const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  int result = _CSTD _vfscanf_l(stdin, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl scanf(const char* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  int result = _CSTD _vfscanf_l(stdin, format, NULL, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _scanf_s_l(const char* const format, const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  int result = _CSTD _vfscanf_s_l(stdin, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl scanf_s(const char* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  int result = _CSTD _vfscanf_s_l(stdin, format, NULL, args);
  __crt_va_end(args);
  return result;
}

int __cdecl __stdio_common_vsprintf(unsigned __int64, char*, size_t, const char*, _locale_t, va_list);
int __cdecl __stdio_common_vsprintf_s(unsigned __int64, char*, size_t, const char*, _locale_t, va_list);
int __cdecl __stdio_common_vsnprintf_s(unsigned __int64, char*, size_t, size_t, const char*, _locale_t, va_list);
int __cdecl __stdio_common_vsprintf_p(unsigned __int64, char*, size_t, const char*, _locale_t, va_list);

inline int __cdecl _vsnprintf_l(char* const buffer, size_t const count, const char* const format,
                                const _locale_t locale, va_list args) {
  const auto options = _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION;
  const int result = _CSTD __stdio_common_vsprintf(options, buffer, count, format, locale, args);
  return result < 0 ? -1 : result;
}

inline int __cdecl _vsnprintf(char* const buffer, size_t const count, const char* const format, va_list args) {
  return _CSTD _vsnprintf_l(buffer, count, format, NULL, args);
}

inline int __cdecl vsnprintf(char* const buffer, size_t const count, const char* const format, va_list args) {
  const auto options = _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR;
  const int result = __stdio_common_vsprintf(options, buffer, count, format, NULL, args);
  return result < 0 ? -1 : result;
}

inline int __cdecl _vsprintf_l(char* const buffer, const char* const format, const _locale_t locale, va_list args) {
  return _CSTD _vsnprintf_l(buffer, (size_t)-1, format, locale, args);
}

inline int __cdecl vsprintf(char* const buffer, const char* const format, va_list args) {
  return _CSTD _vsnprintf_l(buffer, (size_t)-1, format, NULL, args);
}

inline int __cdecl _vsprintf_s_l(char* const buffer, size_t const count, const char* const format,
                                 const _locale_t locale, va_list args) {
  const int result = __stdio_common_vsprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, buffer, count, format, locale, args);
  return result < 0 ? -1 : result;
}

inline int __cdecl vsprintf_s(char* const buffer, size_t const count, const char* const format, va_list args) {
  return _CSTD _vsprintf_s_l(buffer, count, format, NULL, args);
}

inline int __cdecl _vsprintf_p_l(char* const buffer, size_t const count, const char* const format,
                                 const _locale_t locale, va_list args) {
  const int result = __stdio_common_vsprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, buffer, count, format, locale, args);
  return result < 0 ? -1 : result;
}

inline int __cdecl _vsprintf_p(char* const buffer, size_t const count, const char* const format, va_list args) {
  return _CSTD _vsprintf_p_l(buffer, count, format, NULL, args);
}

inline int __cdecl _vsnprintf_s_l(char* const buffer, size_t const count, size_t const maxcount,
                                  const char* const format, const _locale_t locale, va_list args) {
  const auto options = _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS;
  const int result = _CSTD __stdio_common_vsnprintf_s(options, buffer, count, maxcount, format, locale, args);
  return result < 0 ? -1 : result;
}

inline int __cdecl _vsnprintf_s(char* const buffer, size_t const count, size_t const maxcount, const char* const format,
                                va_list args) {
  return _CSTD _vsnprintf_s_l(buffer, count, maxcount, format, NULL, args);
}

inline int __cdecl vsnprintf_s(char* const buffer, size_t const count, size_t const maxcount, const char* const format,
                               va_list args) {
  return _CSTD _vsnprintf_s_l(buffer, count, maxcount, format, NULL, args);
}

inline int __cdecl _vscprintf_l(const char* const format, const _locale_t locale, va_list args) {
  const auto options = _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR;
  const int result = __stdio_common_vsprintf(options, NULL, 0, format, locale, args);
  return result < 0 ? -1 : result;
}

inline int __cdecl _vscprintf(const char* const format, va_list args) { return _CSTD _vscprintf_l(format, NULL, args); }

inline int __cdecl _vscprintf_p_l(const char* const format, const _locale_t locale, va_list args) {
  const auto options = _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR;
  const int result = __stdio_common_vsprintf_p(options, NULL, 0, format, locale, args);
  return result < 0 ? -1 : result;
}

inline int __cdecl _vscprintf_p(const char* const format, va_list args) {
  return _CSTD _vscprintf_p_l(format, NULL, args);
}

inline int __cdecl _vsnprintf_c_l(char* const buffer, size_t const count, const char* const format,
                                  const _locale_t locale, va_list args) {
  const int result = __stdio_common_vsprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, buffer, count, format, locale, args);
  return result < 0 ? -1 : result;
}

inline int __cdecl _vsnprintf_c(char* const buffer, size_t const count, const char* const format, va_list args) {
  return _CSTD _vsnprintf_c_l(buffer, count, format, NULL, args);
}

inline int __cdecl _sprintf_l(char* const buffer, const char* const format, const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  int result = _CSTD _vsprintf_l(buffer, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl sprintf(char* const buffer, const char* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  int result = _CSTD _vsprintf_l(buffer, format, NULL, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _sprintf_s_l(char* const buffer, size_t const count, const char* const format,
                                const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  int result = _CSTD _vsprintf_s_l(buffer, count, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl sprintf_s(char* const buffer, size_t const count, const char* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  int result = _CSTD _vsprintf_s_l(buffer, count, format, NULL, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _sprintf_p_l(char* const buffer, size_t const count, const char* const format,
                                const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  int result = _CSTD _vsprintf_p_l(buffer, count, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _sprintf_p(char* const buffer, size_t const count, const char* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  int result = _CSTD _vsprintf_p_l(buffer, count, format, NULL, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _snprintf_l(char* const buffer, size_t const count, const char* const format, const _locale_t locale,
                               ...) {
  va_list args;
  __crt_va_start(args, locale);
  int result = _CSTD _vsnprintf_l(buffer, count, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl snprintf(char* const buffer, size_t const count, const char* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  int result = _CSTD vsnprintf(buffer, count, format, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _snprintf(char* const buffer, size_t const count, const char* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  int result = _CSTD _vsnprintf(buffer, count, format, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _snprintf_c_l(char* const buffer, size_t const count, const char* const format,
                                 const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  int result = _CSTD _vsnprintf_c_l(buffer, count, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _snprintf_c(char* const buffer, size_t const count, const char* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  int result = _CSTD _vsnprintf_c_l(buffer, count, format, NULL, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _snprintf_s_l(char* const buffer, size_t const count, size_t const maxcount,
                                 const char* const format, const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  int result = _CSTD _vsnprintf_s_l(buffer, count, maxcount, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _snprintf_s(char* const buffer, size_t const count, size_t const maxcount, const char* const format,
                               ...) {
  va_list args;
  __crt_va_start(args, format);
  int result = _CSTD _vsnprintf_s_l(buffer, count, maxcount, format, NULL, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _scprintf_l(const char* const format, const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  int result = _CSTD _vscprintf_l(format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _scprintf(const char* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  int result = _CSTD _vscprintf_l(format, NULL, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _scprintf_p_l(const char* const format, const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  int result = _CSTD _vscprintf_p_l(format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _scprintf_p(const char* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  int result = _CSTD _vscprintf_p(format, args);
  __crt_va_end(args);
  return result;
}

int __cdecl __stdio_common_vsscanf(unsigned __int64, const char*, size_t, const char*, _locale_t, va_list);

inline int __cdecl _vsscanf_l(const char* const buffer, const char* const format, const _locale_t locale,
                              va_list args) {
  return _CSTD __stdio_common_vsscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, buffer, (size_t)-1, format, locale, args);
}

inline int __cdecl vsscanf(const char* const buffer, const char* const format, va_list args) {
  return _CSTD _vsscanf_l(buffer, format, NULL, args);
}

inline int __cdecl _vsscanf_s_l(const char* const buffer, const char* const format, const _locale_t locale,
                                va_list args) {
  const auto options = _CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT;
  return _CSTD __stdio_common_vsscanf(options, buffer, (size_t)-1, format, locale, args);
}

inline int __cdecl vsscanf_s(const char* const buffer, const char* const format, va_list args) {
  return _CSTD _vsscanf_s_l(buffer, format, NULL, args);
}

inline int __cdecl _sscanf_l(const char* const buffer, const char* const format, const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  int result = _CSTD _vsscanf_l(buffer, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl sscanf(const char* const buffer, const char* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  int result = _CSTD _vsscanf_l(buffer, format, NULL, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _sscanf_s_l(const char* const buffer, const char* const format, const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  int result = _CSTD _vsscanf_s_l(buffer, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl sscanf_s(const char* const buffer, const char* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  int result = _CSTD vsscanf_s(buffer, format, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _snscanf_l(const char* const buffer, size_t const count, const char* const format,
                              const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  int result = _CSTD __stdio_common_vsscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, buffer, count, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _snscanf(const char* const buffer, size_t const count, const char* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  int result = _CSTD __stdio_common_vsscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, buffer, count, format, NULL, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _snscanf_s_l(const char* const buffer, size_t const count, const char* const format,
                                const _locale_t locale, ...) {
  va_list args;
  __crt_va_start(args, locale);
  const auto options = _CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT;
  int result = _CSTD __stdio_common_vsscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, buffer,
                                            count, format, locale, args);
  __crt_va_end(args);
  return result;
}

inline int __cdecl _snscanf_s(const char* const buffer, size_t const count, const char* const format, ...) {
  va_list args;
  __crt_va_start(args, format);
  const auto options = _CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT;
  const int result = _CSTD __stdio_common_vsscanf(options, buffer, count, format, NULL, args);
  __crt_va_end(args);
  return result;
}

__ywstd_cfunc_end
