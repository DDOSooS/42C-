#include "./Zombie.hpp"

int main()
{
    Zombie *tmp;

    tmp = zombieHorde(10, "ABDE");
    for (int i = 0; i < 10; i++)
        tmp[i].announce();
    delete [] tmp;
    return 0;
}