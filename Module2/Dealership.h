#pragma once
#include "Showroom.h"
#include <vector>
#include <string>
using namespace std;

class Dealership
{
private:
	string _name;
	vector<Showroom> _showrooms;
	unsigned int _capacity;

public:
	Dealership(
		string name = "Generic Dealership",
		unsigned int capacity = 0
	);

	// Behaviors
	void AddShowroom(Showroom s);
	float GetAveragePrice();
	void ShowInventory();

};