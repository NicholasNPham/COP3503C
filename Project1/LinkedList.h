#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <stdexcept>
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
		Node* prev;
		// ============== STRUCT CONSTRUCTOR ============== 
		Node(const T& value)
		{
			data = value;
			next = nullptr;
			prev = nullptr;
		}

	};

	// ============== BEHAVIORS ============== 
	void PrintForward() const; // BEHAVIOR 1
	void PrintReverse() const; // BEHAVIOR 2

	// ============== ACCESSORS ============== 
	unsigned int NodeCount() const; // ACCESSOR 1
	void FindAll(std::vector<Node*>& outData, const T& value) const; // ACCESSOR 2
	const Node* Find(const T& data) const; // ACCESSOR 3
	Node* Find(const T& data); // ACCESSOR 4
	const Node* GetNode(unsigned int index) const; // ACCESSOR 5
	Node* GetNode(unsigned int index); // ACCESSOR 6
	const Node* Head() const; // ACCESSOR 7
	Node* Head(); // ACCESSOR 8
	const Node* Tail() const; // ACCESSOR 9
	Node* Tail(); // ACCESSOR 10

	// ============== INSERTIONS ============== 
	void AddHead(const T& data); // INSERTION 1
	void AddTail(const T& data); // INSERTION 2
	void AddNodesHead(const T* data, unsigned int count); // INSERTION 3
	void AddNodesTail(const T* data, unsigned int count); // INSERTION 4

	// ============== OPERATORS ============== 
	const T& operator[](unsigned int index) const; // OPERATOR 1
	T& operator[](unsigned int index); // OPERATOR 2

	// ============== CONSTRUCTORS ============== 
	LinkedList(); // DEFAULT CONSTRUCTOR
	LinkedList(const LinkedList<T>& list); // COPY CONSTRUCTOR
	LinkedList<T>& operator=(const LinkedList<T>& rhs); // ASSIGNMENT OPERATOR

	// ============== DESTRUCTOR ============== 
	~LinkedList(); // DEFAULT DESTRUCTOR

private:
	Node* _head; // HEAD
	Node* _tail; // TAIL
	unsigned int _count;  // COUNT

};

template <typename T>
void LinkedList<T>::PrintForward() const { // BEHAVIOR 1
	Node* currentNode = _head; // START AT HEAD NODE

	while (currentNode != nullptr) // WHILE THE CURRENT NODE IS NOT NULLPTR
	{
		cout << currentNode->data << endl;
		currentNode = currentNode->next;
	}
}

template <typename T>
void LinkedList<T>::PrintReverse() const { // BEHAVIOR 2
	
	std::stack<T> stackObj; // CREATE AN EMPTY STACK OBJECT READY TO STACK (LIFO)
	
	Node* currentNode = _head; // START AT HEAD NODE

	while (currentNode != nullptr) // WHILE THE CURRENT NODE IS NOT NULLPTR
	{
		stackObj.push(currentNode->data); // PUSH TO STACK
		currentNode = currentNode->next; // SET CURRENT NODE TO NEXT NODE AND REPEAT
	}

	while (!stackObj.empty()) // WHILE THE STACK OBJECT IS NOT EMPTY
	{
		cout << stackObj.top() << endl; // PRINT TOP OF STACK
		stackObj.pop(); // POP TOP OF STACK AND REPEAT
	}
}

template <typename T>
unsigned int LinkedList<T>::NodeCount() const { // ACCESSOR 1
	return _count;
}

template <typename T>
void LinkedList<T>::FindAll(std::vector<Node*>& outData, const T& value) const {
	Node* currentNode = _head; // INIT CURRENT NODE TO HEAD OF LIST

	while (currentNode != nullptr) // WHILE CURRENT NODE DOES NOT EQUAL NULLPTR
	{
		if (currentNode->data == value) // IF CURRENT NODE DATA EQUALS VALUE
		{
			outData.push_back(currentNode); // PUSH CURRENT NODE POINTER TO VECTOR OUTDATA
		}
		currentNode = currentNode->next; // CONTINUE KEYWORD "CONTINUE" TILL THE END OF LIST NULLPTR
	}
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) const { // ACCESSOR 3
	Node* currentNode = _head; // INIT CURRENT NODE TO START OF THE LIST

	while (currentNode != nullptr) // WHILE CURRENT NODE DOES NOT EQUAL NULLPTR
	{
		if (currentNode->data == data) // IF CURRENT NODE DATA EQUALS DATA FROM PARAMETER
		{
			return currentNode; // RETURN CURRENT NODE POINTER 
		}
		currentNode = currentNode->next; // IF NOT SET CURRENT NODE TO NEXT NODE
	}
	return nullptr; // IF DATA PASSED IN PAREMETER NOT FOUND RETURN NULLPTR
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) // ACCESSOR 4
{
	Node* currentNode = _head; // INIT CURRENT NODE TO START OF THE LIST

	while (currentNode != nullptr) // WHILE CURRENT NODE DOES NOT EQUAL NULLPTR
	{
		if (currentNode->data == data) // IF CURRENT NODE DATA EQUALS DATA FROM PARAMETER
		{
			return currentNode; // RETURN CURRENT NODE POINTER 
		}
		currentNode = currentNode->next; // IF NOT SET CURRENT NODE TO NEXT NODE
	}
	return nullptr; // IF DATA PASSED IN PAREMETER NOT FOUND RETURN NULLPTR
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) const { // ACCESSOR 5

	if (index >= _count) // IF INDEX IS GREATER THAN THE COUNT OF THE LIST
	{
		throw std::out_of_range("INDEX NOT VALID OUT OF RANGE"); // THROW OUT OF RANGE ERROR
	}

	Node* currentNode = _head; // START THE CURRENT NODE AT THE HEAD

	for (unsigned int i = 0; i < index; i++) // START i AT 0, WHILE i IS LESS THAN INDEX, INCREMENT
	{
		currentNode = currentNode->next; // SET CURRENT NODE TO NEXT NODE
	}
	return currentNode; // AFTER FOR LOOP OF INDEX RETURN ADDRESS OF CURRENT NODE 
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) // ACCESSOR 6
{
	if (index >= _count) // IF INDEX IS GREATER THAN THE COUNT OF THE LIST
	{
		throw std::out_of_range("INDEX NOT VALID OUT OF RANGE"); // THROW OUT OF RANGE ERROR
	}

	Node* currentNode = _head; // START THE CURRENT NODE AT THE HEAD

	for (unsigned int i = 0; i < index; i++) // START i AT 0, WHILE i IS LESS THAN INDEX, INCREMENT
	{
		currentNode = currentNode->next; // SET CURRENT NODE TO NEXT NODE
	}
	return currentNode; // AFTER FOR LOOP OF INDEX RETURN ADDRESS OF CURRENT NODE 
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Head() const { // ACCESSOR 7
	return _head;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Head() // ACCESSOR 8
{
	return _head;
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Tail() const { // ACCESSOR 9
	return _tail;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Tail() // ACCESSOR 10
{
	return _tail;
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
	else
	{
		newNode->next->prev = newNode; // THE OLD HEAD NODE NOW WILL PREVIOUSLY POINT TO THE NEW NODE
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
void LinkedList<T>::AddNodesHead(const T* data, unsigned int count) // INSERTION 3
{
	for (int i = count - 1; i >= 0; i--) // SET i AS COUNT - 1, WHILE I IS GREATER OR EQUAL TO 0, DECREMENT
	{
		AddHead(data[i]); // ADDED TO FRONT OF LIST WITH DATA i
	}
}

template <typename T>
void LinkedList<T>::AddNodesTail(const T* data, unsigned int count) // INSERTION 4
{
	for (unsigned int i = 0; i <= count - 1; i++) // SET i AS 0, WHILE i IS LESS THAN OR EQUAL TO COUNT - 1, INCREMENT
	{
		AddTail(data[i]); // ADD TO THE BACK OF THE LIST WITH DATA i
	}
}

template <typename T>
const T& LinkedList<T>::operator[](unsigned int index) const { // OPERATOR 1
	Node* nodeData = GetNode(index); // INITIALIZE NODE DATA FROM RETURN FUNCTION GETNODE INDEX
	return nodeData->data; // RETURN THE NODE DATA FROM POINTER
}

template <typename T>
T& LinkedList<T>::operator[](unsigned int index) // OPERATOR 2
{
	Node* nodeData = GetNode(index); // INITIALIZE NODE DATA FROM RETURN FUNCTION GETNODE INDEX
	return nodeData->data; // RETURN THE NODE DATA FROM POINTER
}

template <typename T>
LinkedList<T>::LinkedList() // DEFAULT CONSTRUCTOR
{
	_head = nullptr;
	_tail = nullptr;
	_count = 0;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list) // COPY CONSTRUCTOR
{
	_head = nullptr; // INIT NEW LIST HEAD
	_tail = nullptr; // INIT NEW LIST TAIL
	_count = 0; // INIT COUNT AS 0

	Node* currentNode = list._head; // CURRENT NODE OF LIST IS AT HEAD OF LIST

	while (currentNode != nullptr) // WHILE LIST A CURRENT NODE IS NOT NULL POINTER
	{
		AddTail(currentNode->data); // ADD THE THE END OF THE LIST AND UPDATE TAIL
		currentNode = currentNode->next; // SET CURRENT NODE OF LIST AND SET TO NEXT
	}
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs)
{
	if (this == &rhs) // MAKE SURE YOUR NOT COPYING FROM THE SAME THING
	{
		return *this; // IF IT DOES == THEN RETURN *THIS
	}
	
	Node* currentNode = _head; // START AT HEAD NODE IF NOT ==

	while (currentNode != nullptr) // WHILE THE CURRENT NODE IS NOT NULLPTR
	{
		Node* nextNode = currentNode->next; // SAVE THE NEXT NODE POINTER
		delete currentNode; // DELETE THE CURRENT NODE
		currentNode = nextNode; // SET CURRENTNODE TO THE NEXT NODE
	}

	_head = nullptr; // INIT NEW LIST HEAD
	_tail = nullptr; // INIT NEW LIST TAIL
	_count = 0; // INIT COUNT AS 0

	Node* rhsNode = rhs._head; 

	while (rhsNode != nullptr) // WHILE LIST A CURRENT NODE IS NOT NULL POINTER
	{
		AddTail(rhsNode->data); // ADD THE THE END OF THE LIST AND UPDATE TAIL
		rhsNode = rhsNode->next; // SET CURRENT NODE OF LIST AND SET TO NEXT
	}
	return *this;
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

