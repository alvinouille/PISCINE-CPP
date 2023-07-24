#include "Contact.hpp"

int Contact::_nbInst = 0;

Contact::Contact(int nb) : publicFoo(nb)
{
    Contact::_nbInst++;

    return ;
}

Contact::~Contact(void)
{
    return ;
}

void    Contact::bar(void)const
{
    std::cout << "hello there" << std::endl;
}

int  Contact::getNbInst(void)
{
    return (Contact::_nbInst);
}


// int Contact::getFoo(void)const
// {
//     return (this->_privateFoo);
// }

// bool    Contact::setFoo(int nb)
// {
//     if (nb >= 0)
//     {
//         this->_privateFoo = nb;
//         return (true);
//     }
//     else
//         return (false);
// }

// int     Contact::compare(Contact *other)const
// {
//     if (this->_privateFoo > other->getFoo())
//         return (1);
//     else if (this->_privateFoo < other->getFoo())
//         return (-1);
//     return (0);
// }

// void    Contact::_privateBar(void) const
// {
//     std::cout << "private = " << this->_privateFoo << std::endl;
// }