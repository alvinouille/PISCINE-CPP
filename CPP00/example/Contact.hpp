#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact 
{
    public:
        Contact(int a);
        ~Contact(void);

        void    bar(void)const;
        // int     getFoo(void)const;
        // bool    setFoo(int nb);
        // int     compare(Contact *other)const;

        int     publicFoo;
        static int getNbInst(void);

    private:
        static int       _nbInst;
        // int     _privateFoo;
        // void    _privateBar(void) const;
 
};

#endif