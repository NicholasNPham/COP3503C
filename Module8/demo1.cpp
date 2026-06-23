#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int demo1()
{
	vector<int> numbers;
	// Generate some random numbers
	for (int i = 0; i < 20; i++)
	{
		numbers.push_back(rand() % 1000000 + 1);
	}
	// write values to a text file
	ofstream textFile("data/numbers.txt");
	textFile << numbers.size() << endl;
	for (unsigned int i = 0; i < numbers.size(); i++)
	{
		textFile << numbers[i] << endl;
	}
	// Write values to a binary file
	// "bin" is just an extension, and doesn't make it binary
	// ios_base::vinary flag == open the file in binary mode
	ofstream binaryFile("data/numbers.bin", ios_base::binary);

	int x = 0;

	//textFile << x;

	//float number = 2.2f;
	//int arrayOfNumbers[10];
	//arrayOfNumbers[(int)number] = 2;

	//binaryFile.write((char*) &x, sizeof(x));
	//binaryFile.write(reinterpret_cast<char*>(&x), sizeof(x));


	// write out the count
	unsigned int size = numbers.size();
	binaryFile.write(reinterpret_cast<char*>(&size), sizeof(size));
	// write out data
	for (unsigned int i = 0; i < numbers.size(); i++)
	{
		binaryFile.write(reinterpret_cast<char*>(&numbers[i]), sizeof(numbers[i]));
	}

	return 0;
}