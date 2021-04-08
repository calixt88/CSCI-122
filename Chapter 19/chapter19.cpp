// Programmer: Calixt Charlebois
// Due date: 
// Assignment:
// Description: 

#include <iostream>
#inlcude <fstream>

using namespace std;

void bubbleSort(int list1[], int len);
void selectionSort(int list2[], int len);
void insertionSort(int list3[], int len);

int main()
{
	int list1[1000], list2[1000], list3[1000];
	srand(1000);

	for (int i = 0; i < 5000; i++)
	{
		list1[i] = rand() % 5000 + 1;
		list2[i] = list1[i];
		list3[i] = list1[i];
	}

	cout << "Number of comparisons ---\n Bubble sort: " << bubbltSort(list1, 1000) << endl;
	cout << " Selection sort: " << selectionSort(list2, 1000) << endl;
	cout << " Insertion sort: " << insertionSort(list3, 1000);

	system("pause");
	return 0;
}

void bubbleSort(int list1[], int len) {
	int index;
	long int keycomp = 0;
	long int itemAsng = 0;
	int iteration;
	int temp;

	for (iteration = 0; iteration < len - 1; iteration++)
	{
		for (index = 0; index < len - iteration; index++)
		{
			keycomp++;
			
			if(list1)
		}
	}
}
