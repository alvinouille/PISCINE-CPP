#include "AMateria.hpp"

AMateria::AMateria()
{
    std::cout << "Default constructor of materia" << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type)
{
    std::cout << "Parametric constructor of materia" << std::endl;
}

AMateria::AMateria(AMateria const &copy)
{
    std::cout << "Copy constructor of materia" << std::endl;
    *this = copy;
}

AMateria::~AMateria() 
{
    std::cout << "Destructor of materia" << std::endl;
}

AMateria &AMateria::operator=(AMateria const &rhs)
{
    std::cout << "Assignement operator of animal" << std::endl;
    if (this == &rhs)
        return (*this);
    this->type = rhs.type;
    return (*this);
}

std::string const &AMateria::getType()const
{
    return (this->type);
}

void AMateria::use(ICharacter &target) {}