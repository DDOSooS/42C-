#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "./ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{

    public:
        FragTrap();
        FragTrap(std::string &name);
        ~FragTrap();
        FragTrap(const FragTrap &copy);
        FragTrap & operator=(const FragTrap &copy);
        void highFivesGuys(void);
};

#endif