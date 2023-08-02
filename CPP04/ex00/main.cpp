#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    Animal const *meta = new Animal();
    Animal const *j = new Dog();
    Animal const *i = new Cat();

    std::cout << meta->getType() << " : ";
    meta->makeSound();
    std::cout << j->getType() << " : ";
    j->makeSound();
    std::cout << i->getType() << " : ";
    i->makeSound();

    WrongAnimal const *meta2 = new WrongAnimal();
    WrongAnimal const *i2 = new WrongCat();
    WrongCat const *j2 = new WrongCat();

    std::cout << meta2->getType() << " : ";
    meta2->makeSound();
    std::cout << i2->getType() << " : ";
    i2->makeSound();
    std::cout << j2->getType() << " : ";
    j2->makeSound();

    delete meta;
    delete j;
    delete i;
    delete meta2;
    delete i2;
    delete j2;
}