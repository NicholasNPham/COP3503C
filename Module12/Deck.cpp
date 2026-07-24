#include <string>
#include "Deck.h"
using namespace std;

Deck::Deck()
{
    string cardNames[] = { "jack", "queen", "king", "ace" };
    string suitNames[] = { "hearts", "diamonds", "clubs", "spades" };

    for (int suit = 0; suit < 4; suit++)
    {
        for (int i = 2; i <= 10; i++)
        {
            string cardName = "cards/";
            cardName += to_string(i); // "2" "3"
            cardName += "_of_";
            cardName += suitNames[suit];

            _cards.push_back(Card(cardName.c_str()));
            _cards[_cards.size() - 1].SetPosition((_cards.size() - 1) * 30, (_cards.size() - 1) * 15);
        }

        for (int i = 0; i < 4; i++)
        {

            string cardName = "cards/" + cardNames[i] + "_of_" + suitNames[suit];
            _cards.push_back(Card(cardName.c_str()));
            _cards[_cards.size() - 1].SetPosition((_cards.size() - 1) * 30, (_cards.size() - 1) * 15);
        }
    }
}

vector<Card>& Deck::GetCards() 
{
    return _cards;
}

void Deck::MousePress(int x, int y)
{
    for (unsigned int i = _cards.size() - 1; i >= 0 && i < _cards.size(); i--)
    {
        if (_cards[i].Contains(x, y))
        {
            _cards[i].Flip();
            break; // only flip one of those cards
        }
    }
}

void Deck::DrawCards(sf::RenderWindow& window)
{
    for (unsigned int i = 0; i < _cards.size(); i++)
    {
        window.draw(_cards[i].GetSprite());
    }
}

void Deck::Shuffle() 
{
    for (int i = 0; i < 52; i++)
    {
        // 1. Get random value (for some index)
        int firstIndex = rand() % 52;

        // 2. Get another random value
        int secondIndex = rand() % 52;

        // 3. Swap those two values
        Card temp = _cards[firstIndex];
        _cards[firstIndex] = _cards[secondIndex];
        _cards[secondIndex] = temp;

    }
    for (int i = 0; i < 52; i++)
    {
        _cards[i].SetPosition(i * 30, i * 15);
    }

}