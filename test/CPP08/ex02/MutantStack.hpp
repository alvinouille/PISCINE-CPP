#ifndef MutantStack_H
# define MutantStack_H

#include <string>
#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() {}
        MutantStack(MutantStack const &copy) 
        { *this = copy; }
        MutantStack &operator=(MutantStack const &rhs);
        { return (*this); }
        ~MutantStack() {}
        
        typedef typename std::deque<T>::iterator iterator;
        iterator begin()
        {

        }
        iterator end()
        {
            
        }

};

#endif