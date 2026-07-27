#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "TextureManager.h"

class Game
{
	sf::RenderWindow _window;
	TextureManager _tm;
	Board _board;
	void loadTextures();
	void drawBoard();
	void drawTile();
public:
	Game();
	void run();
};
