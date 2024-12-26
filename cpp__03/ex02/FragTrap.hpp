#pragma once
#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "./ClapTrap.hpp"

class FragTrap : public ClapTrap
{

    public:
        FragTrap();
        FragTrap(std::string &name);
        ~FragTrap();

        void highFivesGuys(void);
};


// class ScavTrap : public ClapTrap 
// {
//     private:
       
//     public:
//         ScavTrap();

//         ScavTrap(std::string &name);
        
//         ~ScavTrap();

//         void attack(const std::string& target) override;

//         void guardGate();
// };


#endif