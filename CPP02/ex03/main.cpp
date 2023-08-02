#include "Point.hpp"

int main(void) 
{
    std::cout << "TEST 1 : IN" << std::endl;

    Point a1(2.0, 4.0);
    Point b1(-1.0, -1.0);
    Point c1(4.0, 1.0);
    Point p1(3.0, 2.4);

    if (bsp(a1, b1, c1, p1))
        std::cout << "P is in !" << std::endl;
    else
        std::cout << "P is out !" << std::endl;

    std::cout << std::endl << "TEST 2 : OUT (ON A SIDE)" << std::endl;

    Point a2(2.0, 4.0);
    Point b2(1.0, 1.0);
    Point c2(4.0, 1.0);
    Point p2(3.0, 1.05);

    if (bsp(a2, b2, c2, p2))
        std::cout << "P is in !" << std::endl;
    else
        std::cout << "P is out !" << std::endl;
    
    std::cout << std::endl << "TEST 3 : OUT (COMPLETELY OUTSIDE)" << std::endl;

    Point a3(0.0, 0.0);
    Point b3(1.0, 1.0);
    Point c3(0.0, 1.0);
    Point p3(10.0, 2.5);

    if (bsp(a3, b3, c3, p3))
        std::cout << "P is in !" << std::endl;
    else
        std::cout << "P is out !" << std::endl;
    
    std::cout << std::endl << "TEST 4 : OUT (ON POINT B)" << std::endl;

    Point a4(0.0, 0.0);
    Point b4(1.0, 1.0);
    Point c4(0.0, 1.0);
    Point p4(1, 1);

    if (bsp(a4, b4, c4, p4))
        std::cout << "P is in !" << std::endl;
    else
        std::cout << "P is out !" << std::endl;
}
