#include "./DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    std::cout << "[Default Constructor] : Diamond object is being Called!\n";
    this->name = "";
    this->_name = name + "_clap_name";
    this->_attackDamage = 30;
    this->_energyPoint = 50;
    this->_hitPoint = 100;
}

DiamondTrap::DiamondTrap(const std::string &name)
{
    std::cout << "[Constructor] : Diamond object is being Called!\n";
    this->name = name;
    this->_name = name + "_clap_name";
    this->_attackDamage = 30;
    this->_energyPoint = 50;
    this->_hitPoint = 100;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name)
{
    std::cout << "[Constructor] : Diamond object is being Called!\n";
    this->_name = other.name + "_clap_name";
    this->_attackDamage = other._attackDamage;
    this->_energyPoint = other._energyPoint;
    this->_hitPoint = other._hitPoint;
}


DiamondTrap & DiamondTrap::operator=(const DiamondTrap &other)
{
    std::cout << "[Copy Assignment Constructor] : Diamond object is being Called!\n";
    if (this != &other)
    {
        this->name = other.name;
        this->_name = other.name + "_clap_name";
        this->_attackDamage = other._attackDamage;
        this->_energyPoint = other._energyPoint;
        this->_hitPoint = other._hitPoint;
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "[DeConstructor] : Diamond object is being Destroyed!\n";
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::WhoAmI()
{
    std::cout << "I' M DAIMOND ROBOT : " << this->name << ", MY GRAND FATHER CLAPTRAP'S NAME: " << this->_name << std::endl;
}