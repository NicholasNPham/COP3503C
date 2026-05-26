/*
Pointers and References

Memory
- All of the variables we use (and more!) reside somewhere in memory
- Exactly where is called its memory address
- AAddresses are numberic values typically represented in hexadecmial format
	- 0x00000000
	- 0x1c33f1978

Binary / Hex Representation of Values
- All data types are made of some number of bytes
- Integers are commonly 4 bytes

Memory Diagrams
- All of these can be valid there is nt one correct or universal representation
- Diagrams are just an approximation; operating systems are hardware determine the exact details
- We'll focus more on how to work with the system (and less on how the ststem of memory itself works)

Using Memory Address
- The actact address of something is often irrelevent to us
	- For example: Does it matter if we know a variable is stored at 0x0000000 ( most of the time no )
- The operating system determines what goes where in memory
	- Trust it to hand out the correct addresses
	- As long as you properly store and use the address of something, youll be fine
- Memory addresses can be used to hsare access to existing variables.
- This requries the use of pointers. 

What is a pointer?
- Fundamentally: a variable that contains a memory address
- A pointer points to" a memory address and something (i.e some value) exist at that location.
- That something may be referred to as the pointee
- A pointer can only point to one memory address at a time
- Multiple pointes can point to the same address (ie one pointee, multiple pointers pointing to it)

The Pointer Mantra
- Pointers point to memory addresses
	- Not to objects
	- Not to variables
	- But to memory addresses
- Repeat this until it sticks
	- We might say a pointer points to a particular variable

Viewing the Address of Something
- In C++, we can use the ampersand (&) to get the address of the variable..
- Put an ampersand in from of a variable to indicate you want to use the address, not the value

Pointers are just variables
- In C++, we use the astrisk to create a pointer variable
	- We also use this to access the pointee
- Just add the astrisk to the data type when declaring the variable

Basic Pointer Usage
- If pointers point to addresses, and the ampersand (&) can get the address of a variable
- Formal Description: The variable ptr points to the address of the number
	- ptr is the pointer
	- number is the pointee
- Informal Description: ptr points to the number; This is fine for everyday use however technically this is not exactly correct. 

Default Value of a Pointer
- No defualt value, just uninitalized
	- This could be any random value, which means any random memory address not a good idea
- Pointer should be initialized to the address of something
- If not something specific then nullptr (make it a null pointer)

Pointers in Memory
- Pointers are variables...
- ...and all variables reside in memory
- Therefore, pointers reside in memory...? 

Pointers and Arrays
- Some languages treat arrays as formal entities, typically as classes
- C++ Treats arrayts as essentially pointers to the first element of the array
	- This is an oversimplification, but good enough for this course.
- The name of an array is the same thing as the address of the first element. 
- A pointer only stores a single memory address
- The number of elements byond that isn't stored with the pointer
- Additional Variables (created by you must be used to track that data

Dereferencing Pointers
- To get the data from a memory address, we have to deference a pointer
- Dereferencing retrieves the value of the pointee from that location.
- To do so, we use the astrisk again, this time, opn an alreadyt-existing pointer

Dereferencing and Changing a Pointee
- Pointers give access (indirectly) to some original value.
- Simply dereference the pointer, then operate on it like a normal variable
- This is critial when we need to make changes in function and with classes. 

Dereferencing Null (or Bad) Pointers
- Dereferencing a pointe that is nullptr will probably though an exception.
- The same goes for derefgerencing a pointe that isnt nullptr, but also isnt valid (i.e doesnt point to something usable...)
- Officially it is undefined behavior, a common c++ phrase

Undefined Behavior
- Literally what it sounds like: Behavior that is not defined.
- T C++ standard defines what the language should do in many situations, but doesnt cover everything
- In those gray areas, your program can behave unexpectedly

Dereferencing Pointes  to Class Objects
- For objects, we use the membership operator .
- For pointers, instead we have to use the idirect membership operator.
- Why? Lets assume we have a pointer to an instance of a class object
	- Pointers dont have functions - Class objects do 
	- We need to first dereference the pointer 

Pointers Provide indirect access
- A pointer is not the thing.
- A pointer is the location where the memory can be found in memory
- Say you write down a house address on a piece of paper:
	- This is not a house
	- Here is an address whre a house can be found, if you go to that address the house will be there
	- Here is where we store the address of the house, not the house itself. 

Why Pointers:
- The primary reason is efficency
- Pointers lets us avoid making copies of everything
- Pointers are vey small in memory
	- Which is larger an address on a piece of paper of the house itself?
- Copying small data is trival, but large objects are costly
	- copying a small address is easy, but copy a house...
- Many concepts and algorithms are basically impossible if we dont use pointers.

REFERENCES

references
- Similar to Pointers (kind of)
- Pointers tell use the location of something else
- References act as a stand in or alias for anther variable
- A reference is the vbariable that is refgerences
	- Any changes to a reference changes the original
	- They dont use memory address, no dereferencing
- Created by using the ampersand (&) along with the regular datatype

References Rules:
- They must be initalized. No such thing as a null reference
- Once bound, they cannot be reassigned or re-bound (the data they refgerence, however can be changed)

Why should you use references
- They dont copy objects, which is a performance boost!
- They dont require addresses or dereferencing.
- Most of the vbenfits of pointers, with some of their own restrictions
- The recommended way of passing class objects around
- Use pointers when you need pointes, references in all other cases

Is there anything references cant do?
- You cvant create arrays of references.
	- No way to initialize all of them at the time of declaration
- You cant reassign references
	- Need to change targets? Select a different item in a list, a piece on a game board, player in a game?
	- Use a pointer for this! Its why they exist. 
*/