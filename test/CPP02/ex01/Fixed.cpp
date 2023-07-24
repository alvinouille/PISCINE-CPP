#include "Fixed.hpp"

int const Fixed::_fracPart = 8;

Fixed::Fixed(void) : _fixedPt(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const n)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPt = n << Fixed::_fracPart;
}

Fixed::Fixed(float const f)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPt = roundf(f * (1 << Fixed::_fracPart));
}

Fixed::Fixed(Fixed const &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_fixedPt = rhs.getRawBits();
    return (*this);
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

std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
    o << i.toFloat();
    return (o);
}
