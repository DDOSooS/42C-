#pragma once

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

using namespace std;

class Zombie
{
    private:
        string _name;

    public:
        Zombie(string name);
        ~Zombie();
        void announce( void );
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif