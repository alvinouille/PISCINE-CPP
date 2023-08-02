#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ScavTrap.hpp"

class FragTrap : public virtual ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(FragTrap const &copy);
        ~FragTrap();
        FragTrap &operator=(FragTrap const &rhs);
        void highFivesGuys();
};

#endif