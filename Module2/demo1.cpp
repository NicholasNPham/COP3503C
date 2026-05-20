#include <iostream>
#include <string>
#include "Hero.h"
using namespace std;

int hero()
{
	Hero my_hero("Nick", 10, 25); // An Instance of the Hero Class
	
	my_hero.set_name("Nick the Cyborg");
	my_hero.PrintInfo();

	Hero sidekick("Nick Jr.", 100, 300);
	sidekick.PrintInfo();

	// How many hitpoint does Nick Jr. Have?
	cout << "Nick Jr. Hitpoints: " << sidekick.get_hitpoints() << endl;

	// Nick Jr. Takes Damage
	sidekick.take_damage(10);

	return 0;

}