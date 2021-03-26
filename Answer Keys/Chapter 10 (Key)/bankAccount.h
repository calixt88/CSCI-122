//Programmer:   Student Name
//Date:         Current Date
//Assignment:   Chapter 10, Exercise 21, Page 741
//Description:  Program description listed in the book
//              Header File

//Description:  Program description listed in the book
//              Header File

#include <iostream>
#include <string>

using namespace std;

class bankAccount
{
public:
    void setdata(string name, string accType, int num, double bal, double intRate);
    void deposit(double amt);
    void withdraw(double amt);
    double getInterest();
    void updateBalance();
    void print() const;
    int getAccountNumber() const;
    string getAccountHolderName() const;
    string getAccountType() const;
    double getBalance() const;
    double getInterestRate() const;

    bankAccount(string name = "", string accType = "", int accNum = 0, double bal = 0.0, double intRate = 0.0);

private:
    static int num;
	string accountHolderName;
	string accountType;
	int accountNumber;
    double balance;
    double interestRate;
};