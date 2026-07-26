#include <iostream>
#include <fstream>
#include "Board.h"
using namespace std;

Board::Board()
{
	_numOfRows = 0;
	_numOfCols = 0;
	_numOfMines = 0;
	_mineMinusFlagCount = 0;
	_gameOver = false;
	_gameLost = false;
	_debugMode = false;
}

void Board::loadConfigFile(string filename)
{
	ifstream file(filename);

	if (!file.is_open())
	{
		cout << "Could not open File: " << filename << endl;
		return;
	}

	file >> _numOfCols;
	file >> _numOfRows;
	file >> _numOfMines;
}