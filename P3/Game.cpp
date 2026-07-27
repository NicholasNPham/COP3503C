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
			}
		}
		_window.clear(sf::Color::White);
		drawBoard();
		_window.display();
	}
}

