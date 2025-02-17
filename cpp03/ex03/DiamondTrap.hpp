#pragma once

#include "./ScavTrap.hpp"
#include "./FragTrap.hpp"

class DiamondTrap: public ScavTrap,public FragTrap 
{
    private:
        std::string name;
    public:
        DiamondTrap();
        DiamondTrap(const std::string &name);
        DiamondTrap(const DiamondTrap &other);
        DiamondTrap & operator=(const DiamondTrap &other);
        void WhoAmI();
        void attack(const std::string &target);
        ~DiamondTrap();
};