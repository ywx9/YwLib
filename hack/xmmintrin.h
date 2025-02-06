#pragma once
#include "abc.h"
#include "mmintrin.h"

union __declspec(intrin_type) alignas(16) __m128 {
  float m128_f32[4];
  unsigned long long m128_u64[2];
  signed char m128_i8[16];
  short m128_i16[8];
  int m128_i32[4];
  long long m128_i64[2];
  unsigned char m128_u8[16];
  unsigned short m128_u16[8];
  unsigned int m128_u32[4];
};

extern "C" {

export __m128 _mm_add_ss(__m128, __m128);
export __m128 _mm_add_ps(__m128, __m128);
export __m128 _mm_sub_ss(__m128, __m128);
export __m128 _mm_sub_ps(__m128, __m128);
export __m128 _mm_mul_ss(__m128, __m128);
export __m128 _mm_mul_ps(__m128, __m128);
export __m128 _mm_div_ss(__m128, __m128);
export __m128 _mm_div_ps(__m128, __m128);
export __m128 _mm_sqrt_ss(__m128);
export __m128 _mm_sqrt_ps(__m128);
export __m128 _mm_rcp_ss(__m128);
export __m128 _mm_rcp_ps(__m128);
export __m128 _mm_rsqrt_ss(__m128);
export __m128 _mm_rsqrt_ps(__m128);
export __m128 _mm_min_ss(__m128, __m128);
export __m128 _mm_min_ps(__m128, __m128);
export __m128 _mm_max_ss(__m128, __m128);
export __m128 _mm_max_ps(__m128, __m128);

export __m128 _mm_and_ps(__m128, __m128);
export __m128 _mm_andnot_ps(__m128, __m128);
export __m128 _mm_or_ps(__m128, __m128);
export __m128 _mm_xor_ps(__m128, __m128);

export __m128 _mm_cmpeq_ss(__m128, __m128);
export __m128 _mm_cmpeq_ps(__m128, __m128);
export __m128 _mm_cmplt_ss(__m128, __m128);
export __m128 _mm_cmplt_ps(__m128, __m128);
export __m128 _mm_cmple_ss(__m128, __m128);
export __m128 _mm_cmple_ps(__m128, __m128);
export __m128 _mm_cmpgt_ss(__m128, __m128);
export __m128 _mm_cmpgt_ps(__m128, __m128);
export __m128 _mm_cmpge_ss(__m128, __m128);
export __m128 _mm_cmpge_ps(__m128, __m128);
export __m128 _mm_cmpneq_ss(__m128, __m128);
export __m128 _mm_cmpneq_ps(__m128, __m128);
export __m128 _mm_cmpnlt_ss(__m128, __m128);
export __m128 _mm_cmpnlt_ps(__m128, __m128);
export __m128 _mm_cmpnle_ss(__m128, __m128);
export __m128 _mm_cmpnle_ps(__m128, __m128);
export __m128 _mm_cmpngt_ss(__m128, __m128);
export __m128 _mm_cmpngt_ps(__m128, __m128);
export __m128 _mm_cmpnge_ss(__m128, __m128);
export __m128 _mm_cmpnge_ps(__m128, __m128);
export __m128 _mm_cmpord_ss(__m128, __m128);
export __m128 _mm_cmpord_ps(__m128, __m128);
export __m128 _mm_cmpunord_ss(__m128, __m128);
export __m128 _mm_cmpunord_ps(__m128, __m128);
export int _mm_comieq_ss(__m128, __m128);
export int _mm_comilt_ss(__m128, __m128);
export int _mm_comile_ss(__m128, __m128);
export int _mm_comigt_ss(__m128, __m128);
export int _mm_comige_ss(__m128, __m128);
export int _mm_comineq_ss(__m128, __m128);
export int _mm_ucomieq_ss(__m128, __m128);
export int _mm_ucomilt_ss(__m128, __m128);
export int _mm_ucomile_ss(__m128, __m128);
export int _mm_ucomigt_ss(__m128, __m128);
export int _mm_ucomige_ss(__m128, __m128);
export int _mm_ucomineq_ss(__m128, __m128);

export int _mm_cvt_ss2si(__m128);
export int _mm_cvtt_ss2si(__m128);
export __m128 _mm_cvt_si2ss(__m128, int);
export float _mm_cvtss_f32(__m128);

export __int64 _mm_cvtss_si64(__m128);
export __int64 _mm_cvttss_si64(__m128);
export __m128 _mm_cvtsi64_ss(__m128, __int64);

export __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
export __m128 _mm_unpackhi_ps(__m128, __m128);
export __m128 _mm_unpacklo_ps(__m128, __m128);
export __m128 _mm_loadh_pi(__m128, const __m64*);
export __m128 _mm_movehl_ps(__m128, __m128);
export __m128 _mm_movelh_ps(__m128, __m128);
export void _mm_storeh_pi(__m64*, __m128);
export __m128 _mm_loadl_pi(__m128, const __m64*);
export void _mm_storel_pi(__m64*, __m128);
export int _mm_movemask_ps(__m128);

export __m128 _mm_set_ss(float);
export __m128 _mm_set_ps1(float);
export __m128 _mm_set_ps(float, float, float, float);
export __m128 _mm_setr_ps(float, float, float, float);
export __m128 _mm_setzero_ps(void);
export __m128 _mm_load_ss(float const);
export __m128 _mm_load_ps1(float const);
export __m128 _mm_load_ps(float const);
export __m128 _mm_loadr_ps(float const);
export __m128 _mm_loadu_ps(float const);
export void _mm_store_ss(float*, __m128);
export void _mm_store_ps1(float*, __m128);
export void _mm_store_ps(float*, __m128);
export void _mm_storer_ps(float*, __m128);
export void _mm_storeu_ps(float*, __m128);
export void _mm_prefetch(char const, int _Sel);
export void _m_prefetchit0(const void*);
export void _m_prefetchit1(const void*);
export void _mm_stream_ps(float*, __m128);
export __m128 _mm_move_ss(__m128, __m128);

export void _mm_sfence(void);
export unsigned int _mm_getcsr(void);
export void _mm_setcsr(unsigned int);

#define _mm_cvtss_si32 _mm_cvt_ss2si
#define _mm_cvttss_si32 _mm_cvtt_ss2si
#define _mm_cvtsi32_ss _mm_cvt_si2ss
#define _mm_set1_ps _mm_set_ps1
#define _mm_load1_ps _mm_load_ps1
#define _mm_store1_ps _mm_store_ps1
}
