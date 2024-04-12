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
        void solveCalculation(char operand);
        bool is_operand(char c);

        class invalidOperation : public std::exception
        {
            const char *what() const throw();
        };
        class invalidArgument : public std::exception
        {
          const char* what() const throw();
        };
};
