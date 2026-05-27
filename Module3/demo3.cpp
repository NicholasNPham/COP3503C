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

void pass_by_reference(big_object& ref)
{ }

void pass_by_pointer(big_object* ref)
{ }

int demo3()
{
	big_object the_object;
	int count = 30;
	{
		simple_timer t("passing by copy: ");
		for (int i = 0; i < count; i++)
			pass_by_copy(the_object);
	}
	{
		simple_timer t("passing by reference: ");
		for (int i = 0; i < count; i++)
			pass_by_reference(the_object);
	}
	{
		simple_timer t("passing by pointer: ");
		for (int i = 0; i < count; i++)
			pass_by_pointer(&the_object);
	}

	return 0;
}