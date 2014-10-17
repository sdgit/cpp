#include "stringfunctions.h"
#include <string>
#include <list>
#include <stack>
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
/*
	You are given a string S. You need to compute the number of distinct substrings of S.                 
	A substring of S can be obtained by either removing zero or more characters from the left side of S, or by removing zero or more characters from the right side of S, or a combination of both.
	Input Format:
	There is only one line of the input and it contains the string S
	S will only be composed of characters 'a' to 'z' and will not have more than 10^5 characters.
	Output Format:
	You should print the number of distinct substrings of S to the output. This number might be larger than what can be permitted by 32-bit integers.
	Sample input:
	kincenvizh
	Sample output:
	53
*/
	long substringCaculator(string st) {

		long listsize = 0;
		int originalSize = 0;
		std::list<string> mysubstrings;
		std::string temp;

		std::stack < string > s;
		s.push(st);

		//for every substring from the left get it and place in my substrings
		while (!s.empty())
		{
			temp = s.top();
			s.pop();

			mysubstrings.push_back(temp);

			for (int i = 1; i < temp.size() ; i++)
			{
				s.push(temp.substr(i));
			}
			//for every substring from the right get it and place in mysubstrings
			for (int j = temp.size() - 1; j > 0; j--)
			{
				s.push(temp.substr(0, j));
			}
		}
		
		mysubstrings.sort();
		//remove the duplicates
		mysubstrings.unique();
		// get the size of list
		listsize = mysubstrings.size();
		
		return listsize;

	}
}
