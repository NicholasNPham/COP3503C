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
	
	Hero(string name = "Nick", int strength = 10, int hitpoints = 25);

	void PrintInfo();

	/* =============== ACCESSORS ===============*/
	string get_name();
	int get_strength();
	int get_hitpoints();
	int get_level();
	int get_experience();

	int get_power_level();

	/* =============== MUTATORS ===============*/

	// This is actually being used
	void set_hitpoints(int value);

	// example work
	void set_name(string name);
	void set_strength(int value);
	void set_level(int value);
	void set_experience(int value);
};