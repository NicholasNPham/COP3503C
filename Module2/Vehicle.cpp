#include "Vehicle.h"
#include <string>
using namespace std;

Vehicle::Vehicle()
{
	_make = "COP3503";
	_model = "Rust Bucket";
	_year = 1900;
	_price = 0;
	_mileage = 0;
}

Vehicle::Vehicle(string make, string model, unsigned int year, float price, unsigned int mileage)
{
	_make = make;
	_model = model;
	_year = year;
	_price = price;
	_mileage = mileage;

}

float Vehicle::GetPrice()
{
	return _price;
}