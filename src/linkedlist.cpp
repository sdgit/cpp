#include "linkedlist.h"
#include <algorithm>
using std::cout;

namespace sd {

	void LinkedList::push_back(void *const& data)
	{
		NodePtr elem = new Node();
		elem->next = NULL;
		elem->data = data;

		if (0 == m_size)
		{
			m_head = elem;
		}
		else
		{
			m_tail->next = elem;
		}
		m_tail = elem;
		++m_size;
	}

	void LinkedList::push_front(void *const& data)
	{
		NodePtr elem = new Node();
		elem->next = NULL;
		elem->data = data;

		if (0 != m_size)
		{
			elem->next = m_head;
		}

		m_head = elem;
		++m_size;
	}

	void LinkedList::pop_back()
	{
		if (NULL != m_tail)
		{
			NodePtr next = m_head;
			//get node before m_tail
			for (unsigned int i = 0; i < m_size-1; i++)
			{
				next = next->next;
			}
			
			delete m_tail;
			m_tail = next;
			--m_size;
		}

	}

	void LinkedList::pop_front()
	{
		if (NULL != m_head)
		{
			NodePtr next = m_head->next;
			delete m_head;
			m_head = next;
			--m_size;
		}

	}

	void*& LinkedList::back()
	{
		return m_tail->data;
	}

	void*& LinkedList::front()
	{
		return m_head->data;
	}

	void LinkedList::remove(void *const & val)
	{
		NodePtr curr = m_head;
		NodePtr prev = m_head;
		NodePtr next = NULL;
		while (curr != NULL)
		{
			next = curr->next;
			if (curr->data == val)
			{
				if (curr == m_head)
				{
					m_head = next;
				}
				if (curr == m_tail)
				{
					m_tail = prev;
				}
				prev->next = next;
				delete curr;
				--m_size;
			}
			else
			{//dont update prev if we delete
				prev = curr;
			}
			curr = next;
		}
	}

	void LinkedList::reverse()
	{
		NodePtr next = NULL;
		NodePtr prev = NULL;
		NodePtr curr = NULL;

		m_tail = m_head;
		curr = m_head;

		while (curr != NULL)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}

		m_head = prev;

	}

	void LinkedList::clear()
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
	LinkedList::LinkedList(const LinkedList& rhs)
	{
		const Node* src = rhs.m_head;
		while (src)
		{
			push_back(src->data);
			src = src->next;           // advance source
		}
	}

	LinkedList::~LinkedList()
	{
		clear();
	}

	LinkedList& LinkedList::operator=(const LinkedList& rhs)
	{
		LinkedList temp(rhs);
		std::swap(m_head, temp.m_head);
		std::swap(m_tail, temp.m_tail);
		std::swap(m_size, temp.m_size);

		return *this;
	}

	void LinkedList::print() const
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

	void LinkedList::resize(unsigned int size, void * data) 
	{
		while (size > m_size)
		{
			push_back(data);
		}

		while (size < m_size)
		{
			pop_back();

		}

	}

	/*
	
	bool Sort(LinkedList::NodePtr* head)
	{
		int tempData = 0;
		Element *currPos = *head;
		Element *temp = NULL;
		Element *lowest = NULL;

		if(!currPos)
		{
			return false;
		}

		while (currPos != NULL)
		{
			temp = currPos->next;
			lowest = currPos;

			while(temp != NULL)
			{
				if(temp->data < lowest->data)
				{
					lowest = temp;
				}
				temp = temp->next;
			}

			tempData = (int)lowest->data;
			lowest->data = currPos->data;
			currPos->data = (void*)tempData;
			currPos = currPos->next;

		}

		return(true);
	}

	//needs to be reduced and simplified
	//also adding to tail gives error
	bool LinkedList::SortedInsert(NodePtr*head, Element * data)
	{
		Element * currPos = *head;
		Element * prev = currPos;
		if(*head == NULL || data == NULL)
		{
			return false;
		}

		if(currPos->next == NULL)
		{
			//insert to tail
			if(currPos->data >= data->data)
			{
			   currPos->next = data;
			   data->next = NULL;
			}
			else //insert head
			{
				data->next = currPos;
				*head = data;
			}

			return true;
		}

		while(currPos->data < data->data)
		{
		  prev = currPos;
		  currPos = currPos->next;
		}

		if(currPos == prev)
		{
		   if(*head == currPos)
		   {
				data->next = currPos;
				*head = data;
		   }
		   else
		   {
			   currPos->next = data;
			   data->next = NULL;
		   }
		}
		else
		{
			prev->next = data;
			data->next = currPos;
		}

		return (true);
	}*/
}
