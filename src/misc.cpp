#include "misc.h"
#include <queue>
#include "time.h"

bool ReverseString(char theString[], int size)
{
  char * currPos = theString;
  char * end = &theString[size-1];
  char temp = 0;

  if(theString == NULL || size < 1)
  {
      return false;
  }

  while(currPos != end)
  {
     temp = *currPos;
     *currPos = *end;
     *end = temp;

     currPos++;

     if(currPos == end)
     {
         break;
     }
     end--;
  }

  return 0; //change this or review!
}

int UniqueElements(char * array, int size)
{
    int found = 0;
    bool uniqueFlag = false;
    char *unique = new char[size];

    if(array == NULL || size < 1)
    {
        return -1;
    }

    for( int i = 0; i < size; i++ )
    {
        uniqueFlag = true;

        for(int j =0; j <found; j++)
        {
            if(array[i] == unique[j])
            {
                //not unique
                uniqueFlag = false;
                continue;
            }
        }

        if(uniqueFlag == true)
        {
            unique[found] = array[i];
            found++;
        }

    }

    delete [] unique;
    return found;


}

void BreadthFirstTraversal(node * top)
{
	std::queue<node*> q;

	if(!top)
		return;

	node* s = top;
	q.push(s);

	while(!q.empty())
	{
		s = q.front();
		q.pop();
		std::cout<<(int)s->data<<std::endl;
		if(s->left)
			q.push(s->left);
		if(s->right)
		q.push(s->right);
	}



}

node * GenNodeBinaryTree(int size)
{
	if (size <= 0)
		return NULL;

	srand (time(NULL));
	std::queue<node *> q;
	node * root = new node(rand());
	q.push(root);
	node * curr;


	for (int i = 0; i < size; i+=2)
	{
		curr = q.front();
		q.pop();

		if(i >= (size -1))
			break;
		curr->left = new node(rand());
		q.push(curr->left);
		if(i >= (size -2))
			break;
		curr->right = new node(rand());
		q.push(curr->right);
	}
	return root;
}