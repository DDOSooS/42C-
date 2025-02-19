#include "./ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "[Default Constructor] : ScavTrap object is being Called!\n";
    this->_name = "";
    this->_attackDamage = 20;
    this->_energyPoint = 50;
    this->_hitPoint = 100;
}

ScavTrap::ScavTrap(const std::string &name)
{
    std::cout << "[Constructor] : ScavTrap object is being Called!\n";
    this->_name = name;
    this->_attackDamage = 20;
    this->_energyPoint = 50;
    this->_hitPoint = 100;
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
    if (this->_hitPoint && this->_energyPoint)
    {
        std::cout << "[ScavTrap] :" << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!\n";
        this->_energyPoint--;
    }
    else
        std::cout << "No energy Or Hit Point are being left try to be Repariared!\n";
    std::cout << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "=============== [Gate Keeper  Mode] ===============\n";
    std::cout << "ScavTrap : " << this->_name << " is now in Gate keeper mode\n\n";
}