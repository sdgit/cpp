#pragma once

namespace kc{
	class MyClass
	{
	public:
		//Constructors
		MyClass();

		//Copy Constructors
		//MyClass(MyClass&);
		MyClass(const MyClass&);
		
		//Assignment Operator
		MyClass& operator=(const MyClass&);

		virtual ~MyClass();

		void print() const;
	private:
		int m_data;
	};

}
