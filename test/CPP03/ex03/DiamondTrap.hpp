#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string _name;
    
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(DiamondTrap const &copy);
        ~DiamondTrap();
        DiamondTrap &operator=(DiamondTrap const &rhs);
        void attack(std::string const &target);
        void whoAmI();
        std::string getName(void)const;
};

#endif