#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Wrong number of args" << std::endl;
        return (1);
    }
    RPN r;
    r.operation(std::string(av[1]));
}