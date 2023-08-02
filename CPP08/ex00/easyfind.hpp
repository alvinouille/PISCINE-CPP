#ifndef EASYFIND_H
# define EASYFIND_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>

template <typename T>
int easyfind(T const &numbers, int tofind)
{
    typename T::const_iterator res;
    res = std::find(numbers.begin(), numbers.end(), tofind);
    if (res != numbers.end())
        return (std::distance(numbers.begin(), res));
    else
        throw std::exception();
}

#endif