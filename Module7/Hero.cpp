#include "Hero.h"
#include <iostream>
#include <sstream>
using std::istringstream;
using std::ofstream;
using std::string;

using namespace std;

Hero::Hero(string name, int strength, int hitpoints)
{
	// User parameters for initialization
	_name = name;
	_strength = strength;
	_hitpoints = hitpoints;
	_max_hitpoints = hitpoints;

	// Use defaults
	_level = 1;
	_experience = 0;

}

void Hero::PrintInfo()
{
	cout << "Name: " << _name << endl;
	cout << "Strength: " << _strength << endl;
	cout << "Hitpoints: " << _hitpoints << " / " << _max_hitpoints << endl;
	cout << "Level: " << _level << endl;
	cout << "Experience: " << _experience << " / 100" << endl;
	cout << "Power Level: " << get_power_level() << endl;
}

string Hero::get_name()
{
	return _name;
}

int Hero::get_strength()
{
	return _strength;
}

int Hero::get_hitpoints()
{
	return _hitpoints;
}

int Hero::get_level()
{
	return _hitpoints;
}

int Hero::get_experience()
{
	return _experience;
}

int Hero::get_power_level()
{
	return _level * 5 + _strength;
}

void Hero::set_name(string name)
{
	_name = name;
}

void Hero::set_hitpoints(int value)
{
	if (value > 500)
		value = 500;
	if (value < 1)
		value = 1;
	_hitpoints = value;
}

void Hero::take_damage(int amount)
{
	_hitpoints -= amount;

	if (_hitpoints < 0)
		_hitpoints = 0;
}

void Hero::get_healing(int amount)
{
	_hitpoints += amount;

	if (_hitpoints > _max_hitpoints)
		_hitpoints = _max_hitpoints;
}

void Hero::gain_experience(int amount)
{
	_experience += amount;

	while (_experience >= 100)
	{
		level_up();
	}
}

void Hero::level_up()
{
	_level++;
	_strength++;
	_hitpoints += 5;
	_max_hitpoints += 5;
	_experience -= 100;

}

void Hero::Serialize(ofstream& outFile)
{
	outFile << _name << ",";
	outFile << _strength << ",";
	outFile << _hitpoints << ",";
	outFile << _max_hitpoints << ",";
	outFile << _level << ",";
	outFile << _experience << ",";
}

void Hero::Deserialized(istringstream& stream)
{
	// 4. BREAK THAT STREAM INTO TOKENS (ACCORDING TO ITS DATA)
	string nameToken;
	getline(stream, _name, ',');

	string token;
	getline(stream, token, ',');
	_strength = stoi(token);


	getline(stream, token, ',');
	_hitpoints = stoi(token);


	getline(stream, token, ',');
	_max_hitpoints = stoi(token);


	getline(stream, token, ',');
	_level = stoi(token);


	getline(stream, token, ',');
	this->_experience = stoi(token);




}