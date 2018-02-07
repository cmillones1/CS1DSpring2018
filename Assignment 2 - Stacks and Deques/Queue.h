/*
 * Queue.h
 *
 *  Created on: Feb 3, 2018
 *      Author: Chris
 */
#ifndef QUEUE_H_
#define QUEUE_H_
#include "Deque.h"

template<class E>
class Queue : private Deque<E>{
public:

	Queue();            // Constructor
	virtual ~Queue();   // Destructor

	void Back() const;  // Outputs back of Queue
	void Front() const; // Output Front of Queue
	int Size() const;   // Outputs size of Queue
	bool IsEmpty() const; // Outputs if Queue is empty or not.

	void Print() const;  // Print Queue

	void InisiateQueue(string &fName); // Initiate Queue
	void Remove_Front();               // Removes front of queue
	void Insert_Back();				   // Removes back of Queue

private:
	Deque<E> *myQueue;  // pointer of Deque but will be used as a queue

};

// Constructor
template <class E>
Queue<E>::Queue()
{
	myQueue = new Deque<E>;
}

// Descturctor
template <class E>
Queue<E>::~Queue()
{
	delete (myQueue);
}

// Outputs the back of queue
template <class E>
void Queue<E>::Back() const
{
	return myQueue->Back();
}

// outputs the front of queue
template <class E>
void Queue<E>::Front () const
{
	return myQueue->Front();
}

// outputs the size of the queue
template <class E>
int Queue<E>::Size() const
{
	return myQueue->Size();
}

// outputs if the queue is empty
template <class E>
bool Queue<E>::IsEmpty() const
{
	return myQueue->IsEmpty()?true:false;
}

template <class E>
void Queue<E> :: Print() const
{
	myQueue->Print();
}

// Initializes the queue
template <class E>
void Queue<E> :: InisiateQueue(string & fName)
{
	myQueue->InitiateDeque(fName);
}

// Removes the front of the Qeueue
template <class E>
void Queue<E>::Remove_Front()
{
	myQueue->Remove_Front();
}

// Inserts in the back of Qeueue
template <class E>
void Queue<E>::Insert_Back()
{
	myQueue->Insert_Back();
}

#endif /* QUEUE_H_ */
