#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{ 
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