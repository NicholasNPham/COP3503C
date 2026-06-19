#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Hero.h"
using namespace std;

void ReadFromHeroesFile(string filePath, vector<Hero>& output)
{
	// READ A DATA FILE WITH A COUNT
	ifstream inFile(filePath);
	if (inFile.is_open())
	{
		// 1. READ THE COUNT
		int count;

		string dataFromFile;
		getline(inFile, dataFromFile); // READ 3

		// CONVERT TO AN INTEGER
		count = stoi(dataFromFile);
		for (int i = 0; i < count; i++)
		{
			string name;
			getline(inFile, name); // READ 3


			// GET THE STRENGTH VALUE
			getline(inFile, dataFromFile);
			int strength = stoi(dataFromFile);

			// GET THE HITPOINTS VALUE
			getline(inFile, dataFromFile);
			int hitpoints = stoi(dataFromFile);

			Hero heroObjectFromFileData(name, strength, hitpoints);
			output.push_back(heroObjectFromFileData);
		}
	}
	else
	{
		cout << "Error! File " << filePath << " Could not be opened!" << endl;
	}
}
void ReadFromCSVFile(string filepath, vector<Hero>& output)
{
	// READ A CSV FILE
	ifstream csv(filepath);

	// 1. READ THE HEADER FROM THE FILE AND IGNORE IT
	string lineFromFile;
	getline(csv, lineFromFile);
	cout << "Header: " << lineFromFile << endl;

	// 2. GET RAW DATA FROM THE FILE ONE LINE AT A TIME
	while (getline(csv, lineFromFile))
	{

		// 3. CONVERT THAT LINE STRING INTO A STREAM OF DATA 

		istringstream stream(lineFromFile);
		Hero someObject;
		someObject.Deserialized(stream);
		output.push_back(someObject);

	}
}

int main()
{
	vector<Hero> heroes;
	vector<Hero> heroes_csv;
	ReadFromHeroesFile("data/info.heroes", heroes);

	ReadFromCSVFile("data/heroes.csv", heroes_csv);

	for (unsigned int i = 0; i < heroes_csv.size(); i++)
	{
		heroes_csv[i].PrintInfo();
	}

	return 0;
}
