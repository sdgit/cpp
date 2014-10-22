//#ifdef __linux__

#include "Socket.h"

namespace sd
{
	bool ServerSocket::Create()
	{
		sock = socket(af, type, proto);
		return (sock >= 0);
	}

	bool  ServerSocket::Bind(std::string address)
	{
		struct sockaddr_in servAddress;

		memset(&servAddress, 0, sizeof(servAddress));
		servAddress.sin_port = htons(port);
		if (address == "")
		{
			servAddress.sin_addr.s_addr = INADDR_ANY;
		}
		else
		{
			servAddress.sin_addr.s_addr = inet_addr(address.c_str());
		}

		int error = bind(sock, (const sockaddr *)&servAddress, sizeof(servAddress));
		
		return (error == 0);
	}

	bool ServerSocket::Start(const unsigned int thePort = 0, const std::string& address)
	{
		if (port > 0)
		{
			SetPort(thePort);
		}

		if (Create() && Bind(address))
		{
			return (0 == listen(sock, 5));
		}
	}
}

//#endif