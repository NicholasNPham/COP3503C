#include <SFML/Graphics.hpp>
#include "Board.h"

int main() {


    //Board board;
    //board.loadConfigFile("boards/config.cfg");
    //board.setRandomMines();
    //board.calculateAdjacentMines();
    //board.printBoard();
    //board.printBoardDebug();
    //board.revealTile(5, 3);
    //board.printBoard();

    Board board;
    board.loadConfigFile("boards/config.cfg");
    board.loadBoardFile("boards/lots_o_mines.brd");
    board.printBoardDebug();


    sf::RenderWindow window(sf::VideoMode(800, 600), "Test");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.display();
    }
    return 0;
}