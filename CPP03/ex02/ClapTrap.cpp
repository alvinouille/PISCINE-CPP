#include "ClapTrap.hpp"

const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string cyan("\033[1;36m");
const std::string reset("\033[0m");

ClapTrap::ClapTrap()
{
    std::cout << green << "Default constructor of ClapTrap called" << reset << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
    std::cout << green << "Parametric constructor of ClapTrap " << this->_name << " called" << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hP, unsigned int eP, unsigned int aD) : _name(name), _hitPoints(hP), _energyPoints(eP), _attackDamage(aD)
{
    std::cout << green << "Parametric constructor of ClapTrap " << this->_name << " called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
    std::cout << green << "Copy constructor of ClapTrap called" << reset << std::endl;
    *this = copy;
}

ClapTrap::~ClapTrap()
{
    std::cout << red << "Destructor of ClapTrap " << this->_name << " called" << reset << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
    this->_name = rhs.getName();
    this->_hitPoints = rhs.getHitPoints();
    this->_energyPoints = rhs.getEnergyPoints();
    this->_attackDamage = rhs.getAttackDamage();
    return (*this);
}

std::string ClapTrap::getName()const
{
    return (this->_name);
}

unsigned int ClapTrap::getHitPoints()const
{
    return (this->_hitPoints);
}

unsigned int ClapTrap::getEnergyPoints()const
{
    return (this->_energyPoints);
}

unsigned int ClapTrap::getAttackDamage()const
{
    return (this->_attackDamage);
}

bool ClapTrap::isDead()const
{
    if (!this->_energyPoints || !this->_hitPoints)
    {
        std::cout << cyan << "ClapTrap " << this->_name << " is dead ! :(" << reset << std::endl;
        return (true);
    }
    return (false);
}

void ClapTrap::attack(std::string const &target)
{
    if (this->isDead())
        return ;
    this->_energyPoints--;
    std::cout << cyan << "ClapTrap " << this->_name << " attacks " << target;
    std::cout << ", causing " << this->_attackDamage << " points of damage!" << reset << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->isDead())
        return ;
    this->_hitPoints -= amount;
    std::cout << cyan << "ClapTrap " << this->_name << " has " << this->_hitPoints << " hit points left" << reset << std::endl; 
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->isDead())
        return ;
    this->_energyPoints--;
    this->_hitPoints += amount;
    std::cout << cyan << "ClapTrap " << this->_name << " repaired himself of ";
    std::cout << amount << " points, he now has " << this->_hitPoints << " hit points" << reset << std::endl; 
}