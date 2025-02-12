#pragma once
// clang-format off

#ifndef __ywstd_is_exported
#ifndef __ywstd_export
#define __ywstd_export
#define __ywstd_is_exported (false)
#else
#define __ywstd_is_exported (true)
#define _BUILD_STD_MODULE
#endif
#endif

#ifndef __ywstd_is_imported
#ifndef __ywstd_import
#define __ywstd_is_imported (false)
#else
#define __ywstd_is_imported (true)
#endif
#endif

#if __ywstd_is_exported or __ywstd_is_imported
#define __ywstd_cfunc ::
#define __ywstd_cfunc_begin extern "C" {
#define __ywstd_cfunc_end }
#else
#define __ywstd_cfunc ::ywstd::
#define __ywstd_cfunc_begin extern "C" { namespace ywstd {
#define __ywstd_cfunc_end } }
#endif

#define __ywstd_wide_(x) L##x
#define __ywstd_wide(x) __ywstd_wide_(x)

#pragma region [cassert] -------------------------------------------------------
#ifndef assert
#ifdef NDEBUG
#define assert(e) (void(0))
#else
#define assert(e) (void(!(e) && (__ywstd_cfunc _wassert(L#e, __ywstd_wide(__FILE__), unsigned(__LINE__)), 0)))
#endif
#endif
#pragma endregion // ------------------------------------------------- [cassert]
#pragma region [cerrno] --------------------------------------------------------
#ifndef errno
#define errno (*__ywstd_cfunc _errno())
#endif

#define EPERM 1
#define ENOENT 2
#define ESRCH 3
#define EINTR 4
#define EIO 5
#define ENXIO 6
#define E2BIG 7
#define ENOEXEC 8
#define EBADF 9
#define ECHILD 10
#define EAGAIN 11
#define ENOMEM 12
#define EACCES 13
#define EFAULT 14
#define EBUSY 16
#define EEXIST 17
#define EXDEV 18
#define ENODEV 19
#define ENOTDIR 20
#define EISDIR 21
#define ENFILE 23
#define EMFILE 24
#define ENOTTY 25
#define EFBIG 27
#define ENOSPC 28
#define ESPIPE 29
#define EROFS 30
#define EMLINK 31
#define EPIPE 32
#define EDOM 33
#define EDEADLK 36
#define ENAMETOOLONG 38
#define ENOLCK 39
#define ENOSYS 40
#define ENOTEMPTY 41

#define _SECURECRT_ERRCODE_VALUES_DEFINED
#define EINVAL 22
#define ERANGE 34
#define EILSEQ 42
#define STRUNCATE 80

#define EDEADLOCK EDEADLK

#ifndef _CRT_NO_POSIX_ERROR_CODES
#define EADDRINUSE 100
#define EADDRNOTAVAIL 101
#define EAFNOSUPPORT 102
#define EALREADY 103
#define EBADMSG 104
#define ECANCELED 105
#define ECONNABORTED 106
#define ECONNREFUSED 107
#define ECONNRESET 108
#define EDESTADDRREQ 109
#define EHOSTUNREACH 110
#define EIDRM 111
#define EINPROGRESS 112
#define EISCONN 113
#define ELOOP 114
#define EMSGSIZE 115
#define ENETDOWN 116
#define ENETRESET 117
#define ENETUNREACH 118
#define ENOBUFS 119
#define ENODATA 120
#define ENOLINK 121
#define ENOMSG 122
#define ENOPROTOOPT 123
#define ENOSR 124
#define ENOSTR 125
#define ENOTCONN 126
#define ENOTRECOVERABLE 127
#define ENOTSOCK 128
#define ENOTSUP 129
#define EOPNOTSUPP 130
#define EOTHER 131
#define EOVERFLOW 132
#define EOWNERDEAD 133
#define EPROTO 134
#define EPROTONOSUPPORT 135
#define EPROTOTYPE 136
#define ETIME 137
#define ETIMEDOUT 138
#define ETXTBSY 139
#define EWOULDBLOCK 140
#endif
#pragma endregion // -------------------------------------------------- [cerrno]
#pragma region [cfenv] ---------------------------------------------------------
#define FE_TONEAREST 0x000
#define FE_DOWNWARD 0x100
#define FE_UPWARD 0x200
#define FE_TOWARDZERO 0x300
#define FE_ROUND_MASK 0x300
#define FE_INEXACT 0x01
#define FE_UNDERFLOW 0x02
#define FE_OVERFLOW 0x04
#define FE_DIVBYZERO 0x08
#define FE_INVALID 0x10
#define FE_ALL_EXCEPT 0x1f
#define FE_DFL_ENV (&__ywstd_cfunc _Fenv1)
#pragma endregion // --------------------------------------------------- [cfenv]
#pragma region [cfloat] --------------------------------------------------------
#define FLT_ROUNDS (__ywstd_cfunc __fpe_flt_rounds())
#define FLT_RADIX 2
#define DECIMAL_DIG 17
#ifdef _M_FP_FAST
#define FLT_EVAL_METHOD -1
#else
#define FLT_EVAL_METHOD 0
#endif
#define DBL_HAS_SUBNORM 1
#define FLT_HAS_SUBNORM 1
#define LDBL_HAS_SUBNORM DBL_HAS_SUBNORM
#define FLT_DIG 6
#define DBL_DIG 15
#define LDBL_DIG DBL_DIG
#define FLT_DECIMAL_DIG 9
#define DBL_DECIMAL_DIG 17
#define LDBL_DECIMAL_DIG DBL_DECIMAL_DIG
#define FLT_MANT_DIG 24
#define DBL_MANT_DIG 53
#define LDBL_MANT_DIG DBL_MANT_DIG
#define FLT_MAX_EXP 128
#define DBL_MAX_EXP 1024
#define LDBL_MAX_EXP DBL_MAX_EXP
#define FLT_MAX_10_EXP 38
#define DBL_MAX_10_EXP 308
#define LDBL_MAX_10_EXP DBL_MAX_10_EXP
#define FLT_MIN_EXP (-125)
#define DBL_MIN_EXP (-1021)
#define LDBL_MIN_EXP DBL_MIN_EXP
#define FLT_MIN_10_EXP (-37)
#define DBL_MIN_10_EXP (-307)
#define LDBL_MIN_10_EXP DBL_MIN_10_EXP
#define FLT_MAX 3.402823466e+38F
#define DBL_MAX 1.7976931348623158e+308
#define LDBL_MAX 1.7976931348623158e+308L
#define FLT_MIN 1.175494351e-38F
#define DBL_MIN 2.2250738585072014e-308
#define LDBL_MIN 2.2250738585072014e-308L
#define FLT_EPSILON 1.192092896e-07F
#define DBL_EPSILON 2.2204460492503131e-016
#define LDBL_EPSILON 2.2204460492503131e-016L
#define FLT_TRUE_MIN 1.401298464e-45F
#define DBL_TRUE_MIN 4.9406564584124654e-324
#define LDBL_TRUE_MIN 4.9406564584124654e-324L
#pragma endregion // -------------------------------------------------- [cfloat]
#pragma region [cinttypes] -----------------------------------------------------
#define PRId8 "hhd"
#define PRId16 "hd"
#define PRId32 "d"
#define PRId64 "lld"
#define PRIdLEAST8 PRId8
#define PRIdLEAST16 PRId16
#define PRIdLEAST32 PRId32
#define PRIdLEAST64 PRId64
#define PRIdFAST8 PRId8
#define PRIdFAST16 PRId32
#define PRIdFAST32 PRId32
#define PRIdFAST64 PRId64
#define PRIdMAX PRId64
#define PRIdPTR PRId64
#define PRIi8 "hhi"
#define PRIi16 "hi"
#define PRIi32 "i"
#define PRIi64 "lli"
#define PRIiLEAST8 PRIi8
#define PRIiLEAST16 PRIi16
#define PRIiLEAST32 PRIi32
#define PRIiLEAST64 PRIi64
#define PRIiFAST8 PRIi8
#define PRIiFAST16 PRIi32
#define PRIiFAST32 PRIi32
#define PRIiFAST64 PRIi64
#define PRIiMAX PRIi64
#define PRIiPTR PRIi64
#define PRIo8 "hho"
#define PRIo16 "ho"
#define PRIo32 "o"
#define PRIo64 "llo"
#define PRIoLEAST8 PRIo8
#define PRIoLEAST16 PRIo16
#define PRIoLEAST32 PRIo32
#define PRIoLEAST64 PRIo64
#define PRIoFAST8 PRIo8
#define PRIoFAST16 PRIo32
#define PRIoFAST32 PRIo32
#define PRIoFAST64 PRIo64
#define PRIoMAX PRIo64
#define PRIoPTR PRIo64
#define PRIu8 "hhu"
#define PRIu16 "hu"
#define PRIu32 "u"
#define PRIu64 "llu"
#define PRIuLEAST8 PRIu8
#define PRIuLEAST16 PRIu16
#define PRIuLEAST32 PRIu32
#define PRIuLEAST64 PRIu64
#define PRIuFAST8 PRIu8
#define PRIuFAST16 PRIu32
#define PRIuFAST32 PRIu32
#define PRIuFAST64 PRIu64
#define PRIuMAX PRIu64
#define PRIuPTR PRIu64
#define PRIx8 "hhx"
#define PRIx16 "hx"
#define PRIx32 "x"
#define PRIx64 "llx"
#define PRIxLEAST8 PRIx8
#define PRIxLEAST16 PRIx16
#define PRIxLEAST32 PRIx32
#define PRIxLEAST64 PRIx64
#define PRIxFAST8 PRIx8
#define PRIxFAST16 PRIx32
#define PRIxFAST32 PRIx32
#define PRIxFAST64 PRIx64
#define PRIxMAX PRIx64
#define PRIxPTR PRIx64
#define PRIX8 "hhX"
#define PRIX16 "hX"
#define PRIX32 "X"
#define PRIX64 "llX"
#define PRIXLEAST8 PRIX8
#define PRIXLEAST16 PRIX16
#define PRIXLEAST32 PRIX32
#define PRIXLEAST64 PRIX64
#define PRIXFAST8 PRIX8
#define PRIXFAST16 PRIX32
#define PRIXFAST32 PRIX32
#define PRIXFAST64 PRIX64
#define PRIXMAX PRIX64
#define PRIXPTR PRIX64
#define SCNd8 "hhd"
#define SCNd16 "hd"
#define SCNd32 "d"
#define SCNd64 "lld"
#define SCNdLEAST8 SCNd8
#define SCNdLEAST16 SCNd16
#define SCNdLEAST32 SCNd32
#define SCNdLEAST64 SCNd64
#define SCNdFAST8 SCNd8
#define SCNdFAST16 SCNd32
#define SCNdFAST32 SCNd32
#define SCNdFAST64 SCNd64
#define SCNdMAX SCNd64
#define SCNdPTR SCNd64
#define SCNi8 "hhi"
#define SCNi16 "hi"
#define SCNi32 "i"
#define SCNi64 "lli"
#define SCNiLEAST8 SCNi8
#define SCNiLEAST16 SCNi16
#define SCNiLEAST32 SCNi32
#define SCNiLEAST64 SCNi64
#define SCNiFAST8 SCNi8
#define SCNiFAST16 SCNi32
#define SCNiFAST32 SCNi32
#define SCNiFAST64 SCNi64
#define SCNiMAX SCNi64
#define SCNiPTR SCNi64
#define SCNo8 "hho"
#define SCNo16 "ho"
#define SCNo32 "o"
#define SCNo64 "llo"
#define SCNoLEAST8 SCNo8
#define SCNoLEAST16 SCNo16
#define SCNoLEAST32 SCNo32
#define SCNoLEAST64 SCNo64
#define SCNoFAST8 SCNo8
#define SCNoFAST16 SCNo32
#define SCNoFAST32 SCNo32
#define SCNoFAST64 SCNo64
#define SCNoMAX SCNo64
#define SCNoPTR SCNo64
#define SCNu8 "hhu"
#define SCNu16 "hu"
#define SCNu32 "u"
#define SCNu64 "llu"
#define SCNuLEAST8 SCNu8
#define SCNuLEAST16 SCNu16
#define SCNuLEAST32 SCNu32
#define SCNuLEAST64 SCNu64
#define SCNuFAST8 SCNu8
#define SCNuFAST16 SCNu32
#define SCNuFAST32 SCNu32
#define SCNuFAST64 SCNu64
#define SCNuMAX SCNu64
#define SCNuPTR SCNu64
#define SCNx8 "hhx"
#define SCNx16 "hx"
#define SCNx32 "x"
#define SCNx64 "llx"
#define SCNxLEAST8 SCNx8
#define SCNxLEAST16 SCNx16
#define SCNxLEAST32 SCNx32
#define SCNxLEAST64 SCNx64
#define SCNxFAST8 SCNx8
#define SCNxFAST16 SCNx32
#define SCNxFAST32 SCNx32
#define SCNxFAST64 SCNx64
#define SCNxMAX SCNx64
#define SCNxPTR SCNx64
#pragma endregion // ----------------------------------------------- [cinttypes]
#pragma region [climits] -------------------------------------------------------
#define CHAR_BIT 8
#define MB_LEN_MAX 5
#define SCHAR_MIN (-128)
#define SCHAR_MAX 127
#define UCHAR_MAX 0xff
#ifndef _CHAR_UNSIGNED
#define CHAR_MIN SCHAR_MIN
#define CHAR_MAX SCHAR_MAX
#else
#define CHAR_MIN 0
#define CHAR_MAX UCHAR_MAX
#endif
#define SHRT_MIN (-32768)
#define SHRT_MAX 32767
#define USHRT_MAX 0xffff
#define INT_MIN (-2147483647 - 1)
#define INT_MAX 2147483647
#define UINT_MAX 0xffffffff
#define LONG_MIN (-2147483647L - 1)
#define LONG_MAX 2147483647L
#define ULONG_MAX 0xffffffffUL
#define LLONG_MAX 9223372036854775807i64
#define LLONG_MIN (-9223372036854775807i64 - 1)
#define ULLONG_MAX 0xffffffffffffffffui64
#pragma endregion // ------------------------------------------------- [climits]
#pragma region [clocale] -------------------------------------------------------
#ifndef NULL
#define NULL 0
#endif
#define LC_ALL 0
#define LC_COLLATE 1
#define LC_CTYPE 2
#define LC_MONETARY 3
#define LC_NUMERIC 4
#define LC_TIME 5
#pragma endregion // ------------------------------------------------- [clocale]
#pragma region [cmath] ---------------------------------------------------------
#define MATH_ERRNO        1
#define MATH_ERREXCEPT    2
#define math_errhandling  (MATH_ERRNO | MATH_ERREXCEPT)
#define FP_INFINITE  1
#define FP_NAN       2
#define FP_NORMAL    (-1)
#define FP_SUBNORMAL (-2)
#define FP_ZERO      0
#define INFINITY (static_cast<float>(1e300 * 1e300))
#define NAN (-static_cast<float>(INFINITY * 0.0f))
#define HUGE_VAL (static_cast<double>(INFINITY))
#define HUGE_VALF (static_cast<float>(INFINITY))
#define HUGE_VALL (static_cast<long double>(INFINITY))
#pragma endregion // --------------------------------------------------- [cmath]
#pragma region [csetjmp] -------------------------------------------------------
#define setjmp _setjmp
extern "C" struct alignas(16) SETJMP_FLOAT128 { unsigned long long Part[2]; };
using jmp_buf = SETJMP_FLOAT128[16];
#pragma endregion // ------------------------------------------------- [csetjmp]
#pragma region [csignal] -------------------------------------------------------
#define SIG_DFL (reinterpret_cast<void (__cdecl*)(int)>(0))
#define SIG_IGN (reinterpret_cast<void (__cdecl*)(int)>(1))
#define SIG_GET (reinterpret_cast<void (__cdecl*)(int)>(2))
#define SIG_SGE (reinterpret_cast<void (__cdecl*)(int)>(3))
#define SIG_ACK (reinterpret_cast<void (__cdecl*)(int)>(4))
#define SIG_DIE (reinterpret_cast<void (__cdecl*)(int)>(5))
#define SIG_ERR (reinterpret_cast<void (__cdecl*)(int)>(-1))
#define SIGINT 2
#define SIGILL 4
#define SIGFPE 8
#define SIGSEGV 11
#define SIGTERM 15
#define SIGBREAK 21
#define SIGABRT 22
#pragma endregion // ------------------------------------------------- [csignal]
#pragma region [cstdarg] -------------------------------------------------------
using va_list = char*;
#define __crt_va_start(ap, x) ((void)(::ywstd::cstdarg::va_check<decltype(x)>(), __ywstd_cfunc __va_start(&ap, x)))
#define __crt_va_end(ap) (void(ap = nullptr))
#define __crt_va_arg(ap, t) ((sizeof(t) > 8 || (sizeof(t) & (sizeof(t) - 1)) != 0) ? **(t**)((ap += 8) - 8) : *(t*)((ap += 8) - 8))
#pragma endregion // ------------------------------------------------- [cstdarg]
#pragma region [cstddef] -------------------------------------------------------
#ifndef NULL
#define NULL 0
#endif
#define offsetof(s,m) ((size_t)&reinterpret_cast<char const volatile&>((((s*)0)->m)))
#pragma endregion //------------------------------------------------- [stddef.h]
#pragma region[stdint.h] -------------------------------------------------------
#define INT8_MIN (-127i8 - 1)
#define INT16_MIN (-32767i16 - 1)
#define INT32_MIN (-2147483647i32 - 1)
#define INT64_MIN (-9223372036854775807i64 - 1)
#define INT8_MAX 127i8
#define INT16_MAX 32767i16
#define INT32_MAX 2147483647i32
#define INT64_MAX 9223372036854775807i64
#define UINT8_MAX 0xffui8
#define UINT16_MAX 0xffffui16
#define UINT32_MAX 0xffffffffui32
#define UINT64_MAX 0xffffffffffffffffui64
#define INT_LEAST8_MIN INT8_MIN
#define INT_LEAST16_MIN INT16_MIN
#define INT_LEAST32_MIN INT32_MIN
#define INT_LEAST64_MIN INT64_MIN
#define INT_LEAST8_MAX INT8_MAX
#define INT_LEAST16_MAX INT16_MAX
#define INT_LEAST32_MAX INT32_MAX
#define INT_LEAST64_MAX INT64_MAX
#define UINT_LEAST8_MAX UINT8_MAX
#define UINT_LEAST16_MAX UINT16_MAX
#define UINT_LEAST32_MAX UINT32_MAX
#define UINT_LEAST64_MAX UINT64_MAX
#define INT_FAST8_MIN INT8_MIN
#define INT_FAST16_MIN INT32_MIN
#define INT_FAST32_MIN INT32_MIN
#define INT_FAST64_MIN INT64_MIN
#define INT_FAST8_MAX INT8_MAX
#define INT_FAST16_MAX INT32_MAX
#define INT_FAST32_MAX INT32_MAX
#define INT_FAST64_MAX INT64_MAX
#define UINT_FAST8_MAX UINT8_MAX
#define UINT_FAST16_MAX UINT32_MAX
#define UINT_FAST32_MAX UINT32_MAX
#define UINT_FAST64_MAX UINT64_MAX
#define INTPTR_MIN INT64_MIN
#define INTPTR_MAX INT64_MAX
#define UINTPTR_MAX UINT64_MAX
#define INTMAX_MIN INT64_MIN
#define INTMAX_MAX INT64_MAX
#define UINTMAX_MAX UINT64_MAX
#define PTRDIFF_MIN INTPTR_MIN
#define PTRDIFF_MAX INTPTR_MAX
#ifndef SIZE_MAX
#define SIZE_MAX 0xffffffffffffffffui64
#endif
#define SIG_ATOMIC_MIN INT32_MIN
#define SIG_ATOMIC_MAX INT32_MAX
#define WCHAR_MIN 0x0000
#define WCHAR_MAX 0xffff
#define WINT_MIN 0x0000
#define WINT_MAX 0xffff
#define INT8_C(x) (x)
#define INT16_C(x) (x)
#define INT32_C(x) (x)
#define INT64_C(x) (x##LL)
#define UINT8_C(x) (x)
#define UINT16_C(x) (x)
#define UINT32_C(x) (x##U)
#define UINT64_C(x) (x##ULL)
#define INTMAX_C(x) INT64_C(x)
#define UINTMAX_C(x) UINT64_C(x)
#pragma endregion //------------------------------------------------- [stdint.h]
#pragma region [cstdio] --------------------------------------------------------
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
#define stdin  (__ywstd_cfunc __acrt_iob_func(0))
#define stdout (__ywstd_cfunc __acrt_iob_func(1))
#define stderr (__ywstd_cfunc __acrt_iob_func(2))
typedef struct _iobuf { void* _Placeholder; } FILE;
__ywstd_cfunc_begin
__ywstd_export struct __crt_locale_pointers {
  struct __crt_locale_data*    locinfo;
  struct __crt_multibyte_data* mbcinfo;
};
__ywstd_export using _locale_t = __crt_locale_pointers*;
#if not __ywstd_is_imported
__ywstd_export FILE* __cdecl __acrt_iob_func(unsigned);
__declspec(noinline) inline unsigned long long* __cdecl __local_stdio_printf_options() {
  static unsigned long long _OptionsStorage;
  return &_OptionsStorage;
}
__declspec(noinline) inline unsigned long long* __cdecl __local_stdio_scanf_options() {
  static unsigned long long _OptionsStorage;
  return &_OptionsStorage;
}
#endif
__ywstd_cfunc_end
#define _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS (*__ywstd_cfunc __local_stdio_printf_options())
#define _CRT_INTERNAL_LOCAL_SCANF_OPTIONS  (*__ywstd_cfunc __local_stdio_scanf_options ())
#define _CRT_INTERNAL_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION (1ULL << 0)
#define _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR       (1ULL << 1)
#define _CRT_INTERNAL_SCANF_SECURECRT                         (1ULL << 0)
#pragma endregion // -------------------------------------------------- [cstdio]
#pragma region [cstdib] --------------------------------------------------------
#ifndef NULL
#define NULL 0
#endif
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define RAND_MAX 0x7FFF
#define MB_CUR_MAX (__ywstd_cfunc __mb_cur_max_func())
#pragma endregion // -------------------------------------------------- [cstdib]
#pragma region [cstring] -------------------------------------------------------
#ifndef NULL
#define NULL 0
#endif
#pragma endregion // ------------------------------------------------- [cstring]
#pragma region [ctime] ---------------------------------------------------------
#ifndef NULL
#define NULL 0
#endif
#define CLOCKS_PER_SEC ((std::clock_t)1000)
#define TIME_UTC 1
struct tm {
  int tm_sec, tm_min, tm_hour;
  int tm_mday, tm_mon, tm_year;
  int tm_wday, tm_yday, tm_isdst;
};
#pragma endregion // --------------------------------------------------- [ctime]
#pragma region [cuchar] --------------------------------------------------------
#define __STDC_UTF_16__ 1
#define __STDC_UTF_32__ 1
typedef struct _Mbstatet {
  unsigned long _Wchar;
  unsigned short _Byte, _State;
} _Mbstatet;
using mbstate_t = _Mbstatet;
#pragma endregion // -------------------------------------------------- [cuchar]
#pragma region [cwchar] --------------------------------------------------------
#define WEOF (std::wint_t)(0xFFFF)
// NULL, WCHR_MIN and WCHR_MAX are already defined.
#pragma endregion // -------------------------------------------------- [cwchar]
#pragma region [cwctype] -------------------------------------------------------
// WEOF is already defined.
#pragma endregion // ------------------------------------------------- [cwctype]
#pragma region[xlocale] --------------------------------------------------------
#define _UPPER   0x01
#define _LOWER   0x02
#define _DIGIT   0x04
#define _SPACE   0x08
#define _PUNCT   0x10
#define _CONTROL 0x20
#define _BLANK   0x40
#define _HEX     0x80
#define _SH_DENYRW 0x10
#define _SH_DENYWR 0x20
#define _SH_DENYRD 0x30
#define _SH_DENYNO 0x40
#define _SH_SECURE 0x80
#pragma endregion //-------------------------------------------------- [xlocale]
#pragma region [emmintrin] -----------------------------------------------------
#define _MM_SHUFFLE2(x,y) (((x)<<1) | (y))
#define _mm_set_pd1(a)      ::_mm_set1_pd(a)
#define _mm_load_pd1(p)     ::_mm_load1_pd(p)
#define _mm_store_pd1(p, a) ::_mm_store1_pd((p), (a))
#define _mm_bslli_si128     ::_mm_slli_si128
#define _mm_bsrli_si128     ::_mm_srli_si128
#pragma endregion //------------------------------------------------ [emmintrin]
