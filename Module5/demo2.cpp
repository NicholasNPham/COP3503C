#include <iostream>
#include <string>
#include "DynamicArray.h"
#include "Hero.h"
using namespace std;

int demo2()
{
	DynamicArray<string> heroes;
	heroes.Add("Batman");
	heroes.Add("Robin");
	heroes.Add("Batgirl");
	heroes.Add("Alfred");

	DynamicArray<string> marvelHeroes;
	marvelHeroes.Add("Spider-Man");
	marvelHeroes.Add("Mrs. Marvel");
	marvelHeroes.Add("Thor");
	
	heroes.Print();
	
	heroes += marvelHeroes;
	cout << "Cobining two list of heroes..." << endl;
	heroes.Print();

	DynamicArray<string> villains;
	villains.Add("Joker");
	villains.Add("Killer Croc");
	villains.Add("Two-Face");
	villains.Add("Bane");

	return 0;

}
