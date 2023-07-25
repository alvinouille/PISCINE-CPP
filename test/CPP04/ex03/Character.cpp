#include "Character.hpp"

Character::Character() : ICharacter(), _name("")
{
    for (int i = 0 ; i < 4 ; i++)
        this->_inventory[i] = NULL;
    std::cout << "Default constructor of Character" << std::endl;
}

Character::Character(std::string const name) : ICharacter(), _name(name)
{
    for (int i = 0 ; i < 4 ; i++)
        this->_inventory[i] = NULL;
    std::cout << "Parametric constructor of Character" << std::endl;
}

Character::Character(Character const &copy) : ICharacter(copy)
{
    std::cout << "Copy constructor of Character" << std::endl;
    *this = copy;
}

Character::~Character() 
{
    std::cout << "Destructor of Character" << std::endl;
    for (int i = 0 ; i < 4 ; i++)
    {
        if (this->_inventory[i])
            delete this->_inventory[i];
    }
}

Character &Character::operator=(Character const &rhs)
{
    std::cout << "Assignement operator of Character" << std::endl;
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
    }
    for (int i = 0 ; i < 4 ; i++)
    {
        if (rhs._inventory[i])
            this->_inventory[i] = rhs._inventory[i];
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
    for (int i = 0 ; i < 4 ; i++)
    {
        if (!this->_inventory[i])
        {
            this->_inventory[i] = m;
            std::cout << "Now equiped with " << m->getType() << std::endl;
            return ;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && this->_inventory[idx])
    {
        std::cout << "Now unequiped with " << this->_inventory[idx]->getType() << std::endl;
        delete this->_inventory[idx]; //NON enregistrer adresse dans tab dynamique <vector> de AMat
        this->_inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && this->_inventory[idx])
    {
        std::cout << "Using : ";
        this->_inventory[idx]->use(target);
    }
}