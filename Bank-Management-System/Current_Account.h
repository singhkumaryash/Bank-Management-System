#ifndef CURRENT_ACCOUNT_H
#define CURRENT_ACCOUNT_H
#include "Account.h"
#include <iostream>
#include <vector>
#include <iomanip> // Added for setw()
#include <cstdlib> // Added for rand()
#include <ctime>   // Added for time()
#include <string>  // Added for string()
#include <limits>
using namespace std;
class Current_Account : public Account
{
private:
    double overDraftLimit = 10000.00;
    double overDraftUsed = 0;

public:
    Current_Account(string name, double openingBalance)
    {
        accountHolderName = name;
        interestRate = 0.0;
        minimumBalance = 5000;
        accountBalance = openingBalance;
        accountType = 0;
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

        double availableFunds = accountBalance + (overDraftLimit - overDraftUsed);
        if (amount > availableFunds)
        {
            cout << "!!! Insufficient Funds (including overdraft limit) !!!" << endl;
            cout << left << setw(35) << "Available Balance:" << fixed << setprecision(2) << accountBalance << endl;
            cout << left << setw(35) << "Available Overdraft:" << (overDraftLimit - overDraftUsed) << endl;
            cout << left << setw(35) << "Total Available:" << availableFunds << endl;
            return;
        }

        if (accountBalance >= amount)
        {
            accountBalance -= amount;
        }
        else
        {
            double deficit = amount - accountBalance;
            accountBalance = 0;
            overDraftUsed += deficit;
        }
        cout << "Amount Withdrawn Successfully." << endl;
        cout << left << setw(35) << "Account Balance:" << fixed << setprecision(2) << accountBalance << endl;
        if (overDraftUsed > 0)
        {
            cout << left << setw(35) << "Overdraft Used:" << overDraftUsed << " / " << overDraftLimit << endl;
        }
    }

    void displayAccount() override
    {
        Account::displayAccount();
        cout << left << setw(35) << "Overdraft Limit:" << overDraftLimit << endl;
        cout << left << setw(35) << "Overdraft Used:" << overDraftUsed << endl;
        cout << left << setw(35) << "Available Overdraft:" << (overDraftLimit - overDraftUsed) << endl;
    }

    void deposit() override
    {
        double amount;
        cout << left << setw(35) << "Enter the Deposit Amount:";

        while (!(cin >> amount) || amount <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid amount! Enter a positive number: ";
        }

        if (overDraftUsed > 0)
        {
            if (amount >= overDraftUsed)
            {
                amount -= overDraftUsed;
                cout << left << setw(35) << "Overdraft Cleared:" << fixed << setprecision(2) << overDraftUsed << endl;
                overDraftUsed = 0;
                accountBalance += amount;
            }
            else
            {
                overDraftUsed -= amount;
                cout << left << setw(35) << "Overdraft Reduced by:" << fixed << setprecision(2) << amount << endl;
            }
        }
        else
        {
            accountBalance += amount;
        }

        cout << "Amount Deposited Successfully." << endl;
        cout << left << setw(35) << "Account Balance:" << fixed << setprecision(2) << accountBalance << endl;
        if (overDraftUsed > 0)
        {
            cout << left << setw(35) << "Remaining Overdraft:" << overDraftUsed << endl;
        }
    }
    string getAccountType() const override
    {
        return "Current";
    }
};
#endif