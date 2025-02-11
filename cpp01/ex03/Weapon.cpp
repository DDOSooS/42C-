#include "./Weapon.hpp"
#include <iostream>

Weapon::Weapon()
{
    std::cout << "[Default constructor]: Weapon Object is being Created\n"; 
    _type = "";
}

Weapon::Weapon(std::string type)
{
    std::cout << "[constructor]: Weapon Object is being Created\n"; 
    _type = type;
}

Weapon::~Weapon()
{
    std::cout << "[Deconstructor]: Weapon Object is being Destroyed\n"; 
}

void Weapon::setType(std::string type)
{
    this->_type = type;
}

std::string Weapon::getType() const
{
    return (_type);
}
