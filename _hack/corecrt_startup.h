/// \file corecrt_startup.h
/// \copyright (c) 2025 ywx9.com

#pragma once
#include "abc.h"

extern "C" {

struct _EXCEPTION_POINTERS;

_ACRTIMP int __cdecl _seh_filter_dll(unsigned long, _EXCEPTION_POINTERS*);
_ACRTIMP int __cdecl _seh_filter_exe(unsigned long, _EXCEPTION_POINTERS*);

enum _crt_app_type { _crt_unknown_app, _crt_console_app, _crt_gui_app };

_ACRTIMP _crt_app_type __cdecl _query_app_type();
_ACRTIMP void __cdecl _set_app_type(_crt_app_type);

struct _exception {
  int type;
  char* name;
  double arg1;
  double arg2;
  double retval;
};

using _UserMathErrorFunctionPointer = int(__cdecl*)(struct _exception*);

_ACRTIMP void __cdecl __setusermatherr(_UserMathErrorFunctionPointer);
int __cdecl _is_c_termination_complete();

enum _crt_argv_mode { _crt_argv_no_arguments, _crt_argv_unexpanded_arguments, _crt_argv_expanded_arguments };

_ACRTIMP errno_t __cdecl _configure_narrow_argv(_crt_argv_mode);
_ACRTIMP errno_t __cdecl _configure_wide_argv(_crt_argv_mode);

int __CRTDECL _initialize_narrow_environment();
int __CRTDECL _initialize_wide_environment();

_ACRTIMP char** __cdecl _get_initial_narrow_environment();
_ACRTIMP wchar_t** __cdecl _get_initial_wide_environment();

char* __CRTDECL _get_narrow_winmain_command_line();
wchar_t* __CRTDECL _get_wide_winmain_command_line();

_ACRTIMP char** __cdecl __p__acmdln();
_ACRTIMP wchar_t** __cdecl __p__wcmdln();

#define _acmdln (*__p__acmdln())
#define _wcmdln (*__p__wcmdln())

typedef void(__cdecl* _PVFV)(void);
typedef int(__cdecl* _PIFV)(void);
typedef void(__cdecl* _PVFI)(int);

#ifndef _M_CEE
_ACRTIMP void __cdecl _initterm(_In_reads_(_Last - _First) _In_ _PVFV* _First, _In_ _PVFV* _Last);

_ACRTIMP int __cdecl _initterm_e(_In_reads_(_Last - _First) _PIFV* _First, _In_ _PIFV* _Last);
#endif

#ifndef _CRT_ONEXIT_T_DEFINED
#define _CRT_ONEXIT_T_DEFINED

typedef int(__CRTDECL* _onexit_t)(void);
#ifdef _M_CEE
typedef int(__clrcall* _onexit_m_t)(void);
#endif
#endif

typedef struct _onexit_table_t {
  _PVFV* _first;
  _PVFV* _last;
  _PVFV* _end;
} _onexit_table_t;

_ACRTIMP int __cdecl _initialize_onexit_table(_In_opt_ _onexit_table_t* _Table);

_ACRTIMP int __cdecl _register_onexit_function(_In_opt_ _onexit_table_t* _Table, _In_opt_ _onexit_t _Function);

_ACRTIMP int __cdecl _execute_onexit_table(_In_opt_ _onexit_table_t* _Table);

_ACRTIMP int __cdecl _crt_atexit(_In_opt_ _PVFV _Function);

_ACRTIMP int __cdecl _crt_at_quick_exit(_In_opt_ _PVFV _Function);

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Static CRT Initialization Support
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
#if _CRT_FUNCTIONS_REQUIRED

_Success_(return != 0) __crt_bool __cdecl __acrt_initialize(void);

_Success_(return != 0) __crt_bool __cdecl __acrt_uninitialize(_In_ __crt_bool _Terminating);

_Success_(return != 0) __crt_bool __cdecl __acrt_uninitialize_critical(_In_ __crt_bool _Terminating);

_Success_(return != 0) __crt_bool __cdecl __acrt_thread_attach(void);

_Success_(return != 0) __crt_bool __cdecl __acrt_thread_detach(void);

#endif // _CRT_FUNCTIONS_REQUIRED
}
