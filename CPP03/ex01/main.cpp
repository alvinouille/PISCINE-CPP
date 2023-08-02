#include "ScavTrap.hpp"

int main()
{
    ScavTrap mob1("La Montagne");
    ScavTrap mob2("Oberyn");

    mob2.attack(mob1.getName());
    mob1.takeDamage(mob2.getAttackDamage());
    mob1.beRepaired(25);
    mob1.guardGate();
    mob1.attack(mob2.getName());
    mob2.takeDamage(mob1.getAttackDamage());
}