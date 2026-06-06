#include <iostream>
#include "DynamicArray.h"
using namespace std;

class RegularClass
{

};

template <typename T>
class TemplateClass
{
	T someData;
public:
	T GetData();
};

template <typename T>
T TemplateClass<T>::GetData()
{
	return someData();
}

int demo1()
{
	DynamicArray array;
	array.Add(500);
	array.Add(200);
	array.Add(199);
	array.Add(299);
	array.Add(399);

	DynamicArray copy;

	// Reset to original array
	copy = array; // copy assignment operator
	array.Print();
	copy.Print();
	
	return 0;

}

