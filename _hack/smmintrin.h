#pragma once
#include "tmmintrin.h"
__ywstd_export extern "C" {

extern __m128i _mm_blend_epi16(__m128i, __m128i, const int);
extern __m128i _mm_blendv_epi8(__m128i, __m128i, __m128i mask);

extern __m128  _mm_blend_ps(__m128, __m128, const int);
extern __m128  _mm_blendv_ps(__m128, __m128, __m128);

extern __m128d _mm_blend_pd(__m128d, __m128d, const int);
extern __m128d _mm_blendv_pd(__m128d, __m128d, __m128d);

extern __m128  _mm_dp_ps(__m128, __m128, const int);
extern __m128d _mm_dp_pd(__m128d, __m128d, const int);

extern __m128i _mm_cmpeq_epi64(__m128i, __m128i);

extern __m128i _mm_min_epi8(__m128i, __m128i);
extern __m128i _mm_max_epi8(__m128i, __m128i);

extern __m128i _mm_min_epu16(__m128i, __m128i);
extern __m128i _mm_max_epu16(__m128i, __m128i);

extern __m128i _mm_min_epi32(__m128i, __m128i);
extern __m128i _mm_max_epi32(__m128i, __m128i);
extern __m128i _mm_min_epu32(__m128i, __m128i);
extern __m128i _mm_max_epu32(__m128i, __m128i);

extern __m128i _mm_mullo_epi32(__m128i, __m128i);

extern __m128i _mm_mul_epi32(__m128i, __m128i);

extern int _mm_testz_si128(__m128i, __m128i);
extern int _mm_testc_si128(__m128i, __m128i);
extern int _mm_testnzc_si128(__m128i, __m128i);

extern __m128 _mm_insert_ps(__m128, __m128, const int);
extern int _mm_extract_ps(__m128, const int);

extern __m128i _mm_insert_epi8(__m128i, int, const int);
extern __m128i _mm_insert_epi32(__m128i, int, const int);
extern __m128i _mm_insert_epi64(__m128i, __int64, const int);

extern int   _mm_extract_epi8(__m128i, const int);
extern int   _mm_extract_epi32(__m128i, const int);
extern __int64 _mm_extract_epi64(__m128i, const int);

extern __m128i _mm_minpos_epu16(__m128i);

extern __m128d _mm_round_pd(__m128d, int);
extern __m128d _mm_round_sd(__m128d, __m128d, int);

extern __m128  _mm_round_ps(__m128 , int);
extern __m128  _mm_round_ss(__m128, __m128 , int);

extern __m128i _mm_cvtepi8_epi32(__m128i);
extern __m128i _mm_cvtepi16_epi32(__m128i);
extern __m128i _mm_cvtepi8_epi64(__m128i);
extern __m128i _mm_cvtepi32_epi64(__m128i);
extern __m128i _mm_cvtepi16_epi64(__m128i);
extern __m128i _mm_cvtepi8_epi16(__m128i);

extern __m128i _mm_cvtepu8_epi32(__m128i);
extern __m128i _mm_cvtepu16_epi32(__m128i);
extern __m128i _mm_cvtepu8_epi64(__m128i);
extern __m128i _mm_cvtepu32_epi64(__m128i);
extern __m128i _mm_cvtepu16_epi64(__m128i);
extern __m128i _mm_cvtepu8_epi16(__m128i);

extern __m128i _mm_packus_epi32(__m128i, __m128i);

extern __m128i _mm_mpsadbw_epu8(__m128i, __m128i, const int);

extern __m128i _mm_stream_load_si128(const __m128i*);

inline __m128d _mm_ceil_pd(__m128d a) { return _mm_round_pd(a, 0x02); }
inline __m128d _mm_ceil_sd(__m128d a, __m128d b) { return _mm_round_sd(a, b, 0x02); }

inline __m128d _mm_floor_pd(__m128d a) { return _mm_round_pd(a, 0x01); }
inline __m128d _mm_floor_sd(__m128d a, __m128d b) { return _mm_round_sd(a, b, 0x01); }

inline __m128 _mm_ceil_ps(__m128 a) { return _mm_round_ps(a, 0x02); }
inline __m128 _mm_ceil_ss(__m128 a, __m128 b) { return _mm_round_ss(a, b, 0x02); }

inline __m128 _mm_floor_ps(__m128 a) { return _mm_round_ps(a, 0x01); }
inline __m128 _mm_floor_ss(__m128 a, __m128 b) { return _mm_round_ss(a, b, 0x01); }

inline int _mm_test_all_zeros(__m128i a, __m128i b) { return _mm_testz_si128(a, b); }
inline int _mm_test_all_ones(__m128i a) { return _mm_testc_si128(a, _mm_cmpeq_epi32(a, a)); }
inline int _mm_test_mix_ones_zeros(__m128i a, __m128i b) { return _mm_testnzc_si128(a, b); }

}
