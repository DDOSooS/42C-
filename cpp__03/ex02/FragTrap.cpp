#include "./FragTrap.hpp"

FragTrap::FragTrap():ClapTrap(){}

FragTrap::FragTrap(std::string &name): ClapTrap(name)
{
    std::cout << "FragTrap Object is being Created\n";
    this->setAttackDamage(30);
    this->setEnergyPoints(100);
    this->setHitPoints(100);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Object is being Destroyed\n";
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "this is a 🙌 🙌 from FragTrap Objecs's name " << this->getName() <<std::endl;
}