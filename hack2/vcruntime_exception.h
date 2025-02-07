#pragma once // clang-format off
#include "abc.h"

extern "C" {
using terminate_handler = void(__cdecl*)();
[[noreturn]] void __cdecl terminate() throw();
terminate_handler __cdecl set_terminate(terminate_handler) throw();
terminate_handler __cdecl _get_terminate();
}

__ywstd_cfunc_begin
struct __std_exception_data { const char* _What; bool _DoFree; };
void __cdecl __std_exception_copy(const __std_exception_data*, __std_exception_data*);
void __cdecl __std_exception_destroy(__std_exception_data*);
__ywstd_cfunc_end

namespace std {

class exception {
  _CSTD __std_exception_data _data;
public:
  virtual ~exception() noexcept { _CSTD __std_exception_destroy(&_data); }
  exception() noexcept : _data() {}
  exception(const char* const s, int) noexcept : _data() { _data._What = s; }
  exception(exception const& e) noexcept : _data() { _CSTD __std_exception_copy(&e._data, &_data); }
  explicit exception(const char* const s) noexcept : _data() {
    _CSTD __std_exception_data i{s, true};
    _CSTD __std_exception_copy(&i, &_data);
  }

  exception& operator=(exception const& e) noexcept {
    if (this == &e) return *this;
    _CSTD __std_exception_destroy(&_data);
    _CSTD __std_exception_copy(&e._data, &_data);
    return *this;
  }
  [[nodiscard]] virtual const char* what() const { return _data._What ? _data._What : "Unknown exception"; }
};

class bad_exception : public exception {
public: bad_exception() noexcept : exception("bad exception", 1) {}
};

class bad_alloc : public exception {
  friend class bad_array_new_length;
  bad_alloc(const char* const s) noexcept : exception(s, 1) {}
public:
  bad_alloc() noexcept : exception("bad allocation", 1) {}
};

class bad_array_new_length : public bad_alloc {
public: bad_array_new_length() noexcept : bad_alloc("bad array new length") {}
};
}
