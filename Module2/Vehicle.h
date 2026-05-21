#pragma once
#include <string>
using std::string;

class Vehicle
{
	// data to represent our hero explicit private
private:
	string _make;
	string _model;
	unsigned int _year;
	float _price;
	unsigned int _mileage;

public:
	// prototype
	Vehicle();
	Vehicle(
		string make,
		string model,
		unsigned int year,
		float price,
		unsigned int mileage);

	void Display();

	string GetYearMakeModel();

	float GetPrice();

};
