#pragma once
#include "abc.h"

extern "C" {

__int8           __iso_volatile_load8(const volatile __int8*);
__int32          __iso_volatile_load32(const volatile __int32*);
__int64          __iso_volatile_load64(const volatile __int64*);
void             __iso_volatile_store32(volatile __int32*, __int32);
void             __iso_volatile_store64(volatile __int64 *, __int64);
unsigned         __lzcnt(unsigned);
unsigned __int64 __lzcnt64(unsigned __int64);
unsigned __int64 __shiftleft128(unsigned __int64, unsigned __int64, unsigned char);
unsigned __int64 __shiftright128(unsigned __int64, unsigned __int64, unsigned char);

long          _InterlockedCompareExchange(volatile long*, long, long);
__int64       _InterlockedCompareExchange64(volatile __int64*, __int64, __int64);
unsigned char _InterlockedCompareExchange128(volatile __int64*, __int64, __int64, __int64*);
long          _InterlockedDecrement(volatile long*);
long          _InterlockedExchange(volatile long*, long);
char          _InterlockedExchange8(volatile char*, char);
__int64       _InterlockedExchange64(volatile __int64*, __int64);
long          _InterlockedExchangeAdd(long volatile*, long);
__int64       _InterlockedExchangeAdd64(volatile __int64*, __int64);
long          _InterlockedIncrement(volatile long*);
long          _InterlockedOr(long volatile*, long);
void          _ReadWriteBarrier();
void*         _ReturnAddress();

void          _mm_pause();

unsigned char __cdecl      _subborrow_u64(unsigned char, unsigned __int64, unsigned __int64, unsigned __int64 *);
unsigned char __cdecl      _addcarry_u64(unsigned char, unsigned __int64, unsigned __int64, unsigned __int64 *);
unsigned long long __cdecl _byteswap_uint64(unsigned long long);
unsigned long __cdecl      _byteswap_ulong(unsigned long);
unsigned short __cdecl     _byteswap_ushort(unsigned short);
int __cdecl                _fflush_nolock(FILE*);
size_t __cdecl             _fwrite_nolock(const void*, size_t, size_t, FILE*);
void __cdecl               _lock_file(FILE*);
unsigned                   _tzcnt_u32(unsigned);
unsigned __int64 __cdecl   _udiv128(unsigned __int64, unsigned __int64, unsigned __int64, unsigned __int64*);
unsigned __int64           _umul128(unsigned __int64, unsigned __int64, unsigned __int64*);
void __cdecl               _unlock_file(FILE*);
}
