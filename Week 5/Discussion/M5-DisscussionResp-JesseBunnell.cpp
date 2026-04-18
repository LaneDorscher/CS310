/*
* Student Name: Jesse Bunnell
* File Name: Week5Errors.cpp
* Date: 04/15/2026
* 
* Editor Name: Lane Dorscher
* New File Name: M5-DisscussionResp-JesseBunnell.cpp
* Date: 04/18/2026
*/



#include <iostream>
using namespace std;

// Function to add two numbers
int addNumbers(int x, int y)
{
	int result = x + y; //editor note: added semicolon at the end of this line
    return result;
}

int main()
{
    int a = 5;
    int b = 10;

    // Call the function
	int sum = addNumbers(a, b); //editor note: fixed the function call to match the declared function name (addNumbers instead of addNumber)

    cout << "Sum is: " << sum << endl; //editor note: added semicolon at the end of this line

    return 0;
}