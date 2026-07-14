#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int demo2()
{
	unordered_map<string, vector<string>> dictionary;
	ifstream inFile("dictionary.txt");

	// -------------- LOAD DICTIONARY DATA FROM A FILE
	string lineFromFile;
	while (getline(inFile, lineFromFile))
	{
		// BREAK THE LINE INTO TWO PARTS : WORD | DEFINITION
		int delimiter = lineFromFile.find_first_of('|');
		string word = lineFromFile.substr(0, delimiter);
		string definition = lineFromFile.substr(delimiter + 1);

		// STORE THE PAIR
		dictionary[word].push_back(definition);

	}

	cout << "Number of entries: " << dictionary.size() << endl;

	string input;
	cout << "enter a word: ";
	getline(cin, input);

	vector<string>& defs = dictionary[input];
	for (unsigned int i = 0; i < defs.size(); i++)
	{
		cout << defs[i] << endl;
	}

	return 0;
}