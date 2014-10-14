#ifndef MISC_H
#define MISC_H

#include <iostream>

namespace sd
{
	template<typename T>
	void printArray(T theArray[], int size )
	{
		std::cout<<"Array: [";

		for (int i = 0; i < size; i++)
		{
			std::cout << theArray[i];
			if (i < size - 1)
			{
				std::cout << ",";
			}
		}
		std::cout<<"]";
	}
}

#endif


