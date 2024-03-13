#include "utilities.h"
#include "Matrix.h"
#include "Dummy.h"
#include <iostream>

int main()
{
    //* Task 1 test:
    // createFibonacci();

    //* Task 2 tests;
    /* Matrix A{4};
    std::cout << A;

    Matrix B{3, 6};
    B.set(1, 1, 5.0);
    B.set(1, 2, 10.0);
    B.set(1, 3, 15.0);
    std::cout << B;
    std::cout << "Matrix B has " << B.getRows() << " rows and " << B.getColumns() << " coulumns." << std::endl;
    std::cout << "In matrix B, value at (1,2) is: " << B[1][2] << std::endl; */

    //* Task 3 test
    // dummyTest();

    //* Task 4 test
    /* Matrix C{8};
    C.set(1, 1, 5.0);
    C.set(3, 2, 10.0);
    C.set(6, 2, 15.0);

    //Matrix D{8};
    //D = C;
    std::cout << C << std::endl;
    std::cout << "_____-----_____" << std::endl;
    std::cout << D << std::endl; */

    //* Task 5 test
    Matrix A{2, 2}, B{2, 2}, C{2, 2};
    A.set(0, 0, 1.0);
    A.set(0, 1, 2.0);
    A.set(1, 0, 3.0);
    A.set(1, 1, 4.0);

    B.set(0, 0, 4.0);
    B.set(0, 1, 3.0);
    B.set(1, 0, 2.0);
    B.set(1, 1, 1.0);

    C.set(0, 0, 1.0);
    C.set(0, 1, 3.0);
    C.set(1, 0, 1.5);
    C.set(1, 1, 2.0);

    A += B * C;
    std::cout << A << std::endl;
    return 0;
}