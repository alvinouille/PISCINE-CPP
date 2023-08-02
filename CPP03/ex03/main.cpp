#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap mob1("Bran Stark");
    DiamondTrap mob2("The Night King");

    mob1.whoAmI();
    mob2.attack(mob1.getName());
    mob1.takeDamage(mob2.getAttackDamage());
    mob1.beRepaired(25);
    mob1.guardGate();
    mob2.highFivesGuys();
}