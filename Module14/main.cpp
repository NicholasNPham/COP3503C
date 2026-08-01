#include <iostream>
#include <vector>
#include <algorithm>
#include "Hero.h"
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

	int arr[] = { 24, 35, 15, 49, 45, 36, 19, 43, 40, 28,
				  12, 16, 44, 18, 24, 26, 26, 35, 37, 30,
				  7, 17, 4, 45, 13, 7, 41, 29, 26, 19 };
	vector<int> numbers;
	for (int i = 0; i < 30; i++)
	{
		numbers.push_back(arr[i]);
	}

	std::sort(numbers.begin(), numbers.end(), [](int a, int b) 
		{
			return a > b;
		});
	cout << "Sorting in descending order..." << endl;
	PrintNumbers(numbers);
	cout << endl << endl;
	std::sort(numbers.begin(), numbers.end());
	cout << "Sorting in ascending order..." << endl;
	PrintNumbers(numbers);
	cout << endl;


	vector<Hero> heroes;
	heroes.push_back(Hero("Thor", 50, 125));
	heroes.push_back(Hero("Spider-Man", 35, 70));
	heroes.push_back(Hero("Batman", 20, 40));
	heroes.push_back(Hero("Wolverine", 30, 55));


	auto lambda = [](Hero& h1, Hero& h2) {return h1.get_hitpoints() < h2.get_hitpoints(); };
	std::sort(heroes.begin(), heroes.end(), lambda);
	for (unsigned i = 0; i < heroes.size(); i++)
	{
		heroes[i].PrintInfo();
	}
	cout << endl << endl;
	
	std::sort(heroes.begin(), heroes.end(), [](Hero& h1, Hero& h2) {return h1.get_name() < h2.get_name(); });
	for (unsigned i = 0; i < heroes.size(); i++)
	{
		heroes[i].PrintInfo();
	}

	string input;
	getline(cin, input);
	auto result = std::find_if(heroes.begin(), heroes.end(), [input](Hero& h) {return h.get_name() == input; });
	if (result != heroes.end())
	{
		cout << endl;
		cout << "Found " << input << "!" << endl;
		result->PrintInfo();
	}
	else
	{
		cout << "Search term not found" << endl;
	}

	bool found = false;
	for (unsigned int i = 0; i < heroes.size(); i++)
	{
		if (heroes[i].get_name() == "Wolverine")
		{
			cout << endl;
			heroes[i].PrintInfo();
			found = true;
			break;
		}
	}
	if (!found)
	{
		cout << "Search term not found" << endl;
	}


	return 0;

}