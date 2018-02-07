/*
 * Deque.h
 *
 *  Created on: Feb 3, 2018
 *      Author: Chris
 */

#ifndef DEQUE_H_
#define DEQUE_H_

#include "header.h"

/*
 * depending on how u treat the deaque.
 * it can be a LIFO or FIFO.
 */
template <class E>
class Deque {

private:
	// built to handle doubly linked list
	struct Node
	{
		E data;      // holds data - type E
		Node* next;  // Pointer of the next node
		Node* prev;  // pointer of previous node
	};

	int size;		// hold size of the list
	Node* head;		// Holds the head of the deque
	Node* tail;	    // holds the tail of the deque

public:
		Deque();			// Contstructor
		virtual ~Deque();   // Destructor

		virtual void Insert_Back(Node *node);  //Insert the back of deque
		virtual void Insert_Front(Node *&node); // instert the fron of deque

		virtual void Remove_Back();  // remove the back of deque
		virtual void Remove_Front(); // remove the front of deque

		virtual void Print()const; // print the deque

		virtual bool IsEmpty()const;  // checks if deque is empty
		virtual int Size()const;     // outputs the size of deque
		virtual void Front()const;   // outputs the front of deque
		virtual void  Back()const;   // outputs the back of deque

		void InitiateDeque(string &Fname); // Instialize the deque with a file
};

// Cosntructor
template<typename E>
Deque<E>::Deque()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

// Destructor
template<typename E>
Deque<E>::~Deque()
{
	// TODO Auto-generated destructor stub
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
	size++;
}

//Insert the back of a queue
// Then move head back one to the new node
template<typename E>
void Deque<E>::Insert_Back(Node *node)
{
	node->next = NULL;
	node->prev = NULL;

	if(head == NULL) {
		head = node;
		tail = node;
	} else {
		node -> next = head;
		head -> prev = node;
		head = node;
	}
	size++;
}
//REmoves the back of the deque.
// Then moves tail to the previous spot
template<typename E>
void Deque<E>::Remove_Back()
{
	Node *temp = NULL;

	temp = tail;
	cout << "\tPOPPING: " << temp->data << endl;

	tail = tail->next;
	tail->prev = NULL;
	temp->next = NULL;
	temp->prev = NULL;
	delete(temp);
}
// Removes the front of the deque
// then move head to the next
template<typename E>
void Deque<E>::Remove_Front()
{
	Node *temp = NULL;

	temp = head;
	cout << "POPPING: " << temp->data << endl;

	head = head->prev;
	head->next = NULL;
	temp->next = NULL;
	temp->prev = NULL;

	delete(temp);
}

// Will print the deque
template<typename E>
void Deque<E>::Print()const
{
	Node *temp = head;
	int index = 1;
	if(IsEmpty()) {
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

// Displays if deque is empty
template<typename E>
bool Deque<E>::IsEmpty()const
{
	if(head == NULL) {
		return true;
	} else {
		return false;
	}
}

// Display the size of deque
template<typename E>
int Deque<E>::Size()const
{
	return size;
}

// Displays the front of deque
template<typename E>
void Deque<E>::Front()const
{
	cout << "[FRONT]  " << head->data << endl;
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

#endif /* DEQUE_H_ */
