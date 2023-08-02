#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int Base::i = 0;

Base::Base() 
{
    if (!Base::i)
        srand(static_cast<unsigned int>(time(0)));
    Base::i++;
}

Base::~Base() {}

Base::Base(Base const &copy)
{
    *this = copy;
}

Base &Base::operator=(Base const &rhs)
{
    (void)rhs;
    return (*this);
}

Base *Base::generate()
{
    int value;
    int res;
    value = rand() % 10;
    while (value == 9)
        value = rand() % 10;
    res = value / 3;
    if (res == 0)
    {
        std::cout << "A !" << std::endl;
        return (new A());
    }
    if (res == 1)
    {
        std::cout << "B !" << std::endl;
        return (new B());
    }
    if (res == 2)
    {
        std::cout << "C !" << std::endl;
        return (new C());
    }
    return (NULL);
}

void Base::identify(Base *p)
{
    A *a = dynamic_cast<A*>(p);
    if (a)
        std::cout << "The base object is a type A (by ptr)" << std::endl;
    B *b = dynamic_cast<B*>(p);
    if (b)
        std::cout << "The base object is a type B (by ptr)" << std::endl;
    C *c = dynamic_cast<C*>(p);
    if (c)
        std::cout << "The base object is a type C (by ptr)" << std::endl;
}

void Base::identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "The base object is a type A (by ref)" << std::endl;
    }
    catch (std::exception &bc)
    {}
    try
    {
        B &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "The base object is a type B (by ref)" << std::endl;
    }
    catch (std::exception &bc)
    {}
    try
    {
        C &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "The base object is a type C (by ref)" << std::endl;
    }
    catch (std::exception &bc)
    {}
}