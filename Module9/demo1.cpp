#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include "Hero.h"
using namespace std;

class Wizard : public Hero // Wizard IS-A Hero
{

};

int demo1()
{
	Wizard merlin;
	merlin.PrintInfo();
	return 0;
}