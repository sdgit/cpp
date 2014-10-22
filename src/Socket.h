#pragma once


#include <vector>
#include <string>

#ifdef _MSC_VER
#include <WinSock2.h> //fd_set
#else
#include <sys/socket.h>
#define SOCKET int
#endif

namespace sd
{
	class Socket
	{
	public:
		virtual void SetAF(int theAf){ af = theAf; }
		virtual void SetType(int theType){ type = theType; }
		virtual void SetProtocol(int protocol){ proto = protocol; }
		virtual void SetPort(unsigned int thePort){ port = thePort; }
	protected:
		Socket() : MAX_BUFFER_SIZE(1024), af(AF_INET), type(SOCK_STREAM), proto(0), port(10000)
		{
			recvBufferPtr = new char[MAX_BUFFER_SIZE];
			memset(recvBufferPtr, 0, MAX_BUFFER_SIZE);
			sendBufferPtr = new char[MAX_BUFFER_SIZE];
			memset(sendBufferPtr, 0, MAX_BUFFER_SIZE);
		}
		~Socket()
		{
			if (recvBufferPtr)
				delete[] recvBufferPtr;
			if (sendBufferPtr)
				delete[] sendBufferPtr;
		}

		virtual bool Create() = 0;

		char * recvBufferPtr;
		char * sendBufferPtr;
		int af;
		int type;
		int proto;
		unsigned int port;
		fd_set sockets;
		SOCKET sock;
	private:
		const int MAX_BUFFER_SIZE;
		
	};

	class ServerSocket: virtual public Socket
	{
	public:
		bool Start(const std::string& address, const unsigned int thePort = 0);
	private:
		bool Create();
		bool Bind(const std::string& address);

	};

	class ClientSocket : virtual public Socket
	{

	};
}

