#include "stack.h"

using std::cout;

namespace sd
{

	void Stack::push(void * data)
	{
		NodePtr node = new Node();

		node->next = m_head;
		node->data = data;
		m_head = node;
	}

	void Stack::pop()
	{
		if (NULL != m_head)
		{
			NodePtr node = m_head;
			m_head = m_head->next;

			delete node;
		}
	}

	void Stack::erase()
	{
		NodePtr curr = m_head;
		NodePtr next = NULL;
		while (curr != NULL)
		{
			next = curr->next;
			std::cout << "deleting :" << (int)curr->data << std::endl;
			delete curr;
			curr = next;
		}
		m_head = NULL;
		m_tail = NULL;
		m_size = 0;
	}

	void Stack::print()
	{
		NodePtr curr = m_head;
		cout << "[";
		while (NULL != curr)
		{
			cout << (int)curr->data;
			curr = curr->next;
			if (NULL != curr)
				cout << ", ";
		}
		cout << "]" << std::endl;
	}

	void *& Stack::top()
	{
		if (NULL == m_head)
			return (new Node())->data; //sd1 bug
		return m_head->data;
	}

	/*
	bool remove(NodePtr elem)
	{
		Element *currPos = head;
		if (!elem) return (false);

		if (head == elem)
		{
			head = elem->next;
			std::cout << "removing ..." << (int)elem->data << std::endl;
			delete elem;

			if (!head) tail = 0;

			return (true);
		}

		while (currPos)
		{
			if (currPos->next == elem)
			{
				currPos->next = elem->next;
				std::cout << "removing ..." << (int)elem->data << std::endl;
				delete elem;
				return (true);
			}
			currPos = currPos->next;
		}

		return (false);

	}

	bool insertAfter(NodePtr elem, int data)
	{
		NodePtr currPos = head;
		NodePtr newElem = new Element;

		if (!newElem) return (false);

		newElem->data = (void *)data;

		if (!elem)
		{
			newElem->next = head;
			head = newElem;
			std::cout << "inserting:" << (int)newElem->data << " before head" << std::endl;
			if (!newElem->next)
				tail = newElem;
			return (true);
		}

		while (currPos)
		{
			if (currPos == elem)
			{
				if (!currPos->next)
					tail = newElem;
				newElem->next = currPos->next;
				currPos->next = newElem;
				std::cout << "inserting:" << (int)newElem->data << " after:" << (int)currPos->data << std::endl;
				return (true);
			}
			currPos = currPos->next;
		}
		delete newElem;
		return (false);
	}
	
	bool GetMthToLastElement(int m, NodePtr head, NodePtr elem)
	{
		NodePtr currPos = head;
		int numPositions = 0;
		int posDesired = 0;

		if (!head) //empty list
		{
			elem = 0;
			return (false);
		}

		//count how many positions there are
		while (currPos)
		{
			numPositions++;
			currPos = currPos->next;
		}

		if (m > numPositions)
		{
			elem = 0;
			return (false);
		}

		posDesired = numPositions - m;

		currPos = head;
		numPositions = 0;

		while (currPos)
		{
			if (numPositions == posDesired)
			{
				elem = currPos;
				return (true);
			}

			numPositions++;
			currPos = currPos->next;
		}
	}*/

}



