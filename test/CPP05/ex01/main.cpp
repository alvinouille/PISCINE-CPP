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
    
    std::cout << std::endl;
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

    std::cout << std::endl;
    std::cout << "- - - Making unvalid form - - -" << std::endl;
    try
    {
        Form form("26B", 1, 151);
        std::cout << form;
    }
    catch(Form::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(Form::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "- - - 2 valid bureaucrat try to sign a valid form, one is able to, the other one isn't - - -" << std::endl;
    Bureaucrat boss ("The Boss", 1);
    Bureaucrat idiot ("The Idiot", 50);
    Form form("Fire everyone", 1, 1);
    std::cout << boss << idiot << form;
    idiot.signForm(form);
    std::cout << form;
    boss.signForm(form);
    std::cout << form;
}