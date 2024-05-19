#include "MinesweeperWindow.h"
#include <iostream>

MinesweeperWindow::MinesweeperWindow(int x, int y, int width, int height, int mines, const string &title)
	: AnimationWindow{x, y, width * cellSize, (height + 2) * cellSize, title},
	  width{width},
	  height{height},
	  mines{mines},
	  remainingTiles(width * height - mines),
	  remainingMines(mines),
	  fieldHeight(cellSize * 2),
	  statusMessage(Point{0, height * cellSize + 5}, Width() / 2, fieldHeight, to_string(remainingMines) + " mines remainding."),
	  restartBtn(Point{width * cellSize / 2, height * cellSize + 5}, Width() / 4, fieldHeight, "Restart"),
	  quitBtn(Point{width * cellSize * 3 / 4, height * cellSize + 5}, Width() / 4, fieldHeight, "Quit")
{
	// Add tiles
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			tiles.emplace_back(new Tile{Point{j * cellSize, i * cellSize}, cellSize});
			tiles.back()->setCallback(std::bind(&MinesweeperWindow::cb_click, this));
			auto temp = tiles.back().get();
			add(*temp);
		}
	}

	// Add GUI
	add(statusMessage);
	add(quitBtn);
	add(restartBtn);
	quitBtn.setVisible(false);
	restartBtn.setVisible(false);
	quitBtn.setCallback(std::bind(&MinesweeperWindow::cb_quit, this));
	restartBtn.setCallback(std::bind(&MinesweeperWindow::cb_restart, this));

	// Add tiles
	tileReset();
}

vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const
{
	vector<Point> points;
	for (int di = -1; di <= 1; ++di)
	{
		for (int dj = -1; dj <= 1; ++dj)
		{
			if (di == 0 && dj == 0)
			{
				continue;
			}

			Point neighbour{xy.x + di * cellSize, xy.y + dj * cellSize};
			if (inRange(neighbour))
			{
				points.push_back(neighbour);
			}
		}
	}
	return points;
}

void MinesweeperWindow::openTile(Point xy)
{
	shared_ptr<Tile> tileToOpen = at(xy);
	auto stateOfTile = tileToOpen->getState();
	if (tileToOpen && stateOfTile == Cell::closed)
	{ // Ruten eksisterer og er lukket.
		tileToOpen->open();

		if (!tileToOpen->checkIfMine())
		{ // Ruten er ikke en mine
			remainingTiles--;
			if (remainingTiles == 0)
			{ // All non-mine tiles has been opened -> win
				gameOver(true);
			}

			vector<Point> pointsAround = adjacentPoints(xy);
			int minesAround = countMines(pointsAround);
			if (minesAround > 0) // Det er miner rundt
			{
				tileToOpen->setLabel(std::to_string(minesAround));
				tileToOpen->setLabelColor(minesToColor.at(minesAround));
			}
			else // Det er ikke miner rundt
			{
				for (Point adjacentPoint : pointsAround) // Åpner alle ruter rundt
				{
					openTile(adjacentPoint);
				}
			}
		}
		else
		{
			gameOver(false); // Player clicked a mine, Lose
		}
	}
}

void MinesweeperWindow::flagTile(Point xy)
{
	shared_ptr<Tile> tileToFlag = at(xy);
	auto stateOfTile = tileToFlag->getState();
	if (tileToFlag && stateOfTile == Cell::closed)
	{
		// Cell exsists and is closed.
		tileToFlag->flag();
		remainingMines--;
	}
	else if (tileToFlag && stateOfTile == Cell::flagged)
	{
		// Cell exsists and is already flagged -> unflag.
		tileToFlag->flag();
		remainingMines++;
	}
	statusMessage.setText(to_string(remainingMines) + " mines remaining.");
}

// Kaller openTile ved venstreklikk og flagTile ved hoyreklikk
void MinesweeperWindow::cb_click()
{

	Point xy{this->get_mouse_coordinates()};

	if (!inRange(xy))
	{
		return;
	}
	if (this->is_left_mouse_button_down())
	{
		openTile(xy);
	}
	else if (this->is_right_mouse_button_down())
	{
		flagTile(xy);
	}
}

int MinesweeperWindow::countMines(vector<Point> coords) const
{
	int mineCount = 0;
	for (Point tilePoint : coords)
	{
		shared_ptr<Tile> currentTile = at(tilePoint);
		if (currentTile->checkIfMine())
		{
			mineCount++;
		}
	}
	return mineCount;
}

void MinesweeperWindow::gameOver(bool win)
{
	// add(statusMessage);
	statusMessage.setText(win ? " Congratulations! You win!" : " Game over.You lose.");
	quitBtn.setVisible(true);
	restartBtn.setVisible(true);

	// statusMessage.setVisible(true);
	for (shared_ptr<Tile> tile : tiles)
	{
		if (!win)
		{
			if (tile->getState() == Cell::flagged)
			{
				tile->flag(); // Unflag all mines.
			}
		}
		else if (win)
		{
			if ((tile->checkIfMine() && tile->getState() != Cell::flagged) || (!tile->checkIfMine() && tile->getState() == Cell::flagged))
			{
				tile->flag(); // Flag all mines, unflag rest
			}
		}
		tile->open();
	}
}

void MinesweeperWindow::tileReset()
{
	for (auto &tile : tiles)
	{
		tile->resetTile();
	}

	// Place random mines
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> randomMine(1, tiles.size());
	int toBePlaced = mines;

	while (toBePlaced)
	{
		shared_ptr<Tile> currentTile = tiles.at(randomMine(gen));
		if (!currentTile->checkIfMine())
		{ // Not already mine -> place mine
			currentTile->setMine();
			toBePlaced--;
		}
	}
	remainingMines = mines;
	remainingTiles = width * height - mines;
	statusMessage.setText(to_string(remainingMines) + " mines remainding.");
	restartBtn.setVisible(false);
	quitBtn.setVisible(false);
}

void MinesweeperWindow::cb_restart()
{
	tileReset();
}

void MinesweeperWindow::cb_quit()
{
	close();
}