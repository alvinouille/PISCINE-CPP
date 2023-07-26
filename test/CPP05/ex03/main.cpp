#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

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

    // {
    //     Bureaucrat boss ("Big Boss", 130);
    //     Bureaucrat middle("Middle class man", 140);
    //     Bureaucrat idiot ("The Idiot of the village", 150);

    //     ShrubberyCreationForm form1("Lollapalooza");
    //     std::cout << boss << middle << idiot << form1;

    //     idiot.signForm(form1);
    //     idiot.executeForm(form1);
    //     std::cout << form1;
    //     middle.signForm(form1);
    //     middle.executeForm(form1);
    //     std::cout << form1;
    //     boss.executeForm(form1);
    // }
    
    // std::cout << std::endl << std::endl;
    // {
    //     Bureaucrat boss ("Big Boss", 1);
    //     Bureaucrat idiot ("The Idiot of the village", 150);
        
    //     PresidentialPardonForm form3("Nico Moreno");
    //     std::cout << boss << idiot << form3;

    //     idiot.signForm(form3);
    //     idiot.executeForm(form3);
    //     std::cout << form3;
    //     boss.signForm(form3);
    //     boss.executeForm(form3);
    // }

    Bureaucrat boss ("Big Boss", 1);
    Bureaucrat idiot ("The Idiot of the village", 150);
    std::cout << boss << idiot;
    Intern someRandomIntern ;
    try
    {
        std::cout << std::endl <<  "- - - Test with a valid name of form - - -" << std::endl;
        AForm *rrf;

        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *rrf;

        idiot.signForm(*rrf);
        idiot.executeForm(*rrf);
        boss.executeForm(*rrf);
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;

        std::cout << std::endl << "- - - Test with a invalid name of form - - -" << std::endl;
        AForm *bbf;

        bbf = someRandomIntern.makeForm("blblblblbl", "Bender");
        std::cout << *bbf;

        idiot.signForm(*bbf);
        idiot.executeForm(*bbf);
        boss.signForm(*bbf);
        boss.executeForm(*bbf);
    }
    catch(Intern::InexistantFormException &e)
    {
        std::cout << e.what() << std::endl;
    }

}