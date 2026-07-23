#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

int main()
{

    sf::RenderWindow window(sf::VideoMode(1200, 800), "COP3503 is awesome!");

    sf::Texture cardTexture;
    cardTexture.loadFromFile("cards/2_of_clubs.png");
    sf::Texture cardTexture2;
    cardTexture2.loadFromFile("cards/4_of_hearts.png");


    sf::Sprite card(cardTexture);
    sf::Sprite card2(cardTexture2);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // 1. Clear anything that was previously rendered -- do this once
        window.clear();

        // 2. Draw anything that we want to appear on screen
        for (int i = 0; i < 10; i++)
        {
            if (i % 2 == 0)
            {
            card.setPosition(i * 50, i*25);
            window.draw(card);
            }
            else
            {
                card2.setPosition(i * 50, i * 25);
                window.draw(card2);
            }
        }

        // 3. Copy anything that was drawn to the display device (monitor) -- do this only once 
        window.display();

    }

    return 0;
}