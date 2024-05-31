#pragma once
#include "Point.h"
#include <vector>
#include <iostream> //! Only for debugging!
#include "Color.h"
#include <map>

enum class TetrominoType
{
    J,
    L,
    T,
    S,
    Z,
    O,
    I,
    NONE
};

const std::map<TetrominoType, TDT4102::Color> tetrominoColorMap{
    {TetrominoType::J, TDT4102::Color::blue_violet},
    {TetrominoType::L, TDT4102::Color::orange},
    {TetrominoType::T, TDT4102::Color::purple},
    {TetrominoType::S, TDT4102::Color::green},
    {TetrominoType::Z, TDT4102::Color::red},
    {TetrominoType::O, TDT4102::Color::yellow},
    {TetrominoType::I, TDT4102::Color::coral},

};

class Tetromino
{
public:
    static constexpr int blockSize{30};

    Tetromino(TDT4102::Point tetrominoStartingPoint, TetrominoType tetType);
    Tetromino(); // Default constructor

    void rotateClockwise();
    void rotateCounterClockwise();
    void moveDown();
    void moveLeft();
    void moveRight();

    bool blockExists(int row, int column) const;
    TetrominoType getBlock(int row, int column) const;
    int getMatrixSize() const;
    TDT4102::Point getPosition() const;

    void printCurrentBlockMatrix(); //! For debug!

private:
    int matrixSize;
    TDT4102::Point topLeftCorner;
    std::vector<std::vector<TetrominoType>> blockMatrix;
};