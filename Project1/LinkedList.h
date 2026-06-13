#pragma once
#include <iostream>
#include <vector>
using std::cout;
using std::endl;

// ============== CLASS DEFINITION ============== 
template <typename T>
class LinkedList
{
private:
	// HEAD
	// TAIL
	// COUNT

public:
	// NESTED NODE CLASS
	struct Node
	{
		// ============== STRUCT DEFAULT PUBLIC ==============
		T data;
		Node* next;
		// ============== CONSTRUCTORS ============== 
		Node(const T& value);

	};



};