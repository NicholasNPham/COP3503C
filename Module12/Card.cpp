#include "Card.h"
#include "TextureManager.h"

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