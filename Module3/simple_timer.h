#pragma once
#include <string>
#include <chrono>
using namespace std;

using high_res_clock = chrono::high_resolution_clock; // alias
using time_point = high_res_clock::time_point;

class simple_timer
{
	string message;
	time_point start;
	time_point end;
	chrono::duration<double> elapsed;
public:
	simple_timer(const char *msg);
	~simple_timer();
};