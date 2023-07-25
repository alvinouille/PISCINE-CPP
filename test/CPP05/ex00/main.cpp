#include "Bureaucrat.hpp"

int main()
{
    std::cout << "- - - Making a bureaucrat with too low grade - - -" << std::endl;
    try
    {
        Bureaucrat worst("worst", 151);
        std::cout << worst;
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "- - - Making a valid bureaucrat, but upgrading him too much - - -" << std::endl;
    try
    {
        Bureaucrat boss("boss", 2);
        std::cout << boss;
        boss.upgrading();
        std::cout << boss;
        boss.upgrading();
        std::cout << boss;
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
}