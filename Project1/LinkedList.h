#pragma once
#include <iostream>
#include <vector>
using std::cout;
using std::endl;

// ============== CLASS DEFINITION ============== 
template <typename T>
class LinkedList
{
public:
	// NESTED NODE CLASS
	struct Node
	{
		// ============== STRUCT DEFAULT PUBLIC ==============
		T data;
		Node* next;
		// ============== STRUCT CONSTRUCTOR ============== 
		Node(const T& value)
		{
			data = value;
			next = nullptr;
		}

	};

	// ============== BEHAVIORS ============== 
	void PrintForward() const;
	void PrintReverse() const;

	// ============== ACCESSORS ============== 
	unsigned int NodeCount() const;

	// ============== INSERTIONS ============== 
	void AddHead(const T& data); // INSERTION 1
	void AddTail(const T& data); // INSERTION 2
	void AddNodesHead(const T* data, unsigned int count);
	void AddNodesTail(const T* data, unsigned int count);

	// ============== CONSTRUCTORS ============== 
	LinkedList();

	// ============== DESTRUCTOR ============== 
	~LinkedList(); // DEFAULT CONSTRUCTOR

private:
	Node* _head; // HEAD
	Node* _tail; // TAIL
	unsigned int _count;  // COUNT

};

template <typename T>
unsigned int LinkedList<T>::NodeCount() const {
	return _count;
}

template <typename T>
void LinkedList<T>::AddHead(const T& data) // INSERTION 1
{
	Node* newNode = new Node(data); // CREATE A NEW NODE ALWAYS TO THE FRONT
	newNode->next = _head; // SET NEWNODE NEXT POINTER TO WHATEVER _HEAD WAS
	if (newNode->next == nullptr) // IF LIST WAS EMPTY 
	{
		_tail = newNode; // TAIL POINTS TO NEW NODE
	}
	_head = newNode; // HEAD POINTS TO NEW NODE
	_count++; // INCREMENT COUNT. 
}

template <typename T>
void LinkedList<T>::AddTail(const T& data) // INSERTION 2
{
	Node* newNode = new Node(data); // CREATE A NEW NODE ALWAYS TO THE BACK


	if (_head == nullptr) // IF LIST WAS EMPTY 
	{
		_head = newNode; // HEAD POINTS TO NEW NODE
		_tail = newNode; // TAIL POINTS TO NEW NODE
	}
	else // IF LIST HAS NODES
	{
		_tail->next = newNode; // THE PREVIOUS TAIL NEXT NODE POINTS TO THE NEW NODE
		_tail = newNode; // SET TAIL TO NEW NODE
	}
	_count++; // INCREMENT COUNT.
}

template <typename T>
LinkedList<T>::LinkedList() // DEFAULT CONSTRUCTOR
{
	_head = nullptr;
	_tail = nullptr;
	_count = 0;
}

template <typename T>
LinkedList<T>::~LinkedList() // DESTRUCTOR
{
	Node* currentNode = _head; // START AT HEAD NODE

	while (currentNode != nullptr) // WHILE THE CURRENT NODE IS NOT NULLPTR
	{
		Node* nextNode = currentNode->next; // SAVE THE NEXT NODE POINTER
		delete currentNode; // DELETE THE CURRENT NODE
		currentNode = nextNode; // SET CURRENTNODE TO THE NEXT NODE
	}
}