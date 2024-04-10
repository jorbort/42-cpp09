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
        void solveCalculation(void);
};
