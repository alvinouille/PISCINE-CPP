#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <string>
#include <math.h>

class Fixed
{
    public:
        Fixed(void);
        Fixed(int const n);
        Fixed(float const f);
        Fixed(Fixed const &src);
        ~Fixed(void);
        Fixed &operator=(Fixed const &rhs);
        int getRawBits(void)const;
        void setRawBits(int const raw);
        float toFloat(void)const;
        int toInt(void)const;

    private:
        int _fixedPt;
        int const static _fracPart;
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif