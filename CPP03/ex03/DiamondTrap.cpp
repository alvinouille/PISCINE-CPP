#include "DiamondTrap.hpp"

const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string cyan("\033[1;36m");
const std::string reset("\033[0m");

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap() , FragTrap()
{
    std::cout << green << "Default constructor of DiamondTrap called" << reset << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name", 100, 50, 30), ScavTrap(name), FragTrap(name)
{
    this->_name = name;
    std::cout << green << "Parametric constructor of DiamondTrap " << this->_name << " called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
    std::cout << green << "Copy constructor of DiamondTrap called" << reset << std::endl;
    *this = copy;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << red << "Destructor of DiamondTrap " << this->_name << " called" << reset << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs)
{
    if (this == &rhs)
        return (*this);
    this->_name = rhs.getName();
    ClapTrap::operator=(rhs);
    return (*this);
}

void DiamondTrap::attack(std::string const &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << cyan << "DiamondTrap reclaims himself as " << this->_name << " of " << ClapTrap::_name << " the well-borned" << reset << std::endl;
}

std::string DiamondTrap::getName(void)const
{
    return (this->_name);
}