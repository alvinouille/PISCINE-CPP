#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {}

Point::Point(float const x, float const y) : _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point(Point const &src) : _x(src.getX()), _y(src.getY()) {}

Point::~Point(void) {}

Fixed Point::getX(void)const
{
    return (this->_x);
}

Fixed Point::getY(void)const
{
    return (this->_y);
}

Point &Point::operator=(Point const &rhs)
{
    (void)rhs;
    return (*this);
}

std::ostream &operator<<(std::ostream &o, Point const &i)
{
    o << "x = " << i.getX() << " y = " << i.getY();
    return (o);
}