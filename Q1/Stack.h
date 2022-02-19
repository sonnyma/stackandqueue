/* 
 * Stack.h
 *
 * Description: Implementation of an int sequence with push/pop ...
 * Class Invariant: ... in a LIFO order
 *
 * Author: Sonny Ma
 * Date: Feb 17 2022
 */
 
class Stack {

    private:

        // Description:  Nodes for a singly-linked list
        class StackNode {
            public:
                int data;
                StackNode * next;
        };
        

        // Description:  head = ptr to the first StackNode (NULL if empty)
        //               tail = ptr to the last StackNode (NULL if empty)
        // Class Invariant:  Follows Assignment 2 requirements, namely that the implementation 
        //                   is a singly-linked list, with insert/remove 
        //                   operations at the list's tail.
        StackNode * head;
        StackNode * tail;

    public:

        // Description:  Constructor
        // Postcondition:  Stack is empty
        Stack();
        Stack(int _data);


        // Description:  Destructor
        // Postcondition: End of StkTest or called on
        ~Stack();


        // Description:  Insert element x to the top of the stack.
        // Postcondition: If stack is empty, makes head and tail the input. Otherwise, find tail, link the tail to the input, and reset tail
        void push(int x);


        // Description:  Remove and return element at the top of the stack.
        // Precondition: Stack cannot be empty 
        // Postcondition: If one element is in stack, delete head and tail and return element. Otherwise, find element before tail, reset tail to that element, and delete old tail
        int pop();


        // Description:  Return the topmost element of the stack.
        // Precondition: The stack cannot be empty
        // Postcondition: Returns the tail's element  
        int peek() const;


        // Description: Checks if stack is empty
        // Postcondition: If it's empty, return 1. Otherwies, return 0
        bool isEmpty() const;


        // Description: Destructor
        // Postcondition: Deletes the stack
        void recursiveDestructor(StackNode * current);


};