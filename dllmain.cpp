#include <windows.h>

BOOL WINAPI DllMain([[maybe_unused]] HINSTANCE instance, unsigned long reason, void* reserved )
{
    if (reason == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(instance);

        // Don't go multithread with this, use CreateThreadpoolWork instead.
        QueueUserWorkItem([](LPVOID) -> DWORD {
            // Soon examples...
            return 0;
        }, nullptr, WT_EXECUTEDEFAULT);
    }

    return TRUE;
}