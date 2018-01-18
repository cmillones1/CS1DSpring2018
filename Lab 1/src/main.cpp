/*************************************************************************
 * AUTHOR(S)	 : Chris Millones & Jose Cardenas
 * STUDENT IDS   : 361396 & 1026944
 * Lab #		 : 1 - Vectors
 * CLASS         : CS1D
 * SECTION       : Mondays & Wednesday: 3:00 - 6:20PM
 * DUE DATE    	 : 1/17/2018
 ************************************************************************/

/*************************************************************************
 * Vectors
 * _______________________________________________________________________
 *  a.	Write a program that uses a random number generator to generate 15 three-digit integers
	b.	Store the random numbers in a vector
	c.	Sort the random numbers
	d.	Reverse the digits of the random numbers
	e.	Store the reversed digits in another vector
	f.	Sum the digits of the random numbers
	g.	Store the sums in another vector
	h.	Print all three vectors
 ************************************************************************/

#include "header.h"

const void PRINTAUTHOR() {

	cout << left;
	cout << "********************************************************\n";
	cout << setw(10) << "AUTHOR: " << "Christopher Millones & Jose Cardenas\n";
	cout << setw(10) << "Lab #1:   Vectors\n";
	cout << setw(10) << "CLASS: " << "CS1D\n";
	cout << setw(10) << "TIME: " << "Mondays & Wednesday: 3:00 - 6:20PM\n";
	cout << setw(10) << "DUE DATE: " << " 1/17/18\n";
	cout << "********************************************************\n\n";
}

const void INSTRUCTIONS() {

	cout << left;
	cout << "a.	Write a program that uses a random number generator to generate 15 three-digit integers\n"
			"b.	Store the random numbers in a vector\n"
			"c.	Sort the random numbers\n"
			"d.	Reverse the digits of the random numbers\n"
			"e.	Store the reversed digits in another vector\n"
			"f.	Sum the digits of the random numbers\n"
			"g.	Store the sums in another vector\n"
			"h.	Print all three vectors\n\n";
}

string backWards(int number); // prototype of backwards function
int sumNumbers(int number); // prototype of sumNumbers function
int main()
{

	vector<int> randomNumbers; //Will hold 15 random three digit integers
	vector<string> reverseRandomNumbers; // Will hold 15 reverse three random digit integers
	vector<int> sumOfRandomNumbers; // will hold 15 sum of the random three digit integers

	//HEADERS
	PRINTAUTHOR();
	INSTRUCTIONS();



	 srand (time(NULL)); // Will set a seed for a random time

	 // Will push back 15 random numbers between 100 - 999
	for(int i = 0; i<= 14; i++)
	{
		randomNumbers.push_back(rand()%899 + 100);
	}

	// Will sort the 15 random numbers between 100-999
	 std::sort(randomNumbers.begin(), randomNumbers.begin()+15);

	 //Will Reverse the 15 random numbers and store them into a vector
	 for(int i = 0; i<=14; i++)
	 {
		 reverseRandomNumbers.push_back(backWards(randomNumbers.at(i)));
	 }

	 //Will sum the three digit integers for all 15 random numbers
	 for(int i = 0; i<=14; i++)
	 {
		 sumOfRandomNumbers.push_back(sumNumbers(randomNumbers.at(i)));
	 }

	 /*
	  * Will Display the outputs along with the task at hand.
	  */
	 cout << "a&b&c.)Store the random numbers in a vector & sort\n";
	 for(int i = 0; i<=14; i++)
	 {

		cout << randomNumbers.at(i) << endl;
	 }

	 cout << endl << "d&e.)Reverse the digits of the random numberse.Store the reversed digits in another vector\n";
	 for(int i = 0; i<=14; i++)
	 {

		cout << reverseRandomNumbers.at(i) << endl;
	 }

	 cout << endl << "f&g&h.) Sum the digits of the random numbers.Store the sums in another vector";
	 for(int i = 0; i<=14; i++)
	 {
		cout << endl << "The sum of " << randomNumbers.at(i) << " is ";
		cout << sumOfRandomNumbers.at(i);
	 }

	return 0;
}


/*
 * Will take in an integer as a parameter and store the integer into a string stream
 * and repeat for 3 loops generating the reverse of the original number
 */
string backWards(int number)
{

	stringstream temp; // will hold the string stream

	for(int i=0; i<=2; i++)
	{
			temp << (number%10); // will store the the last digit of 'number'
		if( i != 2)
		{
			number /= 10; // will drop the last digit of 'number'
		}
	}
    return temp.str(); // convert stringstream to string for storing methods.
}

/*
 * Will take in an integer as a parameter and sum up the individual digits.
 */
int sumNumbers(int number)
{
	int temp = 0;

	for(int i=0; i<=2; i++)
	{
			temp += (number%10); // will add the the last digit of 'number'
		if( i != 2)
		{
			number /= 10; // will drop the the last digit of 'number'
		}
	}
    return temp;
}
































