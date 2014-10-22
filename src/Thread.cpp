#include "Thread.h"

#ifdef __linux__
namespace sd 
{
	pthread_t* SocketThreads::thread = NULL;
	pthread_attr_t* SocketThreads::attr = NULL;

	bool SocketThreads::StartServer(Socket& sock)
	{
	}
}

#endif
