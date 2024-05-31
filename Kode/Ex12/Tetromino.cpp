#include "Tetromino.h"
#include <map>

const std::map<TetrominoType, std::vector<std::vector<int>>> initialMatrixMap{

    {TetrominoType::J,
     {{0, 0, 0},
      {1, 1, 1},
      {0, 0, 1}}},
    {TetrominoType::L,
     {{0, 0, 0},
      {1, 1, 1},
      {1, 0, 0}}},
    {TetrominoType::T,
     {{0, 0, 0},
      {1, 1, 1},
      {0, 1, 0}}},
    {TetrominoType::S,
     {{0, 0, 0},
      {0, 1, 1},
      {1, 1, 0}}},
    {TetrominoType::Z,
     {{0, 0, 0},
      {1, 1, 0},
      {0, 1, 1}}},
    {TetrominoType::O,
     {{1, 1},
      {1, 1}}},
    {TetrominoType::I,
     {{0, 0, 1, 0},
      {0, 0, 1, 0},
      {0, 0, 1, 0},
      {0, 0, 1, 0}}},

};

Tetromino::Tetromino(TDT4102::Point tetrominoStartingPoint, TetrominoType tetType)
    : topLeftCorner{tetrominoStartingPoint},
      matrixSize{static_cast<int>(initialMatrixMap.at(tetType).size())}
{
    for (int r = 0; r < matrixSize; r++)
    {
        std::vector<TetrominoType> blockMatrixRow;
        for (int c = 0; c < matrixSize; c++)
        {
            if (initialMatrixMap.at(tetType)[r][c] != 0) // If the given block in the mapped matrix is one, push back the type.
            {
                blockMatrixRow.push_back(tetType);
            }
            else // If not, push back NONE-object.
            {
                blockMatrixRow.push_back(TetrominoType::NONE);
            }
        }
        blockMatrix.push_back(blockMatrixRow);
    }
};

Tetromino::Tetromino() : topLeftCorner{0, 0}, matrixSize{0} {};

void Tetromino::rotateCounterClockwise()
{
    // Første rotasjon, med hensyn på diagonalen
    for (int row = 0; row < matrixSize; row++)
    {
        for (int column = 0; column < row; column++)
        {
            std::swap(blockMatrix[row][column], blockMatrix[column][row]);
        }
    }

    // Andre rotasjon, med hensyn på den midtre raden
    for (int row = 0; row < matrixSize / 2; row++)
    {
        for (int column = 0; column < matrixSize; column++)
        {
            std::swap(blockMatrix[row][column], blockMatrix[matrixSize - row - 1][column]);
        }
    }
}

void Tetromino::rotateClockwise()
{
    // Første rotasjon, med hensyn på diagonalen
    for (int row = 0; row < matrixSize; row++)
    {
        for (int column = 0; column < row; column++)
        {
            std::swap(blockMatrix[row][column], blockMatrix[column][row]);
        }
    }

    // Andre rotasjon, med hensyn på den midtre kolonnen
    for (int row = 0; row < matrixSize; row++)
    {
        for (int column = 0; column < matrixSize / 2; column++)
        {
            std::swap(blockMatrix[row][column], blockMatrix[row][matrixSize - column - 1]);
        }
    }
}

void Tetromino::moveDown()
{
    topLeftCorner.y += blockSize;
}

void Tetromino::moveLeft()
{
    topLeftCorner.x -= blockSize;
}

void Tetromino::moveRight()
{
    topLeftCorner.x += blockSize;
}

bool Tetromino::blockExists(int row, int column) const
{
    if (row < 0 || row > matrixSize || column < 0 || column > matrixSize)
    {
        throw std::out_of_range("Tetromino::blockExists() : The given block coordinates is outside the Tetromino Matrix.");
    }
    else
    {
        return blockMatrix[row][column] != TetrominoType::NONE ? true : false;
    }
}

TetrominoType Tetromino::getBlock(int row, int column) const
{
    if (blockExists(row, column))
    {
        return blockMatrix[row][column];
    }
    else
    {
        return TetrominoType::NONE;
    }
}

int Tetromino::getMatrixSize() const { return matrixSize; }

TDT4102::Point Tetromino::getPosition() const { return topLeftCorner; }

// !For debug
void Tetromino::printCurrentBlockMatrix()
{
    int lenght = blockMatrix.size();
    for (int r = 0; r < lenght; r++)
    {
        std::vector currentRow = blockMatrix.at(r);
        for (int c = 0; c < lenght; c++)
        {
            std::cout << static_cast<int>(currentRow.at(c)) << " ";
        }
        std::cout << "\n";
    }
}