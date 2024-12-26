#include "./ClapTrap.hpp"

int main() {
    std::string name = "ABDE";
    std::string name2 = "IMAD";
    ClapTrap p(name);   
    p.attack(name2);
    p.takeDamage(5);
    p.beRepaired(15);
    return 0;
}