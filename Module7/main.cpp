#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<int> numbers;
	ifstream inFile("demo3/file2.txt");

	int someValue;
	
	while (!inFile.eof())
	{
		inFile >> someValue;

		numbers.push_back(someValue);
	}
	

	cout << "numbers from file: " << numbers.size() << endl;
	for (unsigned int i = 0; i < numbers.size(); i++)
	{
		cout << numbers[i] << ' ';
	}
	return 0;
}