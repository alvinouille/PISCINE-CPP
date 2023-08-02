#include "Contact.hpp"

Contact::Contact(void) : _index(Contact::_nbInst)
{
    Contact::_nbInst++;
    if (Contact::_nbInst > 7)
        Contact::_nbInst = 0;
    return ;
}

Contact::~Contact(void)
{
    return ;
}

std::string Contact::get_firstName(void)const
{
    return (this->_firstName);
}

std::string Contact::get_nickname(void)const
{
    return (this->_nickname);
}

std::string Contact::get_phoneNumber(void)const
{
    return (this->_phoneNumber);
}

std::string Contact::get_darkestSecret(void)const
{
    return (this->_darkestSecret);
}

bool Contact::set_firstName(std::string str)
{
    if (str == "")
        return (false);
    this->_firstName = str;
    return (true);
}
        
bool Contact::set_nickname(std::string str)
{
    if (str == "")
        return (false);
    this->_nickname = str;
    return (true);
}

bool Contact::set_phoneNumber(std::string str)
{
    if (str == "")
        return (false);
    this->_phoneNumber = str;
    return (true);
}

bool Contact::set_darkestSecret(std::string str)
{
    if (str == "")
        return (false);
    this->_darkestSecret = str;
    return (true);
}

int Contact::get_nbInst(void)
{
    return (Contact::_nbInst);
}

int Contact::get_index(void)const
{
    return (this->_index);
}

int Contact::_nbInst = 0;