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
	void PrintInfo();
	void TakeDamage(int amount);

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
	:_mana(mana), Hero(name, strength, hitpoints)
{
	_max_mana = _mana;
}

void Wizard::PrintInfo()
{
	// print the hero-specific info
	Hero::PrintInfo();
	// print wizard-specific info
	cout << "Mana: " << _mana << " / " << _max_mana << endl;
}

void Wizard::TakeDamage(int amount)
{
	int damageAbsorbed = 0;
	if (_mana >= amount)
	{
		damageAbsorbed = amount;
		// Take 0 damage, our magic barrier negates all of it
		_mana -= amount;
		amount = 0;
	}
	else if (_mana < amount)
	{
		damageAbsorbed = _mana;
		amount -= _mana;
		_mana -= 0;
	}

	cout << get_name() << " absorbs " << damageAbsorbed << " damage!" << endl;
	Hero::take_damage(amount);
}

class Fighter : virtual public Hero
{
	int _fury; // fight for longer, get angrier
public:
	Fighter(string name = "Nick", int strength = 10, int hitpoints = 25);
	void FuriousStrike(Hero& target);
	void BodySlam(Hero& target);
	void TakeDamage(int amount);
};

Fighter::Fighter(string name, int strength, int hitpoints)
	: Hero(name, strength, hitpoints), _fury(0)
{

}

void Fighter::TakeDamage(int amount)
{
	_fury += amount;

	Hero::take_damage(amount);
}

class BattleMage : public Fighter, public Wizard
{

};

int demo1()
{
	Wizard merlin("Merlin the Magnificent", 15, 70, 250);
	merlin.PrintInfo();
	merlin.TakeDamage(180);
	merlin.PrintInfo();
	merlin.TakeDamage(95);
	merlin.PrintInfo();

	Fighter conan("Conan", 80, 200);

	BattleMage omni;
	cout << omni.get_name();

	return 0;
}