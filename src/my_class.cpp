#include "my_class.h"

#include <iostream>

#if __cplusplus > 199711L || _MSC_VER >= 1203
namespace kc{
	using namespace std;
	MyClass::MyClass()
	{
		cout << "calling MyClass()" << endl;
	}

	MyClass::MyClass(const MyClass& mc)
	{
		cout << "calling MyClass(const MyClass&)" << endl;
	}

	MyClass::~MyClass()
	{
		cout << "calling ~MyClass()" << endl;
	}

	MyClass::MyClass(const MyClass&&) {
		cout << "calling move constructor" << endl;
	}

	MyClass& MyClass::operator=(MyClass&&) {
		cout << "calling move assignment" << endl;
		return *this;
	}

	MyClass& MyClass::operator=(const MyClass& mc) {
		cout << "calling assignment operator" << endl;

		return *this;
	}

	void MyClass::print() const{
		cout << "printing..." << endl;
	}
}
#endif
