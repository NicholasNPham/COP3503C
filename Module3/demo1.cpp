#include <iostream>
#include <string>
#include <vector>
#include "Hero.h"
using namespace std;

void strongest_hero(Hero& one, Hero& two)
{
	
	cout << "Address of Wolverine (in func): " << &one << endl;
	cout << "Address of Wolverine (in func): " << &two << endl;
	
	if (one.get_strength() > two.get_strength())
		cout << one.get_name() << " is stronger than " << two.get_name() << endl;
	else if (one.get_strength() < two.get_strength())
		cout << two.get_name() << " is stronger than " << one.get_name() << endl;
	else
		cout << one.get_name() << " is an even match for " << two.get_name() << endl;

}

int demo1()
{
	Hero wolverine("Wolverine", 50, 60);
	Hero cyclops("Cyclops", 30, 80);

	cout << "Address of Wolverine (in main): " << &wolverine << endl;
	cout << "Address of Wolverine (in main): " << &cyclops << endl;

	strongest_hero(wolverine, cyclops);

	return 0;
}