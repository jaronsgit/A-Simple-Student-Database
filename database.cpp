#include "database.h"
#include <fstream>
#include <iostream>
#include <sstream>
#define PRINT(x) std::cout << x;

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
    std::ifstream databaseFile;

    databaseFile.open(fileName.c_str());

    if (!databaseFile)
    { //If databaseFile could not be opened
        std::cerr << "databaseFile: " << fileName << " could not be opened for reading.";
    }
    else
    {

        while (!databaseFile.eof())
        {
            std::string line;
            getline(databaseFile, line);
            CHNJAR003::StudentRecords.push_back(parseFileLine(line));
        }
        PRINT("All the records are:\n")
        for (CHNJAR003::Student temp : CHNJAR003::StudentRecords)
        {
            PRINT(temp.fName + "\n");
        }
    }

    databaseFile.close();
}

void CHNJAR003::saveDatabase(const std::string fileName)
{

    /*for (CHNJAR003::Student temp : CHNJAR003::StudentRecords)
    {
        PRINT(temp.fName);
    }*/

    std::ofstream databaseFile;
    databaseFile.open(fileName.c_str());

    if (databaseFile.is_open())
    {

        for (CHNJAR003::Student temp : CHNJAR003::StudentRecords)
        {
            databaseFile << serialiseStudent(temp) << "\n";
        }

        databaseFile.close();
    }
}

std::string CHNJAR003::displayStudentData(const std::string studentNumber)
{

    for (CHNJAR003::Student temp : CHNJAR003::StudentRecords)
    {
        if (temp.studentNumber == studentNumber)
        {
            return "\nFirst Name:\t" + temp.fName +
                   "\nLast Name:\t" + temp.sName +
                   "\nStudent Number:\t" + temp.studentNumber +
                   "\nClass Record:\t" + temp.classRecord + "\n\n";
        }
    }

    return "Student record could not be found.";
}

CHNJAR003::Student CHNJAR003::parseFileLine(const std::string line)
{

    CHNJAR003::Student temp;

    std::istringstream iss(line);
    std::string token;

    std::vector<std::string> tokens;

    while (std::getline(iss, token, ','))
    {
        tokens.push_back(token);
    }

    temp.fName = tokens[0];
    temp.sName = tokens[1];
    temp.studentNumber = tokens[2];
    temp.classRecord = tokens[3];

    /*for (int i = 0; i < 4; i++)
    {
        PRINT(std::to_string(i) + ":" + tokens[i] + "\n");

    }
    
    for (std::string temp : tokens)
    {
        PRINT(temp + '\n');
    }*/

    return temp;
}

std::string CHNJAR003::serialiseStudent(const CHNJAR003::Student tempStudent)
{
    std::string serialOut;
    serialOut = tempStudent.fName + "," + tempStudent.sName + "," + tempStudent.studentNumber + "," + tempStudent.classRecord;
    return serialOut;
}