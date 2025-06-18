#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H
#include"Account.h"
#include <iostream>
#include <vector>
#include <iomanip> // Added for setw()
#include <cstdlib> // Added for rand()
#include <ctime>   // Added for time()
#include <string>  // Added for string()
#include <limits>
using namespace std;
class Savings_Account : public Account
{
public:
    Savings_Account(string name, double openingBalance)
    {
        accountHolderName = name;
        interestRate = 0.08;
        minimumBalance = 5000;
        accountBalance = openingBalance;
        accountType = 1;
        accountNumber = 100000 + rand() % 500000;
    }

    void withdraw() override
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
            cout << "!!! Insufficient Funds !!!" << endl;
            cout << left << setw(35) << "Current Balance:" << fixed << setprecision(2) << accountBalance << endl;
            cout << left << setw(35) << "Minimum Balance Required:" << minimumBalance << endl;
            cout << left << setw(35) << "Maximum Withdrawal:" << (accountBalance - minimumBalance) << endl;
            return;
        }

        accountBalance -= amount;
        cout << "Amount Withdrawn Successfully." << endl;
        cout << left << setw(35) << "Remaining Balance:" << fixed << setprecision(2) << accountBalance << endl;
    }
    string getAccountType() const override
    {
        return "Savings";
    }
};
#endif