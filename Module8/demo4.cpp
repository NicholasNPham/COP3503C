#include <iostream>
#include <fstream>
#include <vector>
#include "Hero.h"
using namespace std;

void WriteBinaryData()
{
	vector<Hero> heroes;
	Hero h1("Thor Odinson", 100, 250);
	Hero h2("Batman", 50, 120);
	Hero h3;

	heroes.push_back(h1);
	heroes.push_back(h2);
	heroes.push_back(h3);

	// Write the heroes to a file
	ofstream outFile("data/heroes.bin", ios_base::binary);

	// 1. Write the AMOUNT of data
	unsigned int count = heroes.size();
	outFile.write(reinterpret_cast<char*>(&count), sizeof(count));

	// 2. Write the data itself
	for (unsigned int i = 0; i < heroes.size(); i++)
	{
		heroes[i].Serialize(outFile);
	}
}

void ReadDataFromFile(vector<Hero>& heroes)
{
	// Load data into the program
	ifstream inFile("data/heroes.bin", ios_base::binary);

	// FILE FORMAT
	// 4 BYTE COUNT : THE NUMBER OF HERO OBJECTS
	// FOR EACH HERO OBJECTS
	// 4 BYTE COUNT : THE LENGTH OF HEROES NAME (STRING
	// COUNT BYTES : THE ACTUAL STRING FOR THE HEROES NAME
	// 4 BYTE STRENGTH
	// 4 BYTE HITPOINTS
	// 4 BYTE MAX HITPOINTS
	// 4 BYTE LEVEL
	// 4 BYTE EXPERIENCE

	unsigned int count;
	inFile.read(reinterpret_cast<char*>(&count), sizeof(count));

	for (unsigned int i = 0; i < count; i++)
	{
		Hero someHero;
		someHero.Deserialized(inFile);
		heroes.push_back(someHero);
	}
}

int main()
{
	vector<Hero> heroes;
	ReadDataFromFile(heroes);

	// use the data for some purpose


	return 0;
}