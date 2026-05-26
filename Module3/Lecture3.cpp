/*
Dynamic Memory

What is it?
- Memory is allocated on the heap (The Free store in C++)
- Memory allocated, or reserved, using the new operator
- Memory that must be deallowcated with delete when no longer needed

Compilers need Constant INformation
- Your compiler needs to know the size od  data at compile time.
- This information ensures everything lines up in memory
- Non-constant data throws off this process.

Viewing The Address of SOmething
- Dynamic Allocations dont fall out of scope
- Once allocated with new, that memory is reserved until you deallocate it.
- Deallocated memoryt frees it, making it avilable for some future reservation.
- Dynamic memory is deallocated with the delete operator.
- We deallocate memory addresses, not variables (though pointer variables store the addresses!)

What are new and delete really?
- Behind the scene, new/delete are operators, special types of functions (more on this later)
	- New
	- delete

When do you delete Memory
- When your program no longer needs something
- Main() is just one function
	- Programs may have alot of processes, all with different goals
	- You have to decide it's best to create or delete something
- Classes have destructors which are called when objects fall out of scope ( or when delete is used to deallocate dynamic objects)
- Destructors are the perfect place for classes to delete memory (It's what they were made for!)

You Must Delete Dynamic Memory
- Some languages have memory management systems
	- Variables that are no longer used or referenced get flagged as garbage
	- Periodically, the garbage collector frees that memory.
	- These systems are done for the programmer automatically
- C++ Does not have a system like this - You have to clean up after yourslef
	- Some newer features mimic this, to an extent.
- It can be a massive headache but learning to do so can make you an effective programmer,
	- Even in situation where dynamic memory isnt a thing. 
*/