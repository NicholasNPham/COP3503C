#pragma once
#include <iostream>
using std::cout;
using std::endl;

// CLASS DEFINITIONS
template <typename T>
class DynamicArray
{
	T* _data; // What the class stores -- the "real" data; a pointer to a mem addy
	unsigned int _capacity; // how many elements Can we store?
	unsigned int _size; // How many elements are we storing?

	void Reset(int initialCapacity);

	void CopyFromObject(const DynamicArray& otherObject);

public:
	// Construction / Destruction
	DynamicArray(int initialCapacity = 1); // tilda key if you need it ~
	~DynamicArray();

	// copy constructor
	// ClassName (const ClassName& otherObject);
	DynamicArray(const DynamicArray& otherObject);

	// copy Assignment Operator
	// ClassName& operator(const ClassName& rightHandSide)
	DynamicArray& operator=(const DynamicArray& rhs);


	// ================ ACCESSOR =================
	const T* getData() const;
	int getCapacity() const;
	int getSize() const;
	const T& Get(int index) const;

	// ================ MUTATORS =================
	void Add(T newItem);
	void Remove();
	void Clear();

	// ================ BEHAVIORS =================
	void Print() const;

	// ================ OPERATORS =================
	DynamicArray& operator+=(const DynamicArray& rhs);
	DynamicArray operator+(const DynamicArray& rhs);
	const T& operator[](int index) const;
	T& operator[](int index);
	bool operator==(const DynamicArray& rhs);


	void Combine(const DynamicArray& rhs);
};


// CLASS MEMBER DEFINITIONS

template <typename T>
void DynamicArray<T>::Reset(int initialCapacity)
{
	_size = 0;
	_capacity = initialCapacity;
	_data = new T[_capacity];

}

template <typename T>
void DynamicArray<T>::CopyFromObject(const DynamicArray& otherObject)
{
	this->_size = 0;
	this->_capacity = otherObject._capacity;

	// deep copy
	_data = new T[_capacity];

	for (int i = 0; i < otherObject._size; i++)
		Add(otherObject._data[i]);
}

template <typename T>
DynamicArray<T>::DynamicArray(int initialCapacity)
{
	Reset(initialCapacity);
}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
	delete[] _data;
}

// copy all of the "other objects data into "this" objects data
template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& otherObject)
{
	CopyFromObject(otherObject);
}
template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& rhs)
{

	// 0. Get rid of any old data
	delete[] _data;
	_size = 0;

	// 1. copy all the data from the the other object
	CopyFromObject(rhs);

	return *this; // this line wall always look like this

}

template <typename T>
const T* DynamicArray<T>::getData() const
{
	return _data;
}

template <typename T>
int DynamicArray<T>::getCapacity() const
{
	return _capacity;
}

template <typename T>
int DynamicArray<T>::getSize() const
{
	return _size;
}

template <typename T>
const T& DynamicArray<T>::Get(int index) const
{
	return _data[index];
}

template <typename T>
void DynamicArray<T>::Add(T newItem)
{
	// Should we resize this array?
	if (_size == _capacity) // we full
	{
		_capacity++;
		// resize our array (grow by 1 element)
		T* newArray = new T[_capacity];

		for (int i = 0; i < _size; i++)
			newArray[i] = _data[i];

		delete[] _data;
		_data = newArray;
	}
	// 1. add the new thing to the array at the right location
	_data[_size] = newItem;
	_size++;
}

template <typename T>
void DynamicArray<T>::Remove()
{
	// Remove 1 element from the end of the array

	if (_size > 0)
	{
		_size--; // This was added before demo4 video so this was the "change"
		T* newArray = new T[_capacity];
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

template <typename T>
void DynamicArray<T>::Clear()
{
	cout << "Deallocating memory at: " << _data << endl;
	// get rid of any current/soon-to-be-old data
	delete[] _data;
	// reset everything to capacity of 1
	Reset(1);
}

template <typename T>
void DynamicArray<T>::Print() const
{
	cout << "size: " << _size << " capacity: " << _capacity << endl;
	for (int i = 0; i < _size; i++)
		cout << _data[i] << endl;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator+=(const DynamicArray& rhs)
{
	this->Combine(rhs);

	return *this;
}

template <typename T>
DynamicArray<T> DynamicArray<T>::operator+(const DynamicArray& rhs)
{
	DynamicArray<T> newArray(_size + rhs._size); // pre size according to the size of the both arrays

	// copy this data into new array;
	for (int i = 0; i < _size; i++)
		newArray.Add(_data[i]); // use existing functionality

	// copy rhs data into newArray;
	for (int i = 0; i < rhs._size; i++)
		newArray.Add(rhs._data[i]);

	return newArray;
}

template <typename T>
const T& DynamicArray<T>::operator[](int index) const {
	return _data[index];
}

template <typename T>
T& DynamicArray<T>::operator[](int index) {
	return _data[index];
}

//template <typename T>
//bool DynamicArray<T>::operator==(const DynamicArray& rhs)
//{
//	// Quick Test -- are the sizes the same?
//	if (_size != rhs._size)
//		return false;
//
//	for (int i = 0; i < _size; i++)
//	{
//		if (_data[i] != rhs._data[i])
//			return false;
//	}
//
//	return true;
//}

template <typename T>
void DynamicArray<T>::Combine(const DynamicArray& rhs)
{
	T* newArray = new T[_size + rhs._size];	// Allocate some space that can hold both arrays

	for (int i = 0; i < _size; i++) // copy array 1 (this) into the array

		newArray[i] = _data[i];

	for (int i = 0; i < rhs._size; i++) // copy array 2 (rhs) into the array
		newArray[_size + i] = rhs._data[i];

	_size += rhs._size; // make sure _size and _capacity are updated
	_capacity = _size;

	delete[] _data; // delete the old data


	_data = newArray; // redirect the _data pointer to the new (combined) array

}
