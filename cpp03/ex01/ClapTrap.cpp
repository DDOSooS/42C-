#include "./ClapTrap.hpp"

ClapTrap::ClapTrap():_name(""), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
    std::cout << "[Default Constructor] : ClapTrap object is being Called!\n";
}

ClapTrap::ClapTrap(const std::string &name):_name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
    std::cout << "[Constructor] : ClapTrap object is being Called!\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "[Copy Constructor]: ClapTrap Copy Constructor is being Called !!\n";
    *this = other;
}

ClapTrap & ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "[Copy Assignement Constructor]: ClapTrap Copy Assignement Constructor is being Called !!\n";
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoint = other._hitPoint;
        this->_energyPoint = other._energyPoint;
        this->_attackDamage = other._attackDamage;
    }
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "[Deconstructor] : ClapTrap Object is being Destroyed!!\n";
}

void ClapTrap::attack(const std::string &target)
{
    std::cout << "=============== [ClapTrap Attacking Damage] ===============\n";
    if (this->_hitPoint && this->_energyPoint)
    {
        std::cout << "ClapTrap :" << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!\n";
        this->_energyPoint--;
    }
    else
        std::cout << "No energy Or Hit Point are being left try to be Repariared!\n";
    std::cout << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "=============== [taking Damage] ===============\n";
    if (_hitPoint <=  amount)
        _hitPoint = 0;
    std::cout << "ClapTrap :" << this->_name << " has take a Damage causing lose of  :" << amount << " of hit points! \n";
    _hitPoint -= amount;
    std::cout << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "=============== [Reparing ....] ===============\n";
    if (!this->_energyPoint || !_hitPoint)
        std::cout << "No energy Or Hit Point are being left you can't to be Repariared!\n";
    else
    {
        _energyPoint--;
        _hitPoint += amount;
        std::cout << "ClapTrap :" << this->_name << "has take been repared by :" << amount << " of hit points! \n";
    }
    std::cout << std::endl;
}

unsigned int ClapTrap::getAttackDamage() const
{
    return _attackDamage;
}

unsigned int ClapTrap::getEnergyPoint() const
{
    return _energyPoint;
}

unsigned int ClapTrap::getHitPoint() const
{
    return _hitPoint;
}

const std::string & ClapTrap::getName() const
{
    return _name;
}

void ClapTrap::setAttackDamage(unsigned int amount)
{
    this->_attackDamage = amount;
}

void ClapTrap::setEnergyPoint(unsigned int amount)
{
    this->_energyPoint = amount;
}

void ClapTrap::setHitPoint(unsigned int amount)
{
    this->_hitPoint = amount;
}