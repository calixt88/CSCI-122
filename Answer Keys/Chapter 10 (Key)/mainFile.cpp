//Programmer:   Student Name
//Date:         Current Date
//Assignment:   Chapter 10, Exercise 21, Page 741
//Description:  Program description listed in the book
//              Main program

#include <iostream>
#include <iomanip>
#include <windows.h>
#include "bankAccount.h"

using namespace std;

//function prototypes
void menu();
void subMenu();
int search(bankAccount list[], int length, int acctNum);
void addCustomer(bankAccount list[], int& length);
void processCustomer(bankAccount list[], int length, int acctNum);
void printCustomersData(bankAccount list[], int length);

//global
string hyphens = "";
HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
    //declare and inititalize local array and variables
    bankAccount customersList[10];
    int choice = 0;
    int numOfCustomer = 0;
    int acctNumber = 0;
    char discard = ' ';
    hyphens.assign(35, '-');

     cout << fixed << showpoint << setprecision(2);

     menu();
     cin >> choice;
     cin.get(discard);
     cout << endl;

    while (choice != 9)
    {
        switch (choice)
        {
        case 1:
            if (numOfCustomer < 10)
                addCustomer(customersList, numOfCustomer);
            else
                cout << "Cannot add any New Customers (the list is full)" << endl;
            break;
        case 2:
            SetConsoleTextAttribute(screen, 10);
            cout << "Enter Customer's Account Number: ";
            cin >> acctNumber;
            cout << endl;

            processCustomer(customersList, numOfCustomer, acctNumber);
            cout << "Account Number: " << acctNumber << endl;
            break;

        case 3:
            printCustomersData(customersList, numOfCustomer);
            break;

        default:
            cout << "Invalid choice." << endl;
        }

        menu();
        cin >> choice;
        cin.get(discard);
        cout << endl;
    }
        SetConsoleTextAttribute(screen, 7);

     return 0;
}

void menu()
{
    system("cls");
    SetConsoleTextAttribute(screen, 9);
    cout << hyphens << endl;
    cout << "-     Bank Account Main Menu      -" << endl;
    cout << hyphens << endl;
    cout << "1: Enter 1 to add a new customer" << endl;
    cout << "2: Enter 2 for an existing customer" << endl;
    cout << "3: Enter 3 to print customers data" << endl;
    cout << "9: Enter 9 to exit the program" << endl << endl;
    cout << "Please enter a menu option: ";
}

void subMenu()
{
    system("cls");
    SetConsoleTextAttribute(screen, 10);
    cout << hyphens << endl;
    cout << "Bank Account SubMenu" << endl;
    cout << hyphens << endl;
    cout << "1: Enter 1 to make a deposit" << endl;
    cout << "2: Enter 2 to withdraw" << endl;
    cout << "3: Enter 3 to check balance" << endl;
    cout << "9: Enter 9 to return to the Main Menu" << endl << endl;
    cout << "Please enter a submenu option: ";
}

int search(bankAccount list[], int length, int acctNum)
{
    for (int i = 0; i < length; i++)
        if (list[i].getAccountNumber() == acctNum)
            return i;
        
    return -1;
}

void addCustomer(bankAccount list[], int& length)
{
    string name = "";
    string acctType = "";
    char acctTypeChar = ' ';
    int acctNum = 0;
    double deposit = 0.0;
    double interestRate = 0.0;

    if (length < 10)
    {
        cout << "Enter the Customer's Name:                     ";
        getline(cin, name);

        cout << "Enter Account Type (C)hecking or (S)avings):   ";
        cin >> acctTypeChar; 
        
        cout << "Enter amount to be Deposited to Open Account:  ";
        cin >> deposit;

        cout << "Enter Interest Rate (as a percent):            ";
        cin >> interestRate;
        cout << endl;

        acctTypeChar = toupper(acctTypeChar);

        if (acctTypeChar == 'C')
        {
            acctType = "Checking";
        }
        else
        {
            acctType = "Savings";
        }

        list[length++].setdata(name, acctType, acctNum, deposit, interestRate);
    }
    else
        cout << "Customers' list is full. Cannot add another customer." << endl;

    cout << "Press any key to return to the Main Menu... ";
    system("pause>nul");
    cout << endl;
}

void processCustomer(bankAccount list[], int length, int acctNum)
{
    int index;
    double amount;

    index = search(list, length, acctNum);

    if (index != -1)
    {
        subMenu();
        int selection;

        cin >> selection;
        cout << endl;

        while (selection != 9)
        {
            switch (selection)
            {
            case 1:
                cout << "Enter Amount to be Deposited: " ;
                cin >> amount;
                cout << endl;

                list[index].deposit(amount);
                break;
            case 2:
                cout << "Enter Amount to be Withdrawn: " ;
                cin >> amount;
                cout << endl;
                list[index].withdraw(amount);
                break;
            case 3:
                list[index].print();
                cout << "Press any key to return to the Menu... ";
                system("pause>nul");
                cout << endl;
                break;
            default:
                cout << "Invalid Selection." << endl;
            }

            subMenu();
            cin >> selection;
            cout << endl;
        }
    }
    else
        cout << "Invalid Account Number." << endl;
}

void printCustomersData(bankAccount list[], int length)
{
    for (int i = 0; i < length; i++)
    {
        list[i].print();
        system("pause");
    }
}