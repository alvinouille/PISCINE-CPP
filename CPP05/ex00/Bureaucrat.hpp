#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat
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
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat const &copy);
        Bureaucrat &operator=(Bureaucrat const &rhs);
        ~Bureaucrat();

        std::string getName()const;
        int getGrade()const;
        void upgrading();
        void lowgrading();

    private:
        std::string const _name;
        int _grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);

#endif