#include "Ice.hpp"

const std::string cyan("\033[1;36m");
const std::string reset("\033[0m");
const std::string red("\033[0;31m");

Ice::Ice() : AMateria("ice")
{
    std::cout << cyan << "Default constructor of Ice" << reset << std::endl;
}

Ice::Ice(Ice const &copy) : AMateria(copy)
{
    std::cout << cyan << "Copy constructor of Ice" << reset << std::endl;
    *this = copy;
}

Ice::~Ice() 
{
    std::cout << red << "Destructor of Ice" << reset << std::endl;
}

Ice &Ice::operator=(Ice const &rhs)
{
    std::cout << cyan << "Assignement operator of Ice" << reset << std::endl;
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
