#pragma once
#include "../msvc/inc/yvals_core.h"

#ifndef __ywstd_is_exported
#ifndef __ywstd_export
#define __ywstd_export
#define __ywstd_is_exported 0
#else
#define _BUILD_STD_MODULE
#define __ywstd_is_exported 1
#endif
#endif

#ifndef __ywstd_is_imported
#ifndef __ywstd_import
#define __ywstd_is_imported 0
#else
#define __ywstd_is_imported 1
#endif
#endif

#ifdef _CSTD
#undef _CSTD
#if __ywstd_is_exported or __ywstd_is_imported
#define _CSTD ::
#else
#define _CSTD ::__ywstd_cfunc::
#endif
#endif

#ifdef _STL_INTRIN_HEADER
#undef _STL_INTRIN_HEADER
#define _STL_INTRIN_HEADER <intrin0.h>
#endif
