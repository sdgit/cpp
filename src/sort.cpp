
#include "misc.h"

namespace sd
{
	void swap(int theArray[], int a, int b)
	{
		int temp = theArray[a];
		theArray[a] = theArray[b];
		theArray[b] = temp;
	}

	int split(int theArray[], int left, int right)
	{
		int pivot = theArray[(left + right) / 2];
		int i = left;
		int j = right;

		while (i <= j)
		{
			while (theArray[i] < pivot)
				i++;
			while (theArray[j] > pivot)
				j--;
			if (i <= j)
			{
				swap(theArray, i, j);
				i++;
				j--;
			}
		}

		return i;

	}

	void QuickSort(int theArray[], int left, int right)
	{
		sd::printArray(theArray, left, right + 1);

		int index = split(theArray, left, right);
		if (left < index - 1)
			QuickSort(theArray, left, index - 1);
		if (index < right)
			QuickSort(theArray, index, right);

		sd::printArray(theArray, left, right + 1);
	}
}
