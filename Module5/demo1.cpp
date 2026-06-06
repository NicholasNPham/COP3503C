#include <iostream>
#include <string>
#include "DynamicArray.h"
#include "Hero.h"
using namespace std;

int demo1()
{

	DynamicArray<Hero> heroes;
	heroes.Add(Hero("Thor", 100, 250));
	heroes.Add(Hero());
	
	const Hero* heroData = heroes.getData();
	for (int i = 0; i < heroes.getSize(); i++)
		heroData[i].PrintInfo();

	DynamicArray<float> floats;
	floats.Add(3.14f);
	floats.Add(6.28f);

	DynamicArray<string> words;
	words.Add("Batman");
	words.Add("Robin");
	words.Add("Catwoman");

	DynamicArray<int> array;
	array.Add(500);
	array.Add(200);
	array.Add(199);
	array.Add(299);
	array.Add(399);

	array.Print();
	floats.Print();
	words.Print();





	return 0;

}

