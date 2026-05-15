#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Remember to change back to main because of zybooks 'main'
int lab1()
{
    /* Type code here. */
    /* Overall flow of the program:*/

    string title;
    string column_1;
	string column_2;
    string input_string;
    vector<string> string_names;
	vector<int> int_values;

    // Get some input for the title
    cout << "Enter a title for the data:" << endl;
    getline(cin, title);
    cout << "You entered: " << title << endl;

    // Get some input for column header #1
    cout << "Enter the column 1 header:" << endl;
	getline(cin, column_1);
	cout << "You entered: " << column_1 << endl;

    // Get some input for column header #2
    cout << "Enter the column 2 header:" << endl;
    getline(cin, column_2);
    cout << "You entered: " << column_2 << endl;

    while (true) 
    {
        //Get input for a string
        cout << "Enter a data point (-1 to stop input):" << endl;
		getline(cin, input_string);
		int comma_pos = input_string.find(',');

        //Until the user types "-1":
        if (input_string == "-1")
        {
            break;
        }
        else if (input_string.find(',') == string::npos)
        {
            cout << "Error: No comma in string." << endl;
        }
        else if(input_string.find(',', comma_pos + 1) != string::npos)
        {
			cout << "Error: Too many commas in input." << endl;
        }

        //If valid...
        else
        {
            try
            {
                //   Split
				string data_point_left = input_string.substr(0, comma_pos);
                //   Validate second half of input
                string data_point_right = input_string.substr(comma_pos + 1);
                //   If also valid...
                int data_point_right_int_conversion = stoi(data_point_right);

                
				cout << "Data string: " << data_point_left << endl;
				cout << "Data integer: " << data_point_right_int_conversion << endl;

                // Store separate pieces
                string_names.push_back(data_point_left);
				int_values.push_back(data_point_right_int_conversion);
            }
            catch (invalid_argument)
            {
				cout << "Error: Comma not followed by an integer." << endl;
            }
        }

    }
    
    //Print out data in table format
    cout << setw(33) << right << title << endl;
	cout << setw(20) << left << column_1 << "|" << setw(23) << right << column_2 << endl;
	cout << "--------------------------------------------" << endl;

    for (unsigned i = 0; i < string_names.size(); i++)
    {
        cout << setw(20) << left << string_names[i] << "|";
        cout << setw(23) << right << int_values[i] << endl;
    }

    // Print out data in chart format
    for (unsigned i = 0; i < string_names.size(); i++)
    {
        cout << setw(20) << right << string_names[i] << " ";
        
        for (unsigned j = 0; j < int_values[i]; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}