#include <iostream>
#include "DynamicArray.h"
using namespace std;

int demo3()
{
	DynamicArray array;

	array.Add(500);
	array.Add(200);
	array.Add(199);
	array.Add(299);
	array.Add(399);

	int* someMemory = new int[100];
	int* copy = someMemory;

	cout << someMemory << endl;
	cout << copy << endl;

	someMemory[0] = 50;

	cout << copy[0] << endl;
	delete[] someMemory; // delete new int [100]
	cout << copy[0] << endl;

	return 0;
}