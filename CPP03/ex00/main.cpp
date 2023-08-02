#include "ClapTrap.hpp"

int main()
{
    ClapTrap mob1("Baelish");
    ClapTrap mob2("Varys");

    // std::cout << mob1 << std::endl;
    // std::cout << mob2 << std::endl;

    mob1.attack(mob2.getName());
    mob2.takeDamage(mob1.getAttackDamage());
    mob2.beRepaired(2);
    mob2.attack(mob1.getName());
    mob1.takeDamage(mob2.getAttackDamage());
    mob1.beRepaired(25);

    // std::cout << mob1 << std::endl;
    // std::cout << mob2 << std::endl;
}