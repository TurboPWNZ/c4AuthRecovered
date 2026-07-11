#include "Application.h"

#include <windows.h>

namespace
{
    constexpr wchar_t WINDOW_NAME[] = L"L2Auth Recovered";
}

bool Application::CheckSingleInstance()
{
    if (FindWindow(nullptr, WINDOW_NAME))
    {
        MessageBox(
            nullptr,
            L"Application is already running.",
            L"Auth Server",
            MB_ICONERROR);

        return false;
    }

    return true;
}