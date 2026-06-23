#include <iostream>
#include <fstream>
#include <vector>
#include "Hero.h"
using namespace std;

int main()
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

	return 0;
}