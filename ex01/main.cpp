#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        std::string arguments = argv[1];
        RPN polish;
        try
        {
            polish.parseInput(arguments);
        }
        catch (std::exception & e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    else
    {
        std::cerr << "invalid amount of arguments" << std::endl;
    }
}
