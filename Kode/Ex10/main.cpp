#include "MinesweeperWindow.h"

int main()
{
	constexpr int width = 25;
	constexpr int height = 25;
	constexpr int mines = 100;

	Point startPoint{200, 300};
	MinesweeperWindow mw{startPoint.x, startPoint.y, width, height, mines, "Minesweeper"};
	mw.wait_for_close();

	return 0;
}
