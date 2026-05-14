#include <iostream>
#include <string>
using namespace std;

void print_message(string message)
{ 
	cout << message << endl;
}


int demo4()
{
    char some_string[] = "Batman";
	char other_string[] = "askl;dfl;akjsfkjl;3klj;";

    char some_array[7];
	some_array[0] = 'B';
    some_array[1] = 'a';
    some_array[2] = 't';
    some_array[3] = 'm';
    some_array[4] = 'a';
    some_array[5] = 'n';
    some_array[6] = '\0'; // \n Nul null-terminating charactor, indication the end of a string
    

	// prints the string "Batman" because of the null-terminating charactor at the end of the array
	//cout << some_array << endl;


    const char* also_a_string = "Hello, World";
    
    char* not_const_but_a_string = other_string;

    string instance_of_Std_String = "Also a string!(More than a char* though).";

    string name = "Batman";
	name.append(" and Robin");

    print_message(name);



    string message = "Hello, World!";

    int comma_location = 0;

    comma_location = message.find_first_of(",");

    string first_half = message.substr(0, comma_location);
	cout << "First Half: " << first_half << endl;
    string second_half = message.substr(comma_location + 2, 5);
	cout << "Second Half: " << second_half << endl;


	// Task: Find the location of the comma in the message string

 //   cout << "Comma is at: " << comma_location << endl;

	//unsigned int search = message.find_first_of("$");
 //   if (search == string::npos)
 //   {
	//	cout << "Couldn't Find the Dollar Sign!" << endl;
 //   }


	// Task: Find the location of the comma in the message string

    //for (unsigned int i = 0; i < message.size(); i++)
    //{
    //    if (message[i] == ',')
    //    {
    //        comma_location = i;
    //        break;

    //    }
    //}
    //
    
    
    
    
    
    
    
    
    
    
    
    //name += " and ";
	//name += "Robin";

 //   string password_1 = "password";
	//string password_2 = "PasSwOrd";

 //   if (password_1 == password_2)
	//	cout << "The passwords are the same!" << endl;
 //   else
	//	cout << "The passwords are different!" << endl;


	//cout << "Number of Characters: " << name.size() << endl;

	//int count = 0;
	//for (unsigned int i = 0; i < name.size(); i++)
 //   {
 //       if (name[i] == 'a')
 //           count++;
 //   }
 //   cout << "Number of occurrences of 'a': " << count << endl;



    return 0;
}
