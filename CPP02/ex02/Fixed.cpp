#include "Fixed.hpp"

int const Fixed::_fracPart = 8;

Fixed::Fixed(void) : _fixedPt(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const n)
{
    // std::cout << "Int constructor called" << std::endl;
    this->_fixedPt = n << Fixed::_fracPart;
}

Fixed::Fixed(float const f)
{
    // std::cout << "Float constructor called" << std::endl;
    this->_fixedPt = roundf(f * (1 << Fixed::_fracPart));
}

Fixed::Fixed(Fixed const &src)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed(void)
{
    // std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void)const
{
    // std::cout << "getfixePt member function called" << std::endl;
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
    // std::cout << "Copy assignment operator called" << std::endl;
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
