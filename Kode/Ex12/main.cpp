#include "Tetromino.h"
#include "TetrisWindow.h"

int main()
{
	// TDT4102::Point wantedP{10, 10};
	// Tetromino test{wantedP, TetrominoType::I};
	// test.printCurrentBlockMatrix();

	// std::cout << test.blockExists(1, 1) << std::endl;

	TetrisWindow tw{{1800, 150}, 500, 1000, 15};
	// tw.wait_for_close();
	tw.run();

	/********************************************************/
	// Opprett vindu her
	/********************************************************/
	// kall run på det her
	return 0;
}
