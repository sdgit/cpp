#include "misc.h"

using std::cout;

namespace sd
{
	bool evenDivide(const int &a, const int &b)
	{
		if ((a / b % 2) == 0)
			return true;
		return false;

	}
}



