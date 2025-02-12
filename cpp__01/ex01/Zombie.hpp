#pragma once

#include <string>
#include <iostream>


class Zombie
{
    private:
        std::string _name;

    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        void setName(std::string name);
        std::string getName();

    void announce(void);
};

Zombie* zombieHorde( int N, std::string name );
