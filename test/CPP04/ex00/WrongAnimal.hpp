#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

#include <string>
#include <iostream>

class WrongAnimal
{
    protected:
        std::string _type;
    public:
        WrongAnimal();
        WrongAnimal(WrongAnimal const &copy);
        virtual ~WrongAnimal();
        WrongAnimal &operator=(WrongAnimal const &rhs);
        void makeSound()const;
        std::string getType()const;
};

#endif