#ifndef ITER_H
# define ITER_H

#include <string>
#include <iostream>

template <typename T, typename U>
void iter(T tab[], U size, void(*f)(T const &x))
{
    for (U i = 0 ; i < size ; i++)
        f(tab[i]);
}

template <typename T>
void incrementation(T const &x)
{
    std::cout << x << std::endl;
}


#endif