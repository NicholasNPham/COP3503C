#include <iostream>
#include <string>
#include "Hero.h"
using namespace std;

int hero()
{
	Hero my_hero; // An Instance of the Hero Class
	my_hero.PrintInfo();

	Hero sidekick;
	sidekick.PrintInfo();

	return 0;

}