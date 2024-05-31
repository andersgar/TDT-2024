#pragma once
#include "AnimationWindow.h"
#include "Tetromino.h"
#include "widgets/TextInput.h"
#include "widgets/Button.h"
#include <random>

class TetrisWindow : public TDT4102::AnimationWindow
{

public:
    TetrisWindow(TDT4102::Point startingPoint, int width, int height, int blockNum);
    void run();

private:
    int windowWidth;
    int windowHeight;
    int blockSize;

    std::vector<std::vector<TetrominoType>> gridMatrix;
    TDT4102::Point tetrominoStartingPoint;

    Tetromino currentTetrimino;
    TDT4102::Point currentTetrominoPos;
    int currentTetrominoMatrixSize;

    Tetromino generateRandomTetrimino();
    void drawCurrentTetrimino();
    void moveTetrominoDown();
    void fastenTetromino();

    void handleInput();
};