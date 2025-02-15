#include "./Zombie.hpp"

Zombie::Zombie() : _name("") {}

Zombie::Zombie(std::string name):_name(name){}

Zombie::~Zombie()
{
    std::cout << this->_name << "Zombie is being destroyed\n"; 
}

void Zombie::announce( void )
{
    std::cout << this->_name << ":  BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string name)
{
    this->_name = name;
}

std::string Zombie::getName()
{
    return this->_name;
}