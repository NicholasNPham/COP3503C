#include <iostream>
#include <map>
#include <random>
#include <ctime>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

mt19937 random_mt;

// part 1
int Random(int min, int max)
{
	uniform_int_distribution<int> dist(min, max);
	return dist(random_mt);
}

void RollDice(int numberOfRolls, int numberOfSides)
{
	map<int, int> allRolls;

	for (int i = 1; i <= numberOfSides; i++)
	{
		allRolls.emplace(i, 0);
	}

	for (int i = 0; i < numberOfRolls; i++)
	{
		allRolls[Random(1, numberOfSides)]++;
	}

	cout << endl;
	for (const auto& pair : allRolls)
	{
		cout << pair.first << ": " << pair.second << endl;
	}


}

// part 2
// need a struct for the num data
struct StateData
{
	int perCapitaIncome;
	int population;
	int medianHouseholdIncome;
	int numOfHouseholds;
};

void openFile(string filename, map<string, StateData>& stateData)
{
	ifstream file(filename);
	if (!file.is_open())
	{
		cout << "Error: Could not open file." << endl;
	}

	// skip the header row
	string line;
	if (getline(file, line)) {}

	while (getline(file, line))
	{
		// extract rest of row data
		stringstream ss(line);
		string field;

		getline(ss, field, ',');
		string state = field;

		getline(ss, field, ',');
		int perCapIncome = stoi(field);

		getline(ss, field, ',');
		int population = stoi(field);

		getline(ss, field, ',');
		int medHouseIncome = stoi(field);

		getline(ss, field, ',');
		int numOfHouse = stoi(field);
		
		StateData data;
		data.perCapitaIncome = perCapIncome;
		data.population = population;
		data.medianHouseholdIncome = medHouseIncome;
		data.numOfHouseholds = numOfHouse;

		stateData[state] = data;

	}

}


int main()
{
	cout << "1. Random Numbers\n";
	cout << "2. State Info\n";

	int option;
	cin >> option;

	if (option == 1)
	{
		int randomSeed;
		cout << "Random seed value: ";
		cin >> randomSeed;
		random_mt.seed(randomSeed);

		int numberOfRolls;
		cout << "Number of times to roll the die: ";
		// user input
		cin >> numberOfRolls;

		int numberOfSides;
		cout << "Number of sides on this die: ";
		// user input
		cin >> numberOfSides;

		// Roll Dice
		RollDice(numberOfRolls, numberOfSides);

	}
	else if (option == 2)
	{

		map<string, StateData> stateDataMap;


		// Load the states
		openFile("states.csv", stateDataMap);

		// Get input for option 1 (show all states) or 2 (do a search for a particular state)
		cout << "1.Print all states" << endl;
		cout << "2.Search for a state" << endl;

		int stateOption;
		cin >> stateOption;

		if (stateOption == 1)
		{
			
			for (const auto& pair : stateDataMap)
			{
				cout << pair.first << endl;
				cout << "Population: " << pair.second.population << endl;
				cout << "Per Capita Income: " << pair.second.perCapitaIncome << endl;
				cout << "Median Household Income: " << pair.second.medianHouseholdIncome << endl;
				cout << "Number of Households: " << pair.second.numOfHouseholds << endl;
			
			}
		
		}
		else if (stateOption == 2)
		{

			string nameOfState;
			cin.ignore();
			getline(cin, nameOfState);

			
			map<string, StateData>::iterator iter = stateDataMap.find(nameOfState);
			
			if (iter != stateDataMap.end())
			{
				cout << iter->first << endl;
				cout << "Population: " << iter->second.population << endl;
				cout << "Per Capita Income: " << iter->second.perCapitaIncome << endl;
				cout << "Median Household Income: " << iter->second.medianHouseholdIncome << endl;
				cout << "Number of Households: " << iter->second.numOfHouseholds << endl;
			}
			else
			{
				cout << "No match found for " << nameOfState << endl;
			}


		}

	}

	return 0;
}
