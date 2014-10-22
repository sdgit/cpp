#pragma once

#ifdef __linux__
#include <pthread.h>
#include "Socket.h"

namespace sd 
{
	class SocketThreads
	{
	public:
		static bool StartServer(Socket& sock);
		static void * server(void * arg);
	private:
		SocketThreads(){}
		~SocketThreads(){}

		static pthread_t *thread;
		static pthread_attr_t *attr;
	};
}

#endif

