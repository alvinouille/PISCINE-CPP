#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signed(false), _sGrade(1), _eGrade(1) {}

AForm::AForm(std::string name, int const sGrade, int const eGrade) : _name(name), _sGrade(sGrade), _eGrade(eGrade)
{
    if (sGrade > 150 || eGrade > 150)
        throw AForm::GradeTooLowException();
    else if (sGrade < 1 || eGrade < 1)
        throw AForm::GradeTooHighException();
    else
    {
        this->_signed = false;
        std::cout << "Parametric constructor of AForm" << std::endl;
    }
}

AForm::~AForm() {}

AForm::AForm(AForm const &copy) : _name(copy._name), _signed(copy._signed), _sGrade(copy._sGrade), _eGrade(copy._eGrade)
{
    *this = copy;
}

AForm &AForm::operator=(AForm const &rhs)
{
    if (this == &rhs)
        return (*this);
    this->_signed = rhs._signed;
    return (*this);
}

std::string AForm::getName()const
{
    return (this->_name);
}

int AForm::getSGrade()const
{
    return (this->_sGrade);
}

int AForm::getEGrade()const
{
    return (this->_eGrade);
}

bool AForm::isSigned()const
{
    return (this->_signed);
}

void AForm::beSigned(Bureaucrat &b)
{
    if (b.getGrade() <= this->_sGrade)
        this->_signed = 1;
    else
        throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade to sign or execute too high (exception)");
}
const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade to sign or execute too low (exception)");
}

std::ostream &operator<<(std::ostream &o, AForm const &i)
{
    o << "[" << i.getName() << "] (grade for signing it : " << i.getSGrade() << ") ";
    if (i.isSigned())
        o << "-> SIGNED" << std::endl;
    else
        o << "-> UNSIGNED" << std::endl;
    return (o);
}