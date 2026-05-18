/*
* What is Object-Oriented Programming (OOP)?
* - A programming paradign that emphasizes that use of objects.
* - Objects represent the data for aspect of a program.
* - Objects may also contain functions to operate on that data.
* - To create these objects in code, we write classes
* 
* Why use Objects?
* - Encapsualation
*	- Groupe data and functionality together
* - Create a public interface, do the 'real work' in private
*	- High the details and ctrol access to data
*	- Analogy:
*		- A light switch (interface) verses the wiring in the wall (behind-the-scenes implementation)
* - Code Reuse
*	- Once a class is created, you can instantiate that class
*	- Instatiation creates an instance of the class, a copy of the data and fuctionality.
*	- You can create as many instances as you want, and never have to redefine the class again.
*
* What should be a Class?
* - What are the separate parts of your program?
* - What data needs to be stored for those to work properly?
* - Imagine a program that needs to stroe books
* - Create a public interface, do the "real work" in private
* - All of those variables could be stored together in a class
* 
* Programs Have lots of classes
* - Imaging a game with the following characteristics
*	- Score counter
*	- Ships that fly vertically
*   - Enemies that fly horizontally
* - Different things in the game which have possible classes
* - Even a simple grograms can have alot of classes
* 
* Class Components
* - Member variables (data)
*	- The data of your class is storing
*	- Some languages my call these "fields" or "properties"
* - Member functions (behavior)
*	- These allow you to operate on the data of your class
*	- Some languages may call these "methods" or "procedures"
* - Accessibility Keywords
*	- Defines a region of public, private, or protected accessibility (more on this soon)
*
* Key Functions in a Class
* - Accessors:
* 	- Get functions retrieve something from the class
* - Mutators:
*	- Set functions change something about the class
* - Constructors:
*	- Build the object in a variety of ways
*		- A constructor is only every called once, when an object is first created.
*		- You can define multiple constructors for option/flexibility
* - Destructors:
*	- Destroy the object (only one per class)
*		- Called automatically when an object falls out of scope
*		- Used to "finalize" the object, perform any last steps
*		- Not always needed
* - Every class can be diffeerent and have any number of member functions and variable.
* 
* Access Levels
* - Public:
* 	- Accessible from anywhere in the program
*	- Public members are accessible everywhere.
*	- Use this sparingly, especially for member variables
*	- In general, we want to hid data as much as we can. 
* - Private:
*	- The default Accessibility, only code within class functions (i.e. the class itself) can access
*	- Trying to access private data outside of a class results in a compiler error. 
*	- To avoid undesired changes, as much data as possible should be private, to restrict damages. 
*	- Generally speaking: use private variables, public functions
* - Protected:
*	- This only applies when using inheritance, which well cover later.
* 
* Accessibility Style:
* - Classes members are private by default, so no accessibility indicator is ncessary
* - Once you create a public region, everything that follows is public, A private keywoard is required in this case to indicate private members.
* 
* How do we Access Class Members?
* - We use the membership operation (.) to access members of a class or invoke a member function
* - This indicates the variable or function being accessed "belongs" to the object. 
* 
* Structures, a similar Concept to Classes
* - C++ has the struct keyword from the C Language
*	- Other languages may have this as well
*	- Typically it is similar to a class, but many have minor differences. 
*	- In C++, a structure is exactly like a class except for one, and only one difference:
* 		- Everything in a structure defualts to public accessibility, instead of private, in classe . 
* - For all other purposes, structures and classes are the same
* - All class concedpts also apply to structures, and vice versa
* 
* Why even use Structures?
* - Structures can be good for siple objects
* - Objects that are only a collection of data, with no complex functionality.
* 
* Similarities with Other Languages
* - The core idea of a class object is more or less universla
*	- Encapsulate data and functionality
* - Syntactical difference are always a thing across languages.
* - When dealing with dynamic memory, things get much more complicated
* - Not all laungages use dynamic memory
* 
* Writing Classes in C++
* - Class files are typically split into two files
*	- Header File (.h) or (.hpp)
*		- The initial definition of the class itself
*	- Source File (.cpp)
*		- Where class memeber functions are defined
* 
* Two Files: Good Practice
* - Separating classes into two files helps with organization
*	- Most C++ code follow this convention.
* - You can write a class entirely in the header file.
*	- In some cases, we have to 
* - Get into the habit of breaking all classes into two sepaate files
*	- Header files:
*		- Classes definition, member function prototype
* 	- Source files:
*		- Member function definitions
* 
* Classes and the this variable
* - All calsses have a variable they can access called "this"
* - This is a pointer to the current object, and can be used to access members of the class- It is implicity pass to all class member functions
*	- It is implicity passed to all class member functions
* - This represents the invoking object - The object that called the function
*	- Technially its a pointer to the invoking object (more on pointers later)
* - It lets you reuse code in a class member function
*	- The same code can operate on differnet instances of class variables
* - It can resolve ambiguity between member variables and local function variables. 
* 
* Where Does this Come From?
* - It comes from the object that called the function (ie the invoking object)
* - A pointer to the object is passed to the function, automatically
* 
* Why this -> an d not this. 
* - In C++, this is a poitner to the invoking object
* - Java use the period for accessing memebers of a class
* - C++ does as well but for objects not pointers. 
*/