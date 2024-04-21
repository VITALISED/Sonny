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

#define DECLARE_METHOD_DETAIL(address, type, name) \
    struct name##_ : public Sonny::MethodDetail<type> \
    {\
        static constexpr const char *mpacSignature = address; \
        static constexpr const char *mpacName = #name; \
    };

#define DECLARE_METHOD_IMPL()
#define DECLARE_METHOD_IMPL_NOHOOK()

#define _SNY_CONCAT(x, y) x##y
#define _SNY_MAKE_UNIQUE _SNY_CONCAT(__sny, __COUNTER__)

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

    template <typename Ret, typename... Args>
    class Detour;

    template <typename Ret, typename... Args>
    class Detour<Ret, std::tuple<Args...>>
    {
    private:
        uintptr_t *mpOriginal;
        uintptr_t mpFnAddress;
    };

    // void functions cannot return anything, so we need a specialisation for them
    template <typename... Args>
    class Detour<void, std::tuple<Args...>>
    {
    };

    template <typename Fn>
    class MethodDetail
    {
        using ReturnType = typename FunctionTraits<std::function<Fn>>::Type;
        using ArgsTuple = typename FunctionTraits<std::function<Fn>>::ArgsTuple;

        struct QueueMember
        {
            std::function<Fn> mCallback;
            // might rip this out for a priority system later, just a safeguard for undefined behaviour
            bool mbNeedsReturn;
        };
        // ideally create everything on the stack as static, there should only be 1 instance of this class per method

        static constexpr const char *mpacSignature = "";
        static constexpr const char *mpacName = "";
        static std::deque<QueueMember *> mFnQueue;
        static bool mbFinalSet;
        static std::function<Fn> mFn;
        //static Detour<ReturnType, ArgsTuple> mDetour;
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