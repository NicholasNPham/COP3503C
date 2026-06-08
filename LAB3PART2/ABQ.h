#pragma once
#include <iostream>
#include <stdexcept>
using std::cout;
using std::endl;

// ============== CLASS DEFINITION ============== 
template <typename T>
class ABQ
{

	unsigned int _front;
	unsigned int _size;
	unsigned int _capacity;
	T* _data;
	float _scaleFactor;

public:

	// ============== CONSTRUCTORS ============== 
	ABQ();
	ABQ(int capacity);
	ABQ(const ABQ& d); // BIG THREE


	// ============== COPY ASSIGNMENT OPERATOR ============== 
	ABQ& operator=(const ABQ& d); // BIG THREE

	// ============== DESTRUCTOR ============== 
	~ABQ(); //BIG THREE

	// ============== MUTATORS ==============
	void enqueue(T data);
	T dequeue();

	// ============== ACCESSORS ============== 
	T peek() const;
	unsigned int getSize() const;
	unsigned int getMaxCapacity() const;
	T* getData() const;
};

// ============== CLASS MEMBER DEFINITIONS ==============

template <typename T> // DEFAULT CONSTRUCTOR
ABQ<T>::ABQ()
{
	_front = 0;
	_size = 0;
	_capacity = 1;
	_scaleFactor = 2.0f;
	_data = new T[_capacity];
}

template <typename T> // PARAMETERIZED CONSTRUCTOR
ABQ<T>::ABQ(int capacity)
{
	_front = 0;
	_size = 0;
	_capacity = capacity;
	_scaleFactor = 2.0f;
	_data = new T[_capacity];
}

template <typename T> // COPY CONSTRUCTOR
ABQ<T>::ABQ(const ABQ& d)
{
	// MEMBER VARIABLES
	_front = d._front;
	_size = d._size;
	_capacity = d._capacity;
	_scaleFactor = d._scaleFactor;

	_data = new T[_capacity]; // DEEP COPY

	// COPY THE DATA OVER
	for (unsigned int i = 0; i < d._size; i++)
		_data[i] = d._data[i];
}

template <typename T> // COPY ASSIGNMENT OPERATOR
ABQ<T>& ABQ<T>::operator=(const ABQ& d)
{
	if (this != &d) //DOES THE CURRENT OBJECT LIVE AT THE SAME ADDRESS AS D
	{
		delete[] _data;

		// MEMBER VARIABLES
		_front = d._front;
		_size = d._size;
		_capacity = d._capacity;
		_scaleFactor = d._scaleFactor;

		_data = new T[_capacity];

		// COPY THE DATA OVER
		for (unsigned int i = 0; i < d._size; i++)
			_data[i] = d._data[i];
	}

	return *this;

}

template <typename T> // DESTRUCTOR
ABQ<T>::~ABQ()
{
	delete[] _data;
}

