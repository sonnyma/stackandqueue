/* 
 * Stack.h
 *
 * Description: Implementation of an int sequence with push/pop ...
 * Class Invariant: ... in a LIFO order
 *
 * Author:
 * Date:
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


        // Description:  
        // Postcondition:  
        ~Stack();


        // Description:  Insert element x to the top of the stack.
        // Postcondition:  
        void push(int x);


        // Description:  Remove and return element at the top of the stack.
        // Precondition:  
        // Postcondition:  
        int pop();


        // Description:  Return the topmost element of the stack.
        // Precondition:  
        // Postcondition:  
        int peek() const;


        // Description:  
        // Postcondition:  
        bool isEmpty() const;
};


