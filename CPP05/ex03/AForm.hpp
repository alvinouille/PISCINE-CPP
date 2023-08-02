#ifndef AFORM_H
# define AFORM_H

#include "Bureaucrat.hpp"

class Bureaucrat ;

class AForm
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
        class AlreadySignedException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class NotSignedException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        AForm();
        AForm(std::string name, int const sGrade, int const eGrade);
        AForm(AForm const &copy);
        AForm &operator=(AForm const &rhs);
        virtual ~AForm();

        std::string getName()const;
        int getSGrade()const;
        int getEGrade()const;
        bool isSigned()const;

        void beSigned(Bureaucrat &b);
        void execute(Bureaucrat const &executor)const;
        virtual void execution() const = 0;

    private:
        std::string const _name;
        bool _signed;
        int const _sGrade;
        int const _eGrade;
};

std::ostream &operator<<(std::ostream &o, AForm const &i);

#endif