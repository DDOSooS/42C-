#pragma once
#ifndef AIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
    protected:
        std::string _type;
    public:
        Animal();
        virtual ~Animal();
        Animal(const Animal &copy);
        Animal & operator=(const Animal &copy);
        void setType(std::string &type) ;
        std::string getType() const;

        virtual void makeSound() const;
};

#endif


