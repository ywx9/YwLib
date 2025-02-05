#pragma once
#include "abc.h"
#include "corecrt.h"

_CRT_BEGIN_C_HEADER

struct _exception {
  int type;
  char* name;
  double arg1;
  double arg2;
  double retval;
};

#ifndef _COMPLEX_DEFINED
#define _COMPLEX_DEFINED
struct _complex {
  double x, y;
};
#endif

typedef float float_t;
typedef double double_t;

#define _DOMAIN 1
#define _SING 2
#define _OVERFLOW 3
#define _UNDERFLOW 4
#define _TLOSS 5
#define _PLOSS 6

extern const double _HUGE;

#ifndef _HUGE_ENUF
#define _HUGE_ENUF 1e+300
#endif

#define _DENORM (-2)
#define _FINITE (-1)
#define _INFCODE 1
#define _NANCODE 2

#define _C2 1
#define FP_ILOGB0 (-0x7fffffff - _C2)
#define FP_ILOGBNAN 0x7fffffff

#define _FE_DIVBYZERO 0x04
#define _FE_INEXACT 0x20
#define _FE_INVALID 0x01
#define _FE_OVERFLOW 0x08
#define _FE_UNDERFLOW 0x10

#define _D0_C 3
#define _D1_C 2
#define _D2_C 1
#define _D3_C 0

#define _DBIAS 0x3fe
#define _DOFF 4

#define _F0_C 1
#define _F1_C 0

#define _FBIAS 0x7e
#define _FOFF 7
#define _FRND 1

#define _L0_C 3
#define _L1_C 2
#define _L2_C 1
#define _L3_C 0

#define _LBIAS 0x3fe
#define _LOFF 4

#define _DFRAC ((unsigned short)((1 << _DOFF) - 1))
#define _DMASK ((unsigned short)(0x7fff & ~_DFRAC))
#define _DMAX ((unsigned short)((1 << (15 - _DOFF)) - 1))
#define _DSIGN ((unsigned short)0x8000)

#define _FFRAC ((unsigned short)((1 << _FOFF) - 1))
#define _FMASK ((unsigned short)(0x7fff & ~_FFRAC))
#define _FMAX ((unsigned short)((1 << (15 - _FOFF)) - 1))
#define _FSIGN ((unsigned short)0x8000)

#define _LFRAC ((unsigned short)(-1))
#define _LMASK ((unsigned short)0x7fff)
#define _LMAX ((unsigned short)0x7fff)
#define _LSIGN ((unsigned short)0x8000)

#define _DHUGE_EXP (int)(_DMAX * 900L / 1000)
#define _FHUGE_EXP (int)(_FMAX * 900L / 1000)
#define _LHUGE_EXP (int)(_LMAX * 900L / 1000)

#define _DSIGN_C(_Val) (((_double_val*)(char*)&(_Val))->_Sh[_D0_C] & _DSIGN)
#define _FSIGN_C(_Val) (((_float_val*)(char*)&(_Val))->_Sh[_F0_C] & _FSIGN)
#define _LSIGN_C(_Val) (((_ldouble_val*)(char*)&(_Val))->_Sh[_L0_C] & _LSIGN)

void __cdecl _fperrraise(int _Except);

short __cdecl _dclass(double _X);
short __cdecl _ldclass(long double _X);
short __cdecl _fdclass(float _X);

short __cdecl _d_int(double* _Px, short _Xexp);
short __cdecl _ld_int(long double* _Px, short _Xexp);
short __cdecl _fd_int(float* _Px, short _Xexp);

short __cdecl _dscale(double* _Px, long _Lexp);
short __cdecl _ldscale(long double* _Px, long _Lexp);
short __cdecl _fdscale(float* _Px, long _Lexp);

short __cdecl _dunscale(short* _Pex, double* _Px);
short __cdecl _ldunscale(short* _Pex, long double* _Px);
short __cdecl _fdunscale(short* _Pex, float* _Px);

short __cdecl _dexp(double* _Px, double _Y, long _Eoff);
short __cdecl _ldexp(long double* _Px, long double _Y, long _Eoff);
short __cdecl _fdexp(float* _Px, float _Y, long _Eoff);

short __cdecl _dnorm(unsigned short* _Ps);
short __cdecl _fdnorm(unsigned short* _Ps);

double __cdecl _dpoly(double _X, const double* _Tab, int _N);
long double __cdecl _ldpoly(long double _X, const long double* _Tab, int _N);
float __cdecl _fdpoly(float _X, const float* _Tab, int _N);

double __cdecl _dlog(double _X, int _Baseflag);
long double __cdecl _ldlog(long double _X, int _Baseflag);
float __cdecl _fdlog(float _X, int _Baseflag);

double __cdecl _dsin(double _X, unsigned int _Qoff);
long double __cdecl _ldsin(long double _X, unsigned int _Qoff);
float __cdecl _fdsin(float _X, unsigned int _Qoff);

union _double_val {
  unsigned short _Sh[4];
  double _Val;
};

union _float_val {
  unsigned short _Sh[2];
  float _Val;
};

union _ldouble_val {
  unsigned short _Sh[4];
  long double _Val;
};

union _float_const {
  unsigned short _Word[4];
  float _Float;
  double _Double;
  long double _Long_double;
};

extern const _float_const _Denorm_C, _Inf_C, _Nan_C, _Snan_C, _Hugeval_C;
extern const _float_const _FDenorm_C, _FInf_C, _FNan_C, _FSnan_C;
extern const _float_const _LDenorm_C, _LInf_C, _LNan_C, _LSnan_C;

extern const _float_const _Eps_C, _Rteps_C;
extern const _float_const _FEps_C, _FRteps_C;
extern const _float_const _LEps_C, _LRteps_C;

extern const double _Zero_C, _Xbig_C;
extern const float _FZero_C, _FXbig_C;
extern const long double _LZero_C, _LXbig_C;

#define _FP_LT 1
#define _FP_EQ 2
#define _FP_GT 4

_CRT_END_C_HEADER
