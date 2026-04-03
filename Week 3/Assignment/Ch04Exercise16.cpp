/************
Author: 			Lane Dorscher
Date: 				4/2/2026
Program-Name: 		M3-Assignment
Program-Description:
    A new author is in the process of negotiating a contract for a new romance novel.
    The publisher is offering three options.
        In the first option, the author is paid $5,000 upon delivery of the final manuscript and $20,000 when the novel is published.
        In the second option, the author is paid 12.5% of the net price of the novel for each copy of the novel sold.
        In the third option, the author is paid 10% of the net price for the first 4,000 copies sold, and 14% of the net price for the copies sold over 4,000.
    The author has some idea about the number of copies that will be sold and would like to have an estimate of the royalties generated under each option.
    Write a program that prompts the author to enter the net price of each copy of the novel and the estimated number of copies that will be sold.
    The program then outputs the royalties under each option and the best option the author could choose. 
    (Use appropriate named constants to store the special values such as royalty rates and fixed royalties.).
************/

#include <iostream>
#include <string>

using namespace std;

int main()
{

    // Constants for Option 1
    const double OPTION1_MANUSCRIPT_PAYMENT = 5000;
    const double OPTION1_PUBLICATION_PAYMENT = 20000;

    // Constants for Option 2
    const double OPTION2_ROYALTY_PERCENT = 12.5;

    // Constants for Option 3
    const double OPTION3_ROYALTY_PERCENT_BASE = 10.0;
    const double OPTION3_ROYALTY_PERCENT_ABOVE_THRESHOLD = 14.0;
    const int OPTION3_COPY_THRESHOLD = 4000;

    // mutable fields
    bool continueCalculations = false;
    double netPricePerBook;
    int estimatedCopiesSold;


    do
    {

        /** Print the opening header and prompt input **/

        cout << endl;
        cout << "#==============================================================#" << endl;
        cout << "#                    Royalties Estimator                       #" << endl;
        cout << "#--------------------------------------------------------------#" << endl;
        cout << "Enter the net price per book: ";
        cin >> netPricePerBook;
        cout << "Enter the estimated number of copies sold: ";
        cin >> estimatedCopiesSold;

        cout << endl << endl;

        /** Calculate the payouts **/

        // Option 1: Fixed payments
        double option1_totalPayout = OPTION1_MANUSCRIPT_PAYMENT + OPTION1_PUBLICATION_PAYMENT;

        // Option 2: Percentage per copy sold
        double option2_totalPayout = (netPricePerBook * (OPTION2_ROYALTY_PERCENT / 100)) * estimatedCopiesSold;

        // Option 3: Tiered percentage
        double option3_totalPayout = 0.0;
        if (estimatedCopiesSold > OPTION3_COPY_THRESHOLD)
        {
            option3_totalPayout += ((estimatedCopiesSold - OPTION3_COPY_THRESHOLD) * netPricePerBook * (OPTION3_ROYALTY_PERCENT_ABOVE_THRESHOLD / 100));
            option3_totalPayout += (OPTION3_COPY_THRESHOLD * netPricePerBook * (OPTION3_ROYALTY_PERCENT_BASE / 100));
        }
        else
        {
            option3_totalPayout += (estimatedCopiesSold * netPricePerBook * (OPTION3_ROYALTY_PERCENT_BASE / 100));
        }



        // Display results
        cout << "## Option 1: $5,000 upon manuscript delivery and $20,000 upon publication." << endl;
        cout << "## 	Estimated total payout: $" << option1_totalPayout << "." << endl;

        cout << "## Option 2: " << OPTION2_ROYALTY_PERCENT << "% of the net price per copy sold." << endl;
        cout << "## 	Estimated total payout: $" << option2_totalPayout << "." << endl;

        cout << "## Option 3: " << OPTION3_ROYALTY_PERCENT_BASE << "% for the first " << OPTION3_COPY_THRESHOLD
            << " copies sold, and " << OPTION3_ROYALTY_PERCENT_ABOVE_THRESHOLD
            << "% for copies sold beyond that." << endl;
        cout << "## 	Estimated total payout: $" << option3_totalPayout << "." << endl;

		string bestOptionMessage = "\n## The best option is: ";
        if (option1_totalPayout > option2_totalPayout && option1_totalPayout > option3_totalPayout)
        {
			bestOptionMessage += "Option 1.";
        }
        else if (option2_totalPayout > option1_totalPayout && option2_totalPayout > option3_totalPayout)
        {
            bestOptionMessage += "Option 2.";
        }
        else if (option3_totalPayout > option1_totalPayout && option3_totalPayout > option2_totalPayout)
        {
            bestOptionMessage += "Option 3.";
        }
        else
        {
			bestOptionMessage += "There is a tie between the options.";
		}
        
		cout << bestOptionMessage << endl;

        // Ask if user wants to continue
        char userChoice;
        bool validInput;
        do
        {
            cout << "\nDo you want to perform another calculation? (Y/N): ";
            cin >> userChoice;
            validInput = true;

            string feedbackMessage;

            switch (userChoice)
            {
            case 'Y':
            case 'y':
                feedbackMessage = "Prepare your numbers for another calculation!\n";
                continueCalculations = true;
                break;
            case 'N':
            case 'n':
                feedbackMessage = "Goodbye!\n";
                continueCalculations = false;
                break;
            default:
                feedbackMessage = "Invalid entry! Please enter Y or N.\n";
                validInput = false;
                break;
            }

            cout << feedbackMessage;

        } while (!validInput);

    } while (continueCalculations);

    return 0;
}