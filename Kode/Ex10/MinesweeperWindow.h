#pragma once
#include "AnimationWindow.h"
#include "widgets/TextInput.h"
#include "Tile.h"
#include <random>

using namespace std;
using namespace TDT4102;

// Minesweeper GUI
class MinesweeperWindow : public AnimationWindow
{
public:
	// storrelsen til hver tile
	static constexpr int cellSize = 30;
	MinesweeperWindow(int x, int y, int width, int height, int mines, const string &title);

private:
	const int width;  // Bredde i antall tiles
	const int height; // Hoyde i antall tiles
	const int mines;  // Antall miner

	const int fieldHeight;

	int remainingTiles;
	int remainingMines;
	vector<shared_ptr<Tile>> tiles; // Vektor som inneholder alle tiles

	TextInput statusMessage;
	Button restartBtn;
	Button quitBtn;

	// hoyde og bredde i piksler
	int Height() const { return height * cellSize; }
	int Width() const { return width * cellSize; }

	// Returnerer en vektor med nabotilene rundt en tile, der hver tile representeres som et punkt
	vector<Point> adjacentPoints(Point xy) const;

	// tell miner basert paa en liste tiles
	int countMines(vector<Point> coords) const;

	// Sjekker at et punkt er paa brettet
	bool inRange(Point xy) const { return xy.x >= 0 && xy.x < Width() && xy.y >= 0 && xy.y < Height(); }

	// Returnerer en tile gitt et punkt
	shared_ptr<Tile> &at(Point xy) { return tiles[xy.x / cellSize + (xy.y / cellSize) * width]; }
	const shared_ptr<Tile> &at(Point xy) const { return tiles[xy.x / cellSize + (xy.y / cellSize) * width]; }

	// aapne og flagge rute
	void openTile(Point xy);
	void flagTile(Point xy);

	// callback funksjoner til Tile knappene
	void cb_click();

	void gameOver(bool win);
	void tileReset();
	void cb_restart();
	void cb_quit();
};
