// Trimigno Giuseppe , Computer Engineering at Univeristy of Parma, Italy
// Linked Queue Data Structure, a template class derived from Queue

// This is the file to include in your code if you want access to the
// complete LQueue template class

#ifndef LQUEUE_H
#define LQUEUE_H

#include <string>
using namespace std;

inline void Assert(bool val, string s);

// Include the link class
#include "Link_Class.h"

// First, get the declaration for the base stack class
#include "Queue_BaseClass.h"

// Implementations for linked queue function members
// Linked queue implementation
template <typename E> class LQueue: public Queue<E> {
private:
  Link<E>* front;       // Pointer to front queue node
  Link<E>* rear;        // Pointer to rear queue node
  int size;                // Number of elements in queue

public:
  LQueue()                      // Constructor 
    { front = rear = new Link<E>(); size = 0; }

  ~LQueue() { clear(); delete front; }      // Destructor

  void clear() {                 // Clear queue
	  while (front->next != NULL) { // Delete each link node
		  rear = front;
		  front = front->next;
		  delete rear;
	  }
	  rear = front;
	  size = 0;
  }

  void enqueue(const E& it) { // Put element on rear
    rear->next = new Link<E>(it, NULL);
    rear = rear->next;
    size++;
  }

  E dequeue() {              // Remove element from front
    Assert(size != 0, "Queue is empty");
    E it = front->next->element;  // Store dequeued value
    Link<E>* ltemp = front->next; // Hold dequeued link
    front->next = ltemp->next;       // Advance front
    if (rear == ltemp) rear = front; // Dequeue last element
    delete ltemp;                    // Delete link
    size --;
    return it;                       // Return element value
  }

  const E& frontValue() const { // Get front element
    Assert(size != 0, "Queue is empty");
    return front->next->element;
  }

  virtual int length() const { return size; }
};

#endif