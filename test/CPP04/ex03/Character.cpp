#include "Character.hpp"

const std::string cyan("\033[1;36m");
const std::string reset("\033[0m");
const std::string red("\033[0;31m");

Character::Character() : ICharacter(), _name("")
{
    for (int i = 0 ; i < 4 ; i++)
        this->_inventory[i] = NULL;
    std::cout << cyan << "Default constructor of Character" << reset << std::endl;
}

Character::Character(std::string const name) : ICharacter(), _name(name)
{
    for (int i = 0 ; i < 4 ; i++)
        this->_inventory[i] = NULL;
    std::cout << cyan << "Parametric constructor of Character " << this->_name << reset << std::endl;
}

Character::Character(Character const &copy) : ICharacter(copy), _name(copy._name + "_copy")
{
    std::cout << cyan << "Copy constructor of Character " << this->_name << reset << std::endl;
    for (int i = 0 ; i < 4 ; i++)
    {
        if (copy._inventory[i])
            this->_inventory[i] = copy._inventory[i]->clone();
        else
            this->_inventory[i] = NULL;
    }
}

Character::~Character() 
{
    std::cout << red << "Destructor of Character " << this->_name << reset << std::endl;
    for (int i = 0 ; i < 4 ; i++)
    {
        if (this->_inventory[i])
        {
            delete this->_inventory[i];
            this->_inventory[i] = NULL;
        }
    }
}

Character &Character::operator=(Character const &rhs)
{
    std::cout << cyan << "Assignement operator of Character " << this->_name << reset << std::endl;
    if (this == &rhs)
        return (*this);
    ICharacter::operator=(rhs);
    for (int i = 0 ; i < 4 ; i++)
    {
        if (this->_inventory[i])
        {
            delete this->_inventory[i];
            this->_inventory[i] = NULL;
        }
        if (rhs._inventory[i])
            this->_inventory[i] = rhs._inventory[i]->clone();
    }
    this->_name = rhs._name;
    return (*this);
}

std::string const &Character::getName() const
{
    return (this->_name);
}

void Character::equip(AMateria* m)
{
    if (!m)
    {
        std::cout << this->_name << " has to equip himself with pure void ?" << std::endl;
        return ;
    }
    for (int i = 0 ; i < 4 ; i++)
    {
        if (!this->_inventory[i])
        {
            this->_inventory[i] = m;
            std::cout << this->_name << " now equiped with " << m->getType() << std::endl;
            return ;
        }
    }
    std::cout << this->_name << "'s inventory full ! Sorry not sorry" << std::endl;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && this->_inventory[idx])
    {
        std::cout << this->_name << " now unequiped with " << this->_inventory[idx]->getType() << std::endl;
        this->_inventory[idx] = NULL;
    }
    else
        std::cout << this->_name << " : Wrong index or no materia here" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && this->_inventory[idx])
    {
        std::cout << this->_name << " using : ";
        this->_inventory[idx]->use(target);
    }
    else
        std::cout << this->_name << " : Wrong index or no materia here" << std::endl;
}

AMateria *Character::returnMateria(int idx)
{
    if (idx >= 0 && idx < 4 && this->_inventory[idx])
        return (this->_inventory[idx]);
    else 
        return (NULL);
}