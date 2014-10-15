#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "linkedlist.h"

namespace sd
{

	class Stack
	{
		struct Node
		{
			struct Node* next;
			void * data;
			Node() :next(NULL), data(NULL) {}
		};

		typedef struct Node* NodePtr;

	public:
		Stack() : m_head(NULL), m_tail(NULL), m_size(0){}
		void push(void * data);
		void pop();
		void*& top();
		unsigned int size() { return m_size; }
		void erase();
		void print();
	private:
		NodePtr m_head;
		NodePtr m_tail;
		unsigned int m_size;
	};

	//bool remove(Element* elem);

	//bool insertAfter(Element *elem, int data);

	//bool GetMthToLastElement(int m, Element * head, Element * elem);

}

#endif
