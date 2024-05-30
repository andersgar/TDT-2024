#include "utilities.h"
#include "optimizationTask.h"
#include "MyArray.h"

int main()
{
    //* Task1:
    // loopAndTime(initUniquePtr, "Initialising unique_ptr", 100);
    // loopAndTime(initSharedPtr, "Initialising shared_ptr", 100);
    // loopAndTime(stackAlloc, "Allocation on stack", 100);
    // loopAndTime(heapAlloc, "Allocation on heap", 100);

    //* Task2:
    // std::vector<int> testVector;
    // Stopwatch sw;

    // testVector.reserve(1e6);
    // std::cout << "Before filling: " << testVector.size() << " , " << testVector.capacity() << std::endl;

    // sw.start();
    // for (int i = 0; i < 1e6; i++)
    // {
    //     testVector.push_back(i);
    //     std::cout << testVector.size() << " , " << testVector.capacity() << std::endl;
    // }
    // double timeUsed = sw.stop();
    // std::cout << "Time used to fill; " << std::to_string(timeUsed) << std::endl;

    // // Non-optimized: 131.043785 s
    // // Using reserve(): 137.694563 s
    // // Using resize(): 131.353774 s
    // // ->> Idk why but non-optimized is the fastest.

    //* Task3:
    // Stopwatch sw;
    // sw.start();
    // optimizationTask();
    // double elapsedTime = sw.stop();
    // std::cout << std::to_string(elapsedTime) << std::endl;

    // // Pre-optimization: 11.847743 s
    // // Post-optimization: 9.105055 s
    // // Using release mode: 5.920013 s

    //* Task 4:
    // int a = 1;
    // double b = 2.3;
    // double c = maximum<double>(a, b);

    // std::cout << c << std::endl;

    // std::vector<double> a{1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
    // shuffle(a);
    // for (int i = 0; i <= a.size() - 1; i++)
    // {
    //     std::cout << a.at(i) << ", ";
    // }
    // std::cout << std::endl;

    //* Task 5:
    MyArray<std::string, 10> arr1;
    arr1.fill("HALLA");
    // std::cout << arr1.at(2) << std::endl;

    for (int i = 0; i < arr1.getSize(); i++)
    {
        std::cout << arr1.at(i) << ", ";
    }
    std::cout << std::endl;

    return 0;
}