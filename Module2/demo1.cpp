#include <iostream>
#include <string>
#include "Hero.h"
using namespace std;

int hero()
{
	Hero sidekick("Nick Jr.", 100, 300);
	sidekick.PrintInfo();

	sidekick.gain_experience(110);

	sidekick.PrintInfo();

	return 0;

}