/*
* Objects should be Initialized Before Use
* 
* Constructors:
* - Class members functions are used top initalize an object.
* - Constructors are called only once, when an object is first instantiated
* - The function mae is the same as the class
* - There is no return type (not even void)
* 
* Constructor: Usage
* - The number of arugments may change, but the intent of a construtor is always the same: initilze an object.
* - The class will use those parameters for whatever it needs in the implemntation of those functions
* 
* Defautl Constructors
* - A specific form of constructor that either:
*	- take s no arguments, or takes in all default arguments
* - A class can have many constructors, but no more than one default
* - Defaults arguments can be helpful shortcut and they provode you with convienent options
* 
* Quick Detour to Defualt Arguments
* - Once you assign one argument a default value, all arguments after that must also have a defualt value.
* 
* What if you dont write a constructor
* - If you dont write one an implicit constructor is created.
* - It takes no arguments and does nothing but qualifies as a defualt
* - Without a default constructor you can create an array of object of this type (each element in the array gets the default constructor called)
* 
* Destructors:
* - Class members functions that is automatically invoked when an object falls out of scope
* - The last function an object invokes
* - Used to clean up the object
* - A variable can fall out of scope when:
*	- A function ends
*	- A program ends
*	- A block of code ends
*	- The delete keyword is called on a dynamically allocated pointer (this is a later topic)
* 
* Destructors: What do they do?
* - Whatever a class needs to finish its job
* - For many classes, that might be nothing at all. 
* - Critical when dynamic memory is involved (More on this later)
* 
* Do you have to write a destructor?
* - C++ requires a destructor for all classes
* - If you dont write one, an implicit destructor is created for you.
* - If you dont use dynamic memory then you probably dont need a destructor
*/