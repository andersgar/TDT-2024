#include "Matrix.h"

Matrix::Matrix(int nRows, int nColumns) : rows(nRows), columns(nColumns) // Default constructor
{
    assert(nRows > 0 && nColumns > 0); // Verifies that the matrix has valid coordinates.
    data = new double *[rows];
    for (int i = 0; i < rows; i++)
    {
        data[i] = new double[columns](); // () Initializes the values to 0.
    }
};

Matrix::Matrix(const Matrix &rhs) : Matrix(rhs.rows, rhs.columns) // Copy constructor
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            data[i][j] = rhs.data[i][j];
        }
    }
}

Matrix::Matrix(int nRows) : Matrix(nRows, nRows) // Identity matrix (NxN-matrix)
{
    assert(nRows > 0);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (i == j) // Ecuals 1 on the diagonal.
            {
                data[i][j] = 1.0;
            }
            else
            {
                data[i][j] = 0.0;
            }
        }
    }
}

Matrix::~Matrix() // Destructor
{
    for (int i = 0; i < rows; i++)
    {
        delete[] data[i];
    }
    delete[] data;
};

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