#include "stringfunctions.h"

namespace sd {

	bool ReverseString(char theString[], int size)
	{
	  char * currPos = theString;
	  char * end = &theString[size-1];
	  char temp = 0;

	  if(theString == NULL || size < 1)
	  {
		  return false;
	  }

	  while(currPos != end)
	  {
		 temp = *currPos;
		 *currPos = *end;
		 *end = temp;

		 currPos++;

		 if(currPos == end)
		 {
			 break;
		 }
		 end--;
	  }

	  return 0; //change this or review!
	}

	int UniqueElements(char * array, int size)
	{
		int found = 0;
		bool uniqueFlag = false;
		char *unique = new char[size];

		if(array == NULL || size < 1)
		{
			return -1;
		}

		for( int i = 0; i < size; i++ )
		{
			uniqueFlag = true;

			for(int j =0; j <found; j++)
			{
				if(array[i] == unique[j])
				{
					//not unique
					uniqueFlag = false;
					continue;
				}
			}

			if(uniqueFlag == true)
			{
				unique[found] = array[i];
				found++;
			}

		}

		delete [] unique;
		return found;


	}
}
