#pragma once

#include "./Weapon.hpp"

class HumanA
{
    private:
        std::string _name;
        Weapon *_weapon;
    public:
        HumanA(std::string name);
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
        void attack();
};