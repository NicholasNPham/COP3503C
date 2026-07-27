#include <SFML/Graphics.hpp>
#include "Board.h"
#include "TextureManager.h"
#include "Game.h"
#include <iostream>
#include <string>
using namespace std;

int main() {


    //Board board;
    //board.loadConfigFile("boards/config.cfg");
    //board.setRandomMines();
    //board.calculateAdjacentMines();
    //board.printBoard();
    //board.printBoardDebug();
    //board.revealTile(5, 3);
    //board.printBoard();

    //Board board;
    //board.loadConfigFile("boards/config.cfg");
    //board.loadBoardFile("boards/lots_o_mines.brd");
    //board.printBoardDebug();

    //TextureManager tm;

    //if (tm.loadTexture("mine", "images/mine.png"))
    //    cout << "loaded mine\n";
    //else
    //    cout << "FAILED to load mine\n";

    //sf::RenderWindow window(sf::VideoMode(800, 600), "Test");
    //while (window.isOpen()) {
    //    sf::Event event;
    //    while (window.pollEvent(event)) {
    //        if (event.type == sf::Event::Closed)
    //            window.close();
    //    }
    //    window.clear();
    //    window.display();
    //}

    Game game;
    game.run();

    return 0;
}