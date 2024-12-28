#pragma once

#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    private:
        std::string _name;
        unsigned int _hitPoint;
        unsigned int _energyPoint;
        unsigned int _attackDamage;

    public:
        ClapTrap();
        ClapTrap(std::string &name);
        ClapTrap(const ClapTrap &copy);
        ClapTrap& operator=(const ClapTrap &copy);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        // Getters
        std::string getName() const; 
        unsigned int getHitPoints() const ;
        unsigned int getEnergyPoints() const;
        unsigned int getAttackDamage() const ;

        // Setters
        void setName(std::string &name);
        void setHitPoints(unsigned int points); 
        void setEnergyPoints(unsigned int points);
        void setAttackDamage(unsigned int damage); 
};

#endif