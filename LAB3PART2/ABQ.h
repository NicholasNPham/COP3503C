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

template <typename T>
void ABQ<T>::enqueue(T data)
{
	if (_capacity == _size) // CHECK IF FULL
	{

		unsigned int oldCapacity = _capacity; // SAVE THE OLD CAPACITY BEFORE CHANGE

		_capacity *= _scaleFactor; // INCREASE THE CAPACITY
		T* newArray = new T[_capacity]; // CREATE A NEW ARRAY

		// COPY DATA OVER
		for (unsigned int i = 0; i < _size; i++)
			newArray[i] = _data[(_front + i) % oldCapacity];

		_front = 0; // SET FRONT TO INDEX 0
		delete[] _data; // DELETE OLD DATA
		_data = newArray; // POINT TO NEW ARRAY
	}

	_data[(_front + _size) % _capacity] = data; // ADD TO THE STACK IN THE BACK
	_size++; // UPDATE SIZE

}

template <typename T>
T ABQ<T>::dequeue()
{
	if (_size == 0)
	{
		throw std::runtime_error("ARRAY IS EMPTY NOTHING TO REMOVED");
	}
	T tempVar = _data[_front];
	_front = (_front + 1) % _capacity; // FRONT IS WHATEVER THE NEXT INDEX IS
	_size--; // SHRINK THE SIZE

	if (_size < (_capacity / _scaleFactor))
	{
		unsigned int oldCapacity = _capacity; // SAVE THE OLD CAPACITY BEFORE CHANGE
		_capacity /= _scaleFactor;

		T* newArray = new T[_capacity]; // CREATE A NEW ARRAY

		// COPY DATA OVER
		for (unsigned int i = 0; i < _size; i++)
			newArray[i] = _data[(_front + i) % oldCapacity];

		_front = 0; // FRONT IS NOW INDEX 0
		delete[] _data; // DELETE OLD DATA
		_data = newArray; // POINT TO NEW ARRAY
	}
	return tempVar;
}

template <typename T>
T ABQ<T>::peek() const {

	if (_size == 0)
	{
		throw std::runtime_error("ARRAY IS EMPTY NOTHING TO PEEK");
	}

	return _data[_front]; // THIS RETURNS THE VALUE ON THE TOP OF THE LIST	

}

template <typename T>
unsigned int ABQ<T>::getSize() const {
	return _size;
}

template <typename T>
unsigned int ABQ<T>::getMaxCapacity() const {
	return _capacity;
}

template <typename T>
T* ABQ<T>::getData() const {
	return _data;
}