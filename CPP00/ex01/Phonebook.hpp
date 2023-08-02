#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class Phonebook
{
    public:
        Phonebook(void);
        ~Phonebook(void);
        Contact get_contact(int i)const;
        void    add_contact(Contact nw);
        static int  get_nbContact(void);

    private:
        Contact _tab[8];
        static int _nbContact;
};

#endif