#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource()
{
    for (int i = 0 ; i < 4 ; i++)
        this->_repertory[i] = NULL;
    std::cout << "Default constructor of MateriaSource" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &copy) : IMateriaSource(copy)
{
    std::cout << "Copy constructor of MateriaSource" << std::endl;
    *this = copy;
}

MateriaSource::~MateriaSource() 
{
    std::cout << "Destructor of MateriaSource" << std::endl;
    for (int i = 0 ; i < 4 ; i++)
    {
        if (this->_repertory[i])
            delete this->_repertory[i];
    }
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs)
{
    std::cout << "Assignement operator of MateriaSource" << std::endl;
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

std::string const &MateriaSource::getName() const
{
    return (this->_name);
}

void MateriaSource::learnMateria(AMateria *mat)
{
    for (int i = 0 ; i < 4 ; i++)
    {
        if (!this->_repertory[i])
        {
            this->_repertory[i] = new AMateria(*mat);
            return ;
        }
    }
}

void MateriaSource::createMateria(std:string const &type)
{
    for (int i = 0 ; i < 4 ; i++)
    {
        if (this->_repertory[i].type == type)
            return (new AMateria(this->_repertory[i]));
    }
}