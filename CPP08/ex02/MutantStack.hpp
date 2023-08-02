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
        MutantStack &operator=(MutantStack const &rhs)
        { return (*this); }
        ~MutantStack() {}

        typedef typename std::deque<T>::iterator iterator;
        typedef typename std::deque<T>::reverse_iterator reverse_iterator;
        iterator begin() {return (std::stack<T>::c.begin());}
        iterator end() {return (std::stack<T>::c.end());}
        reverse_iterator rbegin() {return (std::stack<T>::c.rbegin());}
        reverse_iterator rend() {return (std::stack<T>::c.rend());}
};

#endif