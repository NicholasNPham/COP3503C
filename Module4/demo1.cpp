#include <iostream>
using namespace std;

int demo1()
{
	int count;
	cin >> count;
	int* someArray = new int[10];
	// Assume cool stuff being done with the array

	//Goal: Grow the array by 1 element
	
	int* newArray = new int[11];

	for (int i = 0; i < 10; i++)
		newArray[i] = someArray[i];

	delete[] someArray;

	someArray = newArray;
	someArray[10] = 500;

	//Goal: Grow the array by 1 element

	int* newArray = new int[12];

	for (int i = 0; i < 11; i++)
		newArray[i] = someArray[i];

	delete[] someArray;

	someArray = newArray;
	someArray[11] = 200;

	return 0;
}