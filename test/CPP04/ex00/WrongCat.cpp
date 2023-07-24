#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(), _type("WrongCat")
{
    std::cout << "Default constructor of WrongCat" << std::endl;
}

WrongCat::WrongCat(WrongCat const &copy) : WrongAnimal(copy)
{
    std::cout << "Copy constructor of WrongCat" << std::endl;
    *this = copy;
}

WrongCat::~WrongCat() 
{
    std::cout << "Destructor of WrongCat" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs)
{
    if (this == &rhs)
        return (*this);
    WrongAnimal::operator=(rhs);
    this->_type = rhs._type;
    return (*this);
}

void WrongCat::makeSound()const
{
    std::cout << "Miaou..." << std::endl;
}