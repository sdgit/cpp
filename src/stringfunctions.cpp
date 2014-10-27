#include "stringfunctions.h"
#include <string>
#include <list>
#include <stack>
//#include <iterator>
#include <set>

using std::string;

namespace sd {

	std::string reverseStringNotWords(const std::string& sentence)
	{
		std::stack<string> words;
		int currentPosition = 0;
		int nextPosition = -1;
		string delimiters(" ");
		string reverse;

		do
		{
			currentPosition = nextPosition + 1;
			//sd1 find of last produces results with multi spaces if they were in orginal string
			nextPosition = sentence.find_last_of(delimiters, currentPosition);
			words.push(sentence.substr(currentPosition, nextPosition - currentPosition));
		}while (string::npos != nextPosition);

		while (false == words.empty())
		{
			reverse += words.top();
			reverse += " ";
			words.pop();
		}

		return reverse;
	}

	void ReverseString(std::string & str)
	{
		for (int i = 0, j = str.size() - 1; i < j; i++, j--)
		{
			std::swap(str[i], str[j]);
		}
	}

	bool ReverseString(char theString[])
	{
		int length = strlen(theString);
	    char temp = 0;

		for (int i = 0, j = length-1; i < j; i++, j--)
		{
			temp = theString[i];
			theString[i] = theString[j];
			theString[j] = temp;
		}

	  return true;
	}

	int UniqueElements(char * str)
	{
		int found = 0;
		int size = strlen(str);
		std::set<char> unique;

		for( int i = 0; i < size; i++ )
		{
			unique.insert(str[i]);
		}

		return unique.size();
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
