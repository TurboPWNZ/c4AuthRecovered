#include "Network.h"

#include <WinSock2.h>
#include <Windows.h>

#pragma comment(lib, "Ws2_32.lib")

static WSADATA g_WsaData{};

bool InitializeNetwork()
{
    const int result = WSAStartup(MAKEWORD(2, 2), &g_WsaData);

    if (result != 0)
    {
        return false;
    }

    return true;
}

void ShutdownNetwork()
{
    WSACleanup();
}