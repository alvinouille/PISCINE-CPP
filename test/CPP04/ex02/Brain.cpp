#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Default constructor of Brain" << std::endl;
}

Brain::Brain(Brain const &copy)
{
    std::cout << "Copy constructor of Brain" << std::endl;
    *this = copy;
}

Brain::~Brain() 
{
    std::cout << "Destructor of Brain" << std::endl;
}

Brain &Brain::operator=(Brain const &rhs)
{
    std::cout << "Assignement operator of Brain" << std::endl;
    if (this == &rhs)
        return (*this);
    for (int i = 0 ; i < 100 ; i++)
        this->_ideas[i] = rhs._ideas[i];
    return (*this);
}

bool Brain::setIdea(std::string const idea, int i)
{
    if (i >= 100 || i < 0)
        return (false);
    this->_ideas[i] = idea;
    return (true);
}

std::string Brain::getIdea(int i)const
{
    if (i >= 100 || i < 0)
        return (NULL);
    return (this->_ideas[i]);
}