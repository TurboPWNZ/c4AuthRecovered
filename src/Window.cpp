#include "Window.h"

namespace
{
    constexpr wchar_t CLASS_NAME[] = L"AuthServer";
    constexpr wchar_t WINDOW_TITLE[] = L"L2Auth Recovered";

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

bool CreateMainWindow(
    HINSTANCE hInstance,
    int nCmdShow)
{
    WNDCLASSEX wc{};

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);

    RegisterClassEx(&wc);

    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        WINDOW_TITLE,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        640,
        480,
        nullptr,
        nullptr,
        hInstance,
        nullptr);

    if (!hwnd)
        return false;

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    return true;
}
