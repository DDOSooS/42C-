#pragma once
#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <string>

class Weapon
{
    private:
        std::string _type;
    public:
        Weapon();
        Weapon(std::string type);
        ~Weapon();
        void setType(std::string type);
        std::string getType() const;
};
#endif