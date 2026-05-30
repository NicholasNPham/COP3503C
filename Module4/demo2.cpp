#include <iostream>
#include "DynamicArray.h"
using namespace std;

int demo2()
{
	DynamicArray array;

	array.Add(500);
	array.Add(200);
	array.Add(199);
	array.Add(299);
	array.Add(399);

	array.Print();

	const int* thePrivateData = array.getData();

	for (int i = 0; i < array.getSize(); i++)
		thePrivateData[i] = 100000; // This will not work because now it spread to other parts
									// All of const spread here and must make a promise now

	return 0;
}