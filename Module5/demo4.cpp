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

void ExampleTwo()
{
	DynamicArray<int> dynArray;

	for (int i = 0; i < 10; i++)
		dynArray.Add(i);

	// Remove all elements from the array
	while (dynArray.getSize() > 0)
	{
		dynArray.Remove(); // Remove the last item from the list.
	}

	if (dynArray.getSize() == 0)
		cout << "Cleared succesfully!" << endl;
	else
		cout << "Still have itmes in the list!" << endl;
}

int demo4() {

	//ExampleOne();
	cout << "here" << endl;
	ExampleTwo();
	cout << "here" << endl;


	return 0;
}