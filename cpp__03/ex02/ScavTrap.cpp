# include "./ScavTrap.hpp"

ScavTrap::ScavTrap():ClapTrap(){}

ScavTrap::ScavTrap(std::string &name) : ClapTrap(name)
{
    std::cout << "ScavTrap Object is being Created\n";
    this->setAttackDamage(20);
    this->setEnergyPoints(50);
    this->setHitPoints(100);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Object is being Destroyed\n";
}

void ScavTrap::attack(const std::string& target)
{   
    if (this->getEnergyPoints()  <= 0 || this->getHitPoints() <= 0)
    {
        std::cout << "@ScavTrap@:: " << this->getName() << " can't attack - no energy/health left!" << std::endl;
        return;
    }
    this->setEnergyPoints(this->getEnergyPoints() - 1);
    std::cout << "@ScavTrap@:: " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!\n";
}

void ScavTrap::guardGate()
{
    std::cout << " that ScavTrap: "<< this->getName() <<  " is now in Gate keeper mode\n";
}