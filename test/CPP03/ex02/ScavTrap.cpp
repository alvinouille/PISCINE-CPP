#include "ScavTrap.hpp"

const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string cyan("\033[1;36m");
const std::string reset("\033[0m");

ScavTrap::ScavTrap() : ClapTrap() 
{
    std::cout << green << "Default constructor of ScavTrap called" << reset << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
    std::cout << green << "Parametric constructor of ScavTrap " << this->_name << " called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy)
{
    std::cout << green << "Copy constructor of ScavTrap called" << reset << std::endl;
    *this = copy;
}

ScavTrap::~ScavTrap()
{
    std::cout << red << "Destructor of ScavTrap " << this->_name << " called" << reset << std::endl;
}

void ScavTrap::attack(std::string const &target)
{
    if (this->isDead())
        return ;
    this->_energyPoints--;
    std::cout << cyan << "ScavTrap " << this->_name << " attacks " << target;
    std::cout << ", causing " << this->_attackDamage << " points of damage!" << reset << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << cyan << "ScavTrap " << this->_name << " entered in the GATE KEEPER mode..." << reset << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
    if (this == &rhs)
        return (*this);
    ClapTrap::operator=(rhs);
    return (*this);
}