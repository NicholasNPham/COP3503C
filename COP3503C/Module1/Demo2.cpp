#include <iostream>
using namespace std;

int demo2()
{

	// Task: Get user input for array of values
	// Check to see if the sum is positive or negative

	int numbers[3];

	// >> Extraction operator
	// << Insertion operator
	

	// Get input for all of the numbers in our array
	for (int i = 0; i < 3; i ++)
	{ 
		cin >> numbers[i];
	}

	for (int i = 0; i < 3; i++)
	{
		cout << "Value: " << numbers[i] << endl;
	}

	int sum = 0; // Initialize to "sensible" value
	for (int i = 0; i < 3; i++)
		sum += numbers[i];

	if (sum > 0)
		cout << "Sum is positive!" << endl;
	else if (sum < 0)
		cout << "Sum is negative!" << endl;
	else
		cout << "Sum is equal to zero!" << endl;


	return 0;

}