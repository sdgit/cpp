#include "stringfunctions.h"
#include <string>
#include <list>
//#include <iterator>

using std::string;

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

	string longestCommonStr(string &first, string &second)
	{
	
		//wrong, use suffix tree
		string prelimResult, result;

		for(string::size_type i = 0; i < first.size(); i++)
		{
			if(first[i] == second[i])
			{
				prelimResult.append(1, first[i]);
			}
			else
			{
				prelimResult.empty();
			}

			if(prelimResult.size() > result.size())
			{
				result = prelimResult;
			}
		}
			

		return result;

	}

	long substringCaculator(string st) {

		long listsize = 0;
		int originalSize = 0;
		std::list<string> mysubstrings;

		//for every substring from the left get it and place in my substrings
		//for (int i = 2;)
		{

			//for every substring from the right get it and place in mysubstrings

			//remove the duplicates
		}
		mysubstrings.unique();
		// get the size of list
		listsize = mysubstrings.size();
		
		return listsize;

	}
}
