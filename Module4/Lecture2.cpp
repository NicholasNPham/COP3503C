/*
WHAT IS A CONST
- A keyword to protect data - marks a variable as  constant.

	const int maxPlayers = 4;
	const float pi = 3.14159f;

- Also used when Passing by Reference (or by pointer)

	void Print(const object& param);
	void print(const SomeClass* parameter);

- Also used when returning references and pointers

	class Container
	{
		int* dynamicArray;
	public:
		const int* GetData()
		{
			return dytnamicArray;
		}
	};

CONST AND POINTER
- The const keyword can be used in three ways with pointers;
	- Protect the thing the pointer points to (the pointee)
	- Protect the pointer itself
	- Using both the frist and second simultaneously
- Prootecting the pointer is like laminating a piece of paper with an address on it.
- You cant change whats on the piece of paper, but you can change the house
- Protecting the pointee is like building a wall around the building 
- No change of any kind
	- Const pointer to a const int - no change to either pointer or the pointee
	- When you want to be really sure there are no unexpected changes
	
CONST AND CLASS FUNCTION
- Const protects the safety of this inside of a class funciton
- The const keyword after a function;s parameter list marks its as a const member function 

CONST MUMBER FUNCTIONS PROTECTS THIS FROM CHANGES
- no code in that function can change the this pointer
- this essentially makes this "read only" for  this situation

CONST HAS A WAY OF SPREADING

CONST AND NON-CONST VERSIONS FO FUNCTIONS
- Imagine two separate functions you might write elsewhere in your program

WHEN SHOULD YOU USE IT?
- Think about what your code needs to do
- For member functions
	- Is it to retrieve some information (accessor)?
		- use const
	- Is a function meant to change the object *mutator) dont use const.
	- What about return types and parameters?
	- Ask the same questions
		- For parameters and return types:
			- Unless you can state reasons for doing it otherwise, default to passing all class objects by const reference or const pointer. 

	RECAP
	- const is a way marking variables or function as constant or read only
	- Its purpose is to minimize side effects in your code and prevent unwanted changes.
	- The compiler enforces const, and generates erros if we violate it
	- This is especially useful when passing/returning pointers or refernces.
	- We can create const variables, or const clas member functions
	- Const class members functions to protect the invoking object by preventing changes to *this. 
	*/