#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    ScalarConverter scal;

    if (ac != 2)
        return (1);
    std::string str = av[1];
    scal.convert(str);
}