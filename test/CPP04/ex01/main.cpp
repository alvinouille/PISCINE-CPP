#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    std::cout << std::endl << "- - - BASIC TESTS WITH CAT - - -" << std::endl << std::endl;
    
    Cat *cat = new Cat();
    cat->getBrain()->setIdea("Those stupid humans...", 0);
    cat->getBrain()->setIdea("I want to kill them all", 1);

    std::cout << cat->getType() << " : ";
    cat->makeSound();
    std::cout << cat->getType() << " is thinking : ";
    for (int i = 0 ; i < 2 ; i++)
        std::cout << cat->getBrain()->getIdea(i) << std::endl;

    std::cout << std::endl << std::endl << "- - - DEEP COPY TESTS WITH CAT AND CATCOPY - - -" << std::endl << std::endl;
    
    Cat *catCopy = new Cat(*cat); // it's the same
    // Cat *catCopy = new Cat();
    // *catCopy = *cat;

    std::cout << std::endl << "New copy of cat, catCopy, look how they are the same :" << std::endl;

    std::cout << std::endl << "CAT : " << std::endl;
    std::cout << cat->getType() << " : ";
    cat->makeSound();
    for (int i = 0 ; i < 2 ; i++)
        std::cout << cat->getBrain()->getIdea(i) << std::endl;

    std::cout << std::endl << "CATCOPY : " << std::endl;
    std::cout << catCopy->getType() << " : ";
    catCopy->makeSound();
    for (int i = 0 ; i < 2 ; i++)
        std::cout << catCopy->getBrain()->getIdea(i) << std::endl;

    std::cout << std::endl << "Now we only change catCopy into a loving cat, a deep copy is independant and its ideas (attributs) can be changed without changing the cat source" << std::endl;

    catCopy->getBrain()->setIdea("I love them so much omg", 1);

    std::cout << std::endl << "CAT : " << std::endl;
    std::cout << cat->getType() << " : ";
    cat->makeSound();
    for (int i = 0 ; i < 2 ; i++)
        std::cout << cat->getBrain()->getIdea(i) << std::endl;
    
    std::cout << std::endl << "CATCOPY : " << std::endl;
    std::cout << catCopy->getType() << " : ";
    catCopy->makeSound();
    for (int i = 0 ; i < 2 ; i++)
        std::cout << catCopy->getBrain()->getIdea(i) << std::endl;
    std::cout << std::endl;

    delete cat;
    delete catCopy;

    std::cout << std::endl << "CREATION OF ARRAY OF DOGS AND CAT : " << std::endl << std::endl;

    Animal *noahArch[10];
    for (int i = 0 ; i < 5 ; i++)
    {
        std::cout << i << std::endl;
        noahArch[i] = new Dog();
    }
    for (int i = 5 ; i < 10 ; i++)
    {
        std::cout << i << std::endl;
        noahArch[i] = new Cat();
    }

    std::cout << std::endl << "SUPPRESSION OF THE ARRAY : " << std::endl << std::endl;

    for (int i = 0 ; i < 10 ; i++)
    {
        std::cout << i << std::endl;
        delete noahArch[i];
    }
}