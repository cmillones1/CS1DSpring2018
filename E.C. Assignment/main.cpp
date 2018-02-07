/*************************************************************************
 * AUTHOR(S)	 : Chris Millones
 * STUDENT IDS   : 361396 & --------
 * Lab #		 : ------
 * CLASS         : CS1D
 * SECTION       : Mondays & Wednesday: 3:00 - 6:20PM
 * DUE DATE    	 : -------
 ************************************************************************/

/*************************************************************************
 * Lab / Assignment Title.
 * _______________________________________________________________________
 *
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
	cout << setw(10) << "ASSIGNMENT #:  ------\n";
	cout << setw(10) << "CLASS: " << "      CS1D\n";
	cout << setw(10) << "TIME: " << "      Mondays & Wednesday: 3:00 - 6:20PM\n";
	cout << setw(10) << "DUE DATE: " << "      -----\n";
	cout << "********************************************************\n\n";
}

const void INSTRUCTIONS() {

	cout << left;
	cout << "";
}


int main()
{

	Queue<string> *myQ = new Queue<string>;
	ifstream inFile;
	string data;

	inFile.open("Data.txt");

	cout << "\t--Testing Size() and Empty()--\n";
	cout << "Size of Queue: " << myQ->size();
	cout << "\nIs Queue Empty: ";
	if(myQ->empty()){cout << " Yes\n\n";}else{cout << " No\n\n";}

	cout << "\t--Testing Enqueue()--\n";
	while(!inFile.eof())
	{
		getline(inFile,data);
		cout << "Enqueue: " << data << endl;
		myQ->enqueue(data);
	}

	cout << "\n\t--Testing Size() and Empty()--";
	cout << "\nSize of Queue: " << myQ->size();
	cout << "\nIs Queue Empty: ";
	if(myQ->empty()){cout << " Yes\n\n";}else{cout << " No\n\n";}


	cout <<"\t--Testing Front()--\n";
	myQ->front();
	cout << endl;

	cout << "\t--Testing Dequeue()--\n";
	myQ->dequeue();
	myQ->dequeue();

	cout << "\n\t--Testing Size() and Empty()--";
	cout << "\nSize of Queue: " << myQ->size();
	cout << "\nIs Queue Empty: ";
	if(myQ->empty()){cout << " Yes\n\n";}else{cout << " No\n\n";}

	cout << "\t--Testing Dequeue()--\n";
	myQ->dequeue();
	myQ->dequeue();

	cout <<"\n\t--Testing Front()--";
	myQ->front();

	cout << "\n\t--Testing Size() and Empty()--";
	cout << "\nSize of Queue: " << myQ->size();
	cout << "\nIs Queue Empty: ";
	if(myQ->empty()){cout << " Yes\n\n";}else{cout << " No\n\n";}



	return 0;
}
