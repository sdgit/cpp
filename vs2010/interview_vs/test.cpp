#include "number_utils.h"
#include <iostream>
#include "linkedlist.h"
#include "misc.h"
#include <list>
#include <string>


void compareDoublesTest();
void printDoubleResult(bool result);
void testBinaryTree();

void runStack();
bool printStack(Element *head);
void testSortinglist();

extern Element * head;
extern Element * tail;

#define PLUS1(a) ((a) + 1)

void main()
{
	char pause = {0};

	//compareDoublesTest();
	//runStack();

	//testSortinglist();

	testBinaryTree();
	




	int i = 2;
	int j = 4 * PLUS1(i * 3);
	std::cout<<"J:"<<j<<std::endl;

	
	std::cout<<"Press Any key to exit"<<std::endl;
	std::cin.get(&pause, 1);
	return;
}

void testBinaryTree()
{
	node * bt  = GenNodeBinaryTree(0);
	BreadthFirstTraversal(bt);
	std::cout<<std::endl;
	bt  = GenNodeBinaryTree(1);
	BreadthFirstTraversal(bt);
	std::cout<<std::endl;
	bt  = GenNodeBinaryTree(2);
	BreadthFirstTraversal(bt);
	std::cout<<std::endl;
	bt  = GenNodeBinaryTree(3);
	BreadthFirstTraversal(bt);
	std::cout<<std::endl;
	bt  = GenNodeBinaryTree();
	BreadthFirstTraversal(bt);
}

void compareDoublesTest()
{
	bool result = false;
	
	result = number_utils::compare(3.502, 3.504, .0001);

	printDoubleResult(result);

	result = number_utils::compare(3.50127, 3.50121, .0001);

	printDoubleResult(result);
}

void printDoubleResult(bool result)
{
	if(false == result)
	{
		std::cout<<"Doubles are NOT equal"<<std::endl;
	}
	else
	{
		std::cout<<"Doubles are equal"<<std::endl;
	}
}

void runStack()
{
    int elements[10] = {10,9,8,7,16,5,3,3,12,1};
    //int elements[1] = {1};
    //int elements[2] = {2,1};
    void * data;
    Element *elemToRemove = new Element(); //sd
	elemToRemove->data = (void *)9;

    int arraySize = sizeof(elements)/sizeof(int);
    for (int i = 0; i < arraySize; i++)
    {
        if (!push(&head, (void *)elements[i]))
        {
            std::cout<< "error push"<<std::endl;
        }
        else
        {
            std::cout<<"push("<<elements[i]<<")"<<std::endl;
        }
    }

    std::cout<< "printStack returned:"<<(bool)printStack(head)<<std::endl;

    for (int j = 0; j < 4; j++)
    {
        if (!pop(&head, &data)) std::cout<< "error pop"<<std::endl;

        std::cout<< "pop("<<(int)(data)<<")"<<std::endl;
    }

    std::cout<< "printStack returned:"<<(bool)printStack(head)<<std::endl;

    for (int k = 6; k < 10; k++)
    {
        if (!insertAfter(0, elements[k])) std::cout<< "error insertAfter"<<std::endl;
    }

    std::cout<< "printStack returned:"<<(bool)printStack(head)<<std::endl;

    GetMthToLastElement(1, head, elemToRemove);

    std::cout<< "remove returned:"<<remove(elemToRemove)<<std::endl;

    std::cout<< "printStack returned:"<<(bool)printStack(head)<<std::endl;

    ReverseM(&head);

    std::cout<< "reversem printStack returned:"<<(bool)printStack(head)<<std::endl;

    ReverseT(&head);

    std::cout<< "reverset printStack returned:"<<(bool)printStack(head)<<std::endl;

    Sort(&head);

    std::cout<< "sorted printStack returned:"<<(bool)printStack(head)<<std::endl;

    pop(&head, &data);

    std::cout<< "printStack returned:"<<(bool)printStack(head)<<std::endl;

    Element tempElem;
    tempElem.data = (void*)16;
    SortedInsert(&head, &tempElem);

    std::cout<< "sorted insert printStack returned:"<<(bool)printStack(head)<<std::endl;

    ReverseT(&head);

    std::cout<< "reverset printStack returned:"<<(bool)printStack(head)<<std::endl;

    std::cout<< "deleteStack returned:"<<(bool)deleteStack(&head)<<std::endl;

    std::cout<< "printStack returned:"<<(bool)printStack(head)<<std::endl;

    char hello[] = "HELL";
    ReverseString(hello, sizeof(hello)-1);

    std::cout<< "HELL reversed = "<< hello <<std::endl;

    std::cout<< "unique:"<<UniqueElements(hello,sizeof(hello)-1)<<std::endl;


}

bool printStack(Element *head)
{
    int data;
    #ifndef USE_CLASSES
    Element * elem = head;
    #else
    StackClass::Element * elem = head;
    #endif

    if(!head) return (false);

    while(elem)
    {
        data = (int)(elem->data);
        std::cout<<"("<<data<<")"<<std::endl;
        elem= elem->next;
    }
    return true;
}

void testSortinglist()
{
	std::list<std::string> test0, test1, test2, test3;
	std::list<std::string>::iterator it;

	//no elements
	test0.clear();

	//only one lement
	test1.push_back("one");

	//even number of elements
	test2.push_back("one");
	test2.push_back("two");
	test2.push_back("three");
	test2.push_back("four");

	//off number of elements
	test3.push_back("one");
	test3.push_back("4");
	test3.push_back("three");
	test3.push_back("1");
	test3.push_back("two");
	test3.push_back("3");
	test3.push_back("four");
	test3.push_back("3");
	test3.push_back("five");

	// Sort the std::list
	test0.sort();

	// Dump the std::list to check the result
	for (it = test0.begin();
		 it != test0.end(); ++it)
	{
		std::cout << "test0:" << *it<< std::endl;
	}

	// Sort the std::list
	test1.sort();

	// Dump the std::list to check the result
	for (it = test1.begin();
		 it != test1.end(); ++it)
	{
		std::cout << "test1:" << *it<< std::endl;
	}

}