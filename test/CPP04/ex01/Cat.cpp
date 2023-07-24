#include "Cat.hpp"

Cat::Cat() : Animal(), _type("Cat")
{
    this->_brain = new Brain();
    std::cout << "Default constructor of Cat" << std::endl;
}

Cat::Cat(Cat const &copy) : Animal(copy)
{
    std::cout << "Copy constructor of Cat" << std::endl;
    this->_brain = new Brain();
    *this = copy;
}

Cat::~Cat() 
{
    delete this->_brain;
    std::cout << "Destructor of Cat" << std::endl;
}

Cat &Cat::operator=(Cat const &rhs)
{
    std::cout << "Assignement operator of Cat" << std::endl;
    if (this == &rhs)
        return (*this);
    delete this->_brain;
    this->_brain = new Brain(*rhs._brain);
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

Brain *Cat::getBrain(void)const
{
    return (this->_brain);
}