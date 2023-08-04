#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    (void)ac;
    if (ac != 2)
    {
        std::cout << "Wrong number of args" << std::endl;
        return (1);
    }
    Bitcoin btc(av[1]);
    btc.fileToMap();
}