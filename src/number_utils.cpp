#include "number_utils.h"
#include "math.h"
#include "float.h"
#include <iostream>
#include <sstream>

using std::cout;

namespace sd {

	number_utils::number_utils(void)
	{
	}


	number_utils::~number_utils(void)
	{
	}

	bool number_utils::compare(double a, double b, double epsilon)
	{
		if( fabs(a -b) < epsilon)
		{
			return (true);
		}

		return (false);
	}

	bool number_utils::sortInPlace(int * nums, int length)
	{

		return (true);
	}

	bool number_utils::almostEqual(float a, float b, float epsilon) {
		float absA = fabs(a);
		float absB = fabs(b);
		float diff = fabs(a - b);

		if (a == b) { //handles infinite numbers
			return true;
		} else if (a == 0 || b == 0 || diff < FLT_MIN) {
			// a or b is zero or both are extremely close to it
			return (diff < (epsilon * FLT_MIN ));
		} else { // use relative error
			return (diff / (absA + absB) < epsilon);
		}
	}
	
/*
	Write a program which prints the numbers from 1 to N, each on a new line. But for multiples of three print "Fizz" instead of the number 3 and for the multiples of five print "Buzz".  For numbers which are multiples of both three and five print "FizzBuzz". Read in the input number from STDIN.
	Sample Input #00:
	15
	Sample Output #00 :
	1
	2
	Fizz
	4
	Buzz
	Fizz
	7
	8
	Fizz
	Buzz
	11
	Fizz
	13
	14
	FizzBuzz
	Explanation:
	Position 3,6,9,12 have the word "Fizz" because they are multiples of 3.
	Positions 5 and 10 have the word "Buzz" because they are multiples of 5. 
	Position 15 has the word FizzBuzz because it is a multiple of both 3 and 5. 
	Constraints :
	N < 107
*/
	void number_utils::printFizzBuzz()
	{
		unsigned int N;

		cout << "printFizzBuzz were N=";
		std::cin >> N;
		if (N >= 106) //constraint given by problem
			N = 106;
		cout << N << std::endl;
		
		for (int i = 1; i <= N; i++)
		{
			if (i % 3 == 0)
			{
				cout << "Fizz";
			}
			if (i % 5 == 0)
			{
				cout << "Buzz";
			}
			if (i % 3 != 0 && i % 5 != 0)
			{
				cout << i;
			}
			cout << std::endl;
		}
	}

	int number_utils::reverseNumber(int number)
	{
		int reverse = 0;
		while (number != 0)
		{
			reverse = reverse * 10;
			reverse = reverse + number % 10;
			number = number / 10;
		}

		return reverse;
	}

	void number_utils::fibonacci(int n)
	{
		int c, first = 0, second = 1, next;

		cout << "Fibonacci of " << n << std::endl;
		for (c = 0; c < n; c++)
		{
			if (c <= 1)
				next = c;
			else
			{
				next = first + second;
				first = second;
				second = next;
			}
			cout << next << " ";
		}
		cout << std::endl;
	}

	bool number_utils::String2Int(const std::string& str, int& result)
	{
		std::istringstream ss(str);
		ss.imbue(std::locale::classic());
		ss >> result;
		return !ss.fail() && ss.eof();
	}
}
