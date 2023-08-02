#ifndef WHATEVER_H
# define WHATEVER_H

#include <string>
#include <iostream>

template <typename T>
T &max(T &x, T &y)
{
    return (y >= x ? y : x);
}

template <typename T>
T &min(T &x, T &y)
{
    return (y <= x ? y : x);
}

template <typename T>
void swap(T &a, T &b)
{
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

#endif