#include "Contact.hpp"

int main()
{
    std::cout << "Instance = " << Contact::getNbInst() << std::endl;
    Contact first(21);
    Contact second(42);
    std::cout << "Instance = " << Contact::getNbInst() << std::endl;
    // Contact *second(&first);

    // int Contact::*p = NULL;
    // p = &Contact::publicFoo;

    // first.*p = 1;
    // std::cout << "foo first = " << first.publicFoo << std::endl;
    // second->*p = -1;
    // std::cout << "foo second = " << second->publicFoo << std::endl;

    // void (Contact::*f)(void)const;
    // f = &Contact::bar;

    // (first.*f)();
    // (second->*f)();
    // Contact other(56);
    // std::cout << "foo = " << first.getFoo() << std::endl;
    // first.setFoo(42);
    // std::cout << "foo = " << first.getFoo() << std::endl;
    // first.setFoo(-1);
    // std::cout << "foo = " << first.getFoo() << std::endl;
    // std::cout << "comparison = " << first.compare(&other) << std::endl;
    // std::cout << "comparison = " << first.compare(&first) << std::endl;

}