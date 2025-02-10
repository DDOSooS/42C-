#include "./Zombie.hpp"

int main ()
{
    int counter;
    Zombie *z;

    counter = 10;
    z = zombieHorde(counter, "abde");
    for (int i = 0; i < counter ; i++)
        z[i].announce();
    delete []z;
    return 0;
}