#include <iostream>

bool ReverseString(char * theString, int size);

int UniqueElements(char * array, int size);

struct node {
    void * data;
    struct node* left;
    struct node* right;
	node():left(NULL), right(NULL), data(0){}
	node(int val):left(NULL), right(NULL), data((void *)val){}
} ;

void BreadthFirstTraversal(node * top);

node * GenNodeBinaryTree(int size = 100);