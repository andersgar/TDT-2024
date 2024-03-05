#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"

void testCallByValue()
{
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0
         << " increment: " << increment
         << " iterations: " << iterations
         << " result: " << result << endl;
}

void testCallByReference()
{
    int v;
    int v0;
    v = 5;
    v0 = 5;
    int increment = 2;
    int iterations = 10;
    incrementByValueNumTimesRef(v, increment, iterations);
    cout
        << "v0: " << v0
        << " increment: " << increment
        << " iterations: " << iterations
        << " result: " << v << endl;
}

void testSwapNumbers()
{
    int a, b;
    a = 10;
    b = 20;

    cout << "Which type would you like to test?\nCall by:\t1)Value  2)Reference  3)Const-reference" << endl;
    int chosenFunc;
    cin >> chosenFunc;
    switch (chosenFunc)
    {
    case 1:
        swapNumbers_pbv(a, b);
        break;
    case 2:
        swapNumbers_pbr(a, b);
        break;
    case 3:
        swapNumbers_pbcr(a, b);
        break;
    }
    cout << "Outside swap function; a: " << a << "\tb: " << b << endl;
}

void testStudStruct()
{
    Student anders{"Anders Garberg", "BIAIS", 21};
    Student ola{"Ola Normann", "Economics", 20};
    Student kari{"Kari Normann", "Mathematics", 19};

    // vector<Student *> studNames{anders, ola, kari};

    cout << "Type in a study program to check against" << endl;
    string checkProgram;
    cin >> checkProgram;

    if (isInProgram(anders, checkProgram))
    {
        cout << anders.name << " is in fact studying " << checkProgram << "!" << endl;
    }
    printStudent(anders);
    /*for (int i = 0; i < studNames.size(); i++)
    {
        printStudent(Student studNames.at(i));
    }*/
}

void testString()
{
    int numGrades = 8;
    string randomGrades = randomizeString(numGrades, 'a', 'f');
    string orderGrades = "abcdef";

    vector<int> gradeCount(6);
    for (int i = 0; i < 6; i++)
    {
        gradeCount.at(i) = countChar(randomGrades, orderGrades[i]);
        cout << orderGrades[i] << " : " << gradeCount.at(i) << "  ";
    }

    vector<int> gradeValue = {6, 5, 4, 3, 2, 1};
    double averageGrade = inner_product(gradeCount.begin(), gradeCount.end(), gradeValue.begin(), 0) / numGrades;

    cout << "\n -> " << averageGrade << " is the average grade value." << endl;

    cout << "\n\n"
         << readInputToString(5, 'A', 'F') << endl;
}