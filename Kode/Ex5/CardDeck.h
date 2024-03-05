#pragma once
#include "std_lib_facilities.h"
#include "Card.h"

class CardDeck
{
private:
    vector<Card> cards;

public:
    CardDeck();
    void swap(int cardA, int cardB);
    void print();
    void shuffle();
    Card drawCard();
};