#include "PmergeMe.hpp"
#include <ctime>
#include <mutex>

int main(int argc, char **argv)
{
    int i = 1;
    PmergeMe FJ;
    if (argc <= 2)
    {
        std::cout << "Error : the program must receive list of positive numbers as argument" << std::endl;
        return (1);
    }
    while (i < argc)
    {
        try
        {
            FJ.addVec(argv[i]);
            FJ.addDeq(argv[i]);
        }
        catch(std::exception &e)
        {
            std::cerr << e.what() << std::endl;
            return (1);
        }
        i++;
    }
    try
    {
        std::clock_t beginVec = std::clock();
        FJ.sortVec();
        std::clock_t endVec = std::clock();

        std::clock_t beginDeq = std::clock();
        FJ.sortDeq();
        std::clock_t enddeq = std::clock();
    }
    // FJ.printDeq();
    //FJ.printVec();
}
