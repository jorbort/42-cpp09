#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        std::string arguments = argv[1];
        RPN polish;
        polish.parseInput(arguments);
    }
    else
    {
        std::cerr << "invalid amount of arguments" << std::endl;
    }
}
