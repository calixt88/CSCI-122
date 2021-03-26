//Programmer:		Cheryl Miller
//Date:				Current Date
//Assignment:		Chapter 8, Exercise 19, Page 609
//Description:		Program that is used to assign seats for a commercial airplane.
//                  The airplane has 13 rows, with six seats in each row.
//                  Rows 1 and 2 are first class, rows 3 through 7 are business class,
//                  and rows 8 through 13 are economy class. The program prompts the user to enter the 
//                  ticket type (first class, business class, or economy class) and the desired seat

#include <iostream>
#include <iomanip>
#include <windows.h>	//needed for color output display

using namespace std;

//global variables
const int ROWS = 13;
const int COLUMNS = 6;
HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);		//color output set globally so all functions have access to it

//function prototypes
void initiailzeSeatPlan(char sPlan[][COLUMNS], int rowSize);
void showSeatAssignments(char sPlan[][COLUMNS], int rowSize);
void assignSeat(char sPlan[][COLUMNS], int rowSize);
void showMenu(char sPlan[][COLUMNS], int rowSize);

bool isFirstClassFull(char sPlan[][COLUMNS], int rowSize);
bool isBusinessClassFull(char sPlan[][COLUMNS], int rowSize);
bool isEconomyClassFull(char sPlan[][COLUMNS], int rowSize);

void selectSeatNumber(int startRows, int endRows, int& rowNo, char& columnNo);
void assignSeatFirstClass(char sPlan[][COLUMNS], int rowSize);
void assignSeatBusinessClass(char sPlan[][COLUMNS], int rowSize);
void assignSeatEconomyClass(char sPlan[][COLUMNS], int rowSize);

int main()
{
    //declare variables and arrays
    char seatPlan[ROWS][COLUMNS];
    char resp;

    initiailzeSeatPlan(seatPlan, ROWS);

    showMenu(seatPlan, ROWS);

    cout << endl << "To reserve a seat enter Y/y(Yes), N/n(No): ";
    cin >> resp;
    cout << endl;

    while (resp == 'y' || resp == 'Y')
    {
        assignSeat(seatPlan, ROWS);
        //showMenu(seatPlan, ROWS);
        cout << "Reserve another seat Y/y(Yes), N/n(No): ";
        cin >> resp;
        system("cls");
        showMenu(seatPlan, ROWS);
        cout << endl;
    }

    return 0;
}

void initiailzeSeatPlan(char sPlan[][COLUMNS], int rowSize)
{
    int i, j;

    for (i = 0; i < rowSize; i++)
        for (j = 0; j < COLUMNS; j++)
            sPlan[i][j] = '*';
}

void showMenu(char sPlan[][COLUMNS], int rowSize)
{
    //SetConsoleTextAttribute(screen, 7);  //white (default color for console/command prompt)
    cout << "************** Airline Seating Program **************" << endl << endl;
    cout << "This program assigns seats for a commercial airplane." << endl;
    cout << "The current seat assignments are as follows." << endl;
    showSeatAssignments(sPlan, rowSize);
    cout << "Rows 1 and 2 are for first class passengers." << endl;
    cout << "Rows 3 through 7 are for business class passengers." << endl;
    cout << "Rows 8 through 13 are for economy class passengers." << endl;
}

void assignSeat(char sPlan[][COLUMNS], int rowSize)
{
    char ticketType;
    char resp;

    cout << "Enter ticket type: F/f (first class); (B/b) (business class); E/e (economy class): ";
    cin >> ticketType;
   // cout << endl;

    switch (ticketType)
    {
    case 'f':
    case 'F':
        if (!isFirstClassFull(sPlan, rowSize))
            assignSeatFirstClass(sPlan, rowSize);
        else
        {
            cout << "Sorry!!! First Class is Full" << endl;
            cout << "Press Y/y to continue: ";
            cin >> resp;
            cout << endl;
        }

        break;

    case 'b':
    case 'B':
        if (!isBusinessClassFull(sPlan, rowSize))
            assignSeatBusinessClass(sPlan, rowSize);
        else
        {
            cout << "Sorry!!! Business Class is Full" << endl;
            cout << "Press Y/y to continue: ";
            cin >> resp;
            cout << endl;
        }

        break;

    case 'e':
    case 'E':
        if (!isEconomyClassFull(sPlan, rowSize))
            assignSeatEconomyClass(sPlan, rowSize);
        else
        {
            cout << "Sorry!!! Economic Class is Full" << endl;
            cout << "Press Y/y to continue: ";
            cin >> resp;
            cout << endl;
        }
    }

    showSeatAssignments(sPlan, rowSize);
}

void showSeatAssignments(char sPlan[][COLUMNS], int rowSize)
{
    int i, j;
    
    SetConsoleTextAttribute(screen, 9);  //blue
    cout << "        A B C  D E F" << endl;

    for (i = 0; i < rowSize; i++)
    {
        cout << "Row " << setw(2) << i + 1 << "  ";
        for (j = 0; j < COLUMNS; j++)
        {
            cout << sPlan[i][j] << " ";
            if (j == 2)
                cout << " ";
        }
        cout << endl;
    }

    SetConsoleTextAttribute(screen, 7);  //white
    cout << "* -- available seat" << endl;
    cout << "X -- occupied seat" << endl;
    cout << endl;
}

bool isFirstClassFull(char sPlan[][COLUMNS], int rowSize)
{
    int i, j;

    int assignedSeats = 0;

    for (i = 0; i < 2; i++)
        for (j = 0; j < COLUMNS; j++)
            if (sPlan[i][j] == 'X')
                assignedSeats++;

    return (assignedSeats == 2 * COLUMNS);
}

bool isBusinessClassFull(char sPlan[][COLUMNS], int rowSize)
{
    int i, j;

    int assignedSeats = 0;

    for (i = 2; i < 7; i++)
        for (j = 0; j < COLUMNS; j++)
            if (sPlan[i][j] == 'X')
                assignedSeats++;

    return (assignedSeats == 5 * COLUMNS);
}

bool isEconomyClassFull(char sPlan[][COLUMNS], int rowSize)
{
    int i, j;

    int assignedSeats = 0;

    for (i = 7; i < 13; i++)
        for (j = 0; j < COLUMNS; j++)
            if (sPlan[i][j] == 'X')
                assignedSeats++;

    return (assignedSeats == 6 * COLUMNS);
}

void selectSeatNumber(int startRows, int endRows, int& rowNo, char& columnNo)
{
    cout << "Enter row number " << startRows << " - " << endRows << ":    ";
    cin >> rowNo;
    //cout << endl;

    while (rowNo < startRows || rowNo > endRows)
    {
        cout << "Enter row number " << startRows << " - " << endRows << ":    ";
        cin >> rowNo;
        //cout << endl;
    }

    cout << "Enter seat number (A - F): ";
    cin >> columnNo;
    columnNo = toupper(columnNo);
    cout << endl;

    while (columnNo < 'A' || columnNo > 'F')
    {
        cout << "Enter seat number (A - F): ";
        cin >> columnNo;
        columnNo = toupper(columnNo);
        cout << endl;
    }
}

void assignSeatFirstClass(char sPlan[][COLUMNS], int rowSize)
{
    int rowNum;
    char columnPos;

    if (!isFirstClassFull(sPlan, rowSize))
    {
        selectSeatNumber(1, 2, rowNum, columnPos);

        while (sPlan[rowNum - 1][columnPos - 65] != '*')
        {
            cout << "*#*#*#*# This seat is occupied *#*#*#*#" << endl;
            cout << "Make another selection" << endl;

            showSeatAssignments(sPlan, rowSize);

            selectSeatNumber(1, 2, rowNum, columnPos);
        }

        sPlan[rowNum - 1][columnPos - 65] = 'X';

        cout << "This seat is reserved for you" << endl;
    }
    else
        cout << "Sorry!!! First Class is Full" << endl;
}

void assignSeatBusinessClass(char sPlan[][COLUMNS], int rowSize)
{
    int rowNum;
    char columnPos;

    if (!isBusinessClassFull(sPlan, rowSize))
    {
        selectSeatNumber(3, 7, rowNum, columnPos);

        while (sPlan[rowNum - 1][columnPos - 65] != '*')
        {
            cout << "*#*#*#*# This seat is occupied *#*#*#*#" << endl;
            cout << "Make another selection" << endl;

            showSeatAssignments(sPlan, rowSize);

            selectSeatNumber(3, 7, rowNum, columnPos);
        }

        sPlan[rowNum - 1][columnPos - 65] = 'X';
        cout << "This seat is reserved for you" << endl;
    }
    else
        cout << "Business class is full." << endl;
}

void assignSeatEconomyClass(char sPlan[][COLUMNS], int rowSize)
{
    int rowNum;
    char columnPos;

    if (!isEconomyClassFull(sPlan, rowSize))
    {
        selectSeatNumber(8, 13, rowNum, columnPos);

        while (sPlan[rowNum - 1][columnPos - 65] != '*')
        {
            cout << "*#*#*#*# This seat is occupied *#*#*#*#" << endl;
            cout << "Make another selection" << endl;

            showSeatAssignments(sPlan, rowSize);

            selectSeatNumber(8, 13, rowNum, columnPos);
        }

        sPlan[rowNum - 1][columnPos - 65] = 'X';
        cout << "This seat is reserved for you" << endl;
    }
    else
        cout << "Economic class is full." << endl;
}