#include "./DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string &name):FragTrap(name), ScavTrap(name)
{
    std::cout << "DiamondTap Object is being Created\n";
    std::string clap_name = name + "_clap_name";
    FragTrap::setName(clap_name);
    this->_name = name;
    this->FragTrap::setAttackDamage(FragTrap::getAttackDamage());
    this->FragTrap::setEnergyPoints(ScavTrap::getEnergyPoints());
    this->FragTrap::setHitPoints(FragTrap::getHitPoints());
}

void DiamondTrap::attack(const std::string& target)
{
    this->ScavTrap::attack(target);
}


void DiamondTrap::whoAmI()
{
    std::cout   << "ClapTrap object's name of the Diamond Trap object is << " << FragTrap::getName() << " - Diamod Trap's Name :"
                << this->_name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout   << "Daimond Trap Object is being destroyed !!\n";
}