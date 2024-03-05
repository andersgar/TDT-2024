#pragma once
#include "std_lib_facilities.h"
#include <fstream>
#include <string>
#include <map>

void userInputFile();
void addLineNumber(filesystem::path fileToCopy);

void testOverlastOperator();

const map<string, string> capitalsMap{
    {"Norway", "Oslo"},
    {"Sweden", "Stockholm"},
    {"Denmark", "Copenhagen"}};

string getCapital(const string &country);

class CourseCatalog
{
private:
    map<string, string> subjectCodesAndNames{
        ////{"TDT4102", "Posedyre- og objektorientert programmering"},
        ////{"IMAT2012", "Matematikk for ingeniørfag 2A"},
        ////{"ELET1002", "Elektriske kretser - modellering og analyse"},
        ////{"IFYT", "Fysikk"}
    };
    filesystem::path mapSaveFile;
    ofstream mapSaveTo;
    ifstream mapGetFrom;

public:
    CourseCatalog(){};
    friend ostream &operator<<(ostream &os, const CourseCatalog &c);

    void addCourse(string subjectCode, string subjectName);
    void removeCourse(string subjectCode);
    string getCourse(string subjectCode);
    void updateCourseName(string subjectToUpdate, string newSubjectName);
    void saveCoursesToFile();
    void getCoursesFromFile();
};
