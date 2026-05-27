#include "simple_timer.h"
#include <iostream>
using namespace std;

simple_timer::simple_timer(const char *msg) // constructor
{
	message = msg;
	start = high_res_clock::now();
}

simple_timer::~simple_timer()
{
	end = high_res_clock::now();
	elapsed = end - start;
	cout << message << elapsed.count() << endl;
}