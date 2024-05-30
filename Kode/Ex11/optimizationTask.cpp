#include "Stopwatch.h"
#include <vector>
#include <iostream>

// Utdelt kode til oppgave 3

void setDiagonalValue(std::vector<std::vector<double>>& matrix, double newValue){
    for (int row = 0; row < matrix.size(); row++){
        for (int col = 0; col < matrix.size(); col++){
            //// bool isDiagonal = (row == col); Unneccesay to define, only used once. 
            if (row == col){
                matrix.at(row).at(col) = newValue;
            }
        }
    }
}

double sumMatrix(std::vector<std::vector<double>> matrix){
    double sum;
    for (int col = 0; col < matrix.size(); col++){
        for (int row = 0; row < matrix.size(); row++){
            //// double value = matrix.at(row).at(col);
            //// sum += value;
            sum += matrix.at(row).at(col); //Here also, not neccesary to define a variable. 
        }
    }
    return sum;
}

void optimizationTask() {
    
    const int matrixSize = 10000;

    // Create a matrix with zeros
    std::vector<std::vector<double>> matrix;
    matrix.reserve(matrixSize); //Reserving space for all the required column vectors.
    
    for (int i = 0; i < matrixSize; i++){
        std::vector<double> column;
        column.resize(matrixSize); // Resizing all coliumnVectors instead of adding every element induvidually.
        //// for (int j = 0; j < matrixSize; j++){
        ////     column.push_back(0.0);
        //// }
        matrix.push_back(column);
    }

    // Set all elements on the diagonal to 0.41
    setDiagonalValue(matrix, 0.41);
    
    // Sum all elements in the matrix
    double total = sumMatrix(matrix);

    double coolerNumber = total + 2;
    std::cout << "TDT" << coolerNumber << std::endl;
}