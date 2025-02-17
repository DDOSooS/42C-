#pragma once

#include "./ClapTrap.hpp"

class ScavTrap :virtual public ClapTrap
{
    private:

    public:
        ScavTrap();
        ScavTrap(const std::string &name);
        ScavTrap(const ScavTrap &other);
        ScavTrap &operator=(const ScavTrap &other);
        void attack(const std::string& target);
        void guardGate();
        ~ScavTrap();
};
