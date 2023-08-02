#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
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
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

}