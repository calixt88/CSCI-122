//Programmer:		First and Last Name
//Date:		        Current Date
//Assignment:		Chapters 3 & 6 Programming Assignment - Advice Program
//Description:	    Read advice file, output to screen (on a line by line basis)
//			        Accept input from user, write to file (on a line by line basis)

#include <fstream>
#include <iostream>
#include <cstdlib>  // for exit(1)

using namespace std;

int main()
{
    //declare file stream and variables
    ifstream advice;
    ofstream newAdvice;
    string asterick = "";

    asterick.assign(70, '*');

    advice.open("advice.txt");

    system("cls");

    if (!advice)
    {
        cout << endl << "Cannot open file Advice.txt" << endl << endl;
        exit(1);
    }

    cout << asterick << endl;
    cout << "Chapters 3 & 6 Programming Advice" << endl;
    cout << asterick << endl << endl;
    cout << "Here is the advice given by the last person who ran this program: " << endl << endl;
    char c = ' ';
    advice.get(c);

    while (advice)
    {
        cout << c;
        advice.get(c);
    }

    cout << endl << asterick << endl;
    cout << "Please enter your advice below.  Your advice may be as long as you need," << endl;
    cout << "and you can press the <Enter> key one time to type on the next line," << endl;
    cout << "but please press the <Enter> key twice to indicate the end of input:" << endl << endl;

    advice.close();

    newAdvice.open("advice.txt");

    int quit = 0;
    char d = ' ';

    cin.get(c);

    while (!quit)
    {
        newAdvice.put(c);
        cin.get(d);
        cin.putback(d);
        if ('\n' == c && '\n' == d)
            quit = 1; //in an unconstrained program, I'd use a break instead
        cin.get(c);
    }

    newAdvice << endl;
    newAdvice.close();

    cout << asterick << endl << endl;
    cout << "Thank you for your advice." << endl;
    cout << "Press any key to end the Advice Program..." << endl << endl;
    return 0;
}

/*
***************Chapters 3 & 6 Assignment Notes**************
*
- This exercise requires reading text from one file and copying it to another file except that a single blank replaces consecutive blanks.
- If you have any trouble coding the consecutive blanks, maybe the logic below may help
            -
while not end of file
  Read a character
  if not blank,
    write the character
  else
    while character is blank
      read and discard blank characters

-Take a look at the exit function - exit() for the file "Cannot open file Advice.txt" logic/code

-Remember to close the files before the program ends

*/