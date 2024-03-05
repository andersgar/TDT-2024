#include "std_lib_facilities.h"

void inputAndPrintInteger()
{
    int tall;
    cout << "Skriv inn et tall: " << endl;
    cin >> tall;
    cout << "Du skrev tallet " << tall << "!" << endl;
}

int inputInteger()
{
    int tall;
    cout << "Skriv inn et tall: " << endl;
    cin >> tall;
    return tall;
}

void inputIntegersAndPrintSum()
{
    int tall1 = inputInteger();
    int tall2 = inputInteger();
    int summen = tall1 + tall2;
    cout << "Summen av tallene: " << summen << endl;
}

// e) Valgte å bruke inputInteger() fremfor inputAndPrintInteger() da
//  kun førstnevnte returnerer integeren, den andre printer bare til skjerm.

bool isOdd(int i)
{
    if (i % 2 == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
