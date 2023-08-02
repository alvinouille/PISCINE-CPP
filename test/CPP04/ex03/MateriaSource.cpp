#include "MateriaSource.hpp"

const std::string cyan("\033[1;36m");
const std::string reset("\033[0m");
const std::string red("\033[0;31m");

MateriaSource::MateriaSource() : IMateriaSource()
{
    for (int i = 0 ; i < 4 ; i++)
        this->_repertory[i] = NULL;
    std::cout << cyan << "Default constructor of MateriaSource" << reset << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &copy) : IMateriaSource(copy)
{
    std::cout << cyan << "Copy constructor of MateriaSource" << reset << std::endl;
    *this = copy;
}

MateriaSource::~MateriaSource() 
{
    std::cout << red << "Destructor of MateriaSource" << reset << std::endl;
    for (int i = 0 ; i < 4 ; i++)
    {
        if (this->_repertory[i])
            delete this->_repertory[i];
    }
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs)
{
    std::cout << cyan << "Assignement operator of MateriaSource" << reset << std::endl;
    if (this == &rhs)
        return (*this);
    IMateriaSource::operator=(rhs);
    for (int i = 0 ; i < 4 ; i++)
    {
        if (this->_repertory[i])
        {
            delete this->_repertory[i];
            this->_repertory[i] = NULL;
        }
    }
    for (int i = 0 ; i < 4 ; i++)
    {
        if (rhs._repertory[i])
            this->_repertory[i] = rhs._repertory[i];
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria *mat)
{
    for (int i = 0 ; i < 4 ; i++)
    {
        if (!this->_repertory[i])
        {
            this->_repertory[i] = mat;
            std::cout << "SourceMateria knows now how to create a materia " << mat->getType() << std::endl;
            return ;
        }
    }
    std::cout << "SourceMateria's repertory full ! Sorry not sorry" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0 ; i < 4 ; i++)
    {
        if (this->_repertory[i] && this->_repertory[i]->getType() == type)
        {
            std::cout << "SourceMateria create and return a materia " << type << std::endl;
            return (this->_repertory[i]->clone());
        }
    }
    std::cout << "[" << type << "] type of materia not known by SourceMateria" << std::endl;
    return (NULL);
}