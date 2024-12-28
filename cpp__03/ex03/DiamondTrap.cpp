#include "./DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string &name):ClapTrap(name) , FragTrap(name), ScavTrap(name)
{
    std::cout << "[Constructor]: DiamondTap Object is being Created\n";
    std::string clap_name = name + "_clap_name";
    ClapTrap::setName(clap_name);
    this->_name = name;
    this->setAttackDamage(FragTrap::getAttackDamage());
    this->setEnergyPoints(ScavTrap::getEnergyPoints());
    this->setHitPoints(FragTrap::getHitPoints());
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy):ClapTrap(copy) , FragTrap(copy), ScavTrap(copy)
{
    std::cout << "[Copy Constructor]: DiamondTap Object is being Created\n";
    std::string clap_name = copy.getName() + "_clap_name";
    ClapTrap::setName(clap_name);
    this->_name = copy.getName();
    this->setAttackDamage(FragTrap::getAttackDamage());
    this->setEnergyPoints(ScavTrap::getEnergyPoints());
    this->setHitPoints(FragTrap::getHitPoints());
}

DiamondTrap & DiamondTrap::operator=(const DiamondTrap &copy)
{
    std::cout << "[Copy Assignement Constructor]: DiamondTap Object is being Created\n";
    if (this != &copy)
    {
        FragTrap::operator=(copy);
        FragTrap::operator=(copy);
        std::string clap_name = copy.getName() + "_clap_name";
        ClapTrap::setName(clap_name);
        this->_name = copy.getName();
        this->setAttackDamage(FragTrap::getAttackDamage());
        this->setEnergyPoints(ScavTrap::getEnergyPoints());
        this->setHitPoints(FragTrap::getHitPoints());
    }
    return (*this);
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout   << "ClapTrap object's name of the Diamond Trap object is << " << ClapTrap::getName() << "Diamod Trap's Name :"
                << this->_name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout   << "[Deconstructor]: Daimond Trap Object is being destroyed !!\n";
}
