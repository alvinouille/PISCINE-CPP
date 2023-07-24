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
        
        Ice *clone()const override;
        void use(ICharacter &target)override;
}

#endif