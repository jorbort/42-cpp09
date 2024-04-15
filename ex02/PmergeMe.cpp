#include "PmergeMe.hpp"
#include <deque>

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(PmergeMe &src)
{
    *this = src;
}

PmergeMe& PmergeMe::operator=(PmergeMe &rhs)
{
    (void) rhs;
    return (*this);
}

PmergeMe::~PmergeMe()
{
    vec.clear();
    deq.clear();
}

void PmergeMe::addDeq(std::string input)
{
    if (!checkInput(input))
        throw invalidInputException();
    deq.push_back(std::atoi(input.c_str()));
}

void PmergeMe::addVec(std::string input)
{
    if (!checkInput(input))
        throw invalidInputException();
    vec.push_back(std::atoi(input.c_str()));
}


bool PmergeMe::checkInput(std::string input)
{
    long long int num = 0;
    if (input.length() > 10 || input[0] == '-')
        return (false);
    num = std::atoll(input.c_str());
    if (num > MAX_INT)
        return (false);
    return (true);
}

void PmergeMe::sortDeq(void)
{
    if (deq.size() % 2 != 0)
    {
        unsigned int stray = deq.back();
        deq.pop_back();
    }
}

void PmergeMe::printDeq(void)
{
    std::deque<unsigned int>::iterator itB = deq.begin();
    std::deque<unsigned int>::iterator itE = deq.end();
    for (;itB != itE; itB++)
    {
        std::cout << *itB << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printVec(void)
{
    std::vector<unsigned int>::iterator itB = vec.begin();
    std::vector<unsigned int>::iterator itE = vec.end();
    for (;itB != itE; itB++)
    {
        std::cout << *itB << " ";
    }
    std::cout << std::endl;
}

const char * PmergeMe::invalidInputException::what() const throw()
{
    return ("Error: invalid arguments");
}
