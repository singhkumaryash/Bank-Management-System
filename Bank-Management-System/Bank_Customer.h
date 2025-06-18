#ifndef BANK_CUSTOMER_H
#define BANK_CUSTOMER_H
#include "Bank_Operations.h"
#include <iostream>
#include <vector>
#include <iomanip> // Added for setw()
#include <cstdlib> // Added for rand()
#include <ctime>   // Added for time()
#include <string>  // Added for string()
#include <limits>
using namespace std;
class Bank_Customer : public Bank_Operations
{
public:
    void menu()
    {
        int choice;
        do
        {
            cout << "\n=== CUSTOMER ===" << endl;
            cout << "1. Open New Account" << endl;
            cout << "2. Withdraw" << endl;
            cout << "3. Deposit" << endl;
            cout << "4. Display Account Details" << endl;
            cout << "5. Close Account" << endl;
            cout << "6. Exit" << endl;
            cout << left << setw(35) << "Enter your choice:";

            while (!(cin >> choice) || choice < 1 || choice > 6) // Fixed range check
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid choice! Enter a number between 1-6: ";
            }

            switch (choice)
            {
            case 1:
                openAccount();
                break;
            case 2:
                withdraw();
                break;
            case 3:
                deposit();
                break;
            case 4:
                displayAccountDetails();
                break;
            case 5:
                closeAccount();
                break;
            case 6:
                cout << "Thank you for using our Banking System!" << endl;
                cout << "!!!Exited!!!" << endl;
                break;
            }

        } while (choice != 6);
    }
};
#endif