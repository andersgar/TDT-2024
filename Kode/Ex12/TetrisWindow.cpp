#include "TetrisWindow.h"
#include <iostream>

TetrisWindow::TetrisWindow(TDT4102::Point startingPoint, int width, int height, int blockNum)
    : AnimationWindow(startingPoint.x, startingPoint.y, width, height, "Tetris"),
      windowHeight{height}, windowWidth{width},
      blockSize{width / blockNum},
      tetrominoStartingPoint{(blockNum / 3) * blockSize, blockSize}
{
    currentTetrimino = generateRandomTetrimino();
    for (int r = 0; r < height; r += blockSize) // Filling the entire board with empty blocks.
    {
        std::vector<TetrominoType> gridMatrixRow;

        for (int c = 0; c < width; c += blockSize)
        {
            gridMatrixRow.push_back(TetrominoType::NONE);
        }
        gridMatrix.push_back(gridMatrixRow);
    }
};

void TetrisWindow::run()
{
    unsigned int framesSinceLastTetronimoMove = 0;
    const unsigned int framesPerTetronimoMove = 20;

    while (!should_close())
    {
        framesSinceLastTetronimoMove++;
        if (framesSinceLastTetronimoMove >= framesPerTetronimoMove)
        {
            framesSinceLastTetronimoMove = 0;
            /********************************************************/
            // Kall moveTetrominoDown() her
            /********************************************************/
            moveTetrominoDown();
        }
        handleInput();

        currentTetrominoPos = currentTetrimino.getPosition();
        currentTetrominoMatrixSize = currentTetrimino.getMatrixSize();

        /********************************************************/
        // Kall draw-funksjonene her
        /********************************************************/
        drawCurrentTetrimino();

        next_frame();
    }
}

void TetrisWindow::handleInput()
{

    static bool lastLeftKeyState = false;
    static bool lastRightKeyState = false;
    static bool lastDownKeyState = false;
    static bool lastZKeyState = false;
    static bool lastUpKeyState = false;

    bool currentLeftKeyState = is_key_down(KeyboardKey::LEFT);
    bool currentRightKeyState = is_key_down(KeyboardKey::RIGHT);
    bool currentDownKeyState = is_key_down(KeyboardKey::DOWN);
    bool currentZKeyState = is_key_down(KeyboardKey::Z);
    bool currentUpKeyState = is_key_down(KeyboardKey::UP);

    static bool lastTKeyState = false;
    bool currentTKeyState = is_key_down(KeyboardKey::T);
    if (currentTKeyState && !lastTKeyState)
    {
        fastenTetromino();
    }
    lastTKeyState = currentTKeyState;

    int currentSize = blockSize * currentTetrominoMatrixSize;

    if (currentLeftKeyState && !lastLeftKeyState && currentTetrominoPos.x > 0)
    {
        currentTetrimino.moveLeft();
    };

    if (currentRightKeyState && !lastRightKeyState && currentTetrominoPos.x < (windowWidth - currentSize))
    {
        currentTetrimino.moveRight();
    }

    if (currentDownKeyState && !lastDownKeyState && currentTetrominoPos.y < (windowHeight - currentSize)) //! Have to fix colliding with other blocks later....
    {
        currentTetrimino.moveDown();
        std::cout << "DOWN, ypos = " << currentTetrominoPos.y << std::endl;
    }

    if (currentZKeyState && !lastZKeyState)
    {
        currentTetrimino.rotateCounterClockwise();
    }

    if (currentUpKeyState && !lastUpKeyState)
    {
        currentTetrimino.rotateClockwise();
    }

    lastLeftKeyState = currentLeftKeyState;
    lastRightKeyState = currentRightKeyState;
    lastDownKeyState = currentDownKeyState;
    lastZKeyState = currentZKeyState;
    lastUpKeyState = currentUpKeyState;
}

Tetromino TetrisWindow::generateRandomTetrimino()
{
    std::random_device rg;
    std::mt19937 rng(rg());
    std::uniform_int_distribution<int> dist(0, 6);
    return Tetromino(tetrominoStartingPoint, TetrominoType::L); //! Removed randomness for debug.
    // return Tetromino{tetrominoStartingPoint, static_cast<TetrominoType>(dist(rng))};
}

void TetrisWindow::drawCurrentTetrimino()
{
    for (int r = 0; r < currentTetrominoMatrixSize; r++)
    {
        for (int c = 0; c < currentTetrominoMatrixSize; c++)
        {
            if (currentTetrimino.blockExists(r, c))
            {
                draw_rectangle({currentTetrominoPos.x + c * blockSize, currentTetrominoPos.y + r * blockSize},
                               blockSize, blockSize,
                               tetrominoColorMap.at(currentTetrimino.getBlock(r, c)));
            }
        }
    }
}

void TetrisWindow::moveTetrominoDown()
{
    if (currentTetrominoPos.y < (windowHeight - currentTetrominoMatrixSize * blockSize))
    {
        currentTetrimino.moveDown();
    }
}

void TetrisWindow::fastenTetromino()
{
    for (int r = currentTetrominoPos.y; r < (currentTetrominoPos.x + currentTetrominoMatrixSize * blockSize); r += blockSize)
    {
        for (int c = currentTetrominoPos.y; c < (currentTetrominoPos.y + currentTetrominoMatrixSize * blockSize); c += blockSize)
        {
            if (currentTetrimino.blockExists(r, c))
            {
                gridMatrix[r][c] = currentTetrimino.getBlock(r, c);
            }
        }
    }
}