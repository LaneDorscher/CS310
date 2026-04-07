/* Author: Lane Dorscher
 * Date: 04/06/2026
 * Program Name: Ch05Exercise33.cpp
 * Program Description: Calculates the number of dishes that can be prepared in a set time (in minutes)
 * Program Assignment:
		Bianca is preparing special dishes for her daughter’s birthday. It takes her "a" minutes to prepare the first dish, and each following dish takes "b" minutes longer than the previous dish. She has "t" minutes to prepare the dishes.
		For example, if the first dish takes a = 10 minutes and b = 5, then the second dish will take 15 minutes, the third dish will take 20 minutes, and so on. If she has 80 minutes to prepare the dishes, then she can prepare four dishes because 10 + 15 + 20 + 25 = 70.
		Write a program that prompts the user to enter the values of a, b, and t, and outputs the number of dishes Bianca can prepare.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{

	// Variables

	// User Input
	int a;
	int b;
	int t;

	// Calculations
	int timeUsed = 0;
	int currentDishTime = 0;
	int numOfDishes = 0;

	// Acquire the input needed
	cout << "\nHow much time until the party? ";
	cin >> t;
	cout << "\nHow many minutes for the first dish? ";
	cin >> a;
	cout << "\nHow many minutes for the second dish? ";
	cin >> b;

	currentDishTime = a;

	//while loop adds each consequetive dish to the last until the time used is greater than the time we have. Ensuring whole number calculations as we can't make half a dish. 
	while (timeUsed + currentDishTime <= t)
	{
		timeUsed += currentDishTime;
		numOfDishes++;
		currentDishTime += b;
	}

	//Final output

	cout << "\nBianca can prepare " << numOfDishes << " dishes before the party\n\n\n";


	return 0;
}