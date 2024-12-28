#pragma once
#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "./ClapTrap.hpp"

class ScavTrap : public ClapTrap 
{
    private:
       
    public:
        ScavTrap();
        ~ScavTrap();

        ScavTrap(std::string &name);
        ScavTrap(const ScavTrap &copy);
        ScavTrap & operator=(const ScavTrap &copy);
        void attack(const std::string& target) override;
        void guardGate();
};

#endif