#ifndef FORM_H
# define FORM_H

#include "Bureaucrat.hpp"

class Bureaucrat ;

class Form
{
    public:
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        Form();
        Form(std::string name, int const sGrade, int const eGrade);
        Form(Form const &copy);
        Form &operator=(Form const &rhs);
        ~Form();

        std::string getName()const;
        int getSGrade()const;
        int getEGrade()const;
        bool isSigned()const;

        void beSigned(Bureaucrat &b);

    private:
        std::string const _name;
        bool _signed;
        int const _sGrade;
        int const _eGrade;
};

std::ostream &operator<<(std::ostream &o, Form const &i);

#endif