#include <iostream>
#include <fstream>
#include <random>
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

void Board::buildGrid()
{
	_gridOfTiles.clear();

	_gridOfTiles.resize(_numOfRows);
	for (int i = 0; i < _numOfRows; i++)
	{
		_gridOfTiles[i].resize(_numOfCols);
	}
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

	buildGrid();

}

void Board::loadBoardFile(string filename)
{
	ifstream file(filename);

	if (!file.is_open())
	{
		cout << "Could not open File: " << filename << endl;
		return;
	}
	for (int row = 0; row < _numOfRows; row++)
	{
		for (int col = 0; col < _numOfCols; col++)
		{
			char characterNum;
			file >> characterNum;

			if (characterNum == '1')
			{
				_gridOfTiles[row][col].setMine(true);
			}
			else
			{
				_gridOfTiles[row][col].setMine(false);
			}
		}
	}
	calculateAdjacentMines();
}

void Board::resetGame()
{
	buildGrid();
	_gameOver = false;
	_gameLost = false;
	_mineMinusFlagCount = _numOfMines;
	setRandomMines();
	calculateAdjacentMines();
}

void Board::setRandomMines()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> rowDist(0, _numOfRows - 1);
	uniform_int_distribution<int> colDist(0, _numOfCols - 1);

	int successMinePlaced = 0;

	while (successMinePlaced != _numOfMines)
	{
		int tempRowDistNum = rowDist(gen);
		int tempColDistNum = colDist(gen);

		if (!_gridOfTiles[tempRowDistNum][tempColDistNum].isMine())
		{
			_gridOfTiles[tempRowDistNum][tempColDistNum].setMine(true);
			successMinePlaced += 1;
		}
	}
}

void Board::calculateAdjacentMines()
{
	for (int row = 0; row < _numOfRows; row++)
	{
		for (int col = 0; col < _numOfCols; col++)
		{
			int adjacentTileMinesCount = 0;
			
			for (int rowOffset = -1; rowOffset <= 1; rowOffset++)
			{
				for (int colOffset = -1; colOffset <= 1; colOffset++)
				{
					if (rowOffset == 0 && colOffset == 0)
					{
						continue;
					}
					int newRow = row + rowOffset;
					int newCol = col + colOffset;

					// check if they are in bounds 
					if (
						newRow < 0 ||
						newRow >= _numOfRows ||
						newCol < 0 ||
						newCol >= _numOfCols)
					{
						continue;
					}
					if (_gridOfTiles[newRow][newCol].isMine())
					{
						adjacentTileMinesCount += 1;
					}

				}
			}
			_gridOfTiles[row][col].setAdjacentMines(adjacentTileMinesCount);
		}
	}
}

// Accessors ------------------------------------------------------
int Board::getRowCount() const {
	return _numOfRows;
}

int Board::getColCount() const {
	return _numOfCols;
}

bool Board::getIfGameOver() const {
	return _gameOver;
}

bool Board::getIfGameLost() const {
	return _gameLost;
}

int Board::getMineMinusFlagCount() const {
	return _mineMinusFlagCount;
}

const Tile& Board::getTileState(int row, int col) const {
	return _gridOfTiles[row][col];
}

void Board::printBoard() const {

	int totalMinesFound = 0;

	for (int row = 0; row < _numOfRows; row++)
	{
		for (int col = 0; col < _numOfCols; col++)
		{

			if (_gridOfTiles[row][col].isRevealed() == false)
			{
				cout << "[H]";
			}
			else if (_gridOfTiles[row][col].isMine())
			{
				cout << "[*]";
				totalMinesFound += 1;
			}
			else
			{

				if (_gridOfTiles[row][col].getAdjacentMines() == 0)
				{
				cout << "[ ]";
				}
				else
				{
					cout << "[" << _gridOfTiles[row][col].getAdjacentMines() << "]";
				}
			}
		}
		cout << endl;
	}
}

void Board::printBoardDebug() const
{

	cout << endl;

	int totalMinesFound = 0;

	for (int row = 0; row < _numOfRows; row++)
	{
		for (int col = 0; col < _numOfCols; col++)
		{
			if (_gridOfTiles[row][col].isMine())
			{
				cout << "[*]";
				totalMinesFound += 1;
			}
			else
			{

				if (_gridOfTiles[row][col].getAdjacentMines() == 0)
				{
					cout << "[ ]";
				}
				else
				{
					cout << "[" << _gridOfTiles[row][col].getAdjacentMines() << "]";
				}
			}
		}
		cout << endl;
	}

	cout << "numOfMines: " << _numOfMines << endl;
	cout << "Mines Found: " << totalMinesFound << endl;
	cout << endl;
}

// Mutators -------------------------------------------------------
void Board::revealTile(int row, int col)
{
	// guard against out of bounds grid tiles
	if (
		row < 0 ||
		row >= _numOfRows ||
		col < 0 ||
		col >= _numOfCols)
	{
		return;
	}
	// guard against revealed tiles, if connecting tiles reach a already revealed tile return
	if (_gridOfTiles[row][col].isRevealed())
	{
		return;
	}
	// if the tile is flag return and dont reveal
	if (_gridOfTiles[row][col].isFlagged())
	{
		return;
	}
	// reveal selected tile after guard check
	_gridOfTiles[row][col].reveal();

	if (_gridOfTiles[row][col].isMine())
	{
		_gameOver = true;
		_gameLost = true;
	}

	// check if tile adj mines are 0 means its safe
	if (_gridOfTiles[row][col].getAdjacentMines() == 0)
	{
		// loops through the 8 surrounding tiles
		for (int rowOffset = -1; rowOffset <= 1; rowOffset++)
		{
			for (int colOffset = -1; colOffset <= 1; colOffset++)
			{
				// this skips the check the center 3x3
				if (rowOffset == 0 && colOffset == 0)
				{
					continue;
				}
				int newRow = row + rowOffset;
				int newCol = col + colOffset;

				// check if they are in bounds 
				if (
					newRow < 0 ||
					newRow >= _numOfRows ||
					newCol < 0 ||
					newCol >= _numOfCols)
				{
					continue;
				}
				// calls the recursion
				revealTile(newRow, newCol);
			}
		}
	}
}

void Board::toggleFlagPosition(int row, int col)
{
	if (
		row < 0 ||
		row >= _numOfRows ||
		col < 0 ||
		col >= _numOfCols)
	{
		return;
	}

	if (_gridOfTiles[row][col].isRevealed() == false)
	{
		_gridOfTiles[row][col].toggleFlag();
		if (_gridOfTiles[row][col].isFlagged() == true)
		{
			_mineMinusFlagCount -= 1;
		}
		else
		{
			_mineMinusFlagCount += 1;
		}
	}
}

bool Board::checkAndSetWin()
{
	for (int row = 0; row < _numOfRows; row++)
	{
		for (int col = 0; col < _numOfCols; col++)
		{
			if (_gridOfTiles[row][col].isMine() == false && _gridOfTiles[row][col].isRevealed() == false)
			{
				return false;
			}
		}
	}
	_gameOver = true;
	return true;
}

void Board::toggleDebug()
{
	_debugMode = !_debugMode;
}