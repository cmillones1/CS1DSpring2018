#ifndef QUEUE_H_
#define QUEUE_H_

/*
 * Class Queue Will extend DEQUE<E>
 */
template <class E>
class Queue: public Deque<E>{
public:

	Queue();            // Constructor
	virtual ~Queue();   // Destructor

	int size() const;   // Outputs size of Queue
	bool empty() const; // Outputs if Queue is empty or not.
	void front() const; // Output Front of Queue
	void enqueue(E data);				  // Inserts back of Queue
	void dequeue();               // Removes front of queue



	void Print() const;  // Print Queue
	void InisiateQueue(string &fName); // Initiate Queue


	//	void Back() const;  // Outputs back of Queue

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

// outputs the size of the queue
template <class E>
int Queue<E>::size() const
{
	return myQueue->size();
}

// outputs if the queue is empty
template <class E>
bool Queue<E>::empty() const
{
	return myQueue->empty()?true:false;
}

// outputs the front of queue
template <class E>
void Queue<E>::front () const
{
	return myQueue->front();
}

// Inserts in the back of Qeueue
template <class E>
void Queue<E>::enqueue(E data)
{
	myQueue->insertBack(data);
}


// Removes the front of the Qeueue
template <class E>
void Queue<E>::dequeue()
{
	myQueue->eraseFront();
}

// Initializes the queue
template <class E>
void Queue<E> :: InisiateQueue(string & fName)
{
	myQueue->InitiateDeque(fName);
}

template <class E>
void Queue<E> :: Print() const
{
	myQueue->Print();
}


#endif /* QUEUE_H_ */
