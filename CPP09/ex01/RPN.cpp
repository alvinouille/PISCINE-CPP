#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(RPN const &copy) { (void) copy;}

RPN &RPN::operator=(RPN const &rhs)
{
    if (this == &rhs)
        return (*this);
    return (*this);
}

int doOp(int a, int b, char op)
{
    switch (op)
    {
        case '-':
            return (a - b);
        case '+':
            return (a + b);
        case '/':
        {
            if (b == 0)
                throw (std::exception());
            else
                return (a / b);
        }
        case '*':
            return (a * b);
        default:
            return (0);
    }
}

bool isOpe(char c)
{
    if (c != '+' && c != '-' && c != '/' && c != '*')
        return (0);
    return (1);
}
void RPN::operation(std::string str)
{
    std::istringstream iss(str);
    int value1, value2;
    std::string token;

    while (iss >> token)
    {
        if (token.size() != 1 || (!isdigit(token[0]) && !isOpe(token[0])))
            return void(std::cout << "Error: bad input" << std::endl);
        if (isdigit(token[0]))
            pile.push(std::atoi(token.c_str()));
        else
        {
            if (pile.size() < 2)
                return void(std::cout << "Error: bad input" << std::endl);
            value2 = pile.top();
            pile.pop();
            value1 = pile.top();
            pile.pop();
            try
            {
                pile.push(doOp(value1, value2, token[0]));
            }
            catch(std::exception &e)
            {
               return void(std::cout << "Error: division by 0 impossible" << std::endl);
            }
        }
    }
    if (pile.size() != 1)
        return void(std::cout << "Error: bad input" << std::endl);
    std::cout << pile.top() << std::endl;
}