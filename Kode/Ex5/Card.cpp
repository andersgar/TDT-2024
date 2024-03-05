#include "Card.h"

string suitToString(Suit suit)
{
    static const map<Suit, string> suitNames = {
        {Suit::clubs, "Clubs"},
        {Suit::diamonds, "Diamonds"},
        {Suit::hearts, "Hearts"},
        {Suit::spades, "Spades"}

    };
    return suitNames.at(suit);
}

string rankToString(Rank rank)
{
    static const map<Rank, string> rankNames = {
        {Rank::two, "Two"},
        {Rank::three, "Three"},
        {Rank::four, "Four"},
        {Rank::five, "Five"},
        {Rank::six, "Six"},
        {Rank::seven, "Seven"},
        {Rank::eight, "Eight"},
        {Rank::nine, "Nine"},
        {Rank::ten, "Ten"},
        {Rank::jack, "Jack"},
        {Rank::queen, "Queen"},
        {Rank::king, "King"},
        {Rank::ace, "Ace"}

    };
    return rankNames.at(rank);
}

Card::Card(Suit suit, Rank rank) : s(suit), r(rank) {}

Suit Card::getSuit() { return s; }
Rank Card::getRank() { return r; }

string Card::toString()
{
    string suitName = suitToString(s);
    string rankName = rankToString(r);
    return rankName + " of " + suitName;
}