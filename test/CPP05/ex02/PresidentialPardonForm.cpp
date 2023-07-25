#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(), _target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm(copy.getName(), copy.getSGrade(), copy.getEGrade()), _target(copy._target)
{
    *this = copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
    if (this == &rhs)
        return (*this);
    AForm::operator=(rhs);
    this->_target = rhs._target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &executor)const
{
    if (this->isSigned() && executor.getGrade() <= this->getEGrade())
    {
        std::cout << this->_target << "has been forgiven by Zaphod Beeblebrox" << std::endl;
    }
    else
        throw AForm::GradeTooLowException();
}