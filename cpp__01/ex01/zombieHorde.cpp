#include "./Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if (N <= 0)
        return NULL;
    Zombie *newZhorde = new Zombie[N];
    for(int i = 0; i < N; i++)
        new (&newZhorde[i]) Zombie(name);
    return (newZhorde);
}