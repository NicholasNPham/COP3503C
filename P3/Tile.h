#pragma once
class Tile
{
	bool _mine;
	bool _flagged;
	bool _revealed;
	int _adjacentMines;
public:
	Tile();

	// Accessors ---------------------
	int getAdjacentMines() const;
	bool isMine() const;
	bool isFlagged() const;
	bool isRevealed() const;

	// Mutators ----------------------
	void setMine(bool mine);
	void toggleFlag();
	void setAdjacentMines(int count);
	void reveal();

};
