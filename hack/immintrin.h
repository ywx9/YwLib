#pragma once
#include <wmmintrin.h>
extern "C" {

union __declspec(intrin_type) alignas(32) __m256 {
  float m256_f32[8];
};

typedef struct __declspec(intrin_type) alignas(32) __m256d {
  double m256d_f64[4];
};

typedef union __declspec(intrin_type) alignas(32) __m256i {
  __int8 m256i_i8[32];
  __int16 m256i_i16[16];
  __int32 m256i_i32[8];
  __int64 m256i_i64[4];
  unsigned __int8 m256i_u8[32];
  unsigned __int16 m256i_u16[16];
  unsigned __int32 m256i_u32[8];
  unsigned __int64 m256i_u64[4];
};

extern __m256d __cdecl _mm256_add_pd(__m256d, __m256d);
extern __m256 __cdecl _mm256_add_ps(__m256, __m256);

extern __m256d __cdecl _mm256_addsub_pd(__m256d, __m256d);
extern __m256 __cdecl _mm256_addsub_ps(__m256, __m256);

extern __m256d __cdecl _mm256_and_pd(__m256d, __m256d);
extern __m256 __cdecl _mm256_and_ps(__m256, __m256);

extern __m256d __cdecl _mm256_andnot_pd(__m256d, __m256d);
extern __m256 __cdecl _mm256_andnot_ps(__m256, __m256);

extern __m256d __cdecl _mm256_blend_pd(__m256d, __m256d, const int);
extern __m256 __cdecl _mm256_blend_ps(__m256, __m256, const int);

extern __m256d __cdecl _mm256_blendv_pd(__m256d, __m256d, __m256d);
extern __m256 __cdecl _mm256_blendv_ps(__m256, __m256, __m256);

extern __m256d __cdecl _mm256_div_pd(__m256d, __m256d);
extern __m256 __cdecl _mm256_div_ps(__m256, __m256);

extern __m256 __cdecl _mm256_dp_ps(__m256, __m256, const int);

extern __m256d __cdecl _mm256_hadd_pd(__m256d, __m256d);
extern __m256 __cdecl _mm256_hadd_ps(__m256, __m256);

extern __m256d __cdecl _mm256_hsub_pd(__m256d, __m256d);
extern __m256 __cdecl _mm256_hsub_ps(__m256, __m256);

extern __m256d __cdecl _mm256_max_pd(__m256d, __m256d);
extern __m256 __cdecl _mm256_max_ps(__m256, __m256);

extern __m256d __cdecl _mm256_min_pd(__m256d, __m256d);
extern __m256 __cdecl _mm256_min_ps(__m256, __m256);

extern __m256d __cdecl _mm256_mul_pd(__m256d, __m256d);
extern __m256 __cdecl _mm256_mul_ps(__m256, __m256);

extern __m256d __cdecl _mm256_or_pd(__m256d, __m256d);
extern __m256 __cdecl _mm256_or_ps(__m256, __m256);

extern __m256d __cdecl _mm256_shuffle_pd(__m256d, __m256d, const int);
extern __m256 __cdecl _mm256_shuffle_ps(__m256, __m256, const int);

extern __m256d __cdecl _mm256_sub_pd(__m256d, __m256d);
extern __m256 __cdecl _mm256_sub_ps(__m256, __m256);

extern __m256d __cdecl _mm256_xor_pd(__m256d, __m256d);
extern __m256 __cdecl _mm256_xor_ps(__m256, __m256);

extern __m256 __cdecl _mm256_castpd_ps(__m256d);
extern __m256d __cdecl _mm256_castps_pd(__m256);
extern __m256i __cdecl _mm256_castps_si256(__m256);
extern __m256i __cdecl _mm256_castpd_si256(__m256d);
extern __m256 __cdecl _mm256_castsi256_ps(__m256i);
extern __m256d __cdecl _mm256_castsi256_pd(__m256i);
extern __m128 __cdecl _mm256_castps256_ps128(__m256);
extern __m128d __cdecl _mm256_castpd256_pd128(__m256d);
extern __m128i __cdecl _mm256_castsi256_si128(__m256i);
extern __m256 __cdecl _mm256_castps128_ps256(__m128);
extern __m256d __cdecl _mm256_castpd128_pd256(__m128d);
extern __m256i __cdecl _mm256_castsi128_si256(__m128i);

extern __m128d __cdecl _mm_cmp_pd(__m128d, __m128d, const int);
extern __m256d __cdecl _mm256_cmp_pd(__m256d, __m256d, const int);

extern __m128 __cdecl _mm_cmp_ps(__m128, __m128, const int);
extern __m256 __cdecl _mm256_cmp_ps(__m256, __m256, const int);

extern __m128d __cdecl _mm_cmp_sd(__m128d, __m128d, const int);
extern int __cdecl _mm_comi_sd(__m128d, __m128d, const int);

extern __m128 __cdecl _mm_cmp_ss(__m128, __m128, const int);
extern int __cdecl _mm_comi_ss(__m128, __m128, const int);

extern __m256d __cdecl _mm256_cvtepi32_pd(__m128i);
extern __m256 __cdecl _mm256_cvtepi32_ps(__m256i);

extern __m128 __cdecl _mm256_cvtpd_ps(__m256d);
extern __m256i __cdecl _mm256_cvtps_epi32(__m256);

extern __m256d __cdecl _mm256_cvtps_pd(__m128);
extern __m128i __cdecl _mm256_cvttpd_epi32(__m256d);

extern __m128i __cdecl _mm256_cvtpd_epi32(__m256d);
extern __m256i __cdecl _mm256_cvttps_epi32(__m256);

inline float _mm256_cvtss_f32(__m256 a) { return _mm_cvtss_f32(_mm256_castps256_ps128(a)); }
inline double _mm256_cvtsd_f64(__m256d a) { return _mm_cvtsd_f64(_mm256_castpd256_pd128(a)); }
inline int _mm256_cvtsi256_si32(__m256i a) { return _mm_cvtsi128_si32(_mm256_castsi256_si128(a)); }
inline __int64 _mm256_cvtsi256_si64(__m256i a) { return _mm_cvtsi128_si64(_mm256_castsi256_si128(a)); }

extern __m128 __cdecl _mm256_extractf128_ps(__m256, const int);
extern __m128d __cdecl _mm256_extractf128_pd(__m256d, const int);
extern __m128i __cdecl _mm256_extractf128_si256(__m256i, const int);

extern void __cdecl _mm256_zeroall();
extern void __cdecl _mm256_zeroupper();

extern __m256 __cdecl _mm256_permutevar_ps(__m256, __m256i);
extern __m128 __cdecl _mm_permutevar_ps(__m128, __m128i);

extern __m256 __cdecl _mm256_permute_ps(__m256, int);
extern __m128 __cdecl _mm_permute_ps(__m128, int);

extern __m256d __cdecl _mm256_permutevar_pd(__m256d, __m256i);
extern __m128d __cdecl _mm_permutevar_pd(__m128d, __m128i);

extern __m256d __cdecl _mm256_permute_pd(__m256d, int);
extern __m128d __cdecl _mm_permute_pd(__m128d, int);

extern __m256 __cdecl _mm256_permute2f128_ps(__m256, __m256, int);
extern __m256d __cdecl _mm256_permute2f128_pd(__m256d, __m256d, int);
extern __m256i __cdecl _mm256_permute2f128_si256(__m256i, __m256i, int);

extern __m256 __cdecl _mm256_broadcast_ss(float const*);
extern __m128 __cdecl _mm_broadcast_ss(float const*);

extern __m256d __cdecl _mm256_broadcast_sd(double const*);

extern __m256 __cdecl _mm256_broadcast_ps(__m128 const*);
extern __m256d __cdecl _mm256_broadcast_pd(__m128d const*);

extern __m256 __cdecl _mm256_insertf128_ps(__m256, __m128, int);
extern __m256d __cdecl _mm256_insertf128_pd(__m256d, __m128d, int);
extern __m256i __cdecl _mm256_insertf128_si256(__m256i, __m128i, int);

extern __m256d __cdecl _mm256_load_pd(double const*);
extern void __cdecl _mm256_store_pd(double*, __m256d);

extern __m256 __cdecl _mm256_load_ps(float const*);
extern void __cdecl _mm256_store_ps(float*, __m256);

extern __m256d __cdecl _mm256_loadu_pd(double const*);
extern void __cdecl _mm256_storeu_pd(double*, __m256d);

extern __m256 __cdecl _mm256_loadu_ps(float const*);
extern void __cdecl _mm256_storeu_ps(float*, __m256);

extern __m256i __cdecl _mm256_load_si256(__m256i const*);
extern void __cdecl _mm256_store_si256(__m256i*, __m256i);

extern __m256i __cdecl _mm256_loadu_si256(__m256i const*);
extern void __cdecl _mm256_storeu_si256(__m256i*, __m256i);



#define _mm256_loadu2_m128(/* float const* */ hiaddr, /* float const* */ loaddr) \
  _mm256_set_m128(_mm_loadu_ps(hiaddr), _mm_loadu_ps(loaddr))

#define _mm256_loadu2_m128d(/* double const* */ hiaddr, /* double const* */ loaddr) \
  _mm256_set_m128d(_mm_loadu_pd(hiaddr), _mm_loadu_pd(loaddr))

#define _mm256_loadu2_m128i(/* __m128i const* */ hiaddr, /* __m128i const* */ loaddr) \
  _mm256_set_m128i(_mm_loadu_si128(hiaddr), _mm_loadu_si128(loaddr))

#define _mm256_storeu2_m128(/* float* */ hiaddr, /* float* */ loaddr, /* __m256 */ a) \
  do {                                                                                \
    __m256 _a = (a); /* reference a only once in macro body */                        \
    _mm_storeu_ps((loaddr), _mm256_castps256_ps128(_a));                              \
    _mm_storeu_ps((hiaddr), _mm256_extractf128_ps(_a, 0x1));                          \
  } while (0)

#define _mm256_storeu2_m128d(/* double* */ hiaddr, /* double* */ loaddr, /* __m256d */ a) \
  do {                                                                                    \
    __m256d _a = (a); /* reference a only once in macro body */                           \
    _mm_storeu_pd((loaddr), _mm256_castpd256_pd128(_a));                                  \
    _mm_storeu_pd((hiaddr), _mm256_extractf128_pd(_a, 0x1));                              \
  } while (0)

#define _mm256_storeu2_m128i(/* __m128i* */ hiaddr, /* __m128i* */ loaddr, /* __m256i */ a) \
  do {                                                                                      \
    __m256i _a = (a); /* reference a only once in macro body */                             \
    _mm_storeu_si128((loaddr), _mm256_castsi256_si128(_a));                                 \
    _mm_storeu_si128((hiaddr), _mm256_extractf128_si256(_a, 0x1));                          \
  } while (0)

extern __m256d __cdecl _mm256_maskload_pd(double const*, __m256i);
extern void __cdecl _mm256_maskstore_pd(double*, __m256i, __m256d);
extern __m128d __cdecl _mm_maskload_pd(double const*, __m128i);
extern void __cdecl _mm_maskstore_pd(double*, __m128i, __m128d);

extern __m256 __cdecl _mm256_maskload_ps(float const*, __m256i);
extern void __cdecl _mm256_maskstore_ps(float*, __m256i, __m256);
extern __m128 __cdecl _mm_maskload_ps(float const*, __m128i);
extern void __cdecl _mm_maskstore_ps(float*, __m128i, __m128);

extern __m256 __cdecl _mm256_movehdup_ps(__m256);
extern __m256 __cdecl _mm256_moveldup_ps(__m256);
extern __m256d __cdecl _mm256_movedup_pd(__m256d);

extern __m256i __cdecl _mm256_lddqu_si256(__m256i const*);

extern void __cdecl _mm256_stream_si256(__m256i*, __m256i);
extern void __cdecl _mm256_stream_pd(double*, __m256d);
extern void __cdecl _mm256_stream_ps(float*, __m256);

extern __m256 __cdecl _mm256_rcp_ps(__m256);

extern __m256 __cdecl _mm256_rsqrt_ps(__m256);

extern __m256d __cdecl _mm256_sqrt_pd(__m256d);
extern __m256 __cdecl _mm256_sqrt_ps(__m256);

extern __m256d __cdecl _mm256_round_pd(__m256d, int);
inline __m256d __cdecl _mm256_ceil_pd(__m256d a) { return _mm256_round_pd(a, 0x02); }
inline __m256d __cdecl _mm256_floor_pd(__m256d a) { return _mm256_round_pd(a, 0x01); }

extern __m256 __cdecl _mm256_round_ps(__m256, int);
inline __m256 __cdecl _mm256_ceil_ps(__m256 a) { return _mm256_round_ps(a, 0x02); }
inline __m256 __cdecl _mm256_floor_ps(__m256 a) { return _mm256_round_ps(a, 0x01); }

extern __m256d __cdecl _mm256_unpackhi_pd(__m256d, __m256d);
extern __m256 __cdecl _mm256_unpackhi_ps(__m256, __m256);
extern __m256d __cdecl _mm256_unpacklo_pd(__m256d, __m256d);
extern __m256 __cdecl _mm256_unpacklo_ps(__m256, __m256);

extern int __cdecl _mm256_testz_si256(__m256i, __m256i);
inline int __cdecl _mm256_test_all_zeros(__m256i val) { return _mm256_testz_si256(val, val); }

extern int __cdecl _mm256_testc_si256(__m256i, __m256i);
inline int __cdecl _mm256_test_all_ones(__m256i val) { return _mm256_testc_si256(val, _mm256_cmpeq_epi32(val, val)); }

extern int __cdecl _mm256_testnzc_si256(__m256i, __m256i);
inline int __cdecl _mm256_test_mix_ones_zeros(__m256i mask, __m256i val) { return _mm256_testnzc_si256(mask, val); }

extern int __cdecl _mm256_testz_pd(__m256d, __m256d);
extern int __cdecl _mm256_testc_pd(__m256d, __m256d);
extern int __cdecl _mm256_testnzc_pd(__m256d, __m256d);
extern int __cdecl _mm_testz_pd(__m128d, __m128d);
extern int __cdecl _mm_testc_pd(__m128d, __m128d);
extern int __cdecl _mm_testnzc_pd(__m128d, __m128d);

extern int __cdecl _mm256_testz_ps(__m256, __m256);
extern int __cdecl _mm256_testc_ps(__m256, __m256);
extern int __cdecl _mm256_testnzc_ps(__m256, __m256);
extern int __cdecl _mm_testz_ps(__m128, __m128);
extern int __cdecl _mm_testc_ps(__m128, __m128);
extern int __cdecl _mm_testnzc_ps(__m128, __m128);

extern int __cdecl _mm256_movemask_pd(__m256d);
extern int __cdecl _mm256_movemask_ps(__m256);

extern __m256d __cdecl _mm256_setzero_pd();
extern __m256 __cdecl _mm256_setzero_ps();
extern __m256i __cdecl _mm256_setzero_si256();

extern __m256d __cdecl _mm256_set_pd(double, double, double, double);
extern __m256 __cdecl _mm256_set_ps(float, float, float, float, float, float, float, float);
extern __m256i __cdecl _mm256_set_epi8(
  char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char,
  char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char);
extern __m256i __cdecl _mm256_set_epi16(
    short, short, short, short, short, short, short, short, short, short, short, short, short, short, short, short);
extern __m256i __cdecl _mm256_set_epi32(int, int, int, int, int, int, int, int);
extern __m256i __cdecl _mm256_set_epi64x(__int64, __int64, __int64, __int64);


inline __m256 __cdecl _mm256_set_m128(__m128 hi, __m128 lo) {
  return _mm256_insertf128_ps(_mm256_castps128_ps256(lo), hi, 0x1);
}
inline __m256d __cdecl _mm256_set_m128d(__m128d hi, __m128d lo) {
  return _mm256_insertf128_pd(_mm256_castpd128_pd256(lo), hi, 0x1);
}
inline __m256i __cdecl _mm256_set_m128i(__m128i hi, __m128i lo) {
  return _mm256_insertf128_si256(_mm256_castsi128_si256(lo), hi, 0x1);
}

extern __m256d __cdecl _mm256_setr_pd(double, double, double, double);
extern __m256 __cdecl _mm256_setr_ps(float, float, float, float, float, float, float, float);
extern __m256i __cdecl _mm256_setr_epi8(
  char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char,
  char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char);
extern __m256i __cdecl _mm256_setr_epi16(
  short, short, short, short, short, short, short, short, short, short, short, short, short, short, short, short);
extern __m256i __cdecl _mm256_setr_epi32(int, int, int, int, int, int, int, int);
extern __m256i __cdecl _mm256_setr_epi64x(__int64, __int64, __int64, __int64);

inline __m256 __cdecl _mm256_setr_m128(__m128 lo, __m128 hi) { return _mm256_set_m128(hi, lo); }
inline __m256d __cdecl _mm256_setr_m128d(__m128d lo, __m128d hi) { return _mm256_set_m128d(hi, lo); }
inline __m256i __cdecl _mm256_setr_m128i(__m128i lo, __m128i hi) { return _mm256_set_m128i(hi, lo); }

extern __m256d __cdecl _mm256_set1_pd(double);
extern __m256 __cdecl _mm256_set1_ps(float);
extern __m256i __cdecl _mm256_set1_epi8(char);
extern __m256i __cdecl _mm256_set1_epi16(short);
extern __m256i __cdecl _mm256_set1_epi32(int);
extern __m256i __cdecl _mm256_set1_epi64x(long long);

extern __m128 __cdecl _mm_cvtph_ps(__m128i);
extern __m256 __cdecl _mm256_cvtph_ps(__m128i);
extern __m128i __cdecl _mm_cvtps_ph(__m128 /* m1 */, const int /* imm */);
extern __m128i __cdecl _mm256_cvtps_ph(__m256, int);

inline __m128 __cdecl _mm_undefined_ps() { return _mm_setzero_ps(); }
inline __m128d __cdecl _mm_undefined_pd() { return _mm_setzero_pd(); }
inline __m128i __cdecl _mm_undefined_si128() { return _mm_setzero_si128(); }
inline __m256 __cdecl _mm256_undefined_ps() { return _mm256_setzero_ps(); }
inline __m256d __cdecl _mm256_undefined_pd() { return _mm256_setzero_pd(); }
inline __m256i __cdecl _mm256_undefined_si256() { return _mm256_setzero_si256(); }

extern unsigned __int64 __cdecl _xgetbv(unsigned int);
extern void __cdecl _xsetbv(unsigned int, unsigned __int64);

extern void __cdecl _xsave(void*, unsigned __int64);
extern void __cdecl _xsave64(void*, unsigned __int64);

extern void __cdecl _xsaveopt(void*, unsigned __int64);
extern void __cdecl _xsaveopt64(void*, unsigned __int64);

extern void __cdecl _xsavec(void*, unsigned __int64);
extern void __cdecl _xsavec64(void*, unsigned __int64);

extern void __cdecl _xrstor(void const*, unsigned __int64);
extern void __cdecl _xrstor64(void const*, unsigned __int64);

extern void __cdecl _xsaves(void*, unsigned __int64);
extern void __cdecl _xsaves64(void*, unsigned __int64);

extern void __cdecl _xrstors(void const*, unsigned __int64);
extern void __cdecl _xrstors64(void const*, unsigned __int64);

extern void __cdecl _fxsave(void*);
extern void __cdecl _fxsave64(void*);

extern void __cdecl _fxrstor(void const*);
extern void __cdecl _fxrstor64(void const*);

extern int __cdecl _rdrand16_step(unsigned short*);
extern int __cdecl _rdrand32_step(unsigned int*);
extern int __cdecl _rdrand64_step(unsigned __int64*);

extern unsigned int __cdecl _readfsbase_u32();
extern unsigned int __cdecl _readgsbase_u32();
extern unsigned __int64 __cdecl _readfsbase_u64();
extern unsigned __int64 __cdecl _readgsbase_u64();

extern void __cdecl _writefsbase_u32(unsigned int);
extern void __cdecl _writegsbase_u32(unsigned int);
extern void __cdecl _writefsbase_u64(unsigned __int64);
extern void __cdecl _writegsbase_u64(unsigned __int64);

extern __m128 __cdecl _mm_fmadd_ps(__m128, __m128, __m128);
extern __m128d __cdecl _mm_fmadd_pd(__m128d, __m128d, __m128d);
extern __m128 __cdecl _mm_fmadd_ss(__m128, __m128, __m128);
extern __m128d __cdecl _mm_fmadd_sd(__m128d, __m128d, __m128d);
extern __m128 __cdecl _mm_fmsub_ps(__m128, __m128, __m128);
extern __m128d __cdecl _mm_fmsub_pd(__m128d, __m128d, __m128d);
extern __m128 __cdecl _mm_fmsub_ss(__m128, __m128, __m128);
extern __m128d __cdecl _mm_fmsub_sd(__m128d, __m128d, __m128d);
extern __m128 __cdecl _mm_fnmadd_ps(__m128, __m128, __m128);
extern __m128d __cdecl _mm_fnmadd_pd(__m128d, __m128d, __m128d);
extern __m128 __cdecl _mm_fnmadd_ss(__m128, __m128, __m128);
extern __m128d __cdecl _mm_fnmadd_sd(__m128d, __m128d, __m128d);
extern __m128 __cdecl _mm_fnmsub_ps(__m128, __m128, __m128);
extern __m128d __cdecl _mm_fnmsub_pd(__m128d, __m128d, __m128d);
extern __m128 __cdecl _mm_fnmsub_ss(__m128, __m128, __m128);
extern __m128d __cdecl _mm_fnmsub_sd(__m128d, __m128d, __m128d);

extern __m256 __cdecl _mm256_fmadd_ps(__m256, __m256, __m256);
extern __m256d __cdecl _mm256_fmadd_pd(__m256d, __m256d, __m256d);
extern __m256 __cdecl _mm256_fmsub_ps(__m256, __m256, __m256);
extern __m256d __cdecl _mm256_fmsub_pd(__m256d, __m256d, __m256d);
extern __m256 __cdecl _mm256_fnmadd_ps(__m256, __m256, __m256);
extern __m256d __cdecl _mm256_fnmadd_pd(__m256d, __m256d, __m256d);
extern __m256 __cdecl _mm256_fnmsub_ps(__m256, __m256, __m256);
extern __m256d __cdecl _mm256_fnmsub_pd(__m256d, __m256d, __m256d);

extern __m128 __cdecl _mm_fmaddsub_ps(__m128, __m128, __m128);
extern __m128d __cdecl _mm_fmaddsub_pd(__m128d, __m128d, __m128d);
extern __m128 __cdecl _mm_fmsubadd_ps(__m128, __m128, __m128);
extern __m128d __cdecl _mm_fmsubadd_pd(__m128d, __m128d, __m128d);

extern __m256 __cdecl _mm256_fmaddsub_ps(__m256, __m256, __m256);
extern __m256d __cdecl _mm256_fmaddsub_pd(__m256d, __m256d, __m256d);
extern __m256 __cdecl _mm256_fmsubadd_ps(__m256, __m256, __m256);
extern __m256d __cdecl _mm256_fmsubadd_pd(__m256d, __m256d, __m256d);

extern __m256i __cdecl _mm256_cmpeq_epi8(__m256i, __m256i);
extern __m256i __cdecl _mm256_cmpeq_epi16(__m256i, __m256i);
extern __m256i __cdecl _mm256_cmpeq_epi32(__m256i, __m256i);
extern __m256i __cdecl _mm256_cmpeq_epi64(__m256i, __m256i);

extern __m256i __cdecl _mm256_cmpgt_epi8(__m256i, __m256i);
extern __m256i __cdecl _mm256_cmpgt_epi16(__m256i, __m256i);
extern __m256i __cdecl _mm256_cmpgt_epi32(__m256i, __m256i);
extern __m256i __cdecl _mm256_cmpgt_epi64(__m256i, __m256i);

extern __m256i __cdecl _mm256_max_epi8(__m256i, __m256i);
extern __m256i __cdecl _mm256_max_epi16(__m256i, __m256i);
extern __m256i __cdecl _mm256_max_epi32(__m256i, __m256i);
extern __m256i __cdecl _mm256_max_epu8(__m256i, __m256i);
extern __m256i __cdecl _mm256_max_epu16(__m256i, __m256i);
extern __m256i __cdecl _mm256_max_epu32(__m256i, __m256i);

extern __m256i __cdecl _mm256_min_epi8(__m256i, __m256i);
extern __m256i __cdecl _mm256_min_epi16(__m256i, __m256i);
extern __m256i __cdecl _mm256_min_epi32(__m256i, __m256i);
extern __m256i __cdecl _mm256_min_epu8(__m256i, __m256i);
extern __m256i __cdecl _mm256_min_epu16(__m256i, __m256i);
extern __m256i __cdecl _mm256_min_epu32(__m256i, __m256i);

extern __m256i __cdecl _mm256_and_si256(__m256i, __m256i);
extern __m256i __cdecl _mm256_andnot_si256(__m256i, __m256i);
extern __m256i __cdecl _mm256_or_si256(__m256i, __m256i);
extern __m256i __cdecl _mm256_xor_si256(__m256i, __m256i);

extern __m256i __cdecl _mm256_abs_epi8(__m256i);
extern __m256i __cdecl _mm256_abs_epi16(__m256i);
extern __m256i __cdecl _mm256_abs_epi32(__m256i);

extern __m256i __cdecl _mm256_add_epi8(__m256i, __m256i);
extern __m256i __cdecl _mm256_add_epi16(__m256i, __m256i);
extern __m256i __cdecl _mm256_add_epi32(__m256i, __m256i);
extern __m256i __cdecl _mm256_add_epi64(__m256i, __m256i);

extern __m256i __cdecl _mm256_adds_epi8(__m256i, __m256i);
extern __m256i __cdecl _mm256_adds_epi16(__m256i, __m256i);
extern __m256i __cdecl _mm256_adds_epu8(__m256i, __m256i);
extern __m256i __cdecl _mm256_adds_epu16(__m256i, __m256i);

extern __m256i __cdecl _mm256_sub_epi8(__m256i, __m256i);
extern __m256i __cdecl _mm256_sub_epi16(__m256i, __m256i);
extern __m256i __cdecl _mm256_sub_epi32(__m256i, __m256i);
extern __m256i __cdecl _mm256_sub_epi64(__m256i, __m256i);

extern __m256i __cdecl _mm256_subs_epi8(__m256i, __m256i);
extern __m256i __cdecl _mm256_subs_epi16(__m256i, __m256i);
extern __m256i __cdecl _mm256_subs_epu8(__m256i, __m256i);
extern __m256i __cdecl _mm256_subs_epu16(__m256i, __m256i);

extern __m256i __cdecl _mm256_avg_epu8(__m256i, __m256i);
extern __m256i __cdecl _mm256_avg_epu16(__m256i, __m256i);

extern __m256i __cdecl _mm256_hadd_epi16(__m256i, __m256i);
extern __m256i __cdecl _mm256_hadd_epi32(__m256i, __m256i);
extern __m256i __cdecl _mm256_hadds_epi16(__m256i, __m256i);

extern __m256i __cdecl _mm256_hsub_epi16(__m256i, __m256i);
extern __m256i __cdecl _mm256_hsub_epi32(__m256i, __m256i);
extern __m256i __cdecl _mm256_hsubs_epi16(__m256i, __m256i);

extern __m256i __cdecl _mm256_madd_epi16(__m256i, __m256i);
extern __m256i __cdecl _mm256_maddubs_epi16(__m256i, __m256i);

extern __m256i __cdecl _mm256_mulhi_epi16(__m256i, __m256i);
extern __m256i __cdecl _mm256_mulhi_epu16(__m256i, __m256i);

extern __m256i __cdecl _mm256_mullo_epi16(__m256i, __m256i);
extern __m256i __cdecl _mm256_mullo_epi32(__m256i, __m256i);

extern __m256i __cdecl _mm256_mul_epu32(__m256i, __m256i);
extern __m256i __cdecl _mm256_mul_epi32(__m256i, __m256i);

extern __m256i __cdecl _mm256_sign_epi8(__m256i, __m256i);
extern __m256i __cdecl _mm256_sign_epi16(__m256i, __m256i);
extern __m256i __cdecl _mm256_sign_epi32(__m256i, __m256i);

extern __m256i __cdecl _mm256_mulhrs_epi16(__m256i, __m256i);

extern __m256i __cdecl _mm256_sad_epu8(__m256i, __m256i);
extern __m256i __cdecl _mm256_mpsadbw_epu8(__m256i, __m256i, const int);

extern __m256i __cdecl _mm256_slli_si256(__m256i, const int);
#define _mm256_bslli_epi128 _mm256_slli_si256
extern __m256i __cdecl _mm256_srli_si256(__m256i, const int);
#define _mm256_bsrli_epi128 _mm256_srli_si256

extern __m256i __cdecl _mm256_sll_epi16(__m256i, __m128i);
extern __m256i __cdecl _mm256_sll_epi32(__m256i, __m128i);
extern __m256i __cdecl _mm256_sll_epi64(__m256i, __m128i);

extern __m256i __cdecl _mm256_slli_epi16(__m256i, int);
extern __m256i __cdecl _mm256_slli_epi32(__m256i, int);
extern __m256i __cdecl _mm256_slli_epi64(__m256i, int);

extern __m256i __cdecl _mm256_sllv_epi32(__m256i, __m256i);
extern __m256i __cdecl _mm256_sllv_epi64(__m256i, __m256i);

extern __m128i __cdecl _mm_sllv_epi32(__m128i, __m128i);
extern __m128i __cdecl _mm_sllv_epi64(__m128i, __m128i);

extern __m256i __cdecl _mm256_sra_epi16(__m256i, __m128i);
extern __m256i __cdecl _mm256_sra_epi32(__m256i, __m128i);

extern __m256i __cdecl _mm256_srai_epi16(__m256i, int);
extern __m256i __cdecl _mm256_srai_epi32(__m256i, int);

extern __m256i __cdecl _mm256_srav_epi32(__m256i, __m256i);

extern __m128i __cdecl _mm_srav_epi32(__m128i, __m128i);

extern __m256i __cdecl _mm256_srl_epi16(__m256i, __m128i);
extern __m256i __cdecl _mm256_srl_epi32(__m256i, __m128i);
extern __m256i __cdecl _mm256_srl_epi64(__m256i, __m128i);

extern __m256i __cdecl _mm256_srli_epi16(__m256i, int);
extern __m256i __cdecl _mm256_srli_epi32(__m256i, int);
extern __m256i __cdecl _mm256_srli_epi64(__m256i, int);

extern __m256i __cdecl _mm256_srlv_epi32(__m256i, __m256i);
extern __m256i __cdecl _mm256_srlv_epi64(__m256i, __m256i);

extern __m128i __cdecl _mm_srlv_epi32(__m128i, __m128i);
extern __m128i __cdecl _mm_srlv_epi64(__m128i, __m128i);

extern __m128i __cdecl _mm_blend_epi32(__m128i, __m128i, const int);

extern __m256i __cdecl _mm256_blend_epi32(__m256i, __m256i, const int);

extern __m256i __cdecl _mm256_alignr_epi8(__m256i, __m256i, const int);

extern __m256i __cdecl _mm256_blendv_epi8(__m256i, __m256i, __m256i);
extern __m256i __cdecl _mm256_blend_epi16(__m256i, __m256i, const int);

extern __m256i __cdecl _mm256_packs_epi16(__m256i, __m256i);
extern __m256i __cdecl _mm256_packs_epi32(__m256i, __m256i);
extern __m256i __cdecl _mm256_packus_epi16(__m256i, __m256i);
extern __m256i __cdecl _mm256_packus_epi32(__m256i, __m256i);

extern __m256i __cdecl _mm256_unpackhi_epi8(__m256i, __m256i);
extern __m256i __cdecl _mm256_unpackhi_epi16(__m256i, __m256i);
extern __m256i __cdecl _mm256_unpackhi_epi32(__m256i, __m256i);
extern __m256i __cdecl _mm256_unpackhi_epi64(__m256i, __m256i);

extern __m256i __cdecl _mm256_unpacklo_epi8(__m256i, __m256i);
extern __m256i __cdecl _mm256_unpacklo_epi16(__m256i, __m256i);
extern __m256i __cdecl _mm256_unpacklo_epi32(__m256i, __m256i);
extern __m256i __cdecl _mm256_unpacklo_epi64(__m256i, __m256i);

extern __m256i __cdecl _mm256_shuffle_epi8(__m256i, __m256i);
extern __m256i __cdecl _mm256_shuffle_epi32(__m256i, const int);

extern __m256i __cdecl _mm256_shufflehi_epi16(__m256i, const int);
extern __m256i __cdecl _mm256_shufflelo_epi16(__m256i, const int);

extern __m128i __cdecl _mm256_extracti128_si256(__m256i, const int);
extern __m256i __cdecl _mm256_inserti128_si256(__m256i, __m128i, const int);

extern __m128 __cdecl _mm_broadcastss_ps(__m128);
extern __m128d __cdecl _mm_broadcastsd_pd(__m128d);

extern __m128i __cdecl _mm_broadcastb_epi8(__m128i);
extern __m128i __cdecl _mm_broadcastw_epi16(__m128i);
extern __m128i __cdecl _mm_broadcastd_epi32(__m128i);
extern __m128i __cdecl _mm_broadcastq_epi64(__m128i);

extern __m256 __cdecl _mm256_broadcastss_ps(__m128);
extern __m256d __cdecl _mm256_broadcastsd_pd(__m128d);

extern __m256i __cdecl _mm256_broadcastb_epi8(__m128i);
extern __m256i __cdecl _mm256_broadcastw_epi16(__m128i);
extern __m256i __cdecl _mm256_broadcastd_epi32(__m128i);
extern __m256i __cdecl _mm256_broadcastq_epi64(__m128i);

extern __m256i __cdecl _mm256_broadcastsi128_si256(__m128i);

extern __m256i __cdecl _mm256_cvtepi8_epi16(__m128i);
extern __m256i __cdecl _mm256_cvtepi8_epi32(__m128i);
extern __m256i __cdecl _mm256_cvtepi8_epi64(__m128i);
extern __m256i __cdecl _mm256_cvtepi16_epi32(__m128i);
extern __m256i __cdecl _mm256_cvtepi16_epi64(__m128i);
extern __m256i __cdecl _mm256_cvtepi32_epi64(__m128i);

extern __m256i __cdecl _mm256_cvtepu8_epi16(__m128i);
extern __m256i __cdecl _mm256_cvtepu8_epi32(__m128i);
extern __m256i __cdecl _mm256_cvtepu8_epi64(__m128i);
extern __m256i __cdecl _mm256_cvtepu16_epi32(__m128i);
extern __m256i __cdecl _mm256_cvtepu16_epi64(__m128i);
extern __m256i __cdecl _mm256_cvtepu32_epi64(__m128i);

extern int __cdecl _mm256_movemask_epi8(__m256i);

extern __m128i __cdecl _mm_maskload_epi32(int const* /* ptr */, __m128i /* vmask */);
extern __m128i __cdecl _mm_maskload_epi64(__int64 const* /* ptr */, __m128i /* vmask */);

extern void __cdecl _mm_maskstore_epi32(int* /* ptr */, __m128i /* vmask */, __m128i /* val */);
extern void __cdecl _mm_maskstore_epi64(__int64* /* ptr */, __m128i /* vmask */, __m128i /* val */);

extern __m256i __cdecl _mm256_maskload_epi32(int const* /* ptr */, __m256i /* vmask */);
extern __m256i __cdecl _mm256_maskload_epi64(__int64 const* /* ptr */, __m256i /* vmask */);

extern void __cdecl _mm256_maskstore_epi32(int* /* ptr */, __m256i /* vmask */, __m256i /* val */);
extern void __cdecl _mm256_maskstore_epi64(__int64* /* ptr */, __m256i /* vmask */, __m256i /* val */);

extern __m256i __cdecl _mm256_permutevar8x32_epi32(__m256i, __m256i);
extern __m256 __cdecl _mm256_permutevar8x32_ps(__m256, __m256i);

extern __m256i __cdecl _mm256_permute4x64_epi64(__m256i, const int);
extern __m256d __cdecl _mm256_permute4x64_pd(__m256d, const int);

extern __m256i __cdecl _mm256_permute2x128_si256(__m256i, __m256i, const int);

extern __m256i __cdecl _mm256_stream_load_si256(__m256i const*);

extern __m256d __cdecl _mm256_mask_i32gather_pd(__m256d /* old_dst */, double const* /* ptr */, __m128i /* vindex */,
                                                __m256d /* vmask */, const int /* scale */);
extern __m256 __cdecl _mm256_mask_i32gather_ps(__m256 /* old_dst */, float const* /* ptr */, __m256i /* vindex */,
                                               __m256 /* vmask */, const int /* scale */);
extern __m256d __cdecl _mm256_mask_i64gather_pd(__m256d /* old_dst */, double const* /* ptr */, __m256i /* vindex */,
                                                __m256d /* vmask */, const int /* scale */);
extern __m128 __cdecl _mm256_mask_i64gather_ps(__m128 /* old_dst */, float const* /* ptr */, __m256i /* vindex */,
                                               __m128 /* vmask */, const int /* scale */);

extern __m128d __cdecl _mm_mask_i32gather_pd(__m128d /* old_dst */, double const* /* ptr */, __m128i /* vindex */,
                                             __m128d /* vmask */, const int /* scale */);
extern __m128 __cdecl _mm_mask_i32gather_ps(__m128 /* old_dst */, float const* /* ptr */, __m128i /* vindex */,
                                            __m128 /* vmask */, const int /* scale */);
extern __m128d __cdecl _mm_mask_i64gather_pd(__m128d /* old_dst */, double const* /* ptr */, __m128i /* vindex */,
                                             __m128d /* vmask */, const int /* scale */);
extern __m128 __cdecl _mm_mask_i64gather_ps(__m128 /* old_dst */, float const* /* ptr */, __m128i /* vindex */,
                                            __m128 /* vmask */, const int /* scale */);

extern __m256i __cdecl _mm256_mask_i32gather_epi32(__m256i /* old_dst */, int const* /* ptr */, __m256i /* vindex */,
                                                   __m256i /* vmask */, const int /* scale */);
extern __m256i __cdecl _mm256_mask_i32gather_epi64(__m256i /* old_dst */, __int64 const* /* ptr */,
                                                   __m128i /* vindex */, __m256i /* vmask */, const int /* scale */);
extern __m128i __cdecl _mm256_mask_i64gather_epi32(__m128i /* old_dst */, int const* /* ptr */, __m256i /* vindex */,
                                                   __m128i /* vmask */, const int /* scale */);
extern __m256i __cdecl _mm256_mask_i64gather_epi64(__m256i /* old_dst */, __int64 const* /* ptr */,
                                                   __m256i /* vindex */, __m256i /* vmask */, const int /* scale */);

extern __m128i __cdecl _mm_mask_i32gather_epi32(__m128i /* old_dst */, int const* /* ptr */, __m128i /* vindex */,
                                                __m128i /* vmask */, const int /* scale */);
extern __m128i __cdecl _mm_mask_i32gather_epi64(__m128i /* old_dst */, __int64 const* /* ptr */, __m128i /* vindex */,
                                                __m128i /* vmask */, const int /* scale */);
extern __m128i __cdecl _mm_mask_i64gather_epi32(__m128i /* old_dst */, int const* /* ptr */, __m128i /* vindex */,
                                                __m128i /* vmask */, const int /* scale */);
extern __m128i __cdecl _mm_mask_i64gather_epi64(__m128i /* old_dst */, __int64 const* /* ptr */, __m128i /* vindex */,
                                                __m128i /* vmask */, const int /* scale */);

extern __m256d __cdecl _mm256_i32gather_pd(double const* /* ptr */, __m128i /* vindex */, const int /* index_scale */);
extern __m256 __cdecl _mm256_i32gather_ps(float const* /* ptr */, __m256i /* vindex */, const int /* index_scale */);
extern __m256d __cdecl _mm256_i64gather_pd(double const* /* ptr */, __m256i /* vindex */, const int /* index_scale */);
extern __m128 __cdecl _mm256_i64gather_ps(float const* /* ptr */, __m256i /* vindex */, const int /* index_scale */);

extern __m128d __cdecl _mm_i32gather_pd(double const* /* ptr */, __m128i /* vindex */, const int /* index_scale */);
extern __m128 __cdecl _mm_i32gather_ps(float const* /* ptr */, __m128i /* vindex */, const int /* index_scale */);
extern __m128d __cdecl _mm_i64gather_pd(double const* /* ptr */, __m128i /* vindex */, const int /* index_scale */);
extern __m128 __cdecl _mm_i64gather_ps(float const* /* ptr */, __m128i /* vindex */, const int /* index_scale */);

extern __m256i __cdecl _mm256_i32gather_epi32(int const* /* ptr */, __m256i /* vindex */, const int /* scale */);
extern __m256i __cdecl _mm256_i32gather_epi64(__int64 const* /* ptr */, __m128i /* vindex */, const int /* scale */);
extern __m128i __cdecl _mm256_i64gather_epi32(int const* /* ptr */, __m256i /* vindex */, const int /* scale */);
extern __m256i __cdecl _mm256_i64gather_epi64(__int64 const* /* ptr */, __m256i /* vindex */, const int /* scale */);

extern __m128i __cdecl _mm_i32gather_epi32(int const* /* ptr */, __m128i /* vindex */, const int /* index_scale */);
extern __m128i __cdecl _mm_i32gather_epi64(__int64 const* /* ptr */, __m128i /* vindex */, const int /* index_scale */);
extern __m128i __cdecl _mm_i64gather_epi32(int const* /* ptr */, __m128i /* vindex */, const int /* index_scale */);
extern __m128i __cdecl _mm_i64gather_epi64(__int64 const* /* ptr */, __m128i /* vindex */, const int /* index_scale */);

// unaligned load and store functions
#define _mm_loadu_si16(p) _mm_cvtsi32_si128(*(unsigned short const*)(p))
#define _mm_storeu_si16(p, a) (void)(*(short*)(p) = (short)_mm_cvtsi128_si32((a)))
#define _mm_loadu_si32(p) _mm_cvtsi32_si128(*(unsigned int const*)(p))
#define _mm_storeu_si32(p, a) (void)(*(int*)(p) = _mm_cvtsi128_si32((a)))
#define _mm_loadu_si64(p) _mm_loadl_epi64((__m128i const*)(p))
#define _mm_storeu_si64(p, a) (_mm_storel_epi64((__m128i*)(p), (a)))

extern unsigned int _bextr_u32(unsigned int /* src */, unsigned int /* start_bit */, unsigned int /* len_in_bits */);
extern unsigned int _bextr2_u32(unsigned int /* src */, unsigned int /* start_and_len_in_bits */);
extern unsigned int _blsi_u32(unsigned int);
extern unsigned int _blsmsk_u32(unsigned int);
extern unsigned int _blsr_u32(unsigned int);
extern unsigned int _bzhi_u32(unsigned int /* src */, unsigned int /* index */);
extern unsigned int _mulx_u32(unsigned int /* src1 */, unsigned int /* src2 */, unsigned int* /* high_bits */);
extern unsigned int _pdep_u32(unsigned int /* src */, unsigned int /* mask */);
extern unsigned int _pext_u32(unsigned int /* src */, unsigned int /* mask */);
extern unsigned int _rorx_u32(unsigned int /* src */, const unsigned int /* shift_count */);
extern int _sarx_i32(int /* src */, unsigned int /* shift_count */);
extern unsigned int _shlx_u32(unsigned int /* src */, unsigned int /* shift_count */);
extern unsigned int _shrx_u32(unsigned int /* src */, unsigned int /* shift_count */);

#if defined(_M_X64)
extern unsigned __int64 _bextr_u64(unsigned __int64 /* src */, unsigned int /* start_bit */,
                                   unsigned int /* len_in_bits */);
extern unsigned __int64 _bextr2_u64(unsigned __int64 /* src */, unsigned __int64 /* start_and_len_in_bits */);
extern unsigned __int64 _blsi_u64(unsigned __int64);
extern unsigned __int64 _blsmsk_u64(unsigned __int64);
extern unsigned __int64 _blsr_u64(unsigned __int64);
extern unsigned __int64 _bzhi_u64(unsigned __int64 /* src */, unsigned int /* index */);
extern unsigned __int64 _mulx_u64(unsigned __int64 /* src1 */, unsigned __int64 /* src2 */,
                                  unsigned __int64* /* high_bits */);
extern unsigned __int64 _pdep_u64(unsigned __int64 /* src */, unsigned __int64 /* mask */);
extern unsigned __int64 _pext_u64(unsigned __int64 /* src */, unsigned __int64 /* mask */);
extern unsigned __int64 _rorx_u64(unsigned __int64 /* src */, const unsigned int /* shift_count */);
extern __int64 _sarx_i64(__int64 /* src */, unsigned int /* shift_count */);
extern unsigned __int64 _shlx_u64(unsigned __int64 /* src */, unsigned int /* shift_count */);
extern unsigned __int64 _shrx_u64(unsigned __int64 /* src */, unsigned int /* shift_count */);
#endif /* defined (_M_X64) */

/* * */
extern unsigned int _lzcnt_u32(unsigned int);
#if defined(_M_X64)
extern unsigned __int64 _lzcnt_u64(unsigned __int64);
#endif /* defined (_M_X64) */

/* * */
extern unsigned __int16 _tzcnt_u16(unsigned __int16);
extern unsigned int _tzcnt_u32(unsigned int);
#if defined(_M_X64)
extern unsigned __int64 _tzcnt_u64(unsigned __int64);
#endif /* defined (_M_X64) */

extern void __cdecl _invpcid(unsigned int /* type */, void* /* descriptor */);

// Hardware Lock Elision
extern void _Store_HLERelease(long volatile*, long);
extern void _StorePointer_HLERelease(void* volatile*, void*);

extern long _InterlockedExchange_HLEAcquire(long volatile*, long);
extern long _InterlockedExchange_HLERelease(long volatile*, long);
extern void* _InterlockedExchangePointer_HLEAcquire(void* volatile*, void*);
extern void* _InterlockedExchangePointer_HLERelease(void* volatile*, void*);

extern long _InterlockedCompareExchange_HLEAcquire(long volatile*, long, long);
extern long _InterlockedCompareExchange_HLERelease(long volatile*, long, long);
extern __int64 _InterlockedCompareExchange64_HLEAcquire(__int64 volatile*, __int64, __int64);
extern __int64 _InterlockedCompareExchange64_HLERelease(__int64 volatile*, __int64, __int64);
extern void* _InterlockedCompareExchangePointer_HLEAcquire(void* volatile*, void*, void*);
extern void* _InterlockedCompareExchangePointer_HLERelease(void* volatile*, void*, void*);

extern long _InterlockedExchangeAdd_HLEAcquire(long volatile*, long);
extern long _InterlockedExchangeAdd_HLERelease(long volatile*, long);

extern long _InterlockedAnd_HLEAcquire(long volatile*, long);
extern long _InterlockedAnd_HLERelease(long volatile*, long);
extern long _InterlockedOr_HLEAcquire(long volatile*, long);
extern long _InterlockedOr_HLERelease(long volatile*, long);
extern long _InterlockedXor_HLEAcquire(long volatile*, long);
extern long _InterlockedXor_HLERelease(long volatile*, long);

extern unsigned char _interlockedbittestandset_HLEAcquire(long*, long);
extern unsigned char _interlockedbittestandset_HLERelease(long*, long);
extern unsigned char _interlockedbittestandreset_HLEAcquire(long*, long);
extern unsigned char _interlockedbittestandreset_HLERelease(long*, long);

#if defined(_M_X64)
extern void _Store64_HLERelease(__int64 volatile*, __int64);
extern __int64 _InterlockedExchange64_HLEAcquire(__int64 volatile*, __int64);
extern __int64 _InterlockedExchange64_HLERelease(__int64 volatile*, __int64);

extern __int64 _InterlockedExchangeAdd64_HLEAcquire(__int64 volatile*, __int64);
extern __int64 _InterlockedExchangeAdd64_HLERelease(__int64 volatile*, __int64);

extern __int64 _InterlockedAnd64_HLEAcquire(__int64 volatile*, __int64);
extern __int64 _InterlockedAnd64_HLERelease(__int64 volatile*, __int64);
extern __int64 _InterlockedOr64_HLEAcquire(__int64 volatile*, __int64);
extern __int64 _InterlockedOr64_HLERelease(__int64 volatile*, __int64);
extern __int64 _InterlockedXor64_HLEAcquire(__int64 volatile*, __int64);
extern __int64 _InterlockedXor64_HLERelease(__int64 volatile*, __int64);

extern unsigned char _interlockedbittestandset64_HLEAcquire(__int64*, __int64);
extern unsigned char _interlockedbittestandset64_HLERelease(__int64*, __int64);
extern unsigned char _interlockedbittestandreset64_HLEAcquire(__int64*, __int64);
extern unsigned char _interlockedbittestandreset64_HLERelease(__int64*, __int64);
#endif /* defined (_M_X64) */

//  Restricted Transactional Memory
#define _XBEGIN_STARTED (~0u)
#define _XABORT_EXPLICIT (1 << 0)
#define _XABORT_RETRY (1 << 1)
#define _XABORT_CONFLICT (1 << 2)
#define _XABORT_CAPACITY (1 << 3)
#define _XABORT_DEBUG (1 << 4)
#define _XABORT_NESTED (1 << 5)
#define _XABORT_CODE(x) ((unsigned char)(((x) >> 24) & 0xFF))

extern unsigned int __cdecl _xbegin();
extern void __cdecl _xend();
extern void __cdecl _xabort(const unsigned int);
extern unsigned char __cdecl _xtest();

extern int __cdecl _rdseed16_step(unsigned short*);
extern int __cdecl _rdseed32_step(unsigned int*);
#if defined(_M_X64)
extern int __cdecl _rdseed64_step(unsigned __int64*);
#endif /* defined (_M_X64) */

extern unsigned char __cdecl _addcarryx_u32(unsigned char /*c_in*/, unsigned int /*src1*/, unsigned int /*src2*/,
                                            unsigned int* /*out*/);

#if defined(_M_X64)
extern unsigned char __cdecl _addcarryx_u64(unsigned char /*c_in*/, unsigned __int64 /*src1*/,
                                            unsigned __int64 /*src2*/, unsigned __int64* /*out*/);
#endif /* defined (_M_X64) */

extern unsigned short __cdecl _load_be_u16(void const*);
extern unsigned int __cdecl _load_be_u32(void const*);
extern unsigned __int64 __cdecl _load_be_u64(void const*);
#define _loadbe_i16(be_ptr) ((short)_load_be_u16(be_ptr))
#define _loadbe_i32(be_ptr) ((int)_load_be_u32(be_ptr))
#define _loadbe_i64(be_ptr) ((__int64)_load_be_u64(be_ptr))

extern void __cdecl _store_be_u16(void*, unsigned short);
extern void __cdecl _store_be_u32(void*, unsigned int);
extern void __cdecl _store_be_u64(void*, unsigned __int64);
#define _storebe_i16(be_ptr, val) _store_be_u16(be_ptr, (unsigned short)(val))
#define _storebe_i32(be_ptr, val) _store_be_u32(be_ptr, (unsigned int)(val))
#define _storebe_i64(be_ptr, val) _store_be_u64(be_ptr, (unsigned __int64)(__int64)(val))

/**/
extern __m128i __cdecl _mm_sha1msg1_epu32(__m128i, __m128i);
extern __m128i __cdecl _mm_sha1msg2_epu32(__m128i, __m128i);
extern __m128i __cdecl _mm_sha1nexte_epu32(__m128i, __m128i);
extern __m128i __cdecl _mm_sha1rnds4_epu32(__m128i, __m128i, const int);

extern __m128i __cdecl _mm_sha256msg1_epu32(__m128i, __m128i);
extern __m128i __cdecl _mm_sha256msg2_epu32(__m128i, __m128i);
extern __m128i __cdecl _mm_sha256rnds2_epu32(__m128i, __m128i, __m128i);

extern void* __cdecl _bnd_set_ptr_bounds(const void*, size_t);
extern void* __cdecl _bnd_narrow_ptr_bounds(const void*, const void*, size_t);
extern void* __cdecl _bnd_copy_ptr_bounds(const void*, const void*);
extern void* __cdecl _bnd_init_ptr_bounds(const void*);
extern void __cdecl _bnd_store_ptr_bounds(const void**, const void*);
extern void __cdecl _bnd_chk_ptr_lbounds(const void*);
extern void __cdecl _bnd_chk_ptr_ubounds(const void*);
extern void __cdecl _bnd_chk_ptr_bounds(const void*, size_t);
extern void* __cdecl _bnd_load_ptr_bounds(const void**, const void*);
extern const void* __cdecl _bnd_get_ptr_lbound(const void*);
extern const void* __cdecl _bnd_get_ptr_ubound(const void*);

// Insert integer into 256-bit packed integer array at element selected by index
extern __m256i __cdecl _mm256_insert_epi8(__m256i /* dst */, int /* src */, const int /* index */);
extern __m256i __cdecl _mm256_insert_epi16(__m256i /* dst */, int /* src */, const int /* index */);
extern __m256i __cdecl _mm256_insert_epi32(__m256i /* dst */, int /* src */, const int /* index */);
#if defined(_M_X64)
extern __m256i __cdecl _mm256_insert_epi64(__m256i /* dst */, __int64 /* src */, const int /* index */);
#endif // defined (_M_X64)

// Extract integer element selected by index from 256-bit packed integer array
extern int __cdecl _mm256_extract_epi8(__m256i /* src */, const int /* index */);
extern int __cdecl _mm256_extract_epi16(__m256i /* src */, const int /* index */);
extern int __cdecl _mm256_extract_epi32(__m256i /* src */, const int /* index */);
#if defined(_M_X64)
extern __int64 __cdecl _mm256_extract_epi64(__m256i /* src */, const int /* index */);
#endif // defined (_M_X64)

// Zero-extended cast functions
extern __m256d __cdecl _mm256_zextpd128_pd256(__m128d);
extern __m256 __cdecl _mm256_zextps128_ps256(__m128);
extern __m256i __cdecl _mm256_zextsi128_si256(__m128i);

// RDPID
extern unsigned int __cdecl _rdpid_u32();
// PTWRITE
extern void __cdecl _ptwrite32(unsigned int);
#if defined(_M_X64)
extern void __cdecl _ptwrite64(unsigned __int64);
#endif // defined (_M_X64)

// AVX_VNNI intrinsics
extern __m128i __cdecl _mm_dpbusd_avx_epi32(__m128i, __m128i, __m128i);
extern __m256i __cdecl _mm256_dpbusd_avx_epi32(__m256i, __m256i, __m256i);
extern __m128i __cdecl _mm_dpbusds_avx_epi32(__m128i, __m128i, __m128i);
extern __m256i __cdecl _mm256_dpbusds_avx_epi32(__m256i, __m256i, __m256i);
extern __m128i __cdecl _mm_dpwssd_avx_epi32(__m128i, __m128i, __m128i);
extern __m256i __cdecl _mm256_dpwssd_avx_epi32(__m256i, __m256i, __m256i);
extern __m128i __cdecl _mm_dpwssds_avx_epi32(__m128i, __m128i, __m128i);
extern __m256i __cdecl _mm256_dpwssds_avx_epi32(__m256i, __m256i, __m256i);

// MKTME
extern unsigned int __cdecl _pconfig_u32(const int, size_t __data[]);
extern void __cdecl _wbnoinvd();

// SGX
extern unsigned int __cdecl _encls_u32(const int, size_t __data[]);
extern unsigned int __cdecl _enclu_u32(const int, size_t __data[]);
extern unsigned int __cdecl _enclv_u32(const int, size_t __data[]);

// Div & idiv
#if defined(_M_X64)
// _udiv128 is also declared in <intrin0.inl.h>
extern unsigned __int64 __cdecl _udiv128(unsigned __int64 /* highdividend */, unsigned __int64 /* lowdividend */,
                                         unsigned __int64 /* divisor */, unsigned __int64* /* remainder */);
extern __int64 __cdecl _div128(__int64 /* highdividend */, __int64 /* lowdividend */, __int64 /* divisor */,
                               __int64* /* remainder */);
#endif // defined (_M_X64)
extern unsigned __cdecl _udiv64(unsigned __int64 /* dividend */, unsigned /* divisor */, unsigned* /* remainder */);
extern int __cdecl _div64(__int64 /* dividend */, int /* divisor */, int* /* remainder */);

// Keylocker
extern unsigned char _mm_aesdec128kl_u8(__m128i* /* odata */, __m128i /* idata */, const void* /* h */);
extern unsigned char _mm_aesdec256kl_u8(__m128i* /* odata */, __m128i /* idata */, const void* /* h */);
extern unsigned char _mm_aesdecwide128kl_u8(__m128i* /* odata */, const __m128i* /* idata */, const void* /* h */);
extern unsigned char _mm_aesdecwide256kl_u8(__m128i* /* odata */, const __m128i* /* idata */, const void* /* h */);
extern unsigned char _mm_aesenc128kl_u8(__m128i* /* odata */, __m128i /* idata */, const void* /* h */);
extern unsigned char _mm_aesenc256kl_u8(__m128i* /* odata */, __m128i /* idata */, const void* /* h */);
extern unsigned char _mm_aesencwide128kl_u8(__m128i* /* odata */, const __m128i* /* idata */, const void* /* h */);
extern unsigned char _mm_aesencwide256kl_u8(__m128i* /* odata */, const __m128i* /* idata */, const void* /* h */);
extern unsigned int _mm_encodekey128_u32(unsigned int /* htype */, __m128i /* key */, void* /* h */);
extern unsigned int _mm_encodekey256_u32(unsigned int /* htype */, __m128i /* key_lo */, __m128i /* key_hi */,
                                         void* /* h */);
extern void _mm_loadiwkey(unsigned int /* ctl */, __m128i /* intkey */, __m128i /* enkey_lo */, __m128i /* enkey_hi */);

// Protection key rights for user pages
extern unsigned int __cdecl _rdpkru_u32();
extern void __cdecl _wrpkru(unsigned int);

// Enqueue stores
extern int __cdecl _enqcmd(void* /* dst */, const void* /* src */);
extern int __cdecl _enqcmds(void* /* dst */, const void* /* src */);

/*
 * Intel(R) Control-Flow Enforcement Technology (CET) shadow stack intrinsic functions
 */
extern void __cdecl _incsspd(unsigned int);
extern unsigned int __cdecl _rdsspd();
extern void __cdecl _saveprevssp();
extern void __cdecl _rstorssp(void*);
extern void __cdecl _wrssd(unsigned int, void*);
extern void __cdecl _wrussd(unsigned int, void*);
extern void __cdecl _setssbsy();
extern void __cdecl _clrssbsy(void*);
extern void* __cdecl _switchssp(void*);
#if defined(_M_X64)
extern void __cdecl _incsspq(unsigned __int64);
extern unsigned __int64 __cdecl _rdsspq();
extern void __cdecl _wrssq(unsigned __int64, void*);
extern void __cdecl _wrussq(unsigned __int64, void*);
#endif

/*
 * Intrinsic functions for Short Vector Math Library (SVML)
 */

// vector integer divide and remainder
extern __m128i _mm_div_epi8(__m128i, __m128i);
extern __m128i _mm_div_epi16(__m128i, __m128i);
extern __m128i _mm_div_epi32(__m128i, __m128i);
extern __m128i _mm_div_epi64(__m128i, __m128i);
extern __m128i _mm_div_epu8(__m128i, __m128i);
extern __m128i _mm_div_epu16(__m128i, __m128i);
extern __m128i _mm_div_epu32(__m128i, __m128i);
extern __m128i _mm_div_epu64(__m128i, __m128i);
extern __m128i _mm_rem_epi8(__m128i, __m128i);
extern __m128i _mm_rem_epi16(__m128i, __m128i);
extern __m128i _mm_rem_epi32(__m128i, __m128i);
extern __m128i _mm_rem_epi64(__m128i, __m128i);
extern __m128i _mm_rem_epu8(__m128i, __m128i);
extern __m128i _mm_rem_epu16(__m128i, __m128i);
extern __m128i _mm_rem_epu32(__m128i, __m128i);
extern __m128i _mm_rem_epu64(__m128i, __m128i);
extern __m256i _mm256_div_epi8(__m256i, __m256i);
extern __m256i _mm256_div_epi16(__m256i, __m256i);
extern __m256i _mm256_div_epi32(__m256i, __m256i);
extern __m256i _mm256_div_epi64(__m256i, __m256i);
extern __m256i _mm256_div_epu8(__m256i, __m256i);
extern __m256i _mm256_div_epu16(__m256i, __m256i);
extern __m256i _mm256_div_epu32(__m256i, __m256i);
extern __m256i _mm256_div_epu64(__m256i, __m256i);
extern __m256i _mm256_rem_epi8(__m256i, __m256i);
extern __m256i _mm256_rem_epi16(__m256i, __m256i);
extern __m256i _mm256_rem_epi32(__m256i, __m256i);
extern __m256i _mm256_rem_epi64(__m256i, __m256i);
extern __m256i _mm256_rem_epu8(__m256i, __m256i);
extern __m256i _mm256_rem_epu16(__m256i, __m256i);
extern __m256i _mm256_rem_epu32(__m256i, __m256i);
extern __m256i _mm256_rem_epu64(__m256i, __m256i);

#define _mm_idiv_epi32 _mm_div_epi32
#define _mm_irem_epi32 _mm_rem_epi32
#define _mm_udiv_epi32 _mm_div_epu32
#define _mm_urem_epi32 _mm_rem_epu32
#define _mm256_idiv_epi32 _mm256_div_epi32
#define _mm256_irem_epi32 _mm256_rem_epi32
#define _mm256_udiv_epi32 _mm256_div_epu32
#define _mm256_urem_epi32 _mm256_rem_epu32

extern __m128i _mm_divrem_epi32(__m128i* /*rem_res*/, __m128i, __m128i);
extern __m128i _mm_divrem_epu32(__m128i* /*rem_res*/, __m128i, __m128i);
extern __m256i _mm256_divrem_epi32(__m256i* /*rem_res*/, __m256i, __m256i);
extern __m256i _mm256_divrem_epu32(__m256i* /*rem_res*/, __m256i, __m256i);

#define _mm_idivrem_epi32 _mm_divrem_epi32
#define _mm_udivrem_epi32 _mm_divrem_epu32
#define _mm256_idivrem_epi32 _mm256_divrem_epi32
#define _mm256_udivrem_epi32 _mm256_divrem_epu32

// Math functions
extern __m128 _mm_sin_ps(__m128);
extern __m128d _mm_sin_pd(__m128d);
extern __m256 _mm256_sin_ps(__m256);
extern __m256d _mm256_sin_pd(__m256d);
extern __m128 _mm_cos_ps(__m128);
extern __m128d _mm_cos_pd(__m128d);
extern __m256 _mm256_cos_ps(__m256);
extern __m256d _mm256_cos_pd(__m256d);
extern __m128 _mm_sincos_ps(__m128* /*cos_res*/, __m128);
extern __m128d _mm_sincos_pd(__m128d* /*cos_res*/, __m128d);
extern __m256 _mm256_sincos_ps(__m256* /*cos_res*/, __m256);
extern __m256d _mm256_sincos_pd(__m256d* /*cos_res*/, __m256d);
extern __m128 _mm_tan_ps(__m128);
extern __m128d _mm_tan_pd(__m128d);
extern __m256 _mm256_tan_ps(__m256);
extern __m256d _mm256_tan_pd(__m256d);
extern __m128 _mm_asin_ps(__m128);
extern __m128d _mm_asin_pd(__m128d);
extern __m256 _mm256_asin_ps(__m256);
extern __m256d _mm256_asin_pd(__m256d);
extern __m128 _mm_acos_ps(__m128);
extern __m128d _mm_acos_pd(__m128d);
extern __m256 _mm256_acos_ps(__m256);
extern __m256d _mm256_acos_pd(__m256d);
extern __m128 _mm_atan_ps(__m128);
extern __m128d _mm_atan_pd(__m128d);
extern __m256 _mm256_atan_ps(__m256);
extern __m256d _mm256_atan_pd(__m256d);
extern __m128 _mm_atan2_ps(__m128, __m128);
extern __m128d _mm_atan2_pd(__m128d, __m128d);
extern __m256 _mm256_atan2_ps(__m256, __m256);
extern __m256d _mm256_atan2_pd(__m256d, __m256d);
extern __m128 _mm_sind_ps(__m128);
extern __m128d _mm_sind_pd(__m128d);
extern __m256 _mm256_sind_ps(__m256);
extern __m256d _mm256_sind_pd(__m256d);
extern __m128 _mm_cosd_ps(__m128);
extern __m128d _mm_cosd_pd(__m128d);
extern __m256 _mm256_cosd_ps(__m256);
extern __m256d _mm256_cosd_pd(__m256d);
extern __m128 _mm_tand_ps(__m128);
extern __m128d _mm_tand_pd(__m128d);
extern __m256 _mm256_tand_ps(__m256);
extern __m256d _mm256_tand_pd(__m256d);
extern __m128 _mm_sinh_ps(__m128);
extern __m128d _mm_sinh_pd(__m128d);
extern __m256 _mm256_sinh_ps(__m256);
extern __m256d _mm256_sinh_pd(__m256d);
extern __m128 _mm_cosh_ps(__m128);
extern __m128d _mm_cosh_pd(__m128d);
extern __m256 _mm256_cosh_ps(__m256);
extern __m256d _mm256_cosh_pd(__m256d);
extern __m128 _mm_tanh_ps(__m128);
extern __m128d _mm_tanh_pd(__m128d);
extern __m256 _mm256_tanh_ps(__m256);
extern __m256d _mm256_tanh_pd(__m256d);
extern __m128 _mm_asinh_ps(__m128);
extern __m128d _mm_asinh_pd(__m128d);
extern __m256 _mm256_asinh_ps(__m256);
extern __m256d _mm256_asinh_pd(__m256d);
extern __m128 _mm_acosh_ps(__m128);
extern __m128d _mm_acosh_pd(__m128d);
extern __m256 _mm256_acosh_ps(__m256);
extern __m256d _mm256_acosh_pd(__m256d);
extern __m128 _mm_atanh_ps(__m128);
extern __m128d _mm_atanh_pd(__m128d);
extern __m256 _mm256_atanh_ps(__m256);
extern __m256d _mm256_atanh_pd(__m256d);
extern __m128 _mm_log_ps(__m128);
extern __m128d _mm_log_pd(__m128d);
extern __m256 _mm256_log_ps(__m256);
extern __m256d _mm256_log_pd(__m256d);
extern __m128 _mm_log1p_ps(__m128);
extern __m128d _mm_log1p_pd(__m128d);
extern __m256 _mm256_log1p_ps(__m256);
extern __m256d _mm256_log1p_pd(__m256d);
extern __m128 _mm_log10_ps(__m128);
extern __m128d _mm_log10_pd(__m128d);
extern __m256 _mm256_log10_ps(__m256);
extern __m256d _mm256_log10_pd(__m256d);
extern __m128 _mm_log2_ps(__m128);
extern __m128d _mm_log2_pd(__m128d);
extern __m256 _mm256_log2_ps(__m256);
extern __m256d _mm256_log2_pd(__m256d);
extern __m128 _mm_logb_ps(__m128);
extern __m128d _mm_logb_pd(__m128d);
extern __m256 _mm256_logb_ps(__m256);
extern __m256d _mm256_logb_pd(__m256d);
extern __m128 _mm_exp_ps(__m128);
extern __m128d _mm_exp_pd(__m128d);
extern __m256 _mm256_exp_ps(__m256);
extern __m256d _mm256_exp_pd(__m256d);
extern __m128 _mm_exp10_ps(__m128);
extern __m128d _mm_exp10_pd(__m128d);
extern __m256 _mm256_exp10_ps(__m256);
extern __m256d _mm256_exp10_pd(__m256d);
extern __m128 _mm_exp2_ps(__m128);
extern __m128d _mm_exp2_pd(__m128d);
extern __m256 _mm256_exp2_ps(__m256);
extern __m256d _mm256_exp2_pd(__m256d);
extern __m128 _mm_expm1_ps(__m128);
extern __m128d _mm_expm1_pd(__m128d);
extern __m256 _mm256_expm1_ps(__m256);
extern __m256d _mm256_expm1_pd(__m256d);
extern __m128 _mm_pow_ps(__m128, __m128);
extern __m128d _mm_pow_pd(__m128d, __m128d);
extern __m256 _mm256_pow_ps(__m256, __m256);
extern __m256d _mm256_pow_pd(__m256d, __m256d);
extern __m128 _mm_trunc_ps(__m128);
extern __m128d _mm_trunc_pd(__m128d);
extern __m256 _mm256_trunc_ps(__m256);
extern __m256d _mm256_trunc_pd(__m256d);
extern __m128 _mm_svml_floor_ps(__m128);
extern __m128d _mm_svml_floor_pd(__m128d);
extern __m256 _mm256_svml_floor_ps(__m256);
extern __m256d _mm256_svml_floor_pd(__m256d);
extern __m128 _mm_svml_ceil_ps(__m128);
extern __m128d _mm_svml_ceil_pd(__m128d);
extern __m256 _mm256_svml_ceil_ps(__m256);
extern __m256d _mm256_svml_ceil_pd(__m256d);
extern __m128 _mm_svml_round_ps(__m128);
extern __m128d _mm_svml_round_pd(__m128d);
extern __m256 _mm256_svml_round_ps(__m256);
extern __m256d _mm256_svml_round_pd(__m256d);
extern __m128 _mm_fmod_ps(__m128, __m128);
extern __m128d _mm_fmod_pd(__m128d, __m128d);
extern __m256 _mm256_fmod_ps(__m256, __m256);
extern __m256d _mm256_fmod_pd(__m256d, __m256d);
extern __m128 _mm_svml_sqrt_ps(__m128);
extern __m128d _mm_svml_sqrt_pd(__m128d);
extern __m256 _mm256_svml_sqrt_ps(__m256);
extern __m256d _mm256_svml_sqrt_pd(__m256d);
extern __m128 _mm_invsqrt_ps(__m128);
extern __m128d _mm_invsqrt_pd(__m128d);
extern __m256 _mm256_invsqrt_ps(__m256);
extern __m256d _mm256_invsqrt_pd(__m256d);
extern __m128 _mm_cbrt_ps(__m128);
extern __m128d _mm_cbrt_pd(__m128d);
extern __m256 _mm256_cbrt_ps(__m256);
extern __m256d _mm256_cbrt_pd(__m256d);
extern __m128 _mm_invcbrt_ps(__m128);
extern __m128d _mm_invcbrt_pd(__m128d);
extern __m256 _mm256_invcbrt_ps(__m256);
extern __m256d _mm256_invcbrt_pd(__m256d);
extern __m128 _mm_hypot_ps(__m128, __m128);
extern __m128d _mm_hypot_pd(__m128d, __m128d);
extern __m256 _mm256_hypot_ps(__m256, __m256);
extern __m256d _mm256_hypot_pd(__m256d, __m256d);
extern __m128 _mm_cdfnorm_ps(__m128);
extern __m128d _mm_cdfnorm_pd(__m128d);
extern __m256 _mm256_cdfnorm_ps(__m256);
extern __m256d _mm256_cdfnorm_pd(__m256d);
extern __m128 _mm_cdfnorminv_ps(__m128);
extern __m128d _mm_cdfnorminv_pd(__m128d);
extern __m256 _mm256_cdfnorminv_ps(__m256);
extern __m256d _mm256_cdfnorminv_pd(__m256d);
extern __m128 _mm_cexp_ps(__m128);
extern __m256 _mm256_cexp_ps(__m256);
extern __m128 _mm_clog_ps(__m128);
extern __m256 _mm256_clog_ps(__m256);
extern __m128 _mm_csqrt_ps(__m128);
extern __m256 _mm256_csqrt_ps(__m256);
extern __m128 _mm_erf_ps(__m128);
extern __m128d _mm_erf_pd(__m128d);
extern __m256 _mm256_erf_ps(__m256);
extern __m256d _mm256_erf_pd(__m256d);
extern __m128 _mm_erfc_ps(__m128);
extern __m128d _mm_erfc_pd(__m128d);
extern __m256 _mm256_erfc_ps(__m256);
extern __m256d _mm256_erfc_pd(__m256d);
extern __m128 _mm_erfcinv_ps(__m128);
extern __m128d _mm_erfcinv_pd(__m128d);
extern __m256 _mm256_erfcinv_ps(__m256);
extern __m256d _mm256_erfcinv_pd(__m256d);
extern __m128 _mm_erfinv_ps(__m128);
extern __m128d _mm_erfinv_pd(__m128d);
extern __m256 _mm256_erfinv_ps(__m256);
extern __m256d _mm256_erfinv_pd(__m256d);

/* Cache line demote */
extern void _mm_cldemote(void const*);
#define _cldemote _mm_cldemote

/* Direct stores */
extern void _directstoreu_u32(void*, unsigned int);
#if defined(_M_X64)
extern void _directstoreu_u64(void*, unsigned __int64);
#endif /* defined (_M_X64) */
extern void _movdir64b(void*, void const*);

/* serialize and TSX load tracking */
extern void __cdecl _serialize();
extern void __cdecl _xsusldtrk();
extern void __cdecl _xresldtrk();

/* User wait */
extern void _umonitor(void*);
extern unsigned char _umwait(unsigned int, unsigned __int64);
extern unsigned char _tpause(unsigned int, unsigned __int64);

/* user interrupts */
#if defined(_M_X64)
extern void _clui();
extern void _stui();
extern unsigned char _testui();
extern void _senduipi(unsigned __int64);
#endif /* defined (_M_X64) */

/* Hreset */
extern void _hreset(unsigned __int32);

/* SVML conversions (no AVX-512 support needed) */
extern __m128 _mm_svml_cvtepu32_ps(__m128i);
extern __m256 _mm256_svml_cvtepu32_ps(__m256i);
extern __m128d _mm_svml_cvtepu32_pd(__m128i);
extern __m256d _mm256_svml_cvtepu32_pd(__m128i);
extern __m128d _mm_svml_cvtepi64_pd(__m128i);
extern __m256d _mm256_svml_cvtepi64_pd(__m256i);
extern __m128d _mm_svml_cvtepu64_pd(__m128i);
extern __m256d _mm256_svml_cvtepu64_pd(__m256i);

/* casting between floating-point and representation bit pattern as unsigned */
extern unsigned __int32 _castf32_u32(float);
extern unsigned __int64 _castf64_u64(double);
extern float _castu32_f32(unsigned __int32);
extern double _castu64_f64(unsigned __int64);

#if defined __cplusplus
}; /* End "C" */
#endif /* defined __cplusplus */

#include <zmmintrin.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

// No AVX-512 support needed, but require zmmintrin.h definitions for bfloat16 types.

/* Intel(R) AVX-IFMA */
extern __m128i __cdecl _mm_madd52hi_avx_epu64(__m128i, __m128i, __m128i);
extern __m256i __cdecl _mm256_madd52hi_avx_epu64(__m256i, __m256i, __m256i);
extern __m128i __cdecl _mm_madd52lo_avx_epu64(__m128i, __m128i, __m128i);
extern __m256i __cdecl _mm256_madd52lo_avx_epu64(__m256i, __m256i, __m256i);

/* Intel(R) AVX-NE-CONVERT */
extern __m128 __cdecl _mm_bcstnebf16_ps(const __bfloat16*);
extern __m256 __cdecl _mm256_bcstnebf16_ps(const __bfloat16*);
extern __m128 __cdecl _mm_bcstnesh_ps(const void*);
extern __m256 __cdecl _mm256_bcstnesh_ps(const void*);
extern __m128 __cdecl _mm_cvtneebf16_ps(const __m128bh*);
extern __m256 __cdecl _mm256_cvtneebf16_ps(const __m256bh*);
extern __m128 __cdecl _mm_cvtneeph_ps(const __m128h*);
extern __m256 __cdecl _mm256_cvtneeph_ps(const __m256h*);
extern __m128 __cdecl _mm_cvtneobf16_ps(const __m128bh*);
extern __m256 __cdecl _mm256_cvtneobf16_ps(const __m256bh*);
extern __m128 __cdecl _mm_cvtneoph_ps(const __m128h*);
extern __m256 __cdecl _mm256_cvtneoph_ps(const __m256h*);
extern __m128bh __cdecl _mm_cvtneps_avx_pbh(__m128);
extern __m128bh __cdecl _mm256_cvtneps_avx_pbh(__m256);

/* Intel(R) AVX-VNNI-INT8 */
extern __m128i __cdecl _mm_dpbssd_epi32(__m128i, __m128i, __m128i);
extern __m256i __cdecl _mm256_dpbssd_epi32(__m256i, __m256i, __m256i);
extern __m128i __cdecl _mm_dpbssds_epi32(__m128i, __m128i, __m128i);
extern __m256i __cdecl _mm256_dpbssds_epi32(__m256i, __m256i, __m256i);
extern __m128i __cdecl _mm_dpbsud_epi32(__m128i, __m128i, __m128i);
extern __m256i __cdecl _mm256_dpbsud_epi32(__m256i, __m256i, __m256i);
extern __m128i __cdecl _mm_dpbsuds_epi32(__m128i, __m128i, __m128i);
extern __m256i __cdecl _mm256_dpbsuds_epi32(__m256i, __m256i, __m256i);
extern __m128i __cdecl _mm_dpbuud_epi32(__m128i, __m128i, __m128i);
extern __m256i __cdecl _mm256_dpbuud_epi32(__m256i, __m256i, __m256i);
extern __m128i __cdecl _mm_dpbuuds_epi32(__m128i, __m128i, __m128i);
extern __m256i __cdecl _mm256_dpbuuds_epi32(__m256i, __m256i, __m256i);

/* RAO-INT */
extern void __cdecl _aadd_i32(int*, int);
extern void __cdecl _aand_i32(int*, int);
extern void __cdecl _aor_i32(int*, int);
extern void __cdecl _axor_i32(int*, int);
#if defined(_M_X64)
extern void __cdecl _aadd_i64(__int64*, __int64);
extern void __cdecl _aand_i64(__int64*, __int64);
extern void __cdecl _aor_i64(__int64*, __int64);
extern void __cdecl _axor_i64(__int64*, __int64);
#endif /* defined (_M_X64) */

#if defined(_M_X64)

/* Intel(R) CMPCCXADD */
typedef enum {
  _CMPCCX_O,   /* Overflow.  */
  _CMPCCX_NO,  /* No overflow.  */
  _CMPCCX_B,   /* Below.  */
  _CMPCCX_NB,  /* Not below.  */
  _CMPCCX_Z,   /* Zero.  */
  _CMPCCX_NZ,  /* Not zero.  */
  _CMPCCX_BE,  /* Below or equal.  */
  _CMPCCX_NBE, /* Neither below nor equal.  */
  _CMPCCX_S,   /* Sign.  */
  _CMPCCX_NS,  /* No sign.  */
  _CMPCCX_P,   /* Parity.  */
  _CMPCCX_NP,  /* No parity.  */
  _CMPCCX_L,   /* Less.  */
  _CMPCCX_NL,  /* Not less.  */
  _CMPCCX_LE,  /* Less or equal.  */
  _CMPCCX_NLE, /* Neither less nor equal.  */
} _CMPCCX_ENUM;
//
extern int __cdecl _cmpccxadd_epi32(void*, int, int, const int);
extern __int64 __cdecl _cmpccxadd_epi64(void*, __int64, __int64, const int);

#endif /* defined (_M_X64) */

#if defined __cplusplus
}; /* End "C" */
#endif /* defined __cplusplus */

#endif /* defined (_M_CEE_PURE) */
#endif /* __midl */
#endif /* _INCLUDED_IMM */
