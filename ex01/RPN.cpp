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
        if (it == input.end())
            return ;
        if (isdigit(*it))
        {
            operation.push(*it - '0');
            digit++;
        }
        else if (is_operand(*it))
        {
            if (*it == '-')
            {
                ++it;
                if (is_operand(*it))
                {
                    int n = operation.top() * -1;
                    operation.pop();
                    operation.push(n);
                    try
                    {
                        solveCalculation(*it);
                    }
                    catch(std::exception &e)
                    {
                        std::cout << e.what() << std::endl;
                        break;
                    }
                    continue;
                }
                else
                {
                    --it;
                }
            }
            if (digit < 2 && operand == false)
            {
                 throw invalidOperation();
            }
            else
            {
                try
                {
                    solveCalculation(*it);
                }
                catch(std::exception &e)
                {
                    std::cout << e.what() << std::endl;
                    break;
                }
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
}

void RPN::solveCalculation(int operand)
{
    int a = 0;
    int b = 0;
    if (operation.size() < 2 )
        return ;
    switch (operand)
    {
        case 42 :
        {
            a = operation.top();
            operation.pop();
            b = operation.top();
            operation.pop();
            operation.push(b * a);
            break ;
        }
        case 47 :
        {
            a = operation.top();
            operation.pop();
            b = operation.top();
            operation.pop();
            if (a == 0 || b == 0)
                throw invalidDivition();
            operation.push(b / a);
            break;
        }
        case 45 :
        {
            a = operation.top();
            operation.pop();
            b = operation.top();
            operation.pop();
            operation.push(b - a);
            break ;
        }
        case 43:
        {
            a = operation.top();
            operation.pop();
            b = operation.top();
            operation.pop();
            operation.push(b + a);
            break;
        }
    }
}

void RPN::printResult(void)
{
    if (operation.size() > 1)
        throw invalidOperation();
    std::cout << operation.top() << std::endl;
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
const char *RPN::invalidDivition::what() const throw()
{
    return ("Error cannot divide by 0");
}
