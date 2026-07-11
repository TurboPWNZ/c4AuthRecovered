#include "WinMain.h"

int WINAPI wWinMain(
    HINSTANCE hInstance, // Дескриптор (handle) текущего экземпляра приложения.
    HINSTANCE hPrevInstance, // всегда nullptr и больше не говорит о том что запущен еще такой процесс
    PWSTR lpCmdLine, // Это параметры командной строки без имени exe.
    int nCmdShow) // В каком состоянии желательно показать главное окно (обычное, свернутое, развернутое и т.д.).
{
    return RunApplication(
        hInstance,
        hPrevInstance,
        lpCmdLine,
        nCmdShow);
}
