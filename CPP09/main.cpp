#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    (void)ac;
    Bitcoin btc(av[1]);
    btc.fileToMap();
    btc.printData();
}