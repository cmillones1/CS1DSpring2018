#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "header.h"

template<class E>
class StackLinkedList {
public:
	StackLinkedList(); // Constructor
	~StackLinkedList(); // Destructor

	bool empty() const; // Checks if stack is empty
	int size() const; // Checks the size of the stack
	E top() const; // outputs the top of the stack
	void pop(); // deletes the top of the stack
	void push(E data); // Allocate stack with data
	void printStack() const; // Prints the stack in a desired output

	void InitializeStack(string& fileName); // Initializes the stack with file

private:
	struct Node
	{
		E data;		// hold data
		Node* next; // connect nodes

	};
	Node* head; // head of the link
	int count; // counter for size
};

//Constructor
template<class E>
StackLinkedList<E>::StackLinkedList()
{
	head = NULL;
	count = 0;
}

//Destruct the variables
template<class E>
StackLinkedList<E>::~StackLinkedList()
{
	head = NULL;
	count = 0;
}

//Output true or false depending if the stack or list is empty
template<class E>
bool StackLinkedList<E>::empty() const
{
	return count==0? true:false;
}
//Output the current size of the stack/list
template<class E>
int StackLinkedList<E>::size() const
{
	return count;
}
//Output the head or top of the stack
template<class E>
E StackLinkedList<E>::top() const
{
	return head->data;
}
//Deletes the top of the stack/list
template<class E>
void StackLinkedList<E>::pop()
{
	Node* temp = NULL;  // Temporary node to hold data(attached to list)

	if(head == NULL)
	{
		cout << "\tERROR: Stack is empty!";
	}
	else
	{
		count--;
		temp = head;
		head = head->next;
		temp = NULL;
		delete(temp);
	}
}

template<class E>
void StackLinkedList<E>::push(E data)
{
	Node*temp = new Node;
	temp->data = data;
	temp->next = NULL;

	if(head==NULL)
	{
		count++;
		head = temp;
	}
	else
	{
		count++;
		temp->next = head;
		head = temp;
		temp = NULL;
		delete(temp);
	}

}
//Initialize the stack/list using a file type system
template<class E>
void StackLinkedList<E>::InitializeStack(string& fileName)
{
	Node* temp = NULL;  // Temporary node to hold data(attached to list)
	E data;			  // variable to hold data - type E
	ifstream inFile; // File stream

	inFile.open(fileName.c_str()); //open file

	while(!inFile.eof())
	{
		temp = new Node;
		inFile >> data;
		temp->data = data;
		temp->next = NULL;
		count++;

		if(head == NULL)
		{
			head = temp;
		}
		else
		{
			temp->next = head;
			head = temp;
		}
	}
}

//Print the list/stack of the system.
template<class E>
void StackLinkedList<E>::printStack() const
{
	Node* temp = head;
	int index = 1;
	if(empty())
	{
		cout << "ERROR: Stack is empty!";
	}
	else
	{
		while(temp!= NULL)
		{
			cout << "Element [" << index << "] " << temp->data << endl;
			temp = temp->next;
			index++;
		}
	}
}
#endif /* LINKEDLIST_H_ */
