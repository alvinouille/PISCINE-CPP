#ifndef ICE_H
# define ICE_H

#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(Ice const &copy);
        Ice &operator=(Ice const &rhs);
        ~Ice();
        
        Ice *clone()const;
        void use(ICharacter &target);
};

#endif