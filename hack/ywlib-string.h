#pragma once
#include "xyz.h"
#include "ywlib-string_view.h"

namespace yw {

template<typename T> using string = std::basic_string<T>;
using str = string<char>;
using wstr = string<wchar>;

inline constexpr auto is_digit = []<char_type C>(const C c) noexcept { return uintcast(c ^ C('0')) < 10; };
inline constexpr auto is_blank = []<char_type C>(const C c) noexcept { return c == C(' ') || c == C('\t'); };

inline constexpr auto strlen = []<stringable S>(S&& s) -> uint {
  if constexpr (is_array<remove_reference<S>>) return std::extent_v<remove_reference<S>> - 1;
  else if constexpr (is_pointer<remove_reference<S>>) return std::char_traits<iter_value<S>>::length(s);
  else if constexpr (specialization_of<remove_cvref<S>, std::basic_string>) return s.size();
  else if constexpr (specialization_of<remove_cvref<S>, std::basic_string_view>) return s.size();
  else return string_view<iter_value<S>>(s).size();
};

inline constexpr auto format = []<typename... Ts>(str_view fmt, Ts&&... as) { return std::vformat(fmt, std::make_format_args(as...)); };
inline constexpr auto wformat = []<typename... Ts>(wstr_view fmt, Ts&&... as) { return std::vformat(fmt, std::make_wformat_args(as...)); };

inline constexpr auto print = []<typename T, typename... Ts>(T&& a, Ts&&... as) {
  if constexpr (sizeof...(Ts) == 0) {
    if constexpr (stringable<T, char>) std::cout << str_view(a);
    else if constexpr (requires { std::cout << a; }) std::cout << a;
    else always_false<T>;
  } else if constexpr (stringable<T, char>) {
    std::cout << std::vformat(str_view(a), std::make_format_args(as...));
  } else always_false<T>;
};
inline constexpr auto wprint = []<typename T, typename... Ts>(T&& a, Ts&&... as) {
  if constexpr (sizeof...(Ts) == 0) {
    if constexpr (stringable<T, wchar>) std::wcout << wstr_view(a);
    else if constexpr (requires { std::wcout << a; }) std::wcout << a;
    else always_false<T>;
  } else if constexpr (stringable<T, wchar>) {
    std::wcout << std::vformat(wstr_view(a), std::make_wformat_args(as...));
  } else always_false<T>;
};
inline constexpr auto println = []<typename T, typename... Ts>(T&& a, Ts&&... as) {
  if constexpr (sizeof...(Ts) == 0) {
    if constexpr (stringable<T, char>) std::cout << a << std::endl;
    else if constexpr (requires { std::cout << a; }) std::cout << a << std::endl;
    else always_false<T>;
  } else if constexpr (stringable<T, char>) {
    std::cout << std::vformat(str_view(a), std::make_format_args(as...)) << std::endl;
  } else always_false<T>;
};
inline constexpr auto wprintln = []<typename T, typename... Ts>(T&& a, Ts&&... as) {
  if constexpr (sizeof...(Ts) == 0) {
    if constexpr (stringable<T, wchar>) std::wcout << a << std::endl;
    else if constexpr (requires { std::wcout << a; }) std::wcout << a << std::endl;
    else always_false<T>;
  } else if constexpr (stringable<T, wchar>) {
    std::wcout << std::vformat(wstr_view(a), std::make_wformat_args(as...)) << std::endl;
  } else always_false<T>;
};

template<char_type C> constexpr auto cvt = []<stringable S>(S&& s) -> string<C> {
  if constexpr (same_as<S, string<C>>) return static_cast<S&&>(s);
  using In = iter_value<S>;
  string_view<In> sv(s);
  if constexpr (sizeof(In) == sizeof(C)) return string<C>(sv.data(), sv.size());
  string<C> r(sv.size() * (sizeof(In) < sizeof(C) ? 1 : sizeof(In) / sizeof(C)), C{});
  auto p = r.data();
  for (auto i(sv.begin()), e(sv.end()); i < e; ++i) {
    const auto c = uintcast(*i);
    if constexpr (sizeof(In) == 1) {
      if (c < 0x80u) *p++ = C(c);
      else if (c < 0xe0f) *p++ = C((c & 0x1fu) << 6 | (uintcast(*++i) & 0x3fu));
      else if (c < 0xf0u) *p++ = C((c & 0x0fu) << 12 | (uintcast(*++i) & 0x3fu) << 6 | (uintcast(*++i) & 0x3fu));
      else {
        uint4 u = (c & 0x07u) << 18 | (uintcast(*++i) & 0x3fu) << 12 | (uintcast(*++i) & 0x3fu) << 6 | (uintcast(*++i) & 0x3fu);
        if constexpr (sizeof(C) == 4) *p++ = C(u);
        else *p++ = C(0xd800 | (u >> 10)), *p++ = C(0xdc00 | (u & 0x3ff));
      }
    } else if constexpr (sizeof(In) == 2) {
      if (c < 0xd800u || c >= 0xe000u) {
        if constexpr (sizeof(C) == 1) {
          if (c < 0x80) *p++ = C(c);
          else if (c < 0x800) *p++ = C(0xc0 | (c >> 6)), *p++ = C(0x80 | (c & 0x3f));
          else *p++ = C(0xe0 | (c >> 12)), *p++ = C(0x80 | ((c >> 6) & 0x3f)), *p++ = C(0x80 | (c & 0x3f));
        } else *p++ = C(c);
      } else {
        uint4 u = (c & 0x3ffu) << 10 | (uintcast(*++i) & 0x3ffu);
        if constexpr (sizeof(C) == 4) *p++ = C(u);
        else *p++ = C(0xf0 | (u >> 18)), *p++ = C(0x80 | ((u >> 12) & 0x3f)), *p++ = C(0x80 | ((u >> 6) & 0x3f)), *p++ = C(0x80 | (u & 0x3f));
      }
    } else if constexpr (sizeof(In) == 4) {
      if constexpr (sizeof(C) == 1) {
        if (c < 0x80) *p++ = C(c);
        else if (c < 0x800) *p++ = C(0xc0 | (c >> 6)), *p++ = C(0x80 | (c & 0x3f));
        else if (c < 0x10000) *p++ = C(0xe0 | (c >> 12)), *p++ = C(0x80 | ((c >> 6) & 0x3f)), *p++ = C(0x80 | (c & 0x3f));
        else *p++ = C(0xf0 | (c >> 18)), *p++ = C(0x80 | ((c >> 12) & 0x3f)), *p++ = C(0x80 | ((c >> 6) & 0x3f)), *p++ = C(0x80 | (c & 0x3f));
      } else {
        if (c < 0x10000) *p++ = C(c);
        else *p++ = C(0xd800 | (c >> 10)), *p++ = C(0xdc00 | (c & 0x3ff));
      }
    }
  }
};
}
