#ifndef _SONNY_H_
#define _SONNY_H_

#include <deque>
#include <functional>
#include <silver-bun/silver-bun/silver-bun.h>
#include <tuple>

#ifndef SONNY_HOOKLIB
#define SONNY_HOOKLIB MINHOOK
#endif

#if SONNY_HOOKLIB == MINHOOK
#include <minhook/include/MinHook.h>
#else
#error "Unsupported hook library"
#endif

// supports up to 16 args in a call, can be more but i fucking do not care
#pragma region Argument Iteration Helpers

#define _SNY_ARG_0(tuple)
#define _SNY_ARG_1(tuple) std::tuple_element_t<0, decltype(tuple)>
#define _SNY_ARG_2(tuple) std::tuple_element_t<1, decltype(tuple)>
#define _SNY_ARG_3(tuple) std::tuple_element_t<2, decltype(tuple)>
#define _SNY_ARG_4(tuple) std::tuple_element_t<3, decltype(tuple)>
#define _SNY_ARG_5(tuple) std::tuple_element_t<4, decltype(tuple)>
#define _SNY_ARG_6(tuple) std::tuple_element_t<5, decltype(tuple)>
#define _SNY_ARG_7(tuple) std::tuple_element_t<6, decltype(tuple)>
#define _SNY_ARG_8(tuple) std::tuple_element_t<7, decltype(tuple)>
#define _SNY_ARG_9(tuple) std::tuple_element_t<8, decltype(tuple)>
#define _SNY_ARG_10(tuple) std::tuple_element_t<9, decltype(tuple)>
#define _SNY_ARG_11(tuple) std::tuple_element_t<10, decltype(tuple)>
#define _SNY_ARG_12(tuple) std::tuple_element_t<11, decltype(tuple)>
#define _SNY_ARG_13(tuple) std::tuple_element_t<12, decltype(tuple)>
#define _SNY_ARG_14(tuple) std::tuple_element_t<13, decltype(tuple)>
#define _SNY_ARG_15(tuple) std::tuple_element_t<14, decltype(tuple)>
#define _SNY_ARG_16(tuple) std::tuple_element_t<15, decltype(tuple)>

#define _SNY_APPLY_ARGS_0(tuple) _SNY_ARG_0(tuple) arg0
#define _SNY_APPLY_ARGS_1(tuple) _SNY_ARG_0(tuple) arg0, _SNY_ARG_1(tuple) arg1
#define _SNY_APPLY_ARGS_2(tuple) _SNY_ARG_0(tuple) arg0, _SNY_ARG_1(tuple) arg1, _SNY_ARG_2(tuple) arg2
#define _SNY_APPLY_ARGS_3(tuple) _SNY_ARG_0(tuple) arg0, _SNY_ARG_1(tuple) arg1, _SNY_ARG_2(tuple) arg2, _SNY_ARG_3(tuple) arg3
#define _SNY_APPLY_ARGS_4(tuple) _SNY_ARG_0(tuple) arg0, _SNY_ARG_1(tuple) arg1, _SNY_ARG_2(tuple) arg2, _SNY_ARG_3(tuple) arg3, _SNY_ARG_4(tuple) arg4
#define _SNY_APPLY_ARGS_5(tuple) _SNY_ARG_0(tuple) arg0, _SNY_ARG_1(tuple) arg1, _SNY_ARG_2(tuple) arg2, _SNY_ARG_3(tuple) arg3, _SNY_ARG_4(tuple) arg4, _SNY_ARG_5(tuple) arg5
#define _SNY_APPLY_ARGS_6(tuple) _SNY_ARG_0(tuple) arg0, _SNY_ARG_1(tuple) arg1, _SNY_ARG_2(tuple) arg2, _SNY_ARG_3(tuple) arg3, _SNY_ARG_4(tuple) arg4, _SNY_ARG_5(tuple) arg5, _SNY_ARG_6(tuple) arg6
#define _SNY_APPLY_ARGS_7(tuple) _SNY_ARG_0(tuple) arg0, _SNY_ARG_1(tuple) arg1, _SNY_ARG_2(tuple) arg2, _SNY_ARG_3(tuple) arg3, _SNY_ARG_4(tuple) arg4, _SNY_ARG_5(tuple) arg5, _SNY_ARG_6(tuple) arg6, _SNY_ARG_7(tuple) arg7
#define _SNY_APPLY_ARGS_8(tuple) _SNY_ARG_0(tuple) arg0, _SNY_ARG_1(tuple) arg1, _SNY_ARG_2(tuple) arg2, _SNY_ARG_3(tuple) arg3, _SNY_ARG_4(tuple) arg4, _SNY_ARG_5(tuple) arg5, _SNY_ARG_6(tuple) arg6, _SNY_ARG_7(tuple) arg7, _SNY_ARG_8(tuple) arg8
#define _SNY_APPLY_ARGS_9(tuple) _SNY_ARG_0(tuple) arg0, _SNY_ARG_1(tuple) arg1, _SNY_ARG_2(tuple) arg2, _SNY_ARG_3(tuple) arg3, _SNY_ARG_4(tuple) arg4, _SNY_ARG_5(tuple) arg5, _SNY_ARG_6(tuple) arg6, _SNY_ARG_7(tuple) arg7, _SNY_ARG_8(tuple) arg8, _SNY_ARG_9(tuple) arg9
#define _SNY_APPLY_ARGS_10(tuple) _SNY_ARG_0(tuple) arg0, _SNY_ARG_1(tuple) arg1, _SNY_ARG_2(tuple) arg2, _SNY_ARG_3(tuple) arg3, _SNY_ARG_4(tuple) arg4, _SNY_ARG_5(tuple) arg5, _SNY_ARG_6(tuple) arg6, _SNY_ARG_7(tuple) arg7, _SNY_ARG_8(tuple) arg8, _SNY_ARG_9(tuple) arg9, _SNY_ARG_10(tuple) arg10
#define _SNY_APPLY_ARGS_11(tuple) _SNY_ARG_0(tuple) arg0, _SNY_ARG_1(tuple) arg1, _SNY_ARG_2(tuple) arg2, _SNY_ARG_3(tuple) arg3, _SNY_ARG_4(tuple) arg4, _SNY_ARG_5(tuple) arg5, _SNY_ARG_6(tuple) arg6, _SNY_ARG_7(tuple) arg7, _SNY_ARG_8(tuple) arg8, _SNY_ARG_9(tuple) arg9, _SNY_ARG_10(tuple) arg10, _SNY_ARG_11(tuple) arg11
#define _SNY_APPLY_ARGS_12(tuple) _SNY_ARG_0(tuple) arg0, _SNY_ARG_1(tuple) arg1, _SNY_ARG_2(tuple) arg2, _SNY_ARG_3(tuple) arg3, _SNY_ARG_4(tuple) arg4, _SNY_ARG_5(tuple) arg5, _SNY_ARG_6(tuple) arg6, _SNY_ARG_7(tuple) arg7, _SNY_ARG_8(tuple) arg8, _SNY_ARG_9(tuple) arg9, _SNY_ARG_10(tuple) arg10, _SNY_ARG_11(tuple) arg11, _SNY_ARG_12(tuple) arg12
#define _SNY_APPLY_ARGS_13(tuple) _SNY_ARG_0(tuple) arg0, _SNY_ARG_1(tuple) arg1, _SNY_ARG_2(tuple) arg2, _SNY_ARG_3(tuple) arg3, _SNY_ARG_4(tuple) arg4, _SNY_ARG_5(tuple) arg5, _SNY_ARG_6(tuple) arg6, _SNY_ARG_7(tuple) arg7, _SNY_ARG_8(tuple) arg8, _SNY_ARG_9(tuple) arg9, _SNY_ARG_10(tuple) arg10, _SNY_ARG_11(tuple) arg11, _SNY_ARG_12(tuple) arg12, _SNY_ARG_13(tuple) arg13
#define _SNY_APPLY_ARGS_14(tuple) _SNY_ARG_0(tuple) arg0, _SNY_ARG_1(tuple) arg1, _SNY_ARG_2(tuple) arg2, _SNY_ARG_3(tuple) arg3, _SNY_ARG_4(tuple) arg4, _SNY_ARG_5(tuple) arg5, _SNY_ARG_6(tuple) arg6, _SNY_ARG_7(tuple) arg7, _SNY_ARG_8(tuple) arg8, _SNY_ARG_9(tuple) arg9, _SNY_ARG_10(tuple) arg10, _SNY_ARG_11(tuple) arg11, _SNY_ARG_12(tuple) arg12, _SNY_ARG_13(tuple) arg13, _SNY_ARG_14(tuple) arg14
#define _SNY_APPLY_ARGS_15(tuple) _SNY_ARG_0(tuple) arg0, _SNY_ARG_1(tuple) arg1, _SNY_ARG_2(tuple) arg2, _SNY_ARG_3(tuple) arg3, _SNY_ARG_4(tuple) arg4, _SNY_ARG_5(tuple) arg5, _SNY_ARG_6(tuple) arg6, _SNY_ARG_7(tuple) arg7, _SNY_ARG_8(tuple) arg8, _SNY_ARG_9(tuple) arg9, _SNY_ARG_10(tuple) arg10, _SNY_ARG_11(tuple) arg11, _SNY_ARG_12(tuple) arg12, _SNY_ARG_13(tuple) arg13, _SNY_ARG_14(tuple) arg14, _SNY_ARG_15(tuple) arg15
#define _SNY_APPLY_ARGS_16(tuple) _SNY_ARG_0(tuple) arg0, _SNY_ARG_1(tuple) arg1, _SNY_ARG_2(tuple) arg2, _SNY_ARG_3(tuple) arg3, _SNY_ARG_4(tuple) arg4, _SNY_ARG_5(tuple) arg5, _SNY_ARG_6(tuple) arg6, _SNY_ARG_7(tuple) arg7, _SNY_ARG_8(tuple) arg8, _SNY_ARG_9(tuple) arg9, _SNY_ARG_10(tuple) arg10, _SNY_ARG_11(tuple) arg11, _SNY_ARG_12(tuple) arg12, _SNY_ARG_13(tuple) arg13, _SNY_ARG_14(tuple) arg14, _SNY_ARG_15(tuple) arg15, _SNY_ARG_16(tuple) arg16

#define _SNY_APPLY_MEMBER_ARGS_2(tuple)
#define _SNY_APPLY_MEMBER_ARGS_2(tuple)
#define _SNY_APPLY_MEMBER_ARGS_2(tuple) _SNY_ARG_2(tuple) arg2
#define _SNY_APPLY_MEMBER_ARGS_3(tuple) _SNY_ARG_2(tuple) arg2, _SNY_ARG_3(tuple) arg3
#define _SNY_APPLY_MEMBER_ARGS_4(tuple) _SNY_ARG_2(tuple) arg2, _SNY_ARG_3(tuple) arg3, _SNY_ARG_4(tuple) arg4
#define _SNY_APPLY_MEMBER_ARGS_5(tuple) _SNY_ARG_2(tuple) arg2, _SNY_ARG_3(tuple) arg3, _SNY_ARG_4(tuple) arg4, _SNY_ARG_5(tuple) arg5
#define _SNY_APPLY_MEMBER_ARGS_6(tuple) _SNY_ARG_2(tuple) arg2, _SNY_ARG_3(tuple) arg3, _SNY_ARG_4(tuple) arg4, _SNY_ARG_5(tuple) arg5, _SNY_ARG_6(tuple) arg6
#define _SNY_APPLY_MEMBER_ARGS_7(tuple) _SNY_ARG_2(tuple) arg2, _SNY_ARG_3(tuple) arg3, _SNY_ARG_4(tuple) arg4, _SNY_ARG_5(tuple) arg5, _SNY_ARG_6(tuple) arg6, _SNY_ARG_7(tuple) arg7
#define _SNY_APPLY_MEMBER_ARGS_8(tuple) _SNY_ARG_2(tuple) arg2, _SNY_ARG_3(tuple) arg3, _SNY_ARG_4(tuple) arg4, _SNY_ARG_5(tuple) arg5, _SNY_ARG_6(tuple) arg6, _SNY_ARG_7(tuple) arg7, _SNY_ARG_8(tuple) arg8
#define _SNY_APPLY_MEMBER_ARGS_9(tuple) _SNY_ARG_2(tuple) arg2, _SNY_ARG_3(tuple) arg3, _SNY_ARG_4(tuple) arg4, _SNY_ARG_5(tuple) arg5, _SNY_ARG_6(tuple) arg6, _SNY_ARG_7(tuple) arg7, _SNY_ARG_8(tuple) arg8, _SNY_ARG_9(tuple) arg9
#define _SNY_APPLY_MEMBER_ARGS_10(tuple) _SNY_ARG_2(tuple) arg2, _SNY_ARG_3(tuple) arg3, _SNY_ARG_4(tuple) arg4, _SNY_ARG_5(tuple) arg5, _SNY_ARG_6(tuple) arg6, _SNY_ARG_7(tuple) arg7, _SNY_ARG_8(tuple) arg8, _SNY_ARG_9(tuple) arg9, _SNY_ARG_10(tuple) arg10
#define _SNY_APPLY_MEMBER_ARGS_11(tuple) _SNY_ARG_2(tuple) arg2, _SNY_ARG_3(tuple) arg3, _SNY_ARG_4(tuple) arg4, _SNY_ARG_5(tuple) arg5, _SNY_ARG_6(tuple) arg6, _SNY_ARG_7(tuple) arg7, _SNY_ARG_8(tuple) arg8, _SNY_ARG_9(tuple) arg9, _SNY_ARG_10(tuple) arg10, _SNY_ARG_11(tuple) arg11
#define _SNY_APPLY_MEMBER_ARGS_12(tuple) _SNY_ARG_2(tuple) arg2, _SNY_ARG_3(tuple) arg3, _SNY_ARG_4(tuple) arg4, _SNY_ARG_5(tuple) arg5, _SNY_ARG_6(tuple) arg6, _SNY_ARG_7(tuple) arg7, _SNY_ARG_8(tuple) arg8, _SNY_ARG_9(tuple) arg9, _SNY_ARG_10(tuple) arg10, _SNY_ARG_11(tuple) arg11, _SNY_ARG_12(tuple) arg12
#define _SNY_APPLY_MEMBER_ARGS_13(tuple) _SNY_ARG_2(tuple) arg2, _SNY_ARG_3(tuple) arg3, _SNY_ARG_4(tuple) arg4, _SNY_ARG_5(tuple) arg5, _SNY_ARG_6(tuple) arg6, _SNY_ARG_7(tuple) arg7, _SNY_ARG_8(tuple) arg8, _SNY_ARG_9(tuple) arg9, _SNY_ARG_10(tuple) arg10, _SNY_ARG_11(tuple) arg11, _SNY_ARG_12(tuple) arg12, _SNY_ARG_13(tuple) arg13
#define _SNY_APPLY_MEMBER_ARGS_14(tuple) _SNY_ARG_2(tuple) arg2, _SNY_ARG_3(tuple) arg3, _SNY_ARG_4(tuple) arg4, _SNY_ARG_5(tuple) arg5, _SNY_ARG_6(tuple) arg6, _SNY_ARG_7(tuple) arg7, _SNY_ARG_8(tuple) arg8, _SNY_ARG_9(tuple) arg9, _SNY_ARG_10(tuple) arg10, _SNY_ARG_11(tuple) arg11, _SNY_ARG_12(tuple) arg12, _SNY_ARG_13(tuple) arg13, _SNY_ARG_14(tuple) arg14
#define _SNY_APPLY_MEMBER_ARGS_15(tuple) _SNY_ARG_2(tuple) arg2, _SNY_ARG_3(tuple) arg3, _SNY_ARG_4(tuple) arg4, _SNY_ARG_5(tuple) arg5, _SNY_ARG_6(tuple) arg6, _SNY_ARG_7(tuple) arg7, _SNY_ARG_8(tuple) arg8, _SNY_ARG_9(tuple) arg9, _SNY_ARG_10(tuple) arg10, _SNY_ARG_11(tuple) arg11, _SNY_ARG_12(tuple) arg12, _SNY_ARG_13(tuple) arg13, _SNY_ARG_14(tuple) arg14, _SNY_ARG_15(tuple) arg15
#define _SNY_APPLY_MEMBER_ARGS_16(tuple) _SNY_ARG_2(tuple) arg2, _SNY_ARG_3(tuple) arg3, _SNY_ARG_4(tuple) arg4, _SNY_ARG_5(tuple) arg5, _SNY_ARG_6(tuple) arg6, _SNY_ARG_7(tuple) arg7, _SNY_ARG_8(tuple) arg8, _SNY_ARG_9(tuple) arg9, _SNY_ARG_10(tuple) arg10, _SNY_ARG_11(tuple) arg11, _SNY_ARG_12(tuple) arg12, _SNY_ARG_13(tuple) arg13, _SNY_ARG_14(tuple) arg14, _SNY_ARG_15(tuple) arg15, _SNY_ARG_16(tuple) arg16

#define _SNY_PASS_ARGS_0
#define _SNY_PASS_ARGS_1 arg1
#define _SNY_PASS_ARGS_2 _SNY_PASS_ARGS_1, arg2
#define _SNY_PASS_ARGS_3 _SNY_PASS_ARGS_2, arg3
#define _SNY_PASS_ARGS_4 _SNY_PASS_ARGS_3, arg4
#define _SNY_PASS_ARGS_5 _SNY_PASS_ARGS_4, arg5
#define _SNY_PASS_ARGS_6 _SNY_PASS_ARGS_5, arg6
#define _SNY_PASS_ARGS_7 _SNY_PASS_ARGS_6, arg7
#define _SNY_PASS_ARGS_8 _SNY_PASS_ARGS_7, arg8
#define _SNY_PASS_ARGS_9 _SNY_PASS_ARGS_8, arg9
#define _SNY_PASS_ARGS_10 _SNY_PASS_ARGS_9, arg10
#define _SNY_PASS_ARGS_11 _SNY_PASS_ARGS_10, arg11
#define _SNY_PASS_ARGS_12 _SNY_PASS_ARGS_11, arg12
#define _SNY_PASS_ARGS_13 _SNY_PASS_ARGS_12, arg13
#define _SNY_PASS_ARGS_14 _SNY_PASS_ARGS_13, arg14
#define _SNY_PASS_ARGS_15 _SNY_PASS_ARGS_14, arg15
#define _SNY_PASS_ARGS_16 _SNY_PASS_ARGS_15, arg16

#define _SNY_PASS_MEMBER_ARGS_0
#define _SNY_PASS_MEMBER_ARGS_1
#define _SNY_PASS_MEMBER_ARGS_2 _SNY_PASS_ARGS_1, arg2
#define _SNY_PASS_MEMBER_ARGS_3 _SNY_PASS_ARGS_2, arg3
#define _SNY_PASS_MEMBER_ARGS_4 _SNY_PASS_ARGS_3, arg4
#define _SNY_PASS_MEMBER_ARGS_5 _SNY_PASS_ARGS_4, arg5
#define _SNY_PASS_MEMBER_ARGS_6 _SNY_PASS_ARGS_5, arg6
#define _SNY_PASS_MEMBER_ARGS_7 _SNY_PASS_ARGS_6, arg7
#define _SNY_PASS_MEMBER_ARGS_8 _SNY_PASS_ARGS_7, arg8
#define _SNY_PASS_MEMBER_ARGS_9 _SNY_PASS_ARGS_8, arg9
#define _SNY_PASS_MEMBER_ARGS_10 _SNY_PASS_ARGS_9, arg10
#define _SNY_PASS_MEMBER_ARGS_11 _SNY_PASS_ARGS_10, arg11
#define _SNY_PASS_MEMBER_ARGS_12 _SNY_PASS_ARGS_11, arg12
#define _SNY_PASS_MEMBER_ARGS_13 _SNY_PASS_ARGS_12, arg13
#define _SNY_PASS_MEMBER_ARGS_14 _SNY_PASS_ARGS_13, arg14
#define _SNY_PASS_MEMBER_ARGS_15 _SNY_PASS_ARGS_14, arg15
#define _SNY_PASS_MEMBER_ARGS_16 _SNY_PASS_ARGS_15, arg16

#define _SNY_PASS_ARGS(n) _SNY_APPLY_ARGS_##n
#define _SNY_PASS_MEMBER_ARGS(n) _SNY_PASS_MEMBER_ARGS_##n

#pragma endregion

#define _SNY_CONCAT(x, y) x##y
#define _SNY_MAKE_UNIQUE _SNY_CONCAT(__sny, __COUNTER__)

#define DECLARE_METHOD_DETAIL(address, type, name) \
    struct name##_ : public Sonny::MethodDetail<type> \
    {\
        static constexpr auto mSignature = address; \
        static constexpr const char *mpacName = #name; \
    };
#define DECLARE_METHOD_DETAIL_DLL(address, type, name, dll) \
    struct name##_ : public Sonny::MethodDetail<type> \
    {\
        static constexpr auto mSignature = address; \
        static constexpr const char *mpacName = #name; \
        static constexpr const char *mpacModule = dll; \
    };

// helper since we need to call _SNY_MAKE_UNIQUE to avoid redefinition
#define _DECLARE_SETUP_FUNCTION(name, module, callback) \
    struct name : public Sonny::SetupFunction \
    {\
        name() : Sonny::SetupFunction(module, callback) {} \
    };
#define _DECLARE_HOOK(id, name, amount, callback) 


// cast pointer to the original function type and call it with unpacked arguments from the tuple
#define _SNY_METHOD_IMPL(name, amount) reinterpret_cast<name##_::FnPtrType>(name##_::muiPtr)(_SNY_PASS_ARGS(amount))
#define _SNY_MEMBER_IMPL(name, amount) reinterpret_cast<name##_::FnPtrType>(name##_::muiPtr)(_SNY_PASS_MEMBER_ARGS(amount))

#define DECLARE_METHOD_IMPL(name, amount) \
    name##_::ReturnType name(_SNY_APPLY_ARGS_##amount(name##_::ArgsTuple)) { return _SNY_METHOD_IMPL(name, amount); }
#define DECLARE_METHOD_IMPL_V(name, amount) \
    name##_::ReturnType name(_SNY_APPLY_ARGS_##amount(name##_::ArgsTuple)) { _SNY_METHOD_IMPL(name, amount); }
#define DECLARE_MEMBER_IMPL(name, amount) \
    name##_::ReturnType name(_SNY_APPLY_MEMBER_ARGS_##amount(name##_::ArgsTuple)) { return _SNY_MEMBER_IMPL(name, amount); }
#define DECLARE_MEMBER_IMPL_V(name, amount) \
    name##_::ReturnType name(_SNY_APPLY_MEMBER_ARGS_##amount(name##_::ArgsTuple)) { _SNY_MEMBER_IMPL(name, amount); }

// hook a method
#define DECLARE_METHOD_HOOK(name, amount, callback) _DECLARE_HOOK(_SNY_MAKE_UNIQUE, name, amount, callback)

#define DECLARE_METHOD_HOOK_V(name, amount, callback) 

// hook a method but with a callback queue
#define DECLARE_METHOD_HOOK_QUEUE(name, amount)


using __sny_setupfn_t = std::function<void()>;

// Vector with pairs of module name and setup function, if proc is main then first element is nullptr
#define DECLARE_CALLBACK_SETUP() \
    std::vector<std::pair<const char*, __sny_setupfn_t>> __snycbv__ = std::vector<std::pair<const char*, __sny_setupfn_t>>();

extern std::vector<std::pair<const char*, __sny_setupfn_t>> __snycbv__;

class Sonny
{
public:
    using SetupFnType = __sny_setupfn_t;

    static void Init()
    {
#if SONNY_HOOKLIB == MINHOOK
        MH_Initialize();

        for (auto &pair : __snycbv__)
        {
            if (pair.first == nullptr)
            {
                pair.second();
            }
        }

        MH_EnableHook(MH_ALL_HOOKS);
#endif
    }

    static void Cleanup()
    {
#if SONNY_HOOKLIB == MINHOOK
        MH_DisableHook(MH_ALL_HOOKS);
        MH_Uninitialize();
#endif
    }

    template <typename F>
    class FunctionTraits;

    template <typename R, typename... Args>
    class FunctionTraits<std::function<R(Args...)>>
    {
      public:
        using Type = R;
        using ArgsTuple = std::tuple<Args...>;
    };

    template <typename Fn>
    class MethodDetail
    {
      public:
        using ReturnType = typename FunctionTraits<std::function<Fn>>::Type;
        using ArgsTuple = typename FunctionTraits<std::function<Fn>>::ArgsTuple;
        using FnType = Fn;
        using FnPtrType = std::add_pointer_t<Fn>;

        struct QueueMember
        {
            std::function<Fn> mCallback;
            // might rip this out for a priority system later, just a safeguard for undefined behaviour
            bool mbNeedsReturn;
        };
        // ideally create everything on the stack as static, there should only be 1 instance of this class per method

        static constexpr auto mSignature = nullptr;
        static constexpr const char *mpacName = nullptr;
        static constexpr const char *mpacModule = nullptr;
        // needs to be initialised from the static initialiser stuff
        static uintptr_t muiPtr;
        static std::deque<QueueMember *> mFnQueue;
        static bool mbFinalSet;
        static std::function<Fn> mFn;
    };

    class SetupFunction
    {
      public:
        SetupFunction(const char *module, SetupFnType fn)
        {
            __snycbv__.push_back({module, fn});
        }

        template <typename Fn>
        static void _BasicSetup(Fn lFn, uintptr_t luiPtr, uintptr_t luiTrampoline)
        {
#if SONNY_HOOKLIB == MINHOOK
            MH_CreateHook(luiPtr, lFn, reinterpret_cast<LPVOID*>(&trampoline));
#endif
        }
    };

}; // namespace sonny

#endif //_SONNY_H_