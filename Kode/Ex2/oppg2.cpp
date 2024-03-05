#include "std_lib_facilities.h"

void antallHeltallSum()
{
    cout << "Hvor mange tall vil du summere?" << endl;
    int antNum;
    cin >> antNum;
    int summen = 0;
    int tall;
    for (int i = 0; i < antNum; i++)
    {
        cout << "Skriv inn tall: " << endl;
        cin >> tall;
        summen += tall;
    }
    cout << "Summen er: " << summen << endl;
}

void heltallSumNull()
{
    int summen = 0;
    int tall;
    while (tall != 0)
    {
        cout << "Skriv inn tall (0 for aa avslutte): " << endl;
        cin >> tall;
        summen += tall;
    }
    cout << "Summen er: " << summen << endl;
}

// c) I antallHeltallSum() bruker jeg en forløkke da den skal gjentas
// et gitt antall ganger fra brukerens input helt i starten. I heltallSumNull()
// derimot bruker jeg en while-løkke da den skal gjentas helt til brukeren
// velger å avslutte.

double inputDouble()
{
    double tall;
    cout << "Skriv inn et flyttall: " << endl;
    cin >> tall;
    return tall;
}

void NOKTilEuro()
{
    double NOK = inputDouble();
    double kurs = 9.75;
    if (NOK < 0)
    {
        cout << "Vennlist skriv inn et positivt flyttall!" << endl;
        NOK = inputDouble();
    }
    cout << fixed << setprecision(2) << NOK << " norske kroner er lik " << NOK / kurs << " Euro." << endl;
}

// f) Jeg bruker inputDouble() slik at man kan konvertere desimaltall, ikke bare heltall.
// Returtypen er derfor også double.

void gangetabell()
{
    cout << "Genererer gangetabell\n"
         << "Skriv inn onsket hoyde: " << endl;
    int hoyde;
    cin >> hoyde;
    cout << "Skriv inn onsket bredde: " << endl;
    int bredde;
    cin >> bredde;
    for (int i = 1; i < hoyde + 1; i++)
    {
        for (int j = 1; j < bredde + 1; j++)
        {
            cout << setw(3) << i * j;
        }
        cout << endl;
    }
}
