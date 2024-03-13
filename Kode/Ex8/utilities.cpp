#include "utilities.h"

void fillInFibonacciNumbers(int *result, int length)
{
    if (length > 0)
    {
        result[0] = 0;
    }
    if (length > 1)
    {
        result[1] = 1;
    }
    for (int i = 2; i < length; i++)
    {
        result[i] = result[i - 1] + result[i - 2];
    }
}

void printArray(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void createFibonacci()
{
    int length;
    std::cout << "How many numbers do you want in the Fibonacci-sequence?" << std::endl;
    std::cin >> length;

    int *fibonacci = new int[length]{};
    fillInFibonacciNumbers(fibonacci, length);
    printArray(fibonacci, length);
    delete[] fibonacci;
}