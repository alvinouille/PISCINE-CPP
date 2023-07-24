#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Default constructor of Ice" << std::endl;
}

Ice::Ice(Ice const &copy) : AMateria(copy)
{
    std::cout << "Copy constructor of Ice" << std::endl;
    *this = copy;
}

Ice::~Ice() 
{
    std::cout << "Destructor of Ice" << std::endl;
}

Ice &Ice::operator=(Ice const &rhs)
{
    std::cout << "Assignement operator of Ice" << std::endl;
    if (this == &rhs)
        return (*this);
    AMateria::operator=(rhs);
    return (*this);
}

Ice *Ice::clone()const
{
    return (new Ice());
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
