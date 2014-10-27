#ifndef STRINGFUNCTION_H
#define STRINGFUNCTION_H

#include <iostream>

namespace sd {
	bool ReverseString(char theString[]);
	void ReverseString(std::string & str);

	int UniqueElements(char * str);

	std::string longestCommonStr(std::string &first, std::string &second);

	long substringCaculator(std::string st);

	std::string reverseStringNotWords(const std::string& sentence);
}

#endif
