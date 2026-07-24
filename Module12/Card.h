#pragma once
#include <SFML/Graphics.hpp>
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