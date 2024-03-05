#include "std_lib_facilities.h"

//* TESTS¨
/*int increaseVal(int a)
{
    a++;
    cout << "INT" << endl;
    return a;
}*/
double increaseVal(int a)
{
    a++;
    cout << "DOUB" << endl;
    return a;
}

int main()
{
    int a = 2;
    increaseVal(a);
    increaseVal(a);
    cout << a << endl;
    return 0;
}