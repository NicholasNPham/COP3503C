#pragma once
class DynamicArray
{
	int* _data; // What the class stores -- the "real" data; a pointer to a mem addy
	unsigned int _capacity; // how many elements Can we store?
	unsigned int _size; // How many elements are we storing?

	void Reset(int initialCapacity);

public:
	// Construction / Destruction
	DynamicArray(int initialCapacity = 1); // tilda key if you need it ~
	~DynamicArray();

	// Accessors
	int* getData();
	int getCapacity();
	int getSize();

	// Mutators
	void Add(int newItem);
	void Remove();
	void Clear();

	// Behaviors
	void Print();

};