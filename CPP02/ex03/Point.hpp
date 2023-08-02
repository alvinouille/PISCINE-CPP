#ifndef POINT_H
# define POINT_H

#include <cmath>
#include <string>
#include <iostream>
#include "Fixed.hpp"

class Point
{
    private:
        Fixed const _x;
        Fixed const _y;

    public:
        Point(void);
        Point(float const x, float const y);
        Point(Point const &src);
        ~Point(void);
        Fixed getX(void)const;
        Fixed getY(void)const;
        Point &operator=(Point const &rhs);
};

std::ostream &operator<<(std::ostream &o, Point const &i);

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif