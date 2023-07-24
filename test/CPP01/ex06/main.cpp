#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;
    (void)ac;

    if (ac != 2)
        return (1);
    harl.complain(av[1]);
}