#include "Showroom.h"
#include <iostream>
using namespace std;

Showroom::Showroom(string name, unsigned int capacity)
{
	_name = name;
	_capacity = capacity;

}

void Showroom::AddVehicle(Vehicle v)
{
	if (_vehicles.size() == _capacity)
		cout << "Showroom is full! Cannot add " << v.GetYearMakeModel() << endl;
	else
		_vehicles.push_back(v);
}

vector <Vehicle> Showroom::GetVehicleList()
{
	return _vehicles;
}

void Showroom::ShowInventory()
{
	if (_vehicles.size() == 0)
	{
		cout << _name << " is empty!" << endl;
	}
	else
	{
		cout << "Vehicles in " << _name << endl;
		for (unsigned int i = 0; i < _vehicles.size(); i++)
			_vehicles[i].Display();
	}
}

float Showroom::GetInventoryValue()
{
	float total_price_of_showroom = 0;

	for (unsigned int i = 0; i < _vehicles.size(); i++)
		total_price_of_showroom += _vehicles[i].GetPrice();

	return total_price_of_showroom;
}