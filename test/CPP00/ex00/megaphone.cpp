#include <iostream>
#include <string>
#include <cctype>

int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    else if (ac > 2)
        return 0;

    std::string str;
    str = av[1];
    int length = str.length();
    for (int i = 0 ; i < length; i++)
        str[i] = std::toupper(str[i]);
    std::cout << str << std::endl;
}