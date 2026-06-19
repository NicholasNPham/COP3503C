#include <iostream>
#include <fstream>
#include <vector>
#include "Hero.h"
using namespace std;

int main()
{
	ofstream outFile("data/heroes.csv");
	Hero h1("Thor Odinson", 100, 250);
	Hero h2("Batman", 50, 120);
	Hero h3;

	vector<Hero> heroes;
	heroes.push_back(h1);
	heroes.push_back(h2);
	heroes.push_back(h3);

	// WRITE HEADER DATA TO THE FILE
	outFile << "Name," << "Strength" << ',' << "Hitpoints" << "," << "Max Hitpoints" << ',' << "Level" << "," << "Experience" << endl;

	for (unsigned int i = 0; i < heroes.size(); i++)
	{

		heroes[i].Serialize(outFile);

		if (i != heroes.size() - 1)
		{
			outFile << endl;
		}
	}
	return 0;
}