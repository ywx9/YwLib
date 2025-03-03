#pragma once
#include "hack/xyz.h"

namespace yw {

template<typename I> concept iterator = std::input_or_output_iterator<I>;
template<typename R> concept range = std::ranges::range<R>;
template<range R> using iterator_t = std::ranges::iterator_t<R>;
template<range R> using sentinel_t = std::ranges::sentinel_t<R>;

inline constexpr auto begin = []<range R>(R&& r) noexcept(noexcept(std::ranges::begin(static_cast<R&&>(r)))) //
  requires requires { std::ranges::begin(static_cast<R&&>(r)); } { return std::ranges::begin(static_cast<R&&>(r)); };
inline constexpr auto end = []<range R>(R&& r) noexcept(noexcept(std::ranges::end(static_cast<R&&>(r)))) //
  requires requires { std::ranges::end(static_cast<R&&>(r)); } { return std::ranges::end(static_cast<R&&>(r)); };
inline constexpr auto size = []<range R>(R&& r) noexcept(noexcept(std::ranges::size(static_cast<R&&>(r)))) //
  requires requires { std::ranges::size(static_cast<R&&>(r)); } { return std::ranges::size(static_cast<R&&>(r)); };
inline constexpr auto data = []<range R>(R&& r) noexcept(noexcept(std::ranges::data(static_cast<R&&>(r)))) //
  requires requires { std::ranges::data(static_cast<R&&>(r)); } { return std::ranges::data(static_cast<R&&>(r)); };

namespace _ { // clang-format off
template<typename T> struct _iter_types {};
template<iterator I> struct _iter_types<I> {
  using difference = std::iter_difference_t<I>; using value = std::iter_value_t<I>;
  using ref = std::iter_reference_t<I>; using rvref = std::iter_rvalue_reference_t<I>; };
template<range R> struct _iter_types<R> : _iter_types<iterator_t<R>> {};
} // clang-format on

template<typename T> requires iterator<remove_reference<T>> || range<T> using iter_value = typename _::_iter_types<remove_reference<T>>::value;
template<typename T> requires iterator<remove_reference<T>> || range<T> using iter_ref = typename _::_iter_types<remove_reference<T>>::ref;
template<typename T> requires iterator<remove_reference<T>> || range<T> using iter_rvref = typename _::_iter_types<remove_reference<T>>::rvref;
template<typename T> requires iterator<remove_reference<T>> || range<T> using iter_difference = typename _::_iter_types<remove_reference<T>>::difference;

template<typename I, typename T> concept output_iterator = std::output_iterator<I, T>;
template<typename I> concept input_iterator = std::input_iterator<I>;
template<typename I> concept forward_iterator = std::forward_iterator<I>;
template<typename I> concept bidirectional_iterator = std::bidirectional_iterator<I>;
template<typename I> concept random_access_iterator = std::random_access_iterator<I>;
template<typename I> concept contiguous_iterator = std::contiguous_iterator<I>;

template<typename S, typename I> concept sentinel_for = std::sentinel_for<S, I>;
template<typename S, typename I> concept sized_sentinel_for = std::sized_sentinel_for<S, I>;

template<typename R, typename T> concept output_range = std::output_iterator<iterator_t<R>, T>;
template<typename R> concept input_range = std::ranges::input_range<R>;
template<typename R> concept forward_range = std::ranges::forward_range<R>;
template<typename R> concept bidirectional_range = std::ranges::bidirectional_range<R>;
template<typename R> concept random_access_range = std::ranges::random_access_range<R>;
template<typename R> concept contiguous_range = std::ranges::contiguous_range<R>;

template<typename R> concept sized_range = range<R> && std::ranges::sized_range<R>;
template<typename R> concept sized_contiguous_range = sized_range<R> && contiguous_range<R>;
}
