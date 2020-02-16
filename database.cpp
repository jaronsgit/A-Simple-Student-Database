#include "database.h"

void addStudent(const std::string fName, const std::string sName, const std::string studentNumber, const std::string classRecord)
{
    CHNJAR003::Student tempRecord;

    tempRecord.fName = fName;
    tempRecord.sName = sName;
    tempRecord.studentNumber = studentNumber;
    tempRecord.classRecord = classRecord;

    CHNJAR003::StudentRecords.push_back(tempRecord);
}