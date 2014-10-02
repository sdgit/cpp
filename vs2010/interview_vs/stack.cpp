#include "stack.h"

using namespace std;

Element * head = 0;
Element * tail = 0;

bool push(Element **stack, void * data)
{
    Element* elem = new(std::nothrow) Element;

    if(!elem) return (false);

    elem->next = *stack;
    elem->data = data;

    if(!elem->next) tail = elem;

    *stack = elem;
    head = elem;

    return (true);
}

bool pop(Element **stack, void ** data)
{
    Element* elem = *stack;

    if(!elem) return (false);

    *data = elem->data;
    *stack = elem->next;

    head = *stack;

    if(!head) tail = head;

    delete elem;

    return (true);
}

bool createStack(Element** stack)
{
    stack = 0;
    return true;
}

bool deleteStack(Element** stack)
{
    Element * next;
    while(*stack != NULL)
    {
        next = (*stack)->next;
        std::cout<<"deleting ..."<<(int)(*stack)->data<<std::endl;
        delete *stack;
        *stack = next;

    }
    return true;
}

bool remove(Element* elem)
{
    Element *currPos = head;
    if(!elem) return (false);

    if(head == elem)
    {
        head = elem->next;
        std::cout<<"removing ..."<<(int)elem->data<<std::endl;
        delete elem;

        if(!head) tail = 0;

        return (true);
    }

    while(currPos)
    {
        if(currPos->next == elem)
        {
            currPos->next = elem->next;
            std::cout<<"removing ..."<<(int)elem->data<<std::endl;
            delete elem;
            return (true);
        }
        currPos = currPos->next;
    }

    return (false);

}

bool insertAfter(Element *elem, int data)
{
    Element *currPos = head;
    Element *newElem = new Element;

    if(!newElem) return (false);

    newElem->data = (void *) data;

    if(!elem)
    {
        newElem->next = head;
        head = newElem;
        std::cout<<"inserting:"<<(int)newElem->data<<" before head"<<std::endl;
        if(!newElem->next)
            tail = newElem;
        return (true);
    }

    while(currPos)
    {
        if(currPos == elem)
        {
            if(!currPos->next)
                tail = newElem;
            newElem->next = currPos->next;
            currPos->next = newElem;
            std::cout<<"inserting:"<<(int)newElem->data<<" after:"<<(int)currPos->data<<std::endl;
            return (true);
        }
        currPos = currPos->next;
    }
    delete newElem;
    return (false);
}

bool GetMthToLastElement(int m, Element * head, Element * elem)
{
    Element *currPos = head;
    int numPositions = 0;
    int posDesired = 0;

    if(!head) //empty list
    {
        elem = 0;
        return (false);
    }

    //count how many positions there are
    while(currPos)
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

    while(currPos)
    {
        if(numPositions == posDesired)
        {
            elem = currPos;
            return (true);
        }

        numPositions++;
        currPos = currPos->next;
    }
}



