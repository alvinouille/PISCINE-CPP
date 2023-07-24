#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const &copy);
        ~ScavTrap();
        ScavTrap &operator=(ScavTrap const &rhs);
        void attack(std::string const &target);
        void guardGate();
};

#endif