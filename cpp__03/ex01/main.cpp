#include "./ScavTrap.hpp"

int main() {
    std::string name = "ABDE";
    std::string name2 = "IMAD";
    ScavTrap p(name);
    p.attack(name2);
    p.takeDamage(5);
    p.beRepaired(15);
    return 0;
}