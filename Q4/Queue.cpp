/* 
 * Queue.cpp
 *
 * Description: Implementation of an int sequence with enqueue/dequeue ...
 * Class Invariant: ... in FIFO order
 *
 * Author: Sonny Ma
 * Date: Feb 17 2022
 */
 
#include "Queue.h"


// Description:  Constructor
Queue::Queue() : elementCount(0), capacity(INITIAL_CAPACITY), frontindex(0), backindex(0) {
    elements = new int[INITIAL_CAPACITY];
} 


// Description:  Inserts element x at the back (O(1))
// If queue will be filled, double capacity, create new array, copies old array into new
void Queue::enqueue(int x) {
    elementCount++;
    if ((backindex) == capacity) {
        int backindexvalue;
        capacity = 2 * capacity;
        int * temp = new int[capacity];
        for (int i = frontindex, j = 0; i < backindex; i++, j++) {
            temp[j] = elements[i];
            backindexvalue = j;
        }
        delete elements;
        elements = temp;
        backindex = backindexvalue + 1;
        frontindex = 0;
    }
    elements[backindex] = x;
    backindex = (backindex + 1);
}


// Description:  Removes the frontmost element (O(1))
// Precondition:  Queue not empty
// If there is less elements than 1/4 of capacity, half capacity, create new array, copies old array into new
void Queue::dequeue() {
    elementCount--;
    frontindex = (frontindex + 1);
    if ((elementCount < (capacity / 4)) && (capacity / 2 > INITIAL_CAPACITY)) {   
        int backindexvalue;
        capacity = capacity / 2;
        int * temp = new int[capacity];
        for (int i = frontindex, j = 0; i < backindex; i++, j++) {
            temp[j] = elements[i];
            backindexvalue = j;
        }
        delete elements;
        elements = temp;
        backindex = backindexvalue + 1;
        frontindex = 0;
    }
} 


// Description:  Returns a copy of the frontmost element (O(1))
// Precondition:  Queue not empty
int Queue::peek() const {
    return elements[frontindex];
} 


// Description:  Returns true if and only if queue empty (O(1))
bool Queue::isEmpty() const {
    return elementCount == 0;
}


// Description:  Destructor
Queue::~Queue() {
    delete elements;
}

