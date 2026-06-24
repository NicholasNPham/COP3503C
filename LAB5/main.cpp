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
		unsigned int shipCount;
		inFile.read(reinterpret_cast<char*>(&shipCount), sizeof(shipCount));

		for (unsigned int i = 0; i < shipCount; i++)
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

			inFile.read(reinterpret_cast<char*>(&ship._shipLength), sizeof(ship._shipLength)); // SHIP LENGTH
			inFile.read(reinterpret_cast<char*>(&ship._shipShield), sizeof(ship._shipShield)); // SHIP SHIELD
			inFile.read(reinterpret_cast<char*>(&ship._shipWarpSpeed), sizeof(ship._shipWarpSpeed)); // SHIP WARP SPEED

			unsigned int weaponCount; // INIT WEAPON COUNT
			inFile.read(reinterpret_cast<char*>(&weaponCount), sizeof(weaponCount)); // STORE DATA INTO WEAPON COUNT

			for (unsigned int i = 0; i < weaponCount; i++)
			{
				Weapon weapon;

				unsigned int length; // DECLARE NO TYPE LENGTH
				char* buffer; // DECLARE POINTER CHAR NAMED BUFFER

				inFile.read(reinterpret_cast<char*>(&length), sizeof(length)); // ------------------------------------------------------------------------ // READ BYTES FROM THE FILE
				buffer = new char[length]; // ALLOCATE MEMORY OF LENGTH BYTES AND INIT AND STORE AS BUFFER                                                 // &length: take the address of the length var. 
				inFile.read(buffer, length); // READ "LENGTH" BYTES AND STORE IT IN BUFFER                                                                 // reinterpret_cast<char*>(&length) : treat the memory address as if it's a char pointer.
																																						   // sizeof(length) : How many bytes to read. 
				weapon._weaponName = buffer; // THE NEW OBJECT WEAPON NAME IS NOW BUFF
				delete[] buffer; // DELETE BUFFER ALLOCATION

				inFile.read(reinterpret_cast<char*>(&weapon._weaponPower), sizeof(weapon._weaponPower)); // WEAPON POWER
				inFile.read(reinterpret_cast<char*>(&weapon._weaponPowerConsumption), sizeof(weapon._weaponPowerConsumption)); // WEAPON POWER CONSUMPTION

				ship._shipWeapons.push_back(weapon);
			}

			ShipsList.push_back(ship);
		}
	}
	else
	{
		cout << "File failed to open" << endl;
	}
}

int main()
{

	vector<Ship> friendlyShips;
	loadShips(friendlyShips, "friendlyships.shp");
	
	for (unsigned int i = 0; i < friendlyShips.size(); i++)
	{
		cout << "Name: " << friendlyShips[i]._shipName << endl;
		cout << "Class: " << friendlyShips[i]._shipClass << endl;
		cout << "Length: " << friendlyShips[i]._shipLength << endl;
	}

}