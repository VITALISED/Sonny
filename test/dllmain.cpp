#include "dllmain.h"

DECLARE_CALLBACK_SETUP()

void Fish()
{};


BOOL APIENTRY DllMain(HMODULE hModule,
                      DWORD  ul_reason_for_call,
                      LPVOID lpReserved
                     )
{
    DisableThreadLibraryCalls(hModule);

    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        Sonny::Init();
        break;
    case DLL_PROCESS_DETACH:
        Sonny::Cleanup();
        break;
    }
    return TRUE;
}