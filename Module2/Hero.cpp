#include "Hero.h"
#include <iostream>
using namespace std;

// Function Definitions
Hero::Hero()
{
	_name = "Nick";
	_strength = 1;
	_hitpoints = 1;
	_level = 1;
	_experience = 0;
}

Hero::Hero(string name, int strength, int hitpoints)
{
	// User parameters for initialization
	_name = name;
	_strength = strength;
	_hitpoints = hitpoints;
	
	// Use defaults
	_level = 1;
	_experience = 0;

}


void Hero::PrintInfo()
{
	cout << "Name " << _name << endl;
	cout << "Strength " << _strength << endl;
	cout << "Hitpoints " << _hitpoints << endl;
	cout << "level " << _level << endl;
	cout << "experience " << _experience << endl;
}