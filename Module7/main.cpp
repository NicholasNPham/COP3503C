#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void writeNumbers(string filePath, vector<int>& numbers, char delimiter)
{
	ofstream file(filePath);
	// DID THE FILE ACTUALLY OPEN?
	if (file.is_open())
	{
		// WRITE DATA OUT
		for (unsigned int i = 0; i < numbers.size(); i++)
		{
			file << numbers[i];

			// IS THIS THE LAST ELEMENT IN THE CONTAINER
			// IF SO, DONT WRITE THE COMMA

			if (i < numbers.size() - 1)
				file << delimiter;
		}
	}
	else
	{
		cout << "Error File: " << filePath << " was not opened";
	}
}

int main()
{
	vector<int> numbers;
	for (int i = 0; i < 20; i++)
	{
		numbers.push_back(rand() % 50 + 1);
	}

	writeNumbers("data/file1.txt", numbers, ',');
	writeNumbers("data/file2.txt", numbers, '|');

	return 0;
}