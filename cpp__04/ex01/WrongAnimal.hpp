#pragma once
#ifndef WRONG_AIMAL_HPP
#define WRONG_AIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
    protected:
        std::string _type;
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &copy);
        WrongAnimal & operator=(const WrongAnimal &copy);
        virtual ~WrongAnimal();
        void setType(std::string &type);
        std::string getType() const;
        virtual void makeSound() const;
};

#endif