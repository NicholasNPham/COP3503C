#pragma once
#include <vector>
#include <string>
#include "Tile.h"
using std::vector;
using std::string;

class Board
{
	vector<vector<Tile>> _gridOfTiles;
	int _numOfRows;
	int _numOfCols;
	int _numOfMines;
	int _mineMinusFlagCount;
	bool _gameOver;
	bool _gameLost;
	bool _debugMode;
	void buildGrid();
public:
	Board();
	void loadConfigFile(string filename);
	void loadBoardFile(string filename);
	void resetGame();
	void setRandomMines();
	void calculateAdjacentMines();

	// Acessors ------------------------
	int getRowCount() const;
	int getColCount() const;
	bool getIfGameOver() const;
	bool getIfGameLost() const;
	bool getIfDebug() const;
	int getMineMinusFlagCount() const;
	const Tile& getTileState(int row, int col) const;
	void printBoard() const;
	void printBoardDebug() const;

	// Mutators ------------------------
	void revealTile(int row, int col);
	void toggleFlagPosition(int row, int col);
	bool checkAndSetWin();
	void toggleDebug();
};

