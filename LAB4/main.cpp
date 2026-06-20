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
			int minifigs = stoi(minifigsString);

			string piecesString;
			getline(ss, piecesString, ','); // PIECES;
			int pieces = stoi(piecesString);

			string uspriceString;
			getline(ss, uspriceString);
			double usprice = stod(uspriceString);

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
	/*======= Based on the choice, execute the appropriate task and show the results =======*/

	return 0;
}

