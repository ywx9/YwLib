#pragma once
#include "abc.h"
#include "xmmintrin.h"

__ywstd_export extern "C" {

union __declspec(intrin_type) alignas(16) __m128i {
  __int8           m128i_i8[16];
  __int16          m128i_i16[8];
  __int32          m128i_i32[4];
  __int64          m128i_i64[2];
  unsigned __int8  m128i_u8[16];
  unsigned __int16 m128i_u16[8];
  unsigned __int32 m128i_u32[4];
  unsigned __int64 m128i_u64[2];
};

struct __declspec(intrin_type) alignas(16) __m128d {
  double m128d_f64[2];
};

extern __m128d _mm_add_sd(__m128d, __m128d);
extern __m128d _mm_add_pd(__m128d, __m128d);
extern __m128d _mm_sub_sd(__m128d, __m128d);
extern __m128d _mm_sub_pd(__m128d, __m128d);
extern __m128d _mm_mul_sd(__m128d, __m128d);
extern __m128d _mm_mul_pd(__m128d, __m128d);
extern __m128d _mm_sqrt_sd(__m128d, __m128d);
extern __m128d _mm_sqrt_pd(__m128d);
extern __m128d _mm_div_sd(__m128d, __m128d);
extern __m128d _mm_div_pd(__m128d, __m128d);
extern __m128d _mm_min_sd(__m128d, __m128d);
extern __m128d _mm_min_pd(__m128d, __m128d);
extern __m128d _mm_max_sd(__m128d, __m128d);
extern __m128d _mm_max_pd(__m128d, __m128d);

extern __m128d _mm_and_pd(__m128d, __m128d);
extern __m128d _mm_andnot_pd(__m128d, __m128d);
extern __m128d _mm_or_pd(__m128d, __m128d);
extern __m128d _mm_xor_pd(__m128d, __m128d);

extern __m128d _mm_cmpeq_sd(__m128d, __m128d);
extern __m128d _mm_cmpeq_pd(__m128d, __m128d);
extern __m128d _mm_cmplt_sd(__m128d, __m128d);
extern __m128d _mm_cmplt_pd(__m128d, __m128d);
extern __m128d _mm_cmple_sd(__m128d, __m128d);
extern __m128d _mm_cmple_pd(__m128d, __m128d);
extern __m128d _mm_cmpgt_sd(__m128d, __m128d);
extern __m128d _mm_cmpgt_pd(__m128d, __m128d);
extern __m128d _mm_cmpge_sd(__m128d, __m128d);
extern __m128d _mm_cmpge_pd(__m128d, __m128d);
extern __m128d _mm_cmpneq_sd(__m128d, __m128d);
extern __m128d _mm_cmpneq_pd(__m128d, __m128d);
extern __m128d _mm_cmpnlt_sd(__m128d, __m128d);
extern __m128d _mm_cmpnlt_pd(__m128d, __m128d);
extern __m128d _mm_cmpnle_sd(__m128d, __m128d);
extern __m128d _mm_cmpnle_pd(__m128d, __m128d);
extern __m128d _mm_cmpngt_sd(__m128d, __m128d);
extern __m128d _mm_cmpngt_pd(__m128d, __m128d);
extern __m128d _mm_cmpnge_sd(__m128d, __m128d);
extern __m128d _mm_cmpnge_pd(__m128d, __m128d);
extern __m128d _mm_cmpord_pd(__m128d, __m128d);
extern __m128d _mm_cmpord_sd(__m128d, __m128d);
extern __m128d _mm_cmpunord_pd(__m128d, __m128d);
extern __m128d _mm_cmpunord_sd(__m128d, __m128d);
extern int _mm_comieq_sd(__m128d, __m128d);
extern int _mm_comilt_sd(__m128d, __m128d);
extern int _mm_comile_sd(__m128d, __m128d);
extern int _mm_comigt_sd(__m128d, __m128d);
extern int _mm_comige_sd(__m128d, __m128d);
extern int _mm_comineq_sd(__m128d, __m128d);
extern int _mm_ucomieq_sd(__m128d, __m128d);
extern int _mm_ucomilt_sd(__m128d, __m128d);
extern int _mm_ucomile_sd(__m128d, __m128d);
extern int _mm_ucomigt_sd(__m128d, __m128d);
extern int _mm_ucomige_sd(__m128d, __m128d);
extern int _mm_ucomineq_sd(__m128d, __m128d);

extern __m128d _mm_cvtepi32_pd(__m128i);
extern __m128i _mm_cvtpd_epi32(__m128d);
extern __m128i _mm_cvttpd_epi32(__m128d);
extern __m128 _mm_cvtepi32_ps(__m128i);
extern __m128i _mm_cvtps_epi32(__m128);
extern __m128i _mm_cvttps_epi32(__m128);
extern __m128 _mm_cvtpd_ps(__m128d);
extern __m128d _mm_cvtps_pd(__m128);
extern __m128 _mm_cvtsd_ss(__m128, __m128d);
extern __m128d _mm_cvtss_sd(__m128d, __m128);

extern int _mm_cvtsd_si32(__m128d);
extern int _mm_cvttsd_si32(__m128d);
extern __m128d _mm_cvtsi32_sd(__m128d, int);

extern __m128d _mm_unpackhi_pd(__m128d, __m128d);
extern __m128d _mm_unpacklo_pd(__m128d, __m128d);
extern int _mm_movemask_pd(__m128d);
extern __m128d _mm_shuffle_pd(__m128d, __m128d, int);

extern __m128d _mm_load_pd(const double*);
extern __m128d _mm_load1_pd(const double*);
extern __m128d _mm_loadr_pd(const double*);
extern __m128d _mm_loadu_pd(const double*);
extern __m128d _mm_load_sd(const double*);
extern __m128d _mm_loadh_pd(__m128d, const double*);
extern __m128d _mm_loadl_pd(__m128d, const double*);

extern __m128d _mm_set_sd(double);
extern __m128d _mm_set1_pd(double);
extern __m128d _mm_set_pd(double, double);
extern __m128d _mm_setr_pd(double, double);
extern __m128d _mm_setzero_pd();
extern __m128d _mm_move_sd(__m128d, __m128d);

extern void _mm_store_sd(double*, __m128d);
extern void _mm_store1_pd(double*, __m128d);
extern void _mm_store_pd(double*, __m128d);
extern void _mm_storeu_pd(double*, __m128d);
extern void _mm_storer_pd(double*, __m128d);
extern void _mm_storeh_pd(double*, __m128d);
extern void _mm_storel_pd(double*, __m128d);

inline __m128d _mm_set_pd1(double a) { return _mm_set1_pd(a); }
inline __m128d _mm_load_pd1(const double* p) { return _mm_load1_pd(p); }
inline void _mm_store_pd1(double* p, __m128d a) { _mm_store1_pd(p, a); }

extern __m128i _mm_add_epi8(__m128i, __m128i);
extern __m128i _mm_add_epi16(__m128i, __m128i);
extern __m128i _mm_add_epi32(__m128i, __m128i);
extern __m128i _mm_add_epi64(__m128i, __m128i);
extern __m128i _mm_adds_epi8(__m128i, __m128i);
extern __m128i _mm_adds_epi16(__m128i, __m128i);
extern __m128i _mm_adds_epu8(__m128i, __m128i);
extern __m128i _mm_adds_epu16(__m128i, __m128i);
extern __m128i _mm_avg_epu8(__m128i, __m128i);
extern __m128i _mm_avg_epu16(__m128i, __m128i);
extern __m128i _mm_madd_epi16(__m128i, __m128i);
extern __m128i _mm_max_epi16(__m128i, __m128i);
extern __m128i _mm_max_epu8(__m128i, __m128i);
extern __m128i _mm_min_epi16(__m128i, __m128i);
extern __m128i _mm_min_epu8(__m128i, __m128i);
extern __m128i _mm_mulhi_epi16(__m128i, __m128i);
extern __m128i _mm_mulhi_epu16(__m128i, __m128i);
extern __m128i _mm_mullo_epi16(__m128i, __m128i);
extern __m128i _mm_mul_epu32(__m128i, __m128i);
extern __m128i _mm_sad_epu8(__m128i, __m128i);
extern __m128i _mm_sub_epi8(__m128i, __m128i);
extern __m128i _mm_sub_epi16(__m128i, __m128i);
extern __m128i _mm_sub_epi32(__m128i, __m128i);
extern __m128i _mm_sub_epi64(__m128i, __m128i);
extern __m128i _mm_subs_epi8(__m128i, __m128i);
extern __m128i _mm_subs_epi16(__m128i, __m128i);
extern __m128i _mm_subs_epu8(__m128i, __m128i);
extern __m128i _mm_subs_epu16(__m128i, __m128i);

extern __m128i _mm_and_si128(__m128i, __m128i);
extern __m128i _mm_andnot_si128(__m128i, __m128i);
extern __m128i _mm_or_si128(__m128i, __m128i);
extern __m128i _mm_xor_si128(__m128i, __m128i);

extern __m128i _mm_slli_si128(__m128i, int);
extern __m128i _mm_slli_epi16(__m128i, int);
extern __m128i _mm_sll_epi16(__m128i, __m128i);
extern __m128i _mm_slli_epi32(__m128i, int);
extern __m128i _mm_sll_epi32(__m128i, __m128i);
extern __m128i _mm_slli_epi64(__m128i, int);
extern __m128i _mm_sll_epi64(__m128i, __m128i);
extern __m128i _mm_srai_epi16(__m128i, int);
extern __m128i _mm_sra_epi16(__m128i, __m128i);
extern __m128i _mm_srai_epi32(__m128i, int);
extern __m128i _mm_sra_epi32(__m128i, __m128i);
extern __m128i _mm_srli_si128(__m128i, int);
extern __m128i _mm_srli_epi16(__m128i, int);
extern __m128i _mm_srl_epi16(__m128i, __m128i);
extern __m128i _mm_srli_epi32(__m128i, int);
extern __m128i _mm_srl_epi32(__m128i, __m128i);
extern __m128i _mm_srli_epi64(__m128i, int);
extern __m128i _mm_srl_epi64(__m128i, __m128i);

extern __m128i _mm_cmpeq_epi8(__m128i, __m128i);
extern __m128i _mm_cmpeq_epi16(__m128i, __m128i);
extern __m128i _mm_cmpeq_epi32(__m128i, __m128i);
extern __m128i _mm_cmpgt_epi8(__m128i, __m128i);
extern __m128i _mm_cmpgt_epi16(__m128i, __m128i);
extern __m128i _mm_cmpgt_epi32(__m128i, __m128i);
extern __m128i _mm_cmplt_epi8(__m128i, __m128i);
extern __m128i _mm_cmplt_epi16(__m128i, __m128i);
extern __m128i _mm_cmplt_epi32(__m128i, __m128i);

extern __m128i _mm_cvtsi32_si128(int);
extern int _mm_cvtsi128_si32(__m128i);

extern __m128i _mm_packs_epi16(__m128i, __m128i);
extern __m128i _mm_packs_epi32(__m128i, __m128i);
extern __m128i _mm_packus_epi16(__m128i, __m128i);
extern int _mm_extract_epi16(__m128i, int);
extern __m128i _mm_insert_epi16(__m128i, int, int);
extern int _mm_movemask_epi8(__m128i);
extern __m128i _mm_shuffle_epi32(__m128i, int);
extern __m128i _mm_shufflehi_epi16(__m128i, int);
extern __m128i _mm_shufflelo_epi16(__m128i, int);
extern __m128i _mm_unpackhi_epi8(__m128i, __m128i);
extern __m128i _mm_unpackhi_epi16(__m128i, __m128i);
extern __m128i _mm_unpackhi_epi32(__m128i, __m128i);
extern __m128i _mm_unpackhi_epi64(__m128i, __m128i);
extern __m128i _mm_unpacklo_epi8(__m128i, __m128i);
extern __m128i _mm_unpacklo_epi16(__m128i, __m128i);
extern __m128i _mm_unpacklo_epi32(__m128i, __m128i);
extern __m128i _mm_unpacklo_epi64(__m128i, __m128i);

extern __m128i _mm_load_si128(const __m128i*);
extern __m128i _mm_loadu_si128(const __m128i*);
extern __m128i _mm_loadl_epi64(const __m128i*);

extern __m128i _mm_set_epi64x(__int64, __int64);
extern __m128i _mm_set_epi32(int, int, int, int);
extern __m128i _mm_set_epi16(short, short, short, short, short, short, short, short);
extern __m128i _mm_set_epi8(char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char);
extern __m128i _mm_set1_epi64x(__int64);
extern __m128i _mm_set1_epi32(int);
extern __m128i _mm_set1_epi16(short);
extern __m128i _mm_set1_epi8(char);
extern __m128i _mm_setl_epi64(__m128i);
extern __m128i _mm_setr_epi32(int, int, int, int);
extern __m128i _mm_setr_epi16(short, short, short, short, short, short, short, short);
extern __m128i _mm_setr_epi8(char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char);
extern __m128i _mm_setzero_si128();

extern void _mm_store_si128(__m128i*, __m128i);
extern void _mm_storeu_si128(__m128i*, __m128i);
extern void _mm_storel_epi64(__m128i*, __m128i);
extern void _mm_maskmoveu_si128(__m128i, __m128i, char*);

extern __m128i _mm_move_epi64(__m128i);

extern void _mm_stream_pd(double*, __m128d);
extern void _mm_stream_si128(__m128i*, __m128i);
extern void _mm_clflush(const void*);
extern void _mm_lfence();
extern void _mm_mfence();
extern void _mm_stream_si32(int*, int);
extern void _mm_pause();

extern double _mm_cvtsd_f64(__m128d);

extern __m128  _mm_castpd_ps(__m128d);
extern __m128i _mm_castpd_si128(__m128d);
extern __m128d _mm_castps_pd(__m128);
extern __m128i _mm_castps_si128(__m128);
extern __m128  _mm_castsi128_ps(__m128i);
extern __m128d _mm_castsi128_pd(__m128i);

extern __int64 _mm_cvtsd_si64(__m128d);
extern __int64 _mm_cvttsd_si64(__m128d);
extern __m128d _mm_cvtsi64_sd(__m128d, __int64);
extern __m128i _mm_cvtsi64_si128(__int64);
extern __int64 _mm_cvtsi128_si64(__m128i);

}
