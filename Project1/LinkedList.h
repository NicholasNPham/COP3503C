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
	void PrintForwardRecursive(const Node* node) const; // BEHAVIOR 3
	void PrintReverseRecursive(const Node* node) const; // BEHAVIOR 4

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
	void InsertAfter(Node* node, const T& data); // INSERTION 5
	void InsertBefore(Node* node, const T& data); // INSERTION 6
	void InsertAt(const T& data, unsigned int index); // INSERTION 7

	// ============== REMOVALS ============== 
	bool RemoveHead(); // REMOVAL 1
	bool RemoveTail(); // REMOVAL 2
	unsigned int Remove(const T& data); // REMOVAL 3
	bool RemoveAt(unsigned int index); // REMOVAL 4
	void Clear(); // REMOVAL 5

	// ============== OPERATORS ============== 
	const T& operator[](unsigned int index) const; // OPERATOR 1
	T& operator[](unsigned int index); // OPERATOR 2

	// ============== CONSTRUCTORS ============== 
	LinkedList(); // DEFAULT CONSTRUCTOR
	LinkedList(const LinkedList<T>& list); // COPY CONSTRUCTOR
	LinkedList<T>& operator=(const LinkedList<T>& rhs); // ASSIGNMENT OPERATOR
	bool operator==(const LinkedList<T>& rhs) const; // == OPERATOR OVERLOADING

	// ============== DESTRUCTOR ============== 
	~LinkedList(); // DEFAULT DESTRUCTOR

private:
	Node* _head; // HEAD
	Node* _tail; // TAIL
	unsigned int _count;  // COUNT

};

// ============== BEHAVIORS ==============
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
void LinkedList<T>::PrintForwardRecursive(const Node* node) const { // BEHAVIOR 3

	if (node == nullptr) // BASE CASE: IF NODE IS NULLPTR THATS THE END OF THE LIST
	{
		return; // RETURN NOTHING
	}
	else // OTHERWISE IF 
	{
		cout << node->data << endl; // PRINT OUT NODE DATA
		PrintForwardRecursive(node->next); // CALL THE FUNCTION AGAIN WITH PASSED IN NODE TO THE NEXT NODE
	}
}

template <typename T>
void LinkedList<T>::PrintReverseRecursive(const Node* node) const { // BEHAVIOR 3

	if (node == nullptr) // BASE CASE: IF NODE IS NULLPTR THATS THE END OF THE LIST
	{
		return; // RETURN NOTHING
	}
	else // OTHERWISE IF 
	{
		cout << node->data << endl; // PRINT OUT NODE DATA
		PrintReverseRecursive(node->prev); // CALL THE FUNCTION AGAIN WITH PASSED IN NODE TO THE PREVIOUS NODE
	}
}

// ============== ACCESSORS ============== 
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

// ============== INSERTIONS ============== 
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
		newNode->prev = _tail; // SET NEW NODES PREVIOUS TO POINT TO WHAT TAIL IS
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
void LinkedList<T>::InsertAfter(Node* node, const T& data) // INSERTION 5
{
	Node* tempPtr = node->next; // INIT TEMP PTR TO SAVE THE NEW NODES PREVIOUS NODE POINTER POINTING TO NEXT NODE

	Node* newNode = new Node(data); // CREATE A NEW NODE 

	newNode->prev = node; // SET NEW NODES PREVIOUS TO POINT TO PASSED NODE
	newNode->next = tempPtr; // SET NEW NODE TO POINT TO THE SAVED TEMP PTR

	node->next = newNode; // PASSED IN NODE NEXT POINTS TO NEW NODE

	if (tempPtr == nullptr) // IF TEMP PTR IS NULLPTR
	{
		_tail = newNode; // TAIL IS SET TO NEW NODE
	}
	else
	{
		newNode->next->prev = newNode; // OTHERWISE NEWNODES NEXT NODE PREVIOUS POINTS TO THE NEW NODE
	}
	
	_count++; // INCREMENT
}

template <typename T>
void LinkedList<T>::InsertBefore(Node* node, const T& data) // INSERTION 5
{
	Node* tempPtr = node->prev; // INIT TEMP PTR TO SAVE THE NEW NODES PREVIOUS NODE POINTER POINTING TO NEXT NODE

	Node* newNode = new Node(data); // CREATE A NEW NODE 

	newNode->next = node; // SET NEW NODE TO POINT TO PASSED IN NODE

	node->prev = newNode; // NODE NOW PREVIOUS POINTS TO NEW NODE

	if (tempPtr == nullptr) // IF TEMP PTR IS NULLPTR
	{
		_head = newNode; // HEAD IS NOW NEW NODE
	}
	else
	{
		newNode->prev = tempPtr; // NEW NODES PREVIOUS POINTS TO THE TEMP PTR
		newNode->prev->next = newNode; // NEW NODES PREVIOUS POINTED NODE NEXT NODE POINTS TO NEW NODE
	}
	_count++; // INCREMENT
}

template <typename T>
void LinkedList<T>::InsertAt(const T& data, unsigned int index) // INSERTION 7
{
	if (index > _count) // IF INDEX IS GREATER THAN THE COUNT THROW ERROR
	{
		throw std::out_of_range("INVALID INDEX, THE LIST DOES NOT HAVE THAT MANY INDICES");
	}
	else if (index == 0) // IF PASS INDEX IS 0 ADD HEAD FUNCTION IS CALLED TO THE FRONT
	{
		AddHead(data);
	}
	else if (index == _count) // IF INDEX EQUALS COUNT THEN ADD TAIL FUNCTION IS CALLED TO THE BACK
	{
		AddTail(data);
	}
	else // ANYWHERE IN BETWEEN INSERT THE NEW NODE BEFORE THE INDEX
	{
		InsertBefore(GetNode(index), data);
	}
}

// ============== REMOVALS ============== 
template <typename T>
bool LinkedList<T>::RemoveHead() // REMOVAL 1
{
	if (_count == 0) // IF COUNT EQUALS TO 0
	{
		return false; // RETURN FALSE MEANING THERE IS NOTHING IN THE LIST
	}

	Node* tempPtr = _head; // SAVE THE HEAD NODE IN INIT TEMP PTR

	_head = tempPtr->next; // THE NEW HEAD IS NOW THE NEXT NODE

	if (_head != nullptr) // IF HEAD IS NOT NULL PTR
	{
		_head->prev = nullptr; // THE NEW HEAD NODE PREVIOUS POINTS TO NULL PTR
	}
	else 
	{
		_tail = nullptr; // OTHERWISE (MEANING ONLY ONE NODE AND WAS REMOVED) TAIL NOW POINTS TO NULL PTR
	}

	delete tempPtr; // DELETE THE TEMP PTR

	_count--; // DECREMENT COUNT
	return true; // RETURN TRUE MEANING SUCESSFUL REMOVAL
}

template <typename T>
bool LinkedList<T>::RemoveTail() // REMOVAL 2
{
	if (_count == 0) // IF COUNT EQUALS TO 0
	{
		return false; // RETURN FALSE MEANING THERE IS NOTHING IN THE LIST
	}

	Node* tempPtr = _tail; // SAVE THE TAIL NODE IN INIT TEMP PTR

	_tail = tempPtr->prev; // THE TAIL NODE IS NOW THE PREVIOUS NODE

	if (_tail != nullptr) // IF TAIL IS NOT NULL PTR
	{
		_tail->next = nullptr; // THE NEW TAIL NODE NEXT POINTS TO NULL PTR
	}
	else
	{
		_head = nullptr; // OTHERWISE (MEANING ONLY ONE NODE AND WAS REMOVED) HEAD NOW POINTS TO NULL PTR
	}

	delete tempPtr; // DELETE THE TEMP PTR

	_count--; // DECREMENT COUNT
	return true; // RETURN TRUE MEANING SUCESSFUL REMOVAL
}

template <typename T>
unsigned int LinkedList<T>::Remove(const T& data)
{
	unsigned int countDeleteNodes = 0; // INIT COUNT DELETE NODES AND STORE 0
	Node* currentNode = _head; // INIT CURRENT NODE AS THE HEAD OF THE LIST

	while (currentNode != nullptr) // WHILE CURRENT NODE DOES NOT EQUAL NULL PINTER
	{

		Node* tempPtrNext = currentNode->next; // SAVE THE NEXT POINTER FROM CURRENT NODE BEFORE WE DELETE IT

		if (currentNode->data == data) // IF CURRENT NODE DATA == DATA PASSED IN
		{
			if (currentNode == _head) // IF CURRENT NODE EQUALS _HEAD
			{
				RemoveHead(); // REMOVE THE HEAD POINTER AND CALL FUNCTION
			}

			else if (currentNode == _tail) // IF CURRENT NODE EQUALS _TAIL
			{
				RemoveTail(); // REMOVE THE TAIL POINTER AND CALL FUNCTION 
			}
			else
			{
				currentNode->prev->next = currentNode->next; // THE CURRENTS NODES PREVIOUS NODE WILL NOW POINT TO CURRENT NODES NEXT NODE
				currentNode->next->prev = currentNode->prev; // THE CURRENTS NODES NEXT NODE WILL NOW POINT TO CURRENT NODES PREVIOUS NODE
				delete currentNode; // DELETE THE NODE BECAUSE WE ALREADY SAVE IT ABOVE
			}
			countDeleteNodes++; // INCREMENT
		}
		currentNode = tempPtrNext; // CURRENT NODE NOW IS THE TEMP PTR CURRENT NEXT NODE
	}
	return countDeleteNodes; // RETURN COUNT. 
}

template <typename T>
bool LinkedList<T>::RemoveAt(unsigned int index) // REMOVAL 4
{
	if (index >= _count) // IF INDEX IS GREATER THAN THE COUNT RETURN FALSE
	{
		return false; // RETURN FALSE
	}
	else if (index == 0) // INDEX IS AT 0
	{
		RemoveHead(); // CALL REMOVE HEAD
		return true; // RETURN TRUE
	}
	else if (index == _count - 1) // IF INDEX IS AT THE TOP OF THE LIST
	{
		RemoveTail(); // CALL REMOVE TAIL
		return true; // RETURN TRUE
	}
	else // IF IN THE MIDDLE OF THE HEAD AND TAIL
	{

		Node* currentNode = GetNode(index); // GET THE CURRENT NODE WITH INDEX PASSED IN
		currentNode->prev->next = currentNode->next; // THE CURRENTS NODES PREVIOUS NODE WILL NOW POINT TO CURRENT NODES NEXT NODE
		currentNode->next->prev = currentNode->prev; // THE CURRENTS NODES NEXT NODE WILL NOW POINT TO CURRENT NODES PREVIOUS NODE
		delete currentNode; // DELETE THE NODE BECAUSE WE ALREADY SAVE IT ABOVE
		_count--; // DECREMENT
		return true; // RETURN TRUE
	}
}

template <typename T>
void LinkedList<T>::Clear() // REMOVAL 5
{
	Node* currentNode = _head; // START AT HEAD NODE

	while (currentNode != nullptr) // WHILE THE CURRENT NODE IS NOT NULLPTR
	{
		Node* nextNode = currentNode->next; // SAVE THE NEXT NODE POINTER
		delete currentNode; // DELETE THE CURRENT NODE
		currentNode = nextNode; // SET CURRENTNODE TO THE NEXT NODE
	}

	_head = nullptr; // RESET HEAD
	_tail = nullptr; // RESET TAIL
	_count = 0; // RESET COUNT
}

// ============== OPERATORS ============== 
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

// ============== CONSTRUCTORS ============== 
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
bool LinkedList<T>::operator==(const LinkedList<T>& rhs) const { // == OPERATOR OVERLOADING
	
	if (this->_count != rhs._count) // CHECK TO SEE IF A COUNT IS THE SAME AS RHS (B) COUNT
	{
		return false; // RETURN FALSE IF IT ISNT THE SAME
	}

	Node* currentListA = this->_head; // INIT CURRENT LIST A WITH A _HEAD
	Node* currentListB = rhs._head; // INIT CURRENT LIST B WITH B _HEAD

	while (currentListA != nullptr && currentListB != nullptr) // WHILE LOOP OF LIST A AND LIST B CONTINUE IF ITS NOT NULL PTR
	{
		if (currentListA->data != currentListB->data) // IF LIST A DOES NOT EQUAL LIST B
		{
			return false; // RETURN FALSE
		}
		currentListA = currentListA->next; // LIST A NEXT NODE AND SET IT TO CURRENT LIST A NODE
		currentListB = currentListB->next; // LIST B NEXT NODE AND SET IT TO CURRENT LIST B NODE
	}
	return true; // AFTER ALL THESE CHECKS RETURN TRUE
}

// ============== DESTRUCTOR ============== 
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

