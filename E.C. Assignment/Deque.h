
#ifndef DEQUEUE_H_
#define DEQUEUE_H_

#include "header.h"

/*
 * depending on how u treat the deaque.
 * it can be a LIFO or FIFO.
 */
template <class E>
class Deque {

private:
	// build to handle doubly linked list
	struct Node
	{
		E data;      // holds data - type E
		Node* next;  // Pointer of the next node
		Node* prev;  // pointer of previous node
	};

	int count;		// hold size of the list
	Node* head;		// Holds the head of the deque
	Node* tail;	    // holds the tail of the deque

public:
		Deque();			// Contstructor
		virtual ~Deque();   // Destructor

		/*
		 * Will be used to implement a Queue interface.
		 */
		virtual int size()const;     // outputs the size of deque
		virtual bool empty()const;  // checks if deque is empty
		virtual void front()const;   // outputs the front of deque
		virtual void insertBack(E data);  //Insert the back of deque
		virtual void eraseFront(); // remove the front of deque



		/*
		 * Testing methods
		 */
		virtual void Remove_Back();  // remove the back of deque
		virtual void Insert_Front(Node *&node); // instert the fron of deque
		virtual void Print()const; // print the deque
		virtual void  Back()const;   // outputs the back of deque
		void InitiateDeque(string &Fname); // Instialize the deque with a file
};

// Cosntructor
template<typename E>
Deque<E>::Deque()
{
	head = NULL;
	tail = NULL;
	count = 0;
}

// Destructor
template<typename E>
Deque<E>::~Deque()
{
	// TODO Auto-generated destructor stub
}

// Display the size of deque
template<typename E>
int Deque<E>::size()const
{
	return count;
}

// Displays if deque is empty
template<typename E>
bool Deque<E>::empty()const
{
	if(count == 0) {
		return true;
	} else {
		return false;
	}
}


// Displays the front of deque
template<typename E>
void Deque<E>::front()const
{
	if(count == 0)
	{
		cout << "\nQueue is empty unable to display [FRONT]\n";
	}
	else
	{
		cout << "[FRONT]  " << tail->data << endl;
	}

}

//Insert the back of a queue
// Then move head back one to the new node
template<typename E>
void Deque<E>::insertBack(E data)
{
	Node* node = new Node;
	node->next = NULL;
	node->prev = NULL;
	node->data = data;

	//cout << "\n\t " << data;
	if(head == NULL) {
		head = node;
		tail = node;
	} else {
		node -> next = head;
		head -> prev = node;
		head = node;
	}
	count++;
	//cout << "\n\t " << count;
}
// Removes the front of the deque
// then move head to the next
template<typename E>
void Deque<E>::eraseFront()
{
	Node *temp = NULL;

	temp = tail;
	cout << "POPPING: " << temp->data << endl;

	if(tail->prev !=  NULL)
	{
		tail = tail->prev;
		tail->next = NULL;
		temp->next = NULL;
		temp->prev = NULL;
	}
	count --;
	delete(temp);
}


// Instert the to front of the Deque
// then moves tail foward one
template<typename E>
void Deque<E>::Insert_Front(Node *&node)
{
	node->next = NULL;
	node->prev = NULL;

	if(head == NULL) {
		head = node;
		tail = node;
	} else {
		node -> next = tail;
		tail -> prev = node;
		tail = node;
	}
	count++;
}


//REmoves the back of the deque.
// Then moves tail to the previous spot
template<typename E>
void Deque<E>::Remove_Back()
{
	Node *temp = NULL;

	temp = head;
	cout << "\tPOPPING: " << temp->data << endl;

	head = head->prev;
	head->next = NULL;
	temp->next = NULL;
	temp->prev = NULL;

	count--;

	delete(temp);

}

// Will print the deque
template<typename E>
void Deque<E>::Print()const
{
	Node *temp = head;
	int index = 1;
	if(empty()) {
		cout << "Empty!\n";
	}
	else
	{
		while(temp != NULL)
		{

			cout << "Element [" << index << "] " << temp->data << endl;
			temp = temp->prev;
			index ++;
		}
	}
}


// Displays the back of deque
template<typename E>
void Deque<E>::Back()const
{
	cout << "[BACK] " << tail->data << endl;
}

//Initializes the queue with a file.
// Will save data into "data" and
// store node into the deque
template<typename E>
void Deque<E>::InitiateDeque(string &Fname)
{
	ifstream inFile;
	E data;
	Node *node;
	inFile.open(Fname.c_str());

	while(!inFile.eof()) {

		node = new Node;
		inFile >> data;
		node->data = data;
		Insert_Front(node);
	}
}



#endif /* DEQUEUE_H_ */
