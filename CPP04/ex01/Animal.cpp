#include "Animal.hpp"

Animal::Animal() : _type("Animal") 
{
    std::cout << "Default constructor of Animal" << std::endl;
}

Animal::Animal(Animal const &copy)
{
    std::cout << "Copy constructor of Animal" << std::endl;
    *this = copy;
}

Animal::~Animal() 
{
    std::cout << "Destructor of Animal" << std::endl;
}

Animal &Animal::operator=(Animal const &rhs)
{
    std::cout << "Assignement operator of Animal" << std::endl;
    if (this == &rhs)
        return (*this);
    this->_type = rhs._type;
    return (*this);
}

void Animal::makeSound()const
{
    std::cout << "..." << std::endl;
}

std::string Animal::getType()const
{
    return (this->_type);
}