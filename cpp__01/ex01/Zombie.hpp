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
        Zombie() : _name("") {}
        Zombie(string name):_name(name){}
        ~Zombie()
        {
            cout << this->_name << "Zombie is being destroyed\n"; 
        }

    void announce(void);
};

Zombie* zombieHorde( int N, std::string name );
#endif