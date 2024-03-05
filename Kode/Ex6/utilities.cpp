#include "utilities.h"

void userInputFile()
{
    filesystem::path currentFile{"myFile.txt"};
    ofstream outputStream{currentFile};

    string inputWord;
    cout << "Please write a word to be inputed into the file." << endl;
    cin >> inputWord;

    while (inputWord != "quit")
    {
        outputStream << inputWord << endl;

        cout << "Please write a new word to be inputed into the file. Write 'quit' when finished." << endl;
        cin >> inputWord;
    }
}

void addLineNumber(filesystem::path fileToCopy)
{
    ifstream inputStream{fileToCopy};
    filesystem::path copiedFile{fileToCopy.stem()};
    copiedFile += "-copy.txt";
    ofstream outputStream{copiedFile}; // Names copied file [originalFileName]-copy.txt

    if (!inputStream)
    {
        cout << "Could not open file." << endl;
    }

    string line;
    int lineNumber = 1;

    while (getline(inputStream, line))
    {
        outputStream << lineNumber << ": " << line << endl;
        lineNumber++;
    }
}

string getCapital(const string &country)
{
    return capitalsMap.at(country); //* 2a) Her stod det capitalsMap[country], endret til .at(country).
}

void CourseCatalog::addCourse(string subjectCode, string subjectName)
{
    subjectCodesAndNames.insert(make_pair(subjectCode, subjectName));
}

void CourseCatalog::removeCourse(string subjectCode)
{
    subjectCodesAndNames.erase(subjectCode);
}

string CourseCatalog::getCourse(string subjectCode)
{
    return subjectCodesAndNames.at(subjectCode);
}

ostream &operator<<(ostream &os, const CourseCatalog &c)
{
    for (pair subject : c.subjectCodesAndNames)
    {
        os << "Subject code: " << subject.first << " Subject name: " << subject.second << endl;
    }
    return os;
}

void testOverlastOperator()
{
    CourseCatalog c;
    c.addCourse("TDT4110", "Informasjonsteknologi grunnkurs");
    c.addCourse("TDT4102", "Posedyre- og objektorientert programmering");
    c.addCourse("TMA4100", "Matematikk 1");
    cout << c << endl;
}

void CourseCatalog::updateCourseName(string subjectToUpdate, string newSubjectName)
{
    if (subjectCodesAndNames.find(subjectToUpdate) == subjectCodesAndNames.end())
    {
        cout << "Subject code wasnt found, please try again." << endl;
        return;
    }
    else
    {
        subjectCodesAndNames[subjectToUpdate] = newSubjectName;
        // * Det er letter å bruke [] operatorene når objektet allerede finnes i mapet
        // * da nøkkelen til elementet allerede finnes.
    }
}

void CourseCatalog::saveCoursesToFile()
{
    mapSaveFile = "subjectCodesAndNames.txt";
    mapSaveTo = mapSaveFile;

    for (pair subject : subjectCodesAndNames)
    {
        mapSaveTo << subject.first << ":" << subject.second << endl;
    }
}

void CourseCatalog::getCoursesFromFile()
{
    mapSaveFile = "subjectCodesAndNames.txt";
    mapGetFrom = mapSaveFile;

    if (!mapGetFrom)
    {
        cout << "Could not open file " << mapSaveFile << endl;
        return;
    }

    string line;
    while (getline(mapGetFrom, line))
    {
        stringstream ss(line); // Splits each line into code and name using ':' divider
        string subjectCode, subjectName;
        getline(ss, subjectCode, ':');
        getline(ss, subjectName);
        addCourse(subjectCode, subjectName);
    }
}