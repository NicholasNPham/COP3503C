/*
* 
* Static is a Modifier for Variables and Functions
* - We can use additional keywords to assign properties to variables.
* - One of those is staticm and goes in front of the declaration of a vraiable or function
* 
* Static Local Variables
* - Static variables are stored in memory differently than local variables
* - Normal local variables will fall out of scope when the function ends
* - Static variables are initialized once and then stay in memory for the rest off our program
* - If the function is called again the variable retains its value from the previous function call.
* 
* Static Member Variables
* - Normally, each instance of a class has its own copy of member variables. 
* - A static valss member belongs to the class, not indiviual instance.
* - Only one copy of that variable exist.
* - All instance of the class share access to it. 
* 
* Initializing Static Class Variables
* - Static variables must be redeclared and initialized outside of the class
* 
* Static Member Functions
* - Like static variables, static functions belong to the class, and not a specific instance of it
* - Static functions arn't invoked from an object, but from the class. 
* - Static functions have no this pointer, and cant access non-static member variables.
* 
* Static Functions Can Only Access Static Class Members
* - Static members functions dont have this pointe.
* - Static member functions cant access non-static member variables
* 
* Why Use These?
* - Sometimes we want to write a class for the usual reasons (encapsulation), but we dont want or need more than once instance.
* - It might be helpful to have "universal" access to the one instance of all the information.
* - Imaging a utility class that prints debugging messages and writes them to a file.
* - Access to that functionality outside of a class instance
*/