#include "Hero.h"
#include <iostream>
using namespace std;

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
	cout << "Name: " << _name << endl;
	cout << "Strength: " << _strength << endl;
	cout << "Hitpoints: " << _hitpoints << endl;
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
	return _level * 5 +_strength;
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