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
	void drawFace();
	void drawButtons();
	void drawCounter();
	bool isInside(int mouseX, int mouseY, int bx, int by, int width, int height);
public:
	Game();
	void run();
};
