/// \file immintrin.h
/// \brief This header contains intrinsics for Intel SIMD instructions.

#pragma once

extern "C" {

#pragma region TYPES

union __declspec(intrin_type) alignas(8) __m64 {
  unsigned __int64 m64_u64;
  float m64_f32[2];
  __int8 m64_i8[8];
  __int16 m64_i16[4];
  __int32 m64_i32[2];
  __int64 m64_i64;
  unsigned __int8 m64_u8[8];
  unsigned __int16 m64_u16[4];
  unsigned __int32 m64_u32[2];
};

union __declspec(intrin_type) alignas(16) __m128 {
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

union __declspec(intrin_type) alignas(16) __m128i {
  __int8 m128i_i8[16];
  __int16 m128i_i16[8];
  __int32 m128i_i32[4];
  __int64 m128i_i64[2];
  unsigned __int8 m128i_u8[16];
  unsigned __int16 m128i_u16[8];
  unsigned __int32 m128i_u32[4];
  unsigned __int64 m128i_u64[2];
};

struct __declspec(intrin_type) alignas(16) __m128d {
  double m128d_f64[2];
};

union __declspec(intrin_type) alignas(32) __m256 {
  float m256_f32[8];
};

struct __declspec(intrin_type) alignas(32) __m256d {
  double m256d_f64[4];
};

union __declspec(intrin_type) alignas(32) __m256i {
  __int8 m256i_i8[32];
  __int16 m256i_i16[16];
  __int32 m256i_i32[8];
  __int64 m256i_i64[4];
  unsigned __int8 m256i_u8[32];
  unsigned __int16 m256i_u16[16];
  unsigned __int32 m256i_u32[8];
  unsigned __int64 m256i_u64[4];
};

#pragma endregion

void _aligned_free(void*);
inline void _mm_free(void* p) { _aligned_free(p); }
__declspec(allocator) __declspec(restrict) void* _aligned_malloc(size_t, size_t);
inline __declspec(allocator) __declspec(restrict) void* _mm_malloc(size_t s, size_t a) { return _aligned_malloc(s, a); }

#pragma region ALIGNR

extern __m128i _mm_alignr_epi8(__m128i, __m128i, int);
extern __m256i _mm256_alignr_epi8(__m256i, __m256i, const int);

#pragma endregion

#pragma region ARITHMETIC

extern __m128i _mm_abs_epi8(__m128i);
extern __m128i _mm_abs_epi16(__m128i);
extern __m128i _mm_abs_epi32(__m128i);
extern __m256i _mm256_abs_epi8(__m256i);
extern __m256i _mm256_abs_epi16(__m256i);
extern __m256i _mm256_abs_epi32(__m256i);

extern __m128 _mm_add_ss(__m128, __m128);
extern __m128 _mm_add_ps(__m128, __m128);
extern __m128d _mm_add_sd(__m128d, __m128d);
extern __m128d _mm_add_pd(__m128d, __m128d);
extern __m128i _mm_add_epi8(__m128i, __m128i);
extern __m128i _mm_add_epi16(__m128i, __m128i);
extern __m128i _mm_add_epi32(__m128i, __m128i);
extern __m128i _mm_add_epi64(__m128i, __m128i);
extern __m256 _mm256_add_ps(__m256, __m256);
extern __m256d _mm256_add_pd(__m256d, __m256d);
extern __m256i _mm256_add_epi8(__m256i, __m256i);
extern __m256i _mm256_add_epi16(__m256i, __m256i);
extern __m256i _mm256_add_epi32(__m256i, __m256i);
extern __m256i _mm256_add_epi64(__m256i, __m256i);

extern __m128i _mm_adds_epi8(__m128i, __m128i);
extern __m128i _mm_adds_epi16(__m128i, __m128i);
extern __m128i _mm_adds_epu8(__m128i, __m128i);
extern __m128i _mm_adds_epu16(__m128i, __m128i);
extern __m256i _mm256_adds_epi8(__m256i, __m256i);
extern __m256i _mm256_adds_epi16(__m256i, __m256i);
extern __m256i _mm256_adds_epu8(__m256i, __m256i);
extern __m256i _mm256_adds_epu16(__m256i, __m256i);

extern __m128 _mm_addsub_ps(__m128, __m128);
extern __m128d _mm_addsub_pd(__m128d, __m128d);
extern __m256 _mm256_addsub_ps(__m256, __m256);
extern __m256d _mm256_addsub_pd(__m256d, __m256d);

extern __m128i _mm_avg_epu8(__m128i _A, __m128i _B);
extern __m128i _mm_avg_epu16(__m128i _A, __m128i _B);
extern __m256i _mm256_avg_epu8(__m256i, __m256i);
extern __m256i _mm256_avg_epu16(__m256i, __m256i);

extern __m128 _mm_div_ss(__m128, __m128);
extern __m128 _mm_div_ps(__m128, __m128);
extern __m128d _mm_div_sd(__m128d, __m128d);
extern __m128d _mm_div_pd(__m128d, __m128d);
extern __m128i _mm_div_epi8(__m128i, __m128i);
extern __m128i _mm_div_epi16(__m128i, __m128i);
extern __m128i _mm_div_epi32(__m128i, __m128i);
extern __m128i _mm_div_epi64(__m128i, __m128i);
extern __m128i _mm_div_epu8(__m128i, __m128i);
extern __m128i _mm_div_epu16(__m128i, __m128i);
extern __m128i _mm_div_epu32(__m128i, __m128i);
extern __m128i _mm_div_epu64(__m128i, __m128i);
extern __m256 _mm256_div_ps(__m256, __m256);
extern __m256d _mm256_div_pd(__m256d, __m256d);
extern __m256i _mm256_div_epi8(__m256i, __m256i);
extern __m256i _mm256_div_epi16(__m256i, __m256i);
extern __m256i _mm256_div_epi32(__m256i, __m256i);
extern __m256i _mm256_div_epi64(__m256i, __m256i);
extern __m256i _mm256_div_epu8(__m256i, __m256i);
extern __m256i _mm256_div_epu16(__m256i, __m256i);
extern __m256i _mm256_div_epu32(__m256i, __m256i);
extern __m256i _mm256_div_epu64(__m256i, __m256i);

extern __m128i _mm_divrem_epi32(__m128i*, __m128i, __m128i);
extern __m128i _mm_divrem_epu32(__m128i*, __m128i, __m128i);
extern __m256i _mm256_divrem_epi32(__m256i*, __m256i, __m256i);
extern __m256i _mm256_divrem_epu32(__m256i*, __m256i, __m256i);

extern __m128 _mm_dp_ps(__m128, __m128, const int);
extern __m128d _mm_dp_pd(__m128d, __m128d, const int);
extern __m256 _mm256_dp_ps(__m256, __m256, const int);

extern __m128 _mm_fmadd_ss(__m128, __m128, __m128);
extern __m128 _mm_fmadd_ps(__m128, __m128, __m128);
extern __m128d _mm_fmadd_sd(__m128d, __m128d, __m128d);
extern __m128d _mm_fmadd_pd(__m128d, __m128d, __m128d);
extern __m256 _mm256_fmadd_ps(__m256, __m256, __m256);
extern __m256d _mm256_fmadd_pd(__m256d, __m256d, __m256d);

extern __m128 _mm_fmaddsub_ps(__m128, __m128, __m128);
extern __m128d _mm_fmaddsub_pd(__m128d, __m128d, __m128d);
extern __m256 _mm256_fmaddsub_ps(__m256, __m256, __m256);
extern __m256d _mm256_fmaddsub_pd(__m256d, __m256d, __m256d);

extern __m128 _mm_fmsub_ss(__m128, __m128, __m128);
extern __m128 _mm_fmsub_ps(__m128, __m128, __m128);
extern __m128d _mm_fmsub_sd(__m128d, __m128d, __m128d);
extern __m128d _mm_fmsub_pd(__m128d, __m128d, __m128d);
extern __m256 _mm256_fmsub_ps(__m256, __m256, __m256);
extern __m256d _mm256_fmsub_pd(__m256d, __m256d, __m256d);

extern __m128 _mm_fmsubadd_ps(__m128, __m128, __m128);
extern __m128d _mm_fmsubadd_pd(__m128d, __m128d, __m128d);
extern __m256 _mm256_fmsubadd_ps(__m256, __m256, __m256);
extern __m256d _mm256_fmsubadd_pd(__m256d, __m256d, __m256d);

extern __m128 _mm_fnmadd_ss(__m128, __m128, __m128);
extern __m128 _mm_fnmadd_ps(__m128, __m128, __m128);
extern __m128d _mm_fnmadd_sd(__m128d, __m128d, __m128d);
extern __m128d _mm_fnmadd_pd(__m128d, __m128d, __m128d);
extern __m256 _mm256_fnmadd_ps(__m256, __m256, __m256);
extern __m256d _mm256_fnmadd_pd(__m256d, __m256d, __m256d);

extern __m128 _mm_fnmsub_ss(__m128, __m128, __m128);
extern __m128 _mm_fnmsub_ps(__m128, __m128, __m128);
extern __m128d _mm_fnmsub_sd(__m128d, __m128d, __m128d);
extern __m128d _mm_fnmsub_pd(__m128d, __m128d, __m128d);
extern __m256 _mm256_fnmsub_ps(__m256, __m256, __m256);
extern __m256d _mm256_fnmsub_pd(__m256d, __m256d, __m256d);

extern __m128 _mm_hadd_ps(__m128, __m128);
extern __m128d _mm_hadd_pd(__m128d, __m128d);
extern __m128i _mm_hadd_epi16(__m128i, __m128i);
extern __m128i _mm_hadd_epi32(__m128i, __m128i);
extern __m256 _mm256_hadd_ps(__m256, __m256);
extern __m256d _mm256_hadd_pd(__m256d, __m256d);
extern __m256i _mm256_hadd_epi16(__m256i, __m256i);
extern __m256i _mm256_hadd_epi32(__m256i, __m256i);

extern __m128i _mm_hadds_epi16(__m128i, __m128i);
extern __m256i _mm256_hadds_epi16(__m256i, __m256i);

extern __m128 _mm_hsub_ps(__m128, __m128);
extern __m128d _mm_hsub_pd(__m128d, __m128d);
extern __m128i _mm_hsub_epi16(__m128i, __m128i);
extern __m128i _mm_hsub_epi32(__m128i, __m128i);
extern __m256 _mm256_hsub_ps(__m256, __m256);
extern __m256d _mm256_hsub_pd(__m256d, __m256d);
extern __m256i _mm256_hsub_epi16(__m256i, __m256i);
extern __m256i _mm256_hsub_epi32(__m256i, __m256i);

extern __m128i _mm_hsubs_epi16(__m128i, __m128i);
extern __m256i _mm256_hsubs_epi16(__m256i, __m256i);

extern __m128i _mm_madd_epi16(__m128i, __m128i);
extern __m256i _mm256_madd_epi16(__m256i, __m256i);

extern __m128i _mm_maddubs_epi16(__m128i, __m128i);
extern __m256i _mm256_maddubs_epi16(__m256i, __m256i);

extern __m128 _mm_max_ss(__m128, __m128);
extern __m128 _mm_max_ps(__m128, __m128);
extern __m128d _mm_max_sd(__m128d, __m128d);
extern __m128d _mm_max_pd(__m128d, __m128d);
extern __m128i _mm_max_epi8(__m128i, __m128i);
extern __m128i _mm_max_epi16(__m128i, __m128i);
extern __m128i _mm_max_epi32(__m128i, __m128i);
extern __m128i _mm_max_epu8(__m128i, __m128i);
extern __m128i _mm_max_epu16(__m128i, __m128i);
extern __m128i _mm_max_epu32(__m128i, __m128i);
extern __m256 _mm256_max_ps(__m256, __m256);
extern __m256d _mm256_max_pd(__m256d, __m256d);
extern __m256i _mm256_max_epi8(__m256i, __m256i);
extern __m256i _mm256_max_epi16(__m256i, __m256i);
extern __m256i _mm256_max_epi32(__m256i, __m256i);
extern __m256i _mm256_max_epu8(__m256i, __m256i);
extern __m256i _mm256_max_epu16(__m256i, __m256i);
extern __m256i _mm256_max_epu32(__m256i, __m256i);

extern __m128 _mm_min_ss(__m128, __m128);
extern __m128 _mm_min_ps(__m128, __m128);
extern __m128d _mm_min_sd(__m128d, __m128d);
extern __m128d _mm_min_pd(__m128d, __m128d);
extern __m128i _mm_min_epi8(__m128i, __m128i);
extern __m128i _mm_min_epi16(__m128i, __m128i);
extern __m128i _mm_min_epi32(__m128i, __m128i);
extern __m128i _mm_min_epu8(__m128i, __m128i);
extern __m128i _mm_min_epu16(__m128i, __m128i);
extern __m128i _mm_min_epu32(__m128i, __m128i);
extern __m256 _mm256_min_ps(__m256, __m256);
extern __m256d _mm256_min_pd(__m256d, __m256d);
extern __m256i _mm256_min_epi8(__m256i, __m256i);
extern __m256i _mm256_min_epi16(__m256i, __m256i);
extern __m256i _mm256_min_epi32(__m256i, __m256i);
extern __m256i _mm256_min_epu8(__m256i, __m256i);
extern __m256i _mm256_min_epu16(__m256i, __m256i);
extern __m256i _mm256_min_epu32(__m256i, __m256i);

extern __m128i _mm_mpsadbw_epu8(__m128i, __m128i, const int);
extern __m256i _mm256_mpsadbw_epu8(__m256i, __m256i, const int);

extern __m128 _mm_mul_ss(__m128, __m128);
extern __m128 _mm_mul_ps(__m128, __m128);
extern __m128d _mm_mul_sd(__m128d, __m128d);
extern __m128d _mm_mul_pd(__m128d, __m128d);
extern __m128i _mm_mul_epu32(__m128i, __m128i);
extern __m128i _mm_mul_epi32(__m128i, __m128i);
extern __m256 _mm256_mul_ps(__m256, __m256);
extern __m256d _mm256_mul_pd(__m256d, __m256d);
extern __m256i _mm256_mul_epu32(__m256i, __m256i);
extern __m256i _mm256_mul_epi32(__m256i, __m256i);

extern __m128i _mm_mulhi_epi16(__m128i, __m128i);
extern __m128i _mm_mulhi_epu16(__m128i, __m128i);
extern __m256i _mm256_mulhi_epi16(__m256i, __m256i);
extern __m256i _mm256_mulhi_epu16(__m256i, __m256i);

extern __m128i _mm_mulhrs_epi16(__m128i, __m128i);
extern __m256i _mm256_mulhrs_epi16(__m256i, __m256i);

extern __m128i _mm_mullo_epi16(__m128i, __m128i);
extern __m128i _mm_mullo_epi32(__m128i, __m128i);
extern __m256i _mm256_mullo_epi16(__m256i, __m256i);
extern __m256i _mm256_mullo_epi32(__m256i, __m256i);

extern __m128i _mm_rem_epi8(__m128i, __m128i);
extern __m128i _mm_rem_epi16(__m128i, __m128i);
extern __m128i _mm_rem_epi32(__m128i, __m128i);
extern __m128i _mm_rem_epi64(__m128i, __m128i);
extern __m128i _mm_rem_epu8(__m128i, __m128i);
extern __m128i _mm_rem_epu16(__m128i, __m128i);
extern __m128i _mm_rem_epu32(__m128i, __m128i);
extern __m128i _mm_rem_epu64(__m128i, __m128i);
extern __m256i _mm256_rem_epi8(__m256i, __m256i);
extern __m256i _mm256_rem_epi16(__m256i, __m256i);
extern __m256i _mm256_rem_epi32(__m256i, __m256i);
extern __m256i _mm256_rem_epi64(__m256i, __m256i);
extern __m256i _mm256_rem_epu8(__m256i, __m256i);
extern __m256i _mm256_rem_epu16(__m256i, __m256i);
extern __m256i _mm256_rem_epu32(__m256i, __m256i);
extern __m256i _mm256_rem_epu64(__m256i, __m256i);

extern __m128i _mm_sad_epu8(__m128i, __m128i);
extern __m256i _mm256_sad_epu8(__m256i, __m256i);

extern __m128i _mm_sign_epi8(__m128i, __m128i);
extern __m128i _mm_sign_epi16(__m128i, __m128i);
extern __m128i _mm_sign_epi32(__m128i, __m128i);
extern __m256i _mm256_sign_epi8(__m256i, __m256i);
extern __m256i _mm256_sign_epi16(__m256i, __m256i);
extern __m256i _mm256_sign_epi32(__m256i, __m256i);

extern __m128 _mm_sub_ss(__m128, __m128);
extern __m128 _mm_sub_ps(__m128, __m128);
extern __m128d _mm_sub_sd(__m128d, __m128d);
extern __m128d _mm_sub_pd(__m128d, __m128d);
extern __m128i _mm_sub_epi8(__m128i, __m128i);
extern __m128i _mm_sub_epi16(__m128i, __m128i);
extern __m128i _mm_sub_epi32(__m128i, __m128i);
extern __m128i _mm_sub_epi64(__m128i, __m128i);
extern __m256 _mm256_sub_ps(__m256, __m256);
extern __m256d _mm256_sub_pd(__m256d, __m256d);
extern __m256i _mm256_sub_epi8(__m256i, __m256i);
extern __m256i _mm256_sub_epi16(__m256i, __m256i);
extern __m256i _mm256_sub_epi32(__m256i, __m256i);
extern __m256i _mm256_sub_epi64(__m256i, __m256i);

extern __m128i _mm_subs_epi8(__m128i, __m128i);
extern __m128i _mm_subs_epi16(__m128i, __m128i);
extern __m128i _mm_subs_epu8(__m128i, __m128i);
extern __m128i _mm_subs_epu16(__m128i, __m128i);
extern __m256i _mm256_subs_epi8(__m256i, __m256i);
extern __m256i _mm256_subs_epi16(__m256i, __m256i);
extern __m256i _mm256_subs_epu8(__m256i, __m256i);
extern __m256i _mm256_subs_epu16(__m256i, __m256i);

#pragma endregion

#pragma region BITWISE

extern __m128 _mm_and_ps(__m128, __m128);
extern __m128d _mm_and_pd(__m128d, __m128d);
extern __m128i _mm_and_si128(__m128i, __m128i);
extern __m256 _mm256_and_ps(__m256, __m256);
extern __m256d _mm256_and_pd(__m256d, __m256d);
extern __m256i _mm256_and_si256(__m256i, __m256i);

extern __m128 _mm_andnot_ps(__m128, __m128);
extern __m128d _mm_andnot_pd(__m128d, __m128d);
extern __m128i _mm_andnot_si128(__m128i, __m128i);
extern __m256 _mm256_andnot_ps(__m256, __m256);
extern __m256d _mm256_andnot_pd(__m256d, __m256d);
extern __m256i _mm256_andnot_si256(__m256i, __m256i);

extern __m128 _mm_or_ps(__m128, __m128);
extern __m128d _mm_or_pd(__m128d, __m128d);
extern __m128i _mm_or_si128(__m128i, __m128i);
extern __m256 _mm256_or_ps(__m256, __m256);
extern __m256d _mm256_or_pd(__m256d, __m256d);
extern __m256i _mm256_or_si256(__m256i, __m256i);

[[deprecated("Use `slli` instead.")]] __m128i _mm_slli_si128(__m128i, const int) = delete;
[[deprecated("Use `srli` instead.")]] __m128i _mm_srli_si128(__m128i, const int) = delete;
[[deprecated("Use `slli` instead.")]] __m256i _mm256_bslli_epi128(__m256i, const int) = delete;
[[deprecated("Use `srli` instead.")]] __m256i _mm256_bsrli_epi128(__m256i, const int) = delete;

extern __m128i _mm_sll_epi16(__m128i _A, __m128i _Count);
extern __m128i _mm_sll_epi32(__m128i _A, __m128i _Count);
extern __m128i _mm_sll_epi64(__m128i _A, __m128i _Count);
extern __m256i _mm256_sll_epi16(__m256i, __m128i);
extern __m256i _mm256_sll_epi32(__m256i, __m128i);
extern __m256i _mm256_sll_epi64(__m256i, __m128i);

extern __m128i _mm_slli_epi16(__m128i _A, int _Count);
extern __m128i _mm_slli_epi32(__m128i _A, int _Count);
extern __m128i _mm_slli_si128(__m128i _A, int _Imm);
extern __m128i _mm_slli_epi64(__m128i _A, int _Count);
extern __m256i _mm256_slli_epi16(__m256i, int);
extern __m256i _mm256_slli_epi32(__m256i, int);
extern __m256i _mm256_slli_epi64(__m256i, int);
extern __m256i _mm256_slli_si256(__m256i, const int);

extern __m128i _mm_sllv_epi32(__m128i, __m128i);
extern __m128i _mm_sllv_epi64(__m128i, __m128i);
extern __m256i _mm256_sllv_epi32(__m256i, __m256i);
extern __m256i _mm256_sllv_epi64(__m256i, __m256i);

extern __m128i _mm_sra_epi16(__m128i _A, __m128i _Count);
extern __m128i _mm_sra_epi32(__m128i _A, __m128i _Count);
extern __m256i _mm256_sra_epi16(__m256i, __m128i);
extern __m256i _mm256_sra_epi32(__m256i, __m128i);

extern __m128i _mm_srai_epi16(__m128i _A, int _Count);
extern __m128i _mm_srai_epi32(__m128i _A, int _Count);
extern __m256i _mm256_srai_epi16(__m256i, int);
extern __m256i _mm256_srai_epi32(__m256i, int);

extern __m128i _mm_srav_epi32(__m128i, __m128i);
extern __m256i _mm256_srav_epi32(__m256i, __m256i);

extern __m128i _mm_srl_epi16(__m128i _A, __m128i _Count);
extern __m128i _mm_srl_epi32(__m128i _A, __m128i _Count);
extern __m128i _mm_srl_epi64(__m128i _A, __m128i _Count);
extern __m256i _mm256_srl_epi16(__m256i, __m128i);
extern __m256i _mm256_srl_epi32(__m256i, __m128i);
extern __m256i _mm256_srl_epi64(__m256i, __m128i);

extern __m128i _mm_srli_epi16(__m128i _A, int _Count);
extern __m128i _mm_srli_epi32(__m128i _A, int _Count);
extern __m128i _mm_srli_epi64(__m128i _A, int _Count);
extern __m128i _mm_srli_si128(__m128i _A, int _Imm);
extern __m256i _mm256_srli_epi16(__m256i, int);
extern __m256i _mm256_srli_epi32(__m256i, int);
extern __m256i _mm256_srli_epi64(__m256i, int);
extern __m256i _mm256_srli_si256(__m256i, const int);

extern __m128i _mm_srlv_epi32(__m128i, __m128i);
extern __m128i _mm_srlv_epi64(__m128i, __m128i);
extern __m256i _mm256_srlv_epi32(__m256i, __m256i);
extern __m256i _mm256_srlv_epi64(__m256i, __m256i);

extern __m128 _mm_xor_ps(__m128, __m128);
extern __m128d _mm_xor_pd(__m128d, __m128d);
extern __m128i _mm_xor_si128(__m128i, __m128i);
extern __m256 _mm256_xor_ps(__m256, __m256);
extern __m256d _mm256_xor_pd(__m256d, __m256d);
extern __m256i _mm256_xor_si256(__m256i, __m256i);

#pragma endregion

#pragma region BLEND

extern __m128 _mm_blend_ps(__m128, __m128, const int);
extern __m128d _mm_blend_pd(__m128d, __m128d, const int);
extern __m128i _mm_blend_epi16(__m128i, __m128i, const int);
extern __m128i _mm_blend_epi32(__m128i, __m128i, const int);
extern __m256 _mm256_blend_ps(__m256, __m256, const int);
extern __m256d _mm256_blend_pd(__m256d, __m256d, const int);
extern __m256i _mm256_blend_epi16(__m256i, __m256i, const int);
extern __m256i _mm256_blend_epi32(__m256i, __m256i, const int);

extern __m128 _mm_blendv_ps(__m128, __m128, __m128);
extern __m128d _mm_blendv_pd(__m128d, __m128d, __m128d);
extern __m128i _mm_blendv_epi8(__m128i, __m128i, __m128i);
extern __m256 _mm256_blendv_ps(__m256, __m256, __m256);
extern __m256d _mm256_blendv_pd(__m256d, __m256d, __m256d);
extern __m256i _mm256_blendv_epi8(__m256i, __m256i, __m256i);

#pragma endregion

#pragma region BROADCAST

extern __m128 _mm_broadcast_ss(const float*);
extern __m256 _mm256_broadcast_ss(const float*);
extern __m256 _mm256_broadcast_ps(__m128 const*);
extern __m256d _mm256_broadcast_sd(const double*);
extern __m256d _mm256_broadcast_pd(__m128d const*);

extern __m128 _mm_broadcastss_ps(__m128);
extern __m128d _mm_broadcastsd_pd(__m128d);
extern __m128i _mm_broadcastb_epi8(__m128i);
extern __m128i _mm_broadcastw_epi16(__m128i);
extern __m128i _mm_broadcastd_epi32(__m128i);
extern __m128i _mm_broadcastq_epi64(__m128i);
extern __m256 _mm256_broadcastss_ps(__m128);
extern __m256d _mm256_broadcastsd_pd(__m128d);
extern __m256i _mm256_broadcastb_epi8(__m128i);
extern __m256i _mm256_broadcastw_epi16(__m128i);
extern __m256i _mm256_broadcastd_epi32(__m128i);
extern __m256i _mm256_broadcastq_epi64(__m128i);
extern __m256i _mm256_broadcastsi128_si256(__m128i);

#pragma endregion

#pragma region CAST

extern __m128 _mm_castpd_ps(__m128d);
extern __m128i _mm_castpd_si128(__m128d);
extern __m256 _mm256_castpd_ps(__m256d);
extern __m256i _mm256_castpd_si256(__m256d);
extern __m256d _mm256_castpd128_pd256(__m128d);

extern __m128d _mm_castps_pd(__m128);
extern __m128i _mm_castps_si128(__m128);
extern __m256d _mm256_castps_pd(__m256);
extern __m256i _mm256_castps_si256(__m256);
extern __m256 _mm256_castps128_ps256(__m128);

extern __m128 _mm_castsi128_ps(__m128i);
extern __m128d _mm_castsi128_pd(__m128i);
extern __m256i _mm256_castsi128_si256(__m128i);

extern __m256 _mm256_castsi256_ps(__m256i);
extern __m256d _mm256_castsi256_pd(__m256i);
extern __m128 _mm256_castps256_ps128(__m256);
extern __m128d _mm256_castpd256_pd128(__m256d);
extern __m128i _mm256_castsi256_si128(__m256i);

extern __m256 _mm256_zextps128_ps256(__m128);
extern __m256d _mm256_zextpd128_pd256(__m128d);
extern __m256i _mm256_zextsi128_si256(__m128i);

#pragma endregion

#pragma region CONVERT

extern __int32 _mm_cvt_ss2si(__m128);
extern __m128 _mm_cvt_si2ss(__m128, __int32);

extern __m128i _mm_cvtepi8_epi16(__m128i);
extern __m128i _mm_cvtepi8_epi32(__m128i);
extern __m128i _mm_cvtepi8_epi64(__m128i);
extern __m256i _mm256_cvtepi8_epi16(__m128i);
extern __m256i _mm256_cvtepi8_epi32(__m128i);
extern __m256i _mm256_cvtepi8_epi64(__m128i);

extern __m128i _mm_cvtepu8_epi16(__m128i);
extern __m128i _mm_cvtepu8_epi32(__m128i);
extern __m128i _mm_cvtepu8_epi64(__m128i);
extern __m256i _mm256_cvtepu8_epi16(__m128i);
extern __m256i _mm256_cvtepu8_epi32(__m128i);
extern __m256i _mm256_cvtepu8_epi64(__m128i);

extern __m128i _mm_cvtepi16_epi32(__m128i);
extern __m128i _mm_cvtepi16_epi64(__m128i);
extern __m256i _mm256_cvtepi16_epi32(__m128i);
extern __m256i _mm256_cvtepi16_epi64(__m128i);

extern __m128i _mm_cvtepu16_epi32(__m128i);
extern __m128i _mm_cvtepu16_epi64(__m128i);
extern __m256i _mm256_cvtepu16_epi32(__m128i);
extern __m256i _mm256_cvtepu16_epi64(__m128i);

extern __m128 _mm_cvtepi32_ps(__m128i);
extern __m128d _mm_cvtepi32_pd(__m128i);
extern __m128i _mm_cvtepi32_epi64(__m128i);
extern __m256 _mm256_cvtepi32_ps(__m256i);
extern __m256d _mm256_cvtepi32_pd(__m128i);
extern __m256i _mm256_cvtepi32_epi64(__m128i);

extern __m128i _mm_cvtepu32_epi64(__m128i);
extern __m256i _mm256_cvtepu32_epi64(__m128i);

extern __m128 _mm_cvtpd_ps(__m128d);
extern __m128i _mm_cvtpd_epi32(__m128d);
extern __m128 _mm256_cvtpd_ps(__m256d);
extern __m128i _mm256_cvtpd_epi32(__m256d);

extern __m128d _mm_cvtps_pd(__m128);
extern __m128i _mm_cvtps_epi32(__m128);
extern __m256d _mm256_cvtps_pd(__m128);
extern __m256i _mm256_cvtps_epi32(__m256);

extern __int32 _mm_cvtsd_si32(__m128d);
extern __int64 _mm_cvtsd_si64(__m128d);
extern double _mm_cvtsd_f64(__m128d);
extern __m128 _mm_cvtsd_ss(__m128, __m128d);
inline double _mm256_cvtsd_f64(__m256d a) { return _mm_cvtsd_f64(_mm256_castpd256_pd128(a)); }

inline __m128 _mm_cvtsi32_ss(__m128 a, __int32 b) { return _mm_cvt_si2ss(a, b); }
extern __m128d _mm_cvtsi32_sd(__m128d, __int32);
extern __m128i _mm_cvtsi32_si128(__int32);

extern __m128 _mm_cvtsi64_ss(__m128, __int64);
extern __m128d _mm_cvtsi64_sd(__m128d, __int64);
extern __m128i _mm_cvtsi64_si128(__int64);

extern int _mm_cvtsi128_si32(__m128i);
extern __int64 _mm_cvtsi128_si64(__m128i);
inline __int32 _mm256_cvtsi256_si32(__m256i a) { return _mm_cvtsi128_si32(_mm256_castsi256_si128(a)); }
inline __int64 _mm256_cvtsi256_si64(__m256i a) { return _mm_cvtsi128_si64(_mm256_castsi256_si128(a)); }

extern float _mm_cvtss_f32(__m128);
inline float _mm256_cvtss_f32(__m256 a) { return _mm_cvtss_f32(_mm256_castps256_ps128(a)); }
extern __m128d _mm_cvtss_sd(__m128d, __m128);
inline __int32 _mm_cvtss_si32(__m128 a) { return _mm_cvt_ss2si(a); }
extern __int64 _mm_cvtss_si64(__m128);

extern __int32 _mm_cvtt_ss2si(__m128);

extern __m128i _mm_cvttpd_epi32(__m128d);
extern __m128i _mm256_cvttpd_epi32(__m256d);

extern __m128i _mm_cvttps_epi32(__m128);
extern __m256i _mm256_cvttps_epi32(__m256);

extern __int32 _mm_cvttsd_si32(__m128d);
extern __int64 _mm_cvttsd_si64(__m128d);

inline __int32 _mm_cvttss_si32(__m128 a) { return _mm_cvtt_ss2si(a); }
extern __int64 _mm_cvttss_si64(__m128);

#pragma endregion

#pragma region COMPARE

extern __m128 _mm_cmp_ss(__m128, __m128, const int);
extern __m128 _mm_cmp_ps(__m128, __m128, const int);
extern __m128d _mm_cmp_sd(__m128d, __m128d, const int);
extern __m128d _mm_cmp_pd(__m128d, __m128d, const int);
extern __m256 _mm256_cmp_ps(__m256, __m256, const int);
extern __m256d _mm256_cmp_pd(__m256d, __m256d, const int);

extern __m128 _mm_cmpeq_ss(__m128, __m128);
extern __m128 _mm_cmpeq_ps(__m128, __m128);
extern __m128d _mm_cmpeq_sd(__m128d, __m128d);
extern __m128d _mm_cmpeq_pd(__m128d, __m128d);
extern __m128i _mm_cmpeq_epi8(__m128i, __m128i);
extern __m128i _mm_cmpeq_epi16(__m128i, __m128i);
extern __m128i _mm_cmpeq_epi32(__m128i, __m128i);
extern __m128i _mm_cmpeq_epi64(__m128i, __m128i);
extern __m256i _mm256_cmpeq_epi8(__m256i, __m256i);
extern __m256i _mm256_cmpeq_epi16(__m256i, __m256i);
extern __m256i _mm256_cmpeq_epi32(__m256i, __m256i);
extern __m256i _mm256_cmpeq_epi64(__m256i, __m256i);

extern __m128 _mm_cmpge_ss(__m128, __m128);
extern __m128 _mm_cmpge_ps(__m128, __m128);
extern __m128d _mm_cmpge_sd(__m128d, __m128d);
extern __m128d _mm_cmpge_pd(__m128d, __m128d);

extern __m128 _mm_cmpgt_ss(__m128, __m128);
extern __m128 _mm_cmpgt_ps(__m128, __m128);
extern __m128d _mm_cmpgt_sd(__m128d, __m128d);
extern __m128d _mm_cmpgt_pd(__m128d, __m128d);
extern __m128i _mm_cmpgt_epi8(__m128i, __m128i);
extern __m128i _mm_cmpgt_epi16(__m128i, __m128i);
extern __m128i _mm_cmpgt_epi32(__m128i, __m128i);
extern __m128i _mm_cmpgt_epi64(__m128i, __m128i);
extern __m256i _mm256_cmpgt_epi8(__m256i, __m256i);
extern __m256i _mm256_cmpgt_epi16(__m256i, __m256i);
extern __m256i _mm256_cmpgt_epi32(__m256i, __m256i);
extern __m256i _mm256_cmpgt_epi64(__m256i, __m256i);

extern __m128 _mm_cmple_ss(__m128, __m128);
extern __m128 _mm_cmple_ps(__m128, __m128);
extern __m128d _mm_cmple_sd(__m128d, __m128d);
extern __m128d _mm_cmple_pd(__m128d, __m128d);

extern __m128 _mm_cmplt_ss(__m128, __m128);
extern __m128 _mm_cmplt_ps(__m128, __m128);
extern __m128d _mm_cmplt_sd(__m128d, __m128d);
extern __m128d _mm_cmplt_pd(__m128d, __m128d);
extern __m128i _mm_cmplt_epi8(__m128i, __m128i);
extern __m128i _mm_cmplt_epi16(__m128i, __m128i);
extern __m128i _mm_cmplt_epi32(__m128i, __m128i);

extern __m128 _mm_cmpneq_ss(__m128, __m128);
extern __m128 _mm_cmpneq_ps(__m128, __m128);
extern __m128d _mm_cmpneq_sd(__m128d, __m128d);
extern __m128d _mm_cmpneq_pd(__m128d, __m128d);

extern __m128 _mm_cmpnge_ss(__m128, __m128);
extern __m128 _mm_cmpnge_ps(__m128, __m128);
extern __m128d _mm_cmpnge_sd(__m128d, __m128d);
extern __m128d _mm_cmpnge_pd(__m128d, __m128d);

extern __m128 _mm_cmpngt_ss(__m128, __m128);
extern __m128 _mm_cmpngt_ps(__m128, __m128);
extern __m128d _mm_cmpngt_sd(__m128d, __m128d);
extern __m128d _mm_cmpngt_pd(__m128d, __m128d);

extern __m128 _mm_cmpnle_ss(__m128, __m128);
extern __m128 _mm_cmpnle_ps(__m128, __m128);
extern __m128d _mm_cmpnle_sd(__m128d, __m128d);
extern __m128d _mm_cmpnle_pd(__m128d, __m128d);

extern __m128 _mm_cmpnlt_ss(__m128, __m128);
extern __m128 _mm_cmpnlt_ps(__m128, __m128);
extern __m128d _mm_cmpnlt_sd(__m128d, __m128d);
extern __m128d _mm_cmpnlt_pd(__m128d, __m128d);

extern __m128 _mm_cmpord_ss(__m128, __m128);
extern __m128 _mm_cmpord_ps(__m128, __m128);
extern __m128d _mm_cmpord_pd(__m128d, __m128d);
extern __m128d _mm_cmpord_sd(__m128d, __m128d);

extern __m128 _mm_cmpunord_ss(__m128, __m128);
extern __m128 _mm_cmpunord_ps(__m128, __m128);
extern __m128d _mm_cmpunord_pd(__m128d, __m128d);
extern __m128d _mm_cmpunord_sd(__m128d, __m128d);

extern int _mm_comi_sd(__m128d, __m128d, const int);
extern int _mm_comi_ss(__m128, __m128, const int);

extern int _mm_comieq_ss(__m128, __m128);
extern int _mm_comige_ss(__m128, __m128);
extern int _mm_comigt_ss(__m128, __m128);
extern int _mm_comile_ss(__m128, __m128);
extern int _mm_comilt_ss(__m128, __m128);
extern int _mm_comineq_ss(__m128, __m128);
extern int _mm_ucomieq_ss(__m128, __m128);
extern int _mm_ucomige_ss(__m128, __m128);
extern int _mm_ucomigt_ss(__m128, __m128);
extern int _mm_ucomile_ss(__m128, __m128);
extern int _mm_ucomilt_ss(__m128, __m128);
extern int _mm_ucomineq_ss(__m128, __m128);

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

#pragma endregion

#pragma region EXTRACT-INSERT

extern __int32 _mm_extract_ps(__m128, const int);
extern __int32 _mm_extract_epi8(__m128i, const int);
extern __int32 _mm_extract_epi16(__m128i, int);
extern __int32 _mm_extract_epi32(__m128i, const int);
extern __int64 _mm_extract_epi64(__m128i, const int);
extern __int32 _mm256_extract_epi8(__m256i, const int);
extern __int32 _mm256_extract_epi16(__m256i, const int);
extern __int32 _mm256_extract_epi32(__m256i, const int);
extern __int64 _mm256_extract_epi64(__m256i, const int);

extern __m128 _mm256_extractf128_ps(__m256, const int);
extern __m128d _mm256_extractf128_pd(__m256d, const int);
extern __m128i _mm256_extractf128_si256(__m256i, const int);
extern __m128i _mm256_extracti128_si256(__m256i, const int);

extern __m128 _mm_insert_ps(__m128, __m128, const int);
extern __m128i _mm_insert_epi8(__m128i, __int32, const int);
extern __m128i _mm_insert_epi16(__m128i, __int32, int);
extern __m128i _mm_insert_epi32(__m128i, __int32, const int);
extern __m128i _mm_insert_epi64(__m128i, __int64, const int);
extern __m256i _mm256_insert_epi8(__m256i, __int32, const int);
extern __m256i _mm256_insert_epi16(__m256i, __int32, const int);
extern __m256i _mm256_insert_epi32(__m256i, __int32, const int);
extern __m256i _mm256_insert_epi64(__m256i, __int64, const int);

extern __m256 _mm256_insertf128_ps(__m256, __m128, int);
extern __m256d _mm256_insertf128_pd(__m256d, __m128d, int);
extern __m256i _mm256_insertf128_si256(__m256i, __m128i, int);
extern __m256i _mm256_inserti128_si256(__m256i, __m128i, const int);

#pragma endregion

#pragma region GATHER

extern __m256 _mm256_mask_i32gather_ps(__m256, const float*, __m256i, __m256, const int);
extern __m256d _mm256_mask_i32gather_pd(__m256d, const double*, __m128i, __m256d, const int);
extern __m128 _mm256_mask_i64gather_ps(__m128, const float*, __m256i, __m128, const int);
extern __m256d _mm256_mask_i64gather_pd(__m256d, const double*, __m256i, __m256d, const int);

extern __m128 _mm_mask_i32gather_ps(__m128, const float*, __m128i, __m128, const int);
extern __m128d _mm_mask_i32gather_pd(__m128d, const double*, __m128i, __m128d, const int);
extern __m128 _mm_mask_i64gather_ps(__m128, const float*, __m128i, __m128, const int);
extern __m128d _mm_mask_i64gather_pd(__m128d, const double*, __m128i, __m128d, const int);

extern __m256i _mm256_mask_i32gather_epi32(__m256i, const int*, __m256i, __m256i, const int);
extern __m256i _mm256_mask_i32gather_epi64(__m256i, const __int64*, __m128i, __m256i, const int);
extern __m128i _mm256_mask_i64gather_epi32(__m128i, const int*, __m256i, __m128i, const int);
extern __m256i _mm256_mask_i64gather_epi64(__m256i, const __int64*, __m256i, __m256i, const int);

extern __m128i _mm_mask_i32gather_epi32(__m128i, const int*, __m128i, __m128i, const int);
extern __m128i _mm_mask_i32gather_epi64(__m128i, const __int64*, __m128i, __m128i, const int);
extern __m128i _mm_mask_i64gather_epi32(__m128i, const int*, __m128i, __m128i, const int);
extern __m128i _mm_mask_i64gather_epi64(__m128i, const __int64*, __m128i, __m128i, const int);

extern __m256 _mm256_i32gather_ps(const float*, __m256i, const int);
extern __m256d _mm256_i32gather_pd(const double*, __m128i, const int);
extern __m128 _mm256_i64gather_ps(const float*, __m256i, const int);
extern __m256d _mm256_i64gather_pd(const double*, __m256i, const int);

extern __m128 _mm_i32gather_ps(const float*, __m128i, const int);
extern __m128d _mm_i32gather_pd(const double*, __m128i, const int);
extern __m128 _mm_i64gather_ps(const float*, __m128i, const int);
extern __m128d _mm_i64gather_pd(const double*, __m128i, const int);

extern __m256i _mm256_i32gather_epi32(const int*, __m256i, const int);
extern __m256i _mm256_i32gather_epi64(const __int64*, __m128i, const int);
extern __m128i _mm256_i64gather_epi32(const int*, __m256i, const int);
extern __m256i _mm256_i64gather_epi64(const __int64*, __m256i, const int);

extern __m128i _mm_i32gather_epi32(const int*, __m128i, const int);
extern __m128i _mm_i32gather_epi64(const __int64*, __m128i, const int);
extern __m128i _mm_i64gather_epi32(const int*, __m128i, const int);
extern __m128i _mm_i64gather_epi64(const __int64*, __m128i, const int);

#pragma endregion

#pragma region LOAD-SET

extern __m128 _mm_set_ss(float);
extern __m128 _mm_set_ps(float, float, float, float);
extern __m128 _mm_set_ps1(float);
extern __m128d _mm_set_sd(double);
extern __m128d _mm_set_pd(double, double);
extern __m128i _mm_set_epi8(char, char, char, char, char, char, char, char, char, char, char, char, char, char, char,
                            char);
extern __m128i _mm_set_epi16(short, short, short, short, short, short, short, short);
extern __m128i _mm_set_epi32(int, int, int, int);
extern __m128i _mm_set_epi64x(__int64, __int64);
extern __m256 _mm256_set_ps(float, float, float, float, float, float, float, float);
extern __m256d _mm256_set_pd(double, double, double, double);
extern __m256i _mm256_set_epi8(char, char, char, char, char, char, char, char, char, char, char, char, char, char, char,
                               char, char, char, char, char, char, char, char, char, char, char, char, char, char, char,
                               char, char);
extern __m256i _mm256_set_epi16(short, short, short, short, short, short, short, short, short, short, short, short,
                                short, short, short, short);
extern __m256i _mm256_set_epi32(int, int, int, int, int, int, int, int);
extern __m256i _mm256_set_epi64x(__int64, __int64, __int64, __int64);
inline __m256 _mm256_set_m128(__m128 hi, __m128 lo) {
  return _mm256_insertf128_ps(_mm256_castps128_ps256(lo), hi, 0x1);
}
inline __m256d _mm256_set_m128d(__m128d hi, __m128d lo) {
  return _mm256_insertf128_pd(_mm256_castpd128_pd256(lo), hi, 0x1);
}
inline __m256i _mm256_set_m128i(__m128i hi, __m128i lo) {
  return _mm256_insertf128_si256(_mm256_castsi128_si256(lo), hi, 0x1);
}

inline __m128 _mm_set1_ps(float a) { return _mm_set_ps1(a); }
extern __m128d _mm_set1_pd(double);
inline __m128i _mm_set_pd1(double a) { return _mm_set1_pd(a); }
extern __m128i _mm_set1_epi8(char);
extern __m128i _mm_set1_epi16(short);
extern __m128i _mm_set1_epi32(int);
extern __m128i _mm_set1_epi64x(__int64);
extern __m256 _mm256_set1_ps(float);
extern __m256d _mm256_set1_pd(double);
extern __m256i _mm256_set1_epi8(char);
extern __m256i _mm256_set1_epi16(short);
extern __m256i _mm256_set1_epi32(int);
extern __m256i _mm256_set1_epi64x(long long);

extern __m128 _mm_setr_ps(float, float, float, float);
extern __m128d _mm_setr_pd(double, double);
extern __m128i _mm_setr_epi8(char, char, char, char, char, char, char, char, char, char, char, char, char, char, char,
                             char);
extern __m128i _mm_setr_epi16(short, short, short, short, short, short, short, short);
extern __m128i _mm_setr_epi32(int, int, int, int);
extern __m128i _mm_setr_epi64x(__int64, __int64);
extern __m256 _mm256_setr_ps(float, float, float, float, float, float, float, float);
extern __m256d _mm256_setr_pd(double, double, double, double);
extern __m256i _mm256_setr_epi8(char, char, char, char, char, char, char, char, char, char, char, char, char, char,
                                char, char, char, char, char, char, char, char, char, char, char, char, char, char,
                                char, char, char, char);
extern __m256i _mm256_setr_epi16(short, short, short, short, short, short, short, short, short, short, short, short,
                                 short, short, short, short);
extern __m256i _mm256_setr_epi32(int, int, int, int, int, int, int, int);
extern __m256i _mm256_setr_epi64x(__int64, __int64, __int64, __int64);
inline __m256 _mm256_setr_m128(__m128 lo, __m128 hi) { return _mm256_set_m128(hi, lo); }
inline __m256d _mm256_setr_m128d(__m128d lo, __m128d hi) { return _mm256_set_m128d(hi, lo); }
inline __m256i _mm256_setr_m128i(__m128i lo, __m128i hi) { return _mm256_set_m128i(hi, lo); }

extern __m128 _mm_setzero_ps();
extern __m128d _mm_setzero_pd();
extern __m128i _mm_setzero_si128();
extern __m256 _mm256_setzero_ps();
extern __m256d _mm256_setzero_pd();
extern __m256i _mm256_setzero_si256();

inline __m128 _mm_undefined_ps() { return _mm_setzero_ps(); }
inline __m128d _mm_undefined_pd() { return _mm_setzero_pd(); }
inline __m128i _mm_undefined_si128() { return _mm_setzero_si128(); }
inline __m256 _mm256_undefined_ps() { return _mm256_setzero_ps(); }
inline __m256d _mm256_undefined_pd() { return _mm256_setzero_pd(); }
inline __m256i _mm256_undefined_si256() { return _mm256_setzero_si256(); }

extern __m128 _mm_load_ss(const float*);
extern __m128 _mm_load_ps1(const float*);
extern __m128 _mm_load_ps(const float*);
extern __m128d _mm_load_sd(const double*);
extern __m128d _mm_load_pd(const double*);
extern __m128i _mm_load_si128(const __m128i*);
extern __m256 _mm256_load_ps(const float*);
extern __m256d _mm256_load_pd(const double*);
extern __m256i _mm256_load_si256(const __m256i*);

inline __m128 _mm_load1_ps(const float* a) { return _mm_load_ps1(a); }
extern __m128d _mm_load1_pd(const double*);
inline __m128d _mm_load_pd1(const double* a) { return _mm_load1_pd(a); }

extern __m128 _mm_loadh_pi(__m128, const __m64*);
extern __m128d _mm_loadh_pd(__m128d, const double*);

extern __m128 _mm_loadl_pi(__m128, const __m64*);
extern __m128d _mm_loadl_pd(__m128d, const double*);
extern __m128i _mm_loadl_epi64(const __m128i*);

extern __m128 _mm_loadr_ps(const float*);
extern __m128d _mm_loadr_pd(const double*);

extern __m128 _mm_loadu_ps(const float*);
extern __m128d _mm_loadu_pd(const double*);
extern __m128i _mm_loadu_si128(const __m128i*);
extern __m256 _mm256_loadu_ps(const float*);
extern __m256d _mm256_loadu_pd(const double*);
extern __m256i _mm256_loadu_si256(const __m256i*);
inline __m256 _mm_loadu_si16(const unsigned __int16* p) { return _mm_cvtsi32_si128(*p); }
inline __m256 _mm_loadu_si32(const unsigned __int32* p) { return _mm_cvtsi32_si128(*p); }
inline __m256 _mm_loadu_si64(const unsigned __int64* p) { return _mm_loadl_epi64((const __m128i*)p); }

inline __m256 _mm256_loadu2_m128(const float* hi, const float* lo) {
  return _mm256_set_m128(_mm_loadu_ps(hi), _mm_loadu_ps(lo));
}
inline __m256d _mm256_loadu2_m128d(const double* hi, const double* lo) {
  return _mm256_set_m128d(_mm_loadu_pd(hi), _mm_loadu_pd(lo));
}
inline __m256i _mm256_loadu2_m128i(const __m128i* hi, const __m128i* lo) {
  return _mm256_set_m128i(_mm_loadu_si128(hi), _mm_loadu_si128(lo));
}

extern __m128d _mm_loaddup_pd(const double*);
extern __m128i _mm_lddqu_si128(const __m128i*);
extern __m256i _mm256_lddqu_si256(const __m256i*);

#pragma endregion

#pragma region MATH

extern __m128 _mm_rcp_ss(__m128);
extern __m128 _mm_rcp_ps(__m128);

extern __m128 _mm_rsqrt_ss(__m128);
extern __m128 _mm_rsqrt_ps(__m128);

extern __m128 _mm_sqrt_ss(__m128);
extern __m128 _mm_sqrt_ps(__m128);
extern __m128d _mm_sqrt_sd(__m128d, __m128d);
extern __m128d _mm_sqrt_pd(__m128d);


extern __m256 _mm256_rcp_ps(__m256);
extern __m256 _mm256_rsqrt_ps(__m256);
extern __m256d _mm256_sqrt_pd(__m256d);
extern __m256 _mm256_sqrt_ps(__m256);

#pragma endregion

#pragma region MASK-MOVE

extern __m128 _mm_move_ss(__m128, __m128);
extern __m128d _mm_move_sd(__m128d, __m128d);
extern __m128i _mm_move_epi64(__m128i);

extern __m128d _mm_movedup_pd(__m128d);
extern __m256d _mm256_movedup_pd(__m256d);

extern __m128 _mm_movehdup_ps(__m128);
extern __m256 _mm256_movehdup_ps(__m256);

extern __m128 _mm_movehl_ps(__m128, __m128);

extern __m128 _mm_moveldup_ps(__m128);
extern __m256 _mm256_moveldup_ps(__m256);

extern __m128 _mm_movelh_ps(__m128, __m128);

extern int _mm_movemask_ps(__m128);
extern int _mm_movemask_pd(__m128d);
extern int _mm_movemask_epi8(__m128i);
extern int _mm256_movemask_ps(__m256);
extern int _mm256_movemask_pd(__m256d);
extern int _mm256_movemask_epi8(__m256i);

extern __m128 _mm_maskload_ps(const float*, __m128i);
extern __m128d _mm_maskload_pd(const double*, __m128i);
extern __m128i _mm_maskload_epi32(const int*, __m128i);
extern __m128i _mm_maskload_epi64(const __int64*, __m128i);
extern __m256 _mm256_maskload_ps(const float*, __m256i);
extern __m256d _mm256_maskload_pd(const double*, __m256i);
extern __m256i _mm256_maskload_epi32(const int*, __m256i);
extern __m256i _mm256_maskload_epi64(const __int64*, __m256i);

extern void _mm_maskstore_ps(float*, __m128i, __m128);
extern void _mm_maskstore_pd(double*, __m128i, __m128d);
extern void _mm_maskstore_epi32(int*, __m128i, __m128i);
extern void _mm_maskstore_epi64(__int64*, __m128i, __m128i);
extern void _mm256_maskstore_ps(float*, __m256i, __m256);
extern void _mm256_maskstore_pd(double*, __m256i, __m256d);
extern void _mm256_maskstore_epi32(int*, __m256i, __m256i);
extern void _mm256_maskstore_epi64(__int64*, __m256i, __m256i);

#pragma endregion

#pragma region PACK-UNPACK

extern __m128i _mm_packs_epi16(__m128i, __m128i);
extern __m128i _mm_packs_epi32(__m128i, __m128i);
extern __m256i _mm256_packs_epi16(__m256i, __m256i);
extern __m256i _mm256_packs_epi32(__m256i, __m256i);

extern __m128i _mm_packus_epi16(__m128i, __m128i);
extern __m128i _mm_packus_epi32(__m128i, __m128i);
extern __m256i _mm256_packus_epi16(__m256i, __m256i);
extern __m256i _mm256_packus_epi32(__m256i, __m256i);

extern __m128 _mm_unpackhi_ps(__m128, __m128);
extern __m128d _mm_unpackhi_pd(__m128d, __m128d);
extern __m128i _mm_unpackhi_epi8(__m128i, __m128i);
extern __m128i _mm_unpackhi_epi16(__m128i, __m128i);
extern __m128i _mm_unpackhi_epi32(__m128i, __m128i);
extern __m128i _mm_unpackhi_epi64(__m128i, __m128i);
extern __m256 _mm256_unpackhi_ps(__m256, __m256);
extern __m256d _mm256_unpackhi_pd(__m256d, __m256d);
extern __m256i _mm256_unpackhi_epi8(__m256i, __m256i);
extern __m256i _mm256_unpackhi_epi16(__m256i, __m256i);
extern __m256i _mm256_unpackhi_epi32(__m256i, __m256i);
extern __m256i _mm256_unpackhi_epi64(__m256i, __m256i);

extern __m128 _mm_unpacklo_ps(__m128, __m128);
extern __m128d _mm_unpacklo_pd(__m128d, __m128d);
extern __m128i _mm_unpacklo_epi8(__m128i, __m128i);
extern __m128i _mm_unpacklo_epi16(__m128i, __m128i);
extern __m128i _mm_unpacklo_epi32(__m128i, __m128i);
extern __m128i _mm_unpacklo_epi64(__m128i, __m128i);
extern __m256 _mm256_unpacklo_ps(__m256, __m256);
extern __m256d _mm256_unpacklo_pd(__m256d, __m256d);
extern __m256i _mm256_unpacklo_epi8(__m256i, __m256i);
extern __m256i _mm256_unpacklo_epi16(__m256i, __m256i);
extern __m256i _mm256_unpacklo_epi32(__m256i, __m256i);
extern __m256i _mm256_unpacklo_epi64(__m256i, __m256i);

#pragma endregion

#pragma region PERMUTE

extern __m128 _mm_permute_ps(__m128, int);
extern __m128d _mm_permute_pd(__m128d, int);
extern __m256 _mm256_permute_ps(__m256, int);
extern __m256d _mm256_permute_pd(__m256d, int);

extern __m256 _mm256_permute2f128_ps(__m256, __m256, int);
extern __m256d _mm256_permute2f128_pd(__m256d, __m256d, int);
extern __m256i _mm256_permute2f128_si256(__m256i, __m256i, int);

extern __m128 _mm_permutevar_ps(__m128, __m128i);
extern __m128d _mm_permutevar_pd(__m128d, __m128i);
extern __m256 _mm256_permutevar_ps(__m256, __m256i);
extern __m256d _mm256_permutevar_pd(__m256d, __m256i);

extern __m256i _mm256_permute2x128_si256(__m256i, __m256i, const int);
extern __m256d _mm256_permute4x64_pd(__m256d, const int);
extern __m256i _mm256_permute4x64_epi64(__m256i, const int);
extern __m256 _mm256_permutevar8x32_ps(__m256, __m256i);
extern __m256i _mm256_permutevar8x32_epi32(__m256i, __m256i);

#pragma endregion

#pragma region ROUNDING

extern __m128 _mm_round_ss(__m128, __m128, int);
extern __m128 _mm_round_ps(__m128, int);
extern __m128d _mm_round_sd(__m128d, __m128d, int);
extern __m128d _mm_round_pd(__m128d, int);
extern __m256 _mm256_round_ps(__m256, int);
extern __m256d _mm256_round_pd(__m256d, int);

inline __m128 _mm_ceil_ss(__m128 a, __m128 b) { return _mm_round_ss(a, b, 0x02); }
inline __m128 _mm_ceil_ps(__m128 a) { return _mm_round_ps(a, 0x02); }
inline __m128d _mm_ceil_sd(__m128d a, __m128d b) { return _mm_round_sd(a, b, 0x02); }
inline __m128d _mm_ceil_pd(__m128d a) { return _mm_round_pd(a, 0x02); }
inline __m256 _mm256_ceil_ps(__m256 a) { return _mm256_round_ps(a, 0x02); }
inline __m256d _mm256_ceil_pd(__m256d a) { return _mm256_round_pd(a, 0x02); }

inline __m128 _mm_floor_ss(__m128 a, __m128 b) { return _mm_round_ss(a, b, 0x01); }
inline __m128 _mm_floor_ps(__m128 a) { return _mm_round_ps(a, 0x01); }
inline __m128d _mm_floor_sd(__m128d a, __m128d b) { return _mm_round_sd(a, b, 0x01); }
inline __m128d _mm_floor_pd(__m128d a) { return _mm_round_pd(a, 0x01); }
inline __m256 _mm256_floor_ps(__m256 a) { return _mm256_round_ps(a, 0x01); }
inline __m256d _mm256_floor_pd(__m256d a) { return _mm256_round_pd(a, 0x01); }

#pragma endregion

#pragma region SHUFFLE

extern __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern __m128d _mm_shuffle_pd(__m128d, __m128d, int);
extern __m128i _mm_shuffle_epi8(__m128i, __m128i);
extern __m128i _mm_shuffle_epi32(__m128i, int);
extern __m256 _mm256_shuffle_ps(__m256, __m256, const int);
extern __m256d _mm256_shuffle_pd(__m256d, __m256d, const int);
extern __m256i _mm256_shuffle_epi8(__m256i, __m256i);
extern __m256i _mm256_shuffle_epi32(__m256i, const int);

extern __m128i _mm_shufflehi_epi16(__m128i, int);
extern __m128i _mm_shufflelo_epi16(__m128i, int);
extern __m256i _mm256_shufflehi_epi16(__m256i, const int);
extern __m256i _mm256_shufflelo_epi16(__m256i, const int);

#pragma endregion

#pragma region SSE-AVX-MISC


extern void _mm_prefetch(char const* _A, int _Sel);

extern void _mm_sfence();
extern unsigned int _mm_getcsr();
extern void _mm_setcsr(unsigned int);

extern void _mm_maskmoveu_si128(__m128i _D, __m128i _N, char* _P);


extern void _mm_clflush(const void* _P);
extern void _mm_lfence();
extern void _mm_mfence();
extern void _mm_pause();
extern void _mm_monitor(const void* /* p */, unsigned /* extensions */, unsigned /* hints */);
extern void _mm_mwait(unsigned /* extensions */, unsigned /* hints */);


extern __m128i _mm_minpos_epu16(__m128i);


extern int _mm_popcnt_u32(unsigned int /* v */);
extern __int64 _mm_popcnt_u64(unsigned __int64 /* v */);

extern unsigned int _mm_crc32_u8(unsigned int /* crc */, unsigned char /* v */);
extern unsigned int _mm_crc32_u16(unsigned int /* crc */, unsigned short /* v */);
extern unsigned int _mm_crc32_u32(unsigned int /* crc */, unsigned int /* v */);
extern unsigned __int64 _mm_crc32_u64(unsigned __int64 /* crc */, unsigned __int64 /* v */);

extern __m128i _mm_clmulepi64_si128(__m128i /* v1 */, __m128i /* v2 */, const int /* imm8 */);

extern void _mm256_zeroall();
extern void _mm256_zeroupper();

#pragma endregion

#pragma region STORE

extern void _mm_store_ss(float*, __m128);
extern void _mm_store_ps(float*, __m128);
extern void _mm_store_ps1(float*, __m128);
extern void _mm_store_sd(double*, __m128d);
extern void _mm_store_pd(double*, __m128d);
extern void _mm_store_si128(__m128i*, __m128i);
extern void _mm256_store_ps(float*, __m256);
extern void _mm256_store_pd(double*, __m256d);
extern void _mm256_store_si256(__m256i*, __m256i);

inline void _mm_store1_ps(float* a, __m128 b) { _mm_store_ps1(a, b); }
extern void _mm_store1_pd(double*, __m128d);
inline void _mm_store_pd1(double* a, __m128d b) { _mm_store1_pd(a, b); }

extern void _mm_storeh_pi(__m64*, __m128);
extern void _mm_storeh_pd(double*, __m128d);

extern void _mm_storel_pi(__m64*, __m128);
extern void _mm_storel_pd(double*, __m128d);
extern void _mm_storel_epi64(__m128i*, __m128i);

extern void _mm_storer_ps(float*, __m128);
extern void _mm_storer_pd(double*, __m128d);

extern void _mm_storeu_ps(float*, __m128);
extern void _mm_storeu_pd(double*, __m128d);
inline void _mm_storeu_si16(__int16* p, __m128 a) { *p = (short)_mm_cvtsi128_si32(a); }
inline void _mm_storeu_si32(__int32* p, __m128 a) { *p = _mm_cvtsi128_si32(a); }
inline void _mm_storeu_si64(__int64* p, __m128 a) { _mm_storel_epi64((__m128i*)p, a); }
extern void _mm_storeu_si128(__m128i*, __m128i);
extern void _mm256_storeu_ps(float*, __m256);
extern void _mm256_storeu_pd(double*, __m256d);
extern void _mm256_storeu_si256(__m256i*, __m256i);

inline void _mm256_storeu2_m128(float* hi, float* lo, __m256 a) {
  _mm_storeu_ps(lo, _mm256_castps256_ps128(a)), _mm_storeu_ps(hi, _mm256_extractf128_ps(a, 0x1));
}
inline void _mm256_storeu2_m128d(double* hi, double* lo, __m256d a) {
  _mm_storeu_pd(lo, _mm256_castpd256_pd128(a)), _mm_storeu_pd(hi, _mm256_extractf128_pd(a, 0x1));
}
inline void _mm256_storeu2_m128i(__m128i* hi, __m128i* lo, __m256i a) {
  _mm_storeu_si128(lo, _mm256_castsi256_si128(a)), _mm_storeu_si128(hi, _mm256_extractf128_si256(a, 0x1));
}

#pragma endregion

#pragma region STREAM

extern void _mm_stream_ps(float*, __m128);
extern void _mm_stream_pd(double*, __m128d);
extern void _mm_stream_si32(int*, int);
extern void _mm_stream_si128(__m128i*, __m128i);
extern void _mm256_stream_ps(float*, __m256);
extern void _mm256_stream_pd(double*, __m256d);
extern void _mm256_stream_si256(__m256i*, __m256i);

extern __m128i _mm_stream_load_si128(const __m128i*);
extern __m256i _mm256_stream_load_si256(const __m256i*);

#pragma endregion

#pragma region STRING-COMPARE

extern int _mm_cmpestra(__m128i, int, __m128i, int, const int);
extern int _mm_cmpestrc(__m128i, int, __m128i, int, const int);
extern int _mm_cmpestri(__m128i, int, __m128i, int, const int);
extern int _mm_cmpestro(__m128i, int, __m128i, int, const int);
extern int _mm_cmpestrs(__m128i, int, __m128i, int, const int);
extern int _mm_cmpestrz(__m128i, int, __m128i, int, const int);

extern int _mm_cmpistra(__m128i, __m128i, const int);
extern int _mm_cmpistrc(__m128i, __m128i, const int);
extern int _mm_cmpistri(__m128i, __m128i, const int);
extern int _mm_cmpistro(__m128i, __m128i, const int);
extern int _mm_cmpistrs(__m128i, __m128i, const int);
extern int _mm_cmpistrz(__m128i, __m128i, const int);

extern __m128i _mm_cmpestrm(__m128i, int, __m128i, int, const int);
extern __m128i _mm_cmpistrm(__m128i, __m128i, const int);

#pragma endregion

#pragma region TEST

extern int _mm_testc_ps(__m128, __m128);
extern int _mm_testc_pd(__m128d, __m128d);
extern int _mm_testc_si128(__m128i, __m128i);
extern int _mm256_testc_ps(__m256, __m256);
extern int _mm256_testc_pd(__m256d, __m256d);
extern int _mm256_testc_si256(__m256i, __m256i);

extern int _mm_testz_ps(__m128, __m128);
extern int _mm_testz_pd(__m128d, __m128d);
extern int _mm_testz_si128(__m128i, __m128i);
extern int _mm256_testz_ps(__m256, __m256);
extern int _mm256_testz_pd(__m256d, __m256d);
extern int _mm256_testz_si256(__m256i, __m256i);

extern int _mm_testnzc_ps(__m128, __m128);
extern int _mm_testnzc_pd(__m128d, __m128d);
extern int _mm_testnzc_si128(__m128i, __m128i);
extern int _mm256_testnzc_ps(__m256, __m256);
extern int _mm256_testnzc_pd(__m256d, __m256d);
extern int _mm256_testnzc_si256(__m256i, __m256i);

inline int _mm_test_all_ones(__m128i a) { return _mm_testz_si128(a, _mm_cmpeq_epi32(a, a)); }
inline int _mm256_test_all_ones(__m256i a) { return _mm256_testz_si256(a, _mm256_cmpeq_epi32(a, a)); }

inline int _mm_test_all_zeros(__m128i a, __m128i b) { return _mm_testz_si128(a, b); }
inline int _mm256_test_all_zeros(__m256i a, __m256i b) { return _mm256_testz_si256(a, b); }

inline int _mm_test_mix_ones_zeros(__m128i a, __m128i b) { return _mm_testnzc_si128(a, b); }
inline int _mm256_test_mix_ones_zeros(__m256i a, __m256i b) { return _mm256_testnzc_si256(a, b); }

#pragma endregion

#pragma region AES

extern __m128i _mm_aesdec_si128(__m128i, __m128i);
extern __m256i _mm256_aesdec_epi128(__m256i, __m256i);
extern __m128i _mm_aesdeclast_si128(__m128i, __m128i);
extern __m256i _mm256_aesdeclast_epi128(__m256i, __m256i);

extern __m128i _mm_aesenc_si128(__m128i, __m128i);
extern __m256i _mm256_aesenc_epi128(__m256i, __m256i);
extern __m128i _mm_aesenclast_si128(__m128i, __m128i);
extern __m256i _mm256_aesenclast_epi128(__m256i, __m256i);

extern __m128i _mm_aesimc_si128(__m128i);
extern __m128i _mm_aeskeygenassist_si128(__m128i, const int/);

#pragma endregion

#pragma region F16C

extern __m128 _mm_cvtph_ps(__m128i);
extern __m256 _mm256_cvtph_ps(__m128i);
extern __m128i _mm_cvtps_ph(__m128 /* m1 */, const int /* imm */);
extern __m128i _mm256_cvtps_ph(__m256, int);

#pragma endregion

#pragma region XSAVE

extern unsigned __int64 _xgetbv(unsigned int);
extern void _xsetbv(unsigned int, unsigned __int64);

extern void _xsave(void*, unsigned __int64);
extern void _xsave64(void*, unsigned __int64);

extern void _xsaveopt(void*, unsigned __int64);
extern void _xsaveopt64(void*, unsigned __int64);

extern void _xsavec(void*, unsigned __int64);
extern void _xsavec64(void*, unsigned __int64);

extern void _xrstor(const void*, unsigned __int64);
extern void _xrstor64(const void*, unsigned __int64);

extern void _xsaves(void*, unsigned __int64);
extern void _xsaves64(void*, unsigned __int64);

extern void _xrstors(const void*, unsigned __int64);
extern void _xrstors64(const void*, unsigned __int64);

extern void _fxsave(void*);
extern void _fxsave64(void*);

extern void _fxrstor(const void*);
extern void _fxrstor64(const void*);

#pragma endregion

#pragma region RDRAND

extern int _rdrand16_step(unsigned short*);
extern int _rdrand32_step(unsigned int*);
extern int _rdrand64_step(unsigned __int64*);

#pragma endregion

#pragma region FSGSBASE

extern unsigned __int32 _readfsbase_u32();
extern unsigned __int32 _readgsbase_u32();
extern unsigned __int64 _readfsbase_u64();
extern unsigned __int64 _readgsbase_u64();

extern void _writefsbase_u32(unsigned __int32);
extern void _writegsbase_u32(unsigned __int32);
extern void _writefsbase_u64(unsigned __int64);
extern void _writegsbase_u64(unsigned __int64);

#pragma endregion

#pragma region BMI1

extern unsigned __int32 _andn_u32(unsigned __int32, unsigned __int32);
extern unsigned __int64 _andn_u64(unsigned __int64, unsigned __int64);
extern unsigned __int32 _bextr_u32(unsigned __int32, unsigned int, unsigned int);
extern unsigned __int64 _bextr_u64(unsigned __int64, unsigned int, unsigned int);
extern unsigned __int32 _bextr2_u32(unsigned __int32, unsigned __int32);
extern unsigned __int64 _bextr2_u64(unsigned __int64, unsigned __int64);
extern unsigned __int32 _blsi_u32(unsigned __int32);
extern unsigned __int64 _blsi_u64(unsigned __int64);
extern unsigned __int32 _blsmsk_u32(unsigned __int32);
extern unsigned __int64 _blsmsk_u64(unsigned __int64);
extern unsigned __int32 _blsr_u32(unsigned __int32);
extern unsigned __int64 _blsr_u64(unsigned __int64);
extern unsigned __int16 _tzcnt_u16(unsigned __int16);
extern unsigned __int32 _tzcnt_u32(unsigned __int32);
extern unsigned __int64 _tzcnt_u64(unsigned __int64);

#pragma endregion

#pragma region BMI2

extern unsigned __int32 _bzhi_u32(unsigned __int32, unsigned int);
extern unsigned __int64 _bzhi_u64(unsigned __int64, unsigned int);
extern unsigned __int32 _mulx_u32(unsigned __int32, unsigned __int32, unsigned __int32*);
extern unsigned __int64 _mulx_u64(unsigned __int64, unsigned __int64, unsigned __int64*);
extern unsigned __int32 _pdep_u32(unsigned __int32, unsigned __int32);
extern unsigned __int64 _pdep_u64(unsigned __int64, unsigned __int64);
extern unsigned __int32 _pext_u32(unsigned __int32, unsigned __int32);
extern unsigned __int64 _pext_u64(unsigned __int64, unsigned __int64);

#pragma endregion

#pragma region HARDWARE-LOCK_ELISION

extern void _Store_HLERelease(volatile long*, long);
extern void _Store64_HLERelease(volatile __int64*, __int64);
extern void _StorePointer_HLERelease(void* volatile*, void*);

extern long _InterlockedExchange_HLEAcquire(volatile long*, long);
extern long _InterlockedExchange_HLERelease(volatile long*, long);
extern __int64 _InterlockedExchange64_HLEAcquire(volatile __int64*, __int64);
extern __int64 _InterlockedExchange64_HLERelease(volatile __int64*, __int64);
extern void* _InterlockedExchangePointer_HLEAcquire(void* volatile*, void*);
extern void* _InterlockedExchangePointer_HLERelease(void* volatile*, void*);

extern long _InterlockedCompareExchange_HLEAcquire(volatile long*, long, long);
extern long _InterlockedCompareExchange_HLERelease(volatile long*, long, long);
extern __int64 _InterlockedCompareExchange64_HLEAcquire(volatile __int64*, __int64, __int64);
extern __int64 _InterlockedCompareExchange64_HLERelease(volatile __int64*, __int64, __int64);
extern void* _InterlockedCompareExchangePointer_HLEAcquire(void* volatile*, void*, void*);
extern void* _InterlockedCompareExchangePointer_HLERelease(void* volatile*, void*, void*);

extern long _InterlockedExchangeAdd_HLEAcquire(volatile long*, long);
extern long _InterlockedExchangeAdd_HLERelease(volatile long*, long);
extern __int64 _InterlockedExchangeAdd64_HLEAcquire(volatile __int64*, __int64);
extern __int64 _InterlockedExchangeAdd64_HLERelease(volatile __int64*, __int64);

extern long _InterlockedAnd_HLEAcquire(volatile long*, long);
extern long _InterlockedAnd_HLERelease(volatile long*, long);
extern __int64 _InterlockedAnd64_HLEAcquire(volatile __int64*, __int64);
extern __int64 _InterlockedAnd64_HLERelease(volatile __int64*, __int64);

extern long _InterlockedOr_HLEAcquire(volatile long*, long);
extern long _InterlockedOr_HLERelease(volatile long*, long);
extern __int64 _InterlockedOr64_HLEAcquire(volatile __int64*, __int64);
extern __int64 _InterlockedOr64_HLERelease(volatile __int64*, __int64);

extern long _InterlockedXor_HLEAcquire(volatile long*, long);
extern long _InterlockedXor_HLERelease(volatile long*, long);
extern __int64 _InterlockedXor64_HLEAcquire(volatile __int64*, __int64);
extern __int64 _InterlockedXor64_HLERelease(volatile __int64*, __int64);

extern unsigned char _interlockedbittestandset_HLEAcquire(long*, long);
extern unsigned char _interlockedbittestandset_HLERelease(long*, long);
extern unsigned char _interlockedbittestandset64_HLEAcquire(__int64*, __int64);
extern unsigned char _interlockedbittestandset64_HLERelease(__int64*, __int64);

extern unsigned char _interlockedbittestandreset_HLEAcquire(long*, long);
extern unsigned char _interlockedbittestandreset_HLERelease(long*, long);
extern unsigned char _interlockedbittestandreset64_HLEAcquire(__int64*, __int64);
extern unsigned char _interlockedbittestandreset64_HLERelease(__int64*, __int64);

#pragma endregion

#pragma region LZCNT

extern unsigned __int32 _lzcnt_u32(unsigned __int32);
extern unsigned __int64 _lzcnt_u64(unsigned __int64);

#pragma endregion

#pragma region MOVBE

extern unsigned __int16 _load_be_u16(const void*);
extern unsigned __int32 _load_be_u32(const void*);
extern unsigned __int64 _load_be_u64(const void*);
inline __int16 _loadbe_i16(const void* p) { return (short)_load_be_u16(p); }
inline __int32 _loadbe_i32(const void* p) { return (int)_load_be_u32(p); }
inline __int64 _loadbe_i64(const void* p) { return (__int64)_load_be_u64(p); }

extern void _store_be_u16(void*, unsigned __int16);
extern void _store_be_u32(void*, unsigned __int32);
extern void _store_be_u64(void*, unsigned __int64);
inline void _storebe_i16(void* p, __int16 v) { _store_be_u16(p, (unsigned __int16)v); }
inline void _storebe_i32(void* p, __int32 v) { _store_be_u32(p, (unsigned __int32)v); }
inline void _storebe_i64(void* p, __int64 v) { _store_be_u64(p, (unsigned __int64)v); }

#pragma endregion

#pragma region MPX

extern void _bnd_chk_ptr_bounds(const void*, size_t);
extern void _bnd_chk_ptr_lbounds(const void*);
extern void _bnd_chk_ptr_ubounds(const void*);
extern void* _bnd_copy_ptr_bounds(const void*, const void*);
extern const void* _bnd_get_ptr_lbound(const void*);
extern const void* _bnd_get_ptr_ubound(const void*);
extern void* _bnd_init_ptr_bounds(const void*);
extern void* _bnd_load_ptr_bounds(const void**, const void*);
extern void* _bnd_narrow_ptr_bounds(const void*, const void*, size_t);
extern void* _bnd_set_ptr_bounds(const void*, size_t);
extern void _bnd_store_ptr_bounds(const void**, const void*);

#pragma endregion

#pragma region RTM

extern void _xabort(const unsigned);
extern unsigned _xbegin();
extern void _xend();
extern void _xsusldtrk();
extern void _xresldtrk();
extern unsigned char _xtest();

#pragma endregion

#pragma region SHA

extern __m128i _mm_sha1msg1_epu32(__m128i, __m128i);
extern __m128i _mm_sha1msg2_epu32(__m128i, __m128i);
extern __m128i _mm_sha1nexte_epu32(__m128i, __m128i);
extern __m128i _mm_sha1rnds4_epu32(__m128i, __m128i, const int);

extern __m128i _mm_sha256msg1_epu32(__m128i, __m128i);
extern __m128i _mm_sha256msg2_epu32(__m128i, __m128i);
extern __m128i _mm_sha256rnds2_epu32(__m128i, __m128i, __m128i);

#pragma endregion

#pragma region MISC

extern unsigned char _addcarryx_u32(unsigned char, unsigned __int32, unsigned __int32, unsigned __int32*);
extern unsigned char _addcarryx_u64(unsigned char, unsigned __int64, unsigned __int64, unsigned __int64*);

extern void _invpcid(unsigned int, void*);

extern int _rdseed16_step(unsigned __int16*);
extern int _rdseed32_step(unsigned __int32*);
extern int _rdseed64_step(unsigned __int64*);

extern unsigned __int32 _rorx_u32(unsigned __int32, const unsigned int);
extern unsigned __int64 _rorx_u64(unsigned __int64, const unsigned int);

extern __int32 _sarx_i32(__int32, unsigned int);
extern __int64 _sarx_i64(__int64, unsigned int);

extern unsigned __int32 _shlx_u32(unsigned __int32, unsigned int);
extern unsigned __int64 _shlx_u64(unsigned __int64, unsigned int);

extern unsigned __int32 _shrx_u32(unsigned __int32, unsigned int);
extern unsigned __int64 _shrx_u64(unsigned __int64, unsigned int);

#pragma endregion





// RDPID
extern unsigned int _rdpid_u32();
// PTWRITE
extern void _ptwrite32(unsigned int);
#if defined(_M_X64)
extern void _ptwrite64(unsigned __int64);
#endif // defined (_M_X64)

#pragma region AVX-VNNI

extern __m128i _mm_dpbusd_avx_epi32(__m128i, __m128i, __m128i);
extern __m256i _mm256_dpbusd_avx_epi32(__m256i, __m256i, __m256i);
extern __m128i _mm_dpbusds_avx_epi32(__m128i, __m128i, __m128i);
extern __m256i _mm256_dpbusds_avx_epi32(__m256i, __m256i, __m256i);
extern __m128i _mm_dpwssd_avx_epi32(__m128i, __m128i, __m128i);
extern __m256i _mm256_dpwssd_avx_epi32(__m256i, __m256i, __m256i);
extern __m128i _mm_dpwssds_avx_epi32(__m128i, __m128i, __m128i);
extern __m256i _mm256_dpwssds_avx_epi32(__m256i, __m256i, __m256i);

#pragma endregion

// MKTME
extern unsigned int _pconfig_u32(const int, size_t __data[]);
extern void _wbnoinvd();

// SGX
extern unsigned int _encls_u32(const int, size_t __data[]);
extern unsigned int _enclu_u32(const int, size_t __data[]);
extern unsigned int _enclv_u32(const int, size_t __data[]);

// Div & idiv
#if defined(_M_X64)
// _udiv128 is also declared in <intrin0.inl.h>
extern unsigned __int64 _udiv128(unsigned __int64 /* highdividend */, unsigned __int64 /* lowdividend */,
                                 unsigned __int64 /* divisor */, unsigned __int64* /* remainder */);
extern __int64 _div128(__int64 /* highdividend */, __int64 /* lowdividend */, __int64 /* divisor */,
                       __int64* /* remainder */);
#endif // defined (_M_X64)
extern unsigned _udiv64(unsigned __int64 /* dividend */, unsigned /* divisor */, unsigned* /* remainder */);
extern int _div64(__int64 /* dividend */, int /* divisor */, int* /* remainder */);

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
extern unsigned int _rdpkru_u32();
extern void _wrpkru(unsigned int);

// Enqueue stores
extern int _enqcmd(void* /* dst */, const void* /* src */);
extern int _enqcmds(void* /* dst */, const void* /* src */);

/*
 * Intel(R) Control-Flow Enforcement Technology (CET) shadow stack intrinsic functions
 */
extern void _incsspd(unsigned int);
extern unsigned int _rdsspd();
extern void _saveprevssp();
extern void _rstorssp(void*);
extern void _wrssd(unsigned int, void*);
extern void _wrussd(unsigned int, void*);
extern void _setssbsy();
extern void _clrssbsy(void*);
extern void* _switchssp(void*);
#if defined(_M_X64)
extern void _incsspq(unsigned __int64);
extern unsigned __int64 _rdsspq();
extern void _wrssq(unsigned __int64, void*);
extern void _wrussq(unsigned __int64, void*);
#endif

/*
 * Intrinsic functions for Short Vector Math Library (SVML)
 */

// vector integer divide and remainder

#define _mm_idiv_epi32 _mm_div_epi32
#define _mm_irem_epi32 _mm_rem_epi32
#define _mm_udiv_epi32 _mm_div_epu32
#define _mm_urem_epi32 _mm_rem_epu32
#define _mm256_idiv_epi32 _mm256_div_epi32
#define _mm256_irem_epi32 _mm256_rem_epi32
#define _mm256_udiv_epi32 _mm256_div_epu32
#define _mm256_urem_epi32 _mm256_rem_epu32


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
extern void _mm_cldemote(const void*);
#define _cldemote _mm_cldemote

/* Direct stores */
extern void _directstoreu_u32(void*, unsigned int);
#if defined(_M_X64)
extern void _directstoreu_u64(void*, unsigned __int64);
#endif /* defined (_M_X64) */
extern void _movdir64b(void*, const void*);

/* serialize and TSX load tracking */
extern void _serialize();
extern void _xsusldtrk();
extern void _xresldtrk();

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

#pragma region AVX-IFMA

extern __m128i _mm_madd52hi_avx_epu64(__m128i, __m128i, __m128i);
extern __m256i _mm256_madd52hi_avx_epu64(__m256i, __m256i, __m256i);
extern __m128i _mm_madd52lo_avx_epu64(__m128i, __m128i, __m128i);
extern __m256i _mm256_madd52lo_avx_epu64(__m256i, __m256i, __m256i);

#pragma endregion

#pragma region AVX-NE-CONVERT

extern __m128 _mm_bcstnebf16_ps(const __bfloat16*);
extern __m256 _mm256_bcstnebf16_ps(const __bfloat16*);
extern __m128 _mm_bcstnesh_ps(const void*);
extern __m256 _mm256_bcstnesh_ps(const void*);
extern __m128 _mm_cvtneebf16_ps(const __m128bh*);
extern __m256 _mm256_cvtneebf16_ps(const __m256bh*);
extern __m128 _mm_cvtneeph_ps(const __m128h*);
extern __m256 _mm256_cvtneeph_ps(const __m256h*);
extern __m128 _mm_cvtneobf16_ps(const __m128bh*);
extern __m256 _mm256_cvtneobf16_ps(const __m256bh*);
extern __m128 _mm_cvtneoph_ps(const __m128h*);
extern __m256 _mm256_cvtneoph_ps(const __m256h*);
extern __m128bh _mm_cvtneps_avx_pbh(__m128);
extern __m128bh _mm256_cvtneps_avx_pbh(__m256);

#pragma endregion

#pragma region AVX-VNNI-INT8

extern __m128i _mm_dpbssd_epi32(__m128i, __m128i, __m128i);
extern __m256i _mm256_dpbssd_epi32(__m256i, __m256i, __m256i);
extern __m128i _mm_dpbssds_epi32(__m128i, __m128i, __m128i);
extern __m256i _mm256_dpbssds_epi32(__m256i, __m256i, __m256i);
extern __m128i _mm_dpbsud_epi32(__m128i, __m128i, __m128i);
extern __m256i _mm256_dpbsud_epi32(__m256i, __m256i, __m256i);
extern __m128i _mm_dpbsuds_epi32(__m128i, __m128i, __m128i);
extern __m256i _mm256_dpbsuds_epi32(__m256i, __m256i, __m256i);
extern __m128i _mm_dpbuud_epi32(__m128i, __m128i, __m128i);
extern __m256i _mm256_dpbuud_epi32(__m256i, __m256i, __m256i);
extern __m128i _mm_dpbuuds_epi32(__m128i, __m128i, __m128i);
extern __m256i _mm256_dpbuuds_epi32(__m256i, __m256i, __m256i);

#pragma endregion

#pragma region RAO-INT

extern void _aadd_i32(__int32*, __int32);
extern void _aadd_i64(__int64*, __int64);
extern void _aand_i32(__int32*, __int32);
extern void _aand_i64(__int64*, __int64);
extern void _aor_i32(__int32*, __int32);
extern void _aor_i64(__int64*, __int64);
extern void _axor_i32(__int32*, __int32);
extern void _axor_i64(__int64*, __int64);

#pragma endregion


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
extern int _cmpccxadd_epi32(void*, int, int, const int);
extern __int64 _cmpccxadd_epi64(void*, __int64, __int64, const int);

#endif /* defined (_M_X64) */

#if defined __cplusplus
}; /* End "C" */
#endif /* defined __cplusplus */

#endif /* defined (_M_CEE_PURE) */
#endif /* __midl */
#endif /* _INCLUDED_IMM */
