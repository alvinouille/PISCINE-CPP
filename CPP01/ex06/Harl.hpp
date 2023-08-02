#ifndef HARL_H
# define HARL_H

#include <iostream>
#include <string>

class Harl
{
    public:
        Harl(void);
        ~Harl(void);
        void complain(std::string level);

    private:
        void debug(void)const;
        void info(void)const;
        void warning(void)const;
        void error(void)const;
        typedef void (Harl::*f)(void)const;
        f tab[4];
};

#endif