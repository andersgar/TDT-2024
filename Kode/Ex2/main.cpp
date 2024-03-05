#include "std_lib_facilities.h"
#include "oppg1.cpp"
#include "oppg2.cpp"
#include "oppg3.cpp"
#include "oppg4.cpp"
#include "oppg5.cpp"

int main()
{
    int chosenTask;
    bool userActive = true;
    while (userActive)
    {
        cout << "----------\n"
             << "Velg funksjon:\n"
             << "0) Avslutt!\n"
             << "1) inputAndPrintInteger()\n"
             << "2) inputInteger()\n"
             << "3) inputIntegerAndPrintSum()\n"
             << "4) isOdd()\n"
             << "5) AntallHeltallSum()\n"
             << "6) heltallSumNull()\n"
             << "7) inputDouble()\n"
             << "8) NOKTilEuro()\n"
             << "9) gangetabell()\n"
             << "10) solveQuadraticEquation()\n"
             << "11) Pythagoras()\n"
             << "12) calculateBalance()\n"
             << endl;
        cin >> chosenTask;
        switch (chosenTask)
        {
        case 0:
        {
            cout << "Takk for naa!" << endl;
            userActive = false;
            break;
        }
        case 1:
        {
            inputAndPrintInteger();
            break;
        }
        case 2:
        {
            int number = inputInteger();
            cout << "Du skrev: " << number << endl;
            break;
        }
        case 3:
        {
            inputIntegersAndPrintSum();
            break;
        }
        case 4:
        {
            int tall = inputInteger();
            cout << (isOdd(tall) ? "true; Tallet er Oddetall!" : "false; Tallet er Partall!") << endl;
            break;
        }
        case 5:
        {
            antallHeltallSum();
            break;
        }
        case 6:
        {
            heltallSumNull();
            break;
        }
        case 7:
        {
            inputDouble();
            break;
        }
        case 8:
        {
            NOKTilEuro();
            break;
        }
        case 9:
        {
            gangetabell();
            break;
        }
        case 10:
        {
            solveQuadraticEquation();
            break;
        }
        case 11:
        {
            Pythagoras();
            break;
        }
        case 12:
        {
            printBalance(calculateBalance(5000, 3, 10));
            break;
        }
        }
    }
    return 0;
}
