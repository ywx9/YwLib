#pragma once
#include "xyz.h"
#include "ywlib-none.h"

namespace yw {

template<typename F, typename... As>
concept invocable = std::invocable<F, As...>;

template<typename F, typename... As> concept nt_invocable =
  invocable<F, As...> && std::is_nothrow_invocable_v<F, As...>;

template<typename F, typename... As> requires invocable<F, As...> using result =
  select_type<is_void<std::invoke_result_t<F, As...>>, none, std::invoke_result_t<F, As...>>;

template<typename F, typename R, typename... As> concept invocable_r =
  invocable<F, As...> && convertible_to<std::invoke_result_t<F, As...>, R>;

template<typename F, typename R, typename... As> concept nt_invocable_r =
  nt_invocable<F, As...> && nt_convertible_to<std::invoke_result_t<F, As...>, R>;

inline constexpr auto invoke = []<typename F, typename... As>(F&& f, As&&... as)
  noexcept(nt_invocable<F, As...>) -> result<F, As...> requires invocable<F, As...> {
  if constexpr (!std::is_void_v<result<F, As...>>)
    return std::invoke(static_cast<F&&>(f), static_cast<As&&>(as)...);
  else return std::invoke(static_cast<F&&>(f), static_cast<As&&>(as)...), none{};
};

template<typename R> constexpr auto invoke_r = []<typename F, typename... As>(F&& f, As&&... as)
  noexcept(nt_invocable_r<F, R, As...>) -> R requires invocable_r<F, R, As...> {
  return std::invoke(static_cast<F&&>(f), static_cast<As&&>(as)...);
};
}
