#include <iostream>
#include <vector>
#include "DynamicArray.h"
using namespace std;

void ExampleOne()
{
	vector<int> numbers;
	// Initialize to 1-10
	for (int i = 1; i <= 10; i++)
		numbers.push_back(i);

	// Print the list backward
	for (unsigned int i = numbers.size(); i-- > 0; )
		cout << numbers[i] << endl;
}

//void ExampleTwo()
//{
//
//}

int demo4() {

	ExampleOne();
	//ExampleTwo();

	return 0;
}