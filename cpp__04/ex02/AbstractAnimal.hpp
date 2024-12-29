#pragma once
#ifndef AIMAL_HPP
#define AbstractAnimal_HPP

#include <iostream>
#include <string>

class AbstractAnimal
{
    protected:
        std::string _type;
    public:
        AbstractAnimal();
        virtual ~AbstractAnimal();
        void setType(std::string &type) ;
        std::string getType() const;

        virtual void makeSound() const = 0;
};

#endif


