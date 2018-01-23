/*************************************************************************
 * AUTHOR(S)	 : Chris Millones & Alexander Frederick
 * STUDENT IDS   : 361396 & 1054657
 * Lab # 2		 : Recursion
 * CLASS         : CS1D
 * SECTION       : Mondays & Wednesday: 3:00 - 6:20PM
 * DUE DATE    	 : 1/22/2018
 ************************************************************************/

/*************************************************************************
 * Recursion
 * _______________________________________________________________________
 *Write a recursive function that takes a
   string as an argument and returns a TRUE
   if the string is a palindrome otherwise FALSE is returned
 *
 *
 ************************************************************************/

#include "header.h"

const void PRINTAUTHOR() {

	cout << left;
	cout << "********************************************************\n";
	cout << setw(10) << "AUTHOR: " << "Christopher Millones & Alexander Frederick\n";
	cout << setw(10) << "Lab # 2:  Recurssion\n";
	cout << setw(10) << "CLASS: " << "  CS1D\n";
	cout << setw(10) << "TIME: " << "  Mondays & Wednesday: 3:00 - 6:20PM\n";
	cout << setw(10) << "DUE DATE: " << "   1/22/2018\n";
	cout << "********************************************************\n\n";
}

const void INSTRUCTIONS() {

	cout << left;
	cout << "Write a recursive function that takes a\n"
			"string as an argument and returns a TRUE\n"
			"if the string is a palindrome otherwise FALSE is returned\n\n";
}

bool isPalindrome(string word, int start, int end); // prototype of function.
int main()
{
	ifstream data;		// Will hold the data/input
	string word = "";   // Will hold the Orignial word for output purposes
	string temp = "";   // Will hold the lower case version of the word
	string temp2 = "";  // Will hold the OG word without any puncutations and or spaces
	int start = 0;		// Will be used to read the first index of 'temp2'
	int end = 0;		// Will be used to read the last index of 'temp2'

	//Output purposes
	PRINTAUTHOR();
	INSTRUCTIONS();

	data.open("input.txt");	//opens file 'input.txt'

	//Will loop all data of 'input.txt' and display if the word is a Palindrome
	while(!data.eof())
	{
		getline(data, word);
		temp = word;

		//Will lower all letters in word. and store into temp
		for(int i = 0; i < temp.length(); i++)
		temp[i] = tolower(temp[i]);

		//Will store all alpha characters into temp2
		for(int i = 0; i < temp.length(); i++)
		{
			if(isalpha(temp[i]))
			{
				temp2 += temp[i];
			}
		}

		end = temp2.size()-1; // will hold the last index of temp2

		if(isPalindrome(temp2, start, end))
		{
			cout << word << " IS A PALINDROME\n";
		}
		else
		{
			cout << word << " IS NOT A PALINDROME\n";
		}
		temp2 = ""; // reset temp2 to be empty
	}
	data.close(); // close file
	return 0;
}

/*
 *'isPalindrome' will be a recursive function that will take in 3 arguments
 *and return true or false if 'word' is a palindrome. Will compare the word
 *at index 'start' and 'end' until they match or don't. If they don't match
 *will auto return false;
 */
bool isPalindrome(string word, int start, int end)
{
	if(start >= end)
		return true;
	if(word[start] != word[end])
		return false;
	return isPalindrome(word,++start,--end);
}
