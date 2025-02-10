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
    // std::cout << "old " << _type << std::endl;
    this->_type = type;
    // std::cout << "new " << _type << std::endl<<std::endl; 
}

std::string Weapon::getType() const
{
    return (_type);
}
