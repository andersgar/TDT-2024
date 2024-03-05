#include "std_lib_facilities.h"

double discriminant(double a, double b, double c)
{
    return pow(b, 2) + 4 * a * c;
}

void printRealRoots(double a, double b, double c)
{
    double x_1 = (-b + sqrt(discriminant(a, b, c))) / 2 * a;
    double x_2 = (-b - sqrt(discriminant(a, b, c))) / 2 * a;
    if (discriminant(a, b, c) > 0)
    {
        cout << "Ligningen har to losninger, x_1=" << x_1 << " og x_2=" << x_2 << endl;
    }
    else if (discriminant(a, b, c) == 0)
    {
        cout << "Ligningen har èn losning, x=" << x_1 << endl;
    }
    else
    {
        cout << "Ligningen har ingen losning." << endl;
    }
}

void solveQuadraticEquation()
{
    double a, b, c;
    cout << "Skriv inn respektive verdier for a, b og c:" << endl;
    cin >> a;
    cin >> b;
    cin >> c;
    printRealRoots(a, b, c);
}
