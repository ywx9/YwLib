#pragma once
#include "abc.h"
#include "vcruntime_exception.h"

extern "C++" {

struct __type_info_node;
extern __type_info_node __type_info_root_node;
}

__ywstd_cfunc_begin

  struct __std_type_info_data {
  const char* _UndecoratedName;
  const char _DecoratedName[1];
  __std_type_info_data() = delete;
  __std_type_info_data(const __std_type_info_data&) = delete;
  __std_type_info_data(__std_type_info_data&&) = delete;
  __std_type_info_data& operator=(const __std_type_info_data&) = delete;
  __std_type_info_data& operator=(__std_type_info_data&&) = delete;
};

int __cdecl __std_type_info_compare(const __std_type_info_data*, const __std_type_info_data*);
size_t __cdecl __std_type_info_hash(const __std_type_info_data*);
const char* __cdecl __std_type_info_name(__std_type_info_data*, __type_info_node*);

__ywstd_cfunc_end

extern "C++" {

class type_info {
mutable _CSTD __std_type_info_data _Data;
public:
  virtual ~type_info() noexcept;
  type_info(const type_info&) = delete;
  type_info& operator=(const type_info&) = delete;
  size_t hash_code() const noexcept { return _CSTD __std_type_info_hash(&_Data); }
  constexpr bool operator==(const type_info& ti) const noexcept {
    if (__builtin_is_constant_evaluated()) { return &_Data == &ti._Data; }
    return _CSTD __std_type_info_compare(&_Data, &ti._Data) == 0;
  }
  bool before(const type_info& ti) const noexcept { return _CSTD __std_type_info_compare(&_Data, &ti._Data) < 0; }
  const char* name() const noexcept { return _CSTD __std_type_info_name(&_Data, &__type_info_root_node); }
  const char* raw_name() const noexcept { return _Data._DecoratedName; }
};
}

namespace std {

using ::type_info;

class bad_cast : public exception {
  bad_cast(const char* const s, int) noexcept : exception(s, 1) {}
public:
  bad_cast() noexcept : exception("bad cast", 1) {}
  static bad_cast __construct_from_string_literal(const char* const s) noexcept { return bad_cast(s, 1); }
};

class bad_typeid : public exception {
  friend class __non_rtti_object;
  bad_typeid(const char* const s, int) noexcept : exception(s, 1) { }
public:
  bad_typeid() noexcept : exception("bad typeid", 1) {}
  static bad_typeid __construct_from_string_literal(const char* const s) noexcept { return bad_typeid(s, 1); }
};

class __non_rtti_object : public bad_typeid {
  __non_rtti_object(const char* const s, int) noexcept : bad_typeid(s, 1) {}
public:
  static __non_rtti_object __construct_from_string_literal(const char* const s) noexcept {
    return __non_rtti_object(s, 1);
  }
};
}
