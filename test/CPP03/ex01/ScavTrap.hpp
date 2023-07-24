#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const &copy);
        ~ScavTrap();
        void attack(std::string const &target);
        void guardGate();
        ScavTrap &operator=(ScavTrap const &rhs);
};

#endif