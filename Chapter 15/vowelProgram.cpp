// Programmer:  Calixt Charlebois
// Due Date:    03/24/2021
// Assingment:  Chapter 15, Exercise 3
// Description: Vowel Program using recursion.

#include <iostream>
#include <string>

using namespace std;

int vow(string);

int main()
{  
    system("clear");
    string input;

    cout << "Please Enter a String: ";
    getline(cin, input);

    cout << endl << endl << "Number of vowels in \" " << input << " \"" << vow(input) << "\n\n";

    return 0;
}

int vow(string input)
{
    if (input.length() == 0)
    {
        return 0;
    }

    int num = vow(input.substr(1));

    switch(input.at(0))
    {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
        //case 'y': 
        //case 'Y':
            return num + 1;
        default:
            return num;
    }
            


}