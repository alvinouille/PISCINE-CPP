#include "Fixed.hpp"

int main( void ) 
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    // std::cout << "Own tests:" << std::endl;
    // Fixed c(10.0f);
    // Fixed d(2);
    // std::cout << c << " / " << d << " = " << c / d << std::endl;
    // std::cout << c << " + " << d << " = " << c + d << std::endl;
    // std::cout << c << " - " << d << " = " << c - d << std::endl;
    // std::cout << "Between the two the min is : " << Fixed::min(c, d) << std::endl;
    return 0;
}
