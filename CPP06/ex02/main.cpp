#include "Base.hpp"

int main()
{
    Base base;

    for (int i = 0 ; i < 10 ; i++)
    {
        Base *random;
        random = base.generate();
        base.identify(random);
        base.identify(*random);
        delete random;
    }

}