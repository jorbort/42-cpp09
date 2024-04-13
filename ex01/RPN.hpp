#include <exception>
#include <stack>

class RPN
{
    private:
        std::stack<int> operation;
    public:
        RPN();
        RPN(RPN &cpy);
        RPN &operator=(RPN const &rhs);
        ~RPN();

        void parseInput(std::string &input);
        void solveCalculation(int operand);
        bool is_operand(char c);
        void printResult(void);

        class invalidOperation : public std::exception
        {
          virtual  const char *what() const throw();
        };
        class invalidArgument : public std::exception
        {
         virtual const char* what() const throw();
        };
        class invalidDivition : public std::exception
        {
            virtual const char * what() const throw();
        };
};
