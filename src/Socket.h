#pragma once


#include <vector>
#include <string>

#ifdef _MSC_VER
#include <WinSock2.h> //fd_set
#else
#include <sys/socket.h>
#include <netinet/in.h>
typedef int SOCKET;
#endif

namespace sd
{
	class Socket
	{
	public:
		Socket() : MAX_BUFFER_SIZE(1024), af(AF_INET), type(SOCK_STREAM), proto(0), port(10000)
		{
			recvBufferPtr = new char[MAX_BUFFER_SIZE];
			memset(recvBufferPtr, 0, MAX_BUFFER_SIZE);
			sendBufferPtr = new char[MAX_BUFFER_SIZE];
			memset(sendBufferPtr, 0, MAX_BUFFER_SIZE);
		}
		virtual ~Socket()
		{
			if (recvBufferPtr)
				delete[] recvBufferPtr;
			if (sendBufferPtr)
				delete[] sendBufferPtr;
		}

		virtual void SetAF(int theAf){ af = theAf; }
		virtual void SetType(int theType){ type = theType; }
		virtual void SetProtocol(int protocol){ proto = protocol; }
		virtual void SetPort(unsigned int thePort){ port = thePort; }

		virtual void Run() = 0;
		virtual bool Start(const std::string& address, const unsigned int thePort = 0) = 0;
	protected:
			virtual bool Create() = 0;

		char * recvBufferPtr;
		char * sendBufferPtr;
		int af;
		int type;
		int proto;
		unsigned int port;
		fd_set fdSockets;
		SOCKET sock;
		struct sockaddr_in sockAddress;
	private:
		const int MAX_BUFFER_SIZE;
		
	};

	class ServerSocket: virtual public Socket
	{
	public:
		ServerSocket() :MAX_CLIENTS(100) 
		{
			m_clientsPtr = new SOCKET[MAX_CLIENTS];
		}

		~ServerSocket()
		{
			if (NULL != m_clientsPtr)
			{
				delete [] m_clientsPtr;
			}
		}
		bool Start(const std::string& address, const unsigned int thePort = 0);
		void Run();
	private:
		bool Create();
		bool Bind(const std::string& address);
		const unsigned int MAX_CLIENTS;
		SOCKET * m_clientsPtr;

	};

	class ClientSocket : virtual public Socket
	{
	public:
		bool Start(const std::string& address, const unsigned int thePort = 0);
		void Run();
	private:
		bool Create();

	};
}

