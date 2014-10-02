#include "linkedlist.h"

namespace sd {


	//memory hog, but big O (2N)
	bool ReverseM(Element ** head)
	{
		if(!*head)
		{
			return false;
		}

		struct Element *currPos = *head;
		struct Element * temp, *previous;


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

	bool ReverseT(Element ** head)
	{
		if(!*head)
		{
			return false;
		}

		struct Element *currPos = *head;
		struct Element * temp;
		struct Element swap;
		struct Element * end = NULL;

		while(currPos->next != end)
		{
			temp = currPos->next;
			while(temp->next != end)
			{
			  temp = temp->next;
			}

			if(currPos == temp)
			{
				break;
			}

			end = temp;
			swap.data = temp->data;
			temp->data = currPos->data;
			currPos->data = swap.data;

			if(currPos->next == end)
			{
				break;
			}
			currPos = currPos->next;


		}

		return (true);
	}

	bool Sort(Element** head)
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
	bool SortedInsert(Element **head, Element * data)
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
	}
}