/*
Author: Lane Dorscher
Date: 04/16/2026
Assignment: Ch06Exercise14.cpp 

Description:
This program calculates the billing amount for tax consultation services.
It determines whether a client qualifies for discounted rates based on
their yearly income and applies the correct billing rules based on
consultation time.

Source: chapter 6, programming exercise 14
During the tax season, every Friday, the J&J accounting firm provides assistance to people who prepare their own tax returns.

Their charges are as follows:
If a person has low income (<= 25,000) and the consulting time is less than or equal to 30 minutes, there are no charges; otherwise, the service charges are 40% of the regular hourly rate for the time over 30 minutes.
For others, if the consulting time is less than or equal to 20 minutes, there are no service charges; otherwise, service charges are 70% of the regular hourly rate for the time over 20 minutes.

(For example, suppose that a person has low income and spent 1 hour and 15 minutes, and the hourly rate is $70.00. Then the billing amount is 70.00 x 40 x (45/60) = $21.00.)

Write a program that prompts the user to enter the hourly rate, the total consulting time, and whether the person has low income. The program should output the billing amount. Your program must contain a function that takes as input the hourly rate, the total consulting time, and a value indicating whether the person has low income. The function should return the billing amount. Your program may prompt the user to enter the consulting time in minutes.
*/


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


const int LOW_INCOME_CRITERIA = 25000;
const float LOW_INCOME_DISCOUNT_PERCENT = 0.40;
const int LOW_INCOME_TIME_RESTRAINT_IN_MINUTES = 30;

const int TIME_RESTRAINT_IN_MINUTES = 20;
const float DISCOUNT_PERCENT = 0.70;

/* Headers (Prototypes) */

void DisplayGreeting();
void DisplayGoodbye();

float GetHourlyRate();
int GetTotalConsultingTimeInMinutes();
float GetYearlyIncome();

float CalculateCharge(float yearlyIncome, float hourlyRate, int totalMinutes);
void PrintResults(float serviceCharge);

int main()
{
	DisplayGreeting();
	
	float hourlyRate = GetHourlyRate();
	int consultTime = GetTotalConsultingTimeInMinutes();
	float yearlyIncome = GetYearlyIncome();	
	
	float serviceCharge = CalculateCharge(yearlyIncome, hourlyRate, consultTime);
	PrintResults(serviceCharge);
	
	DisplayGoodbye();
	
	return 0;
}

///Prompts the user for a positive, non-zero numeric value to present the hourly rate of the service
///Returns the hourly rate as a float.
float GetHourlyRate()
{
	float rate;
	bool flag;
	do {
		cout << "Enter the hourly rate: ";
		cin >> rate;
		
		flag = rate <= 0;
		if (flag)
		{
			cout << "Hourly rate must be a positive, non-zero, numeric value! Try again!" << endl << endl;			
		}		
	} while(flag);
	return rate;
}

///Prompts the user to enter positive (or zero) integer values for the total hours and minutes of consulting time
///Returns the total consulting time in minutes.
int GetTotalConsultingTimeInMinutes()
{
	int minutes;
	int hours;
	bool flag;
	do {
		//get the total consulting time in hours
		cout << "Enter the total consulting time (Hours): ";
		cin >> hours;

		//validate the time is not negative
		flag = hours < 0;
		if (flag)
		{
			cout << "The consulting time cannot be a negative integer! Try again!" << endl << endl;			
			continue;
		}		
	} while(flag);
	
	do {
		//get the total consulting time in minutes
		cout << "Enter the total consulting time (Minutes): ";
		cin >> minutes;

		//validate the time is not negative
		flag = minutes < 0;
		if (flag)
		{
			cout << "The consulting time cannot be a negative integer! Try again!" << endl << endl;			
			continue;
		}		
	} while(flag);
	
	return minutes + (hours * 60);	
}

///Prompts the user to enter a postive, non-zero numeric value for the customers yearly gross income.
///Returns as a float.
float GetYearlyIncome()
{
	float income;
	bool flag;
	do {
		cout << "Enter the yearly gross income: ";
		cin >> income;
		
		flag = income <= 0; //validate income is a postive number
		if (flag)
		{
			cout << "Yearly gross income must be a positive, non-zero numeric value! Try again!" << endl << endl;			
		}		
	} while(flag);
	return income;
}

/// Calculates the service charge based on income level and consulting time.
/// Applies free time limits and discounted hourly rates as defined by business rules.
float CalculateCharge(float yearlyIncome, float hourlyRate, int totalMinutes)
{
	// uses ternaries for inline condition checking ([condition] ? [value if true] : [value if false])
	
	bool isLowIncome = yearlyIncome <= LOW_INCOME_CRITERIA;
	float discountPercent = (isLowIncome ? LOW_INCOME_DISCOUNT_PERCENT : DISCOUNT_PERCENT);
	// subtract free consultation time based on income level
	int chargedMinutes = totalMinutes - (isLowIncome ? LOW_INCOME_TIME_RESTRAINT_IN_MINUTES : TIME_RESTRAINT_IN_MINUTES);
	
	if (chargedMinutes > 0)
	{
		float discountRate = hourlyRate * discountPercent;
		float totalHours = chargedMinutes / 60.0;
		return discountRate * totalHours;
	}
	return 0; //no charge
}

///Prints the program greeting message
void DisplayGreeting()
{
	cout << endl;
	cout << "||=========================================================||" << endl;
	cout << "||           Tax Season Consultations Calculator           ||" << endl;
	cout << "||=========================================================||" << endl;
	cout << endl;
}

///Prints the program's goodbye message
void DisplayGoodbye()
{
	cout << endl;
	cout << "||=========================================================||" << endl;
	cout << "||                  Thank you for using the                ||" << endl;
	cout << "||           Tax Season Consultations Calculator           ||" << endl;
	cout << "||=========================================================||" << endl;
	cout << endl;
}

///Prints the results from the provided input.
void PrintResults(float serviceCharge)
{
    cout << fixed << setprecision(2);

    string message = " |-> Customer should be charged: $";

    cout << endl;
    cout << message << serviceCharge << endl;
    cout << endl;
}