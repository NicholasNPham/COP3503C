#include <iostream>
#include "DynamicArray.h"
using namespace std;

void Foo(DynamicArray someArray) // calling the copy constructor for some array
{
	someArray.Print();
}


int demo3()
{
	DynamicArray array;

	array.Add(500);
	array.Add(200);
	array.Add(199);
	array.Add(299);
	array.Add(399);

	array.Print();
	Foo(array);
	array.Print();



	return 0;
}