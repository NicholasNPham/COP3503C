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

	DynamicArray copy = array;

	copy.Add(100);
	copy.Add(200);
	copy.Add(300);

	// Reset to original array
	copy = array; // copy assignment operator

	return 0;
}