/*************************************************************************
 * AUTHOR(S)	 : Chris Millones
 * STUDENT IDS   : 361396 & --------
 * Lab #		 : ------
 * CLASS         : CS1D
 * SECTION       : Mondays & Wednesday: 3:00 - 6:20PM
 * DUE DATE    	 : -------
 ************************************************************************/

/*************************************************************************
 * Assignment 2 - Stacks and Deques
 * _______________________________________________________________________
 *	Given the following data:
 *
	Input for the string stacks/queues/deques
	Mark, Alan, Rick, Eric, Jennifer, JoAnn, Bill

	Input for the double stacks/queues/deques
	44.44, 888.55, 88.88, 123.123, 8.445, 983.3

	A.)Implement and print the stacks using the STL <stack> with the above data.
	B.)Delete Cathy and 1.2 from the above stacks (you will need to delete others)
	   using the STL <stack> and print the remaining elements in the stacks.
	C.)Implement and print the stacks using a singly linked list using the above data.
	   Do not use the STL.
	D.)Delete Rick and 88.8 from the above stacks (you will need to delete others)
	   and print the remaining elements in the stacks. Do not use the STL.
	E.)Implement and print the queues using either a circular array or a
	   linked list using the above data.  Do not use the STL.
	F.)Delete Rick and 88.8 from the above queues (you will need to delete others)
	   and print the remaining elements in the queues. Do not use the STL.
	G.)Implement and print the deques using a linked list using the above data.
       Do not use the STL.
	H.)Delete Rick and 88.8 from the above deques (you will need to delete others)
	   and print the remaining elements in the deques. Do not use the STL.
    I.)Implement the Parentheses Algorithm without using the STL).
       Test your algorithm with the following mathematical statements.
 E.C.)If valid, write software to evaluate the expressions assuming x = -1.
 *
 *
 *
 ************************************************************************/

#include "header.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Deque.h"

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
	cout << "Given the following data:\n"
			"Input for the string stacks/queues/deques\n"
			"Mark, Alan, Rick, Eric, Jennifer, JoAnn, Bill\n"
			"Input for the double stacks/queues/deques\n"
			"44.44, 888.55, 88.88, 123.123, 8.445, 983.3\n"
"	A.)Implement and print the stacks using the STL <stack> with the above data.\n"
"	B.)Delete Rick and 88.8 from the above stacks (you will need to delete others)\n"
"	   using the STL <stack> and print the remaining elements in the stacks.\n"
"	C.)Implement and print the stacks using a singly linked list using the above data.\n"
"	   Do not use the STL.\n"
"	D.)Delete Rick and 88.8 from the above stacks (you will need to delete others)\n"
"	   and print the remaining elements in the stacks. Do not use the STL.\n"
"	E.)Implement and print the queues using either a circular array or a\n"
"	   linked list using the above data.  Do not use the STL.\n"
"	F.)Delete Rick and 88.8 from the above queues (you will need to delete others)\n"
"	   and print the remaining elements in the queues. Do not use the STL.\n"
"	G.)Implement and print the deques using a linked list using the above data.\n"
"           Do not use the STL.\n"
"	H.)Delete Rick and 88.8 from the above deques (you will need to delete others)\n"
"	   and print the remaining elements in the deques. Do not use the STL.\n"
"        I.)Implement the Parentheses Algorithm without using the STL).\n"
"           Test your algorithm with the following mathematical statements.\n"
"      E.C.)If valid, write software to evaluate the expressions"
" assuming x = -1.\n";
}

void loadStringData(stack<string>& stringStack, ifstream& inFile);
void loadDoubleData(stack<double>& stringStack, ifstream& inFile);
bool PA(string X);
int main()
{
	/*
	 * The following two functions will be used to display Insturctions to
	 * the Assignment and print the authors information.
	 */
	PRINTAUTHOR();
	INSTRUCTIONS();
//
//	stack<string> stringStack; //Will hold the strings using stack
//	stack<double> doubleStack; //Will hold the doulbes using stack
//	string names[7]; 		   //Will be used to temp hold the data of names
//	double numbers[6];		   //Will be used to temp hold the data of doubles
//	ifstream inFileString;     //Will be used to open name data txt
//	ifstream inFileDouble;     //Will be used to open double data txt
//	int i;					   //Will be used to help display element #
//
//	//Initialize
//	inFileString.open("StringData.txt"); //open string data txt
//	inFileDouble.open("DoubleData.txt"); //open double data txt
//	i = 0; // give 'i' a starting place.
//
//	//Load the stack's with the given data.
//	loadStringData(stringStack,inFileString);
//	loadDoubleData(doubleStack,inFileDouble);
//
///*************************************************************************
// *********** WILL BE PART A and B of the ASSIGNMENT **********************
// *************************************************************************/
//	cout <<"\n\n\t*******PART A*******\n";
//	cout <<"-STACK OF NAMES-\n";
//// Will display the the current stack and 'names[]' will temp hold the data.
//	while(!stringStack.empty())
//	{
//		cout << "ELEMENT [" << i+1 << "]: " << stringStack.top() << endl;
//		names[i] = stringStack.top();
//		stringStack.pop();
//		i++;
//	}
//	i = 0; // re-initialize i to 0 for optimal output
//	cout <<"\n-STACK OF DOUBLES-";
//// Will display the the current stack and 'double[]' will temp hold the data.
//	while(!doubleStack.empty())
//	{
//		cout << "\nELEMENT [" << i+1 << "]: " << doubleStack.top();
//		numbers[i] = doubleStack.top();
//		doubleStack.pop();
//		i++;
//	}
//	i = 0;
//
//	//Re-Initlize the stack to it's Original Data.
//	for(int j=6; j>=0; j--)
//	{
//		stringStack.push(names[j]);
//	}
//	for(int j=5; j >= 0; j--)
//	{
//		doubleStack.push(numbers[j]);
//	}
//	cout << endl << endl;
//	cout <<"\t*******PART B*******\n";
//	cout <<"---POPPING FROM NAMES---\n";
//	//Poping the specified to data from both stacks (Rick and 88.8, respectively)
//	for(int j = 0; j<= 4; j++)
//	{
//		cout << "POPPING: " << stringStack.top() << "\n";
//		stringStack.pop();
//	}
//	cout << "---POPPING FROM DOUBLES---\n";
//	for(int j = 0; j<= 3; j++)
//	{
//		cout << "POPPING: " << doubleStack.top() << "\n";
//		doubleStack.pop();
//	}
//	cout << "\t-REMAINING STACK-\n";
//	cout <<"-STACK OF NAMES-\n";
//	//Display the Final output of after popping Rick and 88.8, respectively
//	while(!stringStack.empty())
//	{
//		cout << "ELEMENT [" << i+1 << "]: " << stringStack.top() << endl;
//		stringStack.pop();
//		i++;
//	}
//	i = 0;
//	cout <<"\n-STACK OF DOUBLES-";
//	while(!doubleStack.empty())
//	{
//		cout << "\nELEMENT [" << i+1 << "]: " << doubleStack.top();
//		doubleStack.pop();
//		i++;
//	}
//
///*************************************************************************
// *********** WILL BE PART C and D of the ASSIGNMENT **********************
// *************************************************************************/
//	StackLinkedList<string>* stackString = new StackLinkedList<string>;
//	StackLinkedList<double>* stackDouble = new StackLinkedList<double>;
//	string nameFile = "StringData.txt";
//	string numberFile = "DoubleData.txt";
//
//	cout <<"\n\n\t*******PART C*******\n";
//	stackString->InitializeStack(nameFile);
//	stackDouble->InitializeStack(numberFile);
//
//	cout<<"-STACK OF NAMES-\n";
//	stackString->printStack();
//	cout<<"-STACK OF DOUBLES-\n";
//	stackDouble->printStack();
//
//	cout <<"\n\t*******PART D*******\n";
//	cout << "---POPPING FROM NAMES---\n";
//	for(int j = 0; j<= 4; j++)
//	{
//		cout << "POPPING: " << stackString->top() << "\n";
//		stackString->pop();
//	}
//	cout << "---POPPING FROM DOUBLES---\n";
//	for(int j = 0; j<= 3; j++)
//	{
//		cout << "POPPING: " << stackDouble->top() << "\n";
//		stackDouble->pop();
//	}
//	cout << "\t-REMAINING STACK-";
//	cout<<"\n-STACK OF NAMES-\n";
//	stackString->printStack();
//	cout<<"\n-STACK OF DOUBLES-\n";
//	stackDouble->printStack();
//
///*************************************************************************
// *********** WILL BE PART E and F of the ASSIGNMENT **********************
// *************************************************************************/
//	Queue<string> *StringQueue = new Queue<string>;
//	Queue<double> *DoubleQueue = new Queue<double>;
//
//	cout <<"\n\t*******PART E*******\n";
//	cout <<"-QUEUE OF NAMES-\n";
//	StringQueue->InisiateQueue(nameFile);
//	StringQueue->Print();
//	cout <<"-QUEUE OF DOUBLES-\n";
//	DoubleQueue->InisiateQueue(numberFile);
//	DoubleQueue->Print();
//	cout <<"\n\t*******PART F*******\n";
//	cout << "---POPPING FROM NAMES---\n";
//	for(int j = 0; j<= 2; j++)
//	{
//		StringQueue->Remove_Front();
//	}
//	cout << "---POPPING FROM DOUBLES---\n";
//	for(int j = 0; j<= 2; j++)
//	{
//		DoubleQueue->Remove_Front();
//	}
//	cout << "\t-REMAINING STACK-";
//	cout<<"\n-STACK OF NAMES-\n";
//	StringQueue->Print();
//	cout<<"\n-STACK OF DOUBLES-\n";
//	DoubleQueue->Print();
//
///*************************************************************************
// *********** WILL BE PART G and H of the ASSIGNMENT **********************
// *************************************************************************/
//	Deque<string> *DequeString = new Deque<string>;
//	Deque<double> *DequeDouble = new Deque<double>;
//
//	cout <<"\n\t*******PART G*******\n";
//	cout <<"-DEQUE OF NAMES-\n";
//	DequeString->InitiateDeque(nameFile);
//	DequeString->Print();
//	cout <<"-DEQUE OF DOUBLES-\n";
//	DequeDouble->InitiateDeque(numberFile);
//	DequeDouble->Print();
//
//	cout <<"\n\t*******PART H*******\n";
//	cout << "---POPPING FROM NAMES---\n";
//	for(int j = 0; j<= 2; j++)
//	{
//		DequeString->Remove_Front();
//	}
//	cout << "---POPPING FROM DOUBLES---\n";
//	for(int j = 0; j<= 2; j++)
//	{
//		DequeDouble->Remove_Front();
//	}
//	cout << "\t-REMAINING STACK-";
//	cout<<"\n-STACK OF NAMES-\n";
//	DequeString->Print();
//	cout<<"\n-STACK OF DOUBLES-\n";
//	DequeDouble->Print();

/*************************************************************************
 *********** WILL BE PART I and E.C. of the ASSIGNMENT ********************
 *************************************************************************/
	ifstream Equations;
	Equations.open("Equations.txt");
	string equation;
	bool temp;

	cout << endl;
	for(int i=0; i<7; i++)
	{
		getline(Equations,equation);
		temp = PA(equation);
		if(temp == true)
		{
			cout << equation << "\t<--IS VALID\n";
		}
		else
		{
			cout <<  equation << "\t<--IS NOT VALID\n";
		}

	}

	Equations.close();
//	inFileDouble.close();
//	inFileString.close();
	return 0;
}
bool PA(string x)
{
	StackLinkedList<char> *list = new StackLinkedList<char>;
	for(int i=0; i< x.size(); i++)
	{
		if(x.at(i)== '[' || x.at(i) == '{' || x.at(i)== '(')
		{
			list->push(x.at(i));
		}
		if(x.at(i)== ']' || x.at(i) == '}' || x.at(i)== ')')
		{
			if(list->empty())
			{
				return false;
			}
			if(x.at(i) == ']' && list->top() == '[')
			{
				list->pop();
			}else if(x.at(i) == '}' && list->top() == '{')
			{
				list->pop();
			}else if(x.at(i) == ')' && list->top() == '(')
			{
				list->pop();
			}else
			{
				return false;
			}

		}
	}
	if(!list->empty())
	{
		return false;
	}
	else
	{
		return true;
	}
}
void loadStringData(stack<string>& stringStack, ifstream& inFile)
{
	string name;
	while(!inFile.eof())
	{
		getline(inFile,name);
		stringStack.push(name);
	}
}
void loadDoubleData(stack<double>& stringStack, ifstream& inFile)
{
	double number;
	while(!inFile.eof())
	{
		inFile >> number;
		stringStack.push(number);
	}

}

















