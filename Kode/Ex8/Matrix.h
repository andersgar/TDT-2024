#pragma once
#include <cassert>
#include <iostream>

class Matrix
{
private:
    int rows;
    int columns;
    double **data;

public:
    Matrix(int nRows, int nColumns) : rows(nRows), columns(nColumns) // Default constructor
    {
        assert(nRows > 0 && nColumns > 0); // Verifies that the matrix has valid coordinates.
        data = new double *[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new double[columns](); // () Initializes the values to 0.
        }
    };

    explicit Matrix(int nRows) : Matrix(nRows, nRows) // Identity matrix
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
    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;
    };

    double *operator[](int index)
    {
        return data[index];
    };
    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);

    double get(int row, int col) const;
    void set(int row, int col, double value);

    int getRows() const;
    int getColumns() const;
};
