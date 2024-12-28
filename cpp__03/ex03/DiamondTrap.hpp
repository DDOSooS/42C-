
#ifndef DIAMAND_TRAP_HPP
#define DIAMAND_TRAP_HPP

#include "./ClapTrap.hpp"
#include "./FragTrap.hpp"
#include "./ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string _name;
    public:
        DiamondTrap(std::string &name);
        DiamondTrap(const DiamondTrap &copy);
        DiamondTrap & operator=(const DiamondTrap &copy);
        ~DiamondTrap();

        void attack(const std::string& target) override;
        void whoAmI();
};

#endif