#include "./DiamondTrap.hpp"

int main()
{
    DiamondTrap diamond1("DiamondOne");
    
    std::cout << "Hit Point: " << diamond1.getHitPoint() << std::endl;
    std::cout << "Energy POint: " << diamond1.getEnergyPoint() << std::endl;
    std::cout << "Attack Damage: " << diamond1.getAttackDamage() << std::endl;
    diamond1.WhoAmI();
    diamond1.attack("Enemy");

    diamond1.takeDamage(5);

    diamond1.beRepaired(3);

    diamond1.attack("Enemy");
    return 0;
}