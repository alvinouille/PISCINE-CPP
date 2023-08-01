#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"

class Cat : public Animal
{
    protected:
        std::string _type;
    public:
        Cat();
        Cat(Cat const &copy);
        ~Cat();
        Cat &operator=(Cat const &rhs);
        void makeSound()const;
        std::string getType()const;
};

#endif