#include <deque>
#include <exception>
#include <vector>
#include <iostream>

#define MAX_INT 2147483647

class PmergeMe
{
    private :
        std::vector<unsigned int> vec;
        std::deque<unsigned int> deq;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(PmergeMe &src);
        PmergeMe& operator=(PmergeMe &rhs);

        bool checkInput(std::string input);
        void addVec(std::string input);
        void addDeq(std::string input);
        void sortVec(void);
        void sortDeq(void);

        void printDeq(void);
        void printVec(void);


    class invalidInputException : public std::exception
    {
        const char *what() const throw();
    };
};
