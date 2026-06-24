#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// STRUCT =======================

struct Weapon
{
	string _weaponName;
	int _weaponPower;
	float _weaponPowerConsumption;
};

struct Ship
{
	string _shipName;
	string _shipClass;
	short _shipLength;
	int _shipShield;
	float _shipWarpSpeed;
	vector<Weapon> _shipWeapons;
};

// FUNCTIONS =====================

void loadShips(vector<Ship>& ShipsList, string filename)
{
	ifstream inFile(filename, ios_base::binary);
	if (inFile.is_open())
	{
		unsigned int count;
		inFile.read(reinterpret_cast<char*>(&count), sizeof(count));

		for (unsigned int i = 0; i < count; i++)
		{
			Ship ship;

			unsigned int length; // DECLARE NO TYPE LENGTH
			char* buffer; // DECLARE POINTER CHAR NAMED BUFFER

			inFile.read(reinterpret_cast<char*>(&length), sizeof(length)); // ------------------------------------------------------------------------ // READ BYTES FROM THE FILE
			buffer = new char[length]; // ALLOCATE MEMORY OF LENGTH BYTES AND INIT AND STORE AS BUFFER                                                 // &length: take the address of the length var. 
			inFile.read(buffer, length); // READ "LENGTH" BYTES AND STORE IT IN BUFFER                                                                 // reinterpret_cast<char*>(&length) : treat the memory address as if it's a char pointer.
			                                                                                                                                           // sizeof(length) : How many bytes to read. 
			ship._shipName = buffer; // THE NEW OBJECT SHIPNAME IS NOW BUFF
			delete[] buffer; // DELETE BUFFER ALLOCATION

			inFile.read(reinterpret_cast<char*>(&length), sizeof(length)); // SAME AS ABOVE BUT READ THE NEXT LINE FOR SHIPCLASS

			buffer = new char[length]; // ALLOCATE MEMORY OF LENGTH BYTES AND INIT AND STORE AS BUFFER
			inFile.read(buffer, length); // READ "LENGTH" BYTES AND STORE IT IN BUFFER

			ship._shipClass = buffer; // THE NEW OBJECT SHIPCLASS IS NOW BUFFER
			delete[] buffer; // DELETE BUFFER ALLOCATION

			inFile.read(reinterpret_cast<char*>(&ship._shipLength), sizeof(ship._shipLength));
			inFile.read(reinterpret_cast<char*>(&ship._shipShield), sizeof(ship._shipShield));
			inFile.read(reinterpret_cast<char*>(&ship._shipWarpSpeed), sizeof(ship._shipWarpSpeed));

			ShipsList.push_back(ship);
		}
	}
	else
	{
		cout << "file failed to open" << endl;
	}
}

int main()
{

	vector<Ship> friendlyShips;
	loadShips(friendlyShips, "friendlyships.shp");
	cout << friendlyShips[0]._shipName;

}