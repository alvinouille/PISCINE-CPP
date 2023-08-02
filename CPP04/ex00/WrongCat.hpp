#ifndef WRONGCAT_H
# define WRONGCAT_H

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    protected:
        std::string _type;
    public:
        WrongCat();
        WrongCat(WrongCat const &copy);
        ~WrongCat();
        WrongCat &operator=(WrongCat const &rhs);
        void makeSound()const;
        std::string getType()const;
};

#endif