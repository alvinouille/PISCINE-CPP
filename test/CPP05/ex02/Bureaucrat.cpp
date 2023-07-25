#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else
    {
        std::cout << "Parametric constructor of Bureaucrat" << std::endl;
        this->_grade = grade;
    }
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : _name(copy._name)
{
    *this = copy;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
    if (this == &rhs)
        return (*this);
    this->_grade = rhs._grade;
    return (*this);
}

std::string Bureaucrat::getName()const
{
    return (this->_name);
}

int Bureaucrat::getGrade()const
{
    return (this->_grade);
}

void Bureaucrat::upgrading()
{
    std::cout << this->_name << " upgrading..." << std::endl;
    if (this->_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->_grade--;
}

void Bureaucrat::lowgrading()
{
    std::cout << this->_name << " lowgrading..." << std::endl;
    if (this->_grade - 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade++;
}

void Bureaucrat::signForm(AForm &f)
{
    try
    {
        f.beSigned(*this);
        std::cout << this->_name << " signed form [" << f.getName() << "]" << std::endl;
    }
    catch (AForm::GradeTooLowException &e)
    {
        std::cout << this->_name << " couldn't sign form [";
        std::cout << f.getName() << "] because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form)
{
    try
    {
        form.execute(*this);
        std::cout << this->_name << " executed form [" << form.getName() << "]" << std::endl;
    }
    catch (AForm::GradeTooLowException &e)
    {
        std::cout << this->_name << " couldn't execute form [";
        std::cout << form.getName() << "] because " << e.what() << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high exception");
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low exception");
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i)
{
    o << i.getName() << ", bureaucrat grade " << i.getGrade() << "." << std::endl;
    return (o);
}