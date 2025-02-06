#pragma once
#include "abc.h"

__ywstd_cfunc_begin // clang-format off

using terminate_handler = void(__cdecl*)();
[[noreturn]] void __cdecl terminate() throw();
terminate_handler __cdecl set_terminate(terminate_handler) throw();
terminate_handler __cdecl _get_terminate();

struct __std_exception_data { const char* _What; bool _DoFree; };
void __cdecl __std_exception_copy(const __std_exception_data*, __std_exception_data*);
void __cdecl __std_exception_destroy(__std_exception_data*);

__ywstd_cfunc_end // clang-format on

namespace std {

class exception {
  _CSTD __std_exception_data _data;
public:
  virtual ~exception() noexcept { _CSTD __std_exception_destroy(&_data); }
  exception() noexcept : _data() {}
  exception(const char* const message, int) noexcept : _data() { _data._What = message; }
  exception(exception const& _Other) noexcept : _data() { _CSTD __std_exception_copy(&_Other._data, &_data); }
  explicit exception(const char* const message) noexcept : _data() {
    _CSTD __std_exception_data _InitData = {message, true};
    _CSTD __std_exception_copy(&_InitData, &_data);
  }

  exception& operator=(exception const& _Other) noexcept {
    if (this == &_Other) return *this;
    _CSTD __std_exception_destroy(&_data);
    _CSTD __std_exception_copy(&_Other._data, &_data);
    return *this;
  }
  [[nodiscard]] virtual const char* what() const { return _data._What ? _data._What : "Unknown exception"; }
};



class bad_exception : public exception {
public: bad_exception() noexcept : exception("bad exception", 1) {}
};

class bad_alloc : public exception {
  friend class bad_array_new_length;
  bad_alloc(const char* const message) noexcept : exception(message, 1) {}
public:
  bad_alloc() noexcept : exception("bad allocation", 1) {}
};

class bad_array_new_length : public bad_alloc {
public: bad_array_new_length() noexcept : bad_alloc("bad array new length") {}
};
}
