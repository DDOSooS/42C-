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

#endif