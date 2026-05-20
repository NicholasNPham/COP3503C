#include <iostream>
#include <string>
#include <vector>
#include "Hero.h"
using namespace std;

int second_hero()
{

	vector<int> numbers;
	vector<string> words;

	// Vector of Hero Objects?
	vector <Hero> heroes;

	// Push some data back onto the vector
	heroes.push_back(Hero("Thor", 50, 200));
	heroes.push_back(Hero("Batman", 30, 100));
	heroes.push_back(Hero("Iron Man", 30, 150));

	// Array of hero objects?
	Hero array[3]{ Hero("Thor", 50, 200), 
				   Hero("Batman", 30, 100),
				   Hero("Iron Man", 30, 150) };

	for (int i = 0; i < 3; i++)
		array[i].PrintInfo();

	return 0;
}