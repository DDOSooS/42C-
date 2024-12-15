#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string t_name) : name(t_name), weapon(NULL){} 

HumanB::~HumanB() {}

void HumanB::attack()
{
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &t_weapon)
{
    this->weapon = &t_weapon;
}
