#include <iostream>
#include "DynamicArray.h"
using namespace std;

int demo1()
{
	DynamicArray array(5); // 1
	array.Add(9);
	array.Add(99);
	array.Add(999);
	array.Add(9999);
	array.Add(99999);

	array.Print();
	
	array.Add(9999999);

	array.Print();

	array.Remove();

	array.Print();

	array.Clear();

	array.Print();

	return 0;
}