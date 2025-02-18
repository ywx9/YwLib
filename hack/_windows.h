#pragma once
#include "abc.h"
// #include <Windows.h>

__ywstd_cfunc_begin

using BOOL     = int;
using BYTE     = unsigned char;
using DWORD    = unsigned long;
using FLOAT    = float;
using HANDLE   = void*;
using HRESULT  = long;
using INT      = int;
using LONG     = long;
using LONGLONG = long long;
using LPCSTR   = const char*;
using LPCWSTR  = const wchar_t*;
using LPSTR    = char*;
using LPWSTR   = wchar_t*;
using LRESULT  = long long;
using SIZE_T   = unsigned long long;
using UINT     = unsigned;
using UINT8    = unsigned char;
using WCHAR    = wchar_t;

struct HBRUSH__    { int unused; }; using HBRUSH    = HBRUSH__*;
struct HCURSOR__   { int unused; }; using HCURSOR   = HCURSOR__*;
struct HICON__     { int unused; }; using HICON     = HICON__*;
struct HINSTANCE__ { int unused; }; using HINSTANCE = HINSTANCE__*;
struct HMENU__     { int unused; }; using HMENU     = HMENU__*;
struct HMONITOR__  { int unused; }; using HMONITOR  = HMONITOR__*;
struct HWND__      { int unused; }; using HWND      = HWND__*;

union LARGE_INTEGER {
  struct {
    DWORD LowPart;
    LONG HighPart;
  } DUMMYSTRUCTNAME;
  struct {
    DWORD LowPart;
    LONG HighPart;
  } u;
  LONGLONG QuadPart;
};

struct LUID {
  DWORD LowPart;
  LONG HighPart;
};

struct POINT { long x, y; };
struct RECT  { long left, top, right, bottom; };

struct MSG {
  HWND               hwnd;
  unsigned           message;
  unsigned long long wParam;
  long long          lParam;
  unsigned long      time;
  POINT              pt;
};

using WNDPROC = long long (__stdcall*)(HWND, unsigned, unsigned long long, long long);

struct WNDCLASSEXW {
  unsigned       cbSize;
  unsigned       style;
  WNDPROC        lpfnWndProc;
  int            cbClsExtra;
  int            cbWndExtra;
  HINSTANCE      hInstance;
  HICON          hIcon;
  HCURSOR        hCursor;
  HBRUSH         hbrBackground;
  const wchar_t* lpszMenuName;
  const wchar_t* lpszClassName;
  HICON          hIconSm;
};

__declspec(dllimport) LPWSTR* __stdcall CommandLineToArgvW(LPCWSTR, int*);
__declspec(dllimport) HWND    __stdcall CreateWindowExW(unsigned long, const wchar_t*, const wchar_t*, unsigned long, int, int, int, int, HWND, HMENU, HINSTANCE, void*);

__declspec(dllimport) long long __stdcall DefWindowProcW(HWND, unsigned, unsigned long long, long long);
__declspec(dllimport) int       __stdcall DestroyWindow(HWND);
__declspec(dllimport) long long __stdcall DispatchMessageW(const MSG*);

__declspec(dllimport) int       __stdcall GetClientRect(HWND, RECT*);
__declspec(dllimport) LPWSTR    __stdcall GetCommandLineW();
__declspec(dllimport) int       __stdcall GetMessageW(MSG*, HWND, unsigned, unsigned);
__declspec(dllimport) HINSTANCE __stdcall GetModuleHandleW(const wchar_t*);
__declspec(dllimport) long long __stdcall GetWindowLongPtrW(HWND, int);
__declspec(dllimport) int       __stdcall GetWindowTextA(HWND, char*, int);
__declspec(dllimport) int       __stdcall GetWindowTextW(HWND, wchar_t*, int);
__declspec(dllimport) int       __stdcall GetWindowTextLengthA(HWND);
__declspec(dllimport) int       __stdcall GetWindowTextLengthW(HWND);

__declspec(dllimport) HCURSOR __stdcall LoadCursorW(HINSTANCE, const wchar_t*);
__declspec(dllimport) HANDLE  __stdcall LocalFree(HANDLE);

__declspec(dllimport) int __stdcall MessageBoxW(HWND, const wchar_t*, const wchar_t*, unsigned);

__declspec(dllimport) int __stdcall PeekMessageW(MSG*, HWND, unsigned, unsigned, unsigned);
__declspec(dllimport) int __stdcall PostMessageW(HWND, unsigned, unsigned long long, long long);
__declspec(dllimport) int __stdcall PostQuitMessage(int);

__declspec(dllimport) unsigned short __stdcall RegisterClassExW(const WNDCLASSEXW*);

__declspec(dllimport) long long __stdcall SendMessageW(HWND, unsigned, unsigned long long, long long);
__declspec(dllimport) HWND      __stdcall SetFocus(HWND);
__declspec(dllimport) long long __stdcall SetWindowLongPtrW(HWND, int, long long);
__declspec(dllimport) int       __stdcall SetWindowPos(HWND, HWND, int, int, int, int, unsigned);
__declspec(dllimport) int       __stdcall SetWindowTextA(HWND, const char*);
__declspec(dllimport) int       __stdcall SetWindowTextW(HWND, const wchar_t*);
__declspec(dllimport) int       __stdcall ShowWindow(HWND, int);

__declspec(dllimport) int __stdcall TranslateMessage(const MSG*);
__ywstd_cfunc_end

__ywstd_export namespace win {

using __ywstd_cfunc HRESULT;
using __ywstd_cfunc LRESULT;
using __ywstd_cfunc UINT;

using __ywstd_cfunc HBRUSH;
using __ywstd_cfunc HCURSOR;
using __ywstd_cfunc HICON;
using __ywstd_cfunc HINSTANCE;
using __ywstd_cfunc HMENU;
using __ywstd_cfunc HWND;

using __ywstd_cfunc POINT;
using __ywstd_cfunc MSG;
using __ywstd_cfunc RECT;
using __ywstd_cfunc WNDPROC;
using __ywstd_cfunc WNDCLASSEXW;

using __ywstd_cfunc CommandLineToArgvW;
using __ywstd_cfunc CreateWindowExW;

using __ywstd_cfunc DefWindowProcW;
using __ywstd_cfunc DestroyWindow;
using __ywstd_cfunc DispatchMessageW;

using __ywstd_cfunc GetClientRect;
using __ywstd_cfunc GetCommandLineW;
using __ywstd_cfunc GetMessageW;
using __ywstd_cfunc GetModuleHandleW;
using __ywstd_cfunc GetWindowLongPtrW;
using __ywstd_cfunc GetWindowTextA;
using __ywstd_cfunc GetWindowTextW;
using __ywstd_cfunc GetWindowTextLengthA;
using __ywstd_cfunc GetWindowTextLengthW;

using __ywstd_cfunc LoadCursorW;
using __ywstd_cfunc LocalFree;

using __ywstd_cfunc MessageBoxW;

using __ywstd_cfunc PeekMessageW;
using __ywstd_cfunc PostMessageW;
using __ywstd_cfunc PostQuitMessage;

using __ywstd_cfunc RegisterClassExW;

using __ywstd_cfunc SendMessageW;
using __ywstd_cfunc SetFocus;
using __ywstd_cfunc SetWindowLongPtrW;
using __ywstd_cfunc SetWindowPos;
using __ywstd_cfunc SetWindowTextA;
using __ywstd_cfunc SetWindowTextW;
using __ywstd_cfunc ShowWindow;

using __ywstd_cfunc TranslateMessage;
}
