#include <iostream>
#include <cstdlib>
#include <string>

int main(void)
{
    for (;;)
    {
        std::cout << "\n0: Add Student\n\
    1: Read Database\n\
    2: Save Database\n\
    3: Display Given Student Data\n\
    4: Grade Given Student\n\
    q: Quit\n\n\
    Enter a given number (or q to quit) and press return: ";

        std::string entered;
        std::cin >> entered;

        std::cout << entered;

        if (entered.compare("q") == 0)
        {
            break;
        }
    }

    return 0;
}