#include "std_lib_facilities.h"
#include "utilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes)
{
    for (int i = 0; i < numTimes; i++)
    {
        startValue += increment;
    }
    return startValue;
}

void incrementByValueNumTimesRef(int &startValue, int increment, int numTimes)
{
    for (int i = 0; i < numTimes; i++)
    {
        startValue += increment;
    }
}

void swapNumbers_pbv(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside swap function; a: " << a << "\tb: " << b << endl;
}
/**
 **Pass by value;
    Må kompiere variabler, noe som kan ta tid ved store datamengder.
    Lager nye variabler lokalt og returnerer disse.
*/

void swapNumbers_pbr(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside swap function; a: " << a << "\tb: " << b << endl;
}
/**
 **Pass by reference;
    Bruker bare referansen til eksisterende variabler og endrer disse, trenger ikke returnere noe.
    Sannsynligvis beste løsning i dette tilfellet.
*/

void swapNumbers_pbcr(const int &a, const int &b)
{
    int newA = b;
    int newB = a;
    cout << "Inside swap function; a: " << a << "\tb: " << b << endl;
}
/**
 **Pass by const-reference;
    Refererer til eksisterende variabler som ikke kan endres. Må derfor definere helt nye variabler som returneres.
    Fordel er at veriene ikke trenger å kopieres, sparer tid.
*/

void printStudent(Student stud)
{
    cout << stud.name << " is a student in " << stud.studyProgram << " and is " << stud.age << " years old." << endl;
}

bool isInProgram(Student stud, string program)
{
    bool state;
    if (stud.studyProgram == program)
    {
        state = true;
    }
    else
    {
        state = false;
    }

    return state;
}

string randomizeString(int charNum, char lowerChar, char upperChar)
{
    string randomString;

    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(lowerChar, upperChar);
    for (int i = 0; i < charNum; i++)
    {
        char randomChar = static_cast<char>(distribution(generator));
        randomString = randomString + randomChar;
    }

    return randomString;
}

string readInputToString(int n, char lowerChar, char upperChar)
{
    string inputString;
    while (true)
    {
        cout << "Input excactly " << n << " characters between " << lowerChar << " and " << upperChar << "!" << endl;
        cin >> inputString;

        if (inputString.length() == n) // Correct lenght
        {
            bool valid = true;
            for (char inputChar : inputString)
            {
                if (inputChar < lowerChar || inputChar > upperChar) // Wrong letters
                {
                    valid = false;
                    break;
                }
            }
            if (valid) // Correct length and letters
            {
                return inputString;
            }
            else // Wrong lettes
            {
                cout << "##### Please only input charachters between " << lowerChar << " and " << upperChar << ". #####" << endl;
            }
        }
        else // Wrong lenght
        {
            cout << "##### Please input exacly " << n << " characters. #####" << endl;
        }
    }
}

int countChar(string testString, char testChar)
{
    int count = 0;

    for (int i = 0; i < testString.size(); i++)
    {
        if (testString[i] == testChar)
        {
            count++;
        }
    }
    return count;
}

int checkCharactersAndPosition(string toBeChecked, string toCheck)
{
    int correct = 0;
    for (int i = 0; i < toBeChecked.length(); i++)
    {
        if (toBeChecked[i] == toCheck[i])
        {
            correct++;
        }
    }

    return correct;
}

int checkCharacters(string toBeChecked, char toCheck)
{
    /*int correct = 0;
    string countedChars;

    for (char currentChar : toCheck)
    {
        if (countedChars.find(currentChar) == string::npos)
        {
            correct += countChar(toBeChecked, currentChar);
            countedChars += currentChar;
        }
    }*/

    int correct = 0;
    string toBeCheckedLeft = toBeChecked;

    while (toBeCheckedLeft.length() > 0)
    {
        for (char charToBeChecked : toBeCheckedLeft)
        {
            if (toBeCheckedLeft.find(toCheck) == string::npos)
            {
                correct += countChar(toBeCheckedLeft, toCheck);
                toBeCheckedLeft.erase(remove(toBeCheckedLeft.begin(), toBeCheckedLeft.end(), toCheck), toBeCheckedLeft.end());
            }
        }
    }

    return correct;
}