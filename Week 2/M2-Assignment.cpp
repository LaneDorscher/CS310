
/*
## Author: Lane Dorscher
## Date: 03/29/2026


##### Assignment Instructions

Interest on a credit card’s unpaid balance is calculated using the average daily balance. 
Suppose that netBalance is the balance shown in the bill, payment is the payment made, 
d1 is the number of days in the billing cycle, and d2 is the number of days payment is 
made before the billing cycle. Then, the average daily balance is:

===========================================================================
averageDailyBalance = (netBalance*d1 - payment*d2)/d1
===========================================================================

If the interest rate per month is, say, 0.0152, then the interest on the unpaid balance is:

===========================================================================
interest = averageDailyBalance*0.0152
Number formatting example:
===========================================================================
// format the output to two decimal places with the thousands separator
            cout << fixed << setprecision(2); // set the decimal to two places.
            locale loc(""); // for the thousands separator
            cout.imbue(loc); // for the thousands separator
===========================================================================
Write a program that accepts as input netBalance, payment, d1, d2, and interest rate per month. 
The program outputs the interest. Format your output to two decimal places and use 
a thousands separator for the dollar amounts.

Do not forget to stage, commit, and push your work to GitHub.
*/


#include <iostream>
#include <string>
#include <iomanip>
#include <locale>

using namespace std;

double netBalance;
double payment;
double interestRate;

int d1, d2;

int main()
{
    // Get the net balance from user input
    cout << "Please enter the net balance! " ;
    cin >> netBalance;

    //get the payment made from user input
    cout << "Please enter the payment made! ";
    cin >> payment;

    //get the number of days in the billing cycle from user
    cout << "Please enter the number of days in the billing cycle! ";
    cin >> d1;

    //get the number of days payment was made before the billing cycle
    cout << "Please enter the number of days payment was made before the billing cycle! ";
    cin >> d2;

    //get the monthly interest rate from user
    cout << "Please enter the monthly interest rate as percentage (EX: 15.5)! ";
    cin >> interestRate;

    // Convert percentage to decimal
    interestRate = interestRate / 100.0;

    // Calculate average daily balance
    double averageDailyBalance = (netBalance * d1 - payment * d2) / d1;

    // Calculate interest
    double interest = averageDailyBalance * interestRate;

    // Formatting output
    cout << fixed << setprecision(2);
    locale loc("");
    cout.imbue(loc);

    cout << "\nAverage Daily Balance: $" << averageDailyBalance << endl;
    cout << "Interest on Unpaid Balance: $" << interest << endl;

    return 0;

}
