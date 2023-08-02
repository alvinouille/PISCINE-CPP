#ifndef BASE_H
# define BASE_H

#include <string>
#include <iostream>
#include <cstdlib>

class Base
{
    public:
        Base();
        Base(Base const&copy);
        Base &operator=(Base const &rhs);
        virtual ~Base();

        Base *generate();
        void identify(Base *p);
        void identify(Base &p);
    
    private:
        static int i;
};

#endif