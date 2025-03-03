#pragma once // clang-format off

#ifndef __ywlib_is_exported
#ifndef __ywlib_export
#define __ywlib_export
#define __ywlib_is_exported (false)
#else
#define __ywlib_is_exported (true)
#define _BUILD_STD_MODULE
#endif
#endif

#ifndef __ywlib_is_imported
#ifndef __ywlib_import
#define __ywlib_is_imported (false)
#else
#define __ywlib_is_imported (true)
#endif
#endif

#if __ywlib_is_imported
import ywlib;
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "libcpmt.lib")
#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "user32.lib")
#endif

namespace ywlib { struct _dummy; }
#if __ywlib_is_exported or __ywlib_is_imported
#define __ywlib_begin struct ywlib::_dummy
#define __ywlib_end struct ywlib::_dummy
#define __ywlib_global ::
#else
#define __ywlib_begin namespace ywlib { struct _dummy
#define __ywlib_end } struct ywlib::_dummy
#define __ywlib_global ::ywlib::
#endif

#define __ywlib_dead(Type_Name_Equal_Value) \
[[deprecated("Do not use the constant as it is only used in `msvc/inc` headers.")]] \
inline constexpr Type_Name_Equal_Value

extern "C" {

// from <cstdint>

using int8_t = signed char;
using int16_t = short;
using int32_t = int;
using int64_t = long long;
using uint8_t = unsigned char;
using uint16_t = unsigned short;
using uint32_t = unsigned int;
using uint64_t = unsigned long long;

__ywlib_begin;

// from <cstdio> and <cwchar>

typedef struct _iobuf {
  void* _Placeholder;
} FILE;
__ywlib_export FILE* __cdecl __acrt_iob_func(unsigned);
#define stdin (__ywlib_global __acrt_iob_func(0))
#define stdout (__ywlib_global __acrt_iob_func(1))
#define stderr (__ywlib_global __acrt_iob_func(2))

typedef struct __crt_locale_pointers {
  struct __crt_locale_data* locinfo;
  struct __crt_multibyte_data* mbcinfo;
} __crt_locale_pointers, *_locale_t;

__declspec(noinline) inline uint64_t* __cdecl __local_stdio_printf_options() {
  static uint64_t _;
  return &_;
}
__declspec(noinline) inline uint64_t* __cdecl __local_stdio_scanf_options() {
  static uint64_t _;
  return &_;
}
#define _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS (*__ywlib_global __local_stdio_printf_options())
#define _CRT_INTERNAL_LOCAL_SCANF_OPTIONS (*__ywlib_global __local_stdio_scanf_options())
#define _CRT_INTERNAL_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION (1ULL << 0)
#define _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR (1ULL << 1)
#define _CRT_INTERNAL_SCANF_SECURECRT (1ULL << 0)

// from <ctime> and <cwchar>

struct tm {
  int tm_sec, tm_min, tm_hour;
  int tm_mday, tm_mon, tm_year;
  int tm_wday, tm_yday, tm_isdst;
};

typedef struct _Mbstatet {
  unsigned long _Wchar;
  unsigned short _Byte, _State;
} _Mbstatet, mbstate_t;

__ywlib_end;
}

// clang-format on

#define uint size_t
#define wchar wchar_t

#if not __ywlib_is_imported
export namespace yw {

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

constexpr int1 operator""_i1(unsigned long long v) noexcept { return static_cast<int1>(v); }
constexpr int2 operator""_i2(unsigned long long v) noexcept { return static_cast<int2>(v); }
constexpr int4 operator""_i4(unsigned long long v) noexcept { return static_cast<int4>(v); }
constexpr int8 operator""_i8(unsigned long long v) noexcept { return static_cast<int8>(v); }
constexpr uint operator""_ui(unsigned long long v) noexcept { return static_cast<uint>(v); }
constexpr uint1 operator""_ui1(unsigned long long v) noexcept { return static_cast<uint1>(v); }
constexpr uint2 operator""_ui2(unsigned long long v) noexcept { return static_cast<uint2>(v); }
constexpr uint4 operator""_ui4(unsigned long long v) noexcept { return static_cast<uint4>(v); }
constexpr uint8 operator""_ui8(unsigned long long v) noexcept { return static_cast<uint8>(v); }
constexpr uchar1 operator""_uc1(unsigned long long v) noexcept { return static_cast<uchar1>(v); }
constexpr uchar2 operator""_uc2(unsigned long long v) noexcept { return static_cast<uchar2>(v); }
constexpr uchar4 operator""_uc4(unsigned long long v) noexcept { return static_cast<uchar4>(v); }

inline constexpr auto npos = static_cast<uint>(-1);
template<typename...> constexpr bool always_false = false;
template<typename...> using void_t = void;
template<typename... Ts> concept valid = requires { typename void_t<Ts...>; };
template<bool... Bs> constexpr uint counts = (Bs + ...);
template<bool... Bs> constexpr uint inspects = 0;
template<bool B, bool... Bs> constexpr uint inspects<B, Bs...> = B ? 0 : 1 + inspects<Bs...>;

struct pass {
  template<typename T> constexpr T&& operator()(T&& a) const noexcept { return static_cast<T&&>(a); }
};

template<auto V, typename T = decltype(V)> requires requires(void (&f)(T)) { f(V); } struct constant {
  using type = T;
  static constexpr type value = V;
  consteval operator type() const noexcept { return value; }
  consteval type operator()() const noexcept { return value; }
};


namespace _ { // clang-format off
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
} // clang-format on

template<typename T> using remove_const = _::_remove_const<T>::type;
template<typename T> using remove_volatile = _::_remove_volatile<T>::type;
template<typename T> using remove_cv = remove_const<remove_volatile<T>>;
template<typename T> using remove_reference = _::_remove_reference<T>::type;
template<typename T> using remove_cvref = remove_cv<remove_reference<T>>;
template<typename T> using remove_pointer = _::_remove_pointer<T>::type;
template<typename T> using remove_extent = _::_remove_extent<T>::type;

namespace _ { // clang-format off
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
template<typename T, uint N> struct _add_extent<T&, N> : _type<T (&)[N]> {};
template<typename T, uint N> struct _add_extent<T&&, N> : _type<T (&&)[N]> {};
template<typename T> struct _add_extent<T, 0> : _type<T[]> {};
template<typename T> struct _add_extent<T&, 0> : _type<T (&)[]> {};
template<typename T> struct _add_extent<T&&, 0> : _type<T (&&)[]> {};
} // clang-format on

template<typename T> using add_const = _::_add_const<T>::type;
template<typename T> using add_volatile = _::_add_volatile<T>::type;
template<typename T> using add_cv = add_const<add_volatile<T>>;
template<typename T> using add_lvref = T&;
template<typename T> using add_rvref = remove_reference<T>&&;
template<typename T> using add_fwref = T&&;
template<typename T> using add_pointer = _::_add_pointer<T>::type;
template<typename T, uint N> using add_extent = _::_add_extent<T, N>::type;

inline constexpr auto mv = []<typename T>(T&& a) noexcept -> add_rvref<T> { return static_cast<add_rvref<T>>(a); };
template<typename T> constexpr auto fwd = [](add_lvref<T> a) noexcept -> T&& { return static_cast<T&&>(a); };
template<typename T> constexpr auto declval = []() noexcept -> add_fwref<T> {};

namespace _ { // clang-format off
template<typename T, typename U> constexpr bool _same_as_ = false;
template<typename T> constexpr bool _same_as_<T, T> = true;
template<typename T, typename U> concept _same_as = _same_as_<T, U>;
} // clang-format on

template<typename T, typename... Ts> concept same_as = ((_::_same_as<T, Ts> and _::_same_as<Ts, T>) and ...);
template<typename T, typename... Ts> concept different_from = ((not same_as<T, Ts>) and ...);
template<typename T, typename... Ts> concept included_in = (same_as<T, Ts> or ...);
template<typename T, typename... Ts> concept castable_to = ((requires { static_cast<Ts>(declval<T>()); }) and ...);
template<typename T, typename... Ts> concept nt_castable_to = castable_to<T, Ts...> and noexcept((static_cast<T>(declval<Ts>()), ...));
template<typename T, typename... Ts> concept convertible_to = (__is_convertible_to(T, Ts) and ...) and castable_to<T, Ts...>;
template<typename T, typename... Ts> concept nt_convertible_to = convertible_to<T, Ts...> and nt_castable_to<T, Ts...>;
template<typename T, typename... Ts> concept derived_from = (__is_base_of(Ts, T) and ...) and convertible_to<const volatile T*, const volatile Ts*...>;

namespace _ { // clang-format off
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
} // clang-format on

template<typename T> concept is_void = same_as<remove_cv<T>, void>;
template<typename T> concept is_bool = same_as<remove_cv<T>, bool>;
template<typename T> concept is_nullptr = same_as<remove_cv<T>, nullptr_t>;
template<typename T> concept char_type = included_in<remove_cv<T>, char, wchar, char8_t, char16_t, char32_t>;
template<typename T> concept int_type = included_in<remove_cv<T>, int1, int2, int4, int8, long>;
template<typename T> concept uint_type = included_in<remove_cv<T>, uint1, uint2, uint4, uint8, unsigned long>;
template<typename T> concept integral = is_bool<T> || char_type<T> || int_type<T> || uint_type<T>;
template<typename T> concept signed_integral = integral<T> && T(-1) < T(0);
template<typename T> concept unsigned_integral = integral<T> && !signed_integral<T>;
template<typename T> concept float_type = included_in<remove_cv<T>, float, double, long double>;
template<typename T> concept arithmetic = integral<T> || float_type<T>;
template<typename T> concept numeric = nt_castable_to<T, bool, int4, int8, uint4, uint8, float, double>;

template<typename T> concept is_const = _::_is_const<T>;
template<typename T> concept is_volatile = _::_is_volatile<T>;
template<typename T> concept is_cv = is_const<T> and is_volatile<T>;
template<typename T> concept is_lvref = _::_is_lvref<T>;
template<typename T> concept is_rvref = _::_is_rvref<T>;
template<typename T> concept is_reference = is_lvref<T> or is_rvref<T>;
template<typename T> concept is_pointer = _::_is_pointer<T>;
template<typename T> concept is_bounded_array = _::_is_bounded_array<T>;
template<typename T> concept is_unbounded_array = _::_is_unbounded_array<T>;
template<typename T> concept is_array = is_bounded_array<T> or is_unbounded_array<T>;
template<typename T> concept is_function = !is_const<const T> and !is_reference<T>;

namespace _ { // clang-format off
template<typename T> struct _member_type : _type<void> {};
template<typename T, typename U> struct _member_type<U T::*> : _type<U> {};
template<typename T> struct _class_type : _type<void> {};
template<typename T, typename U> struct _class_type<U T::*> : _type<T> {};
} // clang-format on

template<typename T> concept is_member_pointer = is_pointer<T> and !is_void<typename _::_member_type<T>::type>;
template<is_member_pointer T> using member_type = _::_member_type<T>::type;
template<is_member_pointer T> using class_type = _::_class_type<T>::type;
template<typename T> concept is_member_object_pointer = is_member_pointer<T> and !is_function<member_type<T>>;
template<typename T> concept is_member_function_pointer = is_member_pointer<T> and is_function<member_type<T>>;

template<typename T> concept is_enum = __is_enum(T);
template<typename T> concept is_scoped_enum = is_enum<T> and convertible_to<T, bool>;
template<is_enum T> using underlying_type = __underlying_type(T);
inline constexpr auto to_underlying = []<is_enum T>(T e) noexcept { return static_cast<underlying_type<T>>(e); };

template<typename T> concept is_class = __is_class(T);
template<typename T> concept is_union = __is_union(T);
template<typename T> concept scalar = arithmetic<T> or is_pointer<T> or is_enum<T> or is_nullptr<T>;
template<typename T> concept trivially_copyable = __is_trivially_copyable(T);

template<trivially_copyable T> constexpr auto bitcast = []<trivially_copyable U>(const U& v) noexcept //
  -> T requires (sizeof(T) == sizeof(U)) { return __builtin_bit_cast(T, v); };

inline constexpr auto uintcast = []<trivially_copyable T>(const T& t) noexcept {
  if constexpr (sizeof(T) == 1) return uint1(t);
  else if constexpr (sizeof(T) == 2) return uint2(t);
  else if constexpr (sizeof(T) == 4) return uint4(t);
  else if constexpr (sizeof(T) == 8) return uint8(t);
  else static_assert(always_false<T>, "unsupported type");
};

template<typename T> concept destructible = __is_destructible(T);
template<typename T> concept nt_destructible = destructible<T> && __is_nothrow_destructible(T);
template<typename T, typename... As> concept constructible = requires { T{declval<As>()...}; };
template<typename T, typename... As> concept nt_constructible = constructible<T, As...> && noexcept(T{declval<As>()...});
template<typename T, typename A> concept assignable = requires { declval<T>() = declval<A>(); };
template<typename T, typename A> concept nt_assignable = assignable<T, A> && noexcept(declval<T>() = declval<A>());
template<typename T, typename A> concept exchangeable = constructible<T, T> && assignable<T&, A>;
template<typename T, typename A> concept nt_exchangeable = exchangeable<T, A> && nt_constructible<T, T> && nt_assignable<T&, A>;

template<typename T> constexpr auto construct = []<typename... As>(As&&... as) noexcept(nt_constructible<T, As...>) //
  -> T requires constructible<T, As...> { return T{static_cast<As&&>(as)...}; };

inline constexpr auto assign = []<typename T, typename A>(T& t, A&& a) noexcept(nt_assignable<T&, A>) //
  -> decltype(auto) requires assignable<T&, A> { return t = static_cast<A&&>(a); };

inline constexpr auto exchange = []<typename T, typename A>(T& t, A&& a) //
  noexcept(nt_exchangeable<T, A>) -> T requires exchangeable<T, A> {
  T r(static_cast<T&&>(t));
  t = static_cast<A&&>(a);
  return r;
};

namespace _ { // clang-format off
template<typename T, template<typename...> typename Tm> constexpr bool _specialization_of = false;
template<template<typename...> typename Tm, typename... Ts> constexpr bool _specialization_of<Tm<Ts...>, Tm> = true;
template<typename T, typename U> constexpr bool _variation_of = false;
template<template<typename...> typename Tm, typename... Ts, typename... Us> constexpr bool _variation_of<Tm<Ts...>, Tm<Us...>> = true;
template<template<auto...> typename Tm, auto... Ts, auto... Us> constexpr bool _variation_of<Tm<Ts...>, Tm<Us...>> = true;
template<template<typename, auto...> typename Tm, typename T, auto... Ts, typename U, auto... Us>
constexpr bool _variation_of<Tm<T, Ts...>, Tm<U, Us...>> = true;
} // clang-format on

template<typename T, template<typename...> typename Tm> concept specialization_of = _::_specialization_of<remove_cvref<T>, Tm>;
template<typename T, typename U> concept variation_of = _::_variation_of<remove_cvref<T>, remove_cvref<U>>;

namespace _ { // clang-format off
template<uint I, typename... Ts> struct _select_type;
template<uint I, typename T, typename... Ts> struct _select_type<I, T, Ts...> : _select_type<I - 1, Ts...> {};
template<typename T, typename... Ts> struct _select_type<0, T, Ts...> : _type<T> {};
} // clang-format on

template<auto I, uint N> concept selectable = convertible_to<decltype(I), uint> && (is_bool<decltype(I)> && N == 2) || (!is_bool<decltype(I)> && uint(I) < N);

template<auto I> inline constexpr auto select = []<typename A, typename... As>(A&& a, As&&... as) noexcept //
  -> decltype(auto) requires selectable<I, 1 + sizeof...(As)> {
  if constexpr (is_bool<decltype(I)>) return select<uint(!I)>(static_cast<A&&>(a), static_cast<As&&>(as)...);
  else if constexpr (same_as<decltype(I), uint>) {
    if constexpr (I == 0) return static_cast<A&&>(a);
    else return select<I - 1>(static_cast<As&&>(as)...);
  } else return select<uint(I)>(static_cast<A&&>(a), static_cast<As&&>(as)...);
};

template<auto I, typename... Ts> requires selectable<I, sizeof...(Ts)> using select_type = _::_select_type<(is_bool<decltype(I)> ? !I : I), Ts...>::type;
template<auto I, auto... Vs> requires selectable<I, sizeof...(Vs)> inline constexpr auto select_value = select_type<I, constant<Vs>...>::value;

template<typename... Fs> struct caster : public Fs... {
private: // clang-format off
  static constexpr uint _n = sizeof...(Fs);
  template<typename F> using _result = decltype(declval<F&>().operator()());
  template<typename R> static constexpr uint _first_same = inspects<same_as<_result<Fs>, R>...>;
  template<typename R> static constexpr uint _first_conv = inspects<convertible_to<_result<Fs>, R>...>;
  template<typename R> static constexpr uint _i = _first_same<R> < _n ? _first_same<R> : _first_conv<R>;
  template<typename R> using _f = select_type<_i<R>, Fs...>;
  using Fs::operator()...;
public: // clang-format on
  constexpr bool operator!() const noexcept(noexcept(_f<bool>::operator()())) { return !_f<bool>::operator()(); }
  template<typename R> constexpr operator R() const noexcept(noexcept(_f<R>::operator()())) { return _f<R>::operator()(); }
};

inline constexpr auto is_cev = caster{[]() noexcept -> bool { return __builtin_is_constant_evaluated(); }};
}
#endif
