#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;
    (void)ac;

    if (ac > 2 || ac < 1)
    {
        std::cout << "Wrong nb of args" << std::endl;
        return (1);
    }
    if (av[1])
        harl.complain(av[1]);
    else
        harl.complain("");
}