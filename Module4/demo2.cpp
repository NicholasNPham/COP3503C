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

	return 0;
}