#include "Dog.hpp"

Dog::Dog() : Animal(), _type("Dog")
{
    std::cout << "Default constructor of Dog" << std::endl;
}

Dog::Dog(Dog const &copy) : Animal(copy)
{
    std::cout << "Copy constructor of Dog" << std::endl;
    *this = copy;
}

Dog::~Dog() 
{
    std::cout << "Destructor of Dog" << std::endl;
}

Dog &Dog::operator=(Dog const &rhs)
{
    if (this == &rhs)
        return (*this);
    Animal::operator=(rhs);
    this->_type = rhs._type;
    return (*this);
}

void Dog::makeSound()const
{
    std::cout << "WOUF !" << std::endl;
}

std::string Dog::getType()const
{
    return (this->_type);
}