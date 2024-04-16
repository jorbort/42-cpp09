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

void PmergeMe::sort(int argc)
{
    std::cout << "Before: ";
    printDeq();
    std::clock_t beginVec = std::clock();
    sortVec(0, vec.size() -1);
    std::clock_t endVec = std::clock();

    std::clock_t beginDeq = std::clock();
    sortDeq(0, deq.size() -1);
    std::clock_t endDeq = std::clock();

    std::cout << "After: ";
    printDeq();
    std::cout << "time to process a range of " << (argc - 1) << " with std::vector : ";
    std::cout << (static_cast<double>(endVec - beginVec) / CLOCKS_PER_SEC) * 1000 << " ms" << std::endl;
    std::cout << "time to process a range of " << (argc - 1) << " with std::deque : ";
    std::cout << (static_cast<double>(endDeq - beginDeq) / CLOCKS_PER_SEC) * 1000 << " ms" << std::endl;
}

void PmergeMe::sortDeq(unsigned int start, unsigned int end)
{
    unsigned int i = 2;
    if (end -start + 1 <= i)
        insertDeq(start, end);
    else if(end - start > 1)
    {
        sortDeq(start, start + ((end - start) / 2));
        sortDeq(start + ((end - start) / 2 ) + 1, end );
        mergeDeq(start,end);
    }
}

void PmergeMe::insertDeq(unsigned int start, unsigned int end)
{
    unsigned int tmp;
    for (unsigned int i = start + 1; i <= end ; i++)
    {
        for (unsigned int j = i ; j > start; j--)
        {
            if (deq[j -1] > deq[j])
            {
                tmp = deq[j];
                deq[j] = deq[j - 1];
                deq[j - 1] = tmp;
            }
            else
            {
                break;
            }
        }
    }
}

void PmergeMe::mergeDeq(unsigned int start, unsigned int end)
{
    std::deque<unsigned int> tmp;
    unsigned int split = start + ((end - start) / 2) + 1;
    unsigned int small = start , big = split , i = 0;

    while (small < split && big <= end)
    {
        if (deq[small] < deq[big])
        {
            tmp.push_back(deq[small++]);
        }
        else
        {
            tmp.push_back(deq[big++]);
        }
    }
    while (small < split)
    {
        tmp.push_back(deq[small++]);
    }
    while (big <= end)
    {
        tmp.push_back(deq[big++]);
    }
    while (i < end - start + 1)
    {
        deq[start + i] = tmp[i];
        i++;
    }
}

void PmergeMe::sortVec(unsigned int start, unsigned int end)
{
    unsigned int i = 2;
    if (end -start + 1 <= i)
        insertVec(start, end);
    else if(end - start > 1)
    {
        sortVec(start, start + ((end - start) / 2));
        sortVec(start + ((end - start) / 2 ) + 1, end );
        mergeVec(start,end);
    }
}

void PmergeMe::insertVec(unsigned int start, unsigned int end)
{
    unsigned int tmp;
    for (unsigned int i = start + 1; i <= end ; i++)
    {
        for (unsigned int j = i ; j > start; j--)
        {
            if (vec[j -1] > vec[j])
            {
                tmp = vec[j];
                vec[j] = vec[j - 1];
                vec[j - 1] = tmp;
            }
            else
            {
                break;
            }
        }
    }

}

void PmergeMe::mergeVec(unsigned int start, unsigned int end)
{
    std::vector<unsigned int> tmp;
    unsigned int split = start + ((end - start) / 2) + 1;
    unsigned int small = start , big = split , i = 0;

    while (small < split && big <= end)
    {
        if (vec[small] < vec[big])
        {
            tmp.push_back(vec[small++]);
        }
        else
        {
            tmp.push_back(vec[big++]);
        }
    }
    while (small < split)
    {
        tmp.push_back(vec[small++]);
    }
    while (big <= end)
    {
        tmp.push_back(vec[big++]);
    }
    while (i < end - start + 1)
    {
        vec[start + i] = tmp[i];
        i++;
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
