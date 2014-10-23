#include "Thread.h"
#include <iostream>

using std::cout;

#ifdef __linux__
namespace sd 
{

	bool SocketThread::SetServer()
	{
		socketPtr = new ServerSocket();
		socketPtr->Start("");
	}

	bool SocketThread::SetClient()
	{
		socketPtr = new ClientSocket();
		socketPtr->Start("");
	}

	void SocketThread::InternalThreadEntry()
	{
		cout<<"Running Thread for "<<typeid(this).name()<<std::endl;
		socketPtr->Run();
	}
}

#endif
