#pragma once
#include "abc.h"

__ywstd_cfunc_begin // clang-format off

long _InterlockedCompareExchange(volatile long*, long, long);
__int64 _InterlockedCompareExchange64(volatile __int64*, __int64, __int64);
unsigned char _InterlockedCompareExchange128(volatile __int64*, __int64, __int64, __int64*);
long _InterlockedDecrement(volatile long*);
long _InterlockedExchange(volatile long*, long);
char _InterlockedExchange8(volatile char*, char);
__int64 _InterlockedExchange64(volatile __int64*, __int64);
long _InterlockedExchangeAdd(long volatile*, long);
__int64 _InterlockedExchangeAdd64(volatile __int64*, __int64);
long _InterlockedIncrement(volatile long*);
long _InterlockedOr(long volatile*, long);

void _ReadWriteBarrier();
void* _ReturnAddress();

unsigned char __cdecl _addcarry_u64(unsigned char, unsigned __int64, unsigned __int64, unsigned __int64*);
unsigned __lzcnt(unsigned);
unsigned __int64 __lzcnt64(unsigned __int64);
unsigned char __cdecl _subborrow_u64(unsigned char, unsigned __int64, unsigned __int64, unsigned __int64*);
unsigned _tzcnt_u32(unsigned);
unsigned __int64 __cdecl _udiv128(unsigned __int64, unsigned __int64, unsigned __int64, unsigned __int64*);
unsigned __int64 _umul128(unsigned __int64, unsigned __int64, unsigned __int64*);

// clang-format on

void _mm_pause();

__int8 __iso_volatile_load8(const volatile __int8*);
__int32 __iso_volatile_load32(const volatile __int32*);
__int64 __iso_volatile_load64(const volatile __int64*);
void __iso_volatile_store32(volatile __int32*, __int32);
void __iso_volatile_store64(volatile __int64 *, __int64);
unsigned __int64 __shiftleft128(unsigned __int64, unsigned __int64, unsigned char);
unsigned __int64 __shiftright128(unsigned __int64, unsigned __int64, unsigned char);

__ywstd_cfunc_end
