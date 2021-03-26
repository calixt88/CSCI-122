/*
Programmer:  Calixt Charlebois
Assignment:  Airline Seating Program
Due Date:    Febuaray 7th, 2021
Description: Airline Seating Program that displays 13 rows of seats and A-F colums. Each seat has a indicator if the seat is full or is empty. The user can request
a seat and after the request is granted the seat switched to full. Rows 1-2 are first class, rows 3-7 are buisness class, and rows 8-13 are economy class.
*/

#include <iostream>
#include <iomanip>
#include <windows.h>  

using namespace std;

// Delcaring Function Prototypes
void initializeSeatPlan();
void showSeatAssignments();
void assignSeat();
void ShowMenu();
void showSeats();

bool isFirstClassFull();
bool isBusinessClassFull();
bool isEconomyClassFull();

void selectSeatNumber();
void assignSeatFirstClass();
void assignSeatBusinessClass();
void assignEconomyClass();

//CONSTANTS
const int ROWS   = 13;
const int COLUMS = 6;
int rowNumber    = 0;
int columnNumber = 0;

char seats[ROWS][COLUMS];
char ticketType = ' ';
char columnLetter = ' ';

//Delcaration of setConsoleAttribute for print color change.
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{

	char reserveAnswer = ' ';

	// Filling the 2d array with empty seats = "*".

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMS; j++)
		{
			seats[i][j] = '*';
		}
	}

	ShowMenu();

	cout << "To Reserve a seat enter Y/y(Yes), N/n(No): ";
	cin >> reserveAnswer;
	if (reserveAnswer == 'Y' || reserveAnswer == 'y')
	{
		TICKET:
		initializeSeatPlan();
		
		if (ticketType == 'F' || ticketType == 'f')
		{
			isFirstClassFull();
			assignSeatFirstClass();
			selectSeatNumber();
			assignSeat();
			showSeats();
			cout << "Would you like to reseve another seat? (Y/y) (N/n) : ";
			cin >> reserveAnswer;

			if (reserveAnswer == 'Y' || reserveAnswer == 'y')
			{
				cout << "\n\n";
				goto TICKET;
			}
			else
			{
				cout << "\n\nThank you for using the airlineSeating Program\n";
				system("Pause");
			}

		}
		else if (ticketType == 'B' || ticketType == 'b')
		{
			isBusinessClassFull();
			assignSeatBusinessClass();
			selectSeatNumber();
			assignSeat();
			showSeats();
			cout << "Would you like to reseve another seat? (Y/y) (N/n) : ";
			cin >> reserveAnswer;

			if (reserveAnswer == 'Y' || reserveAnswer == 'y')
			{
				cout << "\n\n";
				goto TICKET;
			}
			else
			{
				cout << "\n\nThank you for using the airlineSeating Program\n";
				system("Pause");
			}
		}
		else if (ticketType == 'E' || ticketType == 'e')
		{
			isEconomyClassFull();
			assignEconomyClass();
			selectSeatNumber();
			assignSeat();
			showSeats();
			cout << "Would you like to reseve another seat? (Y/y) (N/n) : ";
			cin >> reserveAnswer;

			if (reserveAnswer == 'Y' || reserveAnswer == 'y')
			{
				cout << "\n\n";
				goto TICKET;
			}
			else
			{
				cout << "\n\nThank you for using the airlineSeating Program\n";
				system("Pause");
			}
		}
		else
		{
			cout << "\nIncorret ticket type! Please try again.\n";
			goto TICKET;
		}
	}
	else
	{
		cout << "\n\nThank you for using the Airline Seating Program.\n";
		system("Pause");
	}

	
}

// What you are about to read is the most unoptimised functions in your life
// Please take it easy on me
// God speed.

bool isFirstClassFull()
{
	if (seats[0][0] == 'X' && seats[0][1] == 'X' && seats[0][2] && seats[0][3] == 'X' && seats[0][4] == 'X' && seats[0][5] == 'X'  
		&& seats[1][0] == 'X' && seats[1][1] == 'X' && seats[1][2] == 'X' && seats[1][3] == 'X' && seats[1][4] == 'X' && seats[1][5] == 'X' )
	{
		cout << "\n First Class is full!\n";
		system("pause");
		return 0;
	}
	else
	{
		return true;
	}
}

bool isBusinessClassFull()
{
	if (seats[3][0] == 'X' && seats[3][1] == 'X' && seats[3][2] && seats[3][3] == 'X' && seats[3][4] == 'X' && seats[3][5] == 'X'  
		&& seats[4][0] == 'X' && seats[4][1] == 'X' && seats[1][2] == 'X' && seats[4][3] == 'X' && seats[4][4] == 'X' && seats[4][5] == 'X'
		&& seats[5][0] == 'X' && seats[5][1] == 'X' && seats[5][2] == 'X' && seats[5][3] == 'X' && seats[5][4] == 'X' && seats[5][5] == 'X'
		&& seats[6][0] == 'X' && seats[6][1] == 'X' && seats[6][2] == 'X' && seats[6][3] == 'X' && seats[6][4] == 'X' && seats[6][5] == 'X'
		&& seats[2][0] == 'X' && seats[2][1] == 'X' && seats[2][2] == 'X' && seats[2][3] == 'X' && seats[2][4] == 'X' && seats[2][5] == 'X')
	{
		cout << "\n Business Class is full!\n";
		system("pause");
		return 0;
	}
	else
	{
		return true;
	}
}

bool isEconomyClassFull()
{
	if (seats[8][0] == 'X' && seats[8][1] == 'X' && seats[8][2] && seats[8][3] == 'X' && seats[8][4] == 'X' && seats[8][5] == 'X'
		&& seats[9][0] == 'X' && seats[9][1] == 'X' && seats[9][2] == 'X' && seats[9][3] == 'X' && seats[9][4] == 'X' && seats[9][5] == 'X'
		&& seats[10][0] == 'X' && seats[10][1] == 'X' && seats[10][2] == 'X' && seats[10][3] == 'X' && seats[10][4] == 'X' && seats[10][5] == 'X'
		&& seats[11][0] == 'X' && seats[11][1] == 'X' && seats[11][2] == 'X' && seats[11][3] == 'X' && seats[11][4] == 'X' && seats[11][5] == 'X'
		&& seats[12][0] == 'X' && seats[12][1] == 'X' && seats[12][2] == 'X' && seats[12][3] == 'X' && seats[12][4] == 'X' && seats[12][5] == 'X'
		&& seats[7][0] == 'X' && seats[7][1] == 'X' && seats[7][2] == 'X' && seats[7][3] == 'X' && seats[7][4] == 'X' && seats[7][5] == 'X')
	{
		cout << "\n Economy Class is full!\n";
		system("pause");
		return 0;
	}
	else
	{
		return true;
	}
}


void assignSeat()
{
	if (seats[rowNumber - 1][columnNumber] == 'X')
	{
		cout << "*#*#*#* This seat is occupied *#*#*#*#*\n";
	}
	else
	{
		seats[rowNumber - 1][columnNumber] = 'X';
	}
	
}


void showSeatAssignments()
{
	for (int i = 0; i < ROWS; i++)
	{

		cout << "\nRow " << setfill(' ') << setw(2) << right << (i + 1);

		for (int j = 0; j < COLUMS; j++)
		{
			if (j == 3)
			{
				cout << " ";
			}
			cout << " " << seats[i][j];

		}
	}
}
void selectSeatNumber()
{
	SEAT:
	cout << "Enter seat number (A - F): ";
	cin >> columnLetter;

	// I could have used a switch case, but couldn't be bothered

	if (columnLetter == 'A' || columnLetter == 'a')
	{
		columnNumber = 0;
	}
	else if (columnLetter == 'B' || columnLetter == 'b')
	{
		columnNumber = 1;
	}
	else if (columnLetter == 'C' || columnLetter == 'c')
	{
		columnNumber = 2;
	}
	else if (columnLetter == 'D' || columnLetter == 'd')
	{
		columnNumber = 3;
	}
	else if (columnLetter == 'E' || columnLetter == 'e')
	{
		columnNumber = 4;
	}
	else if (columnLetter == 'F' || columnLetter == 'f')
	{
		columnNumber = 5;
	}
	else
	{
		cout << "Invalid seat! Try again\n\n";
		goto SEAT;
	}

}

void assignSeatFirstClass()
{
	cout << "Enter row number 1 - 2:   ";
	cin >> rowNumber;

}

void assignSeatBusinessClass()
{
	cout << "Enter row number 3 - 7:   ";
	cin >> rowNumber;
	
}

void assignEconomyClass()
{
	cout << "Enter row number 7 - 13:   ";
	cin >> rowNumber;
	
}

void initializeSeatPlan()
{
	cout << "\nEnter ticket type: F/f (first class; (B/b) business class; E/e (economy class): ";
	cin >> ticketType;
}

void ShowMenu()
{
	system("cls");
	cout << setfill('*') << setw(14) << "*" << " Airline Seating Program " << setfill('*') << setw(14) << "*" << endl << endl;
	cout << "This program assigns seats for commerial airlines.\nThe curret seat assignments are as follows:" << endl;

	//Changing print color to blue = 1.
	SetConsoleTextAttribute(hStdOut, 1);

	//Printing the seats with ROWS and COLUMS.
	cout << "       A B C  D E F" << endl;

	for (int i = 0; i < ROWS; i++)
	{

		cout << "\nRow " << setfill(' ') << setw(2) << right << (i + 1);

		for (int j = 0; j < COLUMS; j++)
		{
			if (j == 3)
			{
				cout << " ";
			}
			cout << " " << seats[i][j];

		}
	}

	SetConsoleTextAttribute(hStdOut, 7);

	cout << "\n* -- available seat\nX -- occupied seat";
	cout << "\n\nRows 1 and 2 are for first class passengers.";
	cout << "\nRows 3 through 7 are for business class passengers.";
	cout << "\nRows 8 through 13 are for economy class passengers.\n\n";
	


}

void showSeats()
{
	cout << "\n\nThis seat is reserved for you.\n\n";
	//Changing print color to blue = 1.
	SetConsoleTextAttribute(hStdOut, 1);

	//Printing the seats with ROWS and COLUMS.
	cout << "       A B C  D E F" << endl;

	for (int i = 0; i < ROWS; i++)
	{

		cout << "\nRow " << setfill(' ') << setw(2) << right << (i + 1);

		for (int j = 0; j < COLUMS; j++)
		{
			if (j == 3)
			{
				cout << " ";
			}
			cout << " " << seats[i][j];

		}
	}
	//Changing font back to white
	SetConsoleTextAttribute(hStdOut, 7);
	cout << "\n* -- available seat\nX -- occupied seat\n\n";
	

}