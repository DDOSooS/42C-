#include "./ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap Object is being Created\n";
    this->_name = "";
    this->_attackDamage = 0;
    this->_energyPoint = 10;
    this->_hitPoint = 10;
}

ClapTrap::ClapTrap(std::string &name)
{
    std::cout << "ClapTrap Object is being Created\n";
    this->_name = name;
    this->_energyPoint = 10;
    this->_hitPoint = 10;
    this->_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << "ClapTrap Copy Constructor is being Called\n";
    this->_name = copy.getName();
    this->_hitPoint = copy.getHitPoints();
    this->_energyPoint = copy.getEnergyPoints();
    this->_attackDamage = copy.getAttackDamage();
}

ClapTrap& ClapTrap::operator=(const ClapTrap &copy)
{
    std::cout << "ClapTrap Copy assignement Constructor is being Called\n";
    if (this != &copy)
    {
        this->_name = copy.getName();
        this->_hitPoint = copy.getHitPoints();
        this->_energyPoint = copy.getEnergyPoints();
        this->_attackDamage = copy.getAttackDamage();
    }
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Object is being Destroyed\n";
}

// Getters
std::string ClapTrap::getName() const { return _name;};
unsigned int ClapTrap::getHitPoints() const { return _hitPoint; };
unsigned int ClapTrap::getEnergyPoints() const { return _energyPoint; };
unsigned int ClapTrap::getAttackDamage() const { return _attackDamage; };

// Setters
void ClapTrap::setHitPoints(unsigned int points) { _hitPoint = points; };
void ClapTrap::setEnergyPoints(unsigned int points) { _energyPoint = points; };
void ClapTrap::setAttackDamage(unsigned int damage) { _attackDamage = damage; };

void ClapTrap::attack(const std::string& target)
{
    if (_energyPoint <= 0 || _hitPoint <= 0)
    {
        std::cout << "ClapTrap " << _name << " can't attack - no energy/health left!" << std::endl;
        return;
    }
    this->_energyPoint--;
    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing" << this->_attackDamage << " points of damage!\n";

}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoint <=  amount)
        this->_hitPoint = 0;
    else
        this->_hitPoint -= amount;
    std::cout << "ClapTrap " << _name << " takes " << amount 
              << " damage! Hit points remaining: " << _hitPoint << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoint <= 0 || _hitPoint <= 0)
    {
        std::cout << "ClapTrap " << _name << " can't be repared !!!" << std::endl;
        return;
    }
    this->_energyPoint--;
    this->_hitPoint += amount;
    std::cout << "ClapTrap ," << this->_name << " is being Repared!\n";

}