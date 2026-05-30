#include "DynamicArray.h"
#include <iostream>
using namespace std;

void DynamicArray::Reset(int initialCapacity)
{
	_size = 0;
	_capacity = initialCapacity;
	_data = new int[_capacity];

}

DynamicArray::DynamicArray(int initialCapacity)
{
	Reset(initialCapacity);
}

DynamicArray::~DynamicArray()
{
	delete[] _data;
}

int* DynamicArray::getData()
{
	return _data;
}

int DynamicArray::getCapacity()
{
	return _capacity;
}

int DynamicArray::getSize()
{
	return _size;
}

void DynamicArray::Add(int newItem)
{
	// Should we resize this array?
	if (_size == _capacity) // we full
	{
		cout << "Container Full! resizing to accomodate: " << newItem << endl;
		_capacity++;
		// resize our array (grow by 1 element)
		int* newArray = new int[_capacity];

		for (int i = 0; i < _size; i++)
			newArray[i] = _data[i];

		delete[] _data;
		_data = newArray;
	}
	// 1. add the new thing to the array at the right location
	_data[_size] = newItem;
	_size++;
}

void DynamicArray::Remove()
{
	// Remove 1 element from the end of the array
	
	if (_size > 0)
	{
		_size--;
		int* newArray = new int[_capacity];
		for (int i = 0; i < _size; i++)
			newArray[i] = _data[i];
		delete[] _data;
		_data = newArray;
	}
	else
	{
		cout << "Cant remove anything" << endl;
	}
}

void DynamicArray::Clear()
{
	// get rid of any current/soon-to-be-old data
	delete[] _data;
	// reset everything to capacity of 1
	Reset(1);
}

void DynamicArray::Print()
{
	cout << "size: " << _size << " capacity: " << _capacity << endl;
	for (int i = 0; i < _size; i++)
		cout << _data[i] << endl;

}
