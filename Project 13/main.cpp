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

int main()
{

	int arr[] = { 24, 35, 15, 49, 45, 36, 19, 43, 40, 28,
				  12, 16, 44, 18, 24, 26, 26, 35, 37, 30,
				  7, 17, 4, 45, 13, 7, 41, 29, 26, 19 };

	vector<int> numbers;

	for (int i = 0; i < 30; i++)
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

	vector<int> sorted = numbers;      // copy, not sort's return value
	sort(sorted.begin(), sorted.end()); // sorts the copy in place

	cout << "Sorted: " << endl;
	PrintNumbers(sorted);
	cout << endl;
	
	return 0;

}