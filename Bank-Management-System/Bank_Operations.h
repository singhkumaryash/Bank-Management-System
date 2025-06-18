#ifndef BANK_OPERATIONS_H
#define BANK_OPERATIONS_H
#include "Account.h"
#include "Savings_Account.h"
#include "Current_Account.h"
#include <iostream>
#include <vector>
#include <iomanip> // Added for setw()
#include <cstdlib> // Added for rand()
#include <ctime>   // Added for time()
#include <string>  // Added for string()
#include <limits>
using namespace std;
class Bank_Operations
{
    vector<Account *> accounts;

public:
    void openAccount()
    {
        int type;
        string name;
        double openingBalance;

        cout << "\n--- Open New Account ---" << endl;
        cout << "Enter Account Type:" << endl
             << "1. Savings (8% Interest)" << endl
             << "2. Current (Overdraft Available)" << endl;
        cout << left << setw(35) << "Choice:";

        while (!(cin >> type) || (type != 1 && type != 2))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice! Enter 1 or 2: ";
        }

        cin.ignore();
        cout << left << setw(35) << "Enter Account Holder Name:";
        getline(cin, name);

        while (name.empty())
        {
            cout << "Name cannot be empty! Enter a valid name: ";
            getline(cin, name);
        }

        cout << left << setw(35) << "Enter Opening Balance:";
        while (!(cin >> openingBalance) || openingBalance < 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid amount! Enter a valid balance: ";
        }

        Account *newAccount = nullptr;

        if (type == 1)
        {
            if (openingBalance < 5000)
            {
                cout << "!!! Opening balance must be at least 5000 for Savings Account !!!" << endl;
                return;
            }
            newAccount = new Savings_Account(name, openingBalance);
        }
        else if (type == 2)
        {
            if (openingBalance < 5000)
            {
                cout << "!!! Opening balance must be at least 5000 for Current Account !!!" << endl;
                return;
            }
            newAccount = new Current_Account(name, openingBalance);
        }

        accounts.push_back(newAccount);
        cout << "Account Opened Successfully!" << endl;
        cout << left << setw(35) << "Account Number:" << newAccount->getAccountNumber() << endl;
        cout << left << setw(35) << "Account Holder:" << name << endl;
        cout << left << setw(35) << "Account Type:" << (type == 1 ? "Savings" : "Current") << endl;
        cout << left << setw(35) << "Opening Balance:" << fixed << setprecision(2) << openingBalance << endl;
    }

    void displayAllAccounts()
    {
        if (accounts.empty())
        {
            cout << "!!! No Accounts Found !!!" << endl;
            return;
        }

        cout << "\n--- All Accounts Summary ---" << endl;
        cout << left << setw(12) << "Acc. No."
             << setw(35) << "Name"
             << setw(35) << "Type"
             << setw(35) << "Balance" << endl;
        cout << string(60, '-') << endl;

        for (auto acc : accounts)
        {
            cout << left << setw(35) << acc->getAccountNumber()
                 << setw(35) << acc->getAccountHolderName()
                 << setw(35) << (acc->getAccountType())
                 << fixed << setprecision(2) << acc->getAccountBalance() << endl;
        }
        cout << string(60, '-') << endl;
        cout << left << setw(35) << "Total Accounts:" << accounts.size() << endl;
    }

    void displayAccountDetails()
    {
        if (accounts.empty())
        {
            cout << "!!! No Accounts Found !!!" << endl;
            return;
        }

        int accNum;
        cout << left << setw(35) << "Enter Account Number to Display:";

        while (!(cin >> accNum))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid account number! Enter a valid number: ";
        }

        Account *acc = findAccount(accNum);
        if (acc)
        {
            acc->displayAccount();
        }
        else
        {
            cout << "!!! Account Not Found !!!" << endl;
        }
    }

    Account *findAccount(int accNum)
    {
        for (auto acc : accounts)
        {
            if (acc->getAccountNumber() == accNum)
                return acc;
        }
        return nullptr;
    }

    void deposit()
    {
        if (accounts.empty())
        {
            cout << "!!! No Accounts Found !!!" << endl;
            return;
        }

        int accNum;
        cout << left << setw(35) << "Enter Account Number to Deposit:";

        while (!(cin >> accNum))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid account number! Enter a valid number: ";
        }

        Account *acc = findAccount(accNum);
        if (acc)
        {
            acc->deposit();
        }
        else
        {
            cout << "!!! Account Not Found !!!" << endl;
        }
    }

    void withdraw()
    {
        if (accounts.empty())
        {
            cout << "!!! No Accounts Found !!!" << endl;
            return;
        }

        int accNum;
        cout << left << setw(35) << "Enter Account Number to Withdraw:";

        while (!(cin >> accNum))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid account number! Enter a valid number: ";
        }

        Account *acc = findAccount(accNum);
        if (acc)
        {
            acc->withdraw();
        }
        else
        {
            cout << "!!! Account Not Found !!!" << endl;
        }
    }

    void closeAccount()
    {
        if (accounts.empty())
        {
            cout << "!!! No Accounts Found !!!" << endl;
            return;
        }

        int accNum;
        cout << left << setw(35) << "Enter Account Number to Close:";

        while (!(cin >> accNum))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid account number! Enter a valid number: ";
        }

        for (auto it = accounts.begin(); it != accounts.end(); ++it)
        {
            if ((*it)->getAccountNumber() == accNum)
            {
                cout << "Are you sure you want to close this account? (y/n): ";
                char confirm;
                cin >> confirm;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (confirm == 'y' || confirm == 'Y')
                {
                    delete *it;
                    accounts.erase(it);
                    cout << "Account Closed Successfully." << endl;
                }
                else
                {
                    cout << "Account closure cancelled." << endl;
                }
                return;
            }
        }
        cout << "!!! Account Not Found !!!" << endl;
    }

    ~Bank_Operations()
    {
        for (auto acc : accounts)
        {
            delete acc;
        }
    }
};
#endif