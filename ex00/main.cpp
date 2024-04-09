#include "BitcoinExchange.hpp"
#include <exception>
#include <iostream>


int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    if (argc != 2)
    {
        std::cerr << "invalid number of arguments" << std::endl;
        return (1);
    }
    BitcoinExchange exchange;
    std::string arg = argv[1];
   try
   {
       exchange.checkInput(arg);
   }
   catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
}
