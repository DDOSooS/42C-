#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
    private:
        std::string type;

    public:
        Weapon(std::string t_type);
        ~Weapon();
        std::string getType();
        void setType(std::string t_type);
};

#endif
