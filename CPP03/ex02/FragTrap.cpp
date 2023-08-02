#include "FragTrap.hpp"

const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string cyan("\033[1;36m");
const std::string reset("\033[0m");

FragTrap::FragTrap() : ClapTrap() 
{
    std::cout << green << "Default constructor of FragTrap called" << reset << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
    std::cout << green << "Parametric constructor of FragTrap " << this->_name << " called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy)
{
    std::cout << green << "Copy constructor of FragTrap called" << reset << std::endl;
    *this = copy;
}

FragTrap::~FragTrap()
{
    std::cout << red << "Destructor of FragTrap " << this->_name << " called" << reset << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << cyan << "FragTrap " << this->_name << " does a high five to the other !" << reset << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
    if (this == &rhs)
        return (*this);
    ClapTrap::operator=(rhs);
    return (*this);
}