#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include "Hero.h"
using namespace std;

// wizard.h
class Wizard : virtual public Hero // Wizard IS-A Hero
{
	int _mana; // magic energy
	int _max_mana; // magic energy
public:
	Wizard(string name = "Nick", int strength = 10, int hitpoints = 25, int mana = 100);
	void PrintInfo(bool verbose = false) const;
	void take_damage(int amount);

	// Unique Wizard Behaviors
	void FireBall(Hero& target)
	{
		target.take_damage(50 + _mana);
	}
	void Fly();
	void Invisibility();
};

// wizard.cpp
Wizard::Wizard(string name, int strength, int hitpoints, int mana)
	: _mana(mana), Hero(name, strength, hitpoints)
{
	_max_mana = _mana;
}
void Wizard::PrintInfo(bool verbose) const {
	// print the hero-specific info
	Hero::PrintInfo(verbose);
	// print wizard-specific info
	cout << "Mana: " << _mana << " / " << _max_mana << endl;
}
void Wizard::take_damage(int amount)
{
	int damageAbsorbed = 0;
	if (_mana >= amount)
	{
		// take 0 damage, our magic barrier negates all of it!
		damageAbsorbed = amount;
		_mana -= amount;
		amount = 0;
		cout << get_name() << " absorbs " << damageAbsorbed << " damage" << endl;
	}
	else if (_mana < amount)
	{
		damageAbsorbed = _mana;
		cout << get_name() << "'s magical barrier absorbed " << damageAbsorbed << " damage" << endl;
		amount -= _mana;
		_mana = 0;
	}
}

class Fighter : virtual public Hero
{
	int _fury; // fight for longer, get angrier
	int _maxFury;
public:
	Fighter(string name = "Nick", int strength = 10, int hitpoints = 25);
	void FuriousStrike(Hero& target);
	void PrintInfo(bool verbose = false) const;
	void BodySlam(Hero& target);
	void take_damage(int amount);
};
Fighter::Fighter(string name, int strength, int hitpoints)
	: Hero(name, strength, hitpoints), _fury(0), _maxFury(100)
{
}
void Fighter::PrintInfo(bool verbose) const {
	// print the hero-specific info
	Hero::PrintInfo(verbose);
	// print wizard-specific info
	cout << "Fury: " << _fury << " / " << _maxFury << endl;
}
void Fighter::take_damage(int amount)
{
	Hero::take_damage(amount);

	int furyGained = amount * 0.5f;
	cout << get_name() << " gains " << furyGained << " fury! ";
	_fury += furyGained;
	if (_fury > _maxFury)
	{
		_fury = _maxFury;
	}
	float furyRatio = (float)_fury / _maxFury;
	if (furyRatio > 0.8f)
	{
		cout << get_name() << " is furious!" << endl;
	}
	else if (furyRatio > 0.5f)
	{
		cout << get_name() << " is heating up!" << endl;
	}
	else if (furyRatio > 0.25)
		cout << get_name() << " is starting to get angry..." << endl;
}

int main()
{

	vector<Hero*> heroes;
	heroes.push_back((new Wizard("Merlin", 15, 70, 250)));
	heroes.push_back((new Fighter("Conan", 80, 350)));

	cout << "Heroes are delt 100 damage...\n";
	for (unsigned int i = 0; i < heroes.size(); i++)
	{
		heroes[i]->take_damage(100);
	}
	
	for (unsigned int i = 0; i < heroes.size(); i++)
	{
		delete heroes[i];
	}

	return 0;
}