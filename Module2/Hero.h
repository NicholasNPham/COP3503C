#pragma once
#include <string>
using std::string;

// Class definition
class Hero
{

	// Data to represent our hero
	string _name;    // Who is this?
	int _strength;   // How strong are they?
	int _hitpoints;  // How much damage can they take?
	int _level;      // What level are they?
	int _experience; // Get experience points to level up!

public:
	// Prototype == Delcaration
	Hero(); // Default Constructor
	Hero(string name, int strength, int hitpoints);

	void PrintInfo();

};