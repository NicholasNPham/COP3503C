#include <iostream>
#include <fstream>
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

int main()
{
	vector<Hero> heroes;
	ReadFromHeroesFile("data/info.heroes", heroes);

	// 2. FOR (COUNT)
	for (unsigned int i = 0; i < heroes.size(); i++)
	{
		heroes[i].PrintInfo();
	}
	
	// 3. READ INDIVIDUAL OBJECTS

	// READ A CSV FILE
	ifstream csv("data/heroes.csv");

	return 0;
}


