#ifndef STRINGFUNCTION_H
#define STRINGFUNCTION_H

#include <iostream>

namespace sd {
	bool ReverseString(char * theString, int size);

	int UniqueElements(char * array, int size);

	std::string longestCommonStr(std::string &first, std::string &second);

	long substringCaculator(std::string st);

	std::string reverseStringNotWords(const std::string& sentence);
}

#endif