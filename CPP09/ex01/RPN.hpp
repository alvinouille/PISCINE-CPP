#ifndef RPN_H
# define RPN_H

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

class RPN
{
    public:
        RPN();
        RPN(RPN const &copy);
        ~RPN();
        RPN &operator=(RPN const &rhs);
        void operation(std::string str);
    
    private:
        std::stack<int> pile;
};

#endif