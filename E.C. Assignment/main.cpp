/*************************************************************************
 * AUTHOR(S)	 : Chris Millones
 * STUDENT IDS   : 361396 & --------
 * Assignemnt E.C. : E.C.
 * CLASS         : CS1D
 * SECTION       : Mondays & Wednesday: 3:00 - 6:20PM
 * DUE DATE    	 : -------
 ************************************************************************/

/*************************************************************************
 * E.C. Assignment
 * _______________________________________________________________________
 *"Implement the Queue interface with a class\n"
"that is based on the LinkedDeque and DLinkedList classes (wrapper)\n"
"Test all the member functions (size(), empty(), front(), enqueue, and dequeue)\n"
"of the Queue class with the following data:\n"
"(1)A man a plan, a canal, panama \n(2)Was it a car or a cat I saw? \n(3)Sit on a potato pan,
" Otis \n(4)No lemon, no melon"
 *
 *
 ************************************************************************/

#include "header.h"
#include "Deque.h"
#include "Queue.h"

const void PRINTAUTHOR() {

	cout << left;
	cout << "********************************************************\n";
	cout << setw(10) << "AUTHOR: " << "      Christopher Millones\n";
	cout << setw(10) << "ASSIGNMENT #E.C.:  E.C. Assignment\n";
	cout << setw(10) << "CLASS: " << "      CS1D\n";
	cout << setw(10) << "TIME: " << "      Mondays & Wednesday: 3:00 - 6:20PM\n";
	cout << setw(10) << "DUE DATE: " << "    2/7/18\n";
	cout << "********************************************************\n\n";
}

const void INSTRUCTIONS() {

	cout << left;
	cout << "Implement the Queue interface with a class\n"
			"that is based on the LinkedDeque and DLinkedList classes (wrapper)\n"
			"Test all the member functions (size(), empty(), front(), enqueue, and dequeue)\n"
			"of the Queue class with the following data:\n"
			"(1)A man a plan, a canal, panama \n(2)Was it a car or a cat I saw? \n(3)Sit on a potato pan, Otis \n(4)No lemon, no melon";
}


int main()
{

	Queue<string> *myQ = new Queue<string>; // Queue that wraps extends the deque class
	ifstream inFile; //Open data.txt and have the ability to generate data through files
	string data; // temp varibale to hold data to import into queue

	PRINTAUTHOR(); //Authors information
	INSTRUCTIONS(); // Instructions to Assignment


	inFile.open("Data.txt"); // Open file

	//Will test the size() and empty() at n = 0
	cout << "\n\n\t--Testing Size() and Empty()--\n";
	cout << "Size of Queue: " << myQ->size();
	cout << "\nIs Queue Empty: ";
	if(myQ->empty()){cout << " Yes\n\n";}else{cout << " No\n\n";}

	//Will Enqueue 'data' into queue
	cout << "\t--Testing Enqueue()--\n";
	while(!inFile.eof())
	{
		getline(inFile,data);
		cout << "Enqueue: " << data << endl;
		myQ->enqueue(data);
	}
	//Will test the size() and empty() at n = enqueue entries from above loop
	cout << "\n\t--Testing Size() and Empty()--";
	cout << "\nSize of Queue: " << myQ->size();
	cout << "\nIs Queue Empty: ";
	if(myQ->empty()){cout << " Yes\n\n";}else{cout << " No\n\n";}


	//Test the front of the queue
	cout <<"\t--Testing Front()--\n";
	myQ->front();
	cout << endl;

	//Test Dequeue
	cout << "\t--Testing Dequeue()--\n";
	myQ->dequeue();
	myQ->dequeue();

	//Display front of queue
	cout <<"\n\t--Testing Front()--\n";
	myQ->front();

	//Test Size() and Empty() at n = n-dequeue calls
	cout << "\n\t--Testing Size() and Empty()--";
	cout << "\nSize of Queue: " << myQ->size();
	cout << "\nIs Queue Empty: ";
	if(myQ->empty()){cout << " Yes\n\n";}else{cout << " No\n\n";}

	//Test Dequeue
	cout << "\t--Testing Dequeue()--\n";
	myQ->dequeue();
	myQ->dequeue();

	//Test front (shouldn't be able to or display error msg)
	cout <<"\n\t--Testing Front()--";
	myQ->front();

	//Test Size() and empty() at n = 0. Queue is empty.
	cout << "\n\t--Testing Size() and Empty()--";
	cout << "\nSize of Queue: " << myQ->size();
	cout << "\nIs Queue Empty: ";
	if(myQ->empty()){cout << " Yes\n\n";}else{cout << " No\n\n";}

	inFile.close();

	return 0;
}
