#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class AForm ;
class Bureaucrat ;

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string const target);
        ShrubberyCreationForm(ShrubberyCreationForm const &copy);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
        ~ShrubberyCreationForm();

        void execution()const;

    private:
        std::string _target;
};

#endif