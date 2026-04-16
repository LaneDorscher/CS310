/* Author: Lane Dorscher
 * Date: 04/14/2026
 * Program Name: M5-Discussion-LaneDorscher.cpp
 * Program Description: A continuation of the previous assignment, but with functions and default parameters.
 * Program Assignment: Create a simple C++ program using user-defined functions and at least two errors. The program should not execute and there should be at least two errors in the code
*/

#include <iostream>
#include <string>

using namespace std;


/* Function Prototypes */
void DisplayGoodbye(string hahaMsg);
int GetUserInput(string prompt);
void CountIncrement(int cap, string hahaMsg = "");
void CountDecrement(int cap, string hahaMsg = "");


int main()
{
	const string hahaMsg = "Ha Ha Ha!";

	int num;

	DisplayWelcome();
	num = GetUserInput("Enter a number and I will count to it!");

	CountIncrement(num, hahaMsg);
	CountDecrement(num);


	DisplayGoodbye(hahaMsg);

	return 0;
}

/* Function Definitions */ /

void DisplayWelcome()
{
	cout << "Welcome to my program! I am Count Dracula and I shall count to your number!\n";
}

void DisplayGoodbye(string hahaMsg)
{
	cout << endl << "Bye bye! " << hahaMsg >> endl;
}

int GetUserInput(string prompt)
{
	int num;
	cout << prompt;
	cin >> num;
}


void CountIncrement(int cap, string hahaMsg)
{
	cout << "\n\nI shall count forward! \n";
	bool hasHahaMsg = !hahaMsg.empty();

	for (int i = 1; i <= cap; i++)
	{
		cout << i;
		if (hasHahaMsg && i % 2 == 0)
			cout << "   (" + hahaMsg + ")";
		cout << endl;
	}
}

void CountDecrement(int cap, string hahaMsg)
{
	cout << "\n\nNow I shall count backwards!\n";
	bool hasHahaMsg = !hahaMsg.empty();
	for (int i = cap; i >= 1; i--)
	{
		cout << i;
		if (hasHahaMsg && i % 2 != 0)
			cout << "   (" + hahaMsg + ")";
		cout << endl;
	}
}
