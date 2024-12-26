#include "./FragTrap.hpp"

int main() {
    std::string name = "ABDE";
    std::string name2 = "IMAD";
    FragTrap p(name);
    p.attack(name2);
    p.takeDamage(5);
    p.beRepaired(15);
    p.highFivesGuys();
    return 0;
}