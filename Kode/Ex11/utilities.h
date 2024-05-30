#pragma once
#include <iostream>
#include "Stopwatch.h"
#include <array>
#include <functional> //Lets me use functions as argument in loopAndTime function.
#include <random>

void initUniquePtr();
void initSharedPtr();
void stackAlloc();
void heapAlloc();

void loopAndTime(const std::function<void()> func, const std::string funcName, const int timesToLoop);

template <typename T>
T maximum(T rhs, T lhs)
{
    if (rhs > lhs)
    {
        return rhs;
    }
    else
    {
        return lhs;
    }
}

template <typename T>
void shuffle(std::vector<T> &toBeShuffled)
{
    std::vector<T> shuffeled = toBeShuffled; 
    std::default_random_engine re(123);
    std::shuffle(toBeShuffled.begin(), toBeShuffled.end(), re);
}