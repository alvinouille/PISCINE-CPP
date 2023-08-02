#include "AMateria.hpp"

const std::string cyan("\033[1;36m");
const std::string red("\033[0;31m");
const std::string reset("\033[0m");

AMateria::AMateria()
{
    std::cout << cyan << "Default constructor of AMateria" << reset << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type)
{
    std::cout << cyan << "Parametric constructor of AMateria of type " <<  type << reset << std::endl;
}

AMateria::AMateria(AMateria const &copy)
{
    std::cout << cyan << "Copy constructor of AMateria" << reset << std::endl;
    *this = copy;
}

AMateria::~AMateria() 
{
    std::cout << red << "Destructor of AMateria of type " << this->type << reset << std::endl;
}

AMateria &AMateria::operator=(AMateria const &rhs)
{
    std::cout << cyan << "Assignement operator of AMateria" << reset << std::endl;
    if (this == &rhs)
        return (*this);
    this->type = rhs.type;
    return (*this);
}

std::string const &AMateria::getType()const
{
    return (this->type);
}

void AMateria::use(ICharacter &target) 
{
    (void)target;
}