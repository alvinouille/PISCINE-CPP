#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
    public:
        Contact(void);
        ~Contact(void);

        std::string get_firstName(void)const;
        std::string get_nickname(void)const;
        std::string get_phoneNumber(void)const;
        std::string get_darkestSecret(void)const;
        bool set_firstName(std::string);
        bool set_nickname(std::string);
        bool set_phoneNumber(std::string);
        bool set_darkestSecret(std::string);
        static int get_nbInst(void);
        int get_index(void)const;

    private:
        std::string _firstName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestSecret;
        static int  _nbInst;
        int         _index;

};
#endif