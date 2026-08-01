#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintNumbers(vector<int>& numbers)
{
	for (unsigned int i = 0; i < numbers.size(); i++)
	{
		cout << numbers[i] << " ";
	}
}

void BubbleSort(vector<int>& numbers)
{
	bool swapWasMade = true;
	while (swapWasMade)
	{

		swapWasMade = false;
		// one pass
		for (unsigned int i = 0; i < numbers.size() - 1; i++)
		{

			// compare adjacent values, swap if necessary
			if (numbers[i] > numbers[i + 1])
			{
				int temp = numbers[i];
				numbers[i] = numbers[i + 1];
				numbers[i + 1] = temp;

				swapWasMade = true;
			}
		}
	}
}

void SelectionSort(vector<int>& numbers)
{
	int count = 0;


	// for each element in the array...
	// search each other element in the array to find the smallest number
	// then swap that smallest number (if necessary) into the original element
	for (unsigned int i = 0; i < numbers.size() - 1; i++)
	{
		int minIndex = i; // ---> assuming this is the smallest numbers location
		int sortedIndex = i;
		for (int j = i + 1; j < numbers.size(); j++)
		{
			if (numbers[j] < numbers[minIndex])
			{
				minIndex = j; // update location of the smallest number
			}
		}
		// any changes necessary;
		if (minIndex != sortedIndex)
		{
			int temp = numbers[minIndex];
			numbers[minIndex] = numbers[sortedIndex];
			numbers[sortedIndex] = temp;

			count += 1;
			cout << "Swapped: " << count << " times" << endl;
		}
	}
}

void InsertionSort(vector<int>& numbers)
{
	int count = 0;
	// for each element...
	// Bubble that element forward, until it can't swap anymore (or it's reached the front)

	for (unsigned int i = 1; i < numbers.size(); i++)
	{
		int currentIndex = i; // reduce this to 0... or until we can't swap anymore
		while (currentIndex > 0 && numbers[currentIndex] < numbers[currentIndex - 1])
		{
			// swap
			int temp = numbers[currentIndex];
			numbers[currentIndex] = numbers[currentIndex - 1];
			numbers[currentIndex - 1] = temp;

			currentIndex--;

		}
		count += 1;
		cout << "Swapped: " << count << " times" << endl;
	}
}

bool BinarySearch(vector<int>& numbers, int val)
{
	int numTries = 0;
	int lowIndex = 0, highIndex = numbers.size() - 1;

	while (lowIndex <= highIndex)
	{
		numTries++;
		int midPoint = lowIndex + (highIndex - lowIndex) / 2;
		if (numbers[midPoint] == val)
		{
			cout << "Found " << val << " in " << numTries << " searches!" << endl;
			return true;
		}
		else if (numbers[midPoint] > val)
		{
			highIndex = midPoint - 1;
		}
		else if (numbers[midPoint] < val)
		{
			lowIndex = midPoint + 1;
		}
	}

	cout << "After " << numTries << " searches, the value " << val << " was not found in the list" << endl;
	return false;
}

bool LinearSearch(vector<int>& numbers, int val)
{
	for (unsigned int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == val)
		{
			cout << "Found " << val << " in " << i + 1 << " searches!" << endl;
			return true;
		}
	}
	cout << "After " << numbers.size() << "  searches, the value " << val << " was not found in the list." << endl;
	return false;
}

int main()
{

	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	vector<int> numbers;

	for (int i = 0; i < 10; i++)
	{
		numbers.push_back(arr[i]);
	}

	cout << "Random Vector" << endl;
	PrintNumbers(numbers);
	cout << endl;

	//BubbleSort(numbers);
	//cout << "Bubble Sorted: " << endl;
	//PrintNumbers(numbers);
	//cout << endl;

	//SelectionSort(numbers);
	//cout << "Selection Sorted: " << endl;
	//PrintNumbers(numbers);
	//cout << endl;

	//InsertionSort(numbers);
	//cout << "Insertion Sorted: " << endl;
	//PrintNumbers(numbers);
	//cout << endl;

	//vector<int> sorted = numbers;      // copy, not sort's return value
	//sort(sorted.begin(), sorted.end()); // sorts the copy in place

	//cout << "Sorted: " << endl;
	//PrintNumbers(sorted);
	//cout << endl;

	while (true)
	{
		int input;
		cin >> input;
		if (input == -1)
		{
			break;
		}

		cout << "Binary Search: ";
		BinarySearch(numbers, input);
		cout << "Linear Search: ";
		LinearSearch(numbers, input);

	}



	return 0;

}