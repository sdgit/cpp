#pragma once

//#ifdef __linux__

#include <vector>
#include <WinSock2.h> //fd_set

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
		bool Start(const unsigned int port, const std::string& address = "");
	private:
		bool Create();
		bool Bind(std::string address = "");

	};

	class ClientSocket : virtual public Socket
	{

	};
}

//#endif