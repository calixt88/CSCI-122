//Programmer:   Student Name
//Date:         Current Date
//Assignment:   Chapter 12, Exercise 6, Page 905, Main Program
/*Description:  Rewrite the retrieveAt function so that it is written as a value returning function,
                returning the required item. If the location of the item to be returned is
                out of range, use the assert function to terminate the program.

                Write a program to test the revised function.
                retrieveAt Function code, of the class arrayListType, is listed on page 880
                assert Function code is listed on pages 236-237
*/

#include <iostream> 
#include "unorderedArrayListType.h"
 
using namespace std;

int main()
{
    //declare variables and array list
    unorderedArrayListType intList(25); 
    int number = 0; 
    int position = 0;

    system("cls");
    cout << "************************ class arrayListType Program Example **************************" << endl << endl;
    cout << "Enter 8 Integers on one line (space between each integer): ";

    for (int count = 0; count < 8; count++) 
    {
        cin >> number;
        intList.insertEnd(number);
    }

    cout << endl; 
    cout << "intList: "; 
    intList.print(); 
    cout << endl; 

    cout << "Enter the position of the item to be retrieved: ";  
    cin >> position; 
    cout << endl; 

    cout << "The element at position " << position << " = " << intList.retrieveAt(position) << endl << endl;  
    cout << "***************************************************************************************" << endl << endl;

	return 0; 
}