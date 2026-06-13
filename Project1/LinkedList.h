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
	Node* head; // HEAD
	Node* tail; // TAIL
	unsigned int count;  // COUNT

};