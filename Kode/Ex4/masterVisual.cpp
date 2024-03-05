#include "masterVisual.h"

void addGuess(MastermindWindow &mwin, const string code, const char startLetter)
{
	Guess newGuess{code, startLetter};
	mwin.guesses.push_back(newGuess);
}

void addFeedback(MastermindWindow &mwin, const int correctPosition, const int correctCharacter)
{
	Feedback newFeedback{correctPosition, correctCharacter};
	mwin.feedbacks.push_back(newFeedback);
}

void MastermindWindow::drawCodeHider()
{
	if (code_hidden)
	{
		draw_rectangle(Point{padX, 3 * padY}, winW - size * padX, padY, Color::black);
	}
}

MastermindWindow::MastermindWindow(int x, int y, int w, int h, int size, const string &title)
	: AnimationWindow(x, y, w, h, title),
	  guessBtn{{upperLeftCornerBtn.x, upperLeftCornerBtn.y}, btnW, btnH, "Add"},
	  guess{{upperLeftCornerInBox.x, upperLeftCornerInBox.y}, inBoxW, inBoxH, ""},
	  size(size)
{
	add(guess);
	add(guessBtn);
	guessBtn.setCallback(std::bind(&MastermindWindow::cb_guess, this));
};

void MastermindWindow::drawGuessesAndFeedbacks()
{
	std::map<int, Color> colorConverter{
		{1, Color::red},
		{2, Color::green},
		{3, Color::yellow},
		{4, Color::blue},
		{5, Color::blue_violet},
		{6, Color::dark_cyan}};

	for (int guessIndex = 0; guessIndex < static_cast<int>(guesses.size()); guessIndex++)
	{
		// Implementer funksjonalitet slik at det vises fargede rektangler i grafikkvinduet
		// Tegn gjettet som ligger på plassen guessIndex i vektoren guesses.
		for (int i = 0; i < guesses.at(guessIndex).code.size(); i++)
		{
			int colorInt = static_cast<int>(guesses.at(guessIndex).code[i]) - static_cast<int>('A') + 1;
			// Tegn rektangler ved bruk av draw_rectangle(). Bruk: colorConverter.at() for å få riktig farge
			draw_rectangle({(1 + 2 * i) * padX, (3 + 2 * guessIndex) * padY}, padX, padY, colorConverter.at(colorInt));
		}
	}

	for (int feedbackIndex = 0; feedbackIndex < static_cast<int>(feedbacks.size()); feedbackIndex++)
	{
		Color currentColor;
		Color black = Color::black; // For circle border

		int currentCorrPos = feedbacks.at(feedbackIndex).correctPosition;
		int currentCorrChar = feedbacks.at(feedbackIndex).correctCharacter;

		for (int i = 1; i < guesses.at(feedbackIndex).code.size() + 1; i++)
		{
			if (i <= currentCorrPos)
			{
				currentColor = Color::green; // Corr pos
			}
			else if (i <= currentCorrChar)
			{
				currentColor = Color::yellow; // Corr char
			}
			else
			{
				currentColor = Color::grey; // Wrong
			}
			draw_circle({9 * padX + radCircle * i, ((11 / 2) + 2 * feedbackIndex) * padY}, radCircle, currentColor, black);
		}
	}
}

string MastermindWindow::wait_for_guess()
{
	while (!button_pressed && !should_close())
	{
		drawGuessesAndFeedbacks();
		// Burde tegnes sist siden den skal ligge på toppen
		drawCodeHider();

		next_frame();
	}
	button_pressed = false;

	string newGuess = guess.getText();
	guess.setText("");

	return newGuess;
}

string MastermindWindow::getInput(unsigned int n, char lower, char upper)
{
	bool validInput = false;
	string guess;
	while (!validInput && !should_close())
	{
		guess.clear();
		string input = wait_for_guess();
		if (input.size() == n)
		{
			for (unsigned int i = 0; i < n; i++)
			{
				char ch = input.at(i);
				if (isalpha(ch) && toupper(ch) <= upper && lower <= toupper(ch))
				{
					guess += toupper(ch);
				}
				else
					break;
			}
		}
		if (guess.size() == n)
		{
			validInput = true;
		}
		else
		{
			cout << "Invalid input guess again" << endl;
		}
	}
	return guess;
}

void MastermindWindow::setCodeHidden(bool hidden)
{
	code_hidden = hidden;
}

void playMastermindVisual()
{
	bool active = true;

	int lives = 10;
	constexpr int size = 4;
	constexpr int letters = 6;

	string code = randomizeString(size, 'A', 'A' + (letters - 1));

	MastermindWindow mwin{900, 20, winW, winH, size, "Mastermind"};

	addGuess(mwin, code, 'A');
	mwin.setCodeHidden(true);

	// cout << code << " <- Secret code" << endl; // TODO REMOVE

	cout << "Welcome to Mastermind! \nYou will have " << lives << " to guess the " << size << "-letter word.\n Good luck!" << endl;

	while (active)
	{
		cout << "________\nROUND " << 11 - lives << " - Lives remainding: " << lives << endl;
		string guess = mwin.getInput(size, 'A', 'A' + (letters - 1));

		addGuess(mwin, guess, 'A');

		int numCorrectPos = checkCharactersAndPosition(code, guess);
		// TODO fjern comm int numCommon = checkCharacters(code, guess);
		int numCommon = 0;

		if (numCorrectPos == size)
		{ // Win
			cout << "Congratulations! You've won the game with " << lives << " lives left!" << endl;
			mwin.drawGuessesAndFeedbacks();
			mwin.setCodeHidden(false);
			mwin.wait_for_close();

			cout << "Would you like to play again? (Y/N)" << endl;
			char restartAnswer;
			cin >> restartAnswer;
			if (restartAnswer == 'Y')
			{
				playMastermindVisual();
			}
			else
			{
				active = false;
			}
		}
		else
		{ // Wrong
			cout << "You have " << numCorrectPos << " letters in the correct place, and " << numCommon << " common letters in total." << endl;
			lives--;
			addFeedback(mwin, numCorrectPos, numCommon);
		}

		if (lives == 0) // Lose
		{
			mwin.drawGuessesAndFeedbacks();
			mwin.setCodeHidden(false);
			mwin.wait_for_close();

			cout << "You have unfortunately run out of lives, better luck next time! The correct code was " << code << "." << endl;

			cout << "Would you like to try again? (Y/N)" << endl;
			char restartAnswer;
			cin >> restartAnswer;
			if (restartAnswer == 'Y')
			{
				playMastermindVisual();
			}
			else
			{
				active = false;
			}
		}
	}
}