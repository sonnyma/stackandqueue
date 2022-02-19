/*
 * Stack.cpp
 *
 * Description: Implementation of an int sequence with push/pop ...
 * Class Invariant: ... in a LIFO order
 *
 * Author: Sonny Ma
 * Date: Feb 17 2022
 */

#include <cstddef> // For NULL
#include <iostream>
#include "Stack.h"

using namespace std;

// Description:  Constructor
// Postcondition:  Stack is empty
Stack::Stack()
{
    head = nullptr;
    tail = nullptr;
}

// Description:  Destructor
// Postcondition: End of StkTest or called on
Stack::~Stack()
{
    recursiveDestructor(head);
}

// Description:  Insert element x to the top of the stack.
// Postcondition: If stack is empty, makes head and tail the input. Otherwise, find tail, link the tail to the input, and reset tail
void Stack::push(int x)
{
    if (head == NULL)
    {
        head = new StackNode;
        tail = head;
        head->data = x;
    }
    else
    {
        StackNode * current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = new StackNode;
        (current->next)->data = x;
        current = current->next;
        tail = current;
    }
}

// Description:  Remove and return element at the top of the stack.
// Precondition: Stack cannot be empty 
// Postcondition: If one element is in stack, delete head and tail and return element. Otherwise, find element before tail, reset tail to that element, and delete old tail
int Stack::pop()
{
    if (head == nullptr)
    {
        throw "This stack is empty";
    }
    else if (head == tail)
    {
        int temp = head->data;
        delete head;
        head = nullptr;
        tail = nullptr;
        return temp;
    }
    else
    {
        StackNode * current = head;
        StackNode * previous = current;
        while (current->next != nullptr)
        {
            previous = current;
            current = current->next;
        }
        int temp = tail->data;
        delete tail;
        tail = previous;
        tail->next = nullptr;
        return temp;
    }
}

// Description:  Return the topmost element of the stack.
// Precondition: The stack cannot be empty
// Postcondition: Returns the tail's element
int Stack::peek() const
{
    if (head == nullptr)
    {
        throw "The stack is empty.";
    }
    else
    {
        return tail->data;
    }
}

// Description: Checks if stack is empty
// Postcondition: If it's empty, return 1. Otherwies, return 0
bool Stack::isEmpty() const
{
    if (head == nullptr)
    {
        return 1;
    }
    else
    {
        return 0;
    };
}

// Description: Destructor
// Postcondition: Deletes the stack
void Stack::recursiveDestructor(StackNode * current)
{
    if (current != nullptr)
    {
        recursiveDestructor(current->next);
        delete current;
    }
}