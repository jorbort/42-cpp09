#include "RPN.hpp"

RPN::RPN()
{

}
RPN::RPN(RPN &cpy)
{
    *this = cpy;
}

RPN &RPN::operator=(RPN const &rhs)
{
    *this = rhs;
    return (*this);
}

RPN::~RPN()
{
    operation.empty();
}

void RPN::parseInput(std::string &input)
{

}
