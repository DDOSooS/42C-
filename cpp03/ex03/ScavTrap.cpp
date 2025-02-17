#include "./ScavTrap.hpp"

ScavTrap::ScavTrap():ClapTrap()
{
    std::cout << "[Default Constructor] : ScavTrap object is being Called!\n";
    this->setAttackDamage(20);
    this->setEnergyPoint(50);
    this->setHitPoint(100);
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << "[Constructor] : ScavTrap object is being Called!\n";
    this->setAttackDamage(20);
    this->setEnergyPoint(50);
    this->setHitPoint(100);
}

ScavTrap::ScavTrap(const ScavTrap &other):ClapTrap(other)
{
    std::cout << "[Copy Constructor] : ScavTrap object is being Called!\n";
}

ScavTrap & ScavTrap::operator=(const ScavTrap & other)
{
    std::cout << "[Copy Assignment Constructor] : ScavTrap object is being Called!\n";
    if (this != &other)
        ClapTrap::operator=(other);
    return (*this);
} 

ScavTrap::~ScavTrap()
{
    std::cout << "[DeConstructor] : ScavTrap object is being Called!\n";
}

void ScavTrap::attack(const std::string &target)
{
    std::cout << "=============== [ScavTRAP Attacking Damage] ===============\n";
    if (this->getHitPoint() && this->getEnergyPoint())
    {
        std::cout << "[ScavTrap] :" << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!\n";
        this->setEnergyPoint(this->getEnergyPoint() - 1);
    }
    else
        std::cout << "No energy Or Hit Point are being left try to be Repariared!\n";
    std::cout << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "=============== [Gate Keeper  Mode] ===============\n";
    std::cout << "ScavTrap : " << this->getName() << " is now in Gate keeper mode\n\n";
}