#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"
#include "BlackJack.h"

int main()
{
    //* Test task 1
    /*
    Rank r = Rank::ace;
    Suit s = Suit::hearts;
    string rank = rankToString(r);
    string suit = suitToString(s);
    cout << "Rank: " << rank << " Suit: " << suit << endl;
    */
    //* Test task 2
    /*
    Card c{Suit::spades, Rank::ace};
    cout << c.toString() << endl;
    */

    //* Test task 3
    /*CardDeck deck{};
    cout << "d1" << endl;
    deck.print();
    cout << "pick" << deck.drawCard().toString() << endl;
    cout << "d2" << endl;
    deck.print();
    */

    //* Test blackjack loop
    bool active = true;
    while (active)
    {
        BlackJack b;
        b.playGame();
        cout << "Would you like to play again? (Y/N)" << endl;
        char playAgain;
        cin >> playAgain;
        if (playAgain != 'y')
        {
            active = false;
        }
    }

    return 0;
}
