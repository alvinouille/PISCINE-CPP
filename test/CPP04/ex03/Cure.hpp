#ifndef CURE_H
# define CURE_H

#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(Cure const &copy);
        Cure &operator=(Cure const &rhs);
        ~Cure();
        
        Cure *clone()const override;
        void use(ICharacter &target)override;
};

#endif