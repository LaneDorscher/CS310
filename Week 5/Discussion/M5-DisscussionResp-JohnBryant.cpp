/* Author: John Bryant
   Date: 04/16/2026
   Description: This program performs basic arithmetic operations (addition, subtraction, multiplication) on two user-inputted numbers and displays the results.
	
   Editor: Lane Dorscher
   Filename: M5-DiscussionResp-JohnBryant.cpp
   Date: 04/18/2026
*/

#include <iostream>
using namespace std;


// Editor Note: Added function prototypes for add, subtract, and multiply functions

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);


int main()
{
	int num1, num2;


	cout << "Enter first number: ";
	cin >> num1;

	cout << "Enter second number: ";
	cin >> num2;


	cout << "\nResults:" << endl;
	cout << "Addition: " << add(num1, num2) << endl;
	cout << "Subtraction: " << subtract(num1, num2) << endl;
	cout << "Multiplication: " << multiply(num1, num2) << endl;

} //editor note: added closing curly brace for main function


// editor note: fixed document formatting, not relevant to code functionality

int add(int a, int b)
{
	return a + b;
}

int subtract(int a, int b)
{
	return a - b;
}

int multiply(int a, int b)
{
	return a * b;
}
