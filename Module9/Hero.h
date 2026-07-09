#pragma once
#include <string>
#include <fstream>
#include <sstream>
using std::istringstream;
using std::ofstream;
using std::ifstream;
using std::string;

// Class definition
class Hero
{

	// Data to represent our hero
	string _name;       // Who is this?
	int _strength;      // How strong are they?
	int _hitpoints;     // How much damage can they take?
	int _max_hitpoints; // maximum amount of health
	int _level;         // What level are they?
	int _experience;    // Get experience points to level up!

	void level_up();
protected:
	

public:
	// Prototype == Delcaration

	Hero(string name = "Nick", int strength = 10, int hitpoints = 25);

	void PrintInfo(bool verbose) const;

	/* =============== ACCESSORS ===============*/
	string get_name() const;
	int get_strength() const;
	int get_hitpoints() const;
	int get_level() const;
	int get_experience() const;

	int get_power_level() const;

	/* =============== MUTATORS ===============*/

	// This is actually being used
	void set_hitpoints(int value);

	// example work
	void set_name(string name);
	void set_strength(int value);
	void set_level(int value);
	void set_experience(int value);

	virtual void take_damage(int amount);
	void get_healing(int amount);

	void gain_experience(int amount);

	void Serialize(ofstream& outFile);
	void Deserialized(ifstream& inFile);

	virtual ~Hero();
};