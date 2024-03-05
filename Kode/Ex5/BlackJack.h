#pragma once
#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"

class BlackJack
{
private:
    CardDeck deck;
    vector<Card> playerHand;
    vector<Card> dealerHand;
    int playerHandSum;
    int dealerHandFirstCard;
    int dealerHandSum;
    int dealerStandThreshold = 17;

public:
    bool isAce(Card card);
    int getCardValue(Card card);
    int getHandScore(vector<Card> hand);
    bool askPlayerDrawCard();
    void drawPlayerCard();
    void drawDealerCard();
    void printCurrentStandings();
    void playGame();
};