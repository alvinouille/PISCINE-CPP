#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

#include <string>
#include <iostream>
#include <stdexcept>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class AForm ;
class Bureaucrat ;

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string const target);
        PresidentialPardonForm(PresidentialPardonForm const &copy);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);
        ~PresidentialPardonForm();

        void execute(Bureaucrat const &executor)const;

    private:
        std::string _target;
};

#endif