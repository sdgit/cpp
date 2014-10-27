#include "Thread.h"
#include <iostream>

using std::cout;

#ifdef __linux__
namespace sd 
{

	bool SocketThread::SetServer()
	{
		socketPtr = new ServerSocket();
		name = "ServerThread";
		socketPtr->Start("");
	}

	bool SocketThread::SetClient()
	{
		socketPtr = new ClientSocket();
		name = "ClientThread";
		socketPtr->Start("");
	}

	void SocketThread::InternalThreadEntry()
	{
		cout<<"Running Thread for "<<typeid(this).name()<<std::endl;
		socketPtr->Run();
	}
}

#endif
