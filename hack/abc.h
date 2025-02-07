/// \file abc.h
#pragma once // clang-format off

#ifndef __ywstd_is_exported
#ifndef __ywstd_export
#define __ywstd_export
#define __ywstd_is_exported false
#else
#define __ywstd_is_exported true
#define _BUILD_STD_MODULE
#endif
#endif

#ifndef __ywstd_is_imported
#ifndef __ywstd_import
#define __ywstd_is_imported 0
#else
#define __ywstd_is_imported 1
#endif
#endif

#if __ywstd_is_exported or __ywstd_is_imported
#define _CSTD ::
#define __ywstd_cfunc_begin extern "C" {
#define __ywstd_cfunc_end }
#else
#define _CSTD ::__ywstd_cfunc::
#define __ywstd_cfunc_begin extern "C" { namespace __ywstd_cfunc {
#define __ywstd_cfunc_end } }
#endif

#ifndef __ywstd_nodiscard
#define __ywstd_nodiscard [[nodiscard]]
#endif

#pragma region [cassert] -------------------------------------------------------
#ifndef assert
#ifdef NDEBUG
#define assert(e) (void(0))
#else
#define assert(e) (void(!(e) && (_CSTD _wassert(L#e, __ywstd_wide(__FILE__), unsigned(__LINE__)), 0)))
#endif
#endif
#pragma endregion // ------------------------------------------------- [cassert]
#pragma region [cerrno] --------------------------------------------------------
#ifndef errno
#define errno (*_CSTD _errno())
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
#define FE_DFL_ENV (&_CSTD _Fenv1)
#pragma endregion // --------------------------------------------------- [cfenv]
