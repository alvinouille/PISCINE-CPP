#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie *zombie;
    
    zombie = new Zombie;
    zombie->set_name(name);
    return (zombie);
}

void    randomChump(std::string name)
{
    Zombie zombie;
    
    zombie.set_name(name);
    zombie.announce();
}

int main()
{
    Zombie *zombie;

    zombie = newZombie("Basile");
    zombie->announce();
    randomChump("Daniel");
    delete zombie;

}