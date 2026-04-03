/************
Author: 			Lane Dorscher
Date: 				4/2/2026
Program-Name: 		M3-Discussion
Program-Description:
	Create a simple C++ program using selection control statements and at least two errors. 
	The program should not execute and there should be at least two errors in the code.


************/

#include <iostream>
#include <string>


int main()
{
    bool exitFlag = false;;
    int runCount = 0;
    std::string userInput;

    do
    {        
		std::cout << "Welcome to the program. I'll count how many times you press the enter key!" << std::endl;
        std::cout << "Press ENTER to continue or type EXIT to quit:" << std::endl;

        std::getline(std::cin, userInput);

        if (userInput == "EXIT")
            exitFlag = true;
            std::cout << "Aww :( goodbye friend!" << std::endl;
        else
        {
            runCount++;
            std::cout << "Enter pressed " << runCount << " times!" << endl;
        }

    } while (!exitFlag);

    return 0;
}

























}