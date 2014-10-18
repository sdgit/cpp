#pragma once

namespace kc{
	class MyClass
	{
	public:
		//Constructors
		MyClass();

		//Copy Constructors
		MyClass(const MyClass&);
		MyClass(const MyClass&&);
		//Assignment Operator
		MyClass& operator=(const MyClass&);
		MyClass& operator=(MyClass&&);

		virtual ~MyClass();

		void print() const;
	private:
		int m_data;
	};

}
