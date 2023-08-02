#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain *_brain;
    protected:
        std::string _type;
    public:
        Cat();
        Cat(Cat const &copy);
        ~Cat();
        Cat &operator=(Cat const &rhs);

        void makeSound()const;
        std::string getType()const;
        Brain *getBrain()const;

};

#endif