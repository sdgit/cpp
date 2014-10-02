#include "number_utils.h"
#include "math.h"
#include "float.h"


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
