/*************************************************************************
 * AUTHORS	     : Chris Millones
 * STUDENT IDS   : 361396
 * Assignment #4 : Binary Trees
 * CLASS         : CS1D
 * SECTION       : Mondays & Wednesday: 3:00 - 6:20PM
 * DUE DATE    	 : 2/22/2017
 ************************************************************************/

/*************************************************************************
 * Binary Trees
 * _______________________________________________________________________
 * Implement a binary search tree using an array, vector or linked list.
 * store the following elements:
 * 88, 12, 24, 49, 7, 25, 55, 18, 19, 13, 109, 18, 44, 1001
 *
 * Perform the in-order, post-order, pre-order, breadth-first traversals
 *
 * in addition to the traversals, print out the binary search tree by
 * level.
 ************************************************************************/
#include "header.h"
#include "BST.h"

const void PRINTAUTHOR() {

	cout << left;
	cout << "********************************************************\n";
	cout << setw(10) << "AUTHOR: " << "      Christopher Millones\n";
	cout << setw(10) << "ASSIGNMENT #4:  Binary Trees \n";
	cout << setw(10) << "CLASS: " << "      CS1D\n";
	cout << setw(10) << "TIME: " << "      Mondays & Wednesday: 3:00 - 6:20PM\n";
	cout << setw(10) << "DUE DATE: " << "      2/21/2018\n";
	cout << "********************************************************\n\n";
}

const void INSTRUCTIONS() {

	cout << left;
	cout << "Implement a binary search tree using an array, vector or linked list.\n"
			"store the following elements:\n"
			"\n109, 55, 28, 19, 13, 1001, 18, 44, 88, 12, "
			"24, 49, 7, 35, 55, 28, 19, 13, 18\n\n"
			"Perform the in-order, post-order, pre-order, breadth-first traversals\n"
			"in addition to the traversals, print out the binary search tree by level.\n\n";
}

int main()
{

	PRINTAUTHOR();   //Brief summary abt author
	INSTRUCTIONS();  //Prints the Assignment to be completed


	BST<int>* tree = new BST<int>;  //Create an Empty Tree.

	int data; 						//Will be used to store data. type int.

	ifstream inFile;				//Create an Ifstream variable

	inFile.open("data.txt");	//Open File "data.txt". allows extraction

	/*
	 * Loop Will run until the file is empty.
	 * Will store the data into "data" then store that
	 * data into a root of a tree. and keep on filling the tree
	 * until the file is out of data
	 */
	while(!inFile.eof())
	{
		inFile >> data;	// Store integer data into variable
	tree->root = tree->Insert(tree->root,data); // Store data to tree
	}


	//Prints the original binary tree with levels.
	cout << "\t~BinarySearchTree~\n";
	tree->PrintByLevel(tree->getRoot());

	//prints the traversal of the binary tree( IN-ORDER)
	cout << "\n\t~In-Order Traversals~\n";
	tree->In_Order(tree->getRoot());

	//prints the traversal of the binary tree( POST-ORDER)
	cout << "\n\t~Post-Order Traversals~\n";
	tree->Post_Order(tree->getRoot());

	//prints the traversal of the binary tree( PRE-ORDER)
	cout << "\n\t~Pre-Order Traversals~\n";
	tree->Pre_Order(tree->getRoot());

	//prints the traversal of the binary tree( BREADTH-ORDER)
	cout << "\n\t~Breadth-First~\n";
	tree->Breadth_Order(tree->getRoot());


	return 0;
}


