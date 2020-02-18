#include "database.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#define PRINT(x) std::cout << x;

std::vector<CHNJAR003::Student> CHNJAR003::StudentRecords;

void CHNJAR003::addStudent(const std::string fName, const std::string sName, const std::string studentNumber, const std::string classRecord)
{

    bool recordAlreadyExists = false;

    //iterate through the existing records to check whether it exists already
    for (auto &aRecord : CHNJAR003::StudentRecords)
    {
        std::string tempRecordStudentNumber = aRecord.studentNumber;
        std::transform(tempRecordStudentNumber.begin(), tempRecordStudentNumber.end(), tempRecordStudentNumber.begin(), ::tolower);
        std::string newRecordStudentNumber = studentNumber;
        std::transform(newRecordStudentNumber.begin(), newRecordStudentNumber.end(), newRecordStudentNumber.begin(), ::tolower);

        if (tempRecordStudentNumber.compare(newRecordStudentNumber) == 0) //if the student record already exists, replace it
        {
            recordAlreadyExists = true;
            aRecord.fName = fName;
            aRecord.sName = sName;
            aRecord.classRecord = classRecord;
        }
    }
    if (!recordAlreadyExists) //if the record does not exist, add it
    {
        CHNJAR003::Student tempRecord;
        //entered details stored in temporary object to be added
        tempRecord.fName = fName;
        tempRecord.sName = sName;
        tempRecord.studentNumber = studentNumber;
        tempRecord.classRecord = classRecord;

        //add the record
        CHNJAR003::StudentRecords.push_back(tempRecord);
    }
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

        CHNJAR003::StudentRecords.clear();

        while (!databaseFile.eof())
        {
            std::string line;
            getline(databaseFile, line);
            if (line.size() > 1) //line is not empty
            {
                CHNJAR003::StudentRecords.push_back(parseFileLine(line));
            }
        }
        PRINT("All the records are:\n")
        for (CHNJAR003::Student temp : CHNJAR003::StudentRecords)
        {
            PRINT("\nFirst Name:\t" + temp.fName +
                  "\nLast Name:\t" + temp.sName +
                  "\nStudent Number:\t" + temp.studentNumber +
                  "\nClass Record:\t" + temp.classRecord + "\n\n");
        }
        PRINT("\n")
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
            databaseFile << serialiseStudent(temp) << std::endl;
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

float CHNJAR003::gradeStudent(const std::string studentNumber)
{

    for (CHNJAR003::Student temp : CHNJAR003::StudentRecords)
    {
        if (temp.studentNumber == studentNumber)
        {

            std::istringstream iss(temp.classRecord);
            std::string token;

            std::vector<std::string> marks;

            while (std::getline(iss, token, ' '))
            {
                marks.push_back(token);
            }

            float average;

            for (std::string mark : marks)
            {
                average += atof(mark.c_str());
            }

            return average / marks.size();
        }
    }
    return -1;
}

//Function to process a student record line from the textfile and resolve the record into its individual data parts
CHNJAR003::Student CHNJAR003::parseFileLine(const std::string line)
{

    CHNJAR003::Student temp;

    std::istringstream iss(line);
    std::string token;

    std::vector<std::string> tokens;

    //Break up the line delimited by commas
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

//Function to process a Student record from its struct form into a string that can be stored in a textfile.
std::string CHNJAR003::serialiseStudent(const CHNJAR003::Student tempStudent)
{
    std::string serialOut;
    serialOut = tempStudent.fName + "," + tempStudent.sName + "," + tempStudent.studentNumber + "," + tempStudent.classRecord;
    return serialOut;
}