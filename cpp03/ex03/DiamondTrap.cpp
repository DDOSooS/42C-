#include "./DiamondTrap.hpp"

DiamondTrap::DiamondTrap():ClapTrap(), ScavTrap(), FragTrap()
{
    std::cout << "[Default Constructor] : Diamond object is being Called!\n";
    this->name = "";
    this->setName("_clap_name");
    this->setAttackDamage(30);
    this->setEnergyPoint(50);
    this->setHitPoint(100);
}

DiamondTrap::DiamondTrap(const std::string &name):ClapTrap(name + "_clap_name"),ScavTrap(name + "_clap_name"),FragTrap(name + "_clap_name")
{
    std::cout << "[Constructor] : Diamond object is being Called!\n";
    this->name = name;
    this->setName(name + "_clap_name");
    this->setAttackDamage(30);
    this->setEnergyPoint(50);
    this->setHitPoint(100);
}

DiamondTrap::DiamondTrap(const DiamondTrap &other):ClapTrap(other.name + "_clap_name"), ScavTrap(other.name + "_clap_name"),FragTrap(other.name + "_clap_name"), name(other.name)
{
    std::cout << "[Constructor] : Diamond object is being Called!\n";
    this->setAttackDamage(other.getAttackDamage());
    this->setEnergyPoint(other.getEnergyPoint());
    this->setHitPoint(other.getHitPoint());
}

DiamondTrap & DiamondTrap::operator=(const DiamondTrap &other)
{
    std::cout << "[Copy Assignment Constructor] : Diamond object is being Called!\n";
    if (this != &other)
    {
        ClapTrap::operator=(other);
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        this->name = other.name;
        this->setName(this->name + "_clap_name");
        this->setAttackDamage(other.getAttackDamage());
        this->setEnergyPoint(other.getEnergyPoint());
        this->setHitPoint(other.getHitPoint());
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
    std::cout << "I' M DAIMOND ROBOT : " << this->name << ", MY GRAND FATHER CLAPTRAP'S NAME: " << this->getName() << std::endl;
}