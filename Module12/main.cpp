#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "TextureManager.h"
using namespace std;

// Card.h
class Card
{
    sf::Sprite _cardFront;
    sf::Sprite _cardBack;
    bool _isFaceup;
public:
    Card(const char* cardName);
    sf::Sprite& GetSprite();
    void SetPosition(float x, float y);
    void Flip();
    bool Contains(float x, float y);
};

// Card.cpp
Card::Card(const char* cardName)
{
    _cardFront.setTexture(TextureManager::GetTexture(cardName));
    _cardFront.setScale(0.5f, 0.5f);

    _cardBack.setTexture(TextureManager::GetTexture("cards/card_back"));
    _cardBack.setScale(0.5f, 0.5f);

    _isFaceup = true;
}

sf::Sprite& Card::GetSprite()
{
    if (_isFaceup)
    {
        return _cardFront;
    }
    else
    {
        return _cardBack;
    }
}

void Card::SetPosition(float x, float y)
{
    _cardFront.setPosition(x, y);
    _cardBack.setPosition(x, y);
}

void Card::Flip()
{
    _isFaceup = !_isFaceup;
}

bool Card::Contains(float x, float y)
{
    return _cardFront.getGlobalBounds().contains(x, y);
}

int main()
{

    sf::RenderWindow window(sf::VideoMode(1600, 1000), "COP3503 is awesome!");

    vector<Card> cards;
    for (int i = 2; i <= 10; i++)
    {
        string cardName = "cards/";
        cardName += to_string(i); // "2" "3"
        cardName += "_of_hearts";

        cards.push_back(Card(cardName.c_str()));
        cards[cards.size() - 1].SetPosition((cards.size() - 1) * 60, (cards.size() - 1) * 30);
    }

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

                for (unsigned int i = cards.size() - 1; i >= 0 && i < cards.size(); i--)
                {
                    if (cards[i].Contains(mousePosition.x, mousePosition.y))
                    {
                        cards[i].Flip();
                        break; // only flip one of those cards
                    }
                }

            }
        }

        // 1. Clear anything that was previously rendered -- do this once
        window.clear();

        // 2. Draw anything that we want to appear on screen
        for (unsigned int i = 0; i < cards.size(); i++)
        {
            window.draw(cards[i].GetSprite());
        }

        // 3. Copy anything that was drawn to the display device (monitor) -- do this only once 
        window.display();
    }

    return 0;
}