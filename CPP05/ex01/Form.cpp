#include "Form.hpp"

Form::Form() : _name("Default"), _signed(false), _sGrade(1), _eGrade(1) {}

Form::Form(std::string name, int const sGrade, int const eGrade) : _name(name), _sGrade(sGrade), _eGrade(eGrade)
{
    if (sGrade > 150 || eGrade > 150)
        throw Form::GradeTooLowException();
    else if (sGrade < 1 || eGrade < 1)
        throw Form::GradeTooHighException();
    else
    {
        this->_signed = false;
        std::cout << "Parametric constructor of Form [" << name << "]" << std::endl;
    }
}

Form::~Form() {}

Form::Form(Form const &copy) : _name(copy._name), _signed(copy._signed), _sGrade(copy._sGrade), _eGrade(copy._eGrade)
{
    // std::cout << "Copy constructor of Form [" << _name << "]" << std::endl;
}

Form &Form::operator=(Form const &rhs)
{
    if (this == &rhs)
        return (*this);
    this->_signed = rhs._signed;
    return (*this);
}

std::string Form::getName()const
{
    return (this->_name);
}

int Form::getSGrade()const
{
    return (this->_sGrade);
}

int Form::getEGrade()const
{
    return (this->_eGrade);
}

bool Form::isSigned()const
{
    return (this->_signed);
}

void Form::beSigned(Bureaucrat &b)
{
    if (b.getGrade() <= this->_sGrade)
        this->_signed = 1;
    else
        throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade to sign or execute too high (exception)");
}
const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade to sign or execute too low (exception)");
}

std::ostream &operator<<(std::ostream &o, Form const &i)
{
    o << "[" << i.getName() << "] (grade for signing it : " << i.getSGrade() << ") ";
    if (i.isSigned())
        o << "-> SIGNED" << std::endl;
    else
        o << "-> UNSIGNED" << std::endl;
    return (o);
}