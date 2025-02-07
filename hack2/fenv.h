#pragma once
#include "abc.h"
#include "corecrt.h"
#include "float.h"

__ywstd_cfunc_begin // clang-format off

int __cdecl fegetround();
int __cdecl fesetround(int);

using fexcept_t = unsigned long;
struct fenv_t { unsigned long _Fe_ctl, _Fe_stat; };

int __cdecl fegetenv(fenv_t*);
int __cdecl fesetenv(const fenv_t*);
int __cdecl feclearexcept(int);
int __cdecl feholdexcept(fenv_t*);
int __cdecl fetestexcept(int);
int __cdecl fegetexceptflag(fexcept_t*, int);
int __cdecl fesetexceptflag(const fexcept_t*, int);

__declspec(selectany) inline const fenv_t _Fenv1 = {0x3f00003f, 0};

#pragma optimize("", off)
inline int __cdecl feraiseexcept(int e) {
  static struct {
    int val;
    double num;
    double den;
  } const table[] = {{FE_INVALID, 0.0, 0.0},
                     {FE_DIVBYZERO, 1.0, 0.0},
                     {FE_OVERFLOW, 1e+300, 1e-300},
                     {FE_UNDERFLOW, 1e-300, 1e+300},
                     {FE_INEXACT, 2.0, 3.0}};
  if ((e &= FE_ALL_EXCEPT) == 0) return 0;
  double a = 0.0;
  (void)a;
  for (size_t i = 0; i < 5; ++i)
    if ((e & table[i].val) != 0) a = table[i].num / table[i].den;
  return 0;
}
#pragma optimize("", on)

inline int __cdecl feupdateenv(const fenv_t* env) {
  if (fesetenv(env) != 0) return 1;
  else if (int e = fetestexcept(FE_ALL_EXCEPT); feraiseexcept(e) != 0) return 1;
  else return 0;
}

__ywstd_cfunc_end // clang-format on
