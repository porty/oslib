#pragma once

#include <WinSock2.h>
#pragma comment (lib, "ws2_32.lib")

#include "Win32Exception.h"

namespace OS { namespace Win
{
	class Winsock
	{
	public:
		Winsock()
		{
			WSAData data;
			WSAStartup(MAKEWORD(2, 2), &data);
		}

		~Winsock() { WSACleanup(); }
	};
} }
