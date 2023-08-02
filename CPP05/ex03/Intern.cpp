#include "Intern.hpp"

Intern::Intern() 
{
    _tab[0] = &Intern::SCForm ;
    _tab[1] = &Intern::RRForm ;
    _tab[2] = &Intern::PPForm ;
}

Intern::~Intern() {}

Intern::Intern(Intern const &copy)
{
    *this = copy;
}

Intern &Intern::operator=(Intern const &rhs)
{
    (void)rhs;
    return (*this);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
    std::string tab[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *form;
    for (int i = 0 ; i < 3 ; i++)
    {
        if (tab[i] == name)
        {
            form = (this->*_tab[i])(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return (form);
        }
    }
    throw (Intern::InexistantFormException());
}

const char *Intern::InexistantFormException::what()const throw()
{
    return ("Inexistant Form (exception)");
}

AForm *Intern::SCForm(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::RRForm(std::string target)
{
    return (new RobotomyRequestForm(target));
}

AForm *Intern::PPForm(std::string target)
{
    return (new PresidentialPardonForm(target));
}

