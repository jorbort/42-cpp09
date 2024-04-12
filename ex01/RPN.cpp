#include "RPN.hpp"
#include <cctype>
#include <exception>
#include <string>
#include <iostream>

RPN::RPN()
{

}
RPN::RPN(RPN &cpy)
{
    *this = cpy;
}

RPN &RPN::operator=(RPN const &rhs)
{
    (void) rhs;
    return (*this);
}

RPN::~RPN()
{
    operation.empty();
}

void RPN::parseInput(std::string &input)
{
    std::string::iterator it = input.begin();
    bool operand = false;
    int digit = 0;

    for (;it != input.end(); it++)
    {
        if (isdigit(*it))
        {
            operation.push(*it - '0');
            digit++;
        }
        else if (is_operand(*it))
        {
            if (digit < 2 && operand == false)
            {
                 throw invalidOperation();
            }
            else
            {
               //operation.push(*it);
               solveCalculation(*it);
               operand = true;
               digit = 0;
            }
        }
        else if(isspace(*it))
        {
            continue;
        }
        else
            throw invalidArgument();
    }
    std::cout << (char)operation.top() <<std::endl;
}

bool RPN::is_operand(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' )
        return (true);
    else
    return (false);
}


const char* RPN::invalidOperation::what() const throw()
{
    return ("Error: the operation does not respect the reverse polish notation proper sintax");;
}

const char* RPN::invalidArgument::what() const throw()
{
    return ("Error: invalid argument detected");
}
