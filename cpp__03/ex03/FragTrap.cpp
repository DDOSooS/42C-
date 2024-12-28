#include "./FragTrap.hpp"

FragTrap::FragTrap():ClapTrap(){}

FragTrap::FragTrap(std::string &name): ClapTrap(name)
{
    std::cout << "[Constructor]: FragTrap Object is being Created\n";
    this->setAttackDamage(30);
    this->setEnergyPoints(100);
    this->setHitPoints(100);
}

FragTrap::~FragTrap()
{
    std::cout << "[Deconstructor]: FragTrap Object is being Destroyed\n";
}

FragTrap::FragTrap(const FragTrap &copy):ClapTrap(copy)
{
    std::cout << "[Copy Constructor]: is being Called\n";
}

FragTrap & FragTrap::operator=(const FragTrap &copy)
{
    std::cout << "[Copy Assignement Constructor]: is being Called\n";
    if (this != &copy)
        ClapTrap::operator=(copy);
    return (*this);
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "this is a 🙌 🙌 from FragTrap Objecs's name " << this->getName() <<std::endl;
}