#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <string>

class Fixed
{
    public:
        Fixed(void);
        Fixed(Fixed const &src);
        ~Fixed(void);
        Fixed &operator=(Fixed const &rhs);
        int getRawBits(void)const;
        void setRawBits(int const raw);

    private:
        int _fixedPt;
        int const static _fracPart;
};

#endif