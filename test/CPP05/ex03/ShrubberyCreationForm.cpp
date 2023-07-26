#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy.getName(), copy.getSGrade(), copy.getEGrade()), _target(copy._target)
{
    *this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
    if (this == &rhs)
        return (*this);
    AForm::operator=(rhs);
    this->_target = rhs._target;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execution()const
{
    std::ofstream outfile((this->_target + "_shrubbery").c_str());
    outfile << "             ii " << std::endl;
    outfile << "            o  o" << std::endl;
    outfile << "           o++++o" << std::endl;
    outfile << "          o  ()  o" << std::endl;
    outfile << "          o      o" << std::endl;
    outfile << "         o~`~`~`~`o" << std::endl;
    outfile << "        o  ()  ()  o" << std::endl;
    outfile << "        o          o" << std::endl;
    outfile << "       o &*&*&*&*&*&o" << std::endl;
    outfile << "      o  ()  ()  ()  o" << std::endl;
    outfile << "      o              o" << std::endl;
    outfile << "     o++++++++++++++++o" << std::endl;
    outfile.close();
}