#ifndef ANIMAL_H
# define ANIMAL_H

#include <string>
#include <iostream>

class Aanimal
{
    protected:
        std::string _type;
    public:
        Aanimal();
        Aanimal(Aanimal const &copy);
        virtual ~Aanimal();
        Aanimal &operator=(Aanimal const &rhs);
        virtual void makeSound()const = 0;
        virtual std::string getType()const;
};

#endif