#ifndef AMATERIA_H
# define AMATERIA_H

#include "ICharacter.hpp"
#include <sstream>

class ICharacter ;

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria();
        AMateria(std::string const &type);
        AMateria(AMateria const &copy);
        AMateria &operator=(AMateria const &rhs);
        virtual ~AMateria();

        std::string const &getType()const;
        
        virtual AMateria *clone()const = 0;
        virtual void use(ICharacter &target);
};

#endif