#pragma once
class number_utils
{
public:
	number_utils(void);
	~number_utils(void);

	static bool compare(double a, double b, double epsilon);
	static bool sortInPlace(int * nums, int length);
	bool almostEqual(float a, float b, float epsilon);
};

