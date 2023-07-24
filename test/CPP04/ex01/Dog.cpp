#include "Dog.hpp"

Dog::Dog() : Animal(), _type("Dog")
{
    this->_brain = new Brain();
    std::cout << "Default constructor of Dog" << std::endl;
}

Dog::Dog(Dog const &copy) : Animal(copy)
{
    std::cout << "Copy constructor of Dog" << std::endl;
    this->_brain = new Brain();
    *this = copy;
}

Dog::~Dog() 
{
    delete this->_brain;
    std::cout << "Destructor of Dog" << std::endl;
}

Dog &Dog::operator=(Dog const &rhs)
{
    if (this == &rhs)
        return (*this);
    delete this->_brain;
    this->_brain = new Brain(*rhs._brain);
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

Brain *Dog::getBrain(void)const
{
    return (this->_brain);
}