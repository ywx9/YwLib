#pragma once
#include "abc.h"

#define _CRT_BLOCK 2

#define _calloc_dbg(c, s, t, f, l) __ywstd_cfunc calloc(c, s)
