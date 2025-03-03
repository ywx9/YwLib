#pragma once
#include "xyz.h"

namespace yw {

template<typename T> struct vector2 {
  using value_type = T;
  static constexpr uint count = 2;
  T x{}, y{};

  constexpr vector2() noexcept = default;
  explicit constexpr vector2(const T& v) noexcept : x(v), y(v) {}
  template<convertible_to<T> U, convertible_to<T> V> constexpr vector2(U&& X, V&& Y) noexcept : x(static_cast<U&&>(X)), y(static_cast<V&&>(Y)) {}

  constexpr bool empty() const noexcept { return false; }
  constexpr uint size() const noexcept { return count; }
  T* data() noexcept { return &x; }
  const T* data() const noexcept { return &x; }
  T* begin() noexcept { return &x; }
  const T* begin() const noexcept { return &x; }
  T* end() noexcept { return &x + count; }
  const T* end() const noexcept { return &x + count; }
  constexpr T& front() noexcept { return x; }
  constexpr const T& front() const noexcept { return x; }
  constexpr T& back() noexcept { return y; }
  constexpr const T& back() const noexcept { return y; }
  T& operator[](uint I) { return *(&x + I); }
  const T& operator[](uint I) const { return *(&x + I); }

  template<uint I> requires (I < 2) constexpr T& get() & noexcept { return select<I>(x, y); }
  template<uint I> requires (I < 2) constexpr const T& get() const& noexcept { return select<I>(x, y); }
  template<uint I> requires (I < 2) constexpr T&& get() && noexcept { return static_cast<T&&>(select<I>(x, y)); }
  template<uint I> requires (I < 2) constexpr const T&& get() const&& noexcept { return static_cast<const T&&>(select<I>(x, y)); }
};

template<typename T1, typename T2> vector2(T1&&, T2&&) -> vector2<float>;

template<typename T> struct vector3 {
  using value_type = T;
  static constexpr uint count = 3;
  T x{}, y{}, z{};

  constexpr vector3() noexcept = default;
  explicit constexpr vector3(const T& v) noexcept : x(v), y(v), z(v) {}
  template<convertible_to<T> U, convertible_to<T> V, convertible_to<T> W> constexpr vector3(U&& X, V&& Y, W&& Z) noexcept
    : x(static_cast<U&&>(X)), y(static_cast<V&&>(Y)), z(static_cast<W&&>(Z)) {}

  constexpr bool empty() const noexcept { return false; }
  constexpr uint size() const noexcept { return count; }
  T* data() noexcept { return &x; }
  const T* data() const noexcept { return &x; }
  T* begin() noexcept { return &x; }
  const T* begin() const noexcept { return &x; }
  T* end() noexcept { return &x + count; }
  const T* end() const noexcept { return &x + count; }
  constexpr T& front() noexcept { return x; }
  constexpr const T& front() const noexcept { return x; }
  constexpr T& back() noexcept { return z; }
  constexpr const T& back() const noexcept { return z; }
  T& operator[](uint I) { return *(&x + I); }
  const T& operator[](uint I) const { return *(&x + I); }

  template<uint I> requires (I < 3) constexpr T& get() & noexcept { return select<I>(x, y, z); }
  template<uint I> requires (I < 3) constexpr const T& get() const& noexcept { return select<I>(x, y, z); }
  template<uint I> requires (I < 3) constexpr T&& get() && noexcept { return static_cast<T&&>(select<I>(x, y, z)); }
  template<uint I> requires (I < 3) constexpr const T&& get() const&& noexcept { return static_cast<const T&&>(select<I>(x, y, z)); }
};

template<typename T1, typename T2, typename T3> vector3(T1&&, T2&&, T3&&) -> vector3<float>;

template<typename T> struct vector4 {
  using value_type = T;
  static constexpr uint count = 4;
  T x{}, y{}, z{}, w{};

  constexpr vector4() noexcept = default;
  explicit constexpr vector4(const T& v) noexcept : x(v), y(v), z(v), w(v) {}
  template<convertible_to<T> X, convertible_to<T> Y, convertible_to<T> Z, convertible_to<T> W> //
  constexpr vector4(X&& x, Y&& y, Z&& z, W&& w) noexcept                                       //
    : x(static_cast<X&&>(x)), y(static_cast<Y&&>(y)), z(static_cast<Z&&>(z)), w(static_cast<W&&>(w)) {}

  constexpr bool empty() const noexcept { return false; }
  constexpr uint size() const noexcept { return count; }
  T* data() noexcept { return &x; }
  const T* data() const noexcept { return &x; }
  T* begin() noexcept { return &x; }
  const T* begin() const noexcept { return &x; }
  T* end() noexcept { return &x + count; }
  const T* end() const noexcept { return &x + count; }
  constexpr T& front() noexcept { return x; }
  constexpr const T& front() const noexcept { return x; }
  constexpr T& back() noexcept { return w; }
  constexpr const T& back() const noexcept { return w; }
  T& operator[](uint I) { return *(&x + I); }
  const T& operator[](uint I) const { return *(&x + I); }

  template<uint I> requires (I < 4) constexpr T& get() & noexcept { return select<I>(x, y, z, w); }
  template<uint I> requires (I < 4) constexpr const T& get() const& noexcept { return select<I>(x, y, z, w); }
  template<uint I> requires (I < 4) constexpr T&& get() && noexcept { return static_cast<T&&>(select<I>(x, y, z, w)); }
  template<uint I> requires (I < 4) constexpr const T&& get() const&& noexcept { return static_cast<const T&&>(select<I>(x, y, z, w)); }
};

template<typename T1, typename T2, typename T3, typename T4> vector4(T1&&, T2&&, T3&&, T4&&) -> vector4<float>;
}
namespace std {
template<typename T> struct tuple_size<yw::vector2<T>> : integral_constant<uint, 2> {};
template<typename T> struct tuple_size<yw::vector3<T>> : integral_constant<uint, 3> {};
template<typename T> struct tuple_size<yw::vector4<T>> : integral_constant<uint, 3> {};
template<uint I, typename T> struct tuple_element<I, yw::vector2<T>> : type_identity<T> {};
template<uint I, typename T> struct tuple_element<I, yw::vector3<T>> : type_identity<T> {};
template<uint I, typename T> struct tuple_element<I, yw::vector4<T>> : type_identity<T> {};
}
