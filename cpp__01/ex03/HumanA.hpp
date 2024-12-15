#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    private:
        Weapon &weapon;
        std::string name;

    public:
        HumanA(std::string t_name, Weapon &t_weapon);
        ~HumanA();
        void attack();
};

#endif
