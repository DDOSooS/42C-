#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "./Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon *weapon;  

    public:
        HumanB(std::string t_name);
        ~HumanB();
        void setWeapon(Weapon &t_weapon);  
        void attack(); 
};

#endif
