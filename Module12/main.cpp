#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "TextureManager.h"
#include "Deck.h"
using namespace std;


int main()
{

    sf::RenderWindow window(sf::VideoMode(1600, 1000), "COP3503 is awesome!");

    Deck deck;
    deck.Shuffle();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                auto mousePosition = sf::Mouse::getPosition(window);
                deck.MousePress(mousePosition.x, mousePosition.y);
            }
        }

        // 1. Clear anything that was previously rendered -- do this once
        window.clear();

        // 2. Draw anything that we want to appear on screen
        deck.DrawCards(window);

        // 3. Copy anything that was drawn to the display device (monitor) -- do this only once 
        window.display();
    }

    return 0;
}