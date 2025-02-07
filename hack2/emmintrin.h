#pragma once
#include "abc.h"
#include "xmmintrin.h"

union __declspec(intrin_type) alignas(16) __m128i {
  signed char m128i_i8[16];
  short m128i_i16[8];
  int m128i_i32[4];
  long long m128i_i64[2];
  unsigned char m128i_u8[16];
  unsigned short m128i_u16[8];
  unsigned m128i_u32[4];
  unsigned long long m128i_u64[2];
};

struct __declspec(intrin_type) alignas(16) __m128d {
  double m128d_f64[2];
};

extern "C" {

export __m128d _mm_add_sd(__m128d, __m128d);
export __m128d _mm_add_pd(__m128d, __m128d);
export __m128d _mm_sub_sd(__m128d, __m128d);
export __m128d _mm_sub_pd(__m128d, __m128d);
export __m128d _mm_mul_sd(__m128d, __m128d);
export __m128d _mm_mul_pd(__m128d, __m128d);
export __m128d _mm_sqrt_sd(__m128d, __m128d);
export __m128d _mm_sqrt_pd(__m128d);
export __m128d _mm_div_sd(__m128d, __m128d);
export __m128d _mm_div_pd(__m128d, __m128d);
export __m128d _mm_min_sd(__m128d, __m128d);
export __m128d _mm_min_pd(__m128d, __m128d);
export __m128d _mm_max_sd(__m128d, __m128d);
export __m128d _mm_max_pd(__m128d, __m128d);

export __m128d _mm_and_pd(__m128d, __m128d);
export __m128d _mm_andnot_pd(__m128d, __m128d);
export __m128d _mm_or_pd(__m128d, __m128d);
export __m128d _mm_xor_pd(__m128d, __m128d);

export __m128d _mm_cmpeq_sd(__m128d, __m128d);
export __m128d _mm_cmpeq_pd(__m128d, __m128d);
export __m128d _mm_cmplt_sd(__m128d, __m128d);
export __m128d _mm_cmplt_pd(__m128d, __m128d);
export __m128d _mm_cmple_sd(__m128d, __m128d);
export __m128d _mm_cmple_pd(__m128d, __m128d);
export __m128d _mm_cmpgt_sd(__m128d, __m128d);
export __m128d _mm_cmpgt_pd(__m128d, __m128d);
export __m128d _mm_cmpge_sd(__m128d, __m128d);
export __m128d _mm_cmpge_pd(__m128d, __m128d);
export __m128d _mm_cmpneq_sd(__m128d, __m128d);
export __m128d _mm_cmpneq_pd(__m128d, __m128d);
export __m128d _mm_cmpnlt_sd(__m128d, __m128d);
export __m128d _mm_cmpnlt_pd(__m128d, __m128d);
export __m128d _mm_cmpnle_sd(__m128d, __m128d);
export __m128d _mm_cmpnle_pd(__m128d, __m128d);
export __m128d _mm_cmpngt_sd(__m128d, __m128d);
export __m128d _mm_cmpngt_pd(__m128d, __m128d);
export __m128d _mm_cmpnge_sd(__m128d, __m128d);
export __m128d _mm_cmpnge_pd(__m128d, __m128d);
export __m128d _mm_cmpord_pd(__m128d, __m128d);
export __m128d _mm_cmpord_sd(__m128d, __m128d);
export __m128d _mm_cmpunord_pd(__m128d, __m128d);
export __m128d _mm_cmpunord_sd(__m128d, __m128d);
export int _mm_comieq_sd(__m128d, __m128d);
export int _mm_comilt_sd(__m128d, __m128d);
export int _mm_comile_sd(__m128d, __m128d);
export int _mm_comigt_sd(__m128d, __m128d);
export int _mm_comige_sd(__m128d, __m128d);
export int _mm_comineq_sd(__m128d, __m128d);
export int _mm_ucomieq_sd(__m128d, __m128d);
export int _mm_ucomilt_sd(__m128d, __m128d);
export int _mm_ucomile_sd(__m128d, __m128d);
export int _mm_ucomigt_sd(__m128d, __m128d);
export int _mm_ucomige_sd(__m128d, __m128d);
export int _mm_ucomineq_sd(__m128d, __m128d);

export __m128d _mm_cvtepi32_pd(__m128i);
export __m128i _mm_cvtpd_epi32(__m128d);
export __m128i _mm_cvttpd_epi32(__m128d);
export __m128 _mm_cvtepi32_ps(__m128i);
export __m128i _mm_cvtps_epi32(__m128);
export __m128i _mm_cvttps_epi32(__m128);
export __m128 _mm_cvtpd_ps(__m128d);
export __m128d _mm_cvtps_pd(__m128);
export __m128 _mm_cvtsd_ss(__m128, __m128d);
export __m128d _mm_cvtss_sd(__m128d, __m128);

export int _mm_cvtsd_si32(__m128d);
export int _mm_cvttsd_si32(__m128d);
export __m128d _mm_cvtsi32_sd(__m128d, int);

export __m128d _mm_unpackhi_pd(__m128d, __m128d);
export __m128d _mm_unpacklo_pd(__m128d, __m128d);
export int _mm_movemask_pd(__m128d);
export __m128d _mm_shuffle_pd(__m128d, __m128d, int);

export __m128d _mm_load_pd(const double*);
export __m128d _mm_load1_pd(const double*);
export __m128d _mm_loadr_pd(const double*);
export __m128d _mm_loadu_pd(const double*);
export __m128d _mm_load_sd(const double*);
export __m128d _mm_loadh_pd(__m128d, const double*);
export __m128d _mm_loadl_pd(__m128d, const double*);

export __m128d _mm_set_sd(double);
export __m128d _mm_set1_pd(double);
export __m128d _mm_set_pd(double, double);
export __m128d _mm_setr_pd(double, double);
export __m128d _mm_setzero_pd();
export __m128d _mm_move_sd(__m128d, __m128d);

export void _mm_store_sd(double*, __m128d);
export void _mm_store1_pd(double*, __m128d);
export void _mm_store_pd(double*, __m128d);
export void _mm_storeu_pd(double*, __m128d);
export void _mm_storer_pd(double*, __m128d);
export void _mm_storeh_pd(double*, __m128d);
export void _mm_storel_pd(double*, __m128d);

#define _mm_set_pd1(a) _mm_set1_pd(a)
#define _mm_load_pd1(p) _mm_load1_pd(p)
#define _mm_store_pd1(p, a) _mm_store1_pd((p), (a))

export __m128i _mm_add_epi8(__m128i, __m128i);
export __m128i _mm_add_epi16(__m128i, __m128i);
export __m128i _mm_add_epi32(__m128i, __m128i);
export __m128i _mm_add_epi64(__m128i, __m128i);
export __m128i _mm_adds_epi8(__m128i, __m128i);
export __m128i _mm_adds_epi16(__m128i, __m128i);
export __m128i _mm_adds_epu8(__m128i, __m128i);
export __m128i _mm_adds_epu16(__m128i, __m128i);
export __m128i _mm_avg_epu8(__m128i, __m128i);
export __m128i _mm_avg_epu16(__m128i, __m128i);
export __m128i _mm_madd_epi16(__m128i, __m128i);
export __m128i _mm_max_epi16(__m128i, __m128i);
export __m128i _mm_max_epu8(__m128i, __m128i);
export __m128i _mm_min_epi16(__m128i, __m128i);
export __m128i _mm_min_epu8(__m128i, __m128i);
export __m128i _mm_mulhi_epi16(__m128i, __m128i);
export __m128i _mm_mulhi_epu16(__m128i, __m128i);
export __m128i _mm_mullo_epi16(__m128i, __m128i);
export __m128i _mm_mul_epu32(__m128i, __m128i);
export __m128i _mm_sad_epu8(__m128i, __m128i);
export __m128i _mm_sub_epi8(__m128i, __m128i);
export __m128i _mm_sub_epi16(__m128i, __m128i);
export __m128i _mm_sub_epi32(__m128i, __m128i);
export __m128i _mm_sub_epi64(__m128i, __m128i);
export __m128i _mm_subs_epi8(__m128i, __m128i);
export __m128i _mm_subs_epi16(__m128i, __m128i);
export __m128i _mm_subs_epu8(__m128i, __m128i);
export __m128i _mm_subs_epu16(__m128i, __m128i);

export __m128i _mm_and_si128(__m128i, __m128i);
export __m128i _mm_andnot_si128(__m128i, __m128i);
export __m128i _mm_or_si128(__m128i, __m128i);
export __m128i _mm_xor_si128(__m128i, __m128i);

export __m128i _mm_slli_si128(__m128i, int);
#define _mm_bslli_si128 _mm_slli_si128
export __m128i _mm_slli_epi16(__m128i, int);
export __m128i _mm_sll_epi16(__m128i, __m128i);
export __m128i _mm_slli_epi32(__m128i, int);
export __m128i _mm_sll_epi32(__m128i, __m128i);
export __m128i _mm_slli_epi64(__m128i, int);
export __m128i _mm_sll_epi64(__m128i, __m128i);
export __m128i _mm_srai_epi16(__m128i, int);
export __m128i _mm_sra_epi16(__m128i, __m128i);
export __m128i _mm_srai_epi32(__m128i, int);
export __m128i _mm_sra_epi32(__m128i, __m128i);
export __m128i _mm_srli_si128(__m128i, int);
#define _mm_bsrli_si128 _mm_srli_si128
export __m128i _mm_srli_epi16(__m128i, int);
export __m128i _mm_srl_epi16(__m128i, __m128i);
export __m128i _mm_srli_epi32(__m128i, int);
export __m128i _mm_srl_epi32(__m128i, __m128i);
export __m128i _mm_srli_epi64(__m128i, int);
export __m128i _mm_srl_epi64(__m128i, __m128i);

export __m128i _mm_cmpeq_epi8(__m128i, __m128i);
export __m128i _mm_cmpeq_epi16(__m128i, __m128i);
export __m128i _mm_cmpeq_epi32(__m128i, __m128i);
export __m128i _mm_cmpgt_epi8(__m128i, __m128i);
export __m128i _mm_cmpgt_epi16(__m128i, __m128i);
export __m128i _mm_cmpgt_epi32(__m128i, __m128i);
export __m128i _mm_cmplt_epi8(__m128i, __m128i);
export __m128i _mm_cmplt_epi16(__m128i, __m128i);
export __m128i _mm_cmplt_epi32(__m128i, __m128i);

export __m128i _mm_cvtsi32_si128(int);
export int _mm_cvtsi128_si32(__m128i);

export __m128i _mm_packs_epi16(__m128i, __m128i);
export __m128i _mm_packs_epi32(__m128i, __m128i);
export __m128i _mm_packus_epi16(__m128i, __m128i);
export int _mm_extract_epi16(__m128i, int);
export __m128i _mm_insert_epi16(__m128i, int, int);
export int _mm_movemask_epi8(__m128i);
export __m128i _mm_shuffle_epi32(__m128i, int);
export __m128i _mm_shufflehi_epi16(__m128i, int);
export __m128i _mm_shufflelo_epi16(__m128i, int);
export __m128i _mm_unpackhi_epi8(__m128i, __m128i);
export __m128i _mm_unpackhi_epi16(__m128i, __m128i);
export __m128i _mm_unpackhi_epi32(__m128i, __m128i);
export __m128i _mm_unpackhi_epi64(__m128i, __m128i);
export __m128i _mm_unpacklo_epi8(__m128i, __m128i);
export __m128i _mm_unpacklo_epi16(__m128i, __m128i);
export __m128i _mm_unpacklo_epi32(__m128i, __m128i);
export __m128i _mm_unpacklo_epi64(__m128i, __m128i);

export __m128i _mm_load_si128(const __m128i*);
export __m128i _mm_loadu_si128(const __m128i*);
export __m128i _mm_loadl_epi64(const __m128i*);

export __m128i _mm_set_epi64x(__int64, __int64);
export __m128i _mm_set_epi32(int, int, int, int);
export __m128i _mm_set_epi16(short, short, short, short, short, short, short, short);
export __m128i _mm_set_epi8(char, char, char, char, char, char, char, char, char, char, char, char, char, char, char,
                            char);
export __m128i _mm_set1_epi64x(__int64);
export __m128i _mm_set1_epi32(int);
export __m128i _mm_set1_epi16(short);
export __m128i _mm_set1_epi8(char);
export __m128i _mm_setl_epi64(__m128i);
export __m128i _mm_setr_epi32(int, int, int, int);
export __m128i _mm_setr_epi16(short, short, short, short, short, short, short, short);
export __m128i _mm_setr_epi8(char, char, char, char, char, char, char, char, char, char, char, char, char, char, char,
                             char);
export __m128i _mm_setzero_si128();

export void _mm_store_si128(__m128i*, __m128i);
export void _mm_storeu_si128(__m128i*, __m128i);
export void _mm_storel_epi64(__m128i*, __m128i);
export void _mm_maskmoveu_si128(__m128i, __m128i, char*);

export __m128i _mm_move_epi64(__m128i _Q);

export void _mm_stream_pd(double*, __m128d);
export void _mm_stream_si128(__m128i*, __m128i);
export void _mm_clflush(void const*);
export void _mm_lfence();
export void _mm_mfence();
export void _mm_stream_si32(int*, int _I);
export void _mm_pause();

export double _mm_cvtsd_f64(__m128d);

export __m128 _mm_castpd_ps(__m128d);
export __m128i _mm_castpd_si128(__m128d);
export __m128d _mm_castps_pd(__m128);
export __m128i _mm_castps_si128(__m128);
export __m128 _mm_castsi128_ps(__m128i);
export __m128d _mm_castsi128_pd(__m128i);

export __int64 _mm_cvtsd_si64(__m128d);
export __int64 _mm_cvttsd_si64(__m128d);
export __m128d _mm_cvtsi64_sd(__m128d, __int64);
export __m128i _mm_cvtsi64_si128(__int64);
export __int64 _mm_cvtsi128_si64(__m128i);
#define _mm_stream_si64 _mm_stream_si64x
}
