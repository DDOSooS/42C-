#pragma once
#ifndef DIAMAND_TRAP_HPP
#define DIAMAND_TRAP_HPP

#include "./FragTrap.hpp"
#include "./ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string _name;
    public:
        DiamondTrap(std::string &name);
        ~DiamondTrap();

        void attack(const std::string& target) override;
        void whoAmI();
};

#endif