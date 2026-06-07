#include <iostream>
#include <vector>
#include "Hero.h"
using namespace std;

int demo3()
{
	/*
	4 Kinds of debugging
	- Set breakpoints - stop here when debugging
	- Step Over - Execute the current line of code and move to the next
	- Step Into - Jump into a function for closer inspection
	- Stepout - jump out of a function, running any remaining code, and return to the line after the function call
	*/

	vector<Hero> heroes(5);
	Hero hero("Thor Odinson", 120, 300);
	hero.PrintInfo();
	hero.gain_experience(1000);
	hero.PrintInfo();

	return 0;
}