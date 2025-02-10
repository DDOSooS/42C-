#include "./Zombie.hpp"

int main ()
{
    Zombie *z = newZombie("zombieeeee 1");
    z->announce();
    randomChump("zombieee 2");
    delete z;
    return 0;
}