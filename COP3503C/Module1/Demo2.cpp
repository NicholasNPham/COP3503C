#include <iostream>
using namespace std;

int get_numbers()
{ 

	int numbers[3];

	// Get input for all of the numbers in our array
	for (int i = 0; i < 3; i++)
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

	return sum;

}

void positive_or_negative(int sum)
{ 
	if (sum > 0)
		cout << "Sum is positive!" << endl;
	else if (sum < 0)
		cout << "Sum is negative!" << endl;
	else
		cout << "Sum is equal to zero!" << endl;

}

int demo2()
{

	// Task: Get user input for array of values
	int sum = get_numbers();
	// Check to see if the sum is positive or negative
	positive_or_negative(sum);

	// >> Extraction operator
	// << Insertion operator
	


	return 0;

}