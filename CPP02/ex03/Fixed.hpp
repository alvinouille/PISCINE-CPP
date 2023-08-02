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

        int getRawBits(void)const;
        void setRawBits(int const raw);
        float toFloat(void)const;
        int toInt(void)const;

        Fixed &operator=(Fixed const &rhs);
    
        bool operator>(Fixed const &rhs)const;
        bool operator<(Fixed const &rhs)const;
        bool operator>=(Fixed const &rhs)const;
        bool operator<=(Fixed const &rhs)const;
        bool operator==(Fixed const &rhs)const;
        bool operator!=(Fixed const &rhs)const;
    
        Fixed operator+(Fixed const &rhs)const;
        Fixed operator-(Fixed const &rhs)const;
        Fixed operator*(Fixed const &rhs)const;
        Fixed operator/(Fixed const &rhs)const;

        Fixed &operator++(void);
        Fixed operator++(int);
        Fixed &operator--(void);
        Fixed operator--(int);

        Fixed static &min(Fixed &a, Fixed &b);
        Fixed const static &min(Fixed const &a, Fixed const &b);
        Fixed static &max(Fixed &a, Fixed &b);
        Fixed const static &max(Fixed const &a, Fixed const &b);


    private:
        int _fixedPt;
        int const static _fracPart;
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif