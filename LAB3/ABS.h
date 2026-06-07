#pragma once
#include <iostream>
#include <stdexcept>
using std::cout;
using std::endl;

// ============== CLASS DEFINITION ============== 
template <typename T>
class ABS
{

	unsigned int _size;
	unsigned int _capacity;
	T* _data;
	float _scaleFactor;

public:

// ============== CONSTRUCTORS ============== 
	ABS();
	ABS(int capacity);
	ABS(const ABS& d); // BIG THREE


// ============== COPY ASSIGNMENT OPERATOR ============== 
	ABS& operator=(const ABS& d); // BIG THREE

// ============== DESTRUCTOR ============== 
	~ABS(); //BIG THREE

// ============== MUTATORS ==============
	void push(T data);
	T pop();

// ============== ACCESSORS ============== 
	T peek() const;
	unsigned int getSize() const;
	unsigned int getMaxCapacity() const;
	T* getData() const;
};

// ============== CLASS MEMBER DEFINITIONS ==============

template <typename T> // DEFAULT CONSTRUCTOR
ABS<T>::ABS()
{
	_size = 0;
	_capacity = 1;
	_scaleFactor = 2.0f;
	_data = new T[_capacity];
}  

template <typename T> // PARAMETERIZED CONSTRUCTOR
ABS<T>::ABS(int capacity)
{
		_size = 0;
		_capacity = capacity;
		_scaleFactor = 2.0f;
		_data = new T[_capacity];
}

template <typename T> // COPY CONSTRUCTOR
ABS<T>::ABS(const ABS& d)
{
	// MEMBER VARIABLES
	_size = d._size;
	_capacity = d._capacity;
	_scaleFactor = d._scaleFactor;

	_data = new T[_capacity]; // DEEP COPY

	// COPY THE DATA OVER
	for (int i = 0; i < d._size; i++)
		_data[i] = d._data[i];
}

template <typename T> // COPY ASSIGNMENT OPERATOR
ABS<T>& ABS<T>::operator=(const ABS& d)
{
	if (this != &d) //DOES THE CURRENT OBJECT LIVE AT THE SAME ADDRESS AS D
	{
		delete[] _data;
		
		// MEMBER VARIABLES
		_size = d._size;
		_capacity = d._capacity;
		_scaleFactor = d._scaleFactor;

		_data = new T[_capacity];

		// COPY THE DATA OVER
		for (int i = 0; i < d._size; i++)
			_data[i] = d._data[i];
	}

	return *this;

}

template <typename T> // DESTRUCTOR
ABS<T>::~ABS()
{
	delete[] _data;
}

template <typename T>
void ABS<T>::push(t data)
{
	if (_capacity == _size) // CHECK IF FULL
	{
		_capacity *= _scaleFactor; // INCREASE THE CAPACITY
		T* newArray = new T[_capacity]; // CREATE A NEW ARRAY
	
		// COPY DATA OVER
		for (int i = 0; i < _size; i++)
			newArray[i] = _data[i];

		delete[] _data; // DELETE OLD DATA
		_data = newArray; // POINT TO NEW ARRAY
	}

	_data[_size] = data; // ADD TO THE STACK
	_size++; // UPDATE SIZE

}