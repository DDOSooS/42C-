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
        ClapTrap(const ClapTrap &other);
        ClapTrap &operator=(const ClapTrap & other);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        unsigned int getHitPoint() const;
        unsigned int getEnergyPoint() const;
        unsigned int getAttackDamage() const;
        const std::string &getName() const;

        void setEnergyPoint(unsigned int amount);
        void setAttackDamage(unsigned int amount);
        void setHitPoint(unsigned int amount);
        void setName(const std::string &name);
        ~ClapTrap();
};
