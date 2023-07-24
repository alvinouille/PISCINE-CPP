#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") 
{
    std::cout << "Default constructor of WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy)
{
    std::cout << "Copy constructor of WrongAnimal" << std::endl;
    *this = copy;
}

WrongAnimal::~WrongAnimal() 
{
    std::cout << "Destructor of WrongAnimal" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs)
{
    if (this == &rhs)
        return (*this);
    this->_type = rhs._type;
    return (*this);
}

void WrongAnimal::makeSound()const
{
    std::cout << "..." << std::endl;
}

std::string WrongAnimal::getType()const
{
    return (this->_type);
}