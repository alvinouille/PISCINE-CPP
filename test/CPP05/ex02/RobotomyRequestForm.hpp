#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

#include <string>
#include <iostream>
#include <stdexcept>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class AForm ;
class Bureaucrat ;

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string const target);
        RobotomyRequestForm(RobotomyRequestForm const &copy);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
        ~RobotomyRequestForm();

        void execute(Bureaucrat const &executor)const;

    private:
        std::string _target;
};

#endif