#ifndef ACCOUNT_H
#define ACCOUNT_H
#include"Account.h"
#include <iostream>
#include <vector>
#include <iomanip> // Added for setw()
#include <cstdlib> // Added for rand()
#include <ctime>   // Added for time()
#include <string>  // Added for string()
#include <limits>
using namespace std;
class Account
{
protected:
    string accountHolderName;
    int accountNumber;
    double interestRate;
    double minimumBalance;
    double accountBalance;
    bool accountType;

public:
    virtual void deposit()
    {
        double amount;
        cout << left << setw(35) << "Enter the Deposit Amount:";

        while (!(cin >> amount) || amount <= 0)
        {
            cin.clear();                                         // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid amount! Enter a positive number: ";
        }

        accountBalance += amount;
        cout << "Amount Deposited Successfully." << endl;
        cout << left << setw(35) << "New Balance:" << fixed << setprecision(2) << accountBalance << endl;
    }

    virtual void withdraw()
    {
        double amount;
        cout << left << setw(35) << "Enter the Withdraw Amount:";

        while (!(cin >> amount) || amount <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid amount! Enter a positive number: ";
        }

        if (accountBalance - amount < minimumBalance)
        {
            cout << "!!! Insufficient Balance or Invalid Amount !!!" << endl;
            cout << left << setw(35) << "Current Balance:" << fixed << setprecision(2) << accountBalance << endl;
            cout << left << setw(35) << "Minimum Balance:" << minimumBalance << endl;
            return;
        }

        accountBalance -= amount;
        cout << "Amount Withdrawn Successfully." << endl;
        cout << left << setw(35) << "Remaining Balance:" << fixed << setprecision(2) << accountBalance << endl;
    }

    virtual void displayAccount()
    {
        cout << "\n---- Account Details ----" << endl;
        cout << fixed << setprecision(2);
        cout << left << setw(35) << "Name:" << accountHolderName << endl;
        cout << left << setw(35) << "Account No:" << accountNumber << endl;
        cout << left << setw(35) << "Balance:" << accountBalance << endl;
        cout << left << setw(35) << "Minimum Balance:" << minimumBalance << endl;
        cout << left << setw(35) << "Interest Rate:" << (interestRate * 100) << "%" << endl;
        cout << left << setw(35) << "Account Type:" << (accountType ? "Savings" : "Current") << endl;
    }

    int getAccountNumber() const
    {
        return accountNumber;
    }

    double getAccountBalance() const
    {
        return accountBalance;
    }
    string getAccountHolderName() const
    {
        return accountHolderName;
    }
    virtual string getAccountType() const = 0;

    virtual ~Account() = default;
};
#endif