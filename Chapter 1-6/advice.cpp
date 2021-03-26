// Programmer:  Calixt Charlebois
// Assignment:  Chapter 3 & 6 Program.
// Due Date:    January 24, 2021
// Description: Advice program. The program reads a text file and displays the advice from "advice.txt". It gives the user
//              the option to overwrite the file with the user's new advice.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

void readfile();
void displayAdvice();
void writeFile();

ifstream ofs;
ofstream advice;

string oldAdvice;
char newAdvice[100];


int main()
{
    ifstream ofs;
    ofstream advice;

    string oldAdvice;
    char newAdvice[100];
    cout << setfill('*') << setw(80) << "*" << endl;
    cout << "Chapter 3 & 6 Programming Advice " << endl;
    cout << setfill('*') << setw(80) << "*" << endl << endl;
    cout << "Here is the advice given by the last person who ran this program: " << endl << endl;

    readfile();
    displayAdvice();

    cout << setfill('*') << setw(80) << "*" << endl;

    cout << "Please enter your advice below. Your advice may be as long as you need" << endl
    << "and you can press the <Enter> key one time to type on the next line," << endl
    << "but please press the <Enter> key twice to indicate the end of input: " << endl << endl;

    cin.getline(newAdvice,sizeof(newAdvice)); 

    writeFile();

    cout << setfill('*') << setw(80) << "*" << endl;

    cout << "Thank you for you advice." << endl;
    cout << "Press any button to continue" << endl;
    system("pause");

    return 0;
}

void readfile()
{
    ofs.open("advice.txt", ios::in);
    getline(ofs, oldAdvice);
    
}
void displayAdvice()
{
    cout << oldAdvice << endl << endl;
    ofs.close();
}
void writeFile()
{
    advice.open("advice.txt", ios::trunc);
    advice << newAdvice;
    advice.close();
}