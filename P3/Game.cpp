#include "Game.h"
using namespace std;

void Game::loadTextures()
{
	_tm.loadTexture("debug", "images/debug.png");
	_tm.loadTexture("digits", "images/digits.png");
	_tm.loadTexture("happyFace", "images/face_happy.png");
	_tm.loadTexture("sadFace", "images/face_lose.png");
	_tm.loadTexture("winFace", "images/face_win.png");
	_tm.loadTexture("flag", "images/flag.png");
	_tm.loadTexture("mine", "images/mine.png");
	_tm.loadTexture("number1", "images/number_1.png");
	_tm.loadTexture("number2", "images/number_2.png");
	_tm.loadTexture("number3", "images/number_3.png");
	_tm.loadTexture("number4", "images/number_4.png");
	_tm.loadTexture("number5", "images/number_5.png");
	_tm.loadTexture("number6", "images/number_6.png");
	_tm.loadTexture("number7", "images/number_7.png");
	_tm.loadTexture("number8", "images/number_8.png");
	_tm.loadTexture("test1", "images/test_1.png");
	_tm.loadTexture("test2", "images/test_2.png");
	_tm.loadTexture("test3", "images/test_3.png");
	_tm.loadTexture("tileHidden", "images/tile_hidden.png");
	_tm.loadTexture("tileRevealed", "images/tile_revealed.png");
}

void Game::drawBoard()
{
	sf::Sprite sprite;

	for (int row = 0; row < _board.getRowCount(); row++)
	{
		for (int col = 0; col < _board.getColCount(); col++)
		{
			if (_board.getTileState(row, col).isRevealed() == true)
			{
				sprite.setTexture(_tm.getTexture("tileRevealed"));
				sprite.setPosition(col * 32, row * 32);
				_window.draw(sprite);


				if (_board.getTileState(row, col).isMine() == true)
				{
					sprite.setTexture(_tm.getTexture("mine"));
					sprite.setPosition(col * 32, row * 32);
					_window.draw(sprite);
				}
				else if (_board.getTileState(row, col).getAdjacentMines() > 0)
				{
					int tileMineCount = _board.getTileState(row, col).getAdjacentMines();
					sprite.setTexture(_tm.getTexture("number" + to_string(tileMineCount)));
					sprite.setPosition(col * 32, row * 32);
					_window.draw(sprite);
				}
			}
			else
			{
				sprite.setTexture(_tm.getTexture("tileHidden"));
				sprite.setPosition(col * 32, row * 32);
				_window.draw(sprite);
			
				if (_board.getTileState(row, col).isFlagged() == true)
				{
					sprite.setTexture(_tm.getTexture("flag"));
					sprite.setPosition(col * 32, row * 32);
					_window.draw(sprite);
				}
			}
		}
	}
}

void Game::drawFace()
{

	sf::Sprite sprite;
	string faceKey;

	if (!_board.getIfGameOver())
	{
		faceKey = "happyFace";
	}
	else
	{
		// game is over: won or lost?
		if (_board.getIfGameLost())
		{
			faceKey = "sadFace";
		}
		else
		{
			faceKey = "winFace";
		}
	}


	int x = (_board.getColCount() / 2) * 32 - 32;
	int y = _board.getRowCount() * 32;

	sprite.setTexture(_tm.getTexture(faceKey));
	sprite.setPosition(x, y);
	_window.draw(sprite);

}

void Game::drawButtons()
{
	sf::Sprite sprite;

	int debugXPos = _board.getColCount() * 32 - 256;
	int debugYPos = _board.getRowCount() * 32;

	sprite.setTexture(_tm.getTexture("debug"));
	sprite.setPosition(debugXPos, debugYPos);
	_window.draw(sprite);

	int test1XPos = _board.getColCount() * 32 - 192;
	int test1YPos = _board.getRowCount() * 32;

	sprite.setTexture(_tm.getTexture("test1"));
	sprite.setPosition(test1XPos, test1YPos);
	_window.draw(sprite);

	int test2XPos = _board.getColCount() * 32 - 128;
	int test2YPos = _board.getRowCount() * 32;

	sprite.setTexture(_tm.getTexture("test2"));
	sprite.setPosition(test2XPos, test2YPos);
	_window.draw(sprite);

	int test3XPos = _board.getColCount() * 32 - 64;
	int test3YPos = _board.getRowCount() * 32;

	sprite.setTexture(_tm.getTexture("test3"));
	sprite.setPosition(test3XPos, test3YPos);
	_window.draw(sprite);
}

void Game::drawCounter()
{
	int count = _board.getMineMinusFlagCount();

	bool negCount = false;

	if (count < 0)
	{
		negCount = true;
		count *= -1;
	}

	int hundreds = (count / 100) % 10;
	int tens = (count / 10) % 10;
	int ones = count % 10;

	sf::Sprite sprite;
	sprite.setTexture(_tm.getTexture("digits"));

	if (!negCount)
	{
	// hundreds
		sprite.setTextureRect(sf::IntRect(hundreds * 21, 0, 21, 32));
		sprite.setPosition(33, _board.getRowCount() * 32);
		_window.draw(sprite);
	}
	else
	{
		sprite.setTextureRect(sf::IntRect(10 * 21, 0, 21, 32));
		sprite.setPosition(33, _board.getRowCount() * 32);
		_window.draw(sprite);
	}

	// tenths
	sprite.setTextureRect(sf::IntRect(tens * 21, 0, 21, 32));
	sprite.setPosition(54, _board.getRowCount() * 32);
	_window.draw(sprite);

	//ones
	sprite.setTextureRect(sf::IntRect(ones * 21, 0, 21, 32));
	sprite.setPosition(75, _board.getRowCount() * 32);
	_window.draw(sprite);


}

bool Game::isInside(int mouseX, int mouseY, int bx, int by, int width, int height)
{
	return mouseX >= bx &&
		mouseX < bx + width &&
		mouseY >= by &&
		mouseY < by + height;
}

// public ----------------------------------
Game::Game()
{
	_board.loadConfigFile("boards/config.cfg");

	int windowWidth = _board.getColCount() * 32;
	int windowHeight = _board.getRowCount() * 32 + 100;

	_window.create(sf::VideoMode(windowWidth, windowHeight), "Minesweeper", sf::Style::Close);

	loadTextures();

	_board.resetGame();

	//// TEMP: reveal all for drawBoard testing, delete later
	//for (int row = 0; row < _board.getRowCount(); row++)
	//{
	//	for (int col = 0; col < _board.getColCount(); col++)
	//	{
	//		_board.toggleFlagPosition(row, col);
	//	}
	//}

}

void Game::run()
{
	while (_window.isOpen())
	{

		sf::Event _event;
		while (_window.pollEvent(_event))
		{
			if (_event.type == sf::Event::Closed)
			{
				_window.close();
			}
			else if (_event.type == sf::Event::MouseButtonPressed)
			{
				// reversed but make sense we go down rows and right columns
				int row = _event.mouseButton.y / 32;
				int col = _event.mouseButton.x / 32;

				if (row >= 0 && row < _board.getRowCount() && col >= 0 && col < _board.getColCount())
				{

					if (!_board.getIfGameOver())
					{
						if (_event.mouseButton.button == sf::Mouse::Left)
						{
							_board.revealTile(row, col);
							_board.checkAndSetWin();

						}
						else if (_event.mouseButton.button == sf::Mouse::Right)
						{
							_board.toggleFlagPosition(row, col);
						}
					}
				}
				else
				{
					// face position
					int faceXPos = (_board.getColCount() / 2) * 32 - 32;
					int faceYPos = _board.getRowCount() * 32;

					if (isInside(_event.mouseButton.x, _event.mouseButton.y, faceXPos, faceYPos, 64, 64))
					{
						_board.resetGame();
					}
					
					// debug button
					int debugXPos = _board.getColCount() * 32 - 256;
					int debugYPos = _board.getRowCount() * 32;
					if (isInside(_event.mouseButton.x, _event.mouseButton.y, debugXPos, debugYPos, 64, 64) && !_board.getIfGameOver())
					{
						_board.toggleDebug();
					}




					//isInside(int mouseX, int mouseY, int bx, int by, int width, int height);
					//isInside(int mouseX, int mouseY, int bx, int by, int width, int height);
				}
			}
		}
		_window.clear(sf::Color::White);
		drawBoard();
		drawFace();
		drawCounter();
		drawButtons();
		_window.display();
	}
}

