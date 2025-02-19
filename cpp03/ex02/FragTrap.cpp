#include "./FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "[Default Constructor] : FragTrap object is being Called!\n";
    this->_name = "";
    this->_attackDamage = 30;
    this->_energyPoint =100;
    this->_hitPoint = 100;
}

FragTrap::FragTrap(const std::string &name)
{
    std::cout << "[Constructor] : FragTrap object is being Called!\n";
    this->_name = name;
    this->_attackDamage = 30;
    this->_energyPoint =100;
    this->_hitPoint = 100;
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
    if (this->_hitPoint && this->_energyPoint)
    {
        std::cout << "[FragTrap] :" << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!\n";
        this->_energyPoint --;
    }
    else
        std::cout << "No energy Or Hit Point are being left try to be Repariared!\n";
    std::cout << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "=============== [FragTrap hight Five ] ===============\n";
    std::cout << "✋✋✋ From FragTrap :"<< this->_name << "\n";
}