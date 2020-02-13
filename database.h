#ifndef database_h
#define database_h

#include <string>

namespace CHNJAR003
{

void addStudent(const std::string fName, const std::string sName, const std::string studentNumber, const std::string classRecord);
void readDatabase(const std::string fileName);
void saveDatabase(const std::string fileName);
void displayStudentData(const std::string studentNumber);
void gradeStudent(const std::string studentNumber);

} // namespace CHNJAR003

#endif