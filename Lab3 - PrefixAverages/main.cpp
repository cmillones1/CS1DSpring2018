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
vector<int> prefixAverages1(vector<int> X); //Quadratic
vector<int> prefixAverages2(vector<int> X); //Linear
int main()
{
	vector<int> prefixAvg; // Will hold the prefixaverages
	clock_t start;
	clock_t end;

	for(int i = 1; i<= 100000; i++)
		prefixAvg.push_back(i);

	start = clock();
	prefixAvg = prefixAverages1(prefixAvg);
	end = clock() - start;
	cout << start << "  " << end << endl;
	cout << "It took " << (((double)(end - start)) /(CLOCKS_PER_SEC)*1000000);


	return 0;
}
vector<int> prefixAverages1(vector<int> X) //Quadratic
{
	vector<int> A;
	int a;
	for(int i = 0; i<X.size(); i++)
	{
		a = 0;
		for(int j = 0; j <= i; j++)
		{
			a += X[j];
		}
		A.push_back(a/(i+1));
	}
	return A;
}
vector<int> prefixAverages2(vector<int> X) // Linear
{
	vector<int> A;
	int s = 0;
	for(int i = 0; i<X.size(); i++)
	{
		s += X[i];
		A.push_back(s/(i+1));
	}
	return A;
}




















































