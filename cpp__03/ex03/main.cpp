#include "./DiamondTrap.hpp"

int main() {
    std::string name = "ABDE";
    std::string name2 = "IMAD";
    DiamondTrap p(name);

    // p.000::attack(name2);
    p.ScavTrap::takeDamage(5);
    p.FragTrap::beRepaired(15);
    p.whoAmI();    

    return 0;
}