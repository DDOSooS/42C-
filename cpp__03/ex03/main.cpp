#include "./DiamondTrap.hpp"

int main() {
    std::string name = "ABDE";
    std::string name2 = "IMAD";
    DiamondTrap p(name);

    p.attack(name2);
    p.takeDamage(5);
    p.beRepaired(15);
    p.whoAmI();    

    return 0;
}