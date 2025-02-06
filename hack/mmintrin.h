#pragma once
#include "abc.h"

union __declspec(intrin_type) alignas(8) __m64 {
  unsigned long long m64_u64;
  float m64_f32[2];
  signed char m64_i8[8];
  short m64_i16[4];
  int m64_i32[2];
  long long m64_i64;
  unsigned char m64_u8[8];
  unsigned short m64_u16[4];
  unsigned int m64_u32[2];
};
