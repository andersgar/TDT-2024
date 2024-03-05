#include "std_lib_facilities.h"

// a)
int maxOfTwo(int a, int b)
{
    if (a > b)
    {
        cout << "A is greater than B" << endl;
        return a;
    }
    else
    {
        cout << "B is grater than A" << endl;
        return b;
    }
}

// c)
int fibonacci(int n)
{
    int a = 0;
    int b = 1;
    cout << "Fibonacci numbers" << endl;
    for (int i = 1; i < (n + 1); i++)
    {
        cout << i << " " << b << endl;
        int temp = b;
        b += a;
        a = temp;
    }
    cout << "---" << endl;
    return b;
}

// d)
double sqareNumberSum(int n)
{
    double totalsum = 0;
    for (int i = 1; i < (n + 1); i++)
    {
        totalsum += i * i;
        cout << i * i << endl;
    }
    cout << totalsum << endl;
    return totalsum;
}

// e)
void triandgleNumbersBelow(int n)
{
    int acc = 1;
    int num = 2;
    cout << "Triangle numers below " << n << ":" << endl;
    while (acc < n)
    {
        cout << acc << endl;
        acc += num;
        num++;
    }
}

// f)
bool isPrime(int n)
{
    for (int j = 2; j < n; j++)
    {
        if (n % j == 0)
        {
            return false;
        }
    }
    return true;
}

// g)
void naivePrimeNumberSearch(int n)
{
    for (int number = 2; number < n; number++)
    {
        if (isPrime(number))
        {
            cout << number << " is a prime" << endl;
        }
    }
}

// h)
void inputAndPrintNameAndAge()
{
    cout << "Skriv inn et navn: " << endl;
    string name;
    cin >> name;
    cout << "Skriv inn alderen til " << name << ": " << endl;
    int age;
    cin >> age;
    cout << name << " er " << age << " aar gammel." << endl;
}

int main()
{
    cout << "Oppgave a)" << endl;
    cout << maxOfTwo(5, 6) << endl;

    cout << "Oppgave c)" << endl;
    cout << fibonacci(5) << endl;

    cout << "Oppgave d)" << endl;
    cout << sqareNumberSum(5) << endl;

    cout << "Oppgave e)" << endl;
    triandgleNumbersBelow(10);

    cout << "Oppgave f) og g)" << endl;
    naivePrimeNumberSearch(14);

    cout << "Oppgave h)" << endl;
    inputAndPrintNameAndAge();
    return 0;
}