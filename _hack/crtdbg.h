/// \file crtdbg.h
/// \copyright (c) 2025 ywx9.com

#pragma once
#include "corecrt.h"

#define _CRT_WARN           0
#define _CRT_ERROR          1
#define _CRT_ASSERT         2
#define _CRT_ERRCNT         3

#define _FREE_BLOCK      0
#define _NORMAL_BLOCK    1
#define _CRT_BLOCK       2
#define _IGNORE_BLOCK    3
#define _CLIENT_BLOCK    4
#define _MAX_BLOCKS      5

#define _CrtDbgBreak() ((void)0)
#define _ASSERT_EXPR(expr, msg) ((void)0)
#define _ASSERT(expr) ((void)0)
#define _ASSERTE(expr) ((void)0)
#define _RPT0(rptno, msg)
#define _RPTN(rptno, msg, ...)
#define _RPTW0(rptno, msg)
#define _RPTWN(rptno, msg, ...)
#define _RPTF0(rptno, msg)
#define _RPTFN(rptno, msg, ...)
#define _RPTFW0(rptno, msg)
#define _RPTFWN(rptno, msg, ...)

#define _calloc_dbg(c, s, t, f, l)      (::calloc(c, s))
