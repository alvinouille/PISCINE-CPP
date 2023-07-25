#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm(), _target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy.getName(), copy.getSGrade(), copy.getEGrade()), _target(copy._target)
{
    *this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
    if (this == &rhs)
        return (*this);
    AForm::operator=(rhs);
    this->_target = rhs._target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor)const
{
    static int i = 0;
    if (this->isSigned() && executor.getGrade() <= this->getEGrade())
    {
        std::cout << "Tatatatatatatat..." << std::endl;
        if (i == 0)
        {
            std::cout << this->_target << " has been robotomised" << std::endl;
            i = 1;
        }
        else
        {
            std::cout << "The robotomisation of " << this->_target << "have failed" << std::endl;
            i = 0;
        }
    }
    else
        throw AForm::GradeTooLowException();
}