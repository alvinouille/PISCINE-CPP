#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"

class Dog : public Animal
{
    protected:
        std::string _type;
    public:
        Dog();
        Dog(Dog const &copy);
        ~Dog();
        Dog &operator=(Dog const &rhs);
        virtual void makeSound()const;
        std::string getType()const;
};

#endif