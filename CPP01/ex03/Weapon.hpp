#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>
#include <string>

class Weapon
{
    public:
        Weapon(std::string type);
        ~Weapon(void);
        std::string const &getType(void)const;
        void    setType(std::string type);
    
    private:
        std::string _type;
};

#endif