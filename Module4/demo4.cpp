#include <iostream>
#include "DynamicArray.h"
using namespace std;

int demo4()
{
	DynamicArray array;

	array.Add(500);
	array.Add(200);
	array.Add(199);
	array.Add(299);
	array.Add(399);

	DynamicArray copy = array; // call the copy constructor; member to member copy

	copy.Add(100);
	copy.Add(200);
	copy.Add(300);

	// Reset to original array
	 copy = array; // copy assignment operator

	array.Print();
	copy.Print();

	return 0;
}