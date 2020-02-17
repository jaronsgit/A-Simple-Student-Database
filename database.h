#ifndef database_h
#define database_h

#include <string>
#include <vector>

namespace CHNJAR003
{

struct Student
{
    std::string fName;
    std::string sName;
    std::string studentNumber;
    std::string classRecord;
};

extern std::vector<Student> StudentRecords;

void addStudent(const std::string fName, const std::string sName, const std::string studentNumber, const std::string classRecord);
void readDatabase(const std::string fileName);
void saveDatabase(const std::string fileName);
std::string displayStudentData(const std::string studentNumber);
float gradeStudent(const std::string studentNumber);
Student parseFileLine(const std::string line);
std::string serialiseStudent(const Student tempStudent);

} // namespace CHNJAR003

#endif