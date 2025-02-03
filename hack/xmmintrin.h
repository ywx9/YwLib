/// \file xmmintrin.h
/// \copyright (c) 2025 ywx9.com

#pragma once
#include "abc.h"
#include "mmintrin.h"

#if !__ywstd_is_imported

__ywstd_export union __declspec(intrin_type) alignas(16) __m128 {
  float m128_f32[4];
  unsigned __int64 m128_u64[2];
  __int8 m128_i8[16];
  __int16 m128_i16[8];
  __int32 m128_i32[4];
  __int64 m128_i64[2];
  unsigned __int8 m128_u8[16];
  unsigned __int16 m128_u16[8];
  unsigned __int32 m128_u32[4];
};

__ywstd_export extern "C" {

#define _MM_SHUFFLE(fp3, fp2, fp1, fp0) (((fp3) << 6) | ((fp2) << 4) | ((fp1) << 2) | ((fp0)))

#define _MM_TRANSPOSE4_PS(row0, row1, row2, row3)      \
  {                                                    \
    auto _Tmp0 = _mm_shuffle_ps((row0), (row1), 0x44); \
    auto _Tmp2 = _mm_shuffle_ps((row0), (row1), 0xEE); \
    auto _Tmp1 = _mm_shuffle_ps((row2), (row3), 0x44); \
    auto _Tmp3 = _mm_shuffle_ps((row2), (row3), 0xEE); \
    (row0) = _mm_shuffle_ps(_Tmp0, _Tmp1, 0x88);       \
    (row1) = _mm_shuffle_ps(_Tmp0, _Tmp1, 0xDD);       \
    (row2) = _mm_shuffle_ps(_Tmp2, _Tmp3, 0x88);       \
    (row3) = _mm_shuffle_ps(_Tmp2, _Tmp3, 0xDD);       \
  }

#define _MM_HINT_NTA 0
#define _MM_HINT_T0 1
#define _MM_HINT_T1 2
#define _MM_HINT_T2 3
#define _MM_HINT_ENTA 4
#define _MM_HINT_IT0 7
#define _MM_HINT_IT1 6
#define _MM_ALIGN16 _VCRT_ALIGN(16)
#define _MM_EXCEPT_MASK 0x003f
#define _MM_EXCEPT_INVALID 0x0001
#define _MM_EXCEPT_DENORM 0x0002
#define _MM_EXCEPT_DIV_ZERO 0x0004
#define _MM_EXCEPT_OVERFLOW 0x0008
#define _MM_EXCEPT_UNDERFLOW 0x0010
#define _MM_EXCEPT_INEXACT 0x0020
#define _MM_MASK_MASK 0x1f80
#define _MM_MASK_INVALID 0x0080
#define _MM_MASK_DENORM 0x0100
#define _MM_MASK_DIV_ZERO 0x0200
#define _MM_MASK_OVERFLOW 0x0400
#define _MM_MASK_UNDERFLOW 0x0800
#define _MM_MASK_INEXACT 0x1000
#define _MM_ROUND_MASK 0x6000
#define _MM_ROUND_NEAREST 0x0000
#define _MM_ROUND_DOWN 0x2000
#define _MM_ROUND_UP 0x4000
#define _MM_ROUND_TOWARD_ZERO 0x6000
#define _MM_FLUSH_ZERO_MASK 0x8000
#define _MM_FLUSH_ZERO_ON 0x8000
#define _MM_FLUSH_ZERO_OFF 0x0000
#define _MM_SET_EXCEPTION_STATE(mask) _mm_setcsr((_mm_getcsr() & ~_MM_EXCEPT_MASK) | (mask))
#define _MM_GET_EXCEPTION_STATE() (_mm_getcsr() & _MM_EXCEPT_MASK)
#define _MM_SET_EXCEPTION_MASK(mask) _mm_setcsr((_mm_getcsr() & ~_MM_MASK_MASK) | (mask))
#define _MM_GET_EXCEPTION_MASK() (_mm_getcsr() & _MM_MASK_MASK)
#define _MM_SET_ROUNDING_MODE(mode) _mm_setcsr((_mm_getcsr() & ~_MM_ROUND_MASK) | (mode))
#define _MM_GET_ROUNDING_MODE() (_mm_getcsr() & _MM_ROUND_MASK)
#define _MM_SET_FLUSH_ZERO_MODE(mode) _mm_setcsr((_mm_getcsr() & ~_MM_FLUSH_ZERO_MASK) | (mode))
#define _MM_GET_FLUSH_ZERO_MODE() (_mm_getcsr() & _MM_FLUSH_ZERO_MASK)

  extern __m128 _mm_add_ss(__m128, __m128);
  extern __m128 _mm_add_ps(__m128, __m128);
  extern __m128 _mm_sub_ss(__m128, __m128);
  extern __m128 _mm_sub_ps(__m128, __m128);
  extern __m128 _mm_mul_ss(__m128, __m128);
  extern __m128 _mm_mul_ps(__m128, __m128);
  extern __m128 _mm_div_ss(__m128, __m128);
  extern __m128 _mm_div_ps(__m128, __m128);
  extern __m128 _mm_sqrt_ss(__m128);
  extern __m128 _mm_sqrt_ps(__m128);
  extern __m128 _mm_rcp_ss(__m128);
  extern __m128 _mm_rcp_ps(__m128);
  extern __m128 _mm_rsqrt_ss(__m128);
  extern __m128 _mm_rsqrt_ps(__m128);
  extern __m128 _mm_min_ss(__m128, __m128);
  extern __m128 _mm_min_ps(__m128, __m128);
  extern __m128 _mm_max_ss(__m128, __m128);
  extern __m128 _mm_max_ps(__m128, __m128);

  extern __m128 _mm_and_ps(__m128, __m128);
  extern __m128 _mm_andnot_ps(__m128, __m128);
  extern __m128 _mm_or_ps(__m128, __m128);
  extern __m128 _mm_xor_ps(__m128, __m128);

  extern __m128 _mm_cmpeq_ss(__m128, __m128);
  extern __m128 _mm_cmpeq_ps(__m128, __m128);
  extern __m128 _mm_cmplt_ss(__m128, __m128);
  extern __m128 _mm_cmplt_ps(__m128, __m128);
  extern __m128 _mm_cmple_ss(__m128, __m128);
  extern __m128 _mm_cmple_ps(__m128, __m128);
  extern __m128 _mm_cmpgt_ss(__m128, __m128);
  extern __m128 _mm_cmpgt_ps(__m128, __m128);
  extern __m128 _mm_cmpge_ss(__m128, __m128);
  extern __m128 _mm_cmpge_ps(__m128, __m128);
  extern __m128 _mm_cmpneq_ss(__m128, __m128);
  extern __m128 _mm_cmpneq_ps(__m128, __m128);
  extern __m128 _mm_cmpnlt_ss(__m128, __m128);
  extern __m128 _mm_cmpnlt_ps(__m128, __m128);
  extern __m128 _mm_cmpnle_ss(__m128, __m128);
  extern __m128 _mm_cmpnle_ps(__m128, __m128);
  extern __m128 _mm_cmpngt_ss(__m128, __m128);
  extern __m128 _mm_cmpngt_ps(__m128, __m128);
  extern __m128 _mm_cmpnge_ss(__m128, __m128);
  extern __m128 _mm_cmpnge_ps(__m128, __m128);
  extern __m128 _mm_cmpord_ss(__m128, __m128);
  extern __m128 _mm_cmpord_ps(__m128, __m128);
  extern __m128 _mm_cmpunord_ss(__m128, __m128);
  extern __m128 _mm_cmpunord_ps(__m128, __m128);
  extern int _mm_comieq_ss(__m128, __m128);
  extern int _mm_comilt_ss(__m128, __m128);
  extern int _mm_comile_ss(__m128, __m128);
  extern int _mm_comigt_ss(__m128, __m128);
  extern int _mm_comige_ss(__m128, __m128);
  extern int _mm_comineq_ss(__m128, __m128);
  extern int _mm_ucomieq_ss(__m128, __m128);
  extern int _mm_ucomilt_ss(__m128, __m128);
  extern int _mm_ucomile_ss(__m128, __m128);
  extern int _mm_ucomigt_ss(__m128, __m128);
  extern int _mm_ucomige_ss(__m128, __m128);
  extern int _mm_ucomineq_ss(__m128, __m128);

  extern int _mm_cvt_ss2si(__m128);
  extern int _mm_cvtt_ss2si(__m128);
  extern __m128 _mm_cvt_si2ss(__m128, int);
  extern float _mm_cvtss_f32(__m128);

  extern __int64 _mm_cvtss_si64(__m128);
  extern __int64 _mm_cvttss_si64(__m128);
  extern __m128 _mm_cvtsi64_ss(__m128, __int64 _B);

  extern __m128 _mm_shuffle_ps(__m128, __m128, unsigned);
  extern __m128 _mm_unpackhi_ps(__m128, __m128);
  extern __m128 _mm_unpacklo_ps(__m128, __m128);
  extern __m128 _mm_loadh_pi(__m128, __m64 const*);
  extern __m128 _mm_movehl_ps(__m128, __m128);
  extern __m128 _mm_movelh_ps(__m128, __m128);
  extern void _mm_storeh_pi(__m64*, __m128);
  extern __m128 _mm_loadl_pi(__m128, __m64 const*);
  extern void _mm_storel_pi(__m64*, __m128);
  extern int _mm_movemask_ps(__m128);

  extern __m128 _mm_set_ss(float);
  extern __m128 _mm_set_ps1(float);
  extern __m128 _mm_set_ps(float, float, float, float);
  extern __m128 _mm_setr_ps(float, float, float, float);
  extern __m128 _mm_setzero_ps(void);
  extern __m128 _mm_load_ss(float const*);
  extern __m128 _mm_load_ps1(float const*);
  extern __m128 _mm_load_ps(float const*);
  extern __m128 _mm_loadr_ps(float const*);
  extern __m128 _mm_loadu_ps(float const*);
  extern void _mm_store_ss(float*, __m128);
  extern void _mm_store_ps1(float*, __m128);
  extern void _mm_store_ps(float*, __m128);
  extern void _mm_storer_ps(float*, __m128);
  extern void _mm_storeu_ps(float*, __m128);
  extern void _mm_prefetch(char const*, int);
  extern void _m_prefetchit0(const void*);
  extern void _m_prefetchit1(const void*);
  extern void _mm_stream_ps(float*, __m128);
  extern __m128 _mm_move_ss(__m128, __m128);

  extern void _mm_sfence(void);
  extern unsigned int _mm_getcsr(void);
  extern void _mm_setcsr(unsigned int);

#define _mm_cvtss_si32 _mm_cvt_ss2si
#define _mm_cvttss_si32 _mm_cvtt_ss2si
#define _mm_cvtsi32_ss _mm_cvt_si2ss
#define _mm_set1_ps _mm_set_ps1
#define _mm_load1_ps _mm_load_ps1
#define _mm_store1_ps _mm_store_ps1
}
#endif
