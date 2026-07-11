#include "WinMain.h"
#include "Window.h"
#include <Application/Application.h>
#include <Crypto/Crypto.h>
#include <Exception/Exception.h>
#include <Network/Network.h>

static int RunMessageLoop()
{
    MSG msg{};

    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    ShutdownNetwork();

    return static_cast<int>(msg.wParam);
}

int RunApplication(
    HINSTANCE hInstance,
    HINSTANCE,
    PWSTR,
    int nCmdShow)
{
    if (!Application::CheckSingleInstance())
        return 0;

    Crypto::InitializeBlowfish();
    Crypto::InitializeDes();

    ExceptionInit();

    InitializeNetwork();

    CreateUI(hInstance, nCmdShow);
    //if (!CreateMainWindow(hInstance, nCmdShow))
    //    return -1;

    return RunMessageLoop();
}
