/*
   Author:         Lane Dorscher
   Date:           05/08/2026
   Assignment:     Chapter 10 Programming Exercise 21

   Description:
   This program implements a simple bank account system using a BankAccount class.
   Each account stores the account holder's name, automatically generated account number,
   account type (checking/saving), balance, and interest rate (stored as a decimal).

*/


#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/* declaration .h*/

enum AccountType { Checking, Saving };

class BankAccount {
	static int nextAccountNumber;   // shared across all accounts

private:
	string accountHolder;
	int accountNumber;
	AccountType accountType;
	double accountBalance;
	double interestRate;

public:
	BankAccount();
	BankAccount(string name, AccountType type, double balance, double interestPercent);

	// Getters
	string GetAccountHolder() const;
	int GetAccountNumber() const;
	AccountType GetAccountType() const;
	double GetAccountBalance() const;
	double GetInterestRate() const;

	// Setters
	void SetAccountHolder(const string& name);
	void SetAccountType(AccountType type);
	void SetAccountBalance(double balance);
	void SetInterestRate(double rateAsWholePercent);
};

string PromptAccountHolderName();
AccountType PromptAccountType();
double PromptAccountBalance();
double PromptAccountInterestRate();
bool EndProgram();
void DisplayAccounts(const BankAccount accounts[], int count);
void PrintWelcomeMessage();
void PrintGoodbyeMessage();

int main()
{
	//print header

	BankAccount accounts[10];
	int accountCount = 0;

	//prepopulate some data
	accounts[0] = BankAccount("Alice Johnson", Checking, 1200.50, 3.5);
	accounts[1] = BankAccount("Bob Smith", Saving, 5400.00, 4.0);
	accounts[2] = BankAccount("Charlie Brown", Checking, 250.75, 1.5);
	accounts[3] = BankAccount("Dana White", Saving, 9800.00, 5.0);
	accounts[4] = BankAccount("Evan Lee", Checking, 300.00, 2.0);
	accountCount = 5;

	PrintWelcomeMessage();

	while (accountCount < 10)
	{
		//check if we want to add more 
		if (EndProgram())
			break;

		//get account details (name, type, balance, interest rate, etc)
		BankAccount account = BankAccount();

		account.SetAccountHolder(PromptAccountHolderName());
		account.SetAccountType(PromptAccountType());
		account.SetAccountBalance(PromptAccountBalance());
		account.SetInterestRate(PromptAccountInterestRate());

		//add details
		accounts[accountCount] = account;
		accountCount++;
	}

	//display accounts
	DisplayAccounts(accounts, accountCount);
	//print goodbye
	PrintGoodbyeMessage();
	cin.get();
	return 0;
}


/* implementation*/
string PromptAccountHolderName()
{
	string name;

	cout << "Enter account holder name: ";
	getline(cin >> ws, name); // <-- KEY FIX

	while (name.empty())
	{
		cout << "Name cannot be empty. Try again: ";
		getline(cin >> ws, name);
	}

	return name;
}

double PromptAccountBalance()
{
	while (true)
	{
		cout << "Enter starting balance: ";
		double balance;
		cin >> balance;

		if (balance < 0.0)
		{
			cout << "Balance must be a non-negative number.\n";
			continue;
		}
		return balance;
	}
}

double PromptAccountInterestRate()
{
	while (true)
	{
		cout << "Enter interest rate (whole percent, e.g. 5 for 5%): ";
		double rate;
		cin >> rate;

		if (rate < 0.0 || rate > 100.0)
		{
			cout << "Interest rate must be between 0 and 100.\n";
			continue;
		}

		return rate;
	}
}

AccountType PromptAccountType()
{
	while (true)
	{
		cout << "Enter account type (1 = Checking, 2 = Saving): ";
		int choice;
		cin >> choice;

		if (choice != 1 && choice != 2)
		{
			cout << "Invalid selection.\n";
			continue;
		}

		return (choice == 1) ? Checking : Saving;
	}
}



bool EndProgram()
{
	while (true)
	{
		std::cout << "Add another account? (Y/N): ";

		char choice;
		std::cin >> choice;

		choice = tolower(choice);

		if (choice == 'y')
			return false;   // continue program

		if (choice == 'n')
			return true;    // end program

		std::cout << "Invalid input. Please enter Y or N.\n";
	}
}

void DisplayAccounts(const BankAccount accounts[], int count)
{
	cout << "\n===== BANK ACCOUNTS =====\n\n";

	cout << left
		<< setw(10) << "Acct#"
		<< setw(20) << "Name"
		<< setw(12) << "Type"
		<< setw(15) << "Balance"
		<< setw(10) << "Interest"
		<< endl;

	cout << string(70, '-') << endl;

	for (int i = 0; i < count; i++)
	{
		string typeStr = (accounts[i].GetAccountType() == Checking)
			? "Checking"
			: "Saving";

		cout << left
			<< setw(10) << accounts[i].GetAccountNumber()
			<< setw(20) << accounts[i].GetAccountHolder()
			<< setw(12) << typeStr
			<< "$" << setw(14) << fixed << setprecision(2)
			<< accounts[i].GetAccountBalance()
			<< setw(10) << (accounts[i].GetInterestRate() * 100)
			<< endl;
	}

	cout << "\n==========================\n";
}

void PrintWelcomeMessage()
{
	cout << "=====================================\n";
	cout << "      BANK ACCOUNT SYSTEM\n";
	cout << "=====================================\n\n";
}

void PrintGoodbyeMessage()
{
	cout << "\n=====================================\n";
	cout << "   Thank you for using the system\n";
	cout << "             Goodbye!\n";
	cout << "=====================================\n";
}
/* BankAccount Class */

int BankAccount::nextAccountNumber = 1000; // starting value

BankAccount::BankAccount()
	: accountHolder("Unknown"),
	accountNumber(nextAccountNumber++),
	accountType(Checking),
	accountBalance(0.0),
	interestRate(0.0)
{
}

BankAccount::BankAccount(string name,
	AccountType type,
	double balance,
	double interestPercent)
	: accountHolder(name),
	accountNumber(nextAccountNumber++),
	accountType(type),
	accountBalance(balance),
	interestRate(0.0)
{
	SetInterestRate(interestPercent);
}

string BankAccount::GetAccountHolder() const
{
	return accountHolder;
}

int BankAccount::GetAccountNumber() const
{
	return accountNumber;
}

AccountType BankAccount::GetAccountType() const
{
	return accountType;
}

double BankAccount::GetAccountBalance() const
{
	return accountBalance;
}

double BankAccount::GetInterestRate() const
{
	return interestRate;
}

void BankAccount::SetAccountHolder(const string& name)
{
	accountHolder = name;
}

void BankAccount::SetAccountType(AccountType type)
{
	accountType = type;
}

void BankAccount::SetAccountBalance(double balance)
{
	accountBalance = balance;
}

void BankAccount::SetInterestRate(double rateAsWholePercent)
{
	interestRate = rateAsWholePercent / 100.0;
}

/* End BankAccount class*/