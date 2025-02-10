#include "./HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon): _name(name)
{
    std::cout << "[constructor]: HumanA Object is being Created\n"; 
    this->_weapon = &weapon;
}

void HumanA::attack()
{
    std::cout << _name << " attacks with their " << (*_weapon).getType() << std::endl;
}

HumanA::~HumanA()
{
    std::cout << "[Deconstructor]: HumanA Object is being Destroyed\n"; 
}