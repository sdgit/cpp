#include "Socket.h"

#ifdef _MSC_VER
#include <WS2tcpip.h>
#else
#endif

namespace sd
{
	bool ServerSocket::Create()
	{
		sock = socket(af, type, proto);
		return (sock >= 0);
	}

	bool  ServerSocket::Bind(const std::string& address)
	{
		struct sockaddr_in servAddress;

		memset(&servAddress, 0, sizeof(servAddress));
		servAddress.sin_port = htons(port);
		if (address.empty())
		{
			servAddress.sin_addr.s_addr = INADDR_ANY;
		}
		else
		{
#ifdef _MSC_VER
			inet_pton(AF_INET, address.c_str(), &servAddress.sin_addr);
#else
			servAddress.sin_addr.s_addr = inet_addr(address.c_str());
#endif
		}

		int error = bind(sock, (const sockaddr *)&servAddress, sizeof(servAddress));
		
		return (error == 0);
	}

	bool ServerSocket::Start(const std::string& address, const unsigned int thePort)
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
