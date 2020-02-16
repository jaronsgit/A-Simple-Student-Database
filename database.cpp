#include "database.h"
#include <fstream>

std::vector<CHNJAR003::Student> CHNJAR003::StudentRecords;

void CHNJAR003::addStudent(const std::string fName, const std::string sName, const std::string studentNumber, const std::string classRecord)
{
    CHNJAR003::Student tempRecord;

    tempRecord.fName = fName;
    tempRecord.sName = sName;
    tempRecord.studentNumber = studentNumber;
    tempRecord.classRecord = classRecord;

    CHNJAR003::StudentRecords.push_back(tempRecord);
}

void CHNJAR003::readDatabase(const std::string fileName)
{
    std::ofstream databaseFile;

    databaseFile.open(fileName.c_str());

    databaseFile << "Hello File!";
    databaseFile.close();
}
