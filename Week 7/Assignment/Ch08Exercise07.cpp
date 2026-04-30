/* Author: Lane Dorscher
 * Date: 04/29/2026
 * File name: Ch08Exercise07.cpp
 * Program Description: 
 * Assignment: 
	Source: chapter 8, programming exercise 7
	Write a program that allows the user to enter the last names of five candidates in a local election and the number of 
	votes received by each candidate. The program should then output each candidate’s name, the number of votes received, 
	and the percentage of the total votes received by the candidate. Your program should also output the winner of the election.

  Author Notes: 
	const is used to prevent modification inside functions that should only read the data. 
	References are used for scalar values that must be modified by the function
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;
const int NUM_OF_CANDIDATES = 5;

// Prints the welcome message
void PrintWelcome();
// Tallies votes for a fixed set of candidates: computes the total number of votes and populates each candidate's vote ratio.
void TallyCandidateInfo(string  candidateNames[NUM_OF_CANDIDATES],
	int  candidateVotes[NUM_OF_CANDIDATES], 
	float candidatesRatio[NUM_OF_CANDIDATES],
	int& totalVotes,
	int& winnerIndex);
// Gets the candidate info from the user
void GetCandidateInfo(string& lastName, int& numOfVotes);
// Gets the percentage of votes the candidate received from the total votes collected
void CalculateRatios(int candidateVotes[NUM_OF_CANDIDATES], float candidatesRatio[NUM_OF_CANDIDATES], const int totalVotes);
// Prints the election results
void PrintResults(string candidateNames[NUM_OF_CANDIDATES], 
	int candidateVotes[NUM_OF_CANDIDATES], 
	float candidatesRatio[NUM_OF_CANDIDATES], 
	const int totalVotes, const int winnerIndex);

int main()
{
	string candidateNames[NUM_OF_CANDIDATES];
	int candidateVotes[NUM_OF_CANDIDATES];
	float candidateRatios[NUM_OF_CANDIDATES];
	int totalVotes = 0;
	int winnerIndex = 0;

	PrintWelcome();

	TallyCandidateInfo(candidateNames, candidateVotes, candidateRatios, totalVotes, winnerIndex);

	PrintResults(candidateNames, candidateVotes, candidateRatios, totalVotes, winnerIndex);

	cout << "Press Enter to exit...";
	cin.get();
	return 0;
}

void TallyCandidateInfo(string candidateNames[NUM_OF_CANDIDATES], int candidateVotes[NUM_OF_CANDIDATES], float candidatesRatio[NUM_OF_CANDIDATES], int& totalVotes, int& winnerIndex)
{
	//for every number of candidate, get the last name and votes cast
	for (int i = 0; i < NUM_OF_CANDIDATES; ++i)
	{
		GetCandidateInfo(candidateNames[i], candidateVotes[i]);
		totalVotes += candidateVotes[i];

		if (i == 0 || candidateVotes[i] > candidateVotes[winnerIndex])
			winnerIndex = i;
	}
	CalculateRatios(candidateVotes, candidatesRatio, totalVotes);

}

void PrintWelcome()
{
	cout << "Welcome to the election program!" << endl;
	cout << "Please enter the last name and number of votes for each candidate." << endl << endl;
}

void GetCandidateInfo(std::string& lastName, int& numOfVotes)
{
	cout << "Enter candidate's last name: ";
	cin >> lastName;
	while (true)
	{
		cout << "Enter number of votes for " << lastName << " (positive integer): ";
		cin >> numOfVotes;
		if (numOfVotes >= 0)
		{
			//valid
			break;
		}
		cout << endl << "Votes cannot be negative!" << endl;
	}
	
	cout << endl;
}


void CalculateRatios(int candidateVotes[NUM_OF_CANDIDATES], 
	float candidatesRatio[NUM_OF_CANDIDATES], 
	const int totalVotes)
{
	for (int i = 0; i < NUM_OF_CANDIDATES; ++i)
	{
		candidatesRatio[i] = static_cast<float>(candidateVotes[i]) / totalVotes;
	}
}

void PrintResults(string candidateNames[NUM_OF_CANDIDATES], 
	int candidateVotes[NUM_OF_CANDIDATES], 
	float candidatesRatio[NUM_OF_CANDIDATES], 
	const int totalVotes, 
	const int winnerIndex)
{
	const int nameWidth = 20;
	const int votesWidth = 10;
	const int percentWidth = 12;
	const string dividerLineStr = string(nameWidth + votesWidth + percentWidth, '-');

	cout << "\nElection Results:\n\n";

	// Header
	cout << left << setw(nameWidth) << "Candidate"
      << right << setw(votesWidth) << "Votes"
      << setw(percentWidth) << "Percentage" << '\n';

	// Divider line
	cout << dividerLineStr << '\n';
	for (int i = 0; i < NUM_OF_CANDIDATES; ++i)
	{
		cout << left << setw(nameWidth) << candidateNames[i];
		cout << right << setw(votesWidth) << candidateVotes[i];
		float pct = candidatesRatio[i] * 100.0f;
		ostringstream oss;
		oss << fixed << setprecision(2) << pct << '%';
		string pctStr = oss.str();
		cout << setw(percentWidth) << pctStr << '\n';
	}

	// Divider
	cout << dividerLineStr << '\n';
	cout << endl;

	// Total line
	cout << left << setw(nameWidth) << "Total Votes" << right << setw(votesWidth) << totalVotes << '\n';
	//Winner line
	cout << endl << "The Winner of the Election is " << candidateNames[winnerIndex] << "!" << endl;
}