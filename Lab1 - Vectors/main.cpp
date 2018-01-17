/*************************************************************************
 * AUTHOR(S)	 : Chris Millones & ------
 * STUDENT IDS   : 361396 & --------
 * Lab #		 : ------
 * CLASS         : CS1D
 * SECTION       : Mondays & Wednesday: 3:00 - 6:20PM
 * DUE DATE    	 : -------
 ************************************************************************/

/*************************************************************************
 * Vectors
 * _______________________________________________________________________
 *
 *
 *
 ************************************************************************/

#include "header.h"

const void PRINTAUTHOR() {

	cout << left;
	cout << "********************************************************\n";
	cout << setw(10) << "AUTHOR: " << "Christopher Millones\n";
	cout << setw(10) << "Lab #1:  Vectors\n";
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
	vector<int> randomNumbers; //Will hold 20 random three digit integers

	 srand (time(NULL));
	for(int i = 0; i<= 20; i++)
	{
		cout << rand()%899 + 100  << endl;
	}

	return 0;
}






























