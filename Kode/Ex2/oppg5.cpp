#include "std_lib_facilities.h"

vector<int> calculateBalance(int innskudd, int rente, int antallAar)
{
    vector<int> saldo(antallAar + 1);
    saldo.at(0) = innskudd;
    for (int i = 1; i < antallAar + 1; i++)
    {
        saldo.at(i) = innskudd * pow(1 + (rente / 100.0), i);
        cout << innskudd << endl;
    }
    return saldo;
}

void printBalance(vector<int> saldoer)
{
    cout << "Aar" << setw(10) << "Saldo" << endl;
    for (int i = 0; i < saldoer.size(); i++)
    {
        cout << i << setw(10) << saldoer.at(i) << endl;
    }
}

// c) man kan ikke skrive ut en vektor i sin helhet til cout, man kan
// eventuelt skrive den ut ledd for ledd vha. en for-løkke.
