#include "BlackJack.h"

bool BlackJack::isAce(Card card)
{
    if (static_cast<int>(card.getRank()) == 14)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int BlackJack::getCardValue(Card card)
{
    Rank cardRank = card.getRank();
    if (cardRank >= Rank::two && cardRank <= Rank::nine)
    { // Number card
        return static_cast<int>(cardRank);
    }
    else if (cardRank >= Rank::ten && cardRank <= Rank::king)
    { // Picture card
        return 10;
    }
    else
    { // Ace
        return 11;
    }
}

int BlackJack::getHandScore(vector<Card> hand)
{
    int score = 0;
    int aceCount = 0;

    for (Card card : hand)
    {
        int cardValue = getCardValue(card);
        if (cardValue == 11)
        {
            aceCount++;
        }
        else
        {
            score += cardValue;
        }
    }
    while (aceCount > 0)
    {
        if (score + 11 > 21)
        {
            score += 1; // Adds the ace as 1
        }
        else
        {
            score += 11;
        }
        aceCount--;
    }

    return score;
}

bool BlackJack::askPlayerDrawCard()
{
    cout << "Would you like to draw another card? (Y/N)" << endl;
    char answer;
    cin >> answer;
    if (answer == 'y')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void BlackJack::drawPlayerCard()
{
    playerHand.push_back(deck.drawCard());
}

void BlackJack::drawDealerCard()
{
    dealerHand.push_back(deck.drawCard());
}

void BlackJack::printCurrentStandings()
{
    cout << "The player has " << playerHandSum << ", with the hand of:" << endl;
    for (Card card : playerHand)
    {
        cout << card.toString() << endl;
    }
    cout << "The dealers first card is " << dealerHand.at(0).toString() << " giving a score of " << dealerHandFirstCard << "." << endl;
}

void BlackJack::playGame()
{
    deck.shuffle();

    // Dealing first cards:
    drawPlayerCard();
    drawDealerCard();
    dealerHandFirstCard = getHandScore(dealerHand);
    drawPlayerCard();
    drawDealerCard(); // Second dealer cards remains secret for player.
    playerHandSum = getHandScore(playerHand);
    dealerHandSum = getHandScore(dealerHand);

    printCurrentStandings();

    // Players turn:
    bool wantNewCard = askPlayerDrawCard();
    while (wantNewCard) // Player draws cards
    {
        drawPlayerCard();
        playerHandSum = getHandScore(playerHand);
        if (playerHandSum > 21)
        { // Player bust
            cout << "Unfortunately, your score of " << playerHandSum << " is too high. You busted!" << endl;
            return;
        }
        else
        {
            printCurrentStandings();
            wantNewCard = askPlayerDrawCard();
        }
    }
    cout << "You stand at " << playerHandSum << endl;
    cout << "The dealer has " << dealerHandSum << ", with the hand of:" << endl;
    for (Card card : dealerHand)
    {
        cout << card.toString() << endl;
    }

    // Dealers turn:
    while (dealerHandSum < dealerStandThreshold)
    {
        drawDealerCard();
        dealerHandSum = getHandScore(dealerHand);
        cout << "Dealer draws another card: " << dealerHand.back().toString() << ", and has a new score of " << dealerHandSum << endl;
        if (dealerHandSum > 21)
        { // Dealer bust
            cout << "Dealer busted, you win!" << endl;
            return;
        }
    }

    cout << "Dealer stands." << endl;

    // Finding the winner:
    if (playerHandSum == dealerHandSum)
    { // draw
        cout << "Its a draw, pushback" << endl;
    }
    else if (playerHandSum > dealerHandSum)
    {
        cout << "You Win! You have " << playerHandSum << " while the dealer only have " << dealerHandSum << "!" << endl;
    }
    else
    {
        cout << "You Lose! You have " << playerHandSum << " while the dealer has " << dealerHandSum << ", therefore beating you!" << endl;
    }
}