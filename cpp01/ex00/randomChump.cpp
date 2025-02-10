#include "./Zombie.hpp"

void randomChump(std::string name)
{
    Zombie localZombie = Zombie(name);
    localZombie.announce();
}
