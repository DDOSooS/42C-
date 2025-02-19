#include "./DiamondTrap.hpp"

int main()
{
    DiamondTrap diamond1("DiamondOne");
    
    // std::cout << "Hit Point: " << diamond1._hitPoint << std::endl;
    // std::cout << "Energy POint: " << diamond1._energyPoint << std::endl;
    // std::cout << "Attack Damage: " << diamond1._attackDamage << std::endl;
    diamond1.WhoAmI();
    diamond1.attack("Enemy");

    diamond1.takeDamage(5);

    diamond1.beRepaired(3);

    diamond1.attack("Enemy");
    return 0;
}