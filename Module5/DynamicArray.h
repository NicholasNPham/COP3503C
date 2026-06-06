#pragma once
class DynamicArray
{
	int* _data; // What the class stores -- the "real" data; a pointer to a mem addy
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


	// Accessors
	const int* getData() const;
	int getCapacity() const;
	int getSize() const;

	// Mutators
	void Add(int newItem);
	void Remove();
	void Clear();

	// Behaviors
	void Print() const;

};