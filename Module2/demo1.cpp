#include <iostream>
#include <string>
using namespace std;

class Hero
{

	// Data to represent our hero
	string name;    // Who is this?
	int strength;   // How strong are they?
	int hitpoints;  // How much damage can they take?
	int level;      // What level are they?
	int experience; // Get experience points to level up!

public:
	// Prototype == Delcaration
	Hero(); // Default Constructor

	void PrintInfo();

};

// Function Definitions
Hero::Hero()
{
	name = "nick";
	strength = 1;
	hitpoints = 1;
	level = 1;
	experience = 0;
}

void Hero::PrintInfo()
{
	cout << "Name " << name << endl;
	cout << "Strength " << strength << endl;
	cout << "Hitpoints " << hitpoints << endl;
	cout << "level " << level << endl;
	cout << "experience " << experience << endl;
}

int hero()
{
	Hero my_hero; // An Instance of the Hero Class
	my_hero.PrintInfo();


	return 0;

}