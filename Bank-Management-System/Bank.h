#ifndef BANK_H
#define BANK_H
#include "Bank_Customer.h"
#include "Bank_Employee.h"
#include"Bank_Operations.h"
#include <iostream>
#include <vector>
#include <iomanip> // Added for setw()
#include <cstdlib> // Added for rand()
#include <ctime>   // Added for time()
#include <string>  // Added for string()
#include <limits>
using namespace std;
class Bank
{
    Bank_Employee employee;
    Bank_Customer customer;

public:
    Bank()
    {
        srand(time(0));

        int choice;
        cout << "\n=== BANK MANAGEMENT SYSTEM ===" << endl;
        cout << "\n1. Customer" << "\n2. Employee" << "\nEnter User Type:";
        cin >> choice;

        if (choice == 1)
        {
            customer.menu();
        }
        else if (choice == 2)
        {
            employee.menu();
        }
        else
        {
            cout << "!!!Invalid Choice!!!" << endl;
        }
    }
};
#endif