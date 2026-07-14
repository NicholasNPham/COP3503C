#include <iostream>
#include <string>
#include <map>
using namespace std;

int demo1()
{
	// Store some quiz scores
	map<string, int> scores;

	// add 2 pairs<string, int> using emplace
	scores.emplace("Lee", 85);
	scores.emplace("Joseph", 78);

	// add 2 pairs<string, int> using operator[]
	scores["Alberto"] = 79;
	scores["Martina"] = 92;

	while (true)
	{
		string input;
		cout << "Enter a name to search for (-1 to quit): ";
		getline(cin, input);

		if (input == "-1")
		{
			break;
		}
		if (input == "size")
		{
			cout << "number of elements in the map: " << scores.size() << endl;
		}
		else
		{

			// 1. CONVERT USER INPUT TO LOWERCASE
			string inputLowerCase = input;
			for (unsigned int i = 0; i < inputLowerCase.size(); i++)
			{
				inputLowerCase[i] = tolower(inputLowerCase[i]);
			}
			cout << "Lowercase version of input: " << inputLowerCase << endl;

			bool found = false;
			// 2. ITERATE OVER ALL ELEMENTS IN THE CONTAINER

			for (map<string, int>::iterator iter = scores.begin(); iter != scores.end(); iter++)
			{
				// 3. CONVERT THE KEY OF AN ELEMENT TO LOWERCASE
				string keyLowerCase = iter->first;
				for (unsigned int i = 0; i < keyLowerCase.size(); i++)
				{
					keyLowerCase[i] = tolower(keyLowerCase[i]);

				}
				// 4. COMPARE THE LOWER_INPUT TO LOWER_KEY FOR A MATCH
				if (keyLowerCase == inputLowerCase)
				{
					// 5. PRINT THAT PARTICULAR ELEMENT
					cout << "the score for " << input << " is " << scores[iter->first] << endl;
					found = true;
					break;
				}

			}

			if (!found)
			{
				cout << "Person not found!" << endl;
			}
		}
	}

	return 0;

}