#include "Tile.h"

Tile::Tile() : _mine(false), _flagged(false), _revealed(false), _adjacentMines(0) {
}

// Accessors --------------------------------
int Tile::getAdjacentMines() const {
	return _adjacentMines;
}

bool Tile::isMine() const {
	return _mine;
}

bool Tile::isFlagged() const {
	return _flagged;
}

bool Tile::isRevealed() const {
	return _revealed;
}

// Mutators ----------------------------------
void Tile::setMine(bool mine)
{
	_mine = mine;
}

void Tile::toggleFlag()
{
	_flagged = !_flagged;
}

void Tile::setAdjacentMines(int count)
{
	_adjacentMines = count;
}

void Tile::reveal()
{
	_revealed = true;
}