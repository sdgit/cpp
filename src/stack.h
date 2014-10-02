#ifndef STACK_H
#define STACK_H

#include <iostream>

typedef struct Element
{
    struct Element* next;
    void * data;
    Element():next(NULL), data(0) {}
} Element;


bool push(Element **stack, void * data);

bool createStack(Element** stack);

bool deleteStack(Element** stack);

bool pop(Element **stack, void ** data);

bool remove(Element* elem);

bool insertAfter(Element *elem, int data);

bool GetMthToLastElement(int m, Element * head, Element * elem);

#endif
