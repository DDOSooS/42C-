#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string t_name, Weapon &t_weapon) : weapon(t_weapon), name(t_name) {}

HumanA::~HumanA() {}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
