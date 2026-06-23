#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void WriteNumbersToBinaryFile()
{
	vector<int> numbers;
	// Generate some random numbers
	for (int i = 0; i < 20; i++)
	{
		numbers.push_back(rand() % 50 + 1);
	}
	// Write values to a binary file
	// "bin" is just an extension, and doesn't make it binary
	// ios_base::binary flag == open the file in binary mode
	ofstream binaryFile("data/numbers.bin", ios_base::binary);

	// ================ file format ================
	// 4 bytes - Count of all the numbers in the file
	// Count * 4 bytes - the numbers themselves (each a 4-byte integer)

	// write out the count
	unsigned int size = numbers.size();
	binaryFile.write(reinterpret_cast<char*>(&size), sizeof(size));
	// Write out the data
	for (unsigned int i = 0; i < numbers.size(); i++)
	{
		binaryFile.write(reinterpret_cast<char*>(&numbers[i]), sizeof(numbers));
	}
}

int demo3()
{
	ifstream inFile("data/numbers.bin", ios_base::binary);

	// ================ file format ================
	// 4 bytes - Count of all the numbers in the file
	int count;
	inFile.read(reinterpret_cast<char*>(&count), sizeof(count));
	cout << "Count: " << count << endl;


	vector<int> numbers(count);

	for (int i = 0; i < count; i++)
	{
		int number;
		inFile.read(reinterpret_cast<char*>(&numbers[i]), sizeof(numbers[i]));
	}

	// Count * 4 bytes - the numbers themselves (each a 4-byte integer)

	return 0;
}