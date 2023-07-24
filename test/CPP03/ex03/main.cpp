#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap mob1("Bran Stark");
    DiamondTrap mob2("The Night King");
    DiamondTrap mob3(mob1);
    mob3 = mob2;

    std::cout << "Classical" << std::endl;
    mob1.whoAmI();
    mob2.attack(mob1.getName());
    mob1.takeDamage(mob2.getAttackDamage());
    mob1.beRepaired(25);
    mob1.guardGate();
    mob2.highFivesGuys();
    std::cout << "The copy" << std::endl;
    mob3.beRepaired(50);
    mob3.guardGate();
    mob3.highFivesGuys();
    mob3.whoAmI();
    std::cout << "Once modified" << std::endl;
    mob3.beRepaired(50);
    mob3.guardGate();
    mob3.highFivesGuys();
    mob3.whoAmI();
    mob2.attack(mob1.getName());
}