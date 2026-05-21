#pragma once
#include "Vehicle.h"
#include <vector>
#include <string>
using namespace std;

class Showroom
{
private: // Explicit Private
	string _name;
	vector<Vehicle> _vehicles;
	unsigned int _capacity;

public:
	Showroom(
		string name = "Unnamed Showroom",
		unsigned int capacity = 0
	);

	// accessor
	vector<Vehicle > GetVehicleList();

	// behaviors
	void AddVehicle(Vehicle v);
	void ShowInventory();
	float GetInventoryValue();
};