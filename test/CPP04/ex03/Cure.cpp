#include "Cure.hpp"

Cure::Cure() : AMateria("Cure")
{
    std::cout << "Default constructor of Cure" << std::endl;
}

Cure::Cure(Cure const &copy) : AMateria(copy)
{
    std::cout << "Copy constructor of Cure" << std::endl;
    *this = copy;
}

Cure::~Cure() 
{
    std::cout << "Destructor of Cure" << std::endl;
}

Cure &Cure::operator=(Cure const &rhs)
{
    std::cout << "Assignement operator of Cure" << std::endl;
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
