#include <deque>
#include <exception>
#include <vector>
#include <iostream>

#define MAX_INT 2147483647

class PmergeMe
{
    protected:
        std::vector<unsigned int> vec;
        std::deque<unsigned int> deq;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(PmergeMe &src);
        PmergeMe& operator=(PmergeMe &rhs);

        void sort(int argc);
        bool checkInput(std::string input);
        void addVec(std::string input);
        void addDeq(std::string input);

        void sortVec(unsigned int start, unsigned int end);
        void insertVec(unsigned int start, unsigned int end);
        void mergeVec(unsigned int start, unsigned int end);

        void sortDeq(unsigned int start, unsigned int end);
        void insertDeq(unsigned int start, unsigned int end);
        void mergeDeq(unsigned int start, unsigned int end);


        void printDeq(void);
        void printVec(void);


    class invalidInputException : public std::exception
    {
        const char *what() const throw();
    };
};
