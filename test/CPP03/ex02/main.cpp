#include "FragTrap.hpp"

int main()
{
    FragTrap mob1("Brienne of Tarth");
    FragTrap mob2("Jamie Lannister");

    mob2.attack(mob1.getName());
    mob1.takeDamage(mob2.getAttackDamage());
    mob1.beRepaired(25);
    mob1.attack(mob2.getName());
    mob2.takeDamage(mob1.getAttackDamage());
    mob2.beRepaired(50);
    mob2.highFivesGuys();
    mob1.highFivesGuys();
}