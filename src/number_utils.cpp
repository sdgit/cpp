#include "number_utils.h"
#include "math.h"
#include "float.h"
#include <iostream>
#include <sstream>
#include <limits>
#include <math.h>

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
		if (fabs(a - b) < epsilon)
		{
			return (true);
		}

		return (false);
	}

	bool number_utils::sortInPlace(int * nums, int length)
	{

		return (true);
	}

	//doesnt work for numbers less than 1

	float number_utils::sqrt1(float n)
	{
		float x = n;
		float y = 1;
		float e = 0.0000001;

		while (x - y > e)
		{
			x = (x + y) / 2;
			y = n / x;
		}

		return x;
	}

	float number_utils::sqrt(float n)
	{
		float e = .00000001; //precision
		float min = std::numeric_limits<float>::min();;
		float max = std::numeric_limits<float>::max();
		float f;

		//the guess
		if (n >= 4.0)
		{
			f = n / 2.0;
		}
		else
		{
			f = n * 2.0;
		}

		for (; f > min; f = nextafterf(f, -1.0))
		{
			if ((f*f <= (n + e)) && ((f*f >= (n - e))))
			{
				return f;
			}
		}
	}

	bool number_utils::almostEqual(float a, float b, float epsilon) {
		float absA = fabs(a);
		float absB = fabs(b);
		float diff = fabs(a - b);

		if (a == b) { //handles infinite numbers
			return true;
		}
		else if (a == 0 || b == 0 || diff < FLT_MIN) {
			// a or b is zero or both are extremely close to it
			return (diff < (epsilon * FLT_MIN));
		}
		else { // use relative error
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

	int number_utils::FindFirtSignedInt(std::string str)
	{
		std::string allDelimiters = "+-0123456789";
		std::string numDelimiters = "0123456789";
		std::string numberStr;
		int number = 0;
		int start = str.find_first_of(allDelimiters);
		int end = 0;

		if (start != std::string::npos)
		{

			end = str.find_last_of(numDelimiters, start);
			numberStr = str.substr(start, end - start);
			String2Int(numberStr, number);
		}

		return number;
	}
}

namespace kc{
#include <limits>
	using namespace std;
	void swap_int(int& x, int&y) {
		x ^= y;
		y ^= x;
		x ^= y;
	}

	int string_to_int(const std::string& str) {
		int pos = 1;
		bool found_int = false;
		int ans = 0;

		int MAX_INT = numeric_limits<int>::max();

		for (string::const_iterator itr = str.begin(); itr != str.end(); ++itr) {
			char c = *itr;
			if (c == '-') {
				pos = -1;
			}
			else if (c > '0' && c < '9') {
				ans = (10 * ans) + (c - '0');
				found_int = true;
			}
			else if (found_int){
				break;
			}
		}
		if (found_int) {
			return pos * ans;
		}
		else {
			throw runtime_error("no int found");
		}
	}
}