/*
* Student Name: Jesse Bunnell
* File Name: Errors.cpp
* Date: 03/26/2026
*/

#include <iostream>

int main()
{
    //Declare variables to store hourly wage, hours worked, monthly salary
    double hourlyWage;
    double hoursWorked;
    double monthlySalary;

    // Ask the user to input their hourly wage
	std::cout << "Enter your hourly wage: $";           //dev note (Lane): corrected 'cot' to 'cout'

    // Store the user's input in 'hourlyWage'
    std::cin >> hourlyWage;                             //dev note (Lane): added semicolon at the end of the line

    //Ask the user to input the number of hours worked
    std::cout << "Enter the number of hours worked in a month: "; 
    
    // Store the user's input in 'hoursWorked'
    std::cin >> hoursWorked;

    // Calculate the monthly salary by multiplying wage and hours
    monthlySalary = hourlyWage * hoursWorked;

    // Display the result to the user
    std::cout <<"Your monthly salary is: $" << monthlySalary << std::endl;

    // Return 0 to indicate successful program execution
    return 0;

}