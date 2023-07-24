#include "Cat.hpp"

Cat::Cat() : Animal(), _type("Cat")
{
    std::cout << "Default constructor of Cat" << std::endl;
}

Cat::Cat(Cat const &copy) : Animal(copy)
{
    std::cout << "Copy constructor of Cat" << std::endl;
    *this = copy;
}

Cat::~Cat() 
{
    std::cout << "Destructor of Cat" << std::endl;
}

Cat &Cat::operator=(Cat const &rhs)
{
    if (this == &rhs)
        return (*this);
    Animal::operator=(rhs);
    this->_type = rhs._type;
    return (*this);
}

void Cat::makeSound()const
{
    std::cout << "Miaou..." << std::endl;
}

std::string Cat::getType()const
{
    return (this->_type);
}