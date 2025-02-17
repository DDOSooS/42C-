#include "./FragTrap.hpp"

FragTrap::FragTrap():ClapTrap()
{
    std::cout << "[Default Constructor] : FragTrap object is being Called!\n";
    this->setAttackDamage(30);
    this->setEnergyPoint(100);
    this->setHitPoint(100);
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << "[Constructor] : FragTrap object is being Called!\n";
    this->setAttackDamage(30);
    this->setEnergyPoint(100);
    this->setHitPoint(100);
}

FragTrap::FragTrap(const FragTrap &other):ClapTrap(other)
{
    std::cout << "[Copy Constructor] : FragTrap object is being Called!\n";
}

FragTrap & FragTrap::operator=(const FragTrap & other)
{
    std::cout << "[Copy Assignment Constructor] : FragTrap object is being Called!\n";
    if (this != &other)
        ClapTrap::operator=(other);
    return (*this);
} 

FragTrap::~FragTrap()
{
    std::cout << "[DeConstructor] : FragTrap object is being Called!\n";
}

void FragTrap::attack(const std::string &target)
{
    std::cout << "=============== [FragTrap Attacking Damage] ===============\n";
    if (this->getHitPoint() && this->getEnergyPoint())
    {
        std::cout << "[FragTrap] :" << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!\n";
        this->setEnergyPoint(this->getEnergyPoint() - 1);
    }
    else
        std::cout << "No energy Or Hit Point are being left try to be Repariared!\n";
    std::cout << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "=============== [FragTrap hight Five ] ===============\n";
    std::cout << "✋✋✋ From FragTrap :"<< this->getName() << "\n";
}