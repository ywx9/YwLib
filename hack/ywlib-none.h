#pragma once
#include "xyz.h"
#include "ywlib-string_view.h"

namespace yw {

struct none {
  constexpr none() noexcept = default;
  constexpr none(auto&&...) noexcept {}
  constexpr none& operator=(auto&&) noexcept { return *this; }
  explicit constexpr operator bool() const noexcept { return false; }
  constexpr none operator()() const noexcept { return {}; }
  friend constexpr bool operator==(none, none) noexcept { return false; }
  friend constexpr auto operator<=>(none, none) noexcept { return std::partial_ordering::unordered; }
  friend constexpr none operator+(none) noexcept { return {}; }
  friend constexpr none operator-(none) noexcept { return {}; }
  friend constexpr none operator+(none, none) noexcept { return {}; }
  friend constexpr none operator-(none, none) noexcept { return {}; }
  friend constexpr none operator*(none, none) noexcept { return {}; }
  friend constexpr none operator/(none, none) noexcept { return {}; }
  constexpr none& operator+=(none) noexcept { return *this; }
  constexpr none& operator-=(none) noexcept { return *this; }
  constexpr none& operator*=(none) noexcept { return *this; }
  constexpr none& operator/=(none) noexcept { return *this; }

  template<char_type C> friend constexpr string_view<C> to_string(const none) {
    constexpr auto array[] = {C{'n'}, C{'o'}, C{'n'}, C{'e'}, C{'\0'}};
    return {array, 4};
  }
  template<typename C, typename Tr> friend auto& operator<<(std::basic_ostream<C, Tr>& os, none) {
    return os << to_string<C>(none{});
  }
};

template<typename T> concept is_none = same_as<remove_cv<T>, none>;
}
namespace std {
template<typename T> struct common_type<yw::none, T> : type_identity<yw::none> {};
template<typename T> struct common_type<T, yw::none> : type_identity<yw::none> {};
}
