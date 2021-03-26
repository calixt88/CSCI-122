//Programme:	First and Last Name
//Date:			Current Date
//Assignment:	Chapter 11, Exercise 13, Page 816
//Description:	Main Program

#include <iostream>
#include <iomanip>
#include "savingsAccount.h"
#include "checkingAccount.h"

using namespace std;

int main() 
{
	//declare variables
     int accountNumber = 1000;

     checkingAccount jackAccount(accountNumber++,1000);
     checkingAccount lisaAccount(accountNumber++, 450);
     savingsAccount samirAccount(accountNumber++, 9300);
     savingsAccount ritaAccount(accountNumber++, 32);

	 system("cls");
      
     jackAccount.deposit(1000);
     lisaAccount.deposit(2300);
     samirAccount.deposit(800);
     ritaAccount.deposit(500);

     jackAccount.postInterest();
     lisaAccount.postInterest();
     samirAccount.postInterest();
     ritaAccount.postInterest();

	 cout << "                    Bank Account Program" << endl << endl;
     cout << "******************** Before Withdrawals *********************" << endl;
     jackAccount.print();
     lisaAccount.print();
     samirAccount.print();
     ritaAccount.print();
     cout << "************************************************************" << endl << endl;

     jackAccount.writeCheck(250);
     lisaAccount.writeCheck(350);
     samirAccount.withdraw(120);
     ritaAccount.withdraw(290);

     cout << "******************** After Withdrawals *********************" << endl;
	 jackAccount.print();
     lisaAccount.print();
     samirAccount.print();
     ritaAccount.print();
     cout << "************************************************************" << endl << endl;

	 system("pause");

     return 0;
}