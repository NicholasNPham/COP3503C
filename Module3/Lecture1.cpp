#include <iostream>

/*
LECTURE 1: PASSING DATA BY REFERENCE AND BY POINTER

The World "STACK" in different situations
- A location in memory tracking stac frames
	- The stack, part of the amazing duo, Stack and Heap
- A list of functions currently executing in a program
	- The call stack, which is stored on The Stack
- A last-in, first out data structure
	- class Stack {}; (More on this later)

The Stack
- Summary
	- The stack is a region of memory that tracks stack frames
	- A stack frame is a chunck of memory contains the information necessary to execute a function
		- Memory for variables created in that function
		- Memory for passed-in parameters
		- Memory address of previous stack frame
	- The ordering of a stack is last-in, first out.
		- Similar to a stack of books, or a deck of cards 
*/

// Call stack example

//  int main() 
//  {
//		Initialize(1280, 720);
//		Run();
//		return 0;
//  }

//	void Initalize(int win_x, int_y)
//	{
//		create_window(win_x, win_y); When this function is finished it gets popped off the stack (ie it gets removed)
//		load_models();
//		load_textures();
//		load_sounds();
//	}

//	void load_models()
//	{
//		load_environment_models();
//		load_player_models();
//	}



/*
          The Stack v1
--------------------------


	create_window(1280, 720)
	Initialize(1280, 720)
    main()
*/

/*
		  The Stack v2
--------------------------

	load_environment_models() get popped from  the stack
	load_models()
	Initialize(1280, 720)
	main()
*/

/*
		  The Stack v3
--------------------------

	load_player_models() get popped from the stack
	load_models()
	Initialize(1280, 720)
	main()
*/

/*
		  The Stack v4
--------------------------

	load_textures()
	Initialize(1280, 720)
	main()
*/

/*
etc, as the program runs, the stack is constantly growing and shrinking
It's actually just using more or less of the block of memory that is "the stack"
*/

// STACK FRAME VISUALIZED

//	void Bar(int count)
//	{
//		int* ptr = new int[count];
//		double pi = 3.14f;
//		OtherFunction(pi, ptr);
//	}
//	void Foo()
//	{
//		int x = 5;
//		int y = 10;
//		int z = 12;
//		Bar(10);
//	}
//	int main()
//	{
//		Foo();
//	}

/*
		  The Stack Visualized from the Example Above
-----------------------------------------------
	Local Variables (if any)                                 - Frame for OtherFunction()
	previous function: Bar()
	ptr
	pi
	ptr - local variables                                    - Frame for Bar()
	pi (3.14f) - local variables 
	Previous function: Foo() - Previous function
	count = 10 - Parameter
	x (5)                                                    - Frame for Foo()
	y (10)
	z (12)
	Previous function: main() - pointer to previous function
*/

/*
Size of a stack frame
- The size of any variables declared, plus pointers to previous functions, plus the size of parameters
- The size is determined by the compiler during the build process
- At runtime, these stack frames get pushed or popped

Stack Pointer:
- A Stack Pointer points to the current stack frame
- The pointer moves to different address as functions are called (or as they end)
- Moving this pointer is very fast, and takes almost no time at all
- Usually moves downwards towards the end build start with building the stack first. 
*/

/*
		  The Stack 
--------------------------
	Main() ------------------ High Memory Address   
	Initalize()                    |
	LoadModels()                   V
	LoadEnvironmentModels() - Low Memory Address

Stack Memory Allocation May be Reversed
- We may think of a stack as growing up (ie stacking books)
- In practice is may be the opposite: the stack grows down
- Subsequent frames are added to lower addresses

Stack Memory is Limited
- Depends on the operating System, Possibly compiler settings
- Typically small, only a few megabytes in size
	- You can still create a lot of data in a few megabytes
	- 1 megabyte can be -250.000 integers, -125,000 doubles
- This can affect how you can create objects in your code.
- Too much data on the stack? You can cause a stack overflow error.

Stack Overflow Error:
- Too much memory allocated on the stack
- Every variable occupies some amount of memory
- Every function call occupies some amount of memory
- It all adds up!
- Having 1 large variable or many smaller variables doesnt matter: try to use too much memory, and your program breaks.
*/

// Stack Overflow from Recursion Example:

//	int Factorial(int value)
//	{
//		return value * Factorial(value - 1);
//	}
//
//	int main()
//	{
//		cout << Factorial(5);
//		return 0;
//	}

/*
		  The Stack 
--------------------------
	stack overflow error
	Factorial(int value = -2)
--------------------------------
	Factorial(int value = -1)
	Factorial(int value = 0)
	Factorial(int value = 1)
	Factorial(int value = 2)
	Factorial(int value = 3)
	Factorial(int value = 4)
	Factorial(int value = 5)


What if you need Large Amounts of Memory?
- Then, you dynamically allocate memory on the heap
	
	void SomeFunction()
	{
		int bigArray[300000]; - This data is allocated on the heap instead of the stack and bigArray is on the stack (all local variables here) but it points to memory on the heap
		// Do some stuff
	}

The Heap is for Dynamic Memory
- The heap is for data we cant put on the stack:
	- Large amounts - no stack overflow!
	- Data we don't want to "fall out of scope"
	- Data whose size we dont know at compile time
- Heap memory is allocated, or reserved with new
	- It must be deallocated or freed with delete.
- Much slower than the stack
	- But it must be used in many cases
	- Use the stack when you can, the meap when you must

Heap and the "Free Stor"
- Heap and Stack are general computing concepts
- The C++ standard doesn't mention heap and stack anywhere
	- You may hear the heap called the free store.
	- The C++ Standard uses automatic and dynamic storage.
	- Conceptually, The same thing:
		- Stack: Automatic Storage
		- Heap: Dynamic Storage

Heap and Stack Memory Grow Towards Each Other

		  The Stack
--------------------------
			Main()              - High Memory Address
		Initialize()					|
^		load_models()					| - Stack Allocation Moves Towards Heap
|	load_environment_models()			|
|		 unused memory					V
|		 heap memory - Low Memory Address
|
L - Heap Allocation Moves towards the Stack
	 
Stack variables Vs. Heap Variables
- All local variables are on the stack (in automatic storage)
- All Dynamically Allocated Memory is on the Heap
	 
When Does Heap Data "Disappear
- Stack-Based Variables get "Deleted" when they go out of scope
	- When their function comes off the call stack
	- The space they once occupied will later be overwritten.
- Stack-Based memory is suitable for temporary data.
	- Create some variables, used them, then forget about them
- Heap data lives on "forever"
	- It nevers falls out of scope.
	- You must delete it
	- Most operating systems will free up memory when a program ends
*/
