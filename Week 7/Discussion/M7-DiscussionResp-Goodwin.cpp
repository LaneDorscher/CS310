/*
* Student Name: Dalton Goodwin
* File Name: Week7_Discussion
* Date: 4/27/2026
* 
* Editor Name: Lane Dorscher
* Edited Date: 04/30/2026
* Editor Note: 
*       
* 
*/


#include <iostream>
using namespace std;

int main() {

    //create a 2d array to store latency test results
    //each row represents a different network device
    //each column represents a different ping test
    int latencyResults[3][4] = {
        {24, 30, 28, 35},
        {40, 42, 39, 45},
        {18, 20, 22, 19}
    }; //editor note: Added missing semicolon to initialize statement

    //show the heading for the report
    cout << "Network Latency Report" << endl;
    cout << "----------------------" << endl;

    //move through each device in the array
    for (int device = 0; device < 3; device++) {

        //display which device is being checked
        cout << "Device " << device + 1 << ":" << endl;

        //move through each latency test for the current device
        for (int test = 0; test < 4; test++) { //editor note: corrected the condition to check if test is less than 4 as we start at 0 and the last index is 3.

            //print the ping test number and latency value
            cout << "Ping test " << test + 1 << ": "
                 << latencyResults[device][test] << " ms" << endl;
        }

        //add a blank line after each device
        cout << endl;
    }

    //store the status of one test result
    //latencyResults[1][2] = "timeout"; //editor note: commented out line as A) we can't assign a string into a numeric array and B) it serves no purpose at the end of the program.

    //finish the program
    return 0;
}
