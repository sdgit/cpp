#pragma once
#include <iostream>

namespace sd
{
	class number_utils
	{
	public:
		number_utils(void);
		~number_utils(void);

		static bool compare(double a, double b, double epsilon);
		static bool sortInPlace(int * nums, int length);
		bool almostEqual(float a, float b, float epsilon);

		void printFizzBuzz();
		static int reverseNumber(int number);
		static void fibonacci(int n);
		static bool String2Int(const std::string& str, int& result);
		static int FindFirtSignedInt(std::string str);
		static float sqrt(float n);
		static float sqrt1(float n);
	};
}

namespace kc {
	void swap_int(int& x, int& y);
}
