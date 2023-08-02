#include "Zombie.hpp"

Zombie::Zombie(void)
{
    return ;
}

Zombie::~Zombie(void)
{
    std::cout << "Zombie named " << this->_name << " deleted" << std::endl;
    return ;
}

void    Zombie::announce(void)const
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::set_name(std::string name)
{
    this->_name = name;
}

