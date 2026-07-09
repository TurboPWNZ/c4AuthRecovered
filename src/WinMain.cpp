#include "WinMain.h"
#include "Window.h"

int RunApplication(
    HINSTANCE hInstance,
    HINSTANCE,
    PWSTR,
    int nCmdShow)
{
    if (!CreateMainWindow(hInstance, nCmdShow))
        return -1;

    MSG msg{};

    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return static_cast<int>(msg.wParam);
}
