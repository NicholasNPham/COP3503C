#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<int> numbers;
	// Generate some random numbers
	for (int i = 0; i < 20; i++)
	{
		numbers.push_back(rand() % 50 + 1);
	}
	// write values to a text file
	ofstream textFile("data/numbers.txt");
	for (unsigned int i = 0; i < numbers.size(); i++)
	{
		textFile << numbers[i] << endl;
	}
	// Write values to a binary file
	// "bin" is just an extension, and doesn't make it binary
	// ios_base::vinary flag == open the file in binary mode
	ofstream binaryFile("data/numbers.bin", ios_base::binary);

	return 0;
}