#include "std_lib_facilities.h"
#pragma once

int incrementByValueNumTimes(int startValue, int increment, int numTimes);
void incrementByValueNumTimesRef(int &startValue, int increment, int numTimes);
void swapNumbers_pbv(int a, int b);
void swapNumbers_pbr(int &a, int &b);
void swapNumbers_pbcr(const int &a, const int &b);

struct Student
{
    string name;
    string studyProgram;
    int age;
};

void printStudent(Student stud);
bool isInProgram(Student stud, string program);

string randomizeString(int charNum, char lowerChar, char upperChar);

string readInputToString(int n, char lowerChar, char upperChar);

int countChar(string testString, char testChar);

int checkCharactersAndPosition(string toBeChecked, string toCheck);
int checkCharacters(string toBeChecked, char toCheck);