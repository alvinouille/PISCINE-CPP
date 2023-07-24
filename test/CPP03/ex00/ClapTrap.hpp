#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>
#include <string>
#include <sstream>

class ClapTrap
{
    private:
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;
        bool isDead()const;
    
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const &copy);
        ~ClapTrap();
        ClapTrap &operator=(ClapTrap const &rhs);

        std::string getName()const;
        unsigned int getHitPoints()const;
        unsigned int getEnergyPoints()const;
        unsigned int getAttackDamage()const;

        void attack(std::string const &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

std::ostream &operator<<(std::ostream &o, ClapTrap const &c);

#endif