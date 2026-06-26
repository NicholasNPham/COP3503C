#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// STRUCT =======================

struct Weapon
{
	string _weaponName;
	unsigned int _weaponPower;
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

void printShips(vector<Ship>& ShipList)
{
	for (unsigned int i = 0; i < ShipList.size(); i++)
	{
		cout << "Name: " << ShipList[i]._shipName << endl;
		cout << "Class: " << ShipList[i]._shipClass << endl;
		cout << "Length: " << ShipList[i]._shipLength << endl;
		cout << "Shield capacity: " << ShipList[i]._shipShield << endl;
		cout << "Maximum Warp: " << ShipList[i]._shipWarpSpeed << endl;
		cout << "Armaments:" << endl;
		unsigned int totalFirepower = 0;
		
		if (ShipList[i]._shipWeapons.size() > 0)
		{
			for (unsigned int j = 0; j < ShipList[i]._shipWeapons.size(); j++)
			{
				cout << ShipList[i]._shipWeapons[j]._weaponName << ", " << ShipList[i]._shipWeapons[j]._weaponPower << ", " << ShipList[i]._shipWeapons[j]._weaponPowerConsumption << endl;
				totalFirepower += ShipList[i]._shipWeapons[j]._weaponPower;
			}
			cout << "Total firepower: " << totalFirepower << endl << endl;

		}
		else
		{
			cout << "Unarmed" << endl << endl;
		}
	}
}

void printStrongestWeaponShip(vector<Ship>& ShipList)
{
	unsigned int maxPower = 0;
<<<<<<< HEAD
	unsigned int bestShipIndex = 0;
=======
	int bestShipIndex = 0;
>>>>>>> 154f6463e63f78815772e5808266ce959de1c7b2

	for (unsigned int i = 0; i < ShipList.size(); i++)
	{
		if (ShipList[i]._shipWeapons.size() > 0)
		{
			for (unsigned int j = 0; j < ShipList[i]._shipWeapons.size(); j++)
			{
				if (maxPower < ShipList[i]._shipWeapons[j]._weaponPower)
				{
					maxPower = ShipList[i]._shipWeapons[j]._weaponPower;
					bestShipIndex = i;
				}
			}
		}
	}

	cout << "Name: " << ShipList[bestShipIndex]._shipName << endl;
	cout << "Class: " << ShipList[bestShipIndex]._shipClass << endl;
	cout << "Length: " << ShipList[bestShipIndex]._shipLength << endl;
	cout << "Shield capacity: " << ShipList[bestShipIndex]._shipShield << endl;
	cout << "Maximum Warp: " << ShipList[bestShipIndex]._shipWarpSpeed << endl;
	cout << "Armaments:" << endl;
	unsigned int totalFirepower = 0;

	if (ShipList[bestShipIndex]._shipWeapons.size() > 0)
	{
		for (unsigned int j = 0; j < ShipList[bestShipIndex]._shipWeapons.size(); j++)
		{
			cout << ShipList[bestShipIndex]._shipWeapons[j]._weaponName << ", " << ShipList[bestShipIndex]._shipWeapons[j]._weaponPower << ", " << ShipList[bestShipIndex]._shipWeapons[j]._weaponPowerConsumption << endl;
			totalFirepower += ShipList[bestShipIndex]._shipWeapons[j]._weaponPower;
		}
		cout << "Total firepower: " << totalFirepower << endl << endl;

	}

}

void printStrongestShip(vector<Ship>& ShipList)
{

	unsigned int firePowerMax = 0;
<<<<<<< HEAD
	unsigned int bestShipIndex = 0;
=======
	int bestShipIndex = 0;
>>>>>>> 154f6463e63f78815772e5808266ce959de1c7b2

	for (unsigned int i = 0; i < ShipList.size(); i++)
	{
		unsigned int totalFirepower = 0;

		if (ShipList[i]._shipWeapons.size() > 0)
		{
			for (unsigned int j = 0; j < ShipList[i]._shipWeapons.size(); j++)
			{
				totalFirepower += ShipList[i]._shipWeapons[j]._weaponPower;
			}
			
			if (firePowerMax < totalFirepower)
			{
				firePowerMax = totalFirepower;
				bestShipIndex = i;
			}

		}
	}
	cout << "Name: " << ShipList[bestShipIndex]._shipName << endl;
	cout << "Class: " << ShipList[bestShipIndex]._shipClass << endl;
	cout << "Length: " << ShipList[bestShipIndex]._shipLength << endl;
	cout << "Shield capacity: " << ShipList[bestShipIndex]._shipShield << endl;
	cout << "Maximum Warp: " << ShipList[bestShipIndex]._shipWarpSpeed << endl;
	cout << "Armaments:" << endl;
	unsigned int totalFirepower = 0;

	if (ShipList[bestShipIndex]._shipWeapons.size() > 0)
	{
		for (unsigned int j = 0; j < ShipList[bestShipIndex]._shipWeapons.size(); j++)
		{
			cout << ShipList[bestShipIndex]._shipWeapons[j]._weaponName << ", " << ShipList[bestShipIndex]._shipWeapons[j]._weaponPower << ", " << ShipList[bestShipIndex]._shipWeapons[j]._weaponPowerConsumption << endl;
			totalFirepower += ShipList[bestShipIndex]._shipWeapons[j]._weaponPower;
		}
		cout << "Total firepower: " << totalFirepower << endl << endl;
	}
}

void printWeakestShip(vector<Ship>& ShipList)
{
	unsigned int firePowerMax = 999999;
<<<<<<< HEAD
	unsigned int worstShipIndex = 0;
=======
	int worstShipIndex = 0;
>>>>>>> 154f6463e63f78815772e5808266ce959de1c7b2

	for (unsigned int i = 0; i < ShipList.size(); i++)
	{
		unsigned int totalFirepower = 0;

		if (ShipList[i]._shipWeapons.size() > 0)
		{
			for (unsigned int j = 0; j < ShipList[i]._shipWeapons.size(); j++)
			{
				totalFirepower += ShipList[i]._shipWeapons[j]._weaponPower;
			}
			
			if (firePowerMax > totalFirepower)
			{
				firePowerMax = totalFirepower;
				worstShipIndex = i;
			}

		}
	}
	cout << "Name: " << ShipList[worstShipIndex]._shipName << endl;
	cout << "Class: " << ShipList[worstShipIndex]._shipClass << endl;
	cout << "Length: " << ShipList[worstShipIndex]._shipLength << endl;
	cout << "Shield capacity: " << ShipList[worstShipIndex]._shipShield << endl;
	cout << "Maximum Warp: " << ShipList[worstShipIndex]._shipWarpSpeed << endl;
	cout << "Armaments:" << endl;
	unsigned int totalFirepower = 0;

	if (ShipList[worstShipIndex]._shipWeapons.size() > 0)
	{
		for (unsigned int j = 0; j < ShipList[worstShipIndex]._shipWeapons.size(); j++)
		{
			cout << ShipList[worstShipIndex]._shipWeapons[j]._weaponName << ", " << ShipList[worstShipIndex]._shipWeapons[j]._weaponPower << ", " << ShipList[worstShipIndex]._shipWeapons[j]._weaponPowerConsumption << endl;
			totalFirepower += ShipList[worstShipIndex]._shipWeapons[j]._weaponPower;
		}
		cout << "Total firepower: " << totalFirepower << endl << endl;
	}
}


void printUnarmedShips(vector<Ship>& ShipList)
{
	for (unsigned int i = 0; i < ShipList.size(); i++)
	{
		if (ShipList[i]._shipWeapons.size() == 0)
		{
			cout << "Name: " << ShipList[i]._shipName << endl;
			cout << "Class: " << ShipList[i]._shipClass << endl;
			cout << "Length: " << ShipList[i]._shipLength << endl;
			cout << "Shield capacity: " << ShipList[i]._shipShield << endl;
			cout << "Maximum Warp: " << ShipList[i]._shipWarpSpeed << endl;
			cout << "Armaments:" << endl;
			cout << "Unarmed" << endl << endl;
		}
	}
}

int main()
{
	cout << "Which file(s) to open?\n";
	cout << "1. friendlyships.shp" << endl;
	cout << "2. enemyships.shp" << endl;
	cout << "3. Both files" << endl;
	int option;
	cin >> option;

	vector<Ship> Ships;
	if (option == 1)
	{
		loadShips(Ships, "friendlyships.shp");
	}
	else if (option == 2)
	{
		loadShips(Ships, "enemyships.shp");
	}
	else if (option == 3)
	{
		loadShips(Ships, "friendlyships.shp");
		loadShips(Ships, "enemyships.shp");
	}

	cout << "1. Print all ships" << endl;
	cout << "2. Starship with the strongest weapon" << endl;
	cout << "3. Strongest starship overall" << endl;
	cout << "4. Weakest ship (ignoring unarmed)" << endl;
	cout << "5. Unarmed ships" << endl;

	cin >> option;

	if (option == 1)
	{
		printShips(Ships);
	}
	else if (option == 2)
	{
		printStrongestWeaponShip(Ships);
	}
	else if (option == 3)
	{
		printStrongestShip(Ships);
	}
	else if (option == 4)
	{
		printWeakestShip(Ships);
	}
	else if (option == 5)
	{
		printUnarmedShips(Ships);
	}

	return 0;
}