#pragma once

#include <string>
#include <iostream>

class ClapTrap
{
    private:
        std::string          _name;
        unsigned int         _hitPoint;
        unsigned int         _energyPoint;
        unsigned int         _attackDamage;

    public:
        ClapTrap();
        ClapTrap(const std::string &name);
        ClapTrap(ClapTrap &other);
        ClapTrap &operator=(const ClapTrap & other);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        ~ClapTrap();
};
