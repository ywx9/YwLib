#pragma once
#include "abc.h"
#include "condition_variable"
#include "memory"
#include "mutex"
#include "system_error"

extern "C++" {

namespace Concurrency {

namespace details {

using _Threadpool_callback = void(__cdecl*)(void*);

struct _Threadpool_chore {
  void* _work;
  _Threadpool_callback _callback;
  void* _data;
  _Threadpool_chore(_Threadpool_callback callback, void* data) : _work(nullptr), _callback(callback), _data(data) {}
  _Threadpool_chore() : _work(nullptr), _callback(nullptr), _data(nullptr) {}
};

int __cdecl _Schedule_chore(_Threadpool_chore*);
void __cdecl _Release_chore(_Threadpool_chore*);
int __cdecl _Reschedule_chore(const _Threadpool_chore*);

class _Threadpool_task {
  _Threadpool_chore _chore;
  static void __cdecl callback(void* task) { static_cast<_Threadpool_task*>(task)->_Invoke(); }
public:
  _Threadpool_task() : _chore{&callback, this} {}
  virtual void _Invoke() noexcept = 0;
  virtual ~_Threadpool_task() { _Release_chore(&_chore); }
  void _Schedule() { _Schedule_chore(&_chore); }
  void _Reschedule() const { _Reschedule_chore(&_chore); }
  bool _Is_scheduled() const noexcept { return _chore._work != nullptr; }
};
}

using TaskProc_t = void(__cdecl*)(void*);

struct __declspec(novtable) scheduler_interface {
  virtual void schedule(TaskProc_t, void*) = 0;
};

struct scheduler_ptr {
  explicit scheduler_ptr(::std::shared_ptr<scheduler_interface> scheduler)
    : _shared(::std::move(scheduler)) { _scheduler = _shared.get(); }
  explicit scheduler_ptr(_In_opt_ scheduler_interface* scheduler) : _scheduler(scheduler) {}
  scheduler_interface* operator->() const { return get(); }
  scheduler_interface* get() const { return _scheduler; }
  operator bool() const { return get() != nullptr; }
private:
  ::std::shared_ptr<scheduler_interface> _shared;
  scheduler_interface* _scheduler;
};

enum task_group_status { not_complete, completed, canceled };

class invalid_operation : public ::std::exception {
public:
  explicit invalid_operation(const char* s) noexcept : exception(s) {}
  invalid_operation() noexcept : exception() {}
};

class task_canceled : public ::std::exception {
public:
  explicit task_canceled(const char* s) noexcept : exception(s) {}
  task_canceled() noexcept : exception() {}
};

namespace details {

class _Interruption_exception : public ::std::exception {
public:
  explicit _Interruption_exception(const char* s) noexcept : exception(s) {}
  _Interruption_exception() noexcept : exception() {}
};

enum _TaskInliningMode {
  _NoInline = 0,
  _DefaultAutoInline = 16,
  _ForceInline = -1,
};

using atomic_long = ::std::atomic<long>;
using atomic_size_t = ::std::atomic<size_t>;

template<typename T> T atomic_compare_exchange(::std::atomic<T>& target, T value, T comparand) {
  T result = comparand;
  target.compare_exchange_strong(result, value);
  return result;
}

template<typename T> T atomic_exchange(::std::atomic<T>& target, T value) { return target.exchange(value); }
template<typename T> T atomic_increment(::std::atomic<T>& target) { return target.fetch_add(1) + 1; }
template<typename T> T atomic_decrement(::std::atomic<T>& target) { return target.fetch_sub(1) - 1; }
template<typename T> T atomic_add(::std::atomic<T>& target, T value) { return target.fetch_add(value) + value; }

class _DefaultPPLTaskScheduler : public scheduler_interface {
public:
  class _PPLTaskChore {
    _Threadpool_chore _M_Chore;
    TaskProc_t _M_proc;
    void* _M_param;
    static void __cdecl _Callback(void* _Args) {
      auto _Chore = ::std::unique_ptr<_PPLTaskChore>(static_cast<_PPLTaskChore*>(_Args));
      _Chore->_M_proc(_Chore->_M_param);
    }

  public:
    ~_PPLTaskChore() { _Release_chore(&_M_Chore); }

    _PPLTaskChore(TaskProc_t _Proc, void* _Param) : _M_Chore{&_Callback, this}, _M_proc(_Proc), _M_param(_Param) {}

    void _Schedule() {
      if (_Schedule_chore(&_M_Chore) != 0) {
        delete this;
        _THROW(::std::runtime_error("Fail to schedule the chore!"));
      }
    }
  };

  virtual void schedule(TaskProc_t _Proc, void* _Param) override { (new _PPLTaskChore{_Proc, _Param})->_Schedule(); }
};

inline ::std::shared_ptr<scheduler_interface>* _GetStaticAmbientSchedulerStorage() {
  static ::std::shared_ptr<scheduler_interface> _S_scheduler;
  return &_S_scheduler;
}

inline ::std::shared_ptr<scheduler_interface>& _GetStaticAmbientSchedulerRef() {
  static ::std::once_flag _Flag;
  static ::std::shared_ptr<scheduler_interface>* _S_scheduler_address;
  ::std::call_once(_Flag, [] { _S_scheduler_address = _GetStaticAmbientSchedulerStorage(); });
  return *_S_scheduler_address;
}

void __cdecl _ReportUnobservedException();
namespace platform {
unsigned int __cdecl GetNextAsyncId();
size_t __cdecl CaptureCallstack(void**, size_t, size_t);
long __cdecl GetCurrentThreadId();
}
}

inline const ::std::shared_ptr<scheduler_interface>& get_ambient_scheduler() { return details::_GetStaticAmbientSchedulerRef(); }
inline void set_ambient_scheduler(const ::std::shared_ptr<scheduler_interface>& _Scheduler) { details::_GetStaticAmbientSchedulerRef() = _Scheduler; }


namespace details {

class _RefCounter {
public:
  virtual ~_RefCounter() {}
  long _Reference() { return _InterlockedIncrement(&_M_refCount); }
  long _Release() {
    const auto refcount = _InterlockedDecrement(&_M_refCount);
    return (refcount == 0 ? _Destroy() : void(0)), refcount;
  }
protected:
  virtual void _Destroy() { delete this; }
  _RefCounter(long _InitialCount = 1) : _M_refCount(_InitialCount) {}
  volatile long _M_refCount;
};

class _CancellationTokenState;

class _CancellationTokenRegistration : public _RefCounter {
  friend class _CancellationTokenState;
  static const long _STATE_CLEAR = 0;
  static const long _STATE_DEFER_DELETE = 1;
  static const long _STATE_SYNCHRONIZE = 2;
  static const long _STATE_CALLED = 3;
  atomic_long _M_state;
  ::std::condition_variable _M_CondVar;
  ::std::mutex _M_Mutex;
  bool _M_signaled;
  _CancellationTokenState* _M_pTokenState;
public:
  _CancellationTokenRegistration(long init = 1)
    : _RefCounter(init), _M_state(_STATE_CALLED), _M_signaled(false), _M_pTokenState(nullptr) {}
  _CancellationTokenState* _GetToken() const { return _M_pTokenState; }
protected:
  virtual ~_CancellationTokenRegistration() {}
  virtual void _Exec() = 0;
private:
  void _Invoke() {
    const long _Tid = ::Concurrency::details::platform::GetCurrentThreadId();
    if (long result = atomic_compare_exchange(_M_state, _Tid, _STATE_CLEAR); result == _STATE_CLEAR) {
      _Exec(), result = atomic_compare_exchange(_M_state, _STATE_CALLED, _Tid);
      if (result == _STATE_SYNCHRONIZE) {
        if (::std::lock_guard<::std::mutex> _Lock(_M_Mutex); true) _M_signaled = true;
        _M_CondVar.notify_all();
      }
    }
    _Release();
  }

};

template<typename F> class _CancellationTokenCallback : public _CancellationTokenRegistration {
  F _M_function;
protected:
  virtual void _Exec() override { _M_function(); }
public:
  _CancellationTokenCallback(const F& _Func) : _M_function(_Func) {}
};

class CancellationTokenRegistration_TaskProc : public _CancellationTokenRegistration {
public:
  CancellationTokenRegistration_TaskProc(TaskProc_t _Proc, _In_ void* _PData, int _InitialRefs)
    : _CancellationTokenRegistration(_InitialRefs), _M_proc(_Proc), _M_pData(_PData) {}

protected:
  virtual void _Exec() override { _M_proc(_M_pData); }

private:
  TaskProc_t _M_proc;
  void* _M_pData;
};

class _CancellationTokenState : public _RefCounter {
protected:
  class TokenRegistrationContainer {
  private:
    typedef struct _Node {
      _CancellationTokenRegistration* _M_token;
      _Node* _M_next;

      _Node(_CancellationTokenRegistration* _Token) : _M_token(_Token), _M_next(nullptr) {}
    } Node;

  public:
    TokenRegistrationContainer() : _M_begin(nullptr), _M_last(nullptr) {}

    ~TokenRegistrationContainer() {
      auto _Node = _M_begin;
      while (_Node != nullptr) {
        Node* _Tmp = _Node;
        _Node = _Node->_M_next;
        delete _Tmp;
      }
    }

    void swap(TokenRegistrationContainer& _List) {
      ::std::swap(_List._M_begin, _M_begin);
      ::std::swap(_List._M_last, _M_last);
    }

    bool empty() { return _M_begin == nullptr; }

    template<typename _Ty> void for_each(_Ty _Lambda) {
      Node* _Node = _M_begin;

      while (_Node != nullptr) {
        _Lambda(_Node->_M_token);
        _Node = _Node->_M_next;
      }
    }

    void push_back(_CancellationTokenRegistration* _Token) {
      auto _Node = new Node(_Token);
      if (_M_begin == nullptr) {
        _M_begin = _Node;
      } else {
        _M_last->_M_next = _Node;
      }

      _M_last = _Node;
    }

    void remove(_CancellationTokenRegistration* _Token) {
      Node* _Node = _M_begin;
      Node* _Prev = nullptr;

      while (_Node != nullptr) {
        if (_Node->_M_token == _Token) {
          if (_Prev == nullptr) {
            _M_begin = _Node->_M_next;
          } else {
            _Prev->_M_next = _Node->_M_next;
          }

          if (_Node->_M_next == nullptr) { _M_last = _Prev; }

          delete _Node;
          break;
        }

        _Prev = _Node;
        _Node = _Node->_M_next;
      }
    }

  private:
    Node* _M_begin;
    Node* _M_last;
  };

public:
  static _CancellationTokenState* _NewTokenState() { return new _CancellationTokenState(); }

  static _CancellationTokenState* _None() { return reinterpret_cast<_CancellationTokenState*>(2); }

  static bool _IsValid(_In_opt_ _CancellationTokenState* _PToken) { return (_PToken != nullptr && _PToken != _None()); }

  _CancellationTokenState() : _M_stateFlag(0) {}

  ~_CancellationTokenState() {
    TokenRegistrationContainer _RundownList;
    {
      ::std::lock_guard<::std::mutex> _Lock(_M_listLock);
      _M_registrations.swap(_RundownList);
    }

    _RundownList.for_each([](_CancellationTokenRegistration* _PRegistration) {
      _PRegistration->_M_state = _CancellationTokenRegistration::_STATE_SYNCHRONIZE;
      _PRegistration->_Release();
    });
  }

  bool _IsCanceled() const { return (_M_stateFlag != 0); }

  void _Cancel() {
    if (atomic_compare_exchange(_M_stateFlag, 1l, 0l) == 0) {
      TokenRegistrationContainer _RundownList;
      {
        ::std::lock_guard<::std::mutex> _Lock(_M_listLock);
        _M_registrations.swap(_RundownList);
      }

      _RundownList.for_each([](_CancellationTokenRegistration* _PRegistration) { _PRegistration->_Invoke(); });

      _M_stateFlag = 2;
    }
  }

  _CancellationTokenRegistration* _RegisterCallback(TaskProc_t _PCallback, _In_ void* _PData, int _InitialRefs = 1) {
    _CancellationTokenRegistration* _PRegistration =
      new CancellationTokenRegistration_TaskProc(_PCallback, _PData, _InitialRefs);
    _RegisterCallback(_PRegistration);
    return _PRegistration;
  }

  void _RegisterCallback(_In_ _CancellationTokenRegistration* _PRegistration) {
    _PRegistration->_M_state = _CancellationTokenRegistration::_STATE_CLEAR;
    _PRegistration->_Reference();
    _PRegistration->_M_pTokenState = this;

    bool _Invoke = true;

    if (!_IsCanceled()) {
      ::std::lock_guard<::std::mutex> _Lock(_M_listLock);

      if (!_IsCanceled()) {
        _Invoke = false;
        _M_registrations.push_back(_PRegistration);
      }
    }

    if (_Invoke) { _PRegistration->_Invoke(); }
  }

  void _DeregisterCallback(_In_ _CancellationTokenRegistration* _PRegistration) {
    bool _Synchronize = false;

    {
      ::std::lock_guard<::std::mutex> _Lock(_M_listLock);

      if (!_M_registrations.empty()) {
        _M_registrations.remove(_PRegistration);
        _PRegistration->_M_state = _CancellationTokenRegistration::_STATE_SYNCHRONIZE;
        _PRegistration->_Release();
      } else {
        _Synchronize = true;
      }
    }

    if (_Synchronize) {
      const long _Result =
        atomic_compare_exchange(_PRegistration->_M_state, _CancellationTokenRegistration::_STATE_DEFER_DELETE,
                                _CancellationTokenRegistration::_STATE_CLEAR);

      switch (_Result) {
      case _CancellationTokenRegistration::_STATE_CLEAR:
      case _CancellationTokenRegistration::_STATE_CALLED: break;
      case _CancellationTokenRegistration::_STATE_DEFER_DELETE:
      case _CancellationTokenRegistration::_STATE_SYNCHRONIZE: break;
      default: {
        if (_Result == ::Concurrency::details::platform::GetCurrentThreadId()) { break; }

        const long _Result_1 =
          atomic_exchange(_PRegistration->_M_state, _CancellationTokenRegistration::_STATE_SYNCHRONIZE);

        if (_Result_1 != _CancellationTokenRegistration::_STATE_CALLED) {
          ::std::unique_lock<::std::mutex> _Lock(_PRegistration->_M_Mutex);
          _PRegistration->_M_CondVar.wait(_Lock, [_PRegistration] { return _PRegistration->_M_signaled; });
        }

        break;
      }
      }
    }
  }

private:
  atomic_long _M_stateFlag;

  ::std::mutex _M_listLock;

  TokenRegistrationContainer _M_registrations;
};

}

class cancellation_token_source;
class cancellation_token;

class cancellation_token_registration {
public:
  cancellation_token_registration() noexcept : _M_pRegistration(nullptr) {}

  ~cancellation_token_registration() { _Clear(); }

  cancellation_token_registration(const cancellation_token_registration& _Src) noexcept {
    _Assign(_Src._M_pRegistration);
  }

  cancellation_token_registration(cancellation_token_registration&& _Src) noexcept { _Move(_Src._M_pRegistration); }

  cancellation_token_registration& operator=(const cancellation_token_registration& _Src) noexcept {
    if (this != &_Src) {
      _Clear();
      _Assign(_Src._M_pRegistration);
    }
    return *this;
  }

  cancellation_token_registration& operator=(cancellation_token_registration&& _Src) noexcept {
    if (this != &_Src) {
      _Clear();
      _Move(_Src._M_pRegistration);
    }
    return *this;
  }

  bool operator==(const cancellation_token_registration& _Rhs) const {
    return _M_pRegistration == _Rhs._M_pRegistration;
  }

  bool operator!=(const cancellation_token_registration& _Rhs) const { return !(operator==(_Rhs)); }

private:
  friend class cancellation_token;

  cancellation_token_registration(_In_ details::_CancellationTokenRegistration* _PRegistration) noexcept
    : _M_pRegistration(_PRegistration) {}

  void _Clear() noexcept {
    if (_M_pRegistration != nullptr) { _M_pRegistration->_Release(); }
    _M_pRegistration = nullptr;
  }

  void _Assign(_In_ details::_CancellationTokenRegistration* _PRegistration) noexcept {
    if (_PRegistration != nullptr) { _PRegistration->_Reference(); }
    _M_pRegistration = _PRegistration;
  }

  void _Move(_In_ details::_CancellationTokenRegistration*& _PRegistration) noexcept {
    _M_pRegistration = _PRegistration;
    _PRegistration = nullptr;
  }

  details::_CancellationTokenRegistration* _M_pRegistration;
};

class cancellation_token {
public:
  typedef details::_CancellationTokenState* _ImplType;

  static cancellation_token none() { return cancellation_token(); }

  cancellation_token(const cancellation_token& _Src) { _Assign(_Src._M_Impl); }

  cancellation_token(cancellation_token&& _Src) noexcept { _Move(_Src._M_Impl); }

  cancellation_token& operator=(const cancellation_token& _Src) {
    if (this != &_Src) {
      _Clear();
      _Assign(_Src._M_Impl);
    }
    return *this;
  }

  cancellation_token& operator=(cancellation_token&& _Src) noexcept {
    if (this != &_Src) {
      _Clear();
      _Move(_Src._M_Impl);
    }
    return *this;
  }

  bool operator==(const cancellation_token& _Src) const { return _M_Impl == _Src._M_Impl; }

  bool operator!=(const cancellation_token& _Src) const { return !(operator==(_Src)); }

  ~cancellation_token() { _Clear(); }

  bool is_cancelable() const { return (_M_Impl != nullptr); }

  bool is_canceled() const { return (_M_Impl != nullptr && _M_Impl->_IsCanceled()); }

  template<typename _Function>
  ::Concurrency::cancellation_token_registration register_callback(const _Function& _Func) const {
    if (_M_Impl == nullptr) { throw invalid_operation(); }
#pragma warning(suppress : 28197)
    details::_CancellationTokenCallback<_Function>* _PCallback =
      new details::_CancellationTokenCallback<_Function>(_Func);
    _M_Impl->_RegisterCallback(_PCallback);
    return cancellation_token_registration(_PCallback);
  }

  void deregister_callback(const cancellation_token_registration& _Registration) const {
    _M_Impl->_DeregisterCallback(_Registration._M_pRegistration);
  }

  _ImplType _GetImpl() const { return _M_Impl; }

  _ImplType _GetImplValue() const {
    return (_M_Impl == nullptr) ? ::Concurrency::details::_CancellationTokenState::_None() : _M_Impl;
  }

  static cancellation_token _FromImpl(_ImplType _Impl) { return cancellation_token(_Impl); }

private:
  friend class cancellation_token_source;

  _ImplType _M_Impl;

  void _Clear() {
    if (_M_Impl != nullptr) { _M_Impl->_Release(); }
    _M_Impl = nullptr;
  }

  void _Assign(_ImplType _Impl) {
    if (_Impl != nullptr) { _Impl->_Reference(); }
    _M_Impl = _Impl;
  }

  void _Move(_ImplType& _Impl) {
    _M_Impl = _Impl;
    _Impl = nullptr;
  }

  cancellation_token() : _M_Impl(nullptr) {}

  cancellation_token(_ImplType _Impl) : _M_Impl(_Impl) {
    if (_M_Impl == ::Concurrency::details::_CancellationTokenState::_None()) { _M_Impl = nullptr; }

    if (_M_Impl != nullptr) { _M_Impl->_Reference(); }
  }
};

class cancellation_token_source {
public:
  typedef ::Concurrency::details::_CancellationTokenState* _ImplType;

  cancellation_token_source() { _M_Impl = new ::Concurrency::details::_CancellationTokenState; }

  cancellation_token_source(const cancellation_token_source& _Src) { _Assign(_Src._M_Impl); }

  cancellation_token_source(cancellation_token_source&& _Src) noexcept { _Move(_Src._M_Impl); }

  cancellation_token_source& operator=(const cancellation_token_source& _Src) {
    if (this != &_Src) {
      _Clear();
      _Assign(_Src._M_Impl);
    }
    return *this;
  }

  cancellation_token_source& operator=(cancellation_token_source&& _Src) noexcept {
    if (this != &_Src) {
      _Clear();
      _Move(_Src._M_Impl);
    }
    return *this;
  }

  bool operator==(const cancellation_token_source& _Src) const { return _M_Impl == _Src._M_Impl; }

  bool operator!=(const cancellation_token_source& _Src) const { return !(operator==(_Src)); }

  ~cancellation_token_source() {
    if (_M_Impl != nullptr) { _M_Impl->_Release(); }
  }

  cancellation_token get_token() const { return cancellation_token(_M_Impl); }

  static cancellation_token_source create_linked_source(cancellation_token& _Src) {
    cancellation_token_source _NewSource;
    _Src.register_callback([_NewSource]() { _NewSource.cancel(); });
    return _NewSource;
  }

  template<typename _Iter> static cancellation_token_source create_linked_source(_Iter _Begin, _Iter _End) {
    cancellation_token_source _NewSource;
    for (_Iter _It = _Begin; _It != _End; ++_It) {
      _It->register_callback([_NewSource]() { _NewSource.cancel(); });
    }
    return _NewSource;
  }

  void cancel() const { _M_Impl->_Cancel(); }

  _ImplType _GetImpl() const { return _M_Impl; }

  static cancellation_token_source _FromImpl(_ImplType _Impl) { return cancellation_token_source(_Impl); }

private:
  _ImplType _M_Impl;

  void _Clear() {
    if (_M_Impl != nullptr) { _M_Impl->_Release(); }
    _M_Impl = nullptr;
  }

  void _Assign(_ImplType _Impl) {
    if (_Impl != nullptr) { _Impl->_Reference(); }
    _M_Impl = _Impl;
  }

  void _Move(_ImplType& _Impl) {
    _M_Impl = _Impl;
    _Impl = nullptr;
  }

  cancellation_token_source(_ImplType _Impl) : _M_Impl(_Impl) {
    if (_M_Impl == ::Concurrency::details::_CancellationTokenState::_None()) { _M_Impl = nullptr; }

    if (_M_Impl != nullptr) { _M_Impl->_Reference(); }
  }
};

}
}

extern "C++" {

namespace Concurrency {

namespace details {

#ifndef _REPORT_PPLTASK_UNOBSERVED_EXCEPTION
#define _REPORT_PPLTASK_UNOBSERVED_EXCEPTION()            \
  do {                                                    \
    ReportUnhandledError();                               \
    __debugbreak();                                       \
    ::Concurrency::details::_ReportUnobservedException(); \
  } while (false)

#endif

struct _TaskProcHandle {
  _TaskProcHandle() {}
  virtual ~_TaskProcHandle() {}
  virtual void invoke() const = 0;

  void operator()() const { this->invoke(); }

  static void __cdecl _RunChoreBridge(void* _Parameter) {
    ::std::unique_ptr<_TaskProcHandle> { static_cast<_TaskProcHandle*>(_Parameter) } -> invoke();
  }
};

class _TaskCollectionBaseImpl {
protected:
  enum _TaskCollectionState { _New, _Scheduled, _Completed };

  void _SetCollectionState(_TaskCollectionState _NewState) {
    ::std::lock_guard<::std::mutex> _Lock(_M_Cs);
    if (_M_State < _NewState) { _M_State = _NewState; }

    _M_StateChanged.notify_all();
  }

  void WaitUntilStateChangedTo(_TaskCollectionState _State) {
    ::std::unique_lock<::std::mutex> _Lock(_M_Cs);

    while (_M_State < _State) { _M_StateChanged.wait(_Lock); }
  }
public:
  typedef _TaskProcHandle _TaskProcHandle_t;

  _TaskCollectionBaseImpl(::Concurrency::scheduler_ptr _PScheduler) : _M_pScheduler(_PScheduler), _M_State(_New) {}

  void _ScheduleTask(_TaskProcHandle_t* _Parameter, _TaskInliningMode _InliningMode) {
    if (_InliningMode == _ForceInline) {
      _TaskProcHandle_t::_RunChoreBridge(_Parameter);
    } else {
      if (_M_pScheduler) {
        _M_pScheduler->schedule(_TaskProcHandle_t::_RunChoreBridge, _Parameter);
      } else {
        _DefaultPPLTaskScheduler().schedule(_TaskProcHandle_t::_RunChoreBridge, _Parameter);
      }
    }
  }

  void _Cancel() {}

  void _RunAndWait() { _Wait(); }

  void _Wait() { WaitUntilStateChangedTo(_Completed); }

  void _Complete() { _SetCollectionState(_Completed); }

  ::Concurrency::scheduler_ptr _GetScheduler() const { return _M_pScheduler; }

  static void _RunTask(TaskProc_t _Proc, void* _Parameter, _TaskInliningMode _InliningMode) {
    if (_InliningMode == _ForceInline) {
      _Proc(_Parameter);
    } else {

      auto _Ptr = get_ambient_scheduler();
      if (_Ptr) {
        _Ptr->schedule(_Proc, _Parameter);
      } else {
        _DefaultPPLTaskScheduler().schedule(_Proc, _Parameter);
      }
    }
  }
protected:
  ::std::condition_variable _M_StateChanged;
  ::std::mutex _M_Cs;
  ::Concurrency::scheduler_ptr _M_pScheduler;
  _TaskCollectionState _M_State;
};

typedef _TaskCollectionBaseImpl _TaskCollection_t;

struct _Task_generator_oversubscriber {};

typedef _TaskInliningMode _TaskInliningMode_t;
typedef _Task_generator_oversubscriber _Task_generator_oversubscriber_t;

}
}

namespace concurrency = ::Concurrency;
}
