#ifndef ANIMAL_H
# define ANIMAL_H

#include <string>
#include <iostream>

class Animal
{
    protected:
        std::string _type;
    public:
        Animal();
        Animal(Animal const &copy);
        virtual ~Animal();
        Animal &operator=(Animal const &rhs);
        virtual void makeSound()const;
        virtual std::string getType()const;
};

#endif