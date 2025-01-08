#include "./Zombie.hpp"

Zombie::Zombie(string name):_name(name){}

Zombie::~Zombie()
{
    cout << this->_name << "Zombie is being destroyed\n"; 
}

void Zombie::announce( void )
{
    cout << this->_name << ":  BraiiiiiiinnnzzzZ...\n";
}