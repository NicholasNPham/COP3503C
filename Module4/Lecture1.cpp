/*
What are the "Big Three"?
- Three Class Member Functions
	- Copy Constructor
		- Used to construct an object from another, existing object
	- Copy Assignment Operator
		- Used to copy one object into another object
	- Destructor
		- Used when an object is destroyed-When it falls out of scope, or when delete is called on a pointer to an opbect
- Implicity Created Functions
	- The compiiler writes one for you, if you don't. (why? because C++ requires objects to have these functions)
	- They are written in a standard way, which might be what you need. Or... that standard functionality will break your program
- These special function which, if you do not declare them, get implicity created for you. 
	- The implicit version are not necessarily what you want in your own program.
	- Especially if you are using dynamic memory

COPY CONSTRUCTOR
- A special constructor which is called when, and only when, a class object is initialized with another instance of the same class
- The purpose is to construct a new object, as a copy of the other object.
- Copy primative is easy; How exactly do we copy objects? Like any other class operation, with a function.

How do you copy?
- Style Reminder:
	- You dont have to use this keyword and the indirect membership operator is access variables in a class; it's implied if you leave it out
	- Member-to-member copy: this->_name = otherObject._name;
	- The implicitly created copy constructor will do exactly this, if you don't write it.
	- You dont have to write this unless you are dealing with dynamic memory

How Can We Acess Private Variables?
	- if all of the variables are private, how can we access them after "... = otherObject._name"
		- Wouldnt we use accessor functions
	- Because that is a membver function of lineItem class, it "knows" about private variables
	- Its like two members of a club knowing something about the club that isnt made open to the public
	- Quick reminder: this-> can be ommited if you want; its optional

Copy Constructor Syntax

class ExampleClass
{
public:
	ExampleClass(const ExampleClass& otherObject);
};

	- The copy constructor will always have this format:
		- ExampleClass(const ExampleClass& otherObject);
	- One parameter, always; a constant reference to some instance of this class
	- A reference to pass it quickly
		- Paass by value would crate a copy and call this very function - hello infinite recursion
	- A const reference, so we don't change the other thing
	- Eachy copy constructor works defferently, but the "signature" of each is the same: a constructor with a const reference to an instance of the class

COPY ASSIGNMENT OPERATOR
- A function that is called when you assign an existing object to another existing object
- They are largely similar to copy constructors, with a few differences.
- They will overwrite existing values (a copy constructor has no "old" values to overwrite)
- They can be invoked more than once on an object (copy constructors can only be called once)

- It always has a specific return type "return *this;"

Copy Assignment Operator Syntax

class ExampleClass
{
public:
	ExampleClass& operator=*(const ExampleClass& otherObject)

- "ExampleClass&" : Return type: Always a non-const reference to an instance of this class
- "Operator=" : Not a type , the name of this function is operator=
- "(const ExampleClass& otherObject)" : This is an example of operator overloadin

- One perameter, always: a constant reference to some instance of this class
- A reference, to pass it quickly
- A const reference, so we don't change the other thing. 

Why do we return anything at all
- return *this;
	- this is a pointer to an object not an object
	- This function returns a reference to an object.
	- By dereferencing this, we get an object to which we can bind a reference.
	Why do all that? The reason for all of this, is so we can do this:

THE DECONSTRUCTOR
- A function which is called when an object is destroyed, either
	- when it falls out of scope(like a temporary variable in a function) or...
	- When delete is called on a pointer to an object
- The purpose of the deconstructor is to clean up or "shutdown" an object, which could involve
- Deleting any dynamically allocated memory
	- This is going to be the one we worry about in this course. 
- Possibly notifying another object/function that destruction has occurred.
- Possiblity printing something out to a screen as a result of this object finishing its task

Destructor Syntax

class ExampleClass
{
public:
	(tilda)ExampleClass(); //Prototype
};

ExampleClass::{tilda}ExampleClass() // Definition
{

}
	
- The name of the fuction is like a constructor ( the name of the class, but with a tilde in front of the function)
- The inplicitly declared version of any destructor does... absolutely nothing.
- The assumption is, you have nothing to clean up (ie no new memory you have to delete)

WHY DO YOU NEED THE BIG THREE?
- Programs copy lots of objects and the data they contain.
- Dynamically allocated data must be copied differently, because of pointers.
- Pointers only store memory addresses, the location of the real data.
- Copy pointers (locations) is a shallow copy
- To copy the data itself, we want to perform a deep copy.
- Deep copy means allocating more space for a copy of the dat
- Also we have to clean it up (deconstructors)

- Dangling Pointer: A pointer tha does not poiunt to valid memory
- It points to something but isnt really usable

THE BIG THREE ARE VITAL
- Objects get copied time and again in our code.
- Our code has to use memory properly, classes especially.
- We can't always (easily) tell where these functions will get used in our program

THE RULE OF THREE
- if you write on of hte big three, you sould write the other two, for example
	- if you write a destructor to clean up dynamic memory
		- you need a deep copy support (the other "big two")
	-in Reverse: if you have deep copy support for dynamic memory (in one, maybe two places!)...
		- you need to delete that dynamic memory!
	- Modern C++ extends this to the big five but we wont worry about the other two funcitons ( they are for optimization and not strictly necessary).

RECAP
- The big three are specail class member functions to handle dynamic mem ory properly
	- Copy constructor, copy assignment operator, and the destructor
- We have to write them for classes that use dynamic memory.
- Implicitly-defined versions work without dynamic memory
	- Copy constructor: Member-to-member copy
	- Copy assignment operator: member-to-member copy
	- Destructor: empy, does nothing!
- To copy dynamic memory properly, we use a deep copy.

*/