#include "utilities.h"

void initUniquePtr()
{
    int randomVariable = 1;
    std::unique_ptr<int> up(new int(randomVariable));
}

void initSharedPtr()
{
    int randomVariable = 1;
    std::shared_ptr<int> sp(new int(randomVariable));
}

void stackAlloc()
{
    constexpr int size = 10000;
    std::array<int, size> arr1;
}

void heapAlloc()
{
    constexpr int size = 10000;
    std::array<int, size> *arr2 = new std::array<int, size>;
    delete arr2;
}

void loopAndTime(const std::function<void()> func, const std::string funcName, const int timesToLoop)
{
    Stopwatch sw;
    int i = 0;
    sw.start();
    while (i <= timesToLoop)
    {
        func();
        i++;
    };

    double timeElapsed = sw.stop();
    double timePerIteration = timeElapsed / i;

    std::cout << funcName << ": Total time elapsed: " << std::to_string(timeElapsed) << ", Average time per iteration: " << std::to_string(timePerIteration) << std::endl;
}

