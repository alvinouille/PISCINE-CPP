#include "Point.hpp"

static const Fixed triangleArea(Point const a, Point const b, Point const c)
{
    Point ab((b.getX() - a.getX()).toFloat(), (b.getY() - a.getY()).toFloat());
    Point ac((c.getX() - a.getX()).toFloat(), (c.getY() - a.getY()).toFloat());
    Fixed area((ab.getX() * ac.getY()) - (ab.getY() * ac.getX()));
    if (area < Fixed(0))
        area = area * Fixed(-1);
    return (Fixed(area / Fixed(2).toFloat()));
}


bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    (void)point;
    Fixed triangleAll(triangleArea(a, b, c));
    Fixed triangleP1(triangleArea(a, b, point));
    Fixed triangleP2(triangleArea(a, c, point));
    Fixed triangleP3(triangleArea(b, c, point));
    std::cout << "TriangleAll = " << triangleAll << " / Others = " << triangleP1 << " + " << triangleP2 << " + " << triangleP3;
    std::cout << " (Somme = " << triangleP1 + triangleP2 + triangleP3 << ")" << std::endl;
    if ((triangleAll == (triangleP1 + triangleP2 + triangleP3)) && triangleP1 != 0 && triangleP2 != 0 && triangleP3 != 0)
        return (true);
    else
        return (false);
}