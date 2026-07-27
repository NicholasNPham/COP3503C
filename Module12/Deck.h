#pragma once
#include <vector>
#include "Card.h"
using std::vector;

class Deck
{
	vector<Card> _cards;
public:
	Deck();
	vector<Card>& GetCards();
	void MousePress(int x, int y);
	void DrawCards(sf::RenderWindow& window);
	void Shuffle();
};

