#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie *horde;
    horde = new Zombie[N];

    for (int i = 0 ; i < N ; i++)
        horde[i].set_name(name);
    return (horde);
}

int main()
{
    Zombie *zombie;
    int N(10);

    zombie = zombieHorde(N, "Joel");
    for (int i = 0 ; i < N ; i++)
        zombie[i].announce();
    delete [] zombie;
}