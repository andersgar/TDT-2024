#include "CardDeck.h"

CardDeck::CardDeck()
{ // Double for loop: finds every possible combination of rank and suit.
    for (int currentSuit = static_cast<int>(Suit::clubs); currentSuit <= static_cast<int>(Suit::spades); currentSuit++)
    {
        for (int currentRank = static_cast<int>(Rank::two); currentRank <= static_cast<int>(Rank::ace); currentRank++)
        { // Adds every new element to the end of the cards vector
            cards.push_back(Card(static_cast<Suit>(currentSuit), static_cast<Rank>(currentRank)));
        }
    }
}

void CardDeck::swap(int cardA, int cardB)
{
    Card temp = cards[cardA];
    cards[cardA] = cards[cardB];
    cards[cardB] = temp;
}

void CardDeck::print()
{
    for (Card card : cards)
    {
        cout << card.toString() << endl;
    }
}

void CardDeck::shuffle()
{ // For every card in the deck, this function picks another card to swap with.
    random_device rd;
    default_random_engine gen(rd());

    for (int i = 0; i < cards.size(); i++)
    {
        uniform_int_distribution<int> dist(i, cards.size() - 1);
        int randomCardIndex = dist(gen);
        swap(i, randomCardIndex);
    }
}

Card CardDeck::drawCard()
{
    Card topCard = cards.back();
    cards.pop_back();
    return topCard;
}
