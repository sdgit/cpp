#ifndef MISC_H
#define MISC_H

#include <iostream>

namespace sd
{
	template<typename T>
	void printArray(T theArray[] )
	{
		std::cout<<"Array: [";
		for(auto x: theArray)
		{
			std::cout<<x<<",";
		}
		std::cout<<"]";
	}
}

#endif


