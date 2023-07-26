#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    // std::cout << "- - - Making a bureaucrat with too low grade - - -" << std::endl;
    // try
    // {
    //     Bureaucrat worst("worst", 151);
    //     std::cout << worst;
    // }
    // catch (Bureaucrat::GradeTooHighException &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
    // catch (Bureaucrat::GradeTooLowException &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
    
    // std::cout << std::endl;
    // std::cout << "- - - Making a valid bureaucrat, but upgrading him too much - - -" << std::endl;

    // try
    // {
    //     Bureaucrat boss("boss", 2);
    //     std::cout << boss;
    //     boss.upgrading();
    //     std::cout << boss;
    //     boss.upgrading();
    //     std::cout << boss;
    // }
    // catch (Bureaucrat::GradeTooHighException &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
    // catch (Bureaucrat::GradeTooLowException &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }

    // std::cout << std::endl;
    // std::cout << "- - - Making unvalid Aform - - -" << std::endl;
    // try
    // {
    //     AForm form("26B", 1, 151);
    //     std::cout << form;
    // }
    // catch(AForm::GradeTooHighException &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
    // catch(AForm::GradeTooLowException &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }

    // std::cout << std::endl;
    // std::cout << "- - - 2 valid bureaucrat try to sign a valid Aform, one is able to, the other one isn't - - -" << std::endl;
    
    {
        Bureaucrat boss ("Big Boss", 130);
        Bureaucrat middle("Middle class man", 140);
        Bureaucrat idiot ("The Idiot of the village", 150);

        ShrubberyCreationForm form1("Lollapalooza");
        std::cout << boss << middle << idiot << form1;

        idiot.signForm(form1);
        idiot.executeForm(form1);
        std::cout << form1;
        middle.signForm(form1);
        middle.executeForm(form1);
        std::cout << form1;
        boss.signForm(form1);
        boss.executeForm(form1);
    }

    std::cout << std::endl << std::endl;
    {
        Bureaucrat boss ("Big Boss", 1);
        Bureaucrat middle("Middle class man", 70);
        Bureaucrat idiot ("The Idiot of the village", 150);
        
        RobotomyRequestForm form2("Himself");
        std::cout << boss << middle << idiot << form2;

        idiot.signForm(form2);
        idiot.executeForm(form2);
        std::cout << form2;
        boss.executeForm(form2);
        middle.signForm(form2);
        boss.executeForm(form2);
    }

    std::cout << std::endl << std::endl;
    {
        Bureaucrat boss ("Big Boss", 1);
        Bureaucrat idiot ("The Idiot of the village", 150);
        
        PresidentialPardonForm form3("Nico Moreno");
        std::cout << boss << idiot << form3;

        idiot.signForm(form3);
        idiot.executeForm(form3);
        std::cout << form3;
        boss.signForm(form3);
        boss.executeForm(form3);
    }
}