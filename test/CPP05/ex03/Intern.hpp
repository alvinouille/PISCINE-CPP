#ifndef INTERN_H
# define INTERN_H

#include <string>
#include <iostream>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm ;
class PresidentialPardonForm ;
class RobotomyRequestform ;
class ShrubberyCreationform ;

class Intern
{
    public:
        class InexistantFormException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        Intern();
        Intern(Intern const &copy);
        Intern &operator=(Intern const &rhs);
        ~Intern();

        AForm *makeForm(std::string name, std::string target);

    private:
        AForm *SCForm(std::string target);
        AForm *RRForm(std::string target);
        AForm *PPForm(std::string target);
        typedef AForm *(Intern::*f)(std::string target);
        f _tab[3];
};

#endif