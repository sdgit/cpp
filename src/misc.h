#ifndef MISC_H
#define MISC_H

#include <iostream>

namespace sd
{
	template<typename T>
	void printArray(T theArray[], int start, int end )
	{
		std::cout<<"Array: [";

		for (int i = start; i < end; i++)
		{
			std::cout << theArray[i];
			if (i < end - 1)
			{
				std::cout << ",";
			}
		}
		std::cout<<"]"<<std::endl;
	}

	bool evenDivide(const int &a, const int &b);

	//reference count class
	class RC
	{
	private:
		int count; // Reference count

	public:
		RC() : count(0){}
		void AddRef()
		{
			// Increment the reference count
			count++;
		}

		int Release()
		{
			// Decrement the reference count and
			// return the reference count.
			return --count;
		}
	};

	//smart pointer class
	template < typename T > class SP
	{
	private:
		T*    pData;       // pointer
		RC* reference; // Reference count

	public:
		SP() : pData(0), reference(0)
		{
			// Create a new reference 
			reference = new RC();
			// Increment the reference count
			reference->AddRef();
		}

		SP(T* pValue) : pData(pValue), reference(0)
		{
			// Create a new reference 
			reference = new RC();
			// Increment the reference count
			reference->AddRef();
		}

		SP(const SP<T>& sp) : pData(sp.pData), reference(sp.reference)
		{
			// Copy constructor
			// Copy the data and reference pointer
			// and increment the reference count
			reference->AddRef();
		}

		~SP()
		{
			// Destructor
			// Decrement the reference count
			// if reference become zero delete the data
			if (reference->Release() == 0)
			{
				delete pData;
				delete reference;
			}
		}

		T& operator* ()
		{
			return *pData;
		}

		T* operator-> ()
		{
			return pData;
		}

		SP<T>& operator = (const SP<T>& sp)
		{
			// Assignment operator
			if (this != &sp) // Avoid self assignment
			{
				// Decrement the old reference count
				// if reference become zero delete the old data
				if (reference->Release() == 0)
				{
					delete pData;
					delete reference;
				}

				// Copy the data and reference pointer
				// and increment the reference count
				pData = sp.pData;
				reference = sp.reference;
				reference->AddRef();
			}
			return *this;
		}
	};
}

#endif


