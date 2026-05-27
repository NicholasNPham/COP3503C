#include <iostream>
#include <string>
#include <vector>
#include "Hero.h"
using namespace std;

class Enemy
{
	Hero* _target; // Who is this enemy targeting/tracking/attacking/etc? # storing the address of a hero not the hero itself
public:
	void set_target(Hero* target);
	void print_target_info();
	void clear_target();
};

void Enemy::set_target(Hero* target)
{
	if (target != nullptr) // only set a target if the pointer is valid
	{
		cout << "Target acquired! Tracking " << target->get_name() << endl;
		_target = target;
	}
}

void Enemy::print_target_info()
{
	// if we have a valid target, print some info
	if (_target != nullptr)
		cout << "Target: " << _target->get_name() << " Hitpoints: " << _target->get_hitpoints() << endl;
	else
		cout << "No target, scanning for targets." << endl;

}

void Enemy::clear_target()
{
	cout << "Going to stand-by mode, no target assigned. " << endl;
	_target = nullptr;

}

int demo2()
{
	Hero wolverine("Wolverine", 50, 60);
	Hero cyclops("Cyclops", 30, 80);

	Enemy sentinel;
	sentinel.set_target(&wolverine); // the ampersand is passing in the memory address of wolverine not wolverine itself.

	sentinel.print_target_info();

	wolverine.take_damage(20);

	sentinel.print_target_info();

	sentinel.set_target(&cyclops);
	
	sentinel.print_target_info();

	// go to stand-by mode, dont track anyone
	sentinel.clear_target();


	return 0;
}