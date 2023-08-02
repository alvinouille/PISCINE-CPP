#include "Bureaucrat.hpp"

int main()
{
    std::cout << std::endl << "- - - Making a bureaucrat with too low grade - - -" << std::endl << std::endl;
    try
    {
        Bureaucrat worst("worst", 151);
        std::cout << worst;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl <<  "- - - Making a valid bureaucrat, but upgrading him too much - - -" << std::endl << std::endl;
    try
    {
        Bureaucrat boss("boss", 2);
        std::cout << boss;
        boss.upgrading();
        std::cout << boss;
        boss.upgrading();
        std::cout << boss;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << "- - - Making a valid bureaucrat, but lowgrading him too much - - -" << std::endl << std::endl;
    try
    {
        Bureaucrat tmp("idiot of the village", 149);
        std::cout << tmp;
        tmp.lowgrading();
        std::cout << tmp;
        tmp.lowgrading();
        std::cout << tmp;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}