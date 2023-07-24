#include "Character.hpp"

Character::Character() : ICharacter(), index(0)
{
    std::cout << "Default constructor of Character" << std::endl;
}

Character::Character(std::string const name) : ICharacter(), _name(name), _index(0)
{
    std::cout << "Parametric constructor of Character" << std::endl;
    Character::_index++;
}

Character::Character(Character const &copy) : ICharacter(copy)
{
    std::cout << "Copy constructor of Character" << std::endl;
    *this = copy;
}

Character::~Character() 
{
    std::cout << "Destructor of Character" << std::endl;
    for (int i = 0 ; i < _index ; i++)
        delete this->_inventory[i];
}

Character &Character::operator=(Character const &rhs)
{
    std::cout << "Assignement operator of Character" << std::endl;
    if (this == &rhs)
        return (*this);
    ICharacter::operator=(rhs);
    for (int i = 0 ; i < _index ; i++)
        delete this->_inventory[i];
    for (int i = 0 ; i < rhs._index ; i++)
        this->_inventory[i] = rhs._inventory[i];
    this->_name = rhs._name;
    this->_index = rhs._index;
    return (*this);
}

std::string const &Character::getName() const
{
    return (this->_name);
}

void Character::equip(AMateria* m)
{
    if (this->_index != 4)
        this->_inventory[_index] = new AMateria(*m);
    if (this->_index != 4)
        (this->_index)++;
}

void Character::unequip(int idx)
{
    //enregistrer adresse dans tab dynamique <vector> de AMat
    if (idx >= 0 && idx < 4 && this->_inventory[idx])
    {
        this->_inventory[idx] = NULL;
        this->_index = idx;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && this->_inventory[idx])
        this->_inventory[idx]->use(target);
}