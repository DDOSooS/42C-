#pragma once

#include "./Weapon.hpp"

class HumanB
{
    private:
        std::string _name;
        Weapon *_weapon;
    public:
        HumanB(std::string name);
        HumanB(std::string name, Weapon &weapon);
        void setWeapon(Weapon &weapon);
        void attack();
        ~HumanB();
};
