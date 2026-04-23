/* Author: Lane Dorscher 
 * Date: 04/22/2026
 * File: Ch07Exercise04.cpp
 * Description: This program prompts the user to enter a string, removes all the vowels from the string, and then displays the modified string. The program defines three functions: GetUserInput() to get input from the user, RemoveVowels() to remove vowels from the string, and IsVowel() to check if a character is a vowel. The main function orchestrates the flow of the program by calling these functions in sequence.
 * 
 * Program Assignment: Source: chapter 7, programming exercise 4
 * Write a program that prompts the user to input a string. The program then uses the function substr to remove all the vowels from the string. For example, if str = "There", then after removing all the vowels, str = "Thr".
 * After removing all the vowels, output the string. Your program must contain a function to remove all the vowels and a function to determine whether a character is a vowel.
 */

#include <iostream>
#include <string>
#include <cctype>   // for toupper() function
using namespace std;

string GetUserInput();
string RemoveVowels(string str);
bool IsVowel(char character, bool includeY = false);

int main()
{
    string userInput = GetUserInput();
    userInput = RemoveVowels(userInput);

    cout << "String after removing vowels: " << userInput << endl;
    return 0;
}

// Prompt the user to enter a string and return the input string.
string GetUserInput()
{
    string value;
    cout << "Please enter a string: ";
    getline(cin, value);
    cout << endl;
    return value;	
}

// Remove all the vowels from the input string and return the modified string.
string RemoveVowels(string str)
{
    string result = "";

    for (int i = 0; i < str.length(); i++)
    {
        if (!IsVowel(str[i]))
        {
            result += str.substr(i, 1);
        }
    }

    return result;
}

// Check if a character is a vowel. If includeY is true, then 'Y' is also considered a vowel.
bool IsVowel(char c, bool includeY)
{
    c = static_cast<char>(
        toupper(static_cast<unsigned char>(c))
    );

    switch (c)
    {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return true;
        case 'Y': //not utilized in this program, but included for completeness
            return includeY;
        default:
            return false;		
    }	
}