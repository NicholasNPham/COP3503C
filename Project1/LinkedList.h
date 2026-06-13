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
	void AddHead(const T& data);
	void AddTail(const T& data);
	void AddNodesHead(const T* data, unsigned int count);
	void AddNodesTail(const T* data, unsigned int count);

	// ============== CONSTRUCTORS ============== 
	LinkedList();

	// ============== DESTRUCTOR ============== 
	~LinkedList();

private:
	Node* _head; // HEAD
	Node* _tail; // TAIL
	unsigned int _count;  // COUNT

};

template <typename T>
LinkedList<T>::LinkedList()
{
	_head = nullptr;
	_tail = nullptr;
	_count = 0;
}