#pragma once
class Tile
{
	bool mineFlag;
	bool flaggedFlag;
	bool revealFlag;
	int adjacentMines;
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
