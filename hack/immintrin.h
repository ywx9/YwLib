/// \file immintrin.h
/// \copyright (c) 2025 ywx9.com

#pragma once

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

#pragma region[xmmintrin]-------------------------------------------------------
export extern "C" {}
#pragma endregion //-------------------------------------------------[xmmintrin]
