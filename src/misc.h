#ifndef MISC_H
#define MISC_H

#include <iostream>

namespace sd
{
	template<typename T>
	void printArray(T theArray[], int start, int end )
	{
		std::cout<<"Array: [";

		for (int i = start; i < end; i++)
		{
			std::cout << theArray[i];
			if (i < end - 1)
			{
				std::cout << ",";
			}
		}
		std::cout<<"]"<<std::endl;
	}
}

#endif


