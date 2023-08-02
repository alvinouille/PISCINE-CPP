#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>
#include <string>
#include <sstream>

class ClapTrap
{
    protected:
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;
    
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(std::string name, unsigned int hP, unsigned int eP, unsigned int aD);
        ClapTrap(ClapTrap const &copy);
        ~ClapTrap();
        ClapTrap &operator=(ClapTrap const &rhs);

        std::string getName()const;
        unsigned int getHitPoints()const;
        unsigned int getEnergyPoints()const;
        unsigned int getAttackDamage()const;
        bool isDead()const;

        void attack(std::string const &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif