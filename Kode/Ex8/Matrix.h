#pragma once
#include <cassert>
#include <iostream>
#include <utility>

class Matrix
{
private:
    int rows;
    int columns;
    double **data;

public:
    Matrix(int nRows, int nColumns); // Default constructor
    Matrix(const Matrix &rhs);       // Copy constructor
    explicit Matrix(int nRows);      // Identity matrix (NxN-matrix)

    ~Matrix(); // Destructor

    double *operator[](int index) { return data[index]; };
    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);
    Matrix &operator=(Matrix rhs)
    {
        assert(rows == rhs.rows && columns == rhs.columns); // Verifies that the matrices are the same size.
        std::swap(data, rhs.data);
        return *this;
    }
    Matrix &operator+=(Matrix rhs)
    {
        assert(rows == rhs.rows && columns == rhs.columns); // Verifies that the matrices are the same size.
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                this->data[i][j] = data[i][j] + rhs.data[i][j];
            }
        }
        return *this;
    }
    Matrix &operator+(Matrix rhs)
    {
        *this += rhs;
        return *this;
    }

    Matrix &operator-=(Matrix rhs)
    {
        assert(rows == rhs.rows && columns == rhs.columns); // Verifies that the matrices are the same size.
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                this->data[i][j] = data[i][j] - rhs.data[i][j];
            }
        }
        return *this;
    }

    Matrix &operator-(Matrix rhs)
    {
        *this -= rhs;
        return *this;
    }

    Matrix &operator*=(Matrix rhs)
    {
        assert(rows == rhs.rows && columns == rhs.columns); // Verifies that the matrices are the same size.
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                this->data[i][j] = data[i][j] * rhs.data[i][j];
            }
        }
        return *this;
    }

    Matrix &operator*(Matrix rhs)
    {
        *this *= rhs;
        return *this;
    }

    double get(int row, int col) const;
    void set(int row, int col, double value);

    int getRows() const;
    int getColumns() const;
};
