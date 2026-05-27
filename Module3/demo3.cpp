#include "simple_timer.h"
using namespace std;

class big_object
{
	int lots_of_data[100000];
};

void pass_by_copy(big_object copy)
{
	// not doing anything, just passing a copy of a lot of data
	// our program has to "pay" to copy the parameter
}

int demo3()
{
	big_object the_object;
	int count = 300000;
	{
		simple_timer t("passing by copy: ");
		for (int i = 0; i < count; i++)
			pass_by_copy(the_object);
	}

	return 0;
}