#include <iostream>
#include <string>
#include "DynamicArray.h"
#include "Hero.h"
using namespace std;

int demo2()
{
	DynamicArray<string> heroes(100);
	heroes.Add("Batman");
	heroes.Add("Robin");
	heroes.Add("Batgirl");
	heroes.Add("Alfred");

	DynamicArray<string> marvelHeroes;
	marvelHeroes.Add("Spider-Man");
	marvelHeroes.Add("Mrs. Marvel");
	marvelHeroes.Add("Thor");
	
	//if (heroes == marvelHeroes)
	//	cout << "The two lists are the same!" << endl;
	//else
	//	cout << "the two lists are different!" << endl;

	heroes.Print();

	DynamicArray<string> villains;
	villains.Add("Joker");
	villains.Add("Killer Croc");
	villains.Add("Two-Face");
	villains.Add("Bane");

	cout << "Combining all list of heroes..." << endl;
	DynamicArray<string> all;

	all.Combine(heroes);
	all.Combine(marvelHeroes);
	all.Combine(villains);
	all = heroes + marvelHeroes + villains;

	all.Print();

	return 0;

}
