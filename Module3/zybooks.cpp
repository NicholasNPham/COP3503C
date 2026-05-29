/*
What is a pointer?
- A pointer is a variable that contains a memory address.
- A pointer is a variable that holds a memory address, rather than holding data like most variables

Why use pointers?
- A program often needs to support data of varying sizes.
	- Using a predefined fixed-size array may either waste memory or limit the program's usefulness

10.1.2 Partiticipation Activity
1. How should a programmer define a fixed size array to support existing users?
" Maximum daily sales across all users"
- To support as many users as possible, the array should be large enough to stroe all the sales for the user with the highest daily sales.

2. If the program is designed to support a maximum of 1,000,000 daily sales, what percentage of the array is needed for a small business with only 1,000 daily sales?
"0.1%"
- Using a predefined fixed-size array to support users with different amounts of data can waste memory

3. If the array size must be inccreased to support a new user with a higher number of daily sales, how is the memory usage of other users affected?
"More memory is allocated and is wasted"
- More memory is allocated for the larger array, but existing users do not need the increased capacity. So the memory is wasted.

A program can use a dynamically allocated array to effeciently handle different amounts of data. A dynamically allocated array is an array whose size and memory location are determined during runtime. 

1. What memory addresses were used for the dailySales array?
"100 and 400"
- The initial array with 100 elements was located at address 100. When the array capacity was increased to 200, the new array was located at address 400. The dailySales pointer stores the array's memory address to keep track of the array's location.

2. If the dailySales array is again increased to store up to 400 elements, the new array's memory location will be _____.
"Known only at runtime"
- The memory location of the new array will be determined by the system at runtime, and will vary each time the program executes. The dailySales pointer is assigned the array's memory location anytime the array's capacity changes.

3. Data that is stored in memory and no longer being used should be deleted to free up the memory.
"True"
- Computers come with a finite amount of memory. If an array that is no longer used continues to take up memory, a memory leak could occur and eventually the computer could run out of usable memory (and crash). Unused allocated memory should be freed. Memory leaks are discussed in more detail elsewhere.

Inserting data in arrays/vectors vs linked lists
- An array (or vector) stores elements in continguous memory locations, which enables fast access to any element using the element's index.
- A programmer can used a linked list to make inserts faster.
- A linked list consists of items that contains both data and a pointer (or link) to the next list items. 

1. Insert an item at the front of a 999-element array.
"999"
- Inserting at the front requires making room for the new element. So every current element must be shifted once.

2. Insert an item at the front of a 999-item linked list.
"0"
- The new item's next pointer is assigned to point to the item at the front of the list. The new item then becomes the front of the list. No shifting of other items is required.

3. Inserting a new item between the 10th and 11th items of a 999-item linked list.
"0"
- No shifting of other items is required, which is an advantage of using pointers.

4. Remove an item from the front of a 999-element array.
"998"
- After the first item is deleted, 998 elements remain. Each must be shifted in order to fill the gap of the removed item.

5. Remove an item at the front of a 999-item linked list.
"0"
- The front of the list can be updated to point to the second item. So, no shifting of other items is required.

10.4 Dynamically allocating objects

What does the declaration of a pointer look like?
- A pointer is declared by including * before the pointer's name.

10.4.2
Pointer: A variable that holds a memory address.
- A class pointer is used to point to a dynamically allocated object.

New: The operator that allocates memory for the given type and returns a pointer to the allocated memory.
- A dynamically allocated object is created using new. Once created, the object is accessed using a pointer.

Constructor: A special class function that is called automatically when a variable of that class type is declared.
- When an object is dynamically allocated, the new operator calls the class' constructor after allocating memory for the class' member variables.

1) The new operator returns _____.
"a pointer"
- The new operator returns a pointer to the allocated memory.

2) When used with a class type, the new operator allocates memory _____ calling the class' constructor.
"before"
- The memory is allocated first. Then, the constructor is called.

3) The new operator _____.
"Allocates but does not deallocate memory"
- The delete operator, discussed later in this section, deallocates memory allocated with the new operator.

Member Access Operator

What is the membership operator?
- When using a pointer to an object, the member access operator (->) allows access to the object's members with the syntax a->b

Dereference operator

What does it mean to dereference a pointer?
- The dereference operator (*) is prepended to the pointers variable's name to retrieve the data to which the pointer variable points
- The * operator and the . operator may be combined to access a dynamically allocated object's member as in (*a).b instead of a-> b.

What is the function of new and delete?
New: The operator that allocates memory for the given type and returns a pointer to the allocated memory.
Delete: Deallocates a block of memory that was allocated with the new operator.

Memory Regions Heap/Stack
- Code: The region where the program instructions are stored
	- Instructions are stored in this region
- Static Memory: The region where glabel variables (variables declared outside any function) as well as static local variables (variables declared inside functions starting with the keyword 'static') are allocated. Static variables are allocated once and stay in the same memory location for the duration of a program's execution
	Global and static local variables are allocated in this region once for the duration of the program

What is the stack and the heap?
- The Stack: The region whre a function's local variables are allocated during a function call. A function call adds local variables to the stack, and a return removes them, like adding and removing dishes from a pile; Hence the term "stack" because this memory is automatically allocated and deallocated, it is also called automatic memory
	- The stack a Functions local variables are allocated in this region while a function is called
- The Heap: The region where the "new" operator allocates memory, and where the "delete" operator deallocates memory. The region is also called free store.
	- The memory allocation and deallocation operator affect this region
	- Another name for the heap because the programmer has explicit control of this memory

	- Automatic memory
	- Another name for "the stack" because the programmer does not explicitly control this memory. 


10.11 Memory Leaks
- Memory Leak
	- A memory Leak occurs when a program that allocates memory loses the ability to access the allocated memory typically due to failure to properly destroy/free dynamically allocated memory.
	- A programs leaking memory becomes unusable, much like a water pipe might have water leaking out and become unusable,
	- A memory leak may cause a program to occupy more and more memory as the program runs, which slows programruntime. 
	- Even worse, a memory leak can cause the program to fail if memory becomes completely full and the program is unable to allocate additional memory

Pass by Reference
Instructor Note:
- In C++ Pass by value is the default for all data types. Passing by reference (or by pointer) requires additional work on the part of the programmer.
- In same languages like java this is somewhat reversed: Class Objects (but not primitive types) are passed by reference by default, and the programmer must go out of their way to create copies of objects)

pass by reference
- New programmers sometimes assign a value to a parameter, believing the assignment udpates the corresponding arugment variable
- an example situation is when a function should return two values, whereas a function's return construct can only return one value, assigning a normal parameter fails to update the argument's variable because normal parameters are passed by value, meaning the parguments values is copied into a local variable for the paremeter. 

- C++ supports another kind of parameter that enables updating of an argument variable.
- A pass-by-reference parameter does not create a local copy of the argument, but rather the parameter refers directly to the argumenty variables memory location
- Appending & to a parameters data type makes the parameter pass-by-reference type

Remember; 
- the & (Ampersand) in a function directly affects the variables that are initialized in main.
- so if main has variables like int it finds the memory address that is located in main and directly affects the variables in main from the function. 
- ComputeChange uses & because you need 4 values back and return can only give you one
- GallonsToLiters uses return because only one value comes back, no need to touch main's memory
- InchToCm uses return because one input one output, you can even skip the variable and return the formula directly
- GetUserFullName uses void and & because two strings need to come back and return can only handle one, function does the cin internally and fills main's empty boxes directly
- Circle area and diameter get split into two separate functions with return because they are independent of each other and separately useful, no need for & when each function only outputs one thing
- Pass by value gives the function a copy of the variable, original is never touched, use it when you only need to read the input and return one thing back
- MetersToFeetInches uses pass by value for the input userMeters and pass by reference for userFeet and userInches because you need two outputs back and the input never needs to be modified
- When you see & parameters don't create extra local variables, just use them directly because they already ARE main's variables, if you're assigning back and forth you forgot what & is doing

*/