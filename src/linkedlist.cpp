#include "linkedlist.h"

namespace sd {

	void LinkedList::push_back(void * data)
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
			m_tail = elem;
		}
		++m_size;
	}

	void LinkedList::pop_back()
	{

	}

	void LinkedList::pop_front()
	{
		if (NULL != m_head)
		{
			NodePtr next = m_head->next;
			delete m_head;
			m_head = next;
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


	void LinkedList::reverse()
	{

		NodePtr curr = m_head;
		NodePtr next = NULL;
		NodePtr prev = NULL;

		m_tail = curr;

		for (int i = 0; i < m_size; i++)
		{
			
			next = curr->next;
			curr->next = prev;
			prev = curr;

		}

		m_head = prev;

	}


	/*
	//memory hog, but big O (2N)
	bool LinkedList::ReverseM(NodePtr* head)
	{
	if(!*head)
	{
	return false;
	}

	NodePtr currPos = *head;
	NodePtr temp, previous;

	temp = new Element;
	temp->data = currPos->data;
	temp->next = NULL;

	previous = currPos;
	currPos = currPos->next;
	delete previous;
	previous = temp;

	while( currPos != NULL)
	{
	temp = new Element;
	temp->data = currPos->data;
	temp->next = previous;

	previous = currPos;
	currPos = currPos->next;
	delete previous;
	previous = temp;
	}

	*head = temp;

	return (true);
	}
	
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