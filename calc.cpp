//I Ayne, have not used any code other than my own(or that in the textbook) for this project.
//I also have not used any function or data - structure from the Standard - Template Library.
//I understand that any violation of this disclaimer will result in a 0 for the project.

#include <iostream>
#include <fstream>
#include "stack.h"
#include <string>
using namespace std;
using namespace main_savitch_7A;
//--------------------CONSTANTS--------------------
//THE OPERATORS
const char ADD = '+';
const char SUBTRACT = '-';
const char MULTIPLY = '*';
const char DIVIDE = '/';
const unsigned NUM_OPS = 4; //how many operators

//----------------------------------FUNCTION PROTOTYPES--------------------------------------

//The is_operator function
//Purpose: determines if a char is an operator =,-,*,/
//Parameters: a char, read in from the file
//Returns: a bool, if it's an operator or if it's not an operator
//pre-condition: none
//post-condition: returns true if the char read in is an operator, else false.
bool is_operator(char);

//Printer function
//Purpose: print operators on a stack in post-fix notation
//Parameters: a stack object
//Returns: None
//Pre-condition: non-empty stack
//Post-condition: outputs to the console the operators in post-fix notation
template <class T>
void printer(stack<T>&);

//higher_precedence function
//Purpose: determine precedence of an operator
//Parameters: two chars to compare
//Returns: a bool
//Pre-condition: none
//Post-condition: if top operator on stack has higher precedence, return true.
bool higher_precedence(char, char);


int main()
{

	cout << "testing the stack class..." << endl;
	stack<char> myStack;
	ifstream input("tests.txt");

	if (input.fail())
	{
		cerr << "Could not open input file." << endl;
		system("PAUSE");
		exit(0);
	}

	do
	{

		if (input.peek() == '\n')
		{
			while (!myStack.empty())
				printer(myStack);
			char in = input.get();
			cout << endl;
		}

		else if (input.peek()== '(')
		{
			char in = input.get();
			myStack.push(in);
		}
		else if (isdigit(input.peek()))
		{
			char in = input.get();
			cout << in << " ";
		}
		else if (is_operator(input.peek()))
		{
			while (!myStack.empty())
			{
				if (myStack.top() == '(')
				{
					if (!myStack.empty())
					myStack.pop();
					break;
				}
				if (!higher_precedence(input.peek(), myStack.top()))
				{
					break;
				}
				printer(myStack);
				
			}
			char in = input.get();
			myStack.push(in);
		}
		else
		{
			if (input.peek() == ')')
				input.ignore();
			while (!myStack.empty())
			{
				if (myStack.top() == '(')
					break;
				printer(myStack);
			}
			if (!myStack.empty())
				myStack.pop();
		}
		
		//else if (input.peek() == ')' || input.peek() == '\n') //end of a parenthesis or end of the equation
		//{
		//	//while (!myStack.empty() || myStack.top() != '(')
		//		printer(myStack);
		//		if (!myStack.empty())//pop '('
		//				myStack.pop();
		//		
		//	if (input.peek() == '\n')
		//		cout << endl;
		//	input.get();
		//}
		//else if (!is_operator(input.peek())) //not an operation, ( or )
		//{
		//	char in = input.get();
		//	cout << in << " ";
		//}
		//else
		//{
		//	
		//		
		//	 while (!myStack.empty() && myStack.top() != '(' && higher_precedence(input.peek(), myStack.top()))
		//		 printer(myStack);
		//	char in = input.get();
		//	myStack.push(in);
		//}
		
	
		//       else if(input.peek()==')' || input.peek()=='\n')//if it's the end of the paren. or equation
		//       {
		//
		//          // while(myStack.empty()==false && higher_precedence(input.peek(), myStack.top())) //print what is on the stack.
		//           
		//              // if (!higher_precedence(input.peek(), myStack.top()))
		//                 //  break;
		//               printer(myStack);
		//           
		//           if(input.peek()=='\n')
		//               cout<<endl;
		//           input.get();//get next item after finish printing
		//          
		//          
		//       }
		//
		//else if (!is_operator(input.peek())) //if it's not a (, ) or operator, print it out
		//{
		//	/*if (input.peek() == '\n')
		//		printer(myStack);
		//	if (input.peek() == ')')
		//		input.ignore();
		//	if (input.peek() == '(')
		//		input.ignore();*/
		//	char in = input.get();
		//	cout << in << " ";
		//}

		//else if (is_operator(input.peek())) //if it is an operator...
		//{

		//	while (!myStack.empty() && higher_precedence(input.peek(), myStack.top()) && myStack.top()!='(')
		//		printer(myStack);



		//	char in = input.get();
		//	//               if(!myStack.empty()&& higher_precedence(in, myStack.top()) && input.peek()!=')')
		//	//               {
		//	//                   printer(myStack);
		//	//                  
		//	//               }
		//	myStack.push(in);

		//}
		//else
		//{
		//	input.get();
		//	input.ignore();
		//	while (myStack.top()!='(' || !myStack.empty())
		//		printer(myStack);
		//	if (!myStack.empty())
		//		myStack.pop();//popping left parenthesis
		//}



	} while (input && input.peek() != EOF);
	
	input.close();
	printer(myStack);
	system("PAUSE");

	return 0;
}


bool is_operator(char op)
{

	char ops[] = { ADD, SUBTRACT, MULTIPLY, DIVIDE };
	for (unsigned i = 0; i <NUM_OPS; i++)
	{
		if (op == ops[i])
			return true;
	}
	return false;

}

bool higher_precedence(char nextInput, char nextStack)
{
	char ops[] = { SUBTRACT, ADD, DIVIDE, MULTIPLY };
	int nextInputP = 0;
	int nextStackP = 0;

	for (unsigned i = 0; i<NUM_OPS; i++)
	{
		if (nextInput == ops[i])
			nextInputP = i;
	}
	if (nextInputP == 0)
		nextInputP = 1;
	if (nextInputP == 2)
		nextInputP = 3;
	for (unsigned i = 0; i<NUM_OPS; i++)
	{
		if (nextStack == ops[i])
			nextStackP = i;
	}
	if (nextStackP == 0)
		nextStackP = 1;
	if (nextStackP == 2)
		nextStackP = 3;
	if (nextStackP >= nextInputP)
		return true;
	else
		return false;

}

template <class T>
void printer(stack<T>& theStack)
{
	if (theStack.empty())
		return;

	else
	{
		cout << theStack.top() << " ";
		if (theStack.empty())
			return;

		else
			theStack.pop();
	}


}




