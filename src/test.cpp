#include <iostream>
#include <list>
#include <string>

#include "linkedlist.h"
#include "binary_tree.h"
#include "number_utils.h"
#include "stringfunctions.h"
//#include "IndustryClassifications.h"
#include "sort.h"
#include "misc.h"
#include "stack.h"

void compareDoublesTest();
void printDoubleResult(bool result);
void testBinaryTree();
void testLargestCommonStr();

void testStack();
void testSortinglist();
void testSort();
void testStrings();
void testFizzBuzz();
void testLinkedList();


#define PLUS1(a) ((a) + 1)

using std::cout;

void main()
{
	char pause = {0};

	//compareDoublesTest();
	//testStack();

	//testSortinglist();

	//testBinaryTree();
	//testLargestCommonStr();

	//testSort();
	//testStrings();
	//testFizzBuzz();
	testLinkedList();

	bool even = sd::evenDivide(10, 5);
	
	cout<<"Press Any key to exit"<<std::endl;
	std::cin.get(&pause, 1);
	return;
}

void testFizzBuzz()
{
	sd::number_utils test;
	test.printFizzBuzz();
}

void testSort()
{
	int test[] = {1,12,5,26,7,14,3,7,2};
	int size = sizeof(test) / sizeof(test[0]);
	sd::printArray(test,0, size);
	sd::QuickSort(test, 0, size-1);
	//sd::printArray(test, 0, size);
}

/*
void testIndustryTaxonomy()
{
	try
	{
		sd::readInput();
		sd::printClassification();
		sd::findCompanies("Health Care", "CompanyName");
		sd::findCompanies("Large Pharmaceuticals", "MarketCap");
		sd::findCompanies("Aerospace & Defense", "IndustryRevenue");
		sd::findCompanies("Early Commercial Biotech", "CompanyName");
		sd::findIndustries("Gemvax & Kael");
	}
	catch(std::bad_alloc& exc)
	{
	  cout<<"Exception: std::bad_alloc"<<std::endl;
	}
}*/

void testBinaryTree()
{
	sd::BTNode<int> * bt = NULL;
	sd::GenNodeBinaryTree<int>(&bt,0);
	sd::BreadthFirstTraversal(bt);
	cout<<std::endl;
	sd::GenNodeBinaryTree<int>(&bt,1);
	sd::BreadthFirstTraversal(bt);
	cout<<std::endl;
	sd::GenNodeBinaryTree<int>(&bt,2);
	sd::BreadthFirstTraversal(bt);
	cout<<std::endl;
	sd::GenNodeBinaryTree<int>(&bt,3);
	sd::BreadthFirstTraversal(bt);
	cout<<std::endl;
	sd::GenNodeBinaryTree<int>(&bt);
	sd::BreadthFirstTraversal(bt);
	cout <<"Depth first"<< std::endl;
	sd::BreadthFirstTraversal(bt);
}

void testLargestCommonStr()
{
		std::string a = "cancabc";
		std::string b = "cabcan";
		std::string result;

		result = sd::longestCommonStr(a,b);
		cout<<result;
}

void compareDoublesTest()
{
	bool result = false;
	
	result = sd::number_utils::compare(3.502, 3.504, .0001);

	printDoubleResult(result);

	result = sd::number_utils::compare(3.50127, 3.50121, .0001);

	printDoubleResult(result);
}

void printDoubleResult(bool result)
{
	if(false == result)
	{
		cout<<"Doubles are NOT equal"<<std::endl;
	}
	else
	{
		cout<<"Doubles are equal"<<std::endl;
	}
}

void testLinkedList()
{
	int elements[10] = { 10, 9, 8, 7, 16, 5, 3, 3, 12, 1 };
	int elements2[9] = {1, 12, 3, 3, 5, 16, 7, 8, 9};
	//int elements[2] = {2,1};
	void * data;
	int arraySize = sizeof(elements) / sizeof(int);
	int arraySize2 = sizeof(elements2) / sizeof(int);
	sd::LinkedList ll, ll2;

	for (int i = 0; i < arraySize; i++)
	{
		ll.push_back((void *)elements[i]);
	}

	cout << "Linked List Created: ";
	ll.print();
	cout << std::endl;

	for (int i = 0; i < arraySize2; i++)
	{
		ll2.push_back((void *)elements2[i]);
	}

	cout << "Linked List Created: ";
	ll2.print();
	cout << std::endl;

	ll = ll2;
	cout << "L replaced with LL2: ";
	ll.print();
	cout << std::endl;

	/*
	sd::NodePtr elemToRemove = new sd::Element(); 
	elemToRemove->data = (void *)9;

	for (int k = 6; k < 10; k++)
	{
		if (!sd::insertAfter(0, elements[k])) cout << "error insertAfter" << std::endl;
	}

	cout << "printStack returned:" << (bool)sd::printStack(myStack) << std::endl;

	sd::GetMthToLastElement(1, myStack, elemToRemove);

	cout << "remove returned:" << remove(elemToRemove) << std::endl;

	cout << "printStack returned:" << (bool)sd::printStack(myStack) << std::endl;

	sd::ReverseM(&myStack);

	cout << "reversem printStack returned:" << (bool)sd::printStack(myStack) << std::endl;

	sd::ReverseT(&myStack);

	cout << "reverset printStack returned:" << (bool)sd::printStack(myStack) << std::endl;

	sd::Sort(&myStack);

	cout << "sorted printStack returned:" << (bool)sd::printStack(myStack) << std::endl;

	sd::pop(&myStack, &data);

	cout << "printStack returned:" << (bool)sd::printStack(myStack) << std::endl;

	sd::Element tempElem;
	tempElem.data = (void*)16;
	sd::SortedInsert(&myStack, &tempElem);

	cout << "sorted insert printStack returned:" << (bool)sd::printStack(myStack) << std::endl;

	sd::ReverseT(&myStack);

	cout << "reverset printStack returned:" << (bool)sd::printStack(myStack) << std::endl;

	cout << "deleteStack returned:" << (bool)sd::deleteStack(&myStack) << std::endl;

	cout << "printStack returned:" << (bool)sd::printStack(myStack) << std::endl;
	*/
}

void testStack()
{
	int elements[10] = { 10, 9, 8, 7, 16, 5, 3, 3, 12, 1 };
	//int elements[1] = {1};
	//int elements[2] = {2,1};
	void * data;
	int arraySize = sizeof(elements) / sizeof(int);
	sd::Stack s;

	for (int i = 0; i < arraySize; i++)
	{
		s.push((void *)elements[i]);
	}

	cout << "Stack Created: ";
	s.print();
	cout << std::endl;

	data = s.top();
	cout << "Stack top is now: " << (int)data << std::endl;

	for (int j = 0; j < 4; j++)
	{
		s.pop();
	}
	cout << "Stack after being popped 4 times: ";
	s.print();

	data = s.top();
	cout << "Stack top is now: " << (int)data << std::endl;

	s.erase();

	cout << "Stack erased: ";
	s.print();

	data = s.top();
	cout << "Stack top is now: " << (int)data << std::endl;
}

void testStrings()
{  

    char hello[] = "HELLOOH";
    sd::ReverseString(hello, sizeof(hello)-1);

    cout<< "HELL reversed = "<< hello <<std::endl;

    cout<< "unique:"<<sd::UniqueElements(hello,sizeof(hello)-1)<<std::endl;
	
	cout << "Num of substrings:" << sd::substringCaculator(std::string("kincenvizh")) << std::endl;
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
		cout << "test0:" << *it<< std::endl;
	}

	// Sort the std::list
	test1.sort();

	// Dump the std::list to check the result
	for (it = test1.begin();
		 it != test1.end(); ++it)
	{
		cout << "test1:" << *it<< std::endl;
	}

}