#include "Zombie.hpp"

int main()
{
    Zombie *zombie;

    zombie = newZombie("Basile");
    zombie->announce();
    randomChump("Daniel");
    delete zombie;

}