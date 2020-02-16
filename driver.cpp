#include <iostream>
#include <cstdlib>
#include <string>
#include "database.h"

#define PRINT(x) std::cout << x;

int main(void)
{

    system("clear");
    for (;;)
    {

        PRINT("0: Add Student\n");
        PRINT("1: Read Database\n");
        PRINT("2: Save Database\n");
        PRINT("3: Display Given Student Data\n");
        PRINT("4: Grade Given Student\n");
        PRINT("q: Quit\n\n");
        PRINT("Enter a given number (or q to quit) and press return: ")

        /*
        std::cout << "\n0: Add Student\n\
    1: Read Database\n\
    2: Save Database\n\
    3: Display Given Student Data\n\
    4: Grade Given Student\n\
    q: Quit\n\n\
    Enter a given number (or q to quit) and press return: ";*/

        char entered;
        std::cin >> entered;
        // std::cout << entered;

        CHNJAR003::Student tempStudent; //temporary Student structure to hold details of one student record.
        std::string fileName;

        switch (entered)
        {

        case '0':
            //std::cout << "\nPlease enter student details:";
            PRINT("\nPlease enter student details:");
            PRINT("\nEnter first name: ");
            std::cin >> tempStudent.fName;
            PRINT("\nEnter last name: ");
            std::cin >> tempStudent.sName;
            PRINT("\nEnter student number: ");
            std::cin >> tempStudent.studentNumber;
            PRINT("\nEnter class record (e.g. 78 67 89 91): ");
            //std::cin >> tempStudent.classRecord;
            std::getline(std::cin, tempStudent.classRecord);

            CHNJAR003::addStudent(tempStudent.fName, tempStudent.sName, tempStudent.studentNumber, tempStudent.classRecord);
            PRINT("Function addStudent() called.");

            break;
        case '1':

            //std::cout << "\nPlease enter database file name: ";
            PRINT("\nPlease enter database file name: ");
            std::cin >> fileName;
            CHNJAR003::readDatabase("hello.txt");
            std::cout << "\nFunction readDatabase() called with file name: " << fileName << "\n";

            break;

        case '2':

            PRINT("\nPlease enter file name: ");
            std::cin >> fileName;
            CHNJAR003::saveDatabase(fileName);
            PRINT("\nFunction saveDatabase() called.");

            break;
        }

        if (entered == 'q')
        {
            break;
        }
    }

    return 0;
}
