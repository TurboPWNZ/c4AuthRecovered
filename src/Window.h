#pragma once

#include <Windows.h>

extern HWND g_MainWindow;
extern HWND g_LogWindow;
extern HWND g_ReporterWindow;
extern HWND g_ResetButton;
extern HWND g_ReloadButton;

void CreateUI(
    HINSTANCE hInstance,
    int nCmdShow);

void CreateMainWindow(
    HINSTANCE hInstance,
    int nCmdShow);

void CreateLogWindow(HINSTANCE hInstance);

void CreateReporterWindow(HINSTANCE hInstance);

void CreateResetButton(HINSTANCE hInstance);

void CreateReloadButton(HINSTANCE hInstance);