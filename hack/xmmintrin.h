#pragma once
#include "abc.h"

extern "C" {

__ywstd_export union __declspec(intrin_type) alignas(8) __m64 {
  unsigned __int64 m64_u64;
  float            m64_f32[2];
  __int8           m64_i8[8];
  __int16          m64_i16[4];
  __int32          m64_i32[2];
  __int64          m64_i64;
  unsigned __int8  m64_u8[8];
  unsigned __int16 m64_u16[4];
  unsigned __int32 m64_u32[2];
};

__ywstd_export union __declspec(intrin_type) alignas(16) __m128 {
  float            m128_f32[4];
  unsigned __int64 m128_u64[2];
  __int8           m128_i8[16];
  __int16          m128_i16[8];
  __int32          m128_i32[4];
  __int64          m128_i64[2];
  unsigned __int8  m128_u8[16];
  unsigned __int16 m128_u16[8];
  unsigned __int32 m128_u32[4];
};

}
