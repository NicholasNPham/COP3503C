#include <iostream>
#include <string>
#include "Hero.h"
using namespace std;

int hero()
{
	Hero my_hero("Nick", 10, 25); // An Instance of the Hero Class
	my_hero.PrintInfo();

	Hero sidekick("Nick Jr.", 100, 300);
	sidekick.PrintInfo();

	return 0;

}