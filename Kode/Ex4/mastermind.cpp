#include "std_lib_facilities.h"
#include "utilities.h"
#include "mastermind.h"

void playMastermind()
{
    bool active = true;

    int lives = 10;
    constexpr int size = 4;
    constexpr int letters = 6;

    // TODO string code = randomizeString(size, 'A', 'A' + (letters - 1));
    string code = "AAEE";

    cout << code << " <- Secret code" << endl; // TODO REMOVE

    cout << "Welcome to Mastermind! \nYou will have " << lives << " to guess the " << size << "-letter word.\n Good luck!" << endl;

    while (active)
    {
        cout << "________\nROUND " << 11 - lives << " - Lives remainding: " << lives << endl;
        string guess = readInputToString(size, 'A', 'A' + (letters - 1));

        // TODO fiks
        int numCorrectPos = checkCharactersAndPosition(code, guess);
        int numCommon = 0;
        for (char ch : guess)
        {
            int commonPerChar = checkCharacters(code, ch);
            numCommon += commonPerChar;
        }
        numCommon -= numCorrectPos;

        if (numCorrectPos == size)
        { // Win
            active = false;
            cout << "Congratulations! You've won the game with " << lives << " lives left!" << endl;
            break;
        }
        else
        { // Wrong
            cout << "You have " << numCorrectPos << " letters in the correct place, and " << numCommon << " common letters in total." << endl;
            lives--;
        }

        if (lives == 0)
        {
            cout << "You have unfortunately run out of lives, better luck next time! The correct code was " << code << "." << endl;
            cout << "Would you like to try again? (Y/N)" << endl;
            char restartAnswer;
            cin >> restartAnswer;
            if (restartAnswer == 'Y')
            {
                code = randomizeString(size, 'A', 'A' + (letters - 1)); // Generate new code
                lives = 10;
            }
            else
            {
                active = false;
            }
        }
    };
}