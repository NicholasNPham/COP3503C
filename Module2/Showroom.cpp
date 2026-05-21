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