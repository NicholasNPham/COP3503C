#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

struct LegoSet
{
	string _number;
	string _theme;
	string _name;
	int _minifigs;
	int _pieces;
	double _usprice;
};

void loadFile(vector<LegoSet>& legoSetList, string fileName)
{
	ifstream csv(fileName);
	if (csv.is_open())
	{
		// 1. READ THE HEADER FROM THE FILE AND IGNORE IT
		string lineFromFile;
		getline(csv, lineFromFile);

		getline(csv, lineFromFile);
		while (!csv.fail())
		{
			/*Number,Theme,Name,Minifigs,Pieces,USPrice
			  4653,4 Juniors,Dump Truck,1,27,10*/

			istringstream ss(lineFromFile);

			string number;
			getline(ss, number, ','); // NUMBER

			string theme;
			getline(ss, theme, ','); // THEME

			string name;
			getline(ss, name, ','); // NAME

			string minifigsString;
			getline(ss, minifigsString, ','); // MINIFIGS
			int minifigs = 0;
			try
			{
				minifigs = stoi(minifigsString);
			}
			catch (invalid_argument & e)
			{
				minifigs = 0;
			}

			string piecesString;
			getline(ss, piecesString, ','); // PIECES;
			int pieces = 0;
			try
			{
				pieces = stoi(piecesString);
			}
			catch (invalid_argument& e)
			{
				pieces = 0;
			}

			string uspriceString;
			getline(ss, uspriceString);
			double usprice = 0;
			try
			{
				usprice = stod(uspriceString);
			}
			catch (invalid_argument& e)
			{
				usprice = 0;
			}

			LegoSet legoSetObject;
			legoSetObject._number = number;
			legoSetObject._theme = theme;
			legoSetObject._name = name;
			legoSetObject._minifigs = minifigs;
			legoSetObject._pieces = pieces;
			legoSetObject._usprice = usprice;

			legoSetList.push_back(legoSetObject);

			getline(csv, lineFromFile);

		}
	}
}

void mostExpensive(vector<LegoSet>& legoSetList)
{
	LegoSet tempLegoObject = legoSetList[0];

	for (unsigned int i = 0; i < legoSetList.size(); i++)
	{
		if (legoSetList[i]._usprice > tempLegoObject._usprice)
		{
			tempLegoObject = legoSetList[i];
		}
	}

	cout << "The most expensive set is:" << endl;
	cout << "Name: " << tempLegoObject._name << endl;
	cout << "Number: " << tempLegoObject._number << endl;
	cout << "Theme: " << tempLegoObject._theme << endl;
	cout << "Price: $" << tempLegoObject._usprice << endl;
	cout << "Minifigures: " << tempLegoObject._minifigs << endl;
	cout << "Piece count: " << tempLegoObject._pieces << endl;

}

void largestPieceCount(vector<LegoSet>& legoSetList)
{
	LegoSet tempLegoObject = legoSetList[0];

	for (unsigned int i = 0; i < legoSetList.size(); i++)
	{
		if (legoSetList[i]._pieces > tempLegoObject._pieces)
		{
			tempLegoObject = legoSetList[i];
		}
	}

	cout << "The set with the highest parts count:" << endl;
	cout << "Name: " << tempLegoObject._name << endl;
	cout << "Number: " << tempLegoObject._number << endl;
	cout << "Theme: " << tempLegoObject._theme << endl;
	cout << "Price: $" << tempLegoObject._usprice << endl;
	cout << "Minifigures: " << tempLegoObject._minifigs << endl;
	cout << "Piece count: " << tempLegoObject._pieces << endl;

}

void searchByName(vector<LegoSet>& legoSetList)
{
	string userStrInput;
	getline(cin, userStrInput);

	bool foundMatch = false;

	for (unsigned int i = 0; i < legoSetList.size(); i++)
	{
		if (legoSetList[i]._name.find(userStrInput) != string::npos)
		{
			if (foundMatch == false)
			{
				cout << "Sets matching \"" << userStrInput << "\":" << endl;
			}
			foundMatch = true;
			cout << legoSetList[i]._number << " " << legoSetList[i]._name << " $" << legoSetList[i]._usprice << endl;
		}
	}
	if (foundMatch == false)
	{
		cout << "No sets found matching that search term";
	}
}

void searchByTheme(vector<LegoSet>& legoSetList)
{
	string userStrInput;
	getline(cin, userStrInput);

	bool foundMatch = false;

	for (unsigned int i = 0; i < legoSetList.size(); i++)
	{
		if (legoSetList[i]._theme.find(userStrInput) != string::npos)
		{
			if (foundMatch == false)
			{
				cout << "Sets matching \"" << userStrInput << "\":" << endl;
			}
			foundMatch = true;
			cout << legoSetList[i]._number << " " << legoSetList[i]._name << " $" << legoSetList[i]._usprice << endl;
		}
	}
	if (foundMatch == false)
	{
		cout << "No sets found matching that search term";
	}
}

void partCountInfo(vector<LegoSet>& legoSetList)
{
	int tempTotalCount = 0;

	for (unsigned int i = 0; i < legoSetList.size(); i++)
	{
		tempTotalCount += legoSetList[i]._pieces;
	}

	cout << "Average part count for " << legoSetList.size() << " sets: " << (int)(tempTotalCount / legoSetList.size()) << endl;
}

void priceInfo(vector<LegoSet>& legoSetList)
{
	double tempTotalCount = 0;
	LegoSet maxPriceLegoSet = legoSetList[0];
	LegoSet minPriceLegoSet = legoSetList[0];
	

	for (unsigned int i = 0; i < legoSetList.size(); i++)
	{
		tempTotalCount += legoSetList[i]._usprice;

		if (legoSetList[i]._usprice > maxPriceLegoSet._usprice)
		{
			maxPriceLegoSet = legoSetList[i];
		}

		if (legoSetList[i]._usprice < minPriceLegoSet._usprice)
		{
			minPriceLegoSet = legoSetList[i];
		}

	}

	cout << "Average price for " << legoSetList.size() << " sets: $" << (tempTotalCount / legoSetList.size()) << endl << endl;

	cout << "Least expensive set:" << endl;
	cout << "Name: " << minPriceLegoSet._name << endl;
	cout << "Number: " << minPriceLegoSet._number << endl;
	cout << "Theme: " << minPriceLegoSet._theme << endl;
	cout << "Price: $" << minPriceLegoSet._usprice << endl;
	cout << "Minifigures: " << minPriceLegoSet._minifigs << endl;
	cout << "Piece count: " << minPriceLegoSet._pieces << endl << endl;

	cout << "Most expensive set:" << endl;
	cout << "Name: " << maxPriceLegoSet._name << endl;
	cout << "Number: " << maxPriceLegoSet._number << endl;
	cout << "Theme: " << maxPriceLegoSet._theme << endl;
	cout << "Price: $" << maxPriceLegoSet._usprice << endl;
	cout << "Minifigures: " << maxPriceLegoSet._minifigs << endl;
	cout << "Piece count: " << maxPriceLegoSet._pieces << endl;
}

void minifigInfo(vector<LegoSet>& legoSetList)
{
	int tempMinifigCount = 0;
	LegoSet maxMinifigLegoSet = legoSetList[0];

	for (unsigned int i = 0; i < legoSetList.size(); i++)
	{
		tempMinifigCount += legoSetList[i]._minifigs;

		if (legoSetList[i]._minifigs > maxMinifigLegoSet._minifigs)
		{
			maxMinifigLegoSet = legoSetList[i];
		}

	}

	cout << "Average number of minifigures: " << (tempMinifigCount / legoSetList.size()) << endl;

	cout << "Set with the most minifigures:" << endl;
	cout << "Name: " << maxMinifigLegoSet._name << endl;
	cout << "Number: " << maxMinifigLegoSet._number << endl;
	cout << "Theme: " << maxMinifigLegoSet._theme << endl;
	cout << "Price: $" << maxMinifigLegoSet._usprice << endl;
	cout << "Minifigures: " << maxMinifigLegoSet._minifigs << endl;
	cout << "Piece count: " << maxMinifigLegoSet._pieces << endl;

}

int main()
{
	cout << std::fixed << setprecision(2);
	cout << "Which file(s) to open?\n";
	cout << "1. lego1.csv" << endl;
	cout << "2. lego2.csv" << endl;
	cout << "3. lego3.csv" << endl;
	cout << "4. All 3 files" << endl;
	int option;
	cin >> option;

	/*======= Load data from file(s) =======*/

	vector<LegoSet> legoList;

	if (option == 1)
	{
		loadFile(legoList, "lego1.csv");
	}
	else if (option == 2)
	{
		loadFile(legoList, "lego2.csv");
	}
	else if (option == 3)
	{
		loadFile(legoList, "lego3.csv");
	}
	else if (option == 4)
	{
		loadFile(legoList, "lego1.csv");
		loadFile(legoList, "lego2.csv");
		loadFile(legoList, "lego3.csv");
	}

	cout << "1. Most Expensive set" << endl;
	cout << "2. Largest piece count" << endl;
	cout << "3. Search for set name containing..." << endl;
	cout << "4. Search themes..." << endl;
	cout << "5. Part count information" << endl;
	cout << "6. Price information" << endl;
	cout << "7. Minifigure information" << endl;
	cout << "8. If you bought one of everything..." << endl;
	cout << "0. Exit" << endl;

	int choice;
	cin >> choice;
	cin.get();  // Clear newline character for any later input

	/*======= Print out how many sets were loaded =======*/
	cout << "Total number of sets: " << legoList.size() << endl << endl;

	/*======= Based on the choice, execute the appropriate task and show the results =======*/

	if (choice == 1)
	{
		mostExpensive(legoList);
	}
	if (choice == 2)
	{
		largestPieceCount(legoList);
	}
	if (choice == 3)
	{
		searchByName(legoList);
	}
	if (choice == 4)
	{
		searchByTheme(legoList);
	}
	if (choice == 5)
	{
		partCountInfo(legoList);
	}
	if (choice == 6)
	{
		priceInfo(legoList);
	}
	if (choice == 7)
	{
		minifigInfo(legoList);
	}


	return 0;
}

