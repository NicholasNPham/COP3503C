#include <iostream>
#include <fstream>
#include <vector>
#include "Hero.h"
using namespace std;

int demo2()
{
	Hero h2("Batman", 50, 120);
	Hero h3;

	// Write the heroes to a file
	ofstream outFile("data/heroes.bin", ios_base::binary);

	Hero h1("Thor Odinson", 100, 250);
	// string/variable data needs to be written in a 2 step process
	// 1. Write the AMOUNT of data
	// 2. Write the data itself

	string name = h1.get_name();
	unsigned int length = name.size() + 1; // +1 for \0
	outFile.write(reinterpret_cast<char*>(&length), sizeof(length));
	outFile.write(name.c_str(), length);

	int strength = h1.get_strength();
	outFile.write(reinterpret_cast<char*>(&strength), sizeof(strength));

	int hitpoints = h1.get_hitpoints();
	outFile.write(reinterpret_cast<char*>(&hitpoints), sizeof(hitpoints));

	return 0;
}