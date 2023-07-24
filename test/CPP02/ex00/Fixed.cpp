#include "Fixed.hpp"

int const Fixed::_fracPart = 8;

Fixed::Fixed(void) : _fixedPt(0)
{
    std::cout << "Default constructor called" << std::endl;
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
    this->_fixedPt = rhs.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void)const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedPt);
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPt = raw;
}
