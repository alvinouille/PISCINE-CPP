#include "Fixed.hpp"

int const Fixed::_fracPart = 8;

Fixed::Fixed(void) : _fixedPt(0)
{
}

Fixed::Fixed(int const n)
{
    this->_fixedPt = n << Fixed::_fracPart;
}

Fixed::Fixed(float const f)
{
    this->_fixedPt = roundf(f * (1 << Fixed::_fracPart));
    // std::cout << this->_fixedPt << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
    *this = src;
}

Fixed::~Fixed(void)
{
}

int Fixed::getRawBits(void)const
{
    return (this->_fixedPt);
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPt = raw;
}

float Fixed::toFloat(void)const
{
    return ((float)this->_fixedPt / (1 << Fixed::_fracPart));
}

int Fixed::toInt(void)const
{
    return (this->_fixedPt >> Fixed::_fracPart);
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
    if (this != &rhs)
        this->_fixedPt = rhs.getRawBits();
    return (*this);
}

bool Fixed::operator>(Fixed const &rhs)const
{
    return (this->getRawBits() > rhs.getRawBits());
}

bool Fixed::operator<(Fixed const &rhs)const
{
    return (this->getRawBits() < rhs.getRawBits());
}

bool Fixed::operator>=(Fixed const &rhs)const
{
    return (this->getRawBits() >= rhs.getRawBits());
}

bool Fixed::operator<=(Fixed const &rhs)const
{
    return (this->getRawBits() <= rhs.getRawBits());
}

bool Fixed::operator==(Fixed const &rhs)const
{
    return (this->getRawBits() == rhs.getRawBits());
}

bool Fixed::operator!=(Fixed const &rhs)const
{
    return (this->getRawBits() != rhs.getRawBits());
}

Fixed Fixed::operator+(Fixed const &rhs)const
{
    Fixed res(this->toFloat() + rhs.toFloat());

    return (res);
}

Fixed Fixed::operator-(Fixed const &rhs)const
{
    Fixed res(this->toFloat() - rhs.toFloat());

    return (res);
}

Fixed Fixed::operator*(Fixed const &rhs)const
{
    Fixed res(this->toFloat() * rhs.toFloat());

    return (res);
}

Fixed Fixed::operator/(Fixed const &rhs)const
{
    Fixed res(this->toFloat() / rhs.toFloat());

    return (res);
}

Fixed &Fixed::operator++(void)
{
    ++(this->_fixedPt);
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed old;

    old.setRawBits(this->_fixedPt);
    ++(this->_fixedPt);
    return (old);
}

Fixed &Fixed::operator--(void)
{
    --(this->_fixedPt);
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed old;

    old.setRawBits(this->_fixedPt);
    --(this->_fixedPt);
    return (old);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
    o << i.toFloat();
    return (o);
}
