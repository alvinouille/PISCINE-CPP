#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(FragTrap const &copy);
        ~FragTrap();
        void highFivesGuys();
        FragTrap &operator=(FragTrap const &rhs);
};

#endif