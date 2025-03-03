#pragma once
#include "xyz.h"
#include "ywlib-iterator.h"

namespace yw {

template<typename T, uint N = npos> class array {
  static_assert(N != 0 && N != npos);
public:
  using value_type = T;
  static constexpr uint count = N;
  T _[N]{};

  constexpr operator add_lvref<T[N]>() noexcept { return _; }
  constexpr operator add_lvref<const T[N]>() const noexcept { return _; }

  constexpr bool empty() const noexcept { return false; }
  constexpr uint size() const noexcept { return N; }
  constexpr T* data() noexcept { return _; }
  constexpr const T* data() const noexcept { return _; }
  constexpr T* begin() noexcept { return _; }
  constexpr const T* begin() const noexcept { return _; }
  constexpr T* end() noexcept { return _ + N; }
  constexpr const T* end() const noexcept { return _ + N; }
  constexpr T& front() noexcept { return *_; }
  constexpr const T& front() const noexcept { return *_; }
  constexpr T& back() noexcept { return _[N - 1]; }
  constexpr const T& back() const noexcept { return _[N - 1]; }
  constexpr T& operator[](uint I) { return _[I]; }
  constexpr const T& operator[](uint I) const { return _[I]; }

  template<uint I> requires (I < N) constexpr T& get() & noexcept { return _[I]; }
  template<uint I> requires (I < N) constexpr T&& get() && noexcept { return mv(_[I]); }
  template<uint I> requires (I < N) constexpr const T& get() const& noexcept { return _[I]; }
  template<uint I> requires (I < N) constexpr const T&& get() const&& noexcept { return mv(_[I]); }
};

template<typename T> class array<T, 0> {
public:
  using value_type = T;
  static constexpr uint count = 0;
  constexpr uint size() const noexcept { return 0; }
  constexpr bool empty() const noexcept { return true; }
  constexpr T* data() noexcept { return nullptr; }
  constexpr const T* data() const noexcept { return nullptr; }
  constexpr T* begin() noexcept { return nullptr; }
  constexpr const T* begin() const noexcept { return nullptr; }
  constexpr T* end() noexcept { return nullptr; }
  constexpr const T* end() const noexcept { return nullptr; }
  template<uint I> constexpr void get() const = delete;
};

template<typename T> class array<T, npos> : public std::vector<T> {
public:
  using value_type = T;
  constexpr array() noexcept = default;
  constexpr explicit array(uint n) : std::vector<T>(n) {}
  constexpr array(uint n, const T& v) : std::vector<T>(n, v) {}
  template<input_iterator I> requires convertible_to<iter_value<I>, T> && (!convertible_to<I, uint> || !convertible_to<I, const T&>) //
  constexpr array(I i, I s) : std::vector<T>(mv(i), mv(s)) {}
  template<input_iterator I, sentinel_for<I> S, typename C = std::common_iterator<I, S>>
  requires convertible_to<iter_value<I>, T> && (!same_as<I, S>) && (!convertible_to<I, uint> || !convertible_to<S, const T&>) //
  constexpr array(I i, S s) : std::vector<T>(C(mv(i)), C(mv(s))) {}
  template<input_range R> requires convertible_to<iter_value<R>, T> && (!convertible_to<R, uint>) && (!requires { declval<R&>().operator array<T>(); })
  constexpr array(R&& r) : std::vector<T>(yw::begin(r), yw::end(r)) {}
};

static_assert(sizeof(array<int>) == sizeof(std::vector<int>));

template<typename T, convertible_to<T>... Ts> array(T, Ts...) -> array<T, 1 + sizeof...(Ts)>;
template<typename T> array(uint, const T&) -> array<T, npos>;
template<iterator I, sentinel_for<I> S> array(I, S) -> array<iter_value<I>, npos>;
template<range R> array(R&&) -> array<iter_value<R>, npos>;
}
namespace std {
template<typename T, uint N> requires (N != yw::npos) struct tuple_size<yw::array<T, N>> : integral_constant<uint, N> {};
template<uint I, typename T, uint N> requires (N != yw::npos) struct tuple_element<I, yw::array<T, N>> : type_identity<T> {};
}
