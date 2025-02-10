#include "./HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name): _name(name)
{
    std::cout << "[constructor]: HumanB Object is being Created\n"; 
    _weapon = NULL;
}

HumanB::HumanB(std::string name, Weapon &weapon): _name(name)
{
    std::cout << "[constructor]: HumanB Object is being Created\n"; 
    this->_weapon = &weapon;
}

void HumanB::attack()
{
    std::cout << _name << " attacks with their " << (*_weapon).getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    _weapon = &weapon;
}

HumanB::~HumanB()
{
    std::cout << "[Destructor]: HumanB Object is being Destroyed\n";
}