#include "Cure.hpp"

const std::string cyan("\033[1;36m");
const std::string reset("\033[0m");
const std::string red("\033[0;31m");

Cure::Cure() : AMateria("cure")
{
    std::cout << cyan << "Default constructor of Cure" << reset << std::endl;
}

Cure::Cure(Cure const &copy) : AMateria(copy)
{
    std::cout << cyan << "Copy constructor of Cure" << reset << std::endl;
    *this = copy;
}

Cure::~Cure() 
{
    std::cout << red << "Destructor of Cure" << reset << std::endl;
}

Cure &Cure::operator=(Cure const &rhs)
{
    std::cout << cyan << "Assignement operator of Cure" << reset << std::endl;
    if (this == &rhs)
        return (*this);
    AMateria::operator=(rhs);
    return (*this);
}

Cure *Cure::clone()const
{
    return (new Cure());
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
