#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain *_brain;
    protected:
        std::string _type;
    public:
        Dog();
        Dog(Dog const &copy);
        ~Dog();
        Dog &operator=(Dog const &rhs);

        void makeSound()const;
        std::string getType()const;
        Brain *getBrain(void)const;
};

#endif