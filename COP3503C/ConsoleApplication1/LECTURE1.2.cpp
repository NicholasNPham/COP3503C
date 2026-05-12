/*
Scope:
- The scope is where an identifier is accessible in your code.
- We can't access variables and functions outside of their scope.
- Every language has different rules for scope, typically multiple scopes.
- Scope can be broad or narrow, and variables may be more or less accessible. 
 
Local Scope:
- Variables or parameters you declare inside a function
- Only accessible iside that function

Statement Scope:
- The most narrow scope,. used for temporary variables
- Variables that are declared inside if statements and loops

Falling out of Scope:
- When a function or code block ends, that scope is over.
- Variables declared in that scope will fall out of scope.
- We often need variables to persist for longer.
- For that, we need a "broader" scope.

- Class Scope:
	- Variables (and functions) that are accessible in a class, or through an instance of that class.
- Namespace Scope:
	- Lets us put variables and functions in a "module" of sorts
- Global Scope:
	- A scope that esists outside and above all other. 

Namespace:
- a way to group variables anf functions together
- A way to clearly indicate what your code is referencing
- Helpful in avoiding collisions with other code.

Scope Resolution Operator: (SRO)
Symbol ::
- Indicates the scope something belongs to
- The primary usage will see in this course is for classes and namespaces.
- The syntax is the same., regardless of which scope were accessing.

*/