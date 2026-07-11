#include "Window.h"

HWND g_MainWindow = nullptr;

HWND g_LogWindow = nullptr;
HWND g_ReporterWindow = nullptr;
HWND g_ResetButton = nullptr;
HWND g_ReloadButton = nullptr;

namespace
{
    constexpr wchar_t CLASS_NAME[] = L"AuthServer";
    constexpr wchar_t WINDOW_TITLE[] = L"L2Auth Recovered";
    constexpr wchar_t WINDOW_LOG_TITLE[] = L"Log window";

    LRESULT CALLBACK WindowProc(
        HWND hwnd,
        UINT msg,
        WPARAM wParam,
        LPARAM lParam)
    {
        switch (msg)
        {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        }

        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
}

static void RegisterWindowClass(HINSTANCE hInstance) {
    WNDCLASSEX windowClass{};

    windowClass.cbSize = sizeof(WNDCLASSEX);
    windowClass.style = CS_CLASSDC;
    windowClass.lpfnWndProc = WindowProc;
    windowClass.cbClsExtra = 0;
    windowClass.cbWndExtra = 0;
    windowClass.hInstance = hInstance;
    windowClass.hIcon = nullptr;
    windowClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
    windowClass.hbrBackground = nullptr;
    windowClass.lpszMenuName = nullptr;
    windowClass.lpszClassName = CLASS_NAME;
    windowClass.hIconSm = nullptr;

    RegisterClassEx(&windowClass);
}

void CreateUI(
    HINSTANCE hInstance,
    int nCmdShow)
{
    RegisterWindowClass(hInstance);

    CreateMainWindow(hInstance, nCmdShow);

    CreateLogWindow(hInstance);
    CreateReporterWindow(hInstance);
    CreateResetButton(hInstance);
    CreateReloadButton(hInstance);
}

/*
означает:

0 Ч X (начать от левого кра€)
30 Ч Y (30 пикселей вниз)
640 Ч ширина
720 Ч высота
*/
void CreateMainWindow(
    HINSTANCE hInstance,
    int nCmdShow)
{
    g_MainWindow = CreateWindowEx(
        0,
        CLASS_NAME,
        WINDOW_TITLE,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        610,
        440,
        nullptr,
        nullptr,
        hInstance,
        nullptr);

    ShowWindow(g_MainWindow, nCmdShow);
    UpdateWindow(g_MainWindow);
}

void CreateLogWindow(HINSTANCE hInstance)
{
    g_LogWindow = CreateWindowEx(
        0x200u,
        CLASS_NAME,
        WINDOW_LOG_TITLE,
        0x40000000u,
        0,
        30,
        600,
        410,
        g_MainWindow,
        0,
        hInstance,
        0);

    ShowWindow(g_LogWindow, 5);
    UpdateWindow(g_LogWindow);
}

void CreateReporterWindow(HINSTANCE hInstance)
{
    g_ReporterWindow = CreateWindowEx(
        0x200u,
        CLASS_NAME,
        WINDOW_LOG_TITLE,
        0x40000000u,
        120,
        5,
        480,
        20,
        g_MainWindow,
        0,
        hInstance,
        0);

    ShowWindow(g_ReporterWindow, 5);
    UpdateWindow(g_ReporterWindow);
}

void CreateResetButton(HINSTANCE hInstance)
{
    g_ResetButton = CreateWindowEx(
        0,
        L"Button",
        L"Reset",
        WS_CHILD | WS_VISIBLE,
        0,
        5,
        60,
        20,
        g_MainWindow,
        reinterpret_cast<HMENU>(1),
        hInstance,
        nullptr);

    ShowWindow(g_ResetButton, 5);
    UpdateWindow(g_ResetButton);
}

void CreateReloadButton(HINSTANCE hInstance)
{
    g_ReloadButton = CreateWindowEx(
        0,
        L"Button",
        L"Reload",
        WS_CHILD | WS_VISIBLE,
        60,
        5,
        60,
        20,
        g_MainWindow,
        reinterpret_cast<HMENU>(2),
        hInstance,
        nullptr);

    ShowWindow(g_ReloadButton, 5);
    UpdateWindow(g_ReloadButton);
}