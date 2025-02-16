#pragma once
#include "abc.h"
#include <Windows.h>

__ywstd_cfunc_begin

struct HWND__ {
  int unused;
};
using HWND = HWND__*;

struct POINT {
  long x, y;
};

struct MSG {
  HWND hwnd;
  unsigned message;
  unsigned long long wParam;
  long long lParam;
  unsigned long time;
  POINT pt;
};
__ywstd_cfunc_end

 __ywstd_export namespace win {

using __ywstd_cfunc HWND;
using __ywstd_cfunc POINT;
using __ywstd_cfunc MSG;
}
