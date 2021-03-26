//Programmer:	Cheryl Miller
//Date:			Current Date
//Assignment:	Chapter 7, Exercise 7a-e, Pages 519-520
//Description:	Fraction Calculator - program description listed in the book

#include <iostream>

using namespace std;

void menu();
void addFractions(int num1, int num2, int den1, int den2, int& numfrac, int& denfrac);
void subtractFractions(int num1, int num2, int den1, int den2, int& numfrac, int& denfrac);
void multiplyFractions(int num1, int num2, int den1, int den2, int& numfrac, int& denfrac);
void divideFractions(int num1, int num2, int den1, int den2, int& numfrac, int& denfrac);
void getFraction(int choice, int fractNo, int& numerator, int& denominator);
void showResult(char operation, int num1, int num2, int den1, int den2, int numfrac, int denfrac);

int main()
{
    //declare and initialize local variables
    int numerator1, numerator2, denominator1, denominator2 = 0;
    int resultnum, resultdeno = 0;
    int choice = 0;

    top:        //got0 tag
    
    system("cls");
  
    menu();
    cin >> choice;
    cout << endl;

    //while (choice != 9)
    while (choice == 1 or choice == 2 or choice == 3 or choice == 4)
    {
        cout << "For Fraction 1:" << endl;
        getFraction(choice, 1, numerator1, denominator1);

        cout << "For Fraction 2:" << endl;
        getFraction(choice, 2, numerator2, denominator2);

        switch (choice)
        {
        case 1:
            addFractions(numerator1, numerator2, denominator1, denominator2, resultnum, resultdeno);
            showResult('+', numerator1, numerator2, denominator1, denominator2, resultnum, resultdeno);
            break;
        case 2:
            subtractFractions(numerator1, numerator2, denominator1, denominator2, resultnum, resultdeno);
            showResult('-', numerator1, numerator2, denominator1, denominator2, resultnum, resultdeno);
            break;
        case 3:
            multiplyFractions(numerator1, numerator2, denominator1, denominator2, resultnum, resultdeno);
            showResult('*', numerator1, numerator2, denominator1, denominator2, resultnum, resultdeno);
            break;
        case 4:
            divideFractions(numerator1, numerator2, denominator1, denominator2, resultnum, resultdeno);
            showResult('/', numerator1, numerator2, denominator1, denominator2, resultnum, resultdeno);
            break;
        default:
            cout << "Invalid Selection." << endl;
        }

        menu();
        cin >> choice;
        cout << endl;
    }

    if (choice > 4 && choice != 9)
    {
        cout << "Invalid Selection." << endl << endl;
        cout << "Press any key to clear the screen and display the Menu ...";
        system("pause>nul");
        goto top;
    }

    cout <<"Thank you for running the Fraction Calculator Program (press any key to end the program)";
    system("pause>nul");

    return 0;
}

void menu()
{
    cout << "********************* Fraction Calculator Program *********************" << endl << endl;
    cout << "This program performs operations (+, -, *, /) on fractions." << endl;
    cout << "You will be prompted for the Numerator and Denominator for each fraction." << endl;
    cout << "1 : To add fraction" << endl;
    cout << "2 : To subtract fraction" << endl;
    cout << "3 : To multiply fraction" << endl;
    cout << "4 : To divide fraction" << endl;
    cout << "9 : To exit the program" << endl;
    cout << endl << "Please enter a Menu Option listed above: ";
}

void addFractions(int num1, int num2, int den1, int den2, int& numfrac, int& denfrac)
{
    numfrac = num1 * den2 + num2 * den1;
    denfrac = den1 * den2;
}

void subtractFractions(int num1, int num2, int den1, int den2, int& numfrac, int& denfrac)
{
    numfrac = num1 * den2 - num2 * den1;
    denfrac = den1 * den2;
}

void multiplyFractions(int num1, int num2, int den1, int den2, int& numfrac, int& denfrac)
{
    numfrac = num1 * num2;
    denfrac = den1 * den2;
}

void divideFractions(int num1, int num2, int den1, int den2, int& numfrac, int& denfrac)
{
    numfrac = num1 * den2;
    denfrac = num2 * den1;
}

void getFraction(int choice, int fractNo, int& numerator, int& denominator)
{
    cout << "Please enter the Numerator: ";
    cin >> numerator;
    cout << endl;

    if (choice == 4 && fractNo == 2 && numerator == 0)
    {
        cout << "To divide, the second fraction must be nonzero." << endl;
        while (numerator == 0)
        {
            cout << "Enter a nonzero number for the Numerator: ";
            cin >> numerator;
            cout << endl;
        }
    }

    cout << "Please enter the Denominator: ";
    cin >> denominator;
    cout << endl;

    if (denominator == 0)
    {
        cout << "The Denominator must be nonzero." << endl;

        while (denominator == 0)
        {
            cout << "Please enter the Denominator: ";
            cin >> denominator;
            cout << endl;
        }
    }
}

void showResult(char operation, int num1, int num2, int den1, int den2, int numfrac, int denfrac)
{
    cout << "Operation Result: " << num1 << "/" << den1;

    switch (operation)
    {
    case '+':
        cout << " + ";
        break;
    case '-':
        cout << " - ";
        break;
    case '*':
        cout << " * ";
        break;
    case '/':
        cout << " / ";
        break;
    default:
        cout << "Invalid operation." << endl;
    }

    cout << num2 << "/" << den2 << " = " << numfrac << "/" << denfrac << endl << endl;
    cout << "Press any key to clear the screen and display the Menu ...";
    system("pause>nul");
    system("cls");
}