#include "./Zombie.hpp"

Zombie::Zombie()
{
    std::cout << "[Default constructor]: ZOMBIE Object is being Created\n";
    _name = "";
}

Zombie::Zombie(std::string name):_name(name)
{
    std::cout << "[Zombie constructor]: ZOMBIE Object is being Created\n";
}

void Zombie::announce()
{
    std::cout << _name << ": : BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie()
{
    std::cout << "[Deconstructor]:" << _name << " ZOMBIE Object is being Destroyed\n";
}

void Zombie::setName(std::string name)
{
    _name = name;
}

std::string Zombie::getName() const
{
    return _name;
}
