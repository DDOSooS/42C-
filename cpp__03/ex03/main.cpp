#include "./DiamondTrap.hpp"

int main() {
    std::string name = "ABDE";
    std::string name2 = "IMAD";
    DiamondTrap p(name);

    p.takeDamage(5);
    p.beRepaired(15);
    p.attack(name2);
    p.whoAmI();    

    return 0;
}