# include "./ScavTrap.hpp"

ScavTrap::ScavTrap():ClapTrap(){}

ScavTrap::ScavTrap(std::string &name) : ClapTrap(name)
{
    std::cout << "[Constructor]: ScavTrap Object is being Created\n";
    this->setAttackDamage(20);
    this->setEnergyPoints(50);
    this->setHitPoints(100);
}

ScavTrap::ScavTrap(const ScavTrap &copy):ClapTrap(copy)
{
    std::cout << "[Copy Constructor]: ClapTrap Copy constructor called\n";
}

ScavTrap & ScavTrap::operator=(const ScavTrap &copy)
{
   std::cout << "[Copy Assignement Constructor]: ClapTrap Copy constructor called\n";
    if (this != &copy)
        ClapTrap::operator=(copy); 
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "[Deconstructor]: ScavTrap Object is being Destroyed\n";
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