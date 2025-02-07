#pragma once
#include "abc.h"
#include "corecrt.h"

__ywstd_cfunc_begin

using clock_t = long;
using time_t = long long;

struct _timespec64 { long long tv_sec; long tv_nsec; };
struct timespec { long long tv_sec; long tv_nsec; };
long __cdecl clock();
char* __cdecl asctime(const tm*);
size_t __cdecl strftime(char*, size_t, const char*, const tm*);
char* __cdecl _ctime64(const long long*);
double __cdecl _difftime64(long long, long long);
tm* __cdecl _gmtime64(const long long*);
tm* __cdecl _localtime64(const long long*);
long long __cdecl _mktime64(tm*);
long long __cdecl _time64(long long*);
int __cdecl _timespec64_get(_timespec64*, int);

__ywstd_cfunc_end
