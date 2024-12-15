#include "Weapon.hpp"

Weapon::Weapon(std::string t_type) : type(t_type) {}
Weapon::~Weapon() {}

std::string Weapon::getType()
{
    return type;
}

void Weapon::setType(std::string t_type)
{
    type = t_type;
}
