#include "Dealership.h"
#include <iostream>
using namespace std;

Dealership::Dealership(string name, unsigned int capacity)
{
	_name = name;
	_capacity = capacity;
}

void Dealership::AddShowroom(Showroom s)
{
	if (_showrooms.size() == _capacity)
	{
		cout << "Dealership is full, can't add another showroom!" << endl;
	}
	else
		_showrooms.push_back(s);
}

float Dealership::GetAveragePrice()
{
	// initialize total and count for average
	float total = 0;
	int count = 0;

	// total loop
	for (int i = 0; i < _showrooms.size(); i++)
		total += _showrooms[i].GetInventoryValue();

	// count loop
	for (int i = 0; i < _showrooms.size(); i++)
		count += _showrooms[i].GetVehicleList().size();

	return total / count;
}

void Dealership::ShowInventory()
{
	for (int i = 0; i < _showrooms.size(); i++)
	{
		_showrooms[i].ShowInventory();
	}
	cout << "Average car price: $" << GetAveragePrice() << endl;
}