#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print_numbers(vector<int> numbers)
{
	cout << "Numbers of Elements: " << numbers.size() << endl;

	for (unsigned int i = 0; i < numbers.size(); i++)
	{
		cout << numbers[i] << " ";
	}
}


int demo5()
{

	// <>  template
	vector<int> numbers_vector;

	numbers_vector.push_back(2); // Adds a value to the end of the vector, increasing its size by 1
	numbers_vector.push_back(4);
	numbers_vector.push_back(6);
	numbers_vector.push_back(8);
	numbers_vector.push_back(10);

	vector<string> words;
	words.push_back("Batman");
	words.push_back(" and ");
	words.push_back("Robin");

	cout << "Words of Elements: " << words.size() << endl;
	for (unsigned int i = 0; i < words.size(); i++)
	{
		cout << words[i];
	}

	words.clear();
	cout << "\nWords of Elements: " << words.size() << endl;


	//print_numbers(numbers_vector);



	//vector<int> numbers_vector_2(5); // size == 0, now size == 5
	//numbers_vector_2[0] = 2;
	//numbers_vector_2[1] = 4;
	//numbers_vector_2[2] = 6;
	//numbers_vector_2[3] = 8;
	//numbers_vector_2[4] = 10;

    return 0;
}
