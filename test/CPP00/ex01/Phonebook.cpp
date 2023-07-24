#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
    return ;
}

Phonebook::~Phonebook(void)
{
    return ;
}

int Phonebook::get_nbContact(void)
{
    return (Phonebook::_nbContact);
}

int Phonebook::_nbContact = 0;

Contact Phonebook::get_contact(int i)const
{
    return (this->_tab[i]);
}

void    Phonebook::add_contact(Contact nw)
{
    this->_tab[nw.get_index()] = nw;
    if (Phonebook::_nbContact != 8)
        Phonebook::_nbContact++;
}
