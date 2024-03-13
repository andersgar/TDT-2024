#include "Matrix.h"

double Matrix::get(int row, int col) const
{
    return data[row][col];
}

void Matrix::set(int row, int col, double value)
{
    data[row][col] = value;
}

int Matrix::getRows() const
{
    return rows;
}

int Matrix::getColumns() const
{
    return columns;
}

std::ostream &operator<<(std::ostream &cout, const Matrix &matrix)
{
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.columns; j++)
        {
            cout << matrix.data[i][j] << " ";
        }
        cout << std::endl;
    }
    return cout;
}