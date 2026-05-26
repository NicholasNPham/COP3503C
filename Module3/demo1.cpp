#include <iostream>
#include <string>
#include <vector>
#include "Hero.h"
using namespace std;

void get_some_even_numbers(int count, vector<int>& copy)
{
	for (int i = 0, value = 2; i < count; i++, value += 2)
		copy.push_back(value);
}

void strongest_hero(Hero* one, Hero& two)
{
	
	cout << "Address of Wolverine (in func): " << one << endl;
	cout << "Address of Wolverine (in func): " << &two << endl;
	
	if (one->get_strength() > two.get_strength())
		cout << one->get_name() << " is stronger than " << two.get_name() << endl;
	else if (one->get_strength() < two.get_strength())
		cout << two.get_name() << " is stronger than " << one->get_name() << endl;
	else
		cout << one->get_name() << " is an even match for " << two.get_name() << endl;

}

int demo1()
{
	Hero wolverine("Wolverine", 50, 60);
	Hero cyclops("Cyclops", 30, 80);

	//cout << "Address of Wolverine (in main): " << &wolverine << endl;
	//cout << "Address of Wolverine (in main): " << &cyclops << endl;

	//strongest_hero(&wolverine, cyclops);
	
	vector<int> numbers;
	get_some_even_numbers(10, numbers);

	for (unsigned int i = 0; i < numbers.size(); i++)
		cout << numbers[i] << " ";


	return 0;
}