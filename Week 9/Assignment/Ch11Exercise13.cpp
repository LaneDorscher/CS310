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

class BankAccount {
	public:
		static int nextAccountNumber;   // shared across all accounts

protected:
	string accountHolder;
	int accountNumber;
	double balance;

public:
	BankAccount() :
		accountHolder(""), balance(0.0), accountNumber(0) {
	};
	BankAccount(string aHolder, double aBalance) :
		accountHolder(aHolder), 
		balance(aBalance >= 0.0 ? aBalance : 0.0),
		accountNumber(nextAccountNumber++) {

	};

	virtual ~BankAccount() = default;

	//Deposit money, return true if successful, false if failed
	virtual bool Deposit(double amount) { 
		if (amount > 0.0)
		{
			balance += amount;
			return true;
		}
		cout << "Deposit amount must be positive" << endl;
		return false;
	}

	// Withdraw money, return true if successful, false if failed.
	virtual bool Withdraw(double amount)
	{
		if (amount > 0 && amount <= balance)
		{
			balance -= amount;
			return true;
		}
		cout << "Invalid withdraw amount or insufficient funds" << endl;
		return false;
	}

	// Print account information
	void PrintAccountInfo() const {
		cout << "Account Holder: " << accountHolder << endl;
		cout << "Account Number: " << accountNumber << endl;
		cout << "Balance: $" << balance << endl;
	}

	// Set account number
	void SetAccountNumber(int accNum) {
		accountNumber = accNum;
	}

	// Get account number
	int GetAccountNumber() const {
		return accountNumber;
	}

	// Get balance
	double GetBalance() const {
		return balance;
	}

};

class CheckingAccount : public BankAccount {
private:
	double interestRate;       // annual interest rate (e.g., 0.02 for 2%)
	double minimumBalance;
	double serviceCharge;

public:
	// Default constructor
	CheckingAccount()
		: BankAccount(),
		interestRate(0.0),
		minimumBalance(0.0),
		serviceCharge(0.0) {
	}

	// Parameterized constructor
	CheckingAccount(string aHolder, double aBalance,
		double iRate, double minBal, double sCharge)
		: BankAccount(aHolder, aBalance),
		interestRate(iRate),
		minimumBalance(minBal),
		serviceCharge(sCharge) {
	}

	// Set / Get interest rate
	void SetInterestRate(double rate) {
		interestRate = (rate >= 0.0) ? rate : 0.0;
	}

	double GetInterestRate() const {
		return interestRate;
	}

	// Set / Get minimum balance
	void SetMinimumBalance(double minBal) {
		minimumBalance = (minBal >= 0.0) ? minBal : 0.0;
	}

	double GetMinimumBalance() const {
		return minimumBalance;
	}

	// Set / Get service charge
	void SetServiceCharge(double charge) {
		serviceCharge = (charge >= 0.0) ? charge : 0.0;
	}

	double GetServiceCharge() const {
		return serviceCharge;
	}

	// Check if balance is below minimum
	bool IsBelowMinimum() const {
		return GetBalance() < minimumBalance;
	}

	// Post interest to account
	void PostInterest() {
		double interest = GetBalance() * interestRate;
		Deposit(interest);
	}

	// Write a check (treated like withdrawal)
	bool WriteCheck(double amount) {
		return Withdraw(amount);
	}

	// Override Withdraw to include service charge logic
	bool Withdraw(double amount) override {
		bool success = BankAccount::Withdraw(amount);

		if (!success) {
			return false;
		}

		// Apply service charge if balance falls below minimum
		if (GetBalance() < minimumBalance) {
			cout << "Balance below minimum. Service charge applied: $"
				<< serviceCharge << endl;

			BankAccount::Withdraw(serviceCharge);
		}

		return true;
	}

	// Print account information (extended version)
	void PrintAccountInfo() const {
		BankAccount::PrintAccountInfo();

		cout << "Interest Rate: " << interestRate << endl;
		cout << "Minimum Balance: $" << minimumBalance << endl;
		cout << "Service Charge: $" << serviceCharge << endl;

		if (IsBelowMinimum()) {
			cout << "Status: BELOW MINIMUM BALANCE" << endl;
		}
		else {
			cout << "Status: OK" << endl;
		}
	}
};

class SavingsAccount : public BankAccount {
private:
	double InterestRate;

public:
	// Default constructor
	SavingsAccount()
		: BankAccount(), InterestRate(0.0) {
	}

	// Parameterized constructor
	SavingsAccount(string AccountHolder, double AccountBalance, double Rate)
		: BankAccount(AccountHolder, AccountBalance),
		InterestRate(Rate >= 0.0 ? Rate : 0.0) {
	}

	// Set interest rate
	void SetInterestRate(double Rate) {
		InterestRate = (Rate >= 0.0) ? Rate : 0.0;
	}

	// Get interest rate
	double GetInterestRate() const {
		return InterestRate;
	}

	// Post interest to account
	void PostInterest() {
		double Interest = GetBalance() * InterestRate;
		Deposit(Interest);
	}

	// Override Withdraw method
	bool Withdraw(double Amount) override {
		if (Amount > 0 && Amount <= GetBalance()) {
			return BankAccount::Withdraw(Amount);
		}
		else {
			cout << "Invalid withdraw amount or insufficient funds." << endl;
			return false;
		}
	}

	// Print account information
	void PrintAccountInfo() const {
		BankAccount::PrintAccountInfo();
		cout << "Interest Rate: " << InterestRate << endl;
	}
};

int BankAccount::nextAccountNumber = 1000;

int main()
{
	cout << "===============================" << endl;
	cout << "   BANK ACCOUNT TEST PROGRAM   " << endl;
	cout << "===============================" << endl;

	// Savings Account Tests
	cout << "\n\\-\\-\\-\\- Savings Account Test -/-/-/-/" << endl;

	SavingsAccount savings("Dwayne \"The Rock\" Johnson", 1000.00, 0.05);

	savings.PrintAccountInfo();

	cout << "\nDepositing $500..." << endl;
	savings.Deposit(500.00);

	cout << "Withdrawing $200..." << endl;
	savings.Withdraw(200.00);

	cout << "Posting interest..." << endl;
	savings.PostInterest();

	cout << "\nUpdated Savings Account Info:" << endl;
	savings.PrintAccountInfo();


	// Checking Account Tests
	cout << "\n\\-\\-\\-\\- Checking Account Test -/-/-/-/" << endl;

	CheckingAccount checking("Rubber Ducky", 1200.00, 0.03, 500.00, 25.00);

	checking.PrintAccountInfo();

	cout << "\nDepositing $300..." << endl;
	checking.Deposit(300.00);

	cout << "Writing a check for $1000..." << endl;
	checking.WriteCheck(1000.00);

	cout << "Withdrawing $200..." << endl;
	checking.Withdraw(200.00);

	cout << "Posting interest..." << endl;
	checking.PostInterest();

	cout << "\nUpdated Checking Account Info:" << endl;
	checking.PrintAccountInfo();


	// Edge Case Tests
	cout << "\n\\-\\-\\-\\- Edge Case Test -/-/-/-/" << endl;
	cout << "Attempt invalid deposit (-50): " << endl;
	savings.Deposit(-50);

	cout << "Attempt invalid withdrawal (too large): " << endl;
	checking.Withdraw(100000);

	cin.get();	
	return 0;
}
