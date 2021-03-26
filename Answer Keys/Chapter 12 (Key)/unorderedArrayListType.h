//Programmer:   Student Name
//Date:         Current Date
//Assignment:   Chapter 12, Exercise 6, Page 905, Header File
//Description:  Rewrite the retrieveAt function so that it is written as a value returning function,
//              returning the required item. If the location of the item to be returned is
//              out of range, use the assert function to terminate the program.
//              Write a program to test the function.
//              Function retrieveAt code, of the class arrayListType, starts on page 880
//              Function assert code is listed on pages 236-237

#ifndef H_unorderedArrayListType
#define H_unorderedArrayListType

#include "arrayListType.h" 
  
class unorderedArrayListType: public arrayListType
{
public:
    void insertAt(int location, int insertItem);
    void insertEnd(int insertItem);
    void replaceAt(int location, int repItem);
    int seqSearch(int searchItem) const; 
    void remove(int removeItem);

    unorderedArrayListType(int size = 100);     //Constructor
}; 
#endif