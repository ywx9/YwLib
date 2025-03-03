#pragma once
#include "xyz.h"
#include "ywlib-iterator.h"

namespace yw {

template<char_type C> struct string_view {
  static_assert(same_as<C, remove_cv<C>>);
  using value_type = C;
  const C* _data;
  uint _size;

  string_view(nullptr_t) = delete;
  constexpr string_view() noexcept : _data(nullptr), _size(0) {}
  constexpr string_view(const string_view&) noexcept = default;
  constexpr string_view& operator=(const string_view&) noexcept = default;
  constexpr string_view(const C* Data) noexcept : _data(Data), _size(std::char_traits<C>::length(Data)) {}
  constexpr string_view(const C* Data, uint Size) noexcept : _data(Data), _size(Size) {}
  template<contiguous_iterator I, sized_sentinel_for<I> S> requires same_as<iter_value<I>, C> && (!convertible_to<S, uint>) //
  constexpr string_view(I i, S s) : _data(std::to_address(i)), _size(s - i) {}
  template<sized_contiguous_range R>
  requires same_as<iter_value<R>, C> && (!convertible_to<R, const C*>) && (!requires { declval<R&>().operator string_view<C>(); })
  constexpr string_view(R&& r) : _data(yw::data(r)), _size(yw::size(r)) {}

  constexpr operator std::basic_string_view<C>() const noexcept { return {_data, _size}; }

  constexpr const C* begin() const noexcept { return _data; }
  constexpr const C* end() const noexcept { return _data + _size; }
  constexpr bool empty() const noexcept { return _size == 0; }
  constexpr uint size() const noexcept { return _size; }
  constexpr const C* data() const noexcept { return _data; }
  constexpr const C& operator[](uint Index) const { return _data[Index]; }
  constexpr const C& front() const { return _data[0]; }
  constexpr const C& back() const { return _data[_size - 1]; }

  constexpr string_view substr(uint Pos, uint Count = npos) const {
    if (Pos >= _size) return {};
    if (Count == npos) return {_data + Pos, _size - Pos};
    return {_data + Pos, std::min(Count, _size - Pos)};
  }
  constexpr void remove_prefix(uint N) {
    if (N < _size) _data += N, _size -= N;
    else _data = nullptr, _size = 0;
  }
  constexpr void remove_suffix(uint N) {
    if (N < _size) _size -= N;
    else _data = nullptr, _size = 0;
  }
  friend constexpr void swap(string_view& a, string_view& b) noexcept {
    std::ranges::swap(a._data, b._data);
    std::ranges::swap(a._size, b._size);
  }

  friend constexpr bool operator==(const string_view& a, const string_view& b) noexcept {
    return a._size == b._size && std::char_traits<C>::compare(a._data, b._data, a._size) == 0;
  }
  friend constexpr auto operator<=>(const string_view& a, const string_view& b) noexcept {
    const auto bb = a._size <=> b._size;
    const uint nn = bb < 0 ? a._size : b._size;
    for (uint i{}; i < nn; ++i)
      if (const auto c = uintcast(a[i]) <=> uintcast(b[i]); c != 0) return c;
    return bb;
  }
  template<typename Tr> friend auto& operator<<(std::basic_ostream<C, Tr>& os, const string_view& sv) { return os.write(sv._data, sv._size); }
};

template<is_pointer P> string_view(P) -> string_view<iter_value<P>>;
template<is_pointer P> string_view(P, uint) -> string_view<iter_value<P>>;
template<contiguous_iterator I, sized_sentinel_for<I> S> string_view(I, S) -> string_view<iter_value<I>>;
template<sized_contiguous_range R> string_view(R&&) -> string_view<iter_value<R>>;

using str_view = string_view<char>;
using wstr_view = string_view<wchar>;

template<typename T, typename C = iter_value<T>>
concept stringable = convertible_to<T&, string_view<C>>;
}

namespace std { //  poqpoqpoqpoqpoqpoqpoqpoqpoqpoqpoqpoqpoqpoqpoqpoqpoqpoqpoqpoq
template<typename C> struct formatter<yw::string_view<C>, C> : formatter<basic_string_view<C>, C> {
  auto format(const yw::string_view<C>& sv, auto& ctx) const { return formatter<basic_string_view<C>, C>::format(sv, ctx); }
};
} // bodbodbodbodbodbodbodbodbodbodbodbodbodbodbodbodbodbodbodbodbodbodbodbodbod

namespace std::ranges { //   poqpoqpoqpoqpoqpoqpoqpoqpoqpoqpoqpoqpoqpoqpoqpoqpoq
template<typename C> constexpr bool enable_borrowed_range<yw::string_view<C>> = true;
template<typename C> constexpr bool enable_view<yw::string_view<C>> = true;
} // bodbodbodbodbodbodbodbodbodbodbodbodbodbodbodbodbodbodbodbodbodbodbodbodbod
