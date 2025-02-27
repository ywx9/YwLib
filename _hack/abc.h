#pragma once
// clang-format off



#pragma region YWLIB-CORE ------------------------------------------------------

#define uint size_t
#define wchar wchar_t

extern "C" {
#if not (__ywstd_is_exported or __ywstd_is_imported)
namespace ywstd {
#endif
void* __cdecl memcpy(void*, const void*, size_t);
void* __cdecl memset(void*, int, size_t);
}
#if not (__ywstd_is_exported or __ywstd_is_imported)

}
#endif

namespace yw {

using int1 = signed char;
using int2 = short;
using int4 = int;
using int8 = long long;
using uint1 = unsigned char;
using uint2 = unsigned short;
using uint4 = unsigned int;
using uint8 = unsigned long long;
using uchar1 = char8_t;
using uchar2 = char16_t;
using uchar4 = char32_t;
using nullptr_t = decltype(nullptr);

/// constant value for invalid size, index, or position
inline constexpr auto npos = static_cast<uint>(-1);

/// always represents `false`
template<typename...> constexpr bool always_false = false;

/// always represents `void` unless any of the types are invalid
template<typename...> using void_t = void;

/// checks if the all types are valid
template<typename... Ts> concept valid = requires { typename void_t<Ts...>; };

/// represents the number of `true`
template<bool... Bs> constexpr uint counts = (Bs + ...);

/// represents the index of the first `true`; if none, then the size of the list
template<bool... Bs> constexpr uint inspects = 0;
template<bool B, bool... Bs> constexpr uint inspects<B, Bs...> = B ? 0 : 1 + inspects<Bs...>;

/// struct to represent a constant value
template<auto V, typename T = decltype(V)>
requires requires(void (&f)(T)) { f(V); }
struct constant {
  using type = T;
  static constexpr type value = V;
  consteval operator type() const noexcept { return value; }
  consteval type operator()() const noexcept { return value; }
};

namespace _ {
template<typename T> constexpr bool _is_const = false;
template<typename T> constexpr bool _is_const<const T> = true;
template<typename T> constexpr bool _is_volatile = false;
template<typename T> constexpr bool _is_volatile<volatile T> = true;
template<typename T> constexpr bool _is_lvref = false;
template<typename T> constexpr bool _is_lvref<T&> = true;
template<typename T> constexpr bool _is_rvref = false;
template<typename T> constexpr bool _is_rvref<T&&> = true;
template<typename T> constexpr bool _is_pointer = false;
template<typename T> constexpr bool _is_pointer<T*> = true;
template<typename T> constexpr bool _is_pointer<T* const> = true;
template<typename T> constexpr bool _is_pointer<T* volatile> = true;
template<typename T> constexpr bool _is_pointer<T* const volatile> = true;
template<typename T> constexpr bool _is_bounded_array = false;
template<typename T, uint N> constexpr bool _is_bounded_array<T[N]> = true;
template<typename T> constexpr bool _is_unbounded_array = false;
template<typename T> constexpr bool _is_unbounded_array<T[]> = true;
}

/// checks if the type is `const`
template<typename T> concept is_const = _::_is_const<T>;

/// checks if the type is `volatile`
template<typename T> concept is_volatile = _::_is_volatile<T>;

/// checks if the type is `const volatile`
template<typename T> concept is_cv = is_const<T> and is_volatile<T>;

/// checks if the type is an lvalue reference
template<typename T> concept is_lvref = _::_is_lvref<T>;

/// checks if the type is an rvalue reference
template<typename T> concept is_rvref = _::_is_rvref<T>;

/// checks if the type is a reference
template<typename T> concept is_reference = is_lvref<T> or is_rvref<T>;

/// checks if the type is a pointer
template<typename T> concept is_pointer = _::_is_pointer<T>;

/// checks if the type is a bounded array
template<typename T> concept is_bounded_array = _::_is_bounded_array<T>;

/// checks if the type is an unbounded array
template<typename T> concept is_unbounded_array = _::_is_unbounded_array<T>;

/// checks if the type is an array
template<typename T> concept is_array = is_bounded_array<T> or is_unbounded_array<T>;

/// checks if the type is a function
template<typename T> concept is_function = !is_const<const T> and !is_reference<T>;

namespace _ {
template<typename T> struct _type { using type = T; };
template<typename T> struct _remove_const : _type<T> {};
template<typename T> struct _remove_const<const T> : _type<T> {};
template<typename T> struct _remove_volatile : _type<T> {};
template<typename T> struct _remove_volatile<volatile T> : _type<T> {};
template<typename T> struct _remove_reference : _type<T> {};
template<typename T> struct _remove_reference<T&> : _type<T> {};
template<typename T> struct _remove_reference<T&&> : _type<T> {};
template<typename T> struct _remove_pointer : _type<T> {};
template<typename T> struct _remove_pointer<T*> : _type<T> {};
template<typename T> struct _remove_pointer<T* const> : _type<T> {};
template<typename T> struct _remove_pointer<T* volatile> : _type<T> {};
template<typename T> struct _remove_pointer<T* const volatile> : _type<T> {};
template<typename T> struct _remove_extent : _type<T> {};
template<typename T> struct _remove_extent<T[]> : _type<T> {};
template<typename T, uint N> struct _remove_extent<T[N]> : _type<T> {};
}

/// removes `const` from the type
template<typename T> using remove_const = _::_remove_const<T>::type;

/// removes `volatile` from the type
template<typename T> using remove_volatile = _::_remove_volatile<T>::type;

/// removes `const` and `volatile` from the type
template<typename T> using remove_cv = remove_const<remove_volatile<T>>;

/// removes reference from the type
template<typename T> using remove_reference = _::_remove_reference<T>::type;

/// removes `const`, `volatile`, and reference from the type
template<typename T> using remove_cvref = remove_cv<remove_reference<T>>;

/// removes pointer from the type
template<typename T> using remove_pointer = _::_remove_pointer<T>::type;

/// removes array extent from the type
template<typename T> using remove_extent = _::_remove_extent<T>::type;

namespace _ {
template<typename T> struct _add_const : _type<const T> {};
template<typename T> struct _add_const<T&> : _type<const T&> {};
template<typename T> struct _add_const<T&&> : _type<const T&&> {};
template<typename T> struct _add_volatile : _type<volatile T> {};
template<typename T> struct _add_volatile<T&> : _type<volatile T&> {};
template<typename T> struct _add_volatile<T&&> : _type<volatile T&&> {};
template<typename T> struct _add_pointer : _type<T*> {};
template<typename T> struct _add_pointer<T&> : _type<T*&> {};
template<typename T> struct _add_pointer<T&&> : _type<T*&&> {};
template<typename T, uint N> struct _add_extent : _type<T[N]> {};
template<typename T, uint N> struct _add_extent<T&, N> : _type<T(&)[N]> {};
template<typename T, uint N> struct _add_extent<T&&, N> : _type<T(&&)[N]> {};
template<typename T> struct _add_extent<T, 0> : _type<T[]> {};
template<typename T> struct _add_extent<T&, 0> : _type<T(&)[]> {};
template<typename T> struct _add_extent<T&&, 0> : _type<T(&&)[]> {};
}

/// adds `const` to the type
template<typename T> using add_const = _::_add_const<T>::type;

/// adds `volatile` to the type
template<typename T> using add_volatile = _::_add_volatile<T>::type;

/// adds `const` and `volatile` to the type
template<typename T> using add_cv = add_const<add_volatile<T>>;

/// adds lvalue reference to the type
template<typename T> using add_lvref = T&;

/// adds rvalue reference to the type
template<typename T> using add_rvref = remove_reference<T>&&;

/// adds forward reference to the type
template<typename T> using add_fwref = T&&;

/// adds pointer to the type
template<typename T> using add_pointer = _::_add_pointer<T>::type;

/// adds array extent to the type
template<typename T, uint N> using add_extent = _::_add_extent<T, N>::type;

/// `move` function
inline constexpr auto mv = []<typename T>(T&& a) noexcept -> add_rvref<T> { return static_cast<add_rvref<T>>(a); };

/// `forward` function
template<typename T> constexpr auto fwd = [](add_lvref<T> a) noexcept -> T&& { return static_cast<T&&>(a); };

/// `declval` function
template<typename T> constexpr auto declval = []() noexcept -> add_fwref<T> {};

/// checks if the type can be destroyed
template<typename T> concept destructible = __is_destructible(T);

/// checks if the type can be destroyed without throwing exceptions
template<typename T> concept nt_destructible = destructible<T> && __is_nothrow_destructible(T);

/// checks if the type can be constructed
template<typename T, typename... As> concept constructible = requires { T{declval<As>()...}; };

/// checks if the type can be constructed without throwing exceptions
template<typename T, typename... As> concept nt_constructible =
  constructible<T, As...> && noexcept(T{declval<As>()...});

/// checks if the type can be assigned from the argument
template<typename T, typename A> concept assignable = requires { declval<T>() = declval<A>(); };

/// checks if the type can be assigned from the argument without throwing exceptions
template<typename T, typename A> concept nt_assignable = assignable<T, A> && noexcept(declval<T>() = declval<A>());

/// checks if the type can be exchanged with the argument
template<typename T, typename A> concept exchangeable = constructible<T, T> && assignable<T&, A>;

/// checks if the type can be exchanged with the argument without throwing exceptions
template<typename T, typename A> concept nt_exchangeable =
  exchangeable<T, A> && nt_constructible<T, T> && nt_assignable<T&, A>;

/// checks if the type is trivially copyable
template<typename T> concept trivially_copyable = __is_trivially_copyable(T);

/// constructs the type with the arguments
template<typename T> constexpr auto construct = []<typename... As>(As&&... as)
  noexcept(nt_constructible<T, As...>) -> T requires constructible<T, As...> {
  return T{static_cast<As&&>(as)...};
};

/// assigns the argument to the reference
inline constexpr auto assign = []<typename T, typename A>(T& t, A&& a)
  noexcept(nt_assignable<T&, A>) -> decltype(auto) requires assignable<T&, A> {
  return t = static_cast<A&&>(a);
};

/// exchanges the value of the reference with the argument
inline constexpr auto exchange = []<typename T, typename A>(T& t, A&& a)
  noexcept(nt_exchangeable<T, A>) -> T requires exchangeable<T, A> {
  T r(static_cast<T&&>(t));
  t = static_cast<A&&>(a);
  return r;
};

/// bit-casts the value to another type
template<trivially_copyable T> constexpr auto bitcast = []<trivially_copyable U>(const U& v)
  noexcept -> T requires (sizeof(T) == sizeof(U)) { return __builtin_bit_cast(T, v); };


/// bit-casts the value to uint-type
constexpr auto uintcast = []<trivially_copyable T>(const T& t) noexcept {
  if constexpr (sizeof(T) == 1) return uint1(t);
  else if constexpr (sizeof(T) == 2) return uint2(t);
  else if constexpr (sizeof(T) == 4) return uint4(t);
  else if constexpr (sizeof(T) == 8) return uint8(t);
  else static_assert(always_false<T>, "unsupported type");
};

namespace _ {
template<typename T, typename U> constexpr bool _same_as_ = false;
template<typename T> constexpr bool _same_as_<T, T> = true;
template<typename T, typename U> concept _same_as = _same_as_<T, U>;
template<typename T, typename U> concept _castable_to = requires { static_cast<U>(declval<T>()); };
}

/// checks if all of the types are the same
template<typename T, typename... Ts> concept same_as = ((_::_same_as<T, Ts> and _::_same_as<Ts, T>) and ...);

/// checks if any of the types are the same
template<typename T, typename... Ts> concept included_in = (same_as<T, Ts> or ...);

/// checks if the type can be explicitly converted to the others
template<typename T, typename... Ts> concept castable_to = (_::_castable_to<T, Ts> and ...);

/// checks if the type can be explicitly converted to the others without throwing exceptions
template<typename T, typename... Ts> concept nt_castable_to =
  castable_to<T, Ts...> and noexcept((static_cast<T>(declval<Ts>()), ...));

/// checks if the type can be implicitly converted to the others
template<typename T, typename... Ts> concept convertible_to =
  (__is_convertible_to(T, Ts) and ...) and castable_to<T, Ts...>;

/// checks if the type can be implicitly converted to the others without throwing exceptions
template<typename T, typename... Ts> concept nt_convertible_to =
  convertible_to<T, Ts...> and nt_castable_to<T, Ts...>;

/// checks if the type is derived from the others
template<typename T, typename... Ts> concept derived_from =
  (__is_base_of(Ts, T) and ...) and convertible_to<const volatile T*, const volatile Ts*...>;

/// checks if the type is `bool`
template<typename T> concept is_bool = same_as<remove_cv<T>, bool>;

/// checks if the type is char-type
template<typename T> concept char_type = included_in<remove_cv<T>, char, wchar, char8_t, char16_t, char32_t>;

/// checks if the type is int-type
template<typename T> concept int_type = included_in<remove_cv<T>, int1, int2, int4, int8, long>;

/// checks if the type is uint-type
template<typename T> concept uint_type = included_in<remove_cv<T>, uint1, uint2, uint4, uint8, unsigned long>;

/// checks if the type is integral
template<typename T> concept integral = is_bool<T> || char_type<T> || int_type<T> || uint_type<T>;

/// checks if the type is float-type
template<typename T> concept float_type = included_in<remove_cv<T>, float, double, long double>;

/// checks if the type is arithmetic
template<typename T> concept arithmetic = integral<T> || float_type<T>;

/// checks if the type is numeric; explicitly convertible to almost all arithmetic types
template<typename T> concept numeric = nt_castable_to<T, bool, int4, int8, uint4, uint8, float, double>;

namespace _ {
template<typename T, template<typename...> typename Tm> constexpr bool _specialization_of = false;
template<template<typename...> typename Tm, typename... Ts> constexpr bool _specialization_of<Tm<Ts...>, Tm> = true;
template<typename T, typename U> constexpr bool _variation_of = false;
template<template<typename...> typename Tm, typename... Ts, typename... Us>
constexpr bool _variation_of<Tm<Ts...>, Tm<Us...>> = true;
template<template<auto...> typename Tm, auto... Ts, auto... Us>
constexpr bool _variation_of<Tm<Ts...>, Tm<Us...>> = true;
template<template<typename, auto...> typename Tm, typename T, auto... Ts, typename U, auto... Us>
constexpr bool _variation_of<Tm<T, Ts...>, Tm<U, Us...>> = true;

template<uint I, typename... Ts> struct _select_type;
template<uint I, typename T, typename... Ts> struct _select_type<I, T, Ts...> : _select_type<I - 1, Ts...> {};
template<typename T, typename... Ts> struct _select_type<0, T, Ts...> : _type<T> {};
}

/// checks if the type is a specialization of a template
template<typename T, template<typename...> typename Tm>
concept specialization_of = _::_specialization_of<remove_cvref<T>, Tm>;

/// checks if the type is a variation of a template
template<typename T, typename U> concept variation_of = _::_variation_of<remove_cvref<T>, remove_cvref<U>>;

/// checks if `I` is valid for selecting one from `N`
template<auto I, uint N> concept selectable =
  convertible_to<decltype(I), uint> && (is_bool<decltype(I)> && N == 2) || (!is_bool<decltype(I)> && uint(I) < N);

/// selects a parameter
template<auto I> inline constexpr auto select = []<typename A, typename... As>(A&& a, As&&... as)
  noexcept -> decltype(auto) requires selectable<I, 1 + sizeof...(As)> {
  if constexpr (is_bool<decltype(I)>) return select<uint(!I)>(static_cast<A&&>(a), static_cast<As&&>(as)...);
  else if constexpr (same_as<decltype(I), uint>) {
    if constexpr (I == 0) return static_cast<A&&>(a);
    else return select<I - 1>(static_cast<As&&>(as)...);
  } else return select<uint(I)>(static_cast<A&&>(a), static_cast<As&&>(as)...);
};

/// selects a type
template<auto I, typename... Ts> requires selectable<I, sizeof...(Ts)>
using select_type = _::_select_type<(is_bool<decltype(I)> ? !I : I), Ts...>::type;

/// selects a value
template<auto I, auto... Vs> requires selectable<I, sizeof...(Vs)>
inline constexpr auto select_value = select_type<I, constant<Vs>...>::value;

/// creates an object that calls functions in coversion
template<typename... Fs> struct caster : public Fs... {
private:
  static constexpr uint _n = sizeof...(Fs);
  template<typename F> using _result = decltype(F::operator()());
  template<typename F, typename R> static constexpr bool _same = same_as<_result<F>, R>;
  template<typename F, typename R> static constexpr bool _conv = convertible_to<_result<F>, R>;
  template<typename R> static constexpr uint _first_same = inspects<_same<Fs, R>...>;
  template<typename R> static constexpr uint _i = _first_same<R> < _n ? _first_same<R> : inspects<_conv<Fs, R>...>;
  using Fs::operator()...;
public:

  /// calls a function instead of conversion
  template<typename R, typename F = select_type<_i<R>, Fs...>>
  constexpr operator R() const noexcept(noexcept(F::operator()())) { return F::operator()(); }
};

inline constexpr auto is_cev = caster{[]() noexcept -> bool { return __builtin_is_constant_evaluated(); }};

/// aggregate static array
template<typename T, uint N = npos> class array {
public:
  T _[N]{};
  using value_type = T;

  /// number of elements
  static constexpr uint count = N;

  /// assignment from an array
  template<typename U> requires assignable<T&, const U&>
  constexpr array& operator=(const U (&Other)[N]) noexcept(nt_assignable<T&, const U&>) {
    if (is_cev) {
      for (uint i = 0; i < N; ++i) _[i] = Other[i];
    } else __ywstd_cfunc memcpy(_, Other, sizeof(T) * N);
  }

  /// conversion to reference to the array
  constexpr operator add_lvref<T[N]>() noexcept { return _; }
  constexpr operator add_lvref<const T[N]>() const noexcept { return _; }

  /// checks if the array is empty
  constexpr bool empty() const noexcept { return false; }

  /// returns the size of the array
  constexpr uint size() const noexcept { return N; }

  /// returns the data pointer
  constexpr T* data() noexcept { return _; }
  constexpr const T* data() const noexcept { return _; }

  /// returns the iterator to the beginning
  constexpr T* begin() noexcept { return _; }
  constexpr const T* begin() const noexcept { return _; }

  /// returns the iterator to the end
  constexpr T* end() noexcept { return _ + N; }
  constexpr const T* end() const noexcept { return _ + N; }

  /// accesses the first element
  constexpr T& front() noexcept { return *_; }
  constexpr const T& front() const noexcept { return *_; }

  /// accesses the last element
  constexpr T& back() noexcept { return _[N - 1]; }
  constexpr const T& back() const noexcept { return _[N - 1]; }

  /// accesses the element at the index
  constexpr T& operator[](uint I) { return _[I]; }
  constexpr const T& operator[](uint I) const { return _[I]; }

  /// accesses the element at the index
  template<uint I> requires (I < N) constexpr T& get() & noexcept { return _[I]; }
  template<uint I> requires (I < N) constexpr T&& get() && noexcept { return mv(_[I]); }
  template<uint I> requires (I < N) constexpr const T& get() const& noexcept { return _[I]; }
  template<uint I> requires (I < N) constexpr const T&& get() const&& noexcept { return mv(_[I]); }

  /// fills the array with the value
  constexpr void fill(const T& v) noexcept(nt_assignable<T&, const T&>) {
    for (uint i = 0; i < N; ++i) _[i] = v;
  }
};

/// empty static array
template<typename T> class array<T, 0> {
public:
  static constexpr uint count = 0;
  using value_type = T;
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

template<typename T> class array<T, npos>;
template<typename T, convertible_to<T>... Ts> array(T, Ts...) -> array<T, 1 + sizeof...(Ts)>;

/// structure with two elements; `x` and `y` FFF
template<typename T> struct vector2 {

  /// number of elements
  static constexpr uint count = 2;

  /// first element
  T x{};

  /// second element
  T y{};

  /// default constructor
  constexpr vector2() noexcept = default;

  /// fills the elements with the same value
  explicit constexpr vector2(const T& v) noexcept : x(v), y(v) {}

  /// sets the elements
  template<convertible_to<T> U, convertible_to<T> V> constexpr vector2(U&& X, V&& Y)
    noexcept : x(static_cast<U&&>(X)), y(static_cast<V&&>(Y)) {}

  /// gets the element
  template<uint I> requires (I < 2) constexpr T& get() & noexcept { return select<I>(x, y); }

  /// gets the element
  template<uint I> requires (I < 2) constexpr const T& get() const& noexcept { return select<I>(x, y); }

  /// gets the element
  template<uint I> requires (I < 2) constexpr T&& get() && noexcept { return static_cast<T&&>(select<I>(x, y)); }

  /// gets the element
  template<uint I> requires (I < 2) constexpr const T&& get() const&&
    noexcept { return static_cast<const T&&>(select<I>(x, y)); }
};

template<typename T1, typename T2> vector2(T1&&, T2&&) -> vector2<float>;

/// structure with three elements; `x`, `y`, and `z`
template<typename T> struct vector3 {

  /// number of elements
  static constexpr uint count = 3;

  /// first element
  T x{};

  /// second element
  T y{};

  /// third element
  T z{};

  /// default constructor
  constexpr vector3() noexcept = default;

  /// fills the elements with the same value
  explicit constexpr vector3(const T& v) noexcept : x(v), y(v), z(v) {}

  /// sets the elements
  template<convertible_to<T> U, convertible_to<T> V, convertible_to<T> W> constexpr vector3(U&& X, V&& Y, W&& Z)
    noexcept : x(static_cast<U&&>(X)), y(static_cast<V&&>(Y)), z(static_cast<W&&>(Z)) {}

  /// gets the element
  template<uint I> requires (I < 3) constexpr T& get() & noexcept { return select<I>(x, y, z); }

  /// gets the element
  template<uint I> requires (I < 3) constexpr const T& get() const& noexcept { return select<I>(x, y, z); }

  /// gets the element
  template<uint I> requires (I < 3) constexpr T&& get() && noexcept { return static_cast<T&&>(select<I>(x, y, z)); }

  /// gets the element
  template<uint I> requires (I < 3) constexpr const T&& get() const&&
    noexcept { return static_cast<const T&&>(select<I>(x, y, z)); }
};

template<typename T1, typename T2, typename T3> vector3(T1&&, T2&&, T3&&) -> vector3<float>;

/// structure with four elements; `x`, `y`, `z`, and `w`
template<typename T> struct vector4 {

  /// number of elements
  static constexpr uint count = 4;

  /// first element
  T x{};

  /// second element
  T y{};

  /// third element
  T z{};

  /// fourth element
  T w{};

  /// default constructor
  constexpr vector4() noexcept = default;

  /// fills the elements with the same value
  explicit constexpr vector4(const T& v) noexcept : x(v), y(v), z(v), w(v) {}

  /// sets the elements
  template<convertible_to<T> X, convertible_to<T> Y, convertible_to<T> Z, convertible_to<T> W>
  constexpr vector4(X&& x, Y&& y, Z&& z, W&& w) noexcept
    : x(static_cast<X&&>(x)), y(static_cast<Y&&>(y)), z(static_cast<Z&&>(z)), w(static_cast<W&&>(w)) {}

  /// gets the element
  template<uint I> requires (I < 4) constexpr T& get() & noexcept { return select<I>(x, y, z, w); }

  /// gets the element
  template<uint I> requires (I < 4) constexpr const T& get() const& noexcept { return select<I>(x, y, z, w); }

  /// gets the element
  template<uint I> requires (I < 4) constexpr T&& get() && noexcept { return static_cast<T&&>(select<I>(x, y, z, w)); }

  /// gets the element
  template<uint I> requires (I < 4) constexpr const T&& get() const&&
    noexcept { return static_cast<const T&&>(select<I>(x, y, z, w)); }
};
}
// namespace std {
// template<typename T> struct tuple_size;
// template<typename T, uint N> struct tuple_size<yw::array<T, N>> : integral_constant<uint, N> {};
// template<typename T> struct tuple_size<yw::vector2<T>> : integral_constant<uint, 2> {};
// template<typename T> struct tuple_size<yw::vector3<T>> : integral_constant<uint, 3> {};

// template<uint I, typename T> struct tuple_element;
// template<uint I, typename T, uint N> struct tuple_element<I, yw::array<T, N>> : type_identity<T> {};
// template<uint I, typename T> struct tuple_element<I, yw::vector2<T>> : type_identity<T> {};
// template<uint I, typename T> struct tuple_element<I, yw::vector3<T>> : type_identity<T> {};
// }
#pragma endregion YWLIB-CORE ---------------------------------------------------
