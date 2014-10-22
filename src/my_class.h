#pragma once

#if __cplusplus > 199711L || _MSC_VER >= 1203
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

#endif


