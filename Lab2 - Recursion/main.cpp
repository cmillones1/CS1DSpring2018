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

bool isPalindrome(string word); // prototype of function.
int main()
{
	ifstream data;
	string word;

	data.open("input.txt");

	while(!data.eof())
	{
		getline(data, word);

		if(isPalindrome(word))
		{
			cout << word << " IS A PALINDROME\n";
		}
		else
		{
			cout << word << " IS NOT A PALINDROME\n";
		}
	}

	data.close();
	return 0;
}

/*
 * The "isPalindrome(string word)" function will take in a string, word, as an argument
 * and throughout the function it will break a part and store the word forwards and backwards
 * into two separate variables and comparing them to decide if they are a Palindrome.
 */
bool isPalindrome(string word)
{
	string lowerCase_Word = word;	// Will hold the lower-case for of the O.G. word
	string shortened_Word = "";		// Will hold the word with no spaces or punctuation
	string backwards_Word = "";		// Will hold the O.G. word backwards with no spaces or punctuation


	/*This loop will loop around the original word and take each letter of the
	 *word and return the lower-case of it. Ignoring whitespace and any punctuation.
	 */
	for(int i = 0; i < lowerCase_Word.size() ;i++)
	{
		lowerCase_Word[i] = tolower(lowerCase_Word[i]);
	}

	/*This loop will iterate through lowerCase_Word and store only alphabetical
	 *values into Shortened_word.
	 */
	for(int i = 0; i < lowerCase_Word.size(); i++)
	{
		if(isalpha(lowerCase_Word[i]))
		{
			shortened_Word += lowerCase_Word[i];
		}
	}
	/*This loop will iterate BACKWARDS through lowerCase_Word and store only alphabetical
	 *values into Shortened_word.
	 */
	for(int i = 1; i <= lowerCase_Word.size(); i++)
	{
		if(isalpha(lowerCase_Word[lowerCase_Word.size()-i]))
		{
			backwards_Word += lowerCase_Word[lowerCase_Word.size()-i];
		}
	}

	/*Will compare the Shortened_word vs Backwards_word and return true if the equal
	 * if not, will return false
	 */
	if(shortened_Word.compare(backwards_Word) == 0)
		return true;

	return false;
}
