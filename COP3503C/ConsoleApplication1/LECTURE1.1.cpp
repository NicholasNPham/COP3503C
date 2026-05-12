/**
* 
From code to Program
- Preprocessing: Creates "units" of code for compiling.
-Compiling: Ensures the units are valid C++ code
- Linking: Combine valid C++ code into an executable

Preprocessor:
- Searches projects files from top to bottom for preproccessor directives
- Keywords beginning with #
- Performs the necessary steps for each of these.
- Creates translation units from the results

Translation Unit
- From the C++ Standard
	- A soruce file (a .cpp file) becomes a translation unit (some may call it a compilation unit)

Compiling:
- Checks all of your translation units for proper syntax
- Creates objects files from your translation units
- Object files contain machine code that our computer will understand.
- We write "high Level" instructions, and the compiler converts that to machine instructions.

Compile Errors:
- If there are any compiler erros in the translation unit, no object file is created.
- If there are any erros in this stage, the linking state wont start, and the build process ends.

Linking:
- The file stage, combines object fiels into an executable (or a library, more on that later!)
- Errors at this state are not always easy to interpret (especially for new programmers)

Compiler Errors vs. Linker Errors:
- Compiler Errors:
	- Somthing is wrong syntactically
		- Missing Semi-colon
		- Type with a function
		- Function expects a stirng, you passed an int
		- This is invalid C++ code

- Linker Errors:
	- some definition is missing
		- Some function definition doesnt exist or cant be found
		- Some library (and its functions) doesnt exist or cant be found.

Declaration
- Creates an identifier that can be referenced elsewhere in our code
- Identifieres are the variables, functions, and user-defined types (clases) we need to make our program work.
- Referencing an identifier that doesn't exist is a compiler error

 */