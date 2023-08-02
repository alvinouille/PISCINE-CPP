#include "Animal.hpp"

Aanimal::Aanimal() : _type("animal") 
{
    std::cout << "Default constructor of animal" << std::endl;
}

Aanimal::Aanimal(Aanimal const &copy)
{
    std::cout << "Copy constructor of animal" << std::endl;
    *this = copy;
}

Aanimal::~Aanimal() 
{
    std::cout << "Destructor of animal" << std::endl;
}

Aanimal &Aanimal::operator=(Aanimal const &rhs)
{
    std::cout << "Assignement operator of animal" << std::endl;
    if (this == &rhs)
        return (*this);
    this->_type = rhs._type;
    return (*this);
}

std::string Aanimal::getType()const
{
    return (this->_type);
}