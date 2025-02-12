#pragma once
#include "abc.h"
#include "algorithm"
#include "exception"
#include "functional"
#include "intrin0.h"
#include "mutex"
#include "pplwin.h"
#include "utility"
#include "vector"

#ifndef _PPLTASK_ASYNC_LOGGING
#define _PPLTASK_ASYNC_LOGGING 1
#endif

#if _PPLTASK_ASYNC_LOGGING
#pragma detect_mismatch("_PPLTASK_ASYNC_LOGGING", "1")
#else
#pragma detect_mismatch("_PPLTASK_ASYNC_LOGGING", "0")
#endif

#if defined(PPL_TASK_CONTEXT_ERROR_CONTROL) || defined(__cplusplus_winrt)
#define _PPL_TASK_CONTEXT_CONTROL_ENABLED true
#else
#define _PPL_TASK_CONTEXT_CONTROL_ENABLED false
#endif
#if defined(PPL_TASK_CONTEXT_ERROR_CONTROL)
#define _PPL_TASK_ERROR_REPORT_ENABLED true
#else
#define _PPL_TASK_ERROR_REPORT_ENABLED false
#endif

#pragma pack(push, _CRT_PACKING)

#pragma warning(push)
#pragma warning(disable : 28197)
#pragma warning(disable : 4100)
#pragma warning(disable : 4127)
#pragma warning(disable : 4793)

#pragma push_macro("new")
#undef new

extern "C++" {

namespace Concurrency {
namespace details {
template<class _Ty> _Ty&& declval();
}
}

namespace Concurrency {

typedef task_group_status task_status;

template<typename _Type> class task;
template<> class task<void>;

#ifndef PPL_TASK_SAVE_FRAME_COUNT
#ifdef _DEBUG
#define PPL_TASK_SAVE_FRAME_COUNT 10
#else
#define PPL_TASK_SAVE_FRAME_COUNT 1
#endif
#endif

#ifndef __EDG__
#define _EXPAND_STR(x) #x

#pragma detect_mismatch("ppltask_saved_frame_numbers", _EXPAND_STR(PPL_TASK_SAVE_FRAME_COUNT))
#undef _EXPAND_STR
#endif

#if PPL_TASK_SAVE_FRAME_COUNT > 1
#if defined(__cplusplus_winrt) && !defined(_DEBUG)
#pragma message( \
  "WARNING: Redefining PPL_TASK_SAVE_FRAME_COUNT under Release build for non-desktop applications is not supported; only one frame will be captured!")
#endif
#define _CAPTURE_CALLSTACK()                                                                              \
  ::Concurrency::details::_TaskCreationCallstack::_CaptureMultiFramesCallstack(_ReturnAddress(),          \
                                                                               PPL_TASK_SAVE_FRAME_COUNT)
#else
#define _CAPTURE_CALLSTACK()                                                                     \
  ::Concurrency::details::_TaskCreationCallstack::_CaptureSingleFrameCallstack(_ReturnAddress())
#endif

inline __declspec(noreturn) void __cdecl cancel_current_task() { _THROW(task_canceled{}); }

namespace details {
struct _DefaultTaskHelper {

  static void __declspec(noreturn) __cdecl _NoCallOnDefaultTask_ErrorImpl() {
    _THROW(invalid_operation("This function cannot be called on a default constructed task"));
  }
};

class _TaskCreationCallstack {
private:
  void* _M_SingleFrame;
  ::std::vector<void*> _M_frames;
public:
  _TaskCreationCallstack() { _M_SingleFrame = nullptr; }

  static _TaskCreationCallstack _CaptureSingleFrameCallstack(void* _SingleFrame) {
    _TaskCreationCallstack _csc;
    _csc._M_SingleFrame = _SingleFrame;
    return _csc;
  }

  __declspec(noinline) static _TaskCreationCallstack _CaptureMultiFramesCallstack(void* _SingleFrame,
                                                                                  size_t _CaptureFrames) {
    _TaskCreationCallstack _csc;
    _csc._M_SingleFrame = _SingleFrame;
    if (_CaptureFrames > 1) {
      _csc._M_frames.resize(_CaptureFrames);

      _csc._M_frames.resize(::Concurrency::details::platform::CaptureCallstack(&_csc._M_frames[0], 2, _CaptureFrames));
    }
    return _csc;
  }
};
typedef unsigned char _Unit_type;

struct _TypeSelectorNoAsync {};
struct _TypeSelectorAsyncOperationOrTask {};
struct _TypeSelectorAsyncOperation : public _TypeSelectorAsyncOperationOrTask {};
struct _TypeSelectorAsyncTask : public _TypeSelectorAsyncOperationOrTask {};
struct _TypeSelectorAsyncAction {};
struct _TypeSelectorAsyncActionWithProgress {};
struct _TypeSelectorAsyncOperationWithProgress {};

template<typename _Ty> struct _NormalizeVoidToUnitType {
  typedef _Ty _Type;
};

template<> struct _NormalizeVoidToUnitType<void> {
  typedef _Unit_type _Type;
};

template<typename _Ty> struct _IsUnwrappedAsyncSelector {
  static const bool _Value = true;
};

template<> struct _IsUnwrappedAsyncSelector<_TypeSelectorNoAsync> {
  static const bool _Value = false;
};

template<typename _Ty> struct _UnwrapTaskType {
  typedef _Ty _Type;
};

template<typename _Ty> struct _UnwrapTaskType<task<_Ty>> {
  typedef _Ty _Type;
};

template<typename _Ty> _TypeSelectorAsyncTask _AsyncOperationKindSelector(task<_Ty>);

_TypeSelectorNoAsync _AsyncOperationKindSelector(...);

template<typename _Type> struct _IsIAsyncInfo {
  static const bool _Value = false;
};

template<typename _Type, bool _IsAsync = false> struct _TaskTypeTraits {
  typedef typename _UnwrapTaskType<_Type>::_Type _TaskRetType;
  typedef decltype(_AsyncOperationKindSelector(details::declval<_Type>())) _AsyncKind;
  typedef typename _NormalizeVoidToUnitType<_TaskRetType>::_Type _NormalizedTaskRetType;

  static const bool _IsAsyncTask = false;
  static const bool _IsUnwrappedTaskOrAsync = _IsUnwrappedAsyncSelector<_AsyncKind>::_Value;
};

template<typename _Function> auto _IsCallable(_Function _Func, int) -> decltype(_Func(), ::std::true_type());
template<typename _Function>::std::false_type _IsCallable(_Function, ...);

template<> struct _TaskTypeTraits<void> {
  typedef void _TaskRetType;
  typedef _TypeSelectorNoAsync _AsyncKind;
  typedef _Unit_type _NormalizedTaskRetType;

  static const bool _IsAsyncTask = false;
  static const bool _IsUnwrappedTaskOrAsync = false;
};

struct _BadContinuationParamType {};

template<typename _Function, typename _Type> auto _ReturnTypeHelper(_Type _Obj, _Function _Func, int, int)
  -> decltype(_Func(::std::declval<task<_Type>>()));
template<typename _Function, typename _Type> auto _ReturnTypeHelper(_Type _Obj, _Function _Func, int, ...)
  -> decltype(_Func(_Obj));
template<typename _Function, typename _Type> auto _ReturnTypeHelper(_Type _Obj, _Function _Func, ...)
  -> _BadContinuationParamType;

template<typename _Function, typename _Type> auto _IsTaskHelper(_Type _Obj, _Function _Func, int, int)
  -> decltype(_Func(::std::declval<task<_Type>>()), ::std::true_type());
template<typename _Function, typename _Type> auto _IsTaskHelper(_Type _Obj, _Function _Func, int, ...)
  -> ::std::false_type;

template<typename _Function> auto _VoidReturnTypeHelper(_Function _Func, int, int)
  -> decltype(_Func(::std::declval<task<void>>()));
template<typename _Function> auto _VoidReturnTypeHelper(_Function _Func, int, ...) -> decltype(_Func());

template<typename _Function> auto _VoidIsTaskHelper(_Function _Func, int, int)
  -> decltype(_Func(::std::declval<task<void>>()), ::std::true_type());
template<typename _Function> auto _VoidIsTaskHelper(_Function _Func, int, ...) -> ::std::false_type;

template<typename _Function, typename _ExpectedParameterType> struct _FunctionTypeTraits {
  typedef decltype(_ReturnTypeHelper(details::declval<_ExpectedParameterType>(), details::declval<_Function>(), 0,
                                     0)) _FuncRetType;
  static_assert(!::std::is_same_v<_FuncRetType, _BadContinuationParamType>,
                "incorrect parameter type for the callable object in 'then'; consider _ExpectedParameterType or "
                "task<_ExpectedParameterType> (see below)");

  typedef decltype(_IsTaskHelper(details::declval<_ExpectedParameterType>(), details::declval<_Function>(), 0,
                                 0)) _Takes_task;
};

template<typename _Function> struct _FunctionTypeTraits<_Function, void> {
  typedef decltype(_VoidReturnTypeHelper(details::declval<_Function>(), 0, 0)) _FuncRetType;
  typedef decltype(_VoidIsTaskHelper(details::declval<_Function>(), 0, 0)) _Takes_task;
};

#ifndef _PPLTASKS_NO_STDFUNC
template<typename _Ty, typename _IsTaskType> struct _ContinuationArgTypeHelper {
  static_assert(::std::is_same_v<_IsTaskType, ::std::false_type>,
                "_IsTaskType template parameter must be std::true_type or std::false_type");
  typedef _Ty _ArgType;
};

template<typename _Ty> struct _ContinuationArgTypeHelper<_Ty, ::std::true_type> {
  typedef task<_Ty> _ArgType;
};

template<typename _RetTypeT, typename _ArgTypeT> struct _StdFunctionTypeHelper {
  typedef ::std::function<_RetTypeT __cdecl(_ArgTypeT)> _StdFuncT;
};

template<typename _RetTypeT> struct _StdFunctionTypeHelper<_RetTypeT, void> {
  typedef ::std::function<_RetTypeT __cdecl()> _StdFuncT;
};
#endif

template<typename _Function, typename _ReturnType> struct _ContinuationTypeTraits {
  typedef task<
    typename _TaskTypeTraits<typename _FunctionTypeTraits<_Function, _ReturnType>::_FuncRetType>::_TaskRetType>
    _TaskOfType;
#ifndef _PPLTASKS_NO_STDFUNC
  typedef typename _ContinuationArgTypeHelper<
    _ReturnType, typename details::_FunctionTypeTraits<_Function, _ReturnType>::_Takes_task>::_ArgType _ArgTypeT;
  typedef typename _FunctionTypeTraits<_Function, _ReturnType>::_FuncRetType _RetTypeT;
  typedef typename _StdFunctionTypeHelper<_RetTypeT, _ArgTypeT>::_StdFuncT _StdFuncT;
#endif
};

template<typename _TaskType, typename _FuncRetType> struct _InitFunctorTypeTraits {
  typedef typename _TaskTypeTraits<_FuncRetType>::_AsyncKind _AsyncKind;
  static const bool _IsAsyncTask = _TaskTypeTraits<_FuncRetType>::_IsAsyncTask;
  static const bool _IsUnwrappedTaskOrAsync = _TaskTypeTraits<_FuncRetType>::_IsUnwrappedTaskOrAsync;
};

template<typename _Ty> struct _InitFunctorTypeTraits<_Ty, _Ty> {
  typedef _TypeSelectorNoAsync _AsyncKind;
  static const bool _IsAsyncTask = false;
  static const bool _IsUnwrappedTaskOrAsync = false;
};

struct _TaskProcThunk {
  _TaskProcThunk(const ::std::function<void()>& _Callback) : _M_func(_Callback) {}

  static void __cdecl _Bridge(void* _PData) {
    _TaskProcThunk* _PThunk = reinterpret_cast<_TaskProcThunk*>(_PData);
    _Holder _ThunkHolder(_PThunk);
    _PThunk->_M_func();
  }
private:
  struct _Holder {
    _Holder(_TaskProcThunk* _PThunk) : _M_pThunk(_PThunk) {}

    ~_Holder() { delete _M_pThunk; }

    _TaskProcThunk* _M_pThunk;

  private:
    _Holder& operator=(const _Holder&);
  };

  ::std::function<void()> _M_func;
  _TaskProcThunk& operator=(const _TaskProcThunk&);
};

inline void _ScheduleFuncWithAutoInline(const ::std::function<void()>& _Func, _TaskInliningMode_t _InliningMode) {
  _TaskCollection_t::_RunTask(&_TaskProcThunk::_Bridge, new _TaskProcThunk(_Func), _InliningMode);
}

class _ContextCallback {
  typedef ::std::function<void __cdecl()> _CallbackFunction;

public:
  static _ContextCallback _CaptureCurrent() {
    _ContextCallback _Context;
    _Context._Capture();
    return _Context;
  }

  ~_ContextCallback() { _Reset(); }

  _ContextCallback(bool _DeferCapture = false) noexcept {
    if (_DeferCapture) {
      _M_context._M_captureMethod = _S_captureDeferred;
    } else {
      _M_context._M_pContextCallback = nullptr;
    }
  }

  void _Resolve(bool _CaptureCurrent) {
    if (_M_context._M_captureMethod == _S_captureDeferred) {
      _M_context._M_pContextCallback = nullptr;

      if (_CaptureCurrent && _IsCurrentOriginSTA()) { _Capture(); }
    }
  }

  _ContextCallback(const _ContextCallback& _Src) { _Assign(_Src._M_context._M_pContextCallback); }

  _ContextCallback(_ContextCallback&& _Src) noexcept {
    _M_context._M_pContextCallback = _Src._M_context._M_pContextCallback;
    _Src._M_context._M_pContextCallback = nullptr;
  }

  _ContextCallback& operator=(const _ContextCallback& _Src) {
    if (this != &_Src) {
      _Reset();
      _Assign(_Src._M_context._M_pContextCallback);
    }
    return *this;
  }

  _ContextCallback& operator=(_ContextCallback&& _Src) noexcept {
    if (this != &_Src) {
      _M_context._M_pContextCallback = _Src._M_context._M_pContextCallback;
      _Src._M_context._M_pContextCallback = nullptr;
    }
    return *this;
  }

  bool _HasCapturedContext() const { return (_M_context._M_pContextCallback != nullptr); }

  bool operator==(const _ContextCallback& _Rhs) const {
    return (_M_context._M_pContextCallback == _Rhs._M_context._M_pContextCallback);
  }

  bool operator!=(const _ContextCallback& _Rhs) const { return !(operator==(_Rhs)); }

  _CRTIMP2 void __thiscall _CallInContext(_CallbackFunction _Func, bool _IgnoreDisconnect) const;

  void _CallInContext(_CallbackFunction _Func) const { _CallInContext(_Func, false); }

private:
  _CRTIMP2 void __thiscall _Reset();

  _CRTIMP2 void __thiscall _Assign(void* _PContextCallback);

  _CRTIMP2 static bool __cdecl _IsCurrentOriginSTA();

  _CRTIMP2 void __thiscall _Capture();

  union {
    void* _M_pContextCallback;
    size_t _M_captureMethod;
  } _M_context;

  static const size_t _S_captureDeferred = 1;
};

template<typename _Type> struct _ResultHolder {
  _ResultHolder() = default;

  void Set(const _Type& _type) { _Result = _type; }

  _Type Get() { return _Result; }

  _Type _Result;
};

template<> struct _ResultHolder<::std::vector<bool>> {
  void Set(const ::std::vector<bool>& _type) {
    _Result.resize(_type.size());
    ::std::transform(_type.begin(), _type.end(), _Result.begin(), [](bool _Val) { return static_cast<char>(_Val); });
  }

  ::std::vector<bool> Get() {
    ::std::vector<bool> _Ret(_Result.size());
    ::std::transform(_Result.begin(), _Result.end(), _Ret.begin(), [](char _Val) { return _Val != 0; });
    return _Ret;
  }

  ::std::vector<char> _Result;
};

struct _ExceptionHolder {
private:
#if !defined(_CRTBLD) && defined(UNDOCKED_WINDOWS_UCRT) && !_PPL_TASK_ERROR_REPORT_ENABLED
  void ReportUnhandledError() {}
#else
  _CRTIMP2 void __thiscall ReportUnhandledError();
#endif

public:
  explicit _ExceptionHolder(const ::std::exception_ptr& _E, const _TaskCreationCallstack& _stackTrace)
    : _M_exceptionObserved(0), _M_stdException(_E), _M_stackTrace(_stackTrace) {}

  __declspec(noinline) ~_ExceptionHolder() {
    if (_M_exceptionObserved == 0) { _REPORT_PPLTASK_UNOBSERVED_EXCEPTION(); }
  }

  void _RethrowUserException() {
    if (_M_exceptionObserved == 0) { atomic_exchange(_M_exceptionObserved, 1l); }

    ::std::rethrow_exception(_M_stdException);
  }

  atomic_long _M_exceptionObserved;

  ::std::exception_ptr _M_stdException;

  _TaskCreationCallstack _M_stackTrace;
};

}

class task_continuation_context : public details::_ContextCallback {
public:
  static task_continuation_context use_default() { return task_continuation_context{_Tag{}}; }

  static task_continuation_context get_current_winrt_context() {
    task_continuation_context _Current{_Tag{}};
    _Current._Resolve(true);
    return _Current;
  }

#if defined(__cplusplus_winrt) || defined(PPL_TASK_CONTEXT_ERROR_CONTROL)

  static task_continuation_context use_arbitrary() {
    task_continuation_context _Arbitrary{_Tag {}};
    _Arbitrary._Resolve(false);
    return _Arbitrary;
  }

  static task_continuation_context use_current() { return get_current_winrt_context(); }
#endif

  static task_continuation_context use_synchronous_execution() {
    task_continuation_context _Current{_Tag{}};
    _Current._Resolve(false);
    _Current._M_RunInline = true;
    return _Current;
  }

  bool _ForceInline() const { return _M_RunInline; }

private:
  _CRTIMP2 __thiscall task_continuation_context();
#if defined(UNDOCKED_WINDOWS_UCRT) || _PPL_TASK_CONTEXT_CONTROL_ENABLED
  explicit task_continuation_context(bool _Enable_context) : _ContextCallback(_Enable_context), _M_RunInline(false) {}
#endif

  struct _Tag {};
#if !defined(_CRTBLD) && _PPL_TASK_CONTEXT_CONTROL_ENABLED && !defined(_PPL_TASK_FORCE_DEFAULT_CTOR)
  explicit task_continuation_context(_Tag) : task_continuation_context(_PPL_TASK_CONTEXT_CONTROL_ENABLED) {}
#else
  explicit task_continuation_context(_Tag) : task_continuation_context() {}
#endif

  bool _M_RunInline;
};

class task_options;
namespace details {
struct _Internal_task_options {
  bool _M_hasPresetCreationCallstack;
  _TaskCreationCallstack _M_presetCreationCallstack;

  void _set_creation_callstack(const _TaskCreationCallstack& _callstack) {
    _M_hasPresetCreationCallstack = true;
    _M_presetCreationCallstack = _callstack;
  }
  _Internal_task_options() { _M_hasPresetCreationCallstack = false; }
};

inline _Internal_task_options& _get_internal_task_options(task_options& _Options);
inline const _Internal_task_options& _get_internal_task_options(const task_options& _Options);
}

class task_options {
public:
  task_options()
    : _M_Scheduler(get_ambient_scheduler()), _M_CancellationToken(cancellation_token::none()),
      _M_ContinuationContext(task_continuation_context::use_default()), _M_HasCancellationToken(false),
      _M_HasScheduler(false) {}

  task_options(cancellation_token _Token)
    : _M_Scheduler(get_ambient_scheduler()), _M_CancellationToken(_Token),
      _M_ContinuationContext(task_continuation_context::use_default()), _M_HasCancellationToken(true),
      _M_HasScheduler(false) {}

  task_options(task_continuation_context _ContinuationContext)
    : _M_Scheduler(get_ambient_scheduler()), _M_CancellationToken(cancellation_token::none()),
      _M_ContinuationContext(_ContinuationContext), _M_HasCancellationToken(false), _M_HasScheduler(false) {}

  task_options(cancellation_token _Token, task_continuation_context _ContinuationContext)
    : _M_Scheduler(get_ambient_scheduler()), _M_CancellationToken(_Token), _M_ContinuationContext(_ContinuationContext),
      _M_HasCancellationToken(true), _M_HasScheduler(false) {}

  template<typename _SchedType> task_options(::std::shared_ptr<_SchedType> _Scheduler)
    : _M_Scheduler(::std::move(_Scheduler)), _M_CancellationToken(cancellation_token::none()),
      _M_ContinuationContext(task_continuation_context::use_default()), _M_HasCancellationToken(false),
      _M_HasScheduler(true) {}

  task_options(scheduler_interface& _Scheduler)
    : _M_Scheduler(&_Scheduler), _M_CancellationToken(cancellation_token::none()),
      _M_ContinuationContext(task_continuation_context::use_default()), _M_HasCancellationToken(false),
      _M_HasScheduler(true) {}

  task_options(scheduler_ptr _Scheduler)
    : _M_Scheduler(::std::move(_Scheduler)), _M_CancellationToken(cancellation_token::none()),
      _M_ContinuationContext(task_continuation_context::use_default()), _M_HasCancellationToken(false),
      _M_HasScheduler(true) {}

  task_options(const task_options& _TaskOptions)
    : _M_Scheduler(_TaskOptions.get_scheduler()), _M_CancellationToken(_TaskOptions.get_cancellation_token()),
      _M_ContinuationContext(_TaskOptions.get_continuation_context()),
      _M_HasCancellationToken(_TaskOptions.has_cancellation_token()), _M_HasScheduler(_TaskOptions.has_scheduler()) {}

  void set_cancellation_token(cancellation_token _Token) {
    _M_CancellationToken = _Token;
    _M_HasCancellationToken = true;
  }

  void set_continuation_context(task_continuation_context _ContinuationContext) {
    _M_ContinuationContext = _ContinuationContext;
  }

  bool has_cancellation_token() const { return _M_HasCancellationToken; }

  cancellation_token get_cancellation_token() const { return _M_CancellationToken; }

  task_continuation_context get_continuation_context() const { return _M_ContinuationContext; }

  bool has_scheduler() const { return _M_HasScheduler; }

  scheduler_ptr get_scheduler() const { return _M_Scheduler; }

private:
  task_options const& operator=(task_options const& _Right);
  friend details::_Internal_task_options& details::_get_internal_task_options(task_options&);
  friend const details::_Internal_task_options& details::_get_internal_task_options(const task_options&);

  scheduler_ptr _M_Scheduler;
  cancellation_token _M_CancellationToken;
  task_continuation_context _M_ContinuationContext;
  details::_Internal_task_options _M_InternalTaskOptions;
  bool _M_HasCancellationToken;
  bool _M_HasScheduler;
};

namespace details {

struct _ThenImplOptions {
  _ThenImplOptions(_CancellationTokenState* _Token_state, const task_continuation_context* _Continuation_context,
                   scheduler_ptr _PScheduler, _TaskCreationCallstack _Creation_stack,
                   _TaskInliningMode_t _Inlining_mode = _NoInline)
    : _PTokenState(_Token_state), _Scheduler(_PScheduler), _CreationStack(_Creation_stack),
      _InliningMode(_Inlining_mode),
      _PContinuationContext(const_cast<task_continuation_context*>(_Continuation_context)) {}

  _CancellationTokenState* _PTokenState;
  scheduler_ptr _Scheduler;
  _TaskCreationCallstack _CreationStack;
  _TaskInliningMode_t _InliningMode;
  task_continuation_context* _PContinuationContext;

  static _ThenImplOptions _CreateOptions(const task_options& _Task_Options,
                                         const task_continuation_context& _ContinuationContext,
                                         const scheduler_ptr& impl_scheduler) {
    _CancellationTokenState* _TokenState =
      _Task_Options.has_cancellation_token() ? _Task_Options.get_cancellation_token()._GetImplValue() : nullptr;
    auto _Scheduler = _Task_Options.has_scheduler() ? _Task_Options.get_scheduler() : impl_scheduler;
    auto _InliningMode =
      _Task_Options.get_continuation_context()._ForceInline() ? details::_ForceInline : details::_NoInline;

    auto _Task_Options_Int = details::_get_internal_task_options(_Task_Options);
    auto _CreationStack = _Task_Options_Int._M_hasPresetCreationCallstack ? _Task_Options_Int._M_presetCreationCallstack
                                                                          : details::_TaskCreationCallstack();

    return _ThenImplOptions(_TokenState, &_ContinuationContext, _Scheduler, _CreationStack, _InliningMode);
  }
};

inline _Internal_task_options& _get_internal_task_options(task_options& _Options) {
  return _Options._M_InternalTaskOptions;
}
inline const _Internal_task_options& _get_internal_task_options(const task_options& _Options) {
  return _Options._M_InternalTaskOptions;
}

struct _Task_impl_base;
template<typename _ReturnType> struct _Task_impl;

template<typename _ReturnType> struct _Task_ptr {
  typedef ::std::shared_ptr<_Task_impl<_ReturnType>> _Type;
  static _Type _Make(_CancellationTokenState* _Ct, scheduler_ptr _Scheduler_arg) {
    return ::std::make_shared<_Task_impl<_ReturnType>>(_Ct, _Scheduler_arg);
  }
};

typedef _TaskCollection_t::_TaskProcHandle_t _UnrealizedChore_t;
typedef ::std::shared_ptr<_Task_impl_base> _Task_ptr_base;

struct _ContinuationTaskHandleBase : _UnrealizedChore_t {
  _ContinuationTaskHandleBase* _M_next;
  task_continuation_context _M_continuationContext;
  bool _M_isTaskBasedContinuation;

  _TaskInliningMode_t _M_inliningMode;

  virtual _Task_ptr_base _GetTaskImplBase() const = 0;

  _ContinuationTaskHandleBase()
    : _M_next(nullptr), _M_continuationContext(task_continuation_context::use_default()),
      _M_isTaskBasedContinuation(false), _M_inliningMode(details::_NoInline) {}

  virtual ~_ContinuationTaskHandleBase() {}
};

#if _PPLTASK_ASYNC_LOGGING

struct _TaskEventLogger {
  _Task_impl_base* _M_task;
  bool _M_scheduled;
  bool _M_taskPostEventStarted;

  _CRTIMP2 void __thiscall _LogScheduleTask(bool _isContinuation);

  _CRTIMP2 void __thiscall _LogCancelTask();

  _CRTIMP2 void __thiscall _LogTaskCompleted();

  void _LogTaskExecutionStarted() {}

  _CRTIMP2 void __thiscall _LogTaskExecutionCompleted();

  _CRTIMP2 void __thiscall _LogWorkItemStarted();

  _CRTIMP2 void __thiscall _LogWorkItemCompleted();

  _TaskEventLogger(_Task_impl_base* _task) : _M_task(_task) {
    _M_scheduled = false;
    _M_taskPostEventStarted = false;
  }
};

struct _TaskWorkItemRAIILogger {
  _TaskEventLogger& _M_logger;
  _TaskWorkItemRAIILogger(_TaskEventLogger& _taskHandleLogger) : _M_logger(_taskHandleLogger) {
    _M_logger._LogWorkItemStarted();
  }

  ~_TaskWorkItemRAIILogger() { _M_logger._LogWorkItemCompleted(); }
  _TaskWorkItemRAIILogger& operator=(const _TaskWorkItemRAIILogger&);
};

#else
inline void _LogCancelTask(_Task_impl_base*) {}
struct _TaskEventLogger {
  void _LogScheduleTask(bool) {}
  void _LogCancelTask() {}
  void _LogWorkItemStarted() {}
  void _LogWorkItemCompleted() {}
  void _LogTaskExecutionStarted() {}
  void _LogTaskExecutionCompleted() {}
  void _LogTaskCompleted() {}
  _TaskEventLogger(_Task_impl_base*) {}
};
struct _TaskWorkItemRAIILogger {
  _TaskWorkItemRAIILogger(_TaskEventLogger&) {}
};
#endif

template<typename _ReturnType, typename _DerivedTaskHandle, typename _BaseTaskHandle> struct _PPLTaskHandle :
  _BaseTaskHandle {
  _PPLTaskHandle(const typename _Task_ptr<_ReturnType>::_Type& _PTask) : _M_pTask(_PTask) {}

  virtual ~_PPLTaskHandle() { _M_pTask->_M_taskEventLogger._LogTaskCompleted(); }

  virtual void invoke() const {

    if (!_M_pTask->_TransitionedToStarted()) {
      static_cast<const _DerivedTaskHandle*>(this)->_SyncCancelAndPropagateException();
      return;
    }

    _M_pTask->_M_taskEventLogger._LogTaskExecutionStarted();

    _TRY_BEGIN

    static_cast<const _DerivedTaskHandle*>(this)->_Perform();
    _CATCH(const task_canceled&)
    _M_pTask->_Cancel(true);
    _CATCH(const _Interruption_exception&)
    _M_pTask->_Cancel(true);
    _CATCH_ALL
    _M_pTask->_CancelWithException(::std::current_exception());
    _CATCH_END
    _M_pTask->_M_taskEventLogger._LogTaskExecutionCompleted();
  }

  _Task_ptr_base _GetTaskImplBase() const { return _M_pTask; }

  typename _Task_ptr<_ReturnType>::_Type _M_pTask;
private:
  _PPLTaskHandle const& operator=(_PPLTaskHandle const&);
};

struct _Task_impl_base {
  enum _TaskInternalState {

    _Created,
    _Started,
    _PendingCancel,
    _Completed,
    _Canceled
  };

  _Task_impl_base(_CancellationTokenState* _PTokenState, scheduler_ptr _Scheduler_arg)
    : _M_TaskState(_Created), _M_fFromAsync(false), _M_fUnwrappedTask(false), _M_Continuations(nullptr),
      _M_pRegistration(nullptr), _M_TaskCollection(_Scheduler_arg), _M_taskEventLogger(this) {
    _M_pTokenState = _PTokenState;
    if (_M_pTokenState != _CancellationTokenState::_None()) _M_pTokenState->_Reference();
  }

  virtual ~_Task_impl_base() {
    if (_M_pTokenState != _CancellationTokenState::_None()) { _M_pTokenState->_Release(); }
  }

  task_status _Wait() {
    bool _DoWait = true;

#if (_PPL_TASK_CONTEXT_CONTROL_ENABLED)
    if (_IsNonBlockingThread()) {

      if (!_IsCompleted() && !_IsCanceled()) {
        _THROW(invalid_operation("Illegal to wait on a task in a Windows Runtime STA"));
      } else {

        _DoWait = false;
      }
    }
#endif

    if (_DoWait) {

      if (_M_fFromAsync) {
        _M_TaskCollection._Wait();
      } else {

        _TRY_BEGIN

        _M_TaskCollection._RunAndWait();
        _CATCH(details::_Interruption_exception&)
        _CATCH(task_canceled&)

        _CATCH_ALL

        if (!_HasUserException()) { _CancelWithException(::std::current_exception()); }

        _M_exceptionHolder->_RethrowUserException();
        _CATCH_END

        if (_M_fUnwrappedTask) { _M_TaskCollection._Wait(); }
      }
    }

    if (_HasUserException()) {
      _M_exceptionHolder->_RethrowUserException();
    } else if (_IsCanceled()) {
      return canceled;
    }
    return completed;
  }

  virtual bool _CancelAndRunContinuations(bool _SynchronousCancel, bool _UserException, bool _PropagatedFromAncestor,
                                          const ::std::shared_ptr<_ExceptionHolder>& _ExHolder) = 0;

  bool _Cancel(bool _SynchronousCancel) {

    return _CancelAndRunContinuations(_SynchronousCancel, false, false, _M_exceptionHolder);
  }

  bool _CancelWithExceptionHolder(const ::std::shared_ptr<_ExceptionHolder>& _ExHolder, bool _PropagatedFromAncestor) {

    return _CancelAndRunContinuations(true, true, _PropagatedFromAncestor, _ExHolder);
  }

  bool _CancelWithException(const ::std::exception_ptr& _Exception) {

    return _CancelAndRunContinuations(true, true, false,
                                      ::std::make_shared<_ExceptionHolder>(_Exception, _GetTaskCreationCallstack()));
  }

  void _RegisterCancellation(::std::weak_ptr<_Task_impl_base> _WeakPtr) {

    auto _CancellationCallback = [_WeakPtr]() {
      auto _task = _WeakPtr.lock();
      if (_task != nullptr) _task->_Cancel(false);
    };

    _M_pRegistration = new details::_CancellationTokenCallback<decltype(_CancellationCallback)>(_CancellationCallback);
    _M_pTokenState->_RegisterCallback(_M_pRegistration);
  }

  void _DeregisterCancellation() {
    if (_M_pRegistration != nullptr) {
      _M_pTokenState->_DeregisterCallback(_M_pRegistration);
      _M_pRegistration->_Release();
      _M_pRegistration = nullptr;
    }
  }

  bool _IsCreated() { return (_M_TaskState == _Created); }

  bool _IsStarted() { return (_M_TaskState == _Started); }

  bool _IsPendingCancel() { return (_M_TaskState == _PendingCancel); }

  bool _IsCompleted() { return (_M_TaskState == _Completed); }

  bool _IsCanceled() { return (_M_TaskState == _Canceled); }

  bool _HasUserException() { return static_cast<bool>(_M_exceptionHolder); }

  const ::std::shared_ptr<_ExceptionHolder>& _GetExceptionHolder() { return _M_exceptionHolder; }

  bool _IsApartmentAware() { return _M_fFromAsync; }

  void _SetAsync(bool _Async = true) { _M_fFromAsync = _Async; }

  _TaskCreationCallstack _GetTaskCreationCallstack() { return _M_pTaskCreationCallstack; }

  void _SetTaskCreationCallstack(const _TaskCreationCallstack& _Callstack) { _M_pTaskCreationCallstack = _Callstack; }

  void _ScheduleTask(_UnrealizedChore_t* _PTaskHandle, _TaskInliningMode_t _InliningMode) {
    _TRY_BEGIN
    _M_TaskCollection._ScheduleTask(_PTaskHandle, _InliningMode);
    _CATCH(const task_canceled&)

    _CATCH(const _Interruption_exception&)

    _CATCH_ALL

    if (!_HasUserException()) { _CancelWithException(::std::current_exception()); }
    _CATCH_END
  }

  void _RunContinuation(_ContinuationTaskHandleBase* _PTaskHandle) {
    _Task_ptr_base _ImplBase = _PTaskHandle->_GetTaskImplBase();
    if (_IsCanceled() && !_PTaskHandle->_M_isTaskBasedContinuation) {
      if (_HasUserException()) {

        _ImplBase->_CancelWithExceptionHolder(_GetExceptionHolder(), true);
      } else {

        _ImplBase->_Cancel(true);
      }
    } else {

      return _ImplBase->_ScheduleContinuationTask(_PTaskHandle);
    }

    delete _PTaskHandle;
  }

  void _ScheduleContinuationTask(_ContinuationTaskHandleBase* _PTaskHandle) {

    _M_taskEventLogger._LogScheduleTask(true);

    if (_PTaskHandle->_M_continuationContext._HasCapturedContext()) {

      if (_PTaskHandle->_M_inliningMode != details::_ForceInline) {
        _PTaskHandle->_M_inliningMode = details::_DefaultAutoInline;
      }
      _ScheduleFuncWithAutoInline(
        [_PTaskHandle]() {
          auto _TaskImplPtr = _PTaskHandle->_GetTaskImplBase();
          if (details::_ContextCallback::_CaptureCurrent() == _PTaskHandle->_M_continuationContext) {
            _TaskImplPtr->_ScheduleTask(_PTaskHandle, details::_ForceInline);
          } else {

            _TRY_BEGIN
            _PTaskHandle->_M_continuationContext._CallInContext(
              [_PTaskHandle, _TaskImplPtr]() { _TaskImplPtr->_ScheduleTask(_PTaskHandle, details::_ForceInline); });
            _CATCH_ALL
            _TaskImplPtr->_CancelWithException(::std::current_exception());
            _CATCH_END
          }
        },
        _PTaskHandle->_M_inliningMode);
    } else {
      _ScheduleTask(_PTaskHandle, _PTaskHandle->_M_inliningMode);
    }
  }

  void _ScheduleContinuation(_ContinuationTaskHandleBase* _PTaskHandle) {
    enum { _Nothing, _Schedule, _Cancel, _CancelWithException } _Do = _Nothing;

    {
      ::std::lock_guard<::std::mutex> _LockHolder(_M_ContinuationsCritSec);
      if (_IsCompleted() || (_IsCanceled() && _PTaskHandle->_M_isTaskBasedContinuation)) {
        _Do = _Schedule;
      } else if (_IsCanceled()) {
        if (_HasUserException()) {
          _Do = _CancelWithException;
        } else {
          _Do = _Cancel;
        }
      } else {

        _PTaskHandle->_M_next = _M_Continuations;
        _M_Continuations = _PTaskHandle;
      }
    }

    switch (_Do) {
    case _Schedule: {
      _PTaskHandle->_GetTaskImplBase()->_ScheduleContinuationTask(_PTaskHandle);
      break;
    }
    case _Cancel: {

      _PTaskHandle->_GetTaskImplBase()->_Cancel(true);

      delete _PTaskHandle;
      break;
    }
    case _CancelWithException: {

      _PTaskHandle->_GetTaskImplBase()->_CancelWithExceptionHolder(_GetExceptionHolder(), true);

      delete _PTaskHandle;
      break;
    }
    case _Nothing:
    default: break;
    }
  }

  void _RunTaskContinuations() {

    _ContinuationList _Cur = _M_Continuations, _Next;
    _M_Continuations = nullptr;
    while (_Cur) {

      _Next = _Cur->_M_next;
      _RunContinuation(_Cur);
      _Cur = _Next;
    }
  }

  _CRTIMP2 static bool __cdecl _IsNonBlockingThread();

  template<typename _ReturnType, typename _InternalReturnType>
  static void _AsyncInit(const typename _Task_ptr<_ReturnType>::_Type& _OuterTask,
                         const task<_InternalReturnType>& _UnwrappedTask) {

    _UnwrappedTask._Then(
      [_OuterTask](task<_InternalReturnType> _AncestorTask) {
        if (_AncestorTask._GetImpl()->_IsCompleted()) {
          _OuterTask->_FinalizeAndRunContinuations(_AncestorTask._GetImpl()->_GetResult());
        } else {
          if (_AncestorTask._GetImpl()->_HasUserException()) {

            _OuterTask->_CancelWithExceptionHolder(_AncestorTask._GetImpl()->_GetExceptionHolder(), false);
          } else {
            _OuterTask->_Cancel(true);
          }
        }
      },
      nullptr, details::_DefaultAutoInline);
  }

  scheduler_ptr _GetScheduler() const { return _M_TaskCollection._GetScheduler(); }

  volatile _TaskInternalState _M_TaskState;

  bool _M_fFromAsync;

  bool _M_fUnwrappedTask;

  ::std::shared_ptr<_ExceptionHolder> _M_exceptionHolder;

  typedef _ContinuationTaskHandleBase* _ContinuationList;

  ::std::mutex _M_ContinuationsCritSec;
  _ContinuationList _M_Continuations;

  _CancellationTokenState* _M_pTokenState;

  _CancellationTokenRegistration* _M_pRegistration;

  ::Concurrency::details::_TaskCollection_t _M_TaskCollection;

  _TaskCreationCallstack _M_pTaskCreationCallstack;

  _TaskEventLogger _M_taskEventLogger;
private:
  _Task_impl_base(const _Task_impl_base&);
  _Task_impl_base const& operator=(_Task_impl_base const&);
};

template<typename _ReturnType> struct _Task_impl : public _Task_impl_base {
#pragma warning(push)
#pragma warning(disable : 26495)
  _Task_impl(_CancellationTokenState* _Ct, scheduler_ptr _Scheduler_arg) : _Task_impl_base(_Ct, _Scheduler_arg) {}
#pragma warning(pop)

  virtual ~_Task_impl() { _DeregisterCancellation(); }

  virtual bool _CancelAndRunContinuations(bool _SynchronousCancel, bool _UserException, bool _PropagatedFromAncestor,
                                          const ::std::shared_ptr<_ExceptionHolder>& _ExceptionHolder_arg) override {
    enum { _Nothing, _RunContinuations, _Cancel } _Do = _Nothing;
    {
      ::std::lock_guard<::std::mutex> _LockHolder(_M_ContinuationsCritSec);
      if (_UserException) {

        if (_M_TaskState == _Canceled) {

          return false;
        } else {
          _M_exceptionHolder = _ExceptionHolder_arg;
        }
      } else {

        if (_IsCompleted() || _IsCanceled() || (_IsPendingCancel() && !_SynchronousCancel)) { return false; }
      }

      if (_SynchronousCancel) {

        _M_TaskState = _Canceled;

        _Do = _RunContinuations;
      } else {

        if (_IsStarted()) { _Do = _Cancel; }

        _M_TaskState = _PendingCancel;

        _M_taskEventLogger._LogCancelTask();
      }
    }

    switch (_Do) {
    case _Cancel: {
      if (_M_InternalCancellation) { _M_InternalCancellation(); }
      _M_TaskCollection._Cancel();
      break;
    }
    case _RunContinuations: {

      _M_TaskCollection._Complete();

      if (_M_Continuations) {

        _ScheduleFuncWithAutoInline([this]() { _RunTaskContinuations(); }, details::_DefaultAutoInline);
      }

      break;
    }
    case _Nothing:
    default: break;
    }
    return true;
  }

  void _FinalizeAndRunContinuations(_ReturnType _Result) {
    _M_Result.Set(_Result);

    {

      ::std::lock_guard<::std::mutex> _LockHolder(_M_ContinuationsCritSec);

      if (_IsCanceled()) { return; }

      _M_TaskState = _Completed;
    }
    _M_TaskCollection._Complete();
    _RunTaskContinuations();
  }

  bool _TransitionedToStarted() {
    ::std::lock_guard<::std::mutex> _LockHolder(_M_ContinuationsCritSec);
    if (_IsPendingCancel()) return false;
    _M_TaskState = _Started;
    return true;
  }

  bool _IsDone() { return _IsCompleted() || _IsCanceled(); }

  _ReturnType _GetResult() { return _M_Result.Get(); }

  _ResultHolder<_ReturnType> _M_Result;
  ::std::function<void()> _M_InternalCancellation;
};

template<typename _ResultType> struct _Task_completion_event_impl {
private:
  _Task_completion_event_impl(const _Task_completion_event_impl&);
  _Task_completion_event_impl& operator=(const _Task_completion_event_impl&);

public:
  typedef ::std::vector<typename _Task_ptr<_ResultType>::_Type> _TaskList;

#pragma warning(push)
#pragma warning(disable : 26495)
  _Task_completion_event_impl() : _M_fHasValue(false), _M_fIsCanceled(false) {}
#pragma warning(pop)

  bool _HasUserException() { return _M_exceptionHolder != nullptr; }

  ~_Task_completion_event_impl() {
    for (auto _TaskIt = _M_tasks.begin(); _TaskIt != _M_tasks.end(); ++_TaskIt) { (*_TaskIt)->_Cancel(true); }
  }

  _TaskList _M_tasks;
  ::std::mutex _M_taskListCritSec;
  _ResultHolder<_ResultType> _M_value;
  ::std::shared_ptr<_ExceptionHolder> _M_exceptionHolder;
  bool _M_fHasValue;
  bool _M_fIsCanceled;
};

inline ::std::function<_Unit_type()> _MakeVoidToUnitFunc(const ::std::function<void()>& _Func) {
  return [=]() -> _Unit_type {
    _Func();
    return _Unit_type();
  };
}

template<typename _Type>::std::function<_Type(_Unit_type)> _MakeUnitToTFunc(const ::std::function<_Type()>& _Func) {
  return [=](_Unit_type) -> _Type { return _Func(); };
}

template<typename _Type>::std::function<_Unit_type(_Type)> _MakeTToUnitFunc(const ::std::function<void(_Type)>& _Func) {
  return [=](_Type _Obj) -> _Unit_type {
    _Func(_Obj);
    return _Unit_type();
  };
}

inline ::std::function<_Unit_type(_Unit_type)> _MakeUnitToUnitFunc(const ::std::function<void()>& _Func) {
  return [=](_Unit_type) -> _Unit_type {
    _Func();
    return _Unit_type();
  };
}
}

template<typename _ResultType> class task_completion_event {
public:
  task_completion_event() : _M_Impl(::std::make_shared<details::_Task_completion_event_impl<_ResultType>>()) {}

  bool set(_ResultType _Result) const {

    if (_IsTriggered()) { return false; }

    _TaskList _Tasks;
    bool _RunContinuations = false;
    {
      ::std::lock_guard<::std::mutex> _LockHolder(_M_Impl->_M_taskListCritSec);

      if (!_IsTriggered()) {
        _M_Impl->_M_value.Set(_Result);
        _M_Impl->_M_fHasValue = true;

        _Tasks.swap(_M_Impl->_M_tasks);
        _RunContinuations = true;
      }
    }

    if (_RunContinuations) {
      for (auto _TaskIt = _Tasks.begin(); _TaskIt != _Tasks.end(); ++_TaskIt) {

        if ((*_TaskIt)->_IsPendingCancel()) (*_TaskIt)->_Cancel(true);
        else { (*_TaskIt)->_FinalizeAndRunContinuations(_M_Impl->_M_value.Get()); }
      }

      return true;
    }

    return false;
  }

  template<typename _E> __declspec(noinline) bool set_exception(_E _Except) const {

    return _Cancel(::std::make_exception_ptr(_Except), _CAPTURE_CALLSTACK());
  }

  __declspec(noinline) bool set_exception(::std::exception_ptr _ExceptionPtr) const {

    return _Cancel(_ExceptionPtr, _CAPTURE_CALLSTACK());
  }

  bool _Cancel() const { return _CancelInternal(); }

  template<typename _ExHolderType> bool
  _Cancel(_ExHolderType _ExHolder,
          const details::_TaskCreationCallstack& _SetExceptionAddressHint = details::_TaskCreationCallstack()) const {
    bool _Canceled;
    if (_StoreException(_ExHolder, _SetExceptionAddressHint)) {
      _Canceled = _CancelInternal();
    } else {
      _Canceled = false;
    }
    return _Canceled;
  }

  template<typename _ExHolderType>
  bool _StoreException(_ExHolderType _ExHolder, const details::_TaskCreationCallstack& _SetExceptionAddressHint =
                                                  details::_TaskCreationCallstack()) const {
    ::std::lock_guard<::std::mutex> _LockHolder(_M_Impl->_M_taskListCritSec);
    if (!_IsTriggered() && !_M_Impl->_HasUserException()) {

      _M_Impl->_M_exceptionHolder = _ToExceptionHolder(_ExHolder, _SetExceptionAddressHint);
      return true;
    }
    return false;
  }

  void _ClearStoredException() const {
    ::std::lock_guard<::std::mutex> _LockHolder(_M_Impl->_M_taskListCritSec);
    if (_M_Impl->_M_exceptionHolder) {
      details::atomic_exchange(_M_Impl->_M_exceptionHolder->_M_exceptionObserved, 1l);
      _M_Impl->_M_exceptionHolder.reset();
    }
  }

  bool _IsTriggered() const { return _M_Impl->_M_fHasValue || _M_Impl->_M_fIsCanceled; }

private:
  static ::std::shared_ptr<details::_ExceptionHolder>
  _ToExceptionHolder(const ::std::shared_ptr<details::_ExceptionHolder>& _ExHolder,
                     const details::_TaskCreationCallstack&) {
    return _ExHolder;
  }

  static ::std::shared_ptr<details::_ExceptionHolder>
  _ToExceptionHolder(::std::exception_ptr _ExceptionPtr,
                     const details::_TaskCreationCallstack& _SetExceptionAddressHint) {
    return ::std::make_shared<details::_ExceptionHolder>(_ExceptionPtr, _SetExceptionAddressHint);
  }

  template<typename _Ty> friend class task;
  template<typename _Ty> friend class task_completion_event;

  typedef typename details::_Task_completion_event_impl<_ResultType>::_TaskList _TaskList;

  bool _CancelInternal() const {

    if (_M_Impl->_M_fIsCanceled) { return false; }

    _TaskList _Tasks;
    bool _Cancel = false;
    {
      ::std::lock_guard<::std::mutex> _LockHolder(_M_Impl->_M_taskListCritSec);
      if (!_M_Impl->_M_fIsCanceled) {
        _M_Impl->_M_fIsCanceled = true;
        _Tasks.swap(_M_Impl->_M_tasks);
        _Cancel = true;
      }
    }

    const bool _UserException = _M_Impl->_HasUserException();

    if (_Cancel) {
      for (auto _TaskIt = _Tasks.begin(); _TaskIt != _Tasks.end(); ++_TaskIt) {

        if (_UserException) {
          (*_TaskIt)->_CancelWithExceptionHolder(_M_Impl->_M_exceptionHolder, true);
        } else {
          (*_TaskIt)->_Cancel(true);
        }
      }
    }
    return _Cancel;
  }

  void _RegisterTask(const typename details::_Task_ptr<_ResultType>::_Type& _TaskParam) {
    enum { _Nothing, _Trigger, _Cancel } _Action = _Nothing;
    {
      ::std::lock_guard<::std::mutex> _LockHolder(_M_Impl->_M_taskListCritSec);

      if (_M_Impl->_HasUserException()) {
        _Action = _Cancel;
      } else if (_M_Impl->_M_fHasValue) {
        _Action = _Trigger;
      } else {
        _M_Impl->_M_tasks.push_back(_TaskParam);
      }
    }

    switch (_Action) {
    case _Trigger: _TaskParam->_FinalizeAndRunContinuations(_M_Impl->_M_value.Get()); break;
    case _Cancel: _TaskParam->_CancelWithExceptionHolder(_M_Impl->_M_exceptionHolder, true); break;
    case _Nothing:
    default: break;
    }
  }

  ::std::shared_ptr<details::_Task_completion_event_impl<_ResultType>> _M_Impl;
};

template<> class task_completion_event<void> {
public:
  bool set() const { return _M_unitEvent.set(details::_Unit_type()); }

  template<typename _E> __declspec(noinline) bool set_exception(_E _Except) const {
    return _M_unitEvent._Cancel(::std::make_exception_ptr(_Except), _CAPTURE_CALLSTACK());
  }

  __declspec(noinline) bool set_exception(::std::exception_ptr _ExceptionPtr) const {

    return _M_unitEvent._Cancel(_ExceptionPtr, _CAPTURE_CALLSTACK());
  }

  void _Cancel() const { _M_unitEvent._Cancel(); }

  void _Cancel(const ::std::shared_ptr<details::_ExceptionHolder>& _ExHolder) const { _M_unitEvent._Cancel(_ExHolder); }

  bool _StoreException(const ::std::shared_ptr<details::_ExceptionHolder>& _ExHolder) const {
    return _M_unitEvent._StoreException(_ExHolder);
  }

  void _ClearStoredException() const { _M_unitEvent._ClearStoredException(); }

  bool _IsTriggered() const { return _M_unitEvent._IsTriggered(); }

private:
  template<typename _Ty> friend class task;

  void _RegisterTask(details::_Task_ptr<details::_Unit_type>::_Type _TaskParam) {
    _M_unitEvent._RegisterTask(_TaskParam);
  }

  task_completion_event<details::_Unit_type> _M_unitEvent;
};

namespace details {

template<typename _ReturnType, typename _Ty> auto _IsValidTaskCtor(_Ty _Param, int, int, int, int)
  -> decltype(_Param(), ::std::true_type());

template<typename _ReturnType, typename _Ty> auto _IsValidTaskCtor(_Ty _Param, int, int, ...)
  -> decltype(_Param.set(details::declval<_ReturnType>()), ::std::true_type());

template<typename _ReturnType, typename _Ty> auto _IsValidTaskCtor(_Ty _Param, int, ...)
  -> decltype(_Param.set(), ::std::true_type());

template<typename _ReturnType, typename _Ty>::std::false_type _IsValidTaskCtor(_Ty _Param, ...);

template<typename _ReturnType, typename _Ty> void _ValidateTaskConstructorArgs(const _Ty& _Param) {
  static_assert(::std::is_same_v<decltype(_IsValidTaskCtor<_ReturnType, _Ty>(_Param, 0, 0, 0, 0)), ::std::true_type>,

                "incorrect argument for task constructor; must be either a callable object or a task_completion_event");
}

class _ProgressReporterCtorArgType {};

}

template<typename _InpType, typename _OutType> class _Continuation_func_transformer {
public:
  static auto _Perform(::std::function<_OutType(_InpType)> _Func) -> decltype(_Func) { return _Func; }
};

template<typename _OutType> class _Continuation_func_transformer<void, _OutType> {
public:
  static auto _Perform(::std::function<_OutType()> _Func) -> decltype(details::_MakeUnitToTFunc<_OutType>(_Func)) {
    return details::_MakeUnitToTFunc<_OutType>(_Func);
  }
};

template<typename _InType> class _Continuation_func_transformer<_InType, void> {
public:
  static auto _Perform(::std::function<void(_InType)> _Func) -> decltype(details::_MakeTToUnitFunc<_InType>(_Func)) {
    return details::_MakeTToUnitFunc<_InType>(_Func);
  }
};

template<> class _Continuation_func_transformer<void, void> {
public:
  static auto _Perform(::std::function<void()> _Func) -> decltype(details::_MakeUnitToUnitFunc(_Func)) {
    return details::_MakeUnitToUnitFunc(_Func);
  }
};

template<typename _RetType> class _Init_func_transformer {
public:
  static auto _Perform(::std::function<_RetType()> _Func) -> decltype(_Func) { return _Func; }
};

template<> class _Init_func_transformer<void> {
public:
  static auto _Perform(::std::function<void()> _Func) -> decltype(details::_MakeVoidToUnitFunc(_Func)) {
    return details::_MakeVoidToUnitFunc(_Func);
  }
};

template<typename _ReturnType> class task {
public:
  typedef _ReturnType result_type;

  task() noexcept : _M_Impl(nullptr) {}

  template<typename _Ty> __declspec(noinline) explicit task(_Ty _Param) {
    task_options _TaskOptions;
    details::_ValidateTaskConstructorArgs<_ReturnType, _Ty>(_Param);

    _CreateImpl(_TaskOptions.get_cancellation_token()._GetImplValue(), _TaskOptions.get_scheduler());

    _SetTaskCreationCallstack(_CAPTURE_CALLSTACK());

    _TaskInitMaybeFunctor(_Param, decltype(details::_IsCallable(_Param, 0))());
  }

  template<typename _Ty> __declspec(noinline) explicit task(_Ty _Param, const task_options& _TaskOptions) {
    details::_ValidateTaskConstructorArgs<_ReturnType, _Ty>(_Param);

    _CreateImpl(_TaskOptions.get_cancellation_token()._GetImplValue(), _TaskOptions.get_scheduler());

    _SetTaskCreationCallstack(details::_get_internal_task_options(_TaskOptions)._M_hasPresetCreationCallstack
                                ? details::_get_internal_task_options(_TaskOptions)._M_presetCreationCallstack
                                : _CAPTURE_CALLSTACK());

    _TaskInitMaybeFunctor(_Param, decltype(details::_IsCallable(_Param, 0))());
  }

  task(const task& _Other) noexcept : _M_Impl(_Other._M_Impl) {}

  task(task&& _Other) noexcept : _M_Impl(::std::move(_Other._M_Impl)) {}

  task& operator=(const task& _Other) noexcept {
    if (this != &_Other) { _M_Impl = _Other._M_Impl; }
    return *this;
  }

  task& operator=(task&& _Other) noexcept {
    if (this != &_Other) { _M_Impl = ::std::move(_Other._M_Impl); }
    return *this;
  }

  template<typename _Function> __declspec(noinline) auto then(const _Function& _Func) const ->
    typename details::_ContinuationTypeTraits<_Function, _ReturnType>::_TaskOfType {
    task_options _TaskOptions;
    details::_get_internal_task_options(_TaskOptions)._set_creation_callstack(_CAPTURE_CALLSTACK());

    auto _ContinuationContext = _TaskOptions.get_continuation_context();
    auto _Options =
      details::_ThenImplOptions::_CreateOptions(_TaskOptions, _ContinuationContext, _ThenGetImpl()->_GetScheduler());

#ifndef _PPLTASKS_NO_STDFUNC
    return _ThenImpl<_ReturnType>(typename details::_ContinuationTypeTraits<_Function, _ReturnType>::_StdFuncT(_Func),
                                  _Options);
#else
    return _ThenImpl<_ReturnType>(_Func, _Options);
#endif
  }

  template<typename _Function> __declspec(noinline) auto then(const _Function& _Func, task_options _TaskOptions) const
    -> typename details::_ContinuationTypeTraits<_Function, _ReturnType>::_TaskOfType {
    details::_get_internal_task_options(_TaskOptions)._set_creation_callstack(_CAPTURE_CALLSTACK());

    auto _ContinuationContext = _TaskOptions.get_continuation_context();
    auto _Options =
      details::_ThenImplOptions::_CreateOptions(_TaskOptions, _ContinuationContext, _ThenGetImpl()->_GetScheduler());

#ifndef _PPLTASKS_NO_STDFUNC
    return _ThenImpl<_ReturnType>(typename details::_ContinuationTypeTraits<_Function, _ReturnType>::_StdFuncT(_Func),
                                  _Options);
#else
    return _ThenImpl<_ReturnType>(_Func, _Options);
#endif
  }

  template<typename _Function>
  __declspec(noinline) auto then(const _Function& _Func, cancellation_token _CancellationToken,
                                 task_continuation_context _ContinuationContext) const ->
    typename details::_ContinuationTypeTraits<_Function, _ReturnType>::_TaskOfType {

    task_options _TaskOptions(_CancellationToken, _ContinuationContext);
    details::_get_internal_task_options(_TaskOptions)._set_creation_callstack(_CAPTURE_CALLSTACK());

    auto _Options =
      details::_ThenImplOptions::_CreateOptions(_TaskOptions, _ContinuationContext, _ThenGetImpl()->_GetScheduler());

#ifndef _PPLTASKS_NO_STDFUNC
    return _ThenImpl<_ReturnType>(typename details::_ContinuationTypeTraits<_Function, _ReturnType>::_StdFuncT(_Func),
                                  _Options);
#else
    return _ThenImpl<_ReturnType>(_Func, _Options);
#endif
  }

  task_status wait() const {
    if (!_M_Impl) { details::_DefaultTaskHelper::_NoCallOnDefaultTask_ErrorImpl(); }

    return _M_Impl->_Wait();
  }

  _ReturnType get() const {
    if (!_M_Impl) { details::_DefaultTaskHelper::_NoCallOnDefaultTask_ErrorImpl(); }

    if (_M_Impl->_Wait() == canceled) { _THROW(task_canceled{}); }

    return _M_Impl->_GetResult();
  }

  bool is_done() const {
    if (!_M_Impl) { details::_DefaultTaskHelper::_NoCallOnDefaultTask_ErrorImpl(); }

    return _M_Impl->_IsDone();
  }

  scheduler_ptr scheduler() const {
    if (!_M_Impl) { details::_DefaultTaskHelper::_NoCallOnDefaultTask_ErrorImpl(); }

    return _M_Impl->_GetScheduler();
  }

  bool is_apartment_aware() const {
    if (!_M_Impl) { details::_DefaultTaskHelper::_NoCallOnDefaultTask_ErrorImpl(); }
    return _M_Impl->_IsApartmentAware();
  }

  bool operator==(const task<_ReturnType>& _Rhs) const { return (_M_Impl == _Rhs._M_Impl); }

  bool operator!=(const task<_ReturnType>& _Rhs) const { return !operator==(_Rhs); }

  void _CreateImpl(details::_CancellationTokenState* _Ct, scheduler_ptr _Scheduler) {
    _M_Impl = details::_Task_ptr<_ReturnType>::_Make(_Ct, _Scheduler);
    if (_Ct != details::_CancellationTokenState::_None()) { _M_Impl->_RegisterCancellation(_M_Impl); }
  }

  const typename details::_Task_ptr<_ReturnType>::_Type& _GetImpl() const { return _M_Impl; }

  const typename details::_Task_ptr<_ReturnType>::_Type& _ThenGetImpl() const {
    if (!_M_Impl) { details::_DefaultTaskHelper::_NoCallOnDefaultTask_ErrorImpl(); }

    return _M_Impl;
  }

  void _SetImpl(const typename details::_Task_ptr<_ReturnType>::_Type& _Impl) { _M_Impl = _Impl; }

  void _SetImpl(typename details::_Task_ptr<_ReturnType>::_Type&& _Impl) { _M_Impl = ::std::move(_Impl); }

  void _SetAsync(bool _Async = true) { _GetImpl()->_SetAsync(_Async); }

  void _SetTaskCreationCallstack(const details::_TaskCreationCallstack& _callstack) {
    _GetImpl()->_SetTaskCreationCallstack(_callstack);
  }

  template<typename _Function> auto _Then(const _Function& _Func, details::_CancellationTokenState* _PTokenState,
                                          details::_TaskInliningMode_t _InliningMode = details::_ForceInline) const ->
    typename details::_ContinuationTypeTraits<_Function, _ReturnType>::_TaskOfType {

    auto _Scheduler = _GetImpl()->_GetScheduler();

    auto _Default_Context = task_continuation_context::use_default();
    details::_ThenImplOptions _Options(_PTokenState, &_Default_Context, _Scheduler, _CAPTURE_CALLSTACK(),
                                       _InliningMode);

#ifndef _PPLTASKS_NO_STDFUNC
    return _ThenImpl<_ReturnType>(typename details::_ContinuationTypeTraits<_Function, _ReturnType>::_StdFuncT(_Func),
                                  _Options);
#else
    return _ThenImpl<_ReturnType>(_Func, _Options);
#endif
  }

private:
  template<typename _Ty> friend class task;

  template<typename _InternalReturnType, typename _Function, typename _TypeSelection> struct _InitialTaskHandle :
    details::_PPLTaskHandle<_ReturnType, _InitialTaskHandle<_InternalReturnType, _Function, _TypeSelection>,
                            details::_UnrealizedChore_t> {
    _Function _M_function;
    _InitialTaskHandle(const typename details::_Task_ptr<_ReturnType>::_Type& _TaskImpl, const _Function& _func)
      : details::_PPLTaskHandle<_ReturnType, _InitialTaskHandle<_InternalReturnType, _Function, _TypeSelection>,
                                details::_UnrealizedChore_t>::_PPLTaskHandle(_TaskImpl),
        _M_function(_func) {}

    virtual ~_InitialTaskHandle() {}

    template<typename _Func> auto _LogWorkItemAndInvokeUserLambda(_Func _func) const -> decltype(_func()) {
      details::_TaskWorkItemRAIILogger _LogWorkItem(this->_M_pTask->_M_taskEventLogger);
      return _func();
    }

    void _Perform() const { _Init(_TypeSelection()); }

    void _SyncCancelAndPropagateException() const { this->_M_pTask->_Cancel(true); }

    void _Init(details::_TypeSelectorNoAsync) const {
      this->_M_pTask->_FinalizeAndRunContinuations(
        _LogWorkItemAndInvokeUserLambda(_Init_func_transformer<_InternalReturnType>::_Perform(_M_function)));
    }

    void _Init(details::_TypeSelectorAsyncOperationOrTask) const {
      details::_Task_impl_base::_AsyncInit<_ReturnType, _InternalReturnType>(
        this->_M_pTask, _LogWorkItemAndInvokeUserLambda(_M_function));
    }
  };

  template<typename _InternalReturnType, typename _ContinuationReturnType, typename _Function, typename _IsTaskBased,
           typename _TypeSelection>
  struct _ContinuationTaskHandle :
    details::_PPLTaskHandle<
      typename details::_NormalizeVoidToUnitType<_ContinuationReturnType>::_Type,
      _ContinuationTaskHandle<_InternalReturnType, _ContinuationReturnType, _Function, _IsTaskBased, _TypeSelection>,
      details::_ContinuationTaskHandleBase> {
    typedef
      typename details::_NormalizeVoidToUnitType<_ContinuationReturnType>::_Type _NormalizedContinuationReturnType;

    typename details::_Task_ptr<_ReturnType>::_Type _M_ancestorTaskImpl;
    _Function _M_function;

    _ContinuationTaskHandle(
      const typename details::_Task_ptr<_ReturnType>::_Type& _AncestorImpl,
      const typename details::_Task_ptr<_NormalizedContinuationReturnType>::_Type& _ContinuationImpl,
      const _Function& _Func, const task_continuation_context& _Context, details::_TaskInliningMode_t _InliningMode)
      : details::_PPLTaskHandle<typename details::_NormalizeVoidToUnitType<_ContinuationReturnType>::_Type,
                                _ContinuationTaskHandle<_InternalReturnType, _ContinuationReturnType, _Function,
                                                        _IsTaskBased, _TypeSelection>,
                                details::_ContinuationTaskHandleBase>::_PPLTaskHandle(_ContinuationImpl),
        _M_ancestorTaskImpl(_AncestorImpl), _M_function(_Func) {
      this->_M_isTaskBasedContinuation = _IsTaskBased::value;
      this->_M_continuationContext = _Context;
      this->_M_continuationContext._Resolve(_AncestorImpl->_IsApartmentAware());
      this->_M_inliningMode = _InliningMode;
    }

    virtual ~_ContinuationTaskHandle() {}

    template<typename _Func, typename _Arg> auto _LogWorkItemAndInvokeUserLambda(_Func&& _func, _Arg&& _value) const
      -> decltype(_func(::std::forward<_Arg>(_value))) {
      details::_TaskWorkItemRAIILogger _LogWorkItem(this->_M_pTask->_M_taskEventLogger);
      return _func(::std::forward<_Arg>(_value));
    }

    void _Perform() const { _Continue(_IsTaskBased(), _TypeSelection()); }

    void _SyncCancelAndPropagateException() const {
      if (_M_ancestorTaskImpl->_HasUserException()) {

        this->_M_pTask->_CancelWithExceptionHolder(_M_ancestorTaskImpl->_GetExceptionHolder(), true);
      } else {

        this->_M_pTask->_Cancel(true);
      }
    }

    void _Continue(::std::false_type, details::_TypeSelectorNoAsync) const {
      this->_M_pTask->_FinalizeAndRunContinuations(_LogWorkItemAndInvokeUserLambda(
        _Continuation_func_transformer<_InternalReturnType, _ContinuationReturnType>::_Perform(_M_function),
        _M_ancestorTaskImpl->_GetResult()));
    }

    void _Continue(::std::false_type, details::_TypeSelectorAsyncOperationOrTask) const {
      typedef typename details::_FunctionTypeTraits<_Function, _InternalReturnType>::_FuncRetType _FuncOutputType;

      details::_Task_impl_base::_AsyncInit<_NormalizedContinuationReturnType, _ContinuationReturnType>(
        this->_M_pTask, _LogWorkItemAndInvokeUserLambda(
                          _Continuation_func_transformer<_InternalReturnType, _FuncOutputType>::_Perform(_M_function),
                          _M_ancestorTaskImpl->_GetResult()));
    }

    void _Continue(::std::true_type, details::_TypeSelectorNoAsync) const {
      typedef task<_InternalReturnType> _FuncInputType;
      task<_InternalReturnType> _ResultTask;
      _ResultTask._SetImpl(::std::move(_M_ancestorTaskImpl));
      this->_M_pTask->_FinalizeAndRunContinuations(_LogWorkItemAndInvokeUserLambda(
        _Continuation_func_transformer<_FuncInputType, _ContinuationReturnType>::_Perform(_M_function),
        ::std::move(_ResultTask)));
    }

    void _Continue(::std::true_type, details::_TypeSelectorAsyncOperationOrTask) const {

      task<_InternalReturnType> _ResultTask;
      _ResultTask._SetImpl(::std::move(_M_ancestorTaskImpl));
      details::_Task_impl_base::_AsyncInit<_NormalizedContinuationReturnType, _ContinuationReturnType>(
        this->_M_pTask, _LogWorkItemAndInvokeUserLambda(_M_function, ::std::move(_ResultTask)));
    }
  };

  template<typename _InternalReturnType, typename _Function> void _TaskInitWithFunctor(const _Function& _Func) {
    typedef typename details::_InitFunctorTypeTraits<_InternalReturnType, decltype(::std::declval<_Function>()())>
      _Async_type_traits;

    _M_Impl->_M_fFromAsync = _Async_type_traits::_IsAsyncTask;
    _M_Impl->_M_fUnwrappedTask = _Async_type_traits::_IsUnwrappedTaskOrAsync;
    _M_Impl->_M_taskEventLogger._LogScheduleTask(false);
    _M_Impl->_ScheduleTask(
      new _InitialTaskHandle<_InternalReturnType, _Function, typename _Async_type_traits::_AsyncKind>(_GetImpl(),
                                                                                                      _Func),
      details::_NoInline);
  }

  void _TaskInitNoFunctor(task_completion_event<_ReturnType>& _Event) { _Event._RegisterTask(_M_Impl); }

  template<typename _Function> void _TaskInitMaybeFunctor(_Function& _Func, ::std::true_type) {
    _TaskInitWithFunctor<_ReturnType, _Function>(_Func);
  }

  template<typename _Ty> void _TaskInitMaybeFunctor(_Ty& _Param, ::std::false_type) { _TaskInitNoFunctor(_Param); }

  template<typename _InternalReturnType, typename _Function>
  auto _ThenImpl(const _Function& _Func, details::_ThenImplOptions& _Options) const ->
    typename details::_ContinuationTypeTraits<_Function, _InternalReturnType>::_TaskOfType {

    typedef details::_FunctionTypeTraits<_Function, _InternalReturnType> _Function_type_traits;
    typedef details::_TaskTypeTraits<typename _Function_type_traits::_FuncRetType> _Async_type_traits;
    typedef typename _Async_type_traits::_TaskRetType _TaskType;

    if (_Options._PTokenState == nullptr) {
      if (_Function_type_traits::_Takes_task::value) {
        _Options._PTokenState = details::_CancellationTokenState::_None();
      } else {
        _Options._PTokenState = _GetImpl()->_M_pTokenState;
      }
    }

    task<_TaskType> _ContinuationTask;
    _ContinuationTask._CreateImpl(_Options._PTokenState, _Options._Scheduler);

    _ContinuationTask._GetImpl()->_M_fFromAsync = (_GetImpl()->_M_fFromAsync || _Async_type_traits::_IsAsyncTask);
    _ContinuationTask._GetImpl()->_M_fUnwrappedTask = _Async_type_traits::_IsUnwrappedTaskOrAsync;
    _ContinuationTask._SetTaskCreationCallstack(_Options._CreationStack);

    _GetImpl()->_ScheduleContinuation(
      new _ContinuationTaskHandle<_InternalReturnType, _TaskType, _Function,
                                  typename _Function_type_traits::_Takes_task, typename _Async_type_traits::_AsyncKind>(
        _GetImpl(), _ContinuationTask._GetImpl(), _Func, *_Options._PContinuationContext, _Options._InliningMode));

    return _ContinuationTask;
  }

  typename details::_Task_ptr<_ReturnType>::_Type _M_Impl;
};

template<> class task<void> {
public:
  typedef void result_type;

  task() noexcept : _M_unitTask() {}

  template<typename _Ty>
  __declspec(noinline) explicit task(_Ty _Param, const task_options& _TaskOptions = task_options()) {
    details::_ValidateTaskConstructorArgs<void, _Ty>(_Param);

    _M_unitTask._CreateImpl(_TaskOptions.get_cancellation_token()._GetImplValue(), _TaskOptions.get_scheduler());

    _M_unitTask._SetTaskCreationCallstack(
      details::_get_internal_task_options(_TaskOptions)._M_hasPresetCreationCallstack
        ? details::_get_internal_task_options(_TaskOptions)._M_presetCreationCallstack
        : _CAPTURE_CALLSTACK());

    _TaskInitMaybeFunctor(_Param, decltype(details::_IsCallable(_Param, 0))());
  }

  task(const task& _Other) noexcept : _M_unitTask(_Other._M_unitTask) {}

  task(task&& _Other) noexcept : _M_unitTask(::std::move(_Other._M_unitTask)) {}

  task& operator=(const task& _Other) noexcept {
    if (this != &_Other) { _M_unitTask = _Other._M_unitTask; }
    return *this;
  }

  task& operator=(task&& _Other) noexcept {
    if (this != &_Other) { _M_unitTask = ::std::move(_Other._M_unitTask); }
    return *this;
  }

  template<typename _Function>
  __declspec(noinline) auto then(const _Function& _Func, task_options _TaskOptions = task_options()) const ->
    typename details::_ContinuationTypeTraits<_Function, void>::_TaskOfType {
    details::_get_internal_task_options(_TaskOptions)._set_creation_callstack(_CAPTURE_CALLSTACK());

    auto _ContinuationContext = _TaskOptions.get_continuation_context();
    auto _Options =
      details::_ThenImplOptions::_CreateOptions(_TaskOptions, _ContinuationContext, _ThenGetImpl()->_GetScheduler());

#ifndef _PPLTASKS_NO_STDFUNC
    return _M_unitTask._ThenImpl<void>(typename details::_ContinuationTypeTraits<_Function, void>::_StdFuncT(_Func),
                                       _Options);
#else
    return _M_unitTask._ThenImpl<void>(_Func, _Options);
#endif
  }

  template<typename _Function>
  __declspec(noinline) auto then(const _Function& _Func, cancellation_token _CancellationToken,
                                 task_continuation_context _ContinuationContext) const ->
    typename details::_ContinuationTypeTraits<_Function, void>::_TaskOfType {

    task_options _TaskOptions(_CancellationToken, _ContinuationContext);
    details::_get_internal_task_options(_TaskOptions)._set_creation_callstack(_CAPTURE_CALLSTACK());

    auto _Options =
      details::_ThenImplOptions::_CreateOptions(_TaskOptions, _ContinuationContext, _ThenGetImpl()->_GetScheduler());

#ifndef _PPLTASKS_NO_STDFUNC
    return _M_unitTask._ThenImpl<void>(typename details::_ContinuationTypeTraits<_Function, void>::_StdFuncT(_Func),
                                       _Options);
#else
    return _M_unitTask._ThenImpl<void>(_Func, _Options);
#endif
  }

  task_status wait() const { return _M_unitTask.wait(); }

  void get() const { _M_unitTask.get(); }

  bool is_done() const { return _M_unitTask.is_done(); }

  scheduler_ptr scheduler() const { return _M_unitTask.scheduler(); }

  bool is_apartment_aware() const { return _M_unitTask.is_apartment_aware(); }

  bool operator==(const task<void>& _Rhs) const { return (_M_unitTask == _Rhs._M_unitTask); }

  bool operator!=(const task<void>& _Rhs) const { return !operator==(_Rhs); }

  void _CreateImpl(details::_CancellationTokenState* _Ct, scheduler_ptr _Scheduler) {
    _M_unitTask._CreateImpl(_Ct, _Scheduler);
  }

  const details::_Task_ptr<details::_Unit_type>::_Type& _GetImpl() const { return _M_unitTask._M_Impl; }

  const details::_Task_ptr<details::_Unit_type>::_Type& _ThenGetImpl() const {
    if (!_M_unitTask._M_Impl) { details::_DefaultTaskHelper::_NoCallOnDefaultTask_ErrorImpl(); }

    return _M_unitTask._M_Impl;
  }

  void _SetImpl(const details::_Task_ptr<details::_Unit_type>::_Type& _Impl) { _M_unitTask._SetImpl(_Impl); }

  void _SetImpl(details::_Task_ptr<details::_Unit_type>::_Type&& _Impl) { _M_unitTask._SetImpl(::std::move(_Impl)); }

  void _SetAsync(bool _Async = true) { _M_unitTask._SetAsync(_Async); }

  void _SetTaskCreationCallstack(const details::_TaskCreationCallstack& _callstack) {
    _M_unitTask._SetTaskCreationCallstack(_callstack);
  }

  template<typename _Function> auto _Then(const _Function& _Func, details::_CancellationTokenState* _PTokenState,
                                          details::_TaskInliningMode_t _InliningMode = details::_ForceInline) const ->
    typename details::_ContinuationTypeTraits<_Function, void>::_TaskOfType {

    auto _Scheduler = _ThenGetImpl()->_GetScheduler();

    auto _Default_Context = task_continuation_context::use_default();
    details::_ThenImplOptions _Options{_PTokenState, &_Default_Context, _Scheduler, _CAPTURE_CALLSTACK(),
                                       _InliningMode};

#ifndef _PPLTASKS_NO_STDFUNC
    return _M_unitTask._ThenImpl<void>(typename details::_ContinuationTypeTraits<_Function, void>::_StdFuncT(_Func),
                                       _Options);
#else
    return _M_unitTask._ThenImpl<void>(_Func, _Options);
#endif
  }

private:
  template<typename _Ty> friend class task;
  template<typename _Ty> friend class task_completion_event;

  void _TaskInitNoFunctor(task_completion_event<void>& _Event) { _M_unitTask._TaskInitNoFunctor(_Event._M_unitEvent); }

  template<typename _Function> void _TaskInitMaybeFunctor(_Function& _Func, ::std::true_type) {
    _M_unitTask._TaskInitWithFunctor<void, _Function>(_Func);
  }

  template<typename _Ty> void _TaskInitMaybeFunctor(_Ty& _Param, ::std::false_type) { _TaskInitNoFunctor(_Param); }

  task<details::_Unit_type> _M_unitTask;
};

namespace details {

template<typename _Ty> _Ty _GetUnwrappedType(task<_Ty>);

template<typename _Ty> auto _GetUnwrappedReturnType(_Ty _Arg, int) -> decltype(_GetUnwrappedType(_Arg));

template<typename _Ty> _Ty _GetUnwrappedReturnType(_Ty, ...);

template<typename _Ty> _Ty _GetTaskType(task_completion_event<_Ty>, ::std::false_type);

template<typename _Ty> auto _GetTaskType(_Ty _NonFunc, ::std::false_type) -> decltype(_GetUnwrappedType(_NonFunc));

template<typename _Ty> auto _GetTaskType(_Ty _Func, ::std::true_type) -> decltype(_GetUnwrappedReturnType(_Func(), 0));

void _GetTaskType(::std::function<void()>, ::std::true_type);
struct _BadArgType {};

template<typename _Ty> auto _FilterValidTaskType(_Ty _Param, int)
  -> decltype(_GetTaskType(_Param, _IsCallable(_Param, 0)));

template<typename _Ty> _BadArgType _FilterValidTaskType(_Ty _Param, ...);

template<typename _Ty> struct _TaskTypeFromParam {
  typedef decltype(_FilterValidTaskType(details::declval<_Ty>(), 0)) _Type;
};

inline bool _IsHRCOMDisconnected(int __hr) {
  return static_cast<unsigned int>(__hr) == 0x800706BAU || static_cast<unsigned int>(__hr) == 0x80010108U ||
         static_cast<unsigned int>(__hr) == 0x89020001U;
}
}

template<typename _Ty> __declspec(noinline) auto create_task(_Ty _Param, task_options _TaskOptions = task_options())
  -> task<typename details::_TaskTypeFromParam<_Ty>::_Type> {
  static_assert(!::std::is_same_v<typename details::_TaskTypeFromParam<_Ty>::_Type, details::_BadArgType>,

                "incorrect argument for create_task; must be either a callable object or a task_completion_event");
  details::_get_internal_task_options(_TaskOptions)._set_creation_callstack(_CAPTURE_CALLSTACK());
  task<typename details::_TaskTypeFromParam<_Ty>::_Type> _CreatedTask(_Param, _TaskOptions);
  return _CreatedTask;
}

template<typename _ReturnType> __declspec(noinline) task<_ReturnType> create_task(const task<_ReturnType>& _Task) {
  task<_ReturnType> _CreatedTask(_Task);
  return _CreatedTask;
}

namespace details {

template<typename _Type> struct _RunAllParam {
  _RunAllParam() : _M_completeCount(0), _M_numTasks(0) {}

  void _Resize(size_t _Len, bool _SkipVector = false) {
    _M_numTasks = _Len;
    if (!_SkipVector) { _M_vector._Result.resize(_Len); }
  }

  task_completion_event<_Unit_type> _M_completed;
  _ResultHolder<::std::vector<_Type>> _M_vector;
  _ResultHolder<_Type> _M_mergeVal;
  atomic_size_t _M_completeCount;
  size_t _M_numTasks;
};

template<typename _Type> struct _RunAllParam<::std::vector<_Type>> {
  _RunAllParam() : _M_completeCount(0), _M_numTasks(0) {}

  void _Resize(size_t _Len, bool _SkipVector = false) {
    _M_numTasks = _Len;

    if (!_SkipVector) { _M_vector.resize(_Len); }
  }

  task_completion_event<_Unit_type> _M_completed;
  ::std::vector<_ResultHolder<::std::vector<_Type>>> _M_vector;
  atomic_size_t _M_completeCount;
  size_t _M_numTasks;
};

template<> struct _RunAllParam<_Unit_type> {
  _RunAllParam() : _M_completeCount(0), _M_numTasks(0) {}

  void _Resize(size_t _Len) { _M_numTasks = _Len; }

  task_completion_event<_Unit_type> _M_completed;
  atomic_size_t _M_completeCount;
  size_t _M_numTasks;
};

inline void _JoinAllTokens_Add(const cancellation_token_source& _MergedSrc,
                               _CancellationTokenState* _PJoinedTokenState) {
  if (_PJoinedTokenState != nullptr && _PJoinedTokenState != _CancellationTokenState::_None()) {
    cancellation_token _T = cancellation_token::_FromImpl(_PJoinedTokenState);
    _T.register_callback([=]() { _MergedSrc.cancel(); });
  }
}

template<typename _ElementType, typename _Function, typename _TaskType>
void _WhenAllContinuationWrapper(_RunAllParam<_ElementType>* _PParam, _Function _Func, task<_TaskType>& _Task) {
  if (_Task._GetImpl()->_IsCompleted()) {
    _Func();
    if (atomic_increment(_PParam->_M_completeCount) == _PParam->_M_numTasks) {

      _PParam->_M_completed.set(_Unit_type());

      delete _PParam;
    }
  } else {
    if (_Task._GetImpl()->_HasUserException()) {

      if (!_PParam->_M_completed._Cancel(_Task._GetImpl()->_GetExceptionHolder())) {
        atomic_exchange(_Task._GetImpl()->_GetExceptionHolder()->_M_exceptionObserved, 1l);
      }
    } else {
      _PParam->_M_completed._Cancel();
    }

    if (atomic_increment(_PParam->_M_completeCount) == _PParam->_M_numTasks) { delete _PParam; }
  }
}

template<typename _ElementType, typename _Iterator> struct _WhenAllImpl {
  static task<::std::vector<_ElementType>> _Perform(const task_options& _TaskOptions, _Iterator _Begin,
                                                    _Iterator _End) {
    _CancellationTokenState* _PTokenState =
      _TaskOptions.has_cancellation_token() ? _TaskOptions.get_cancellation_token()._GetImplValue() : nullptr;

    auto _PParam = new _RunAllParam<_ElementType>();
    cancellation_token_source _MergedSource;

    task_options _Options(_TaskOptions);
    _Options.set_cancellation_token(_MergedSource.get_token());
    task<_Unit_type> _All_tasks_completed(_PParam->_M_completed, _Options);

    auto _ReturnTask = _All_tasks_completed._Then(
      [=](_Unit_type) -> ::std::vector<_ElementType> { return _PParam->_M_vector.Get(); }, nullptr);

    if (_PTokenState) {
      _JoinAllTokens_Add(_MergedSource, _PTokenState);
      _PParam->_Resize(static_cast<size_t>(::std::distance(_Begin, _End)));
    } else {
      size_t _TaskNum = 0;
      for (auto _PTask = _Begin; _PTask != _End; ++_PTask) {
        _TaskNum++;
        _JoinAllTokens_Add(_MergedSource, _PTask->_GetImpl()->_M_pTokenState);
      }
      _PParam->_Resize(_TaskNum);
    }

    if (_Begin == _End) {
      _PParam->_M_completed.set(_Unit_type());
      delete _PParam;
    } else {
      size_t _Index = 0;
      for (auto _PTask = _Begin; _PTask != _End; ++_PTask) {
        if (_PTask->is_apartment_aware()) { _ReturnTask._SetAsync(); }

        _PTask->_Then(
          [_PParam, _Index](task<_ElementType> _ResultTask) {
            auto _Func = [_PParam, _Index, &_ResultTask]() {
              _PParam->_M_vector._Result[_Index] = _ResultTask._GetImpl()->_GetResult();
            };

            _WhenAllContinuationWrapper(_PParam, _Func, _ResultTask);
          },
          _CancellationTokenState::_None());

        _Index++;
      }
    }

    return _ReturnTask;
  }
};

template<typename _ElementType, typename _Iterator> struct _WhenAllImpl<::std::vector<_ElementType>, _Iterator> {
  static task<::std::vector<_ElementType>> _Perform(const task_options& _TaskOptions, _Iterator _Begin,
                                                    _Iterator _End) {
    _CancellationTokenState* _PTokenState =
      _TaskOptions.has_cancellation_token() ? _TaskOptions.get_cancellation_token()._GetImplValue() : nullptr;

    auto _PParam = new _RunAllParam<::std::vector<_ElementType>>();
    cancellation_token_source _MergedSource;

    task_options _Options(_TaskOptions);
    _Options.set_cancellation_token(_MergedSource.get_token());
    task<_Unit_type> _All_tasks_completed(_PParam->_M_completed, _Options);

    auto _ReturnTask = _All_tasks_completed._Then(
      [=](_Unit_type) -> ::std::vector<_ElementType> {
        ::std::vector<_ElementType> _Result;
        for (size_t _I = 0; _I < _PParam->_M_numTasks; _I++) {
          const ::std::vector<_ElementType>& _Vec = _PParam->_M_vector[_I].Get();
          _Result.insert(_Result.end(), _Vec.begin(), _Vec.end());
        }
        return _Result;
      },
      nullptr);

    if (_PTokenState) {
      _JoinAllTokens_Add(_MergedSource, _PTokenState);
      _PParam->_Resize(static_cast<size_t>(::std::distance(_Begin, _End)));
    } else {
      size_t _TaskNum = 0;
      for (auto _PTask = _Begin; _PTask != _End; ++_PTask) {
        _TaskNum++;
        _JoinAllTokens_Add(_MergedSource, _PTask->_GetImpl()->_M_pTokenState);
      }
      _PParam->_Resize(_TaskNum);
    }

    if (_Begin == _End) {
      _PParam->_M_completed.set(_Unit_type());
      delete _PParam;
    } else {
      size_t _Index = 0;
      for (auto _PTask = _Begin; _PTask != _End; ++_PTask) {
        if (_PTask->is_apartment_aware()) { _ReturnTask._SetAsync(); }

        _PTask->_Then(
          [_PParam, _Index](task<::std::vector<_ElementType>> _ResultTask) {
            auto _Func = [_PParam, _Index, &_ResultTask]() {
              _PParam->_M_vector[_Index].Set(_ResultTask._GetImpl()->_GetResult());
            };

            _WhenAllContinuationWrapper(_PParam, _Func, _ResultTask);
          },
          _CancellationTokenState::_None());

        _Index++;
      }
    }

    return _ReturnTask;
  }
};

template<typename _Iterator> struct _WhenAllImpl<void, _Iterator> {
  static task<void> _Perform(const task_options& _TaskOptions, _Iterator _Begin, _Iterator _End) {
    _CancellationTokenState* _PTokenState =
      _TaskOptions.has_cancellation_token() ? _TaskOptions.get_cancellation_token()._GetImplValue() : nullptr;

    auto _PParam = new _RunAllParam<_Unit_type>();
    cancellation_token_source _MergedSource;

    task_options _Options(_TaskOptions);
    _Options.set_cancellation_token(_MergedSource.get_token());
    task<_Unit_type> _All_tasks_completed(_PParam->_M_completed, _Options);

    auto _ReturnTask = _All_tasks_completed._Then([=](_Unit_type) {}, nullptr);

    if (_PTokenState) {
      _JoinAllTokens_Add(_MergedSource, _PTokenState);
      _PParam->_Resize(static_cast<size_t>(::std::distance(_Begin, _End)));
    } else {
      size_t _TaskNum = 0;
      for (auto _PTask = _Begin; _PTask != _End; ++_PTask) {
        _TaskNum++;
        _JoinAllTokens_Add(_MergedSource, _PTask->_GetImpl()->_M_pTokenState);
      }
      _PParam->_Resize(_TaskNum);
    }

    if (_Begin == _End) {
      _PParam->_M_completed.set(_Unit_type());
      delete _PParam;
    } else {
      for (auto _PTask = _Begin; _PTask != _End; ++_PTask) {
        if (_PTask->is_apartment_aware()) { _ReturnTask._SetAsync(); }

        _PTask->_Then(
          [_PParam](task<void> _ResultTask) {
            auto _Func = []() {};
            _WhenAllContinuationWrapper(_PParam, _Func, _ResultTask);
          },
          _CancellationTokenState::_None());
      }
    }

    return _ReturnTask;
  }
};

template<typename _ReturnType>
task<::std::vector<_ReturnType>> _WhenAllVectorAndValue(const task<::std::vector<_ReturnType>>& _VectorTask,
                                                        const task<_ReturnType>& _ValueTask, bool _OutputVectorFirst) {
  auto _PParam = new _RunAllParam<_ReturnType>();
  cancellation_token_source _MergedSource;

  task<_Unit_type> _All_tasks_completed(_PParam->_M_completed, _MergedSource.get_token());

  auto _ReturnTask = _All_tasks_completed._Then(
    [=](_Unit_type) -> ::std::vector<_ReturnType> {
      auto _Result = _PParam->_M_vector.Get();
      auto _mergeVal = _PParam->_M_mergeVal.Get();

      if (_OutputVectorFirst == true) {
        _Result.push_back(_mergeVal);
      } else {
        _Result.insert(_Result.begin(), _mergeVal);
      }
      return _Result;
    },
    nullptr);

  _JoinAllTokens_Add(_MergedSource, _VectorTask._GetImpl()->_M_pTokenState);
  _JoinAllTokens_Add(_MergedSource, _ValueTask._GetImpl()->_M_pTokenState);

  _PParam->_Resize(2, true);

  if (_VectorTask.is_apartment_aware() || _ValueTask.is_apartment_aware()) { _ReturnTask._SetAsync(); }
  _VectorTask._Then(
    [_PParam](task<::std::vector<_ReturnType>> _ResultTask) {
      auto _Func = [_PParam, &_ResultTask]() {
        auto _ResultLocal = _ResultTask._GetImpl()->_GetResult();
        _PParam->_M_vector.Set(_ResultLocal);
      };

      _WhenAllContinuationWrapper(_PParam, _Func, _ResultTask);
    },
    _CancellationTokenState::_None());
  _ValueTask._Then(
    [_PParam](task<_ReturnType> _ResultTask) {
      auto _Func = [_PParam, &_ResultTask]() {
        auto _ResultLocal = _ResultTask._GetImpl()->_GetResult();
        _PParam->_M_mergeVal.Set(_ResultLocal);
      };

      _WhenAllContinuationWrapper(_PParam, _Func, _ResultTask);
    },
    _CancellationTokenState::_None());

  return _ReturnTask;
}
}

template<typename _Iterator>
auto when_all(_Iterator _Begin, _Iterator _End, const task_options& _TaskOptions = task_options())
  -> decltype(details::_WhenAllImpl<typename ::std::iterator_traits<_Iterator>::value_type::result_type,
                                    _Iterator>::_Perform(_TaskOptions, _Begin, _End)) {
  typedef typename ::std::iterator_traits<_Iterator>::value_type::result_type _ElementType;
  return details::_WhenAllImpl<_ElementType, _Iterator>::_Perform(_TaskOptions, _Begin, _End);
}

template<typename _ReturnType> auto operator&&(const task<_ReturnType>& _Lhs, const task<_ReturnType>& _Rhs) {
  task<_ReturnType> _PTasks[2] = {_Lhs, _Rhs};
  return when_all(_PTasks, _PTasks + 2);
}

template<typename _ReturnType> task<::std::vector<_ReturnType>> operator&&(const task<::std::vector<_ReturnType>>& _Lhs,
                                                                           const task<_ReturnType>& _Rhs) {
  return details::_WhenAllVectorAndValue(_Lhs, _Rhs, true);
}

template<typename _ReturnType> task<::std::vector<_ReturnType>>
operator&&(const task<_ReturnType>& _Lhs, const task<::std::vector<_ReturnType>>& _Rhs) {
  return details::_WhenAllVectorAndValue(_Rhs, _Lhs, false);
}

template<typename _ReturnType> task<::std::vector<_ReturnType>>
operator&&(const task<::std::vector<_ReturnType>>& _Lhs, const task<::std::vector<_ReturnType>>& _Rhs) {
  task<::std::vector<_ReturnType>> _PTasks[2] = {_Lhs, _Rhs};
  return when_all(_PTasks, _PTasks + 2);
}

namespace details {

template<typename _CompletionType> struct _RunAnyParam {
  _RunAnyParam()
    : _M_exceptionRelatedToken(nullptr), _M_completeCount(0), _M_numTasks(0), _M_fHasExplicitToken(false) {}
  ~_RunAnyParam() {
    if (_CancellationTokenState::_IsValid(_M_exceptionRelatedToken)) _M_exceptionRelatedToken->_Release();
  }
  task_completion_event<_CompletionType> _M_Completed;
  cancellation_token_source _M_cancellationSource;
  _CancellationTokenState* _M_exceptionRelatedToken;
  atomic_size_t _M_completeCount;
  size_t _M_numTasks;
  bool _M_fHasExplicitToken;
};

template<typename _CompletionType, typename _Function, typename _TaskType> void
_WhenAnyContinuationWrapper(_RunAnyParam<_CompletionType>* _PParam, const _Function& _Func, task<_TaskType>& _Task) {
  bool _IsTokenCanceled = !_PParam->_M_fHasExplicitToken &&
                          _Task._GetImpl()->_M_pTokenState != _CancellationTokenState::_None() &&
                          _Task._GetImpl()->_M_pTokenState->_IsCanceled();
  if (_Task._GetImpl()->_IsCompleted() && !_IsTokenCanceled) {
    _Func();
    if (atomic_increment(_PParam->_M_completeCount) == _PParam->_M_numTasks) {
      _PParam->_M_Completed._ClearStoredException();
      delete _PParam;
    }
  } else {
    if (_Task._GetImpl()->_HasUserException()) {
      if (!_IsTokenCanceled && _PParam->_M_Completed._StoreException(_Task._GetImpl()->_GetExceptionHolder())) {

        _PParam->_M_exceptionRelatedToken = _Task._GetImpl()->_M_pTokenState;

        if (_PParam->_M_exceptionRelatedToken != _CancellationTokenState::_None()) {
          _PParam->_M_exceptionRelatedToken->_Reference();
        }
      } else {

        atomic_exchange(_Task._GetImpl()->_GetExceptionHolder()->_M_exceptionObserved, 1l);
      }
    }

    if (atomic_increment(_PParam->_M_completeCount) == _PParam->_M_numTasks) {

      if (!_PParam->_M_Completed._IsTriggered()) {

        if (!_PParam->_M_fHasExplicitToken) {
          if (_PParam->_M_exceptionRelatedToken) {
            _JoinAllTokens_Add(_PParam->_M_cancellationSource, _PParam->_M_exceptionRelatedToken);
          } else {

            _JoinAllTokens_Add(_PParam->_M_cancellationSource, _Task._GetImpl()->_M_pTokenState);
          }
        }

        _PParam->_M_Completed._Cancel();
      } else _PParam->_M_Completed._ClearStoredException();
      delete _PParam;
    }
  }
}

template<typename _ElementType, typename _Iterator> struct _WhenAnyImpl {
  static task<::std::pair<_ElementType, size_t>> _Perform(const task_options& _TaskOptions, _Iterator _Begin,
                                                          _Iterator _End) {
    if (_Begin == _End) { _THROW(invalid_operation("when_any(begin, end) cannot be called on an empty container.")); }
    _CancellationTokenState* _PTokenState =
      _TaskOptions.has_cancellation_token() ? _TaskOptions.get_cancellation_token()._GetImplValue() : nullptr;
    auto _PParam = new _RunAnyParam<::std::pair<::std::pair<_ElementType, size_t>, _CancellationTokenState*>>();

    if (_PTokenState) {
      _JoinAllTokens_Add(_PParam->_M_cancellationSource, _PTokenState);
      _PParam->_M_fHasExplicitToken = true;
    }

    task_options _Options(_TaskOptions);
    _Options.set_cancellation_token(_PParam->_M_cancellationSource.get_token());
    task<::std::pair<::std::pair<_ElementType, size_t>, _CancellationTokenState*>> _Any_tasks_completed(
      _PParam->_M_Completed, _Options);

    auto _CancellationSource = _PParam->_M_cancellationSource;

    _PParam->_M_numTasks = static_cast<size_t>(::std::distance(_Begin, _End));
    size_t _Index = 0;
    for (auto _PTask = _Begin; _PTask != _End; ++_PTask) {
      if (_PTask->is_apartment_aware()) { _Any_tasks_completed._SetAsync(); }

      _PTask->_Then(
        [_PParam, _Index](task<_ElementType> _ResultTask) {
          auto _Func = [&_ResultTask, _PParam, _Index]() {
            _PParam->_M_Completed.set(::std::make_pair(::std::make_pair(_ResultTask._GetImpl()->_GetResult(), _Index),
                                                       _ResultTask._GetImpl()->_M_pTokenState));
          };

          _WhenAnyContinuationWrapper(_PParam, _Func, _ResultTask);
        },
        _CancellationTokenState::_None());

      _Index++;
    }

    return _Any_tasks_completed._Then(
      [=](::std::pair<::std::pair<_ElementType, size_t>, _CancellationTokenState*> _Result)
        -> ::std::pair<_ElementType, size_t> {
        if (!_PTokenState) { _JoinAllTokens_Add(_CancellationSource, _Result.second); }
        return _Result.first;
      },
      nullptr);
  }
};

template<typename _Iterator> struct _WhenAnyImpl<void, _Iterator> {
  static task<size_t> _Perform(const task_options& _TaskOptions, _Iterator _Begin, _Iterator _End) {
    if (_Begin == _End) { _THROW(invalid_operation("when_any(begin, end) cannot be called on an empty container.")); }

    _CancellationTokenState* _PTokenState =
      _TaskOptions.has_cancellation_token() ? _TaskOptions.get_cancellation_token()._GetImplValue() : nullptr;
    auto _PParam = new _RunAnyParam<::std::pair<size_t, _CancellationTokenState*>>();

    if (_PTokenState) {
      _JoinAllTokens_Add(_PParam->_M_cancellationSource, _PTokenState);
      _PParam->_M_fHasExplicitToken = true;
    }

    task_options _Options(_TaskOptions);
    _Options.set_cancellation_token(_PParam->_M_cancellationSource.get_token());
    task<::std::pair<size_t, _CancellationTokenState*>> _Any_tasks_completed(_PParam->_M_Completed, _Options);

    auto _CancellationSource = _PParam->_M_cancellationSource;

    _PParam->_M_numTasks = static_cast<size_t>(::std::distance(_Begin, _End));
    size_t _Index = 0;
    for (auto _PTask = _Begin; _PTask != _End; ++_PTask) {
      if (_PTask->is_apartment_aware()) { _Any_tasks_completed._SetAsync(); }

      _PTask->_Then(
        [_PParam, _Index](task<void> _ResultTask) {
          auto _Func = [&_ResultTask, _PParam, _Index]() {
            _PParam->_M_Completed.set(::std::make_pair(_Index, _ResultTask._GetImpl()->_M_pTokenState));
          };
          _WhenAnyContinuationWrapper(_PParam, _Func, _ResultTask);
        },
        _CancellationTokenState::_None());

      _Index++;
    }

    return _Any_tasks_completed._Then(
      [=](::std::pair<size_t, _CancellationTokenState*> _Result) -> size_t {
        if (!_PTokenState) { _JoinAllTokens_Add(_CancellationSource, _Result.second); }
        return _Result.first;
      },
      nullptr);
  }
};
}

template<typename _Iterator>
auto when_any(_Iterator _Begin, _Iterator _End, const task_options& _TaskOptions = task_options())
  -> decltype(details::_WhenAnyImpl<typename ::std::iterator_traits<_Iterator>::value_type::result_type,
                                    _Iterator>::_Perform(_TaskOptions, _Begin, _End)) {
  typedef typename ::std::iterator_traits<_Iterator>::value_type::result_type _ElementType;
  return details::_WhenAnyImpl<_ElementType, _Iterator>::_Perform(_TaskOptions, _Begin, _End);
}

template<typename _Iterator> auto when_any(_Iterator _Begin, _Iterator _End, cancellation_token _CancellationToken)
  -> decltype(details::_WhenAnyImpl<typename ::std::iterator_traits<_Iterator>::value_type::result_type,
                                    _Iterator>::_Perform(_CancellationToken._GetImplValue(), _Begin, _End)) {
  typedef typename ::std::iterator_traits<_Iterator>::value_type::result_type _ElementType;
  return details::_WhenAnyImpl<_ElementType, _Iterator>::_Perform(_CancellationToken._GetImplValue(), _Begin, _End);
}

template<typename _ReturnType>
task<_ReturnType> operator||(const task<_ReturnType>& _Lhs, const task<_ReturnType>& _Rhs) {
  auto _PParam = new details::_RunAnyParam<::std::pair<_ReturnType, size_t>>();

  task<::std::pair<_ReturnType, size_t>> _Any_tasks_completed(_PParam->_M_Completed,
                                                              _PParam->_M_cancellationSource.get_token());

  auto _ReturnTask = _Any_tasks_completed._Then(
    [=](::std::pair<_ReturnType, size_t> _Ret) -> _ReturnType {
      _JoinAllTokens_Add(_PParam->_M_cancellationSource,
                         reinterpret_cast<details::_CancellationTokenState*>(_Ret.second));
      return _Ret.first;
    },
    nullptr);

  if (_Lhs.is_apartment_aware() || _Rhs.is_apartment_aware()) { _ReturnTask._SetAsync(); }

  _PParam->_M_numTasks = 2;
  auto _Continuation = [_PParam](task<_ReturnType> _ResultTask) {
    auto _Func = [&_ResultTask, _PParam]() {
      _PParam->_M_Completed.set(::std::make_pair(_ResultTask._GetImpl()->_GetResult(),
                                                 reinterpret_cast<size_t>(_ResultTask._GetImpl()->_M_pTokenState)));
    };
    _WhenAnyContinuationWrapper(_PParam, _Func, _ResultTask);
  };

  _Lhs._Then(_Continuation, details::_CancellationTokenState::_None());
  _Rhs._Then(_Continuation, details::_CancellationTokenState::_None());

  return _ReturnTask;
}

template<typename _ReturnType> task<::std::vector<_ReturnType>> operator||(const task<::std::vector<_ReturnType>>& _Lhs,
                                                                           const task<_ReturnType>& _Rhs) {
  auto _PParam =
    new details::_RunAnyParam<::std::pair<::std::vector<_ReturnType>, details::_CancellationTokenState*>>();

  task<::std::pair<::std::vector<_ReturnType>, details::_CancellationTokenState*>> _Any_tasks_completed(
    _PParam->_M_Completed, _PParam->_M_cancellationSource.get_token());

  auto _ReturnTask = _Any_tasks_completed._Then(
    [=](::std::pair<::std::vector<_ReturnType>, details::_CancellationTokenState*> _Ret) -> ::std::vector<_ReturnType> {
      _JoinAllTokens_Add(_PParam->_M_cancellationSource, _Ret.second);
      return _Ret.first;
    },
    nullptr);

  if (_Lhs.is_apartment_aware() || _Rhs.is_apartment_aware()) { _ReturnTask._SetAsync(); }

  _PParam->_M_numTasks = 2;
  _Lhs._Then(
    [_PParam](task<::std::vector<_ReturnType>> _ResultTask) {
      auto _Func = [&_ResultTask, _PParam]() {
        auto _Result = _ResultTask._GetImpl()->_GetResult();
        _PParam->_M_Completed.set(::std::make_pair(_Result, _ResultTask._GetImpl()->_M_pTokenState));
      };
      _WhenAnyContinuationWrapper(_PParam, _Func, _ResultTask);
    },
    details::_CancellationTokenState::_None());

  _Rhs._Then(
    [_PParam](task<_ReturnType> _ResultTask) {
      auto _Func = [&_ResultTask, _PParam]() {
        auto _Result = _ResultTask._GetImpl()->_GetResult();

        ::std::vector<_ReturnType> _Vec;
        _Vec.push_back(_Result);
        _PParam->_M_Completed.set(::std::make_pair(_Vec, _ResultTask._GetImpl()->_M_pTokenState));
      };
      _WhenAnyContinuationWrapper(_PParam, _Func, _ResultTask);
    },
    details::_CancellationTokenState::_None());

  return _ReturnTask;
}

template<typename _ReturnType> task<::std::vector<_ReturnType>>
operator||(const task<_ReturnType>& _Lhs, const task<::std::vector<_ReturnType>>& _Rhs) {
  return _Rhs || _Lhs;
}

template<typename _Ty = task<void>,
         typename _Pair = ::std::pair<details::_Unit_type, details::_CancellationTokenState*>>
inline _Ty operator||(const task<void>& _Lhs_arg, const task<void>& _Rhs_arg) {
  const _Ty& _Lhs = _Lhs_arg;
  const _Ty& _Rhs = _Rhs_arg;

  auto _PParam = new details::_RunAnyParam<_Pair>();

  task<_Pair> _Any_task_completed(_PParam->_M_Completed, _PParam->_M_cancellationSource.get_token());

  auto _ReturnTask = _Any_task_completed._Then(
    [=](_Pair _Ret) { details::_JoinAllTokens_Add(_PParam->_M_cancellationSource, _Ret.second); }, nullptr);

  if (_Lhs.is_apartment_aware() || _Rhs.is_apartment_aware()) { _ReturnTask._SetAsync(); }

  _PParam->_M_numTasks = 2;
  auto _Continuation = [_PParam](_Ty _ResultTask) mutable {
    auto _Func = [&_ResultTask, _PParam]() {
      _PParam->_M_Completed.set(::std::make_pair(details::_Unit_type(), _ResultTask._GetImpl()->_M_pTokenState));
    };
    _WhenAnyContinuationWrapper(_PParam, _Func, _ResultTask);
  };

  _Lhs._Then(_Continuation, details::_CancellationTokenState::_None());
  _Rhs._Then(_Continuation, details::_CancellationTokenState::_None());

  return _ReturnTask;
}

template<typename _Ty> task<_Ty> task_from_result(_Ty _Param, const task_options& _TaskOptions = task_options()) {
  task_completion_event<_Ty> _Tce;
  _Tce.set(_Param);
  return create_task(_Tce, _TaskOptions);
}

inline task<void> task_from_result(const task_options& _TaskOptions = task_options()) {
  task_completion_event<void> _Tce;
  _Tce.set();
  return create_task(_Tce, _TaskOptions);
}

template<typename _TaskType, typename _ExType>
task<_TaskType> task_from_exception(_ExType _Exception, const task_options& _TaskOptions = task_options()) {
  task_completion_event<_TaskType> _Tce;
  _Tce.set_exception(_Exception);
  return create_task(_Tce, _TaskOptions);
}

namespace details {

template<typename _Ty = task<bool>> inline _Ty do_while(::std::enable_if_t<true, ::std::function<_Ty()>> _Func) {
  _Ty _First = _Func();
  return _First.then([=](bool _Guard) -> _Ty {
    if (_Guard) return do_while(_Func);
    else return _First;
  });
}

}

}
}

#pragma pop_macro("new")
#pragma warning(pop)
#pragma pack(pop)
